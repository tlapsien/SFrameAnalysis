#include <iostream>

using namespace std;

// Local include(s):
#include "include/ZprimePreSelectionCycle.h"
#include "include/SelectionModules.h"
#include "include/ExampleHists.h"
#include "include/ObjectHandler.h"
#include "include/Cleaner.h"
#include "JetCorrectorParameters.h"

ClassImp( ZprimePreSelectionCycle );

ZprimePreSelectionCycle::ZprimePreSelectionCycle()
   : AnalysisCycle() {

  // constructor, declare additional variables that should be 
  // obtained from the steering-xml file
  
  // set the integrated luminosity per bin for the lumi-yield control plots
  SetIntLumiPerBin(25.);

}

ZprimePreSelectionCycle::~ZprimePreSelectionCycle() 
{
  // destructor
}

void ZprimePreSelectionCycle::BeginCycle() throw( SError ) 
{
  // Start of the job, general set-up and definition of 
  // objects are done here

  // Important: first call BeginCycle of base class
  AnalysisCycle::BeginCycle();

  return;

}

void ZprimePreSelectionCycle::EndCycle() throw( SError ) 
{
  // clean-up, info messages and final calculations after the analysis

  
  // call the base cycle class for all standard methods
  // and a summary of the made selections
  AnalysisCycle::EndCycle();

  return;

}

void ZprimePreSelectionCycle::BeginInputData( const SInputData& id ) throw( SError ) 
{
  // declaration of histograms and selections

  // Important: first call BeginInputData of base class
  AnalysisCycle::BeginInputData( id );

  // -------------------- set up the selections ---------------------------

  Selection* preselection= new Selection("pre-selection");

  preselection->addSelectionModule(new NElectronSelection(1,int_infinity(),30,2.5));//at least one electron
  preselection->addSelectionModule(new NMuonSelection(0,0));//no muons
  preselection->addSelectionModule(new NJetSelection(2));//at least two jets
  RegisterSelection(preselection);

  std::vector<JetCorrectorParameters> pars;

  //see https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookJetEnergyCorrections#GetTxtFiles how to get the txt files with jet energy corrections from the database

  pars.push_back(JetCorrectorParameters("/afs/naf.desy.de/user/p/peiffer/SFrame/SFrameAnalysis/config/GR_R_52_V7_L1FastJet_AK5PF.txt"));
  pars.push_back(JetCorrectorParameters("/afs/naf.desy.de/user/p/peiffer/SFrame/SFrameAnalysis/config/GR_R_52_V7_L2Relative_AK5PF.txt"));  
  pars.push_back(JetCorrectorParameters("/afs/naf.desy.de/user/p/peiffer/SFrame/SFrameAnalysis/config/GR_R_52_V7_L3Absolute_AK5PF.txt")); 

  if(!addGenInfo()) pars.push_back(JetCorrectorParameters("/afs/naf.desy.de/user/p/peiffer/SFrame/SFrameAnalysis/config/GR_R_52_V7_L2L3Residual_AK5PF.txt")); 

  corrector = new FactorizedJetCorrector(pars);

  return;

}

void ZprimePreSelectionCycle::EndInputData( const SInputData& id ) throw( SError ) 
{

   return;

}

void ZprimePreSelectionCycle::BeginInputFile( const SInputData& id ) throw( SError ) 
{
  // Connect all variables from the Ntuple file with the ones needed for the analysis
  // The variables are commonly stored in the BaseCycleContaincer

  // important: call to base function to connect all variables to Ntuples from the input tree
  AnalysisCycle::BeginInputFile( id );

  return;

}

void ZprimePreSelectionCycle::ExecuteEvent( const SInputData& id, Double_t weight) throw( SError ) 
{
  // this is the most important part: here the full analysis happens
  // user should implement selections, filling of histograms and results

  // first step: call Execute event of base class to perform basic consistency checks
  // also, the good-run selection is performed there and the calculator is reset
  AnalysisCycle::ExecuteEvent( id, weight);

  ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = objs->GetBaseCycleContainer();

  //save uncleaned jet collection and MET to be stored in output
  std::vector<Jet> uncleaned_jets;
  for(unsigned int i=0; i<bcc->jets->size();++i){
    uncleaned_jets.push_back(bcc->jets->at(i));
  }
  MET uncleaned_met = *bcc->met;

  //clean collections here

  Cleaner* cleaner= new Cleaner();

  if(bcc->muons) cleaner->MuonCleaner_noIso(35,2.1);
  if(bcc->jets) cleaner->JetLeptonSubtractor(corrector);
  //if(!bcc->isRealData && bcc->jets) cleaner->JetEnergyResolutionShifter();
  if(bcc->jets) cleaner->JetCleaner(30,2.4,true);

  // get the selections
  static Selection* preselection = GetSelection("pre-selection");
  
  if(!preselection->passSelection())  throw SError( SError::SkipEvent );

  //fill the uncleaned collections back to bcc to store them in output tree
  bcc->met->set_pt (uncleaned_met.pt());
  bcc->met->set_phi (uncleaned_met.phi());
  bcc->jets->clear();
  for(unsigned int i=0; i<uncleaned_jets.size();++i){
     bcc->jets->push_back(uncleaned_jets.at(i));
  }
//   objs->SetBaseCycleContainer(bcc);


  WriteOutputTree();

  return;

  
}
