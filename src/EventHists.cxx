#include "include/EventHists.h"
#include "include/SelectionModules.h"
#include "include/AnalysisCycle.h"
#include <iostream>

using namespace std;

EventHists::EventHists(const char* name) : BaseHists(name)
{
  // named default constructor
  
}

EventHists::~EventHists()
{
  // default destructor, does nothing
}

void EventHists::Init()
{
  // book all histograms here
  Book( TH1F( "N_PrimVertices","number of primary vertices", 56,-0.5,55.5));
  Book( TH1F( "N_PrimVertices_ly","number of primary vertices", 56,-0.5,55.5));
  Book( TH1F( "Weights","weights", 100,0,2));
  Book( TH1F( "Weights_ly","weights", 100,0,2));
  Book( TH1F( "N_events_perlumibin", "N^{evt}", 44, 0, 22) );
  Book( TH1F( "HT", "H_{T}", 100,0,5000 ) );
  Book( TH1F( "HT_ly", "H_{T}", 100,0,5000 ) );
  Book( TH1F( "HTLep", "H_{T}Lep", 100,0,1000 ) );
  Book( TH1F( "HTLep_ly", "H_{T}Lep", 100,0,1000 ) );
  Book( TH1F( "HT_Jets", "H_{T} Jets", 100,0,3500 ) );
  Book( TH1F( "HT_Jets_ly", "H_{T} Jets", 100,0,3500 ) );
  Book( TH1F( "MET", "missing E_{T}", 200,0,1000 ) );
  Book( TH1F( "MET_ly", "missing E_{T}", 200,0,1000 ) );
  Book( TH1F( "ChargeSign", "",3,-1.5,1.5 ) );
  Book( TH1F( "ChargeSign_ly", "",3,-1.5,1.5 ) );
}

void EventHists::Fill()
{
   // important: get the event weight
  EventCalc* calc = EventCalc::Instance();
  double weight = calc -> GetWeight();
  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();
  TopJet topjet;
  
  // topjet=  bcc->topjets->at(0);
	  //pythia with allpf
	  // weight=(-0.000454599*topjet.pt()+1.85542)*weight;
	  //pythia
	  //if(topjet.pt()<600) weight=(-0.00769656*topjet.pt()+5.6314)*weight;
	  // weight=(-0.000379343*(topjet.pt()-80)+1.42218)*weight;
	  //polynom CA15 pythia gauss
	  // weight=(1.09821e+00*exp(-0.5*pow((topjet.pt()-4.51606e+02)/4.73986e+01,2))+1.35922e+00-3.04198e-04*topjet.pt())*weight;
	  // if(weight<0) weight=0;
	  //[0]*exp(-0.5*((x-[1])/[2])**2)

	  /*  weight=
	    (-537.779+
	    5.76144*topjet.pt()
	    -0.0260814*pow(topjet.pt(),2)
	    +6.60249e-05*pow(topjet.pt(),3)
	    -1.0344e-07*pow(topjet.pt(),4)
	    +1.04341e-10*pow(topjet.pt(),5)
	    -6.79438e-14*pow(topjet.pt(),6)
	    +2.76038e-17*pow(topjet.pt(),7)
	    -6.36222e-21*pow(topjet.pt(),8)
	    +6.35006e-25*pow(topjet.pt(),9))*weight;*/
	  //herwig
	  // weight=(0.000948735*topjet.pt()+1.47648)*weight;
	  // pythia CA8
	  // weight=(-0.000377752*topjet.pt()+1.59353)*weight;
	  //herwig CA8
  //	  weight=(0.00137297*topjet.pt()+1.49578)*weight;
	  //  if(topjet.pt()<400) weight=weight;
	  // else weight=(-0.000395331*topjet.pt()+1.59101)*weight;



  LuminosityHandler* lumih = calc->GetLumiHandler();
  //  BaseCycleContainer* bcc = calc->GetBaseCycleContainer();

  int NPrimVertices = bcc-> pvs -> size();
  Hist("N_PrimVertices")-> Fill(NPrimVertices,weight);
  Hist("N_PrimVertices_ly")-> Fill(NPrimVertices,weight);

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  if(calc->IsRealData()){ 
    Hist( "N_events_perlumibin")->Fill( lumih->GetLumiBin(run, lumiblock)*0.5, weight);
  }

  Hist("Weights")-> Fill(weight);
  Hist("Weights_ly")-> Fill(weight); 

  double HT =0;
  double HT_MET = 0;
  double HT_Jets =0;
  
  HT = calc->GetHT();
  double HTlep = calc->GetHTlep();

  const unsigned int njets = bcc->jets ? bcc->jets->size() : 0;
  for(unsigned int i=0; i< njets; ++i){
     const Jet & jet =  bcc->jets->at(i);
     HT_Jets= HT_Jets + jet.pt();      
  }
  double met = bcc->met ? bcc->met->pt() : -1.0;
  
  
  Hist("HT")->Fill(HT, weight);
  Hist("HT_ly")->Fill(HT, weight);
  Hist("HTLep")->Fill(HTlep, weight);
  Hist("HTLep_ly")->Fill(HTlep, weight);
  Hist("HT_Jets")->Fill(HT_Jets, weight);
  Hist("HT_Jets_ly")->Fill(HT_Jets, weight);
  Hist("MET")->Fill(met, weight);
  Hist("MET_ly")->Fill(met, weight);
 
  double charge = -1; // -1 means "not available" ...
  
  if(bcc->muons && bcc->taus){
    charge = 1;
    if (bcc->muons->size() == 1 && bcc->taus->size() == 1){
        const Muon &  muon = bcc->muons->at(0);
        const Tau & tau = bcc->taus->at(0);
        if (muon.charge() != tau.charge()) charge = -1;
    }
    else if(bcc->taus->size() == 0 && bcc->muons->size() == 2){
        const Muon & muon1 = bcc->muons->at(0);
        const Muon & muon2 = bcc->muons->at(1);
        if (muon1.charge() != muon2.charge()) charge = -1;
    }
    if (bcc->taus->size() == 0 && bcc->muons->size() == 1) charge = 0;
  }
  
  Hist("ChargeSign")->Fill(charge, weight);
  Hist("ChargeSign_ly")->Fill(charge, weight);
}


