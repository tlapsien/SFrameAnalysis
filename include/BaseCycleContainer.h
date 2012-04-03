
#ifndef BaseCycleContainer_H
#define BaseCycleContainer_H

struct BaseCycleContainer{
  //input variables
  int run;
  int luminosityBlock;
  int event;
  bool isRealData;
  bool HBHENoiseFilterResult;

  float beamspot_x0;
  float beamspot_y0;
  float beamspot_z0;
  
  std::vector< Electron >* electrons;  
  std::vector< Muon >* muons;
  std::vector< Tau >* taus;
  std::vector< Photon >* photons;
  std::vector< PrimaryVertex >* pvs;
  std::vector< Jet >* jets;
  std::vector< TopJet >* topjets;
  std::vector< TopJet >* prunedjets;
  std::vector< GenParticle >* genparticles;
  MET* met;
  
  GenInfo* genInfo;
 
  std::vector<std::string>* triggerNames;
  std::vector<bool>* triggerResults;
  std::vector<int>* L1_prescale;
  std::vector<int>* HLT_prescale;
};


#endif
