// $Id: SelectionCycle.cxx,v 1.1 2012/05/30 09:27:02 peiffer Exp $

// Local include(s):
#include "../include/SelectionCycle.h"

ClassImp( SelectionCycle );


SelectionCycle::SelectionCycle()
   : SCycleBase() {

  SetLogName( GetName() );
  newrun=true;
  
  DeclareProperty( "JetCollection", JetCollection );
  DeclareProperty( "ElectronCollection", ElectronCollection );
  DeclareProperty( "MuonCollection", MuonCollection );
  DeclareProperty( "TauCollection", TauCollection );
  DeclareProperty( "PhotonCollection", PhotonCollection );
  DeclareProperty( "PrimaryVertexCollection", PrimaryVertexCollection );
  DeclareProperty( "METName", METName );
  DeclareProperty( "TopJetCollection", TopJetCollection );
  DeclareProperty( "PrunedJetCollection", PrunedJetCollection );
  DeclareProperty( "GenParticleCollection", GenParticleCollection);
  
}

SelectionCycle::~SelectionCycle() {

}

void SelectionCycle::BeginCycle() throw( SError ) {
  
  return;

}

void SelectionCycle::EndCycle() throw( SError ) {

  return;

}

void SelectionCycle::BeginInputData( const SInputData& inputData) throw( SError ) {


  addGenInfo=true;
  if(inputData.GetType()=="DATA" || inputData.GetType()=="Data" || inputData.GetType()=="data") addGenInfo=false;

  //Set-Up Selection
  first_selection= new Selection("first selection");

  first_selection->addSelectionModule(new NPrimaryVertexSelection(1)); //at least one good PV
  first_selection->addSelectionModule(new NJetSelection(2,int_infinity(),50,2.4));//at least two jets
  first_selection->addSelectionModule(new NElectronSelection(1,int_infinity(),70,2.5));//at least one electron
  first_selection->addSelectionModule(new NElectronSelection(1,1,70,2.5));//exactly one electron 
  first_selection->addSelectionModule(new NMuonSelection(0,0,35,2.1));//no muons
  first_selection->addSelectionModule(new TwoDCut()); 

  second_selection= new Selection("second selection");

  second_selection->addSelectionModule(new NJetSelection(1,int_infinity(),150,2.4));//leading jet with pt>150 GeV
  second_selection->addSelectionModule(new NBTagSelection(1)); //at least one b tag
  //second_selection->addSelectionModule(new NBTagSelection(0,0)); //no b tags
  second_selection->addSelectionModule(new HTlepCut(150));
  second_selection->addSelectionModule(new TriangularCut());
  second_selection->addSelectionModule(new METCut(50));

  std::vector<JetCorrectorParameters> pars;

  //see https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookJetEnergyCorrections#GetTxtFiles how to get the txt files with jet energy corrections from the database

  pars.push_back(JetCorrectorParameters("/afs/naf.desy.de/user/p/peiffer/SFrame/SFrameAnalysis/config/GR_R_52_V7_L1FastJet_AK5PF.txt"));
  pars.push_back(JetCorrectorParameters("/afs/naf.desy.de/user/p/peiffer/SFrame/SFrameAnalysis/config/GR_R_52_V7_L2Relative_AK5PF.txt"));  
  pars.push_back(JetCorrectorParameters("/afs/naf.desy.de/user/p/peiffer/SFrame/SFrameAnalysis/config/GR_R_52_V7_L3Absolute_AK5PF.txt")); 

  if(!addGenInfo) pars.push_back(JetCorrectorParameters("/afs/naf.desy.de/user/p/peiffer/SFrame/SFrameAnalysis/config/GR_R_52_V7_L2L3Residual_AK5PF.txt")); 

  corrector = new FactorizedJetCorrector(pars);


  DeclareVariable( bcc.run, "run" );
  DeclareVariable( bcc.luminosityBlock, "luminosityBlock" );
  DeclareVariable( bcc.event, "event" );
  DeclareVariable( bcc.rho, "rho" );
  DeclareVariable( bcc.isRealData, "isRealData" );
  DeclareVariable( bcc.beamspot_x0, "beamspot_x0");
  DeclareVariable( bcc.beamspot_y0, "beamspot_y0");
  DeclareVariable( bcc.beamspot_z0, "beamspot_z0");

  if(ElectronCollection.size()>0) DeclareVariable( o_electrons, ElectronCollection.c_str() );
  if(MuonCollection.size()>0) DeclareVariable( o_muons, MuonCollection.c_str() ); 
  if(TauCollection.size()>0) DeclareVariable( o_taus, TauCollection.c_str() );
  if(JetCollection.size()>0) DeclareVariable( o_jets, JetCollection.c_str() );
  if(PhotonCollection.size()>0) DeclareVariable( o_photons, PhotonCollection.c_str() );
  if(METName.size()>0) DeclareVariable( o_met, METName.c_str() );
  if(PrimaryVertexCollection.size()>0) DeclareVariable( o_pvs, PrimaryVertexCollection.c_str());
  if(TopJetCollection.size()>0) DeclareVariable( o_topjets, TopJetCollection.c_str());
  if(PrunedJetCollection.size()>0) DeclareVariable( o_prunedjets, PrunedJetCollection.c_str());
  if(addGenInfo && GenParticleCollection.size()>0) DeclareVariable( o_genparticles, GenParticleCollection.c_str());
  if(addGenInfo) DeclareVariable( o_genInfo, "genInfo" );
  DeclareVariable( o_triggerNames, "triggerNames");
  DeclareVariable( o_triggerResults, "triggerResults");  


  return;

}

void SelectionCycle::EndInputData( const SInputData& ) throw( SError ) {

  first_selection->printCutFlow();
  second_selection->printCutFlow();
  return;
  
}

void SelectionCycle::BeginInputFile( const SInputData& ) throw( SError ) {

  ConnectVariable( "AnalysisTree", "triggerResults" , bcc.triggerResults);
  ConnectVariable( "AnalysisTree", "triggerNames" , bcc.triggerNames);
  if(ElectronCollection.size()>0) ConnectVariable( "AnalysisTree", ElectronCollection.c_str() ,bcc. electrons);
  if(MuonCollection.size()>0) ConnectVariable( "AnalysisTree", MuonCollection.c_str() , bcc.muons); 
  if(TauCollection.size()>0) ConnectVariable( "AnalysisTree", TauCollection.c_str() , bcc.taus);
  if(JetCollection.size()>0) ConnectVariable( "AnalysisTree", JetCollection.c_str() , bcc.jets);
  if(PhotonCollection.size()>0) ConnectVariable( "AnalysisTree", PhotonCollection.c_str() , bcc.photons);
  if(METName.size()>0) ConnectVariable( "AnalysisTree", METName.c_str() , bcc.met);
  if(PrimaryVertexCollection.size()>0) ConnectVariable( "AnalysisTree", PrimaryVertexCollection.c_str() , bcc.pvs);
  if(TopJetCollection.size()>0) ConnectVariable( "AnalysisTree", TopJetCollection.c_str() , bcc.topjets);
  if(PrunedJetCollection.size()>0) ConnectVariable( "AnalysisTree", PrunedJetCollection.c_str() , bcc.prunedjets);
  if(GenParticleCollection.size()>0) ConnectVariable( "AnalysisTree", GenParticleCollection.c_str() , bcc.genparticles);
  if(addGenInfo) ConnectVariable( "AnalysisTree", "genInfo" , bcc.genInfo);
  ConnectVariable( "AnalysisTree", "run" , bcc.run);
  ConnectVariable( "AnalysisTree", "luminosityBlock" , bcc.luminosityBlock);
  ConnectVariable( "AnalysisTree" ,"event" ,bcc.event);
  ConnectVariable( "AnalysisTree", "rho" , bcc.rho);
  ConnectVariable( "AnalysisTree" ,"isRealData", bcc.isRealData);
  //ConnectVariable( "AnalysisTree" ,"HBHENoiseFilterResult", bcc.HBHENoiseFilterResult);
  ConnectVariable( "AnalysisTree" ,"beamspot_x0", bcc.beamspot_x0);
  ConnectVariable( "AnalysisTree" ,"beamspot_y0", bcc.beamspot_y0);
  ConnectVariable( "AnalysisTree" ,"beamspot_z0", bcc.beamspot_z0);

  return;

}

void SelectionCycle::ExecuteEvent( const SInputData&, Double_t weight) throw( SError ) {

  if(bcc.isRealData && addGenInfo){
    m_logger << WARNING<< "this seems to be real data but addGenInfo=True from config file" << SLogger::endmsg;
  }

  //fill list of trigger names
  if(bcc.triggerNames->size()!=0){
    bcc.triggerNames_actualrun = *bcc.triggerNames;
    newrun=true;
  }

  //clean collections here

  Cleaner cleaner(&bcc);

  if(bcc.pvs)  cleaner.PrimaryVertexCleaner(4, 24., 2.);
  if(bcc.electrons) cleaner.ElectronCleaner_noIso(70,2.5);
  if(bcc.muons) cleaner.MuonCleaner_noIso(35,2.1);
  if(bcc.jets) cleaner.JetLeptonSubtractor(corrector);
  if(!bcc.isRealData && bcc.jets) cleaner.JetEnergyResolutionShifter();
  //apply loose jet cleaning for 2D cut
  if(bcc.jets) cleaner.JetCleaner(25,double_infinity(),true);

  if(!first_selection->passSelection(&bcc))  throw SError( SError::SkipEvent );

  //apply tighter jet cleaning for further cuts and analysis steps
  if(bcc.jets) cleaner.JetCleaner(50,2.4,true);
  
  if(!second_selection->passSelection(&bcc))  throw SError( SError::SkipEvent );

  //write out all objects
  
  o_photons.clear();
  o_jets.clear();
  o_electrons.clear();
  o_muons.clear();
  o_taus.clear();
  o_pvs.clear();
  o_topjets.clear();
  o_prunedjets.clear();
  o_genparticles.clear();
  o_triggerNames.clear();
  o_triggerResults.clear();
  
  if(PhotonCollection.size()>0) o_photons=*bcc.photons;
  if(JetCollection.size()>0) o_jets=*bcc.jets; 
  if(ElectronCollection.size()>0) o_electrons=*bcc.electrons;
  if(MuonCollection.size()>0) o_muons=*bcc.muons;
  if(TauCollection.size()>0) o_taus=*bcc.taus;
  if(PrimaryVertexCollection.size()>0) o_pvs=*bcc.pvs;
  if(METName.size()>0) o_met = *bcc.met; 
  if(addGenInfo) o_genInfo = *bcc.genInfo;
  if(TopJetCollection.size()>0) o_topjets=*bcc.topjets;
  if(PrunedJetCollection.size()>0) o_prunedjets=*bcc.prunedjets;
  if(GenParticleCollection.size()>0) o_genparticles=*bcc.genparticles;
  
  if(newrun) o_triggerNames = bcc.triggerNames_actualrun;//store trigger names only for new runs
  newrun=false;
  o_triggerResults = *bcc.triggerResults;

  return;

}
