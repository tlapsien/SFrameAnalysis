#include "include/TMVATreeFiller.h"

#include "SFrameTools/include/EventCalc.h"
#include "NtupleWriter/include/JetProps.h"
#include "UHHAnalysis/NtupleWriter/interface/Nsubjettiness.h"
#include "UHHAnalysis/NtupleWriter/interface/QjetsPlugin.h"
#include "fastjet/tools/Pruner.hh"

#include <iostream>

using namespace std;

TMVATreeFiller::TMVATreeFiller(const char* name, TTree * t) : BaseHists(name), m_tree(t)
{
  // named default constructor
}

TMVATreeFiller::~TMVATreeFiller()
{
  // default destructor, does nothing
}

void TMVATreeFiller::Init()
{  
  m_tree->Branch("pf_pt1",&m_pf_pt[0],"pf_pt1/D");
  m_tree->Branch("pf_pt2",&m_pf_pt[1],"pf_pt2/D");
  m_tree->Branch("pf_pt3",&m_pf_pt[2],"pf_pt3/D");
  m_tree->Branch("pf_pt4",&m_pf_pt[3],"pf_pt4/D");
  m_tree->Branch("pf_pt5",&m_pf_pt[4],"pf_pt5/D");
  m_tree->Branch("pf_pt6",&m_pf_pt[5],"pf_pt6/D");
  m_tree->Branch("pf_pt7",&m_pf_pt[6],"pf_pt7/D");
  m_tree->Branch("pf_pt8",&m_pf_pt[7],"pf_pt8/D");
  m_tree->Branch("pf_pt9",&m_pf_pt[8],"pf_pt9/D");
  m_tree->Branch("pf_pt10",&m_pf_pt[9],"pf_pt10/D");
  
   m_tree->Branch("pf_pt11",&m_pf_pt[10],"pf_pt11/D");
  m_tree->Branch("pf_pt12",&m_pf_pt[11],"pf_pt12/D");
  m_tree->Branch("pf_pt13",&m_pf_pt[12],"pf_pt13/D");
  m_tree->Branch("pf_pt14",&m_pf_pt[13],"pf_pt14/D");
  m_tree->Branch("pf_pt15",&m_pf_pt[14],"pf_pt15/D");
  m_tree->Branch("pf_pt16",&m_pf_pt[15],"pf_pt16/D");
  m_tree->Branch("pf_pt17",&m_pf_pt[16],"pf_pt17/D");
  m_tree->Branch("pf_pt18",&m_pf_pt[17],"pf_pt18/D");
  m_tree->Branch("pf_pt19",&m_pf_pt[18],"pf_pt19/D");
  m_tree->Branch("pf_pt20",&m_pf_pt[19],"pf_pt20/D");

 m_tree->Branch("pf_pt21",&m_pf_pt[20],"pf_pt21/D");
 m_tree->Branch("pf_pt22",&m_pf_pt[21],"pf_pt22/D");
  m_tree->Branch("pf_pt23",&m_pf_pt[22],"pf_pt23/D");
  m_tree->Branch("pf_pt24",&m_pf_pt[23],"pf_pt24/D");
  m_tree->Branch("pf_pt25",&m_pf_pt[24],"pf_pt25/D");
  m_tree->Branch("pf_pt26",&m_pf_pt[25],"pf_pt26/D");
  m_tree->Branch("pf_pt27",&m_pf_pt[26],"pf_pt27/D");
  m_tree->Branch("pf_pt28",&m_pf_pt[27],"pf_pt28/D");
  m_tree->Branch("pf_pt29",&m_pf_pt[28],"pf_pt29/D");
  m_tree->Branch("pf_pt30",&m_pf_pt[29],"pf_pt30/D");

 m_tree->Branch("pf_pt31",&m_pf_pt[30],"pf_pt31/D");
  m_tree->Branch("pf_pt32",&m_pf_pt[31],"pf_pt32/D");
  m_tree->Branch("pf_pt33",&m_pf_pt[32],"pf_pt33/D");
  m_tree->Branch("pf_pt34",&m_pf_pt[33],"pf_pt34/D");
  m_tree->Branch("pf_pt35",&m_pf_pt[34],"pf_pt35/D");
  m_tree->Branch("pf_pt36",&m_pf_pt[35],"pf_pt36/D");
  m_tree->Branch("pf_pt37",&m_pf_pt[36],"pf_pt37/D");
  m_tree->Branch("pf_pt38",&m_pf_pt[37],"pf_pt38/D");
  m_tree->Branch("pf_pt39",&m_pf_pt[38],"pf_pt39/D");
  m_tree->Branch("pf_pt40",&m_pf_pt[39],"pf_pt40/D");

 m_tree->Branch("pf_pt41",&m_pf_pt[40],"pf_pt51/D");
  m_tree->Branch("pf_pt42",&m_pf_pt[41],"pf_pt52/D");
  m_tree->Branch("pf_pt43",&m_pf_pt[42],"pf_pt53/D");
  m_tree->Branch("pf_pt44",&m_pf_pt[43],"pf_pt54/D");
  m_tree->Branch("pf_pt45",&m_pf_pt[44],"pf_pt55/D");
  m_tree->Branch("pf_pt46",&m_pf_pt[45],"pf_pt56/D");
  m_tree->Branch("pf_pt47",&m_pf_pt[46],"pf_pt57/D");
  m_tree->Branch("pf_pt48",&m_pf_pt[47],"pf_pt58/D");
  m_tree->Branch("pf_pt49",&m_pf_pt[48],"pf_pt59/D");
  m_tree->Branch("pf_pt50",&m_pf_pt[49],"pf_pt60/D");

 m_tree->Branch("pf_pt51",&m_pf_pt[50],"pf_pt51/D");
  m_tree->Branch("pf_pt52",&m_pf_pt[51],"pf_pt52/D");
  m_tree->Branch("pf_pt53",&m_pf_pt[52],"pf_pt53/D");
  m_tree->Branch("pf_pt54",&m_pf_pt[53],"pf_pt54/D");
  m_tree->Branch("pf_pt55",&m_pf_pt[54],"pf_pt55/D");
  m_tree->Branch("pf_pt56",&m_pf_pt[55],"pf_pt56/D");
  m_tree->Branch("pf_pt57",&m_pf_pt[56],"pf_pt57/D");
  m_tree->Branch("pf_pt58",&m_pf_pt[57],"pf_pt58/D");
  m_tree->Branch("pf_pt59",&m_pf_pt[58],"pf_pt59/D");
  m_tree->Branch("pf_pt60",&m_pf_pt[59],"pf_pt60/D");

 m_tree->Branch("pf_pt61",&m_pf_pt[60],"pf_pt61/D");
  m_tree->Branch("pf_pt62",&m_pf_pt[61],"pf_pt62/D");
  m_tree->Branch("pf_pt63",&m_pf_pt[62],"pf_pt63/D");
  m_tree->Branch("pf_pt64",&m_pf_pt[63],"pf_pt64/D");
  m_tree->Branch("pf_pt65",&m_pf_pt[64],"pf_pt65/D");
  m_tree->Branch("pf_pt66",&m_pf_pt[65],"pf_pt66/D");
  m_tree->Branch("pf_pt67",&m_pf_pt[66],"pf_pt67/D");
  m_tree->Branch("pf_pt68",&m_pf_pt[67],"pf_pt68/D");
  m_tree->Branch("pf_pt69",&m_pf_pt[68],"pf_pt69/D");
  m_tree->Branch("pf_pt70",&m_pf_pt[69],"pf_pt70/D");

 m_tree->Branch("pf_pt71",&m_pf_pt[70],"pf_pt71/D");
  m_tree->Branch("pf_pt72",&m_pf_pt[71],"pf_pt72/D");
  m_tree->Branch("pf_pt73",&m_pf_pt[72],"pf_pt73/D");
  m_tree->Branch("pf_pt74",&m_pf_pt[73],"pf_pt74/D");
  m_tree->Branch("pf_pt75",&m_pf_pt[74],"pf_pt75/D");
  m_tree->Branch("pf_pt76",&m_pf_pt[75],"pf_pt76/D");
  m_tree->Branch("pf_pt77",&m_pf_pt[76],"pf_pt77/D");
  m_tree->Branch("pf_pt78",&m_pf_pt[77],"pf_pt78/D");
  m_tree->Branch("pf_pt79",&m_pf_pt[78],"pf_pt79/D");
  m_tree->Branch("pf_pt80",&m_pf_pt[79],"pf_pt80/D");

 m_tree->Branch("pf_pt81",&m_pf_pt[80],"pf_pt81/D");
  m_tree->Branch("pf_pt82",&m_pf_pt[81],"pf_pt82/D");
  m_tree->Branch("pf_pt83",&m_pf_pt[82],"pf_pt83/D");
  m_tree->Branch("pf_pt84",&m_pf_pt[83],"pf_pt84/D");
  m_tree->Branch("pf_pt85",&m_pf_pt[84],"pf_pt85/D");
  m_tree->Branch("pf_pt86",&m_pf_pt[85],"pf_pt86/D");
  m_tree->Branch("pf_pt87",&m_pf_pt[86],"pf_pt87/D");
  m_tree->Branch("pf_pt88",&m_pf_pt[87],"pf_pt88/D");
  m_tree->Branch("pf_pt89",&m_pf_pt[88],"pf_pt89/D");
  m_tree->Branch("pf_pt90",&m_pf_pt[89],"pf_pt90/D");

  m_tree->Branch("pf_pt91",&m_pf_pt[90],"pf_pt91/D");
  m_tree->Branch("pf_pt92",&m_pf_pt[91],"pf_pt92/D");
  m_tree->Branch("pf_pt93",&m_pf_pt[92],"pf_pt93/D");
  m_tree->Branch("pf_pt94",&m_pf_pt[93],"pf_pt94/D");
  m_tree->Branch("pf_pt95",&m_pf_pt[94],"pf_pt95/D");
  m_tree->Branch("pf_pt96",&m_pf_pt[95],"pf_pt96/D");
  m_tree->Branch("pf_pt97",&m_pf_pt[96],"pf_pt97/D");
  m_tree->Branch("pf_pt98",&m_pf_pt[97],"pf_pt98/D");
  m_tree->Branch("pf_pt99",&m_pf_pt[98],"pf_pt99/D");
  m_tree->Branch("pf_pt100",&m_pf_pt[99],"pf_pt100/D");


  m_tree->Branch("pf_phi1",&m_pf_phi[0],"pf_phi1/D");
  m_tree->Branch("pf_phi2",&m_pf_phi[1],"pf_phi2/D");
  m_tree->Branch("pf_phi3",&m_pf_phi[2],"pf_phi3/D");
  m_tree->Branch("pf_phi4",&m_pf_phi[3],"pf_phi4/D");
  m_tree->Branch("pf_phi5",&m_pf_phi[4],"pf_phi5/D");
  m_tree->Branch("pf_phi6",&m_pf_phi[5],"pf_phi6/D");
  m_tree->Branch("pf_phi7",&m_pf_phi[6],"pf_phi7/D");
  m_tree->Branch("pf_phi8",&m_pf_phi[7],"pf_phi8/D");
  m_tree->Branch("pf_phi9",&m_pf_phi[8],"pf_phi9/D");
  m_tree->Branch("pf_phi10",&m_pf_phi[9],"pf_phi10/D");
  
   m_tree->Branch("pf_phi11",&m_pf_phi[10],"pf_phi11/D");
  m_tree->Branch("pf_phi12",&m_pf_phi[11],"pf_phi12/D");
  m_tree->Branch("pf_phi13",&m_pf_phi[12],"pf_phi13/D");
  m_tree->Branch("pf_phi14",&m_pf_phi[13],"pf_phi14/D");
  m_tree->Branch("pf_phi15",&m_pf_phi[14],"pf_phi15/D");
  m_tree->Branch("pf_phi16",&m_pf_phi[15],"pf_phi16/D");
  m_tree->Branch("pf_phi17",&m_pf_phi[16],"pf_phi17/D");
  m_tree->Branch("pf_phi18",&m_pf_phi[17],"pf_phi18/D");
  m_tree->Branch("pf_phi19",&m_pf_phi[18],"pf_phi19/D");
  m_tree->Branch("pf_phi20",&m_pf_phi[19],"pf_phi20/D");

 m_tree->Branch("pf_phi21",&m_pf_phi[20],"pf_phi21/D");
 m_tree->Branch("pf_phi22",&m_pf_phi[21],"pf_phi22/D");
  m_tree->Branch("pf_phi23",&m_pf_phi[22],"pf_phi23/D");
  m_tree->Branch("pf_phi24",&m_pf_phi[23],"pf_phi24/D");
  m_tree->Branch("pf_phi25",&m_pf_phi[24],"pf_phi25/D");
  m_tree->Branch("pf_phi26",&m_pf_phi[25],"pf_phi26/D");
  m_tree->Branch("pf_phi27",&m_pf_phi[26],"pf_phi27/D");
  m_tree->Branch("pf_phi28",&m_pf_phi[27],"pf_phi28/D");
  m_tree->Branch("pf_phi29",&m_pf_phi[28],"pf_phi29/D");
  m_tree->Branch("pf_phi30",&m_pf_phi[29],"pf_phi30/D");

 m_tree->Branch("pf_phi31",&m_pf_phi[30],"pf_phi31/D");
  m_tree->Branch("pf_phi32",&m_pf_phi[31],"pf_phi32/D");
  m_tree->Branch("pf_phi33",&m_pf_phi[32],"pf_phi33/D");
  m_tree->Branch("pf_phi34",&m_pf_phi[33],"pf_phi34/D");
  m_tree->Branch("pf_phi35",&m_pf_phi[34],"pf_phi35/D");
  m_tree->Branch("pf_phi36",&m_pf_phi[35],"pf_phi36/D");
  m_tree->Branch("pf_phi37",&m_pf_phi[36],"pf_phi37/D");
  m_tree->Branch("pf_phi38",&m_pf_phi[37],"pf_phi38/D");
  m_tree->Branch("pf_phi39",&m_pf_phi[38],"pf_phi39/D");
  m_tree->Branch("pf_phi40",&m_pf_phi[39],"pf_phi40/D");

 m_tree->Branch("pf_phi41",&m_pf_phi[40],"pf_phi51/D");
  m_tree->Branch("pf_phi42",&m_pf_phi[41],"pf_phi52/D");
  m_tree->Branch("pf_phi43",&m_pf_phi[42],"pf_phi53/D");
  m_tree->Branch("pf_phi44",&m_pf_phi[43],"pf_phi54/D");
  m_tree->Branch("pf_phi45",&m_pf_phi[44],"pf_phi55/D");
  m_tree->Branch("pf_phi46",&m_pf_phi[45],"pf_phi56/D");
  m_tree->Branch("pf_phi47",&m_pf_phi[46],"pf_phi57/D");
  m_tree->Branch("pf_phi48",&m_pf_phi[47],"pf_phi58/D");
  m_tree->Branch("pf_phi49",&m_pf_phi[48],"pf_phi59/D");
  m_tree->Branch("pf_phi50",&m_pf_phi[49],"pf_phi60/D");

 m_tree->Branch("pf_phi51",&m_pf_phi[50],"pf_phi51/D");
  m_tree->Branch("pf_phi52",&m_pf_phi[51],"pf_phi52/D");
  m_tree->Branch("pf_phi53",&m_pf_phi[52],"pf_phi53/D");
  m_tree->Branch("pf_phi54",&m_pf_phi[53],"pf_phi54/D");
  m_tree->Branch("pf_phi55",&m_pf_phi[54],"pf_phi55/D");
  m_tree->Branch("pf_phi56",&m_pf_phi[55],"pf_phi56/D");
  m_tree->Branch("pf_phi57",&m_pf_phi[56],"pf_phi57/D");
  m_tree->Branch("pf_phi58",&m_pf_phi[57],"pf_phi58/D");
  m_tree->Branch("pf_phi59",&m_pf_phi[58],"pf_phi59/D");
  m_tree->Branch("pf_phi60",&m_pf_phi[59],"pf_phi60/D");

 m_tree->Branch("pf_phi61",&m_pf_phi[60],"pf_phi61/D");
  m_tree->Branch("pf_phi62",&m_pf_phi[61],"pf_phi62/D");
  m_tree->Branch("pf_phi63",&m_pf_phi[62],"pf_phi63/D");
  m_tree->Branch("pf_phi64",&m_pf_phi[63],"pf_phi64/D");
  m_tree->Branch("pf_phi65",&m_pf_phi[64],"pf_phi65/D");
  m_tree->Branch("pf_phi66",&m_pf_phi[65],"pf_phi66/D");
  m_tree->Branch("pf_phi67",&m_pf_phi[66],"pf_phi67/D");
  m_tree->Branch("pf_phi68",&m_pf_phi[67],"pf_phi68/D");
  m_tree->Branch("pf_phi69",&m_pf_phi[68],"pf_phi69/D");
  m_tree->Branch("pf_phi70",&m_pf_phi[69],"pf_phi70/D");

 m_tree->Branch("pf_phi71",&m_pf_phi[70],"pf_phi71/D");
  m_tree->Branch("pf_phi72",&m_pf_phi[71],"pf_phi72/D");
  m_tree->Branch("pf_phi73",&m_pf_phi[72],"pf_phi73/D");
  m_tree->Branch("pf_phi74",&m_pf_phi[73],"pf_phi74/D");
  m_tree->Branch("pf_phi75",&m_pf_phi[74],"pf_phi75/D");
  m_tree->Branch("pf_phi76",&m_pf_phi[75],"pf_phi76/D");
  m_tree->Branch("pf_phi77",&m_pf_phi[76],"pf_phi77/D");
  m_tree->Branch("pf_phi78",&m_pf_phi[77],"pf_phi78/D");
  m_tree->Branch("pf_phi79",&m_pf_phi[78],"pf_phi79/D");
  m_tree->Branch("pf_phi80",&m_pf_phi[79],"pf_phi80/D");

 m_tree->Branch("pf_phi81",&m_pf_phi[80],"pf_phi81/D");
  m_tree->Branch("pf_phi82",&m_pf_phi[81],"pf_phi82/D");
  m_tree->Branch("pf_phi83",&m_pf_phi[82],"pf_phi83/D");
  m_tree->Branch("pf_phi84",&m_pf_phi[83],"pf_phi84/D");
  m_tree->Branch("pf_phi85",&m_pf_phi[84],"pf_phi85/D");
  m_tree->Branch("pf_phi86",&m_pf_phi[85],"pf_phi86/D");
  m_tree->Branch("pf_phi87",&m_pf_phi[86],"pf_phi87/D");
  m_tree->Branch("pf_phi88",&m_pf_phi[87],"pf_phi88/D");
  m_tree->Branch("pf_phi89",&m_pf_phi[88],"pf_phi89/D");
  m_tree->Branch("pf_phi90",&m_pf_phi[89],"pf_phi90/D");

  m_tree->Branch("pf_phi91",&m_pf_phi[90],"pf_phi91/D");
  m_tree->Branch("pf_phi92",&m_pf_phi[91],"pf_phi92/D");
  m_tree->Branch("pf_phi93",&m_pf_phi[92],"pf_phi93/D");
  m_tree->Branch("pf_phi94",&m_pf_phi[93],"pf_phi94/D");
  m_tree->Branch("pf_phi95",&m_pf_phi[94],"pf_phi95/D");
  m_tree->Branch("pf_phi96",&m_pf_phi[95],"pf_phi96/D");
  m_tree->Branch("pf_phi97",&m_pf_phi[96],"pf_phi97/D");
  m_tree->Branch("pf_phi98",&m_pf_phi[97],"pf_phi98/D");
  m_tree->Branch("pf_phi99",&m_pf_phi[98],"pf_phi99/D");
  m_tree->Branch("pf_phi100",&m_pf_phi[99],"pf_phi100/D");

 m_tree->Branch("pf_eta1",&m_pf_eta[0],"pf_eta1/D");
  m_tree->Branch("pf_eta2",&m_pf_eta[1],"pf_eta2/D");
  m_tree->Branch("pf_eta3",&m_pf_eta[2],"pf_eta3/D");
  m_tree->Branch("pf_eta4",&m_pf_eta[3],"pf_eta4/D");
  m_tree->Branch("pf_eta5",&m_pf_eta[4],"pf_eta5/D");
  m_tree->Branch("pf_eta6",&m_pf_eta[5],"pf_eta6/D");
  m_tree->Branch("pf_eta7",&m_pf_eta[6],"pf_eta7/D");
  m_tree->Branch("pf_eta8",&m_pf_eta[7],"pf_eta8/D");
  m_tree->Branch("pf_eta9",&m_pf_eta[8],"pf_eta9/D");
  m_tree->Branch("pf_eta10",&m_pf_eta[9],"pf_eta10/D");
  
   m_tree->Branch("pf_eta11",&m_pf_eta[10],"pf_eta11/D");
  m_tree->Branch("pf_eta12",&m_pf_eta[11],"pf_eta12/D");
  m_tree->Branch("pf_eta13",&m_pf_eta[12],"pf_eta13/D");
  m_tree->Branch("pf_eta14",&m_pf_eta[13],"pf_eta14/D");
  m_tree->Branch("pf_eta15",&m_pf_eta[14],"pf_eta15/D");
  m_tree->Branch("pf_eta16",&m_pf_eta[15],"pf_eta16/D");
  m_tree->Branch("pf_eta17",&m_pf_eta[16],"pf_eta17/D");
  m_tree->Branch("pf_eta18",&m_pf_eta[17],"pf_eta18/D");
  m_tree->Branch("pf_eta19",&m_pf_eta[18],"pf_eta19/D");
  m_tree->Branch("pf_eta20",&m_pf_eta[19],"pf_eta20/D");

 m_tree->Branch("pf_eta21",&m_pf_eta[20],"pf_eta21/D");
 m_tree->Branch("pf_eta22",&m_pf_eta[21],"pf_eta22/D");
  m_tree->Branch("pf_eta23",&m_pf_eta[22],"pf_eta23/D");
  m_tree->Branch("pf_eta24",&m_pf_eta[23],"pf_eta24/D");
  m_tree->Branch("pf_eta25",&m_pf_eta[24],"pf_eta25/D");
  m_tree->Branch("pf_eta26",&m_pf_eta[25],"pf_eta26/D");
  m_tree->Branch("pf_eta27",&m_pf_eta[26],"pf_eta27/D");
  m_tree->Branch("pf_eta28",&m_pf_eta[27],"pf_eta28/D");
  m_tree->Branch("pf_eta29",&m_pf_eta[28],"pf_eta29/D");
  m_tree->Branch("pf_eta30",&m_pf_eta[29],"pf_eta30/D");

 m_tree->Branch("pf_eta31",&m_pf_eta[30],"pf_eta31/D");
  m_tree->Branch("pf_eta32",&m_pf_eta[31],"pf_eta32/D");
  m_tree->Branch("pf_eta33",&m_pf_eta[32],"pf_eta33/D");
  m_tree->Branch("pf_eta34",&m_pf_eta[33],"pf_eta34/D");
  m_tree->Branch("pf_eta35",&m_pf_eta[34],"pf_eta35/D");
  m_tree->Branch("pf_eta36",&m_pf_eta[35],"pf_eta36/D");
  m_tree->Branch("pf_eta37",&m_pf_eta[36],"pf_eta37/D");
  m_tree->Branch("pf_eta38",&m_pf_eta[37],"pf_eta38/D");
  m_tree->Branch("pf_eta39",&m_pf_eta[38],"pf_eta39/D");
  m_tree->Branch("pf_eta40",&m_pf_eta[39],"pf_eta40/D");

 m_tree->Branch("pf_eta41",&m_pf_eta[40],"pf_eta51/D");
  m_tree->Branch("pf_eta42",&m_pf_eta[41],"pf_eta52/D");
  m_tree->Branch("pf_eta43",&m_pf_eta[42],"pf_eta53/D");
  m_tree->Branch("pf_eta44",&m_pf_eta[43],"pf_eta54/D");
  m_tree->Branch("pf_eta45",&m_pf_eta[44],"pf_eta55/D");
  m_tree->Branch("pf_eta46",&m_pf_eta[45],"pf_eta56/D");
  m_tree->Branch("pf_eta47",&m_pf_eta[46],"pf_eta57/D");
  m_tree->Branch("pf_eta48",&m_pf_eta[47],"pf_eta58/D");
  m_tree->Branch("pf_eta49",&m_pf_eta[48],"pf_eta59/D");
  m_tree->Branch("pf_eta50",&m_pf_eta[49],"pf_eta60/D");

 m_tree->Branch("pf_eta51",&m_pf_eta[50],"pf_eta51/D");
  m_tree->Branch("pf_eta52",&m_pf_eta[51],"pf_eta52/D");
  m_tree->Branch("pf_eta53",&m_pf_eta[52],"pf_eta53/D");
  m_tree->Branch("pf_eta54",&m_pf_eta[53],"pf_eta54/D");
  m_tree->Branch("pf_eta55",&m_pf_eta[54],"pf_eta55/D");
  m_tree->Branch("pf_eta56",&m_pf_eta[55],"pf_eta56/D");
  m_tree->Branch("pf_eta57",&m_pf_eta[56],"pf_eta57/D");
  m_tree->Branch("pf_eta58",&m_pf_eta[57],"pf_eta58/D");
  m_tree->Branch("pf_eta59",&m_pf_eta[58],"pf_eta59/D");
  m_tree->Branch("pf_eta60",&m_pf_eta[59],"pf_eta60/D");

 m_tree->Branch("pf_eta61",&m_pf_eta[60],"pf_eta61/D");
  m_tree->Branch("pf_eta62",&m_pf_eta[61],"pf_eta62/D");
  m_tree->Branch("pf_eta63",&m_pf_eta[62],"pf_eta63/D");
  m_tree->Branch("pf_eta64",&m_pf_eta[63],"pf_eta64/D");
  m_tree->Branch("pf_eta65",&m_pf_eta[64],"pf_eta65/D");
  m_tree->Branch("pf_eta66",&m_pf_eta[65],"pf_eta66/D");
  m_tree->Branch("pf_eta67",&m_pf_eta[66],"pf_eta67/D");
  m_tree->Branch("pf_eta68",&m_pf_eta[67],"pf_eta68/D");
  m_tree->Branch("pf_eta69",&m_pf_eta[68],"pf_eta69/D");
  m_tree->Branch("pf_eta70",&m_pf_eta[69],"pf_eta70/D");

 m_tree->Branch("pf_eta71",&m_pf_eta[70],"pf_eta71/D");
  m_tree->Branch("pf_eta72",&m_pf_eta[71],"pf_eta72/D");
  m_tree->Branch("pf_eta73",&m_pf_eta[72],"pf_eta73/D");
  m_tree->Branch("pf_eta74",&m_pf_eta[73],"pf_eta74/D");
  m_tree->Branch("pf_eta75",&m_pf_eta[74],"pf_eta75/D");
  m_tree->Branch("pf_eta76",&m_pf_eta[75],"pf_eta76/D");
  m_tree->Branch("pf_eta77",&m_pf_eta[76],"pf_eta77/D");
  m_tree->Branch("pf_eta78",&m_pf_eta[77],"pf_eta78/D");
  m_tree->Branch("pf_eta79",&m_pf_eta[78],"pf_eta79/D");
  m_tree->Branch("pf_eta80",&m_pf_eta[79],"pf_eta80/D");

 m_tree->Branch("pf_eta81",&m_pf_eta[80],"pf_eta81/D");
  m_tree->Branch("pf_eta82",&m_pf_eta[81],"pf_eta82/D");
  m_tree->Branch("pf_eta83",&m_pf_eta[82],"pf_eta83/D");
  m_tree->Branch("pf_eta84",&m_pf_eta[83],"pf_eta84/D");
  m_tree->Branch("pf_eta85",&m_pf_eta[84],"pf_eta85/D");
  m_tree->Branch("pf_eta86",&m_pf_eta[85],"pf_eta86/D");
  m_tree->Branch("pf_eta87",&m_pf_eta[86],"pf_eta87/D");
  m_tree->Branch("pf_eta88",&m_pf_eta[87],"pf_eta88/D");
  m_tree->Branch("pf_eta89",&m_pf_eta[88],"pf_eta89/D");
  m_tree->Branch("pf_eta90",&m_pf_eta[89],"pf_eta90/D");

  m_tree->Branch("pf_eta91",&m_pf_eta[90],"pf_eta91/D");
  m_tree->Branch("pf_eta92",&m_pf_eta[91],"pf_eta92/D");
  m_tree->Branch("pf_eta93",&m_pf_eta[92],"pf_eta93/D");
  m_tree->Branch("pf_eta94",&m_pf_eta[93],"pf_eta94/D");
  m_tree->Branch("pf_eta95",&m_pf_eta[94],"pf_eta95/D");
  m_tree->Branch("pf_eta96",&m_pf_eta[95],"pf_eta96/D");
  m_tree->Branch("pf_eta97",&m_pf_eta[96],"pf_eta97/D");
  m_tree->Branch("pf_eta98",&m_pf_eta[97],"pf_eta98/D");
  m_tree->Branch("pf_eta99",&m_pf_eta[98],"pf_eta99/D");
  m_tree->Branch("pf_eta100",&m_pf_eta[99],"pf_eta100/D");

 m_tree->Branch("pf_energy1",&m_pf_energy[0],"pf_energy1/D");
  m_tree->Branch("pf_energy2",&m_pf_energy[1],"pf_energy2/D");
  m_tree->Branch("pf_energy3",&m_pf_energy[2],"pf_energy3/D");
  m_tree->Branch("pf_energy4",&m_pf_energy[3],"pf_energy4/D");
  m_tree->Branch("pf_energy5",&m_pf_energy[4],"pf_energy5/D");
  m_tree->Branch("pf_energy6",&m_pf_energy[5],"pf_energy6/D");
  m_tree->Branch("pf_energy7",&m_pf_energy[6],"pf_energy7/D");
  m_tree->Branch("pf_energy8",&m_pf_energy[7],"pf_energy8/D");
  m_tree->Branch("pf_energy9",&m_pf_energy[8],"pf_energy9/D");
  m_tree->Branch("pf_energy10",&m_pf_energy[9],"pf_energy10/D");
  
   m_tree->Branch("pf_energy11",&m_pf_energy[10],"pf_energy11/D");
  m_tree->Branch("pf_energy12",&m_pf_energy[11],"pf_energy12/D");
  m_tree->Branch("pf_energy13",&m_pf_energy[12],"pf_energy13/D");
  m_tree->Branch("pf_energy14",&m_pf_energy[13],"pf_energy14/D");
  m_tree->Branch("pf_energy15",&m_pf_energy[14],"pf_energy15/D");
  m_tree->Branch("pf_energy16",&m_pf_energy[15],"pf_energy16/D");
  m_tree->Branch("pf_energy17",&m_pf_energy[16],"pf_energy17/D");
  m_tree->Branch("pf_energy18",&m_pf_energy[17],"pf_energy18/D");
  m_tree->Branch("pf_energy19",&m_pf_energy[18],"pf_energy19/D");
  m_tree->Branch("pf_energy20",&m_pf_energy[19],"pf_energy20/D");

 m_tree->Branch("pf_energy21",&m_pf_energy[20],"pf_energy21/D");
 m_tree->Branch("pf_energy22",&m_pf_energy[21],"pf_energy22/D");
  m_tree->Branch("pf_energy23",&m_pf_energy[22],"pf_energy23/D");
  m_tree->Branch("pf_energy24",&m_pf_energy[23],"pf_energy24/D");
  m_tree->Branch("pf_energy25",&m_pf_energy[24],"pf_energy25/D");
  m_tree->Branch("pf_energy26",&m_pf_energy[25],"pf_energy26/D");
  m_tree->Branch("pf_energy27",&m_pf_energy[26],"pf_energy27/D");
  m_tree->Branch("pf_energy28",&m_pf_energy[27],"pf_energy28/D");
  m_tree->Branch("pf_energy29",&m_pf_energy[28],"pf_energy29/D");
  m_tree->Branch("pf_energy30",&m_pf_energy[29],"pf_energy30/D");

 m_tree->Branch("pf_energy31",&m_pf_energy[30],"pf_energy31/D");
  m_tree->Branch("pf_energy32",&m_pf_energy[31],"pf_energy32/D");
  m_tree->Branch("pf_energy33",&m_pf_energy[32],"pf_energy33/D");
  m_tree->Branch("pf_energy34",&m_pf_energy[33],"pf_energy34/D");
  m_tree->Branch("pf_energy35",&m_pf_energy[34],"pf_energy35/D");
  m_tree->Branch("pf_energy36",&m_pf_energy[35],"pf_energy36/D");
  m_tree->Branch("pf_energy37",&m_pf_energy[36],"pf_energy37/D");
  m_tree->Branch("pf_energy38",&m_pf_energy[37],"pf_energy38/D");
  m_tree->Branch("pf_energy39",&m_pf_energy[38],"pf_energy39/D");
  m_tree->Branch("pf_energy40",&m_pf_energy[39],"pf_energy40/D");

 m_tree->Branch("pf_energy41",&m_pf_energy[40],"pf_energy51/D");
  m_tree->Branch("pf_energy42",&m_pf_energy[41],"pf_energy52/D");
  m_tree->Branch("pf_energy43",&m_pf_energy[42],"pf_energy53/D");
  m_tree->Branch("pf_energy44",&m_pf_energy[43],"pf_energy54/D");
  m_tree->Branch("pf_energy45",&m_pf_energy[44],"pf_energy55/D");
  m_tree->Branch("pf_energy46",&m_pf_energy[45],"pf_energy56/D");
  m_tree->Branch("pf_energy47",&m_pf_energy[46],"pf_energy57/D");
  m_tree->Branch("pf_energy48",&m_pf_energy[47],"pf_energy58/D");
  m_tree->Branch("pf_energy49",&m_pf_energy[48],"pf_energy59/D");
  m_tree->Branch("pf_energy50",&m_pf_energy[49],"pf_energy60/D");

 m_tree->Branch("pf_energy51",&m_pf_energy[50],"pf_energy51/D");
  m_tree->Branch("pf_energy52",&m_pf_energy[51],"pf_energy52/D");
  m_tree->Branch("pf_energy53",&m_pf_energy[52],"pf_energy53/D");
  m_tree->Branch("pf_energy54",&m_pf_energy[53],"pf_energy54/D");
  m_tree->Branch("pf_energy55",&m_pf_energy[54],"pf_energy55/D");
  m_tree->Branch("pf_energy56",&m_pf_energy[55],"pf_energy56/D");
  m_tree->Branch("pf_energy57",&m_pf_energy[56],"pf_energy57/D");
  m_tree->Branch("pf_energy58",&m_pf_energy[57],"pf_energy58/D");
  m_tree->Branch("pf_energy59",&m_pf_energy[58],"pf_energy59/D");
  m_tree->Branch("pf_energy60",&m_pf_energy[59],"pf_energy60/D");

 m_tree->Branch("pf_energy61",&m_pf_energy[60],"pf_energy61/D");
  m_tree->Branch("pf_energy62",&m_pf_energy[61],"pf_energy62/D");
  m_tree->Branch("pf_energy63",&m_pf_energy[62],"pf_energy63/D");
  m_tree->Branch("pf_energy64",&m_pf_energy[63],"pf_energy64/D");
  m_tree->Branch("pf_energy65",&m_pf_energy[64],"pf_energy65/D");
  m_tree->Branch("pf_energy66",&m_pf_energy[65],"pf_energy66/D");
  m_tree->Branch("pf_energy67",&m_pf_energy[66],"pf_energy67/D");
  m_tree->Branch("pf_energy68",&m_pf_energy[67],"pf_energy68/D");
  m_tree->Branch("pf_energy69",&m_pf_energy[68],"pf_energy69/D");
  m_tree->Branch("pf_energy70",&m_pf_energy[69],"pf_energy70/D");

 m_tree->Branch("pf_energy71",&m_pf_energy[70],"pf_energy71/D");
  m_tree->Branch("pf_energy72",&m_pf_energy[71],"pf_energy72/D");
  m_tree->Branch("pf_energy73",&m_pf_energy[72],"pf_energy73/D");
  m_tree->Branch("pf_energy74",&m_pf_energy[73],"pf_energy74/D");
  m_tree->Branch("pf_energy75",&m_pf_energy[74],"pf_energy75/D");
  m_tree->Branch("pf_energy76",&m_pf_energy[75],"pf_energy76/D");
  m_tree->Branch("pf_energy77",&m_pf_energy[76],"pf_energy77/D");
  m_tree->Branch("pf_energy78",&m_pf_energy[77],"pf_energy78/D");
  m_tree->Branch("pf_energy79",&m_pf_energy[78],"pf_energy79/D");
  m_tree->Branch("pf_energy80",&m_pf_energy[79],"pf_energy80/D");

 m_tree->Branch("pf_energy81",&m_pf_energy[80],"pf_energy81/D");
  m_tree->Branch("pf_energy82",&m_pf_energy[81],"pf_energy82/D");
  m_tree->Branch("pf_energy83",&m_pf_energy[82],"pf_energy83/D");
  m_tree->Branch("pf_energy84",&m_pf_energy[83],"pf_energy84/D");
  m_tree->Branch("pf_energy85",&m_pf_energy[84],"pf_energy85/D");
  m_tree->Branch("pf_energy86",&m_pf_energy[85],"pf_energy86/D");
  m_tree->Branch("pf_energy87",&m_pf_energy[86],"pf_energy87/D");
  m_tree->Branch("pf_energy88",&m_pf_energy[87],"pf_energy88/D");
  m_tree->Branch("pf_energy89",&m_pf_energy[88],"pf_energy89/D");
  m_tree->Branch("pf_energy90",&m_pf_energy[89],"pf_energy90/D");

  m_tree->Branch("pf_energy91",&m_pf_energy[90],"pf_energy91/D");
  m_tree->Branch("pf_energy92",&m_pf_energy[91],"pf_energy92/D");
  m_tree->Branch("pf_energy93",&m_pf_energy[92],"pf_energy93/D");
  m_tree->Branch("pf_energy94",&m_pf_energy[93],"pf_energy94/D");
  m_tree->Branch("pf_energy95",&m_pf_energy[94],"pf_energy95/D");
  m_tree->Branch("pf_energy96",&m_pf_energy[95],"pf_energy96/D");
  m_tree->Branch("pf_energy97",&m_pf_energy[96],"pf_energy97/D");
  m_tree->Branch("pf_energy98",&m_pf_energy[97],"pf_energy98/D");
  m_tree->Branch("pf_energy99",&m_pf_energy[98],"pf_energy99/D");
  m_tree->Branch("pf_energy100",&m_pf_energy[99],"pf_energy100/D");

 m_tree->Branch("pf_charge1",&m_pf_charge[0],"pf_charge1/D");
  m_tree->Branch("pf_charge2",&m_pf_charge[1],"pf_charge2/D");
  m_tree->Branch("pf_charge3",&m_pf_charge[2],"pf_charge3/D");
  m_tree->Branch("pf_charge4",&m_pf_charge[3],"pf_charge4/D");
  m_tree->Branch("pf_charge5",&m_pf_charge[4],"pf_charge5/D");
  m_tree->Branch("pf_charge6",&m_pf_charge[5],"pf_charge6/D");
  m_tree->Branch("pf_charge7",&m_pf_charge[6],"pf_charge7/D");
  m_tree->Branch("pf_charge8",&m_pf_charge[7],"pf_charge8/D");
  m_tree->Branch("pf_charge9",&m_pf_charge[8],"pf_charge9/D");
  m_tree->Branch("pf_charge10",&m_pf_charge[9],"pf_charge10/D");
  
   m_tree->Branch("pf_charge11",&m_pf_charge[10],"pf_charge11/D");
  m_tree->Branch("pf_charge12",&m_pf_charge[11],"pf_charge12/D");
  m_tree->Branch("pf_charge13",&m_pf_charge[12],"pf_charge13/D");
  m_tree->Branch("pf_charge14",&m_pf_charge[13],"pf_charge14/D");
  m_tree->Branch("pf_charge15",&m_pf_charge[14],"pf_charge15/D");
  m_tree->Branch("pf_charge16",&m_pf_charge[15],"pf_charge16/D");
  m_tree->Branch("pf_charge17",&m_pf_charge[16],"pf_charge17/D");
  m_tree->Branch("pf_charge18",&m_pf_charge[17],"pf_charge18/D");
  m_tree->Branch("pf_charge19",&m_pf_charge[18],"pf_charge19/D");
  m_tree->Branch("pf_charge20",&m_pf_charge[19],"pf_charge20/D");

 m_tree->Branch("pf_charge21",&m_pf_charge[20],"pf_charge21/D");
 m_tree->Branch("pf_charge22",&m_pf_charge[21],"pf_charge22/D");
  m_tree->Branch("pf_charge23",&m_pf_charge[22],"pf_charge23/D");
  m_tree->Branch("pf_charge24",&m_pf_charge[23],"pf_charge24/D");
  m_tree->Branch("pf_charge25",&m_pf_charge[24],"pf_charge25/D");
  m_tree->Branch("pf_charge26",&m_pf_charge[25],"pf_charge26/D");
  m_tree->Branch("pf_charge27",&m_pf_charge[26],"pf_charge27/D");
  m_tree->Branch("pf_charge28",&m_pf_charge[27],"pf_charge28/D");
  m_tree->Branch("pf_charge29",&m_pf_charge[28],"pf_charge29/D");
  m_tree->Branch("pf_charge30",&m_pf_charge[29],"pf_charge30/D");

 m_tree->Branch("pf_charge31",&m_pf_charge[30],"pf_charge31/D");
  m_tree->Branch("pf_charge32",&m_pf_charge[31],"pf_charge32/D");
  m_tree->Branch("pf_charge33",&m_pf_charge[32],"pf_charge33/D");
  m_tree->Branch("pf_charge34",&m_pf_charge[33],"pf_charge34/D");
  m_tree->Branch("pf_charge35",&m_pf_charge[34],"pf_charge35/D");
  m_tree->Branch("pf_charge36",&m_pf_charge[35],"pf_charge36/D");
  m_tree->Branch("pf_charge37",&m_pf_charge[36],"pf_charge37/D");
  m_tree->Branch("pf_charge38",&m_pf_charge[37],"pf_charge38/D");
  m_tree->Branch("pf_charge39",&m_pf_charge[38],"pf_charge39/D");
  m_tree->Branch("pf_charge40",&m_pf_charge[39],"pf_charge40/D");

 m_tree->Branch("pf_charge41",&m_pf_charge[40],"pf_charge51/D");
  m_tree->Branch("pf_charge42",&m_pf_charge[41],"pf_charge52/D");
  m_tree->Branch("pf_charge43",&m_pf_charge[42],"pf_charge53/D");
  m_tree->Branch("pf_charge44",&m_pf_charge[43],"pf_charge54/D");
  m_tree->Branch("pf_charge45",&m_pf_charge[44],"pf_charge55/D");
  m_tree->Branch("pf_charge46",&m_pf_charge[45],"pf_charge56/D");
  m_tree->Branch("pf_charge47",&m_pf_charge[46],"pf_charge57/D");
  m_tree->Branch("pf_charge48",&m_pf_charge[47],"pf_charge58/D");
  m_tree->Branch("pf_charge49",&m_pf_charge[48],"pf_charge59/D");
  m_tree->Branch("pf_charge50",&m_pf_charge[49],"pf_charge60/D");

 m_tree->Branch("pf_charge51",&m_pf_charge[50],"pf_charge51/D");
  m_tree->Branch("pf_charge52",&m_pf_charge[51],"pf_charge52/D");
  m_tree->Branch("pf_charge53",&m_pf_charge[52],"pf_charge53/D");
  m_tree->Branch("pf_charge54",&m_pf_charge[53],"pf_charge54/D");
  m_tree->Branch("pf_charge55",&m_pf_charge[54],"pf_charge55/D");
  m_tree->Branch("pf_charge56",&m_pf_charge[55],"pf_charge56/D");
  m_tree->Branch("pf_charge57",&m_pf_charge[56],"pf_charge57/D");
  m_tree->Branch("pf_charge58",&m_pf_charge[57],"pf_charge58/D");
  m_tree->Branch("pf_charge59",&m_pf_charge[58],"pf_charge59/D");
  m_tree->Branch("pf_charge60",&m_pf_charge[59],"pf_charge60/D");

 m_tree->Branch("pf_charge61",&m_pf_charge[60],"pf_charge61/D");
  m_tree->Branch("pf_charge62",&m_pf_charge[61],"pf_charge62/D");
  m_tree->Branch("pf_charge63",&m_pf_charge[62],"pf_charge63/D");
  m_tree->Branch("pf_charge64",&m_pf_charge[63],"pf_charge64/D");
  m_tree->Branch("pf_charge65",&m_pf_charge[64],"pf_charge65/D");
  m_tree->Branch("pf_charge66",&m_pf_charge[65],"pf_charge66/D");
  m_tree->Branch("pf_charge67",&m_pf_charge[66],"pf_charge67/D");
  m_tree->Branch("pf_charge68",&m_pf_charge[67],"pf_charge68/D");
  m_tree->Branch("pf_charge69",&m_pf_charge[68],"pf_charge69/D");
  m_tree->Branch("pf_charge70",&m_pf_charge[69],"pf_charge70/D");

 m_tree->Branch("pf_charge71",&m_pf_charge[70],"pf_charge71/D");
  m_tree->Branch("pf_charge72",&m_pf_charge[71],"pf_charge72/D");
  m_tree->Branch("pf_charge73",&m_pf_charge[72],"pf_charge73/D");
  m_tree->Branch("pf_charge74",&m_pf_charge[73],"pf_charge74/D");
  m_tree->Branch("pf_charge75",&m_pf_charge[74],"pf_charge75/D");
  m_tree->Branch("pf_charge76",&m_pf_charge[75],"pf_charge76/D");
  m_tree->Branch("pf_charge77",&m_pf_charge[76],"pf_charge77/D");
  m_tree->Branch("pf_charge78",&m_pf_charge[77],"pf_charge78/D");
  m_tree->Branch("pf_charge79",&m_pf_charge[78],"pf_charge79/D");
  m_tree->Branch("pf_charge80",&m_pf_charge[79],"pf_charge80/D");

 m_tree->Branch("pf_charge81",&m_pf_charge[80],"pf_charge81/D");
  m_tree->Branch("pf_charge82",&m_pf_charge[81],"pf_charge82/D");
  m_tree->Branch("pf_charge83",&m_pf_charge[82],"pf_charge83/D");
  m_tree->Branch("pf_charge84",&m_pf_charge[83],"pf_charge84/D");
  m_tree->Branch("pf_charge85",&m_pf_charge[84],"pf_charge85/D");
  m_tree->Branch("pf_charge86",&m_pf_charge[85],"pf_charge86/D");
  m_tree->Branch("pf_charge87",&m_pf_charge[86],"pf_charge87/D");
  m_tree->Branch("pf_charge88",&m_pf_charge[87],"pf_charge88/D");
  m_tree->Branch("pf_charge89",&m_pf_charge[88],"pf_charge89/D");
  m_tree->Branch("pf_charge90",&m_pf_charge[89],"pf_charge90/D");

  m_tree->Branch("pf_charge91",&m_pf_charge[90],"pf_charge91/D");
  m_tree->Branch("pf_charge92",&m_pf_charge[91],"pf_charge92/D");
  m_tree->Branch("pf_charge93",&m_pf_charge[92],"pf_charge93/D");
  m_tree->Branch("pf_charge94",&m_pf_charge[93],"pf_charge94/D");
  m_tree->Branch("pf_charge95",&m_pf_charge[94],"pf_charge95/D");
  m_tree->Branch("pf_charge96",&m_pf_charge[95],"pf_charge96/D");
  m_tree->Branch("pf_charge97",&m_pf_charge[96],"pf_charge97/D");
  m_tree->Branch("pf_charge98",&m_pf_charge[97],"pf_charge98/D");
  m_tree->Branch("pf_charge99",&m_pf_charge[98],"pf_charge99/D");
  m_tree->Branch("pf_charge100",&m_pf_charge[99],"pf_charge100/D");

  m_tree->Branch("TopJet_px", &m_px, "TopJet_px/D");
  m_tree->Branch("TopJet_py", &m_py, "TopJet_py/D");
  m_tree->Branch("TopJet_pz", &m_pz, "TopJet_pz/D");
  m_tree->Branch("TopJet_pt", &m_pt, "TopJet_pt/D");
  m_tree->Branch("TopJet_pt_selection", &m_pt_selection, "TopJet_pt_selection/D");
  m_tree->Branch("TopJet_mass", &m_mass, "TopJet_mass/D");
  m_tree->Branch("Chi_sd",&m_chi,"Chi_sd/D");
  m_tree->Branch("TopQuark_px", &m_genpx, "TopQuark_px/D");
  m_tree->Branch("TopQuark_py", &m_genpy, "TopQuark_py/D");
  m_tree->Branch("TopQuark_pz", &m_genpz, "TopQuark_pz/D");

  m_tree->Branch("TopQuark_px", &m_genpx, "TopQuark_px/D");
  m_tree->Branch("TopQuark_py", &m_genpy, "TopQuark_py/D");
  m_tree->Branch("TopQuark_pz", &m_genpz, "TopQuark_pz/D");

  m_tree->Branch("bQuark_px", &m_b_genpx, "bQuark_px/D");
  m_tree->Branch("bQuark_py", &m_b_genpy, "bQuark_py/D");
  m_tree->Branch("bQuark_pz", &m_b_genpz, "bQuark_pz/D");

  m_tree->Branch("WQuark1_px", &m_wq1_genpx, "WQuark1_px/D");
  m_tree->Branch("WQuark1_py", &m_wq1_genpy, "WQuark1_py/D");
  m_tree->Branch("WQuark1_pz", &m_wq1_genpz, "WQuark1_pz/D");

  m_tree->Branch("WQuark2_px", &m_wq2_genpx, "WQuark2_px/D");
  m_tree->Branch("WQuark2_py", &m_wq2_genpy, "WQuark2_py/D");
  m_tree->Branch("WQuark2_pz", &m_wq2_genpz, "WQuark2_pz/D");

  m_tree->Branch("Event_NPV", &m_npv, "N_PV/I");
  m_tree->Branch("Event_Weight", &m_weight, "Event_Weight/D");

  m_tree->Branch("TopJet_tau1", &m_tau1, "TopJet_tau1/D");
  m_tree->Branch("TopJet_tau2", &m_tau2, "TopJet_tau2/D");  
  m_tree->Branch("TopJet_tau3", &m_tau3, "TopJet_tau3/D");
  m_tree->Branch("TopJet_tau4", &m_tau4, "TopJet_tau4/D");

  m_tree->Branch("TopJet_pruned_tau1", &m_pruned_tau1, "TopJet_pruned_tau1/D");
  m_tree->Branch("TopJet_pruned_tau2", &m_pruned_tau2, "TopJet_pruned_tau2/D");  
  m_tree->Branch("TopJet_pruned_tau3", &m_pruned_tau3, "TopJet_pruned_tau3/D");
  m_tree->Branch("TopJet_pruned_tau4", &m_pruned_tau4, "TopJet_pruned_tau4/D");

  m_tree->Branch("TopJet_psi_02", &m_psi_02, "TopJet_psi_02/D");
  m_tree->Branch("TopJet_psi_04", &m_psi_04, "TopJet_psi_04/D");
  m_tree->Branch("TopJet_psi_06", &m_psi_06, "TopJet_psi_06/D");

  m_tree->Branch("TopJet_Qjets_volatility", &m_qjets, "TopJet_Qjets_volatility/D");
  m_tree->Branch("TopJet_Qjets_volatility_mmin", &m_qjet_mmin, "TopJet_Qjets_volatility_mmin/D");
  m_tree->Branch("TopJet_Qjets_volatility_mass", &m_qjet_mass, "TopJet_Qjets_volatility_mass/D");
  m_tree->Branch("TopJet_Qjets_volatility_nsubjets", &m_qjet_nsubjets, "TopJet_Qjets_volatility_nsubjets/D");
  m_tree->Branch("TopJet_Qjets_volatility_nsubjettiness1", &m_qjet_nsubjettiness1, "TopJet_Qjets_volatility_nsubjettiness1/D");
  m_tree->Branch("TopJet_Qjets_volatility_nsubjettiness2", &m_qjet_nsubjettiness2, "TopJet_Qjets_volatility_nsubjettiness2/D");
  m_tree->Branch("TopJet_Qjets_volatility_nsubjettiness3", &m_qjet_nsubjettiness3, "TopJet_Qjets_volatility_nsubjettiness3/D");

  //jwj
   m_tree->Branch("TopJet_jwj01", &m_jetm01, "TopJet_jwj01/D");
   m_tree->Branch("TopJet_jwj02", &m_jetm01, "TopJet_jwj02/D");
   m_tree->Branch("TopJet_jwj03", &m_jetm01, "TopJet_jwj03/D");
   m_tree->Branch("TopJet_jwj04", &m_jetm01, "TopJet_jwj04/D");

   //ecf
    m_tree->Branch("TopJet_ecf_c3", &m_c3, "TopJet_ecf_c3/D");
     m_tree->Branch("TopJet_ecf_d3", &m_d3, "TopJet_ecf_d3/D");

     //softdrop
     m_tree->Branch("TopJet_softdrop_mass",&m_softdrop_mass,"TopJet_softdrop_mass/D");

  m_tree->Branch("TopJet_Nsubjets", &m_nsubs, "TopJet_Nsubjets/I");

  m_tree->Branch("TopJet_NConstituents", &m_number_of_constituents, "TopJet_Nconstituents/I");
  m_tree->Branch("TopJet_NChargedConstituents", &m_number_of_charged_constituents, "TopJet_NChargedConstituents/I");
  m_tree->Branch("TopJet_Charge", &m_jet_charge, "TopJet_Charge/D");
  m_tree->Branch("TopJet_WeightedCharge_k02", &m_weighted_jet_charge_02, "TopJet_WeightedCharge_k02/D");
  m_tree->Branch("TopJet_WeightedCharge_k04", &m_weighted_jet_charge_04, "TopJet_WeightedCharge_k04/D");  
  m_tree->Branch("TopJet_WeightedCharge_k06", &m_weighted_jet_charge_06, "TopJet_WeightedCharge_k06/D");
  m_tree->Branch("TopJet_WeightedCharge_k08", &m_weighted_jet_charge_08, "TopJet_WeightedCharge_k08/D");
  m_tree->Branch("TopJet_WeightedCharge", &m_weighted_jet_charge, "TopJet_WeightedCharge/D");
  m_tree->Branch("TopJet_FirstMoment", &m_first_jet_moment, "TopJet_FirstMoment/D");
  m_tree->Branch("TopJet_SecondMoment", &m_second_jet_moment, "TopJet_SecondMoment/D");

  m_tree->Branch("Subjet1_px", &m_sub1_px, "Subjet1_px/D");
  m_tree->Branch("Subjet1_py", &m_sub1_py, "Subjet1_py/D");
  m_tree->Branch("Subjet1_pz", &m_sub1_pz, "Subjet1_pz/D");
  m_tree->Branch("Subjet1_pt", &m_subjet1pt, "Subjet1_pt/D");
  m_tree->Branch("Subjet1_mass", &m_sub1_mass, "Subjet1_mass/D");

  m_tree->Branch("Subjet2_px", &m_sub2_px, "Subjet2_px/D");
  m_tree->Branch("Subjet2_py", &m_sub2_py, "Subjet2_py/D");
  m_tree->Branch("Subjet2_pz", &m_sub2_pz, "Subjet2_pz/D");
  m_tree->Branch("Subjet2_pt", &m_subjet2pt, "Subjet2_pt/D");
  m_tree->Branch("Subjet2_mass", &m_sub2_mass, "Subjet2_mass/D");

  m_tree->Branch("Subjet3_px", &m_sub3_px, "Subjet3_px/D");
  m_tree->Branch("Subjet3_py", &m_sub3_py, "Subjet3_py/D");
  m_tree->Branch("Subjet3_pz", &m_sub3_pz, "Subjet3_pz/D");
  m_tree->Branch("Subjet3_pt", &m_subjet3pt, "Subjet3_pt/D");
  m_tree->Branch("Subjet3_mass", &m_sub3_mass, "Subjet3_mass/D");

  m_tree->Branch("Subjet4_px", &m_sub4_px, "Subjet4_px/D");
  m_tree->Branch("Subjet4_py", &m_sub4_py, "Subjet4_py/D");
  m_tree->Branch("Subjet4_pz", &m_sub4_pz, "Subjet4_pz/D");
  m_tree->Branch("Subjet4_mass", &m_sub4_mass, "Subjet4_mass/D");

  m_tree->Branch("Subjets12_mass", &m_m12, "Subjet_mass12/D");
  m_tree->Branch("Subjets13_mass", &m_m13, "Subjet_mass13/D");
  m_tree->Branch("Subjets23_mass", &m_m23, "Subjet_mass23/D");

  m_tree->Branch("TopJet_pruned_mass", &m_pruned_mass, "TopJet_pruned_mass/D");
  m_tree->Branch("Subjets12_pruned_mass", &m_pruned_m12, "Subjet_pruned_mass12/D");
  m_tree->Branch("Subjets13_pruned_mass", &m_pruned_m13, "Subjet_pruned_mass13/D");
  m_tree->Branch("Subjets23_pruned_mass", &m_pruned_m23, "Subjet_pruned_mass23/D");

  m_tree->Branch("HelAng12", &m_HelAng12, "HelAng12/D");
  m_tree->Branch("HelAng13", &m_HelAng13, "HelAng13/D");
  m_tree->Branch("HelAng23", &m_HelAng23, "HelAng23/D");
  
  m_tree->Branch("TopJet_HEPTopTag", &m_HEPTopTag, "HEPTopTag/O");
  m_tree->Branch("TopJet_CMSTopTag", &m_CMSTopTag, "CMSTopTag/O");

   m_tree->Branch("dR1", &m_dR1, "dR1/D");
  m_tree->Branch("dR2", &m_dR2, "dR2/D");
  m_tree->Branch("dR3", &m_dR3, "dR3/D");

  Book( TH1F( "DR_top","#DeltaR_{jet,top}",100,0,3.5));  
  Book( TH1F( "DR_atop","#DeltaR_{jet,anti-top}",100,0,3.5));

  Book( TH1F( "TopGen_pt", "gen top P_{T} [GeV]", 100, 0, 1000));
  Book( TH1F( "MatchedJet_pt", "matched jet: gen top P_{T} [GeV]", 100, 0, 1000));

  Book( TH1F( "TopGen_eta", "gen top #eta (P_{T} > 200 GeV)", 50, -3, 3));
  Book( TH1F( "MatchedJet_eta", "matched jet: gen top #eta  (P_{T} > 200 GeV)", 50, -3, 3));

  Book( TH1F( "TopGen_NPV", "gen top N_{PV} (P_{T} > 200 GeV)", 51, 0, 50));
  Book( TH1F( "MatchedJet_NPV", "matched jet N_{PV} (P_{T} > 200 GeV)", 51, 0, 50));

  Book( TH1F( "DR_max_topjet_decayproducts", "#DeltaR_{max}(topjet, top decay products) ", 50, 0, 3) );
  Book( TH1F( "mass_decayproducts", "mass of top decay products [GeV]", 50, 170, 176 ) );

  Showerdeconstruction_tagger= new Showerdeconstruction();
  Softdrop = new SoftDrop();
  jwj = new Jetswithoutjets();
  ecf = new ECF();
}

void TMVATreeFiller::Fill()
{
  // fill the histograms
  
  EventCalc* calc = EventCalc::Instance();
  bool IsRealData = calc->IsRealData();
  LuminosityHandler* lumih = calc->GetLumiHandler();

  // important: get the event weight
  double weight = calc->GetWeight();

  int run = calc->GetRunNum();
  int lumiblock = calc->GetLumiBlock();
  int Npvs = calc->GetPrimaryVertices()->size();
  
  std::vector< TopJet >* tjets = calc->GetCAJets();

  // check if we got a ttbar event on generator level

  TTbarGen geninfo(calc->GetBaseCycleContainer());
  GenParticle top = geninfo.Top();
  GenParticle atop = geninfo.Antitop();

  // match the CA-jet with a top-jet only for a sample where ttbar quarks have been generated
  bool backgroundMC = false;
  if (top.pt()<0.001 && atop.pt()<0.001) backgroundMC = true;  

  if (!backgroundMC){
    double npv = calc->GetPrimaryVertices()->size();
    Hist("TopGen_pt")-> Fill(top.v4().pt(),weight);
    if (top.v4().pt()>250){
      Hist("TopGen_eta")-> Fill(top.v4().eta(),weight);
      Hist("TopGen_NPV")-> Fill(npv,weight);
    }    

    Hist("TopGen_pt")-> Fill(atop.v4().pt(),weight);
    if (atop.v4().pt()>250){
      Hist("TopGen_eta")-> Fill(atop.v4().eta(),weight);
      Hist("TopGen_NPV")-> Fill(npv,weight);
    }
  }

  for (UInt_t i=0; i<tjets->size(); ++i){

    ClearVariables();

    TopJet tj = tjets->at(i);

    bool is_signal = false;

    Double_t DR1 = RecGenMatch(tj, top);
    Double_t DR2 = RecGenMatch(tj, atop);

    GenParticle topquark;

    m_weight = weight;
    Hist("DR_top")-> Fill(DR1,weight);
    Hist("DR_atop")-> Fill(DR2,weight);

    double djb, djq1, djq2;

    if (DR1<0.7){
      if (geninfo.IsTopHadronicDecay()){
	is_signal = true;
	topquark = top;

	GenParticle bquark = geninfo.bTop();
	GenParticle Wdecay1 = geninfo.Wdecay1();
	GenParticle Wdecay2 = geninfo.Wdecay2();
	
	m_b_genpx = bquark.v4().px();
	m_b_genpy = bquark.v4().py();
	m_b_genpz = bquark.v4().pz();
	
	m_wq1_genpx = Wdecay1.v4().px();
	m_wq1_genpy = Wdecay1.v4().py();
	m_wq1_genpz = Wdecay1.v4().pz();
	
	m_wq2_genpx = Wdecay2.v4().px();
	m_wq2_genpy = Wdecay2.v4().py();
	m_wq2_genpz = Wdecay2.v4().pz();

	// calculate largest value of DeltaR between decay products and top jet
	djb = CalcDR(bquark, topquark);
	djq1 = CalcDR(Wdecay1, topquark);
	djq2 = CalcDR(Wdecay2, topquark);
	LorentzVector v = bquark.v4() + Wdecay1.v4() + Wdecay2.v4();
	if (v.isTimelike()){
	  Hist("mass_decayproducts")->Fill(v.mass(), weight);
	}

      }
    }
    if (DR2<0.7){
      if (geninfo.IsAntiTopHadronicDecay()){
	is_signal = true;
	topquark = atop;
	
	GenParticle bquark = geninfo.bAntitop();
	GenParticle Wdecay1 = geninfo.WMinusdecay1();
	GenParticle Wdecay2 = geninfo.WMinusdecay2();
	
	m_b_genpx = bquark.v4().px();
	m_b_genpy = bquark.v4().py();
	m_b_genpz = bquark.v4().pz();
	
	m_wq1_genpx = Wdecay1.v4().px();
	m_wq1_genpy = Wdecay1.v4().py();
	m_wq1_genpz = Wdecay1.v4().pz();
      
	m_wq2_genpx = Wdecay2.v4().px();
	m_wq2_genpy = Wdecay2.v4().py();
	m_wq2_genpz = Wdecay2.v4().pz();

	// calculate largest value of DeltaR between decay products and top jet
	djb = CalcDR(bquark, topquark);
	djq1 = CalcDR(Wdecay1, topquark);
	djq2 = CalcDR(Wdecay2, topquark);

	LorentzVector v = bquark.v4() + Wdecay1.v4() + Wdecay2.v4();
	if (v.isTimelike()){
	  Hist("mass_decayproducts")->Fill(v.mass(), weight);
	}
	
      }
    }

    if ((!backgroundMC) && (!is_signal)){
      continue;
    }

    // check if this jet fulfills the cuts
    if (tj.pt()<200) continue;
    if (fabs(tj.eta())>2.5) continue;

    double dmax1 = std::max(djb, djq1);
    double dmax = std::max(dmax1, djq2);
    
    Hist("DR_max_topjet_decayproducts")-> Fill(dmax,weight);
    
    FillTopJetProperties(tj, topquark);

    m_tree->Fill();
    
  }

}

void TMVATreeFiller::Finish()
{
  // final calculations, like division and addition of certain histograms

}

Double_t TMVATreeFiller::RecGenMatch(TopJet tj, GenParticle gen)
{
  
  // protection against non-existant gen particle
  if (gen.pt()<0.0001) return 9999.;

  double eta1 = tj.eta();
  double eta2 = gen.eta();
  double DeltaEta = eta1 - eta2;

  double phi1 = tj.phi();
  double phi2 = gen.phi();

  // fold difference in phi into [0,pi]
  static const double pi = 3.14159265358979323846;
  double DeltaPhi = phi1 - phi2;
  if (abs(DeltaPhi) > pi){
    if (DeltaPhi>0) DeltaPhi-=2*pi;
    else DeltaPhi+=2*pi;
  }
  DeltaPhi = abs(DeltaPhi); // projection into [0,pi]

  double DR = sqrt(DeltaEta*DeltaEta + DeltaPhi*DeltaPhi);

  return DR;

}

void TMVATreeFiller::ClearVariables()
{
  m_npv = 0;
  m_weight = 0;

  m_px = 0;
  m_py = 0;
  m_pz = 0;
  m_mass = 0;

  m_genpx = 0;
  m_genpy = 0;
  m_genpz = 0;

  m_b_genpx = 0;
  m_b_genpy = 0;
  m_b_genpz = 0;

  m_wq1_genpx = 0;
  m_wq1_genpy = 0;
  m_wq1_genpz = 0;

  m_wq2_genpx = 0;
  m_wq2_genpy = 0;
  m_wq2_genpz = 0;

  m_tau1 = 0;
  m_tau2 = 0;
  m_tau3 = 0;
  m_tau4 = 0;

  m_pruned_tau1 = 0;
  m_pruned_tau2 = 0;
  m_pruned_tau3 = 0;
  m_pruned_tau4 = 0;

  m_psi_02 = 0;
  m_psi_04 = 0; 
  m_psi_06 = 0;

  m_qjets = 0;
  m_qjet_mmin=0;
  m_qjet_mass=0;
  m_qjet_nsubjets=0;
  m_qjet_nsubjettiness1=0;
  m_qjet_nsubjettiness2= 0;
  m_qjet_nsubjettiness3= 0;
  //jwj

  m_jetm01=0;
  m_jetm02=0;
  m_jetm03=0;
  m_jetm04=0;

  //ecf
  m_c3=0;
  m_d3=0;
  //softdrop
  m_softdrop_mass=0;

  m_sub1_px = 0;
  m_sub1_py = 0;
  m_sub1_pz = 0;
  m_sub1_mass = 0;

  m_sub2_px = 0;
  m_sub2_py = 0;
  m_sub2_pz = 0;
  m_sub2_mass = 0;

  m_sub3_px = 0;
  m_sub3_py = 0;
  m_sub3_pz = 0;
  m_sub3_mass = 0;

  m_sub4_px = 0;
  m_sub4_py = 0;
  m_sub4_pz = 0;
  m_sub4_mass = 0;

  m_m12 = 0;	
  m_m13 = 0;	
  m_m23 = 0;	

  m_chi=0;

  m_pruned_mass = 0;
  m_pruned_m12 = 0;	
  m_pruned_m13 = 0;	
  m_pruned_m23 = 0;

  m_HEPTopTag = false;
  m_CMSTopTag = false;

  m_number_of_constituents = 0;
  m_number_of_constituents = 0;
  m_jet_charge = 0;
  m_weighted_jet_charge = 0;
  m_weighted_jet_charge_02 = 0; 
  m_weighted_jet_charge_04 = 0; 
  m_weighted_jet_charge_06 = 0; 
  m_weighted_jet_charge_08 = 0; 
  m_first_jet_moment = 0;
  m_second_jet_moment = 0;
  m_dR1=0;
  m_dR2=0;
  m_dR3=0;
  m_pt=0;
  m_HelAng12=0;
  m_HelAng13=0;
  m_HelAng23=0;
  m_subjet1pt=0;
  m_subjet2pt=0;
  m_subjet3pt=0;
}


void TMVATreeFiller::FillTopJetProperties(TopJet topjet, GenParticle topquark)
{

  EventCalc* calc = EventCalc::Instance();
  m_npv = calc->GetPrimaryVertices()->size();
  double weight = calc->GetWeight();
  
  m_px = topjet.v4().px();
  m_py = topjet.v4().py();
  m_pz = topjet.v4().pz();

  m_genpx = topquark.v4().px();
  m_genpy = topquark.v4().py();
  m_genpz = topquark.v4().pz();
  //TL
  /*
  m_dR1=distance_quark(topjet,1,0.8);
  m_dR2=distance_quark(topjet,2,0.8);
  m_dR3=distance_quark(topjet,3,0.8);
  if(m_dR1<0.8 && m_dR2<0.8 && m_dR3<0.8 && m_dR1>0 && m_dR2>0 &&m_dR3>0) m_pt_selection=topjet.pt();
  m_pt=topjet.pt();*/
  //----
  Hist("MatchedJet_pt")-> Fill(topquark.v4().pt(),weight);
  if (topquark.v4().pt()>250){
    Hist("MatchedJet_eta")-> Fill(topquark.v4().eta(),weight);
    Hist("MatchedJet_NPV")-> Fill(m_npv,weight);
  }

  m_nsubs=topjet.numberOfDaughters();

  // some jet substructure variables
  // N-subjettiness
  JetProps jp(&topjet, calc->GetPFParticles() );
  m_tau1 = jp.GetNsubjettiness(1, Njettiness::onepass_kt_axes, 1., 0.8);
  m_tau2 = jp.GetNsubjettiness(2, Njettiness::onepass_kt_axes, 1., 0.8);
  m_tau3 = jp.GetNsubjettiness(3, Njettiness::onepass_kt_axes, 1., 0.8);
  m_tau4 = jp.GetNsubjettiness(4, Njettiness::onepass_kt_axes, 1., 0.8);

  m_pruned_tau1 = jp.GetPrunedNsubjettiness(1, Njettiness::onepass_kt_axes, 1., 0.8);
  m_pruned_tau2 = jp.GetPrunedNsubjettiness(2, Njettiness::onepass_kt_axes, 1., 0.8);
  m_pruned_tau3 = jp.GetPrunedNsubjettiness(3, Njettiness::onepass_kt_axes, 1., 0.8);
  m_pruned_tau4 = jp.GetPrunedNsubjettiness(4, Njettiness::onepass_kt_axes, 1., 0.8);

  //SHOWER DECONSTRUCTION
  double Mmicrojet=0;
  int Nmicrojets=0;
  std::vector<fastjet::PseudoJet> microjets;
  //double chi=0;
  double microconesize=0.3;
  if(topjet.pt()>500) microconesize=0.2;
  if(topjet.pt()>700) microconesize=0.1;
  //if(Ca8jet.pt()>800) microconesize=0.05;                                                                                                                                                        
  double chi=0;  
   if(topjet.pt()>350) chi = Showerdeconstruction_tagger->ChiMicro(topjet,Nmicrojets,Mmicrojet,microconesize,microjets);
  if(chi>-1) m_chi=chi;


  /*  std::vector<PFParticle> jetconst =  calc->GetJetPFParticles(&topjet);
  sort(jetconst.begin(),jetconst.end(),HigherPt());
  for(int i=0; i<jetconst.size();i++){
    if(i<100) m_pf_pt[i]=jetconst[i].pt();
    if(i<100) m_pf_phi[i]=jetconst[i].phi();
     if(i<100) m_pf_eta[i]=jetconst[i].eta();
      if(i<100) m_pf_energy[i]=jetconst[i].energy();
       if(i<100) m_pf_charge[i]=jetconst[i].charge();
       }*/


 // Q-jets
  m_qjets = topjet.qjets_volatility(); //jp.GetQjetVolatility(calc->GetEventNum(), 0.8);
  m_qjet_mmin=jp.GetQjetVolatility_mmin(calc->GetEventNum(),0.8);
  m_qjet_mass=jp.GetQjetVolatility(calc->GetEventNum(),0.8);
  m_qjet_nsubjets=jp.GetQjetVolatility_nsubjets(calc->GetEventNum(),0.8);
  m_qjet_nsubjettiness1= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 1, Njettiness::onepass_kt_axes , 1.);
  m_qjet_nsubjettiness2= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 2, Njettiness::onepass_kt_axes , 1.);
  m_qjet_nsubjettiness3= jp.GetQjetVolatility_Nsubjettiness(calc->GetEventNum(), 0.8, 3, Njettiness::onepass_kt_axes , 1.);
  //jwj

  m_jetm01=jwj->SubjetMultiplicity(topjet, calc->GetPFParticles(),0.05,0.1);
  m_jetm02=jwj->SubjetMultiplicity(topjet, calc->GetPFParticles(),0.05,0.2);
  m_jetm03=jwj->SubjetMultiplicity(topjet, calc->GetPFParticles(),0.05,0.3);
  m_jetm04=jwj->SubjetMultiplicity(topjet, calc->GetPFParticles(),0.05,0.4);


  //ecf

  m_c3=ecf->Get_C(topjet,calc->GetPFParticles(), 3, 1.0);
  m_d3=ecf->Get_D3(topjet,calc->GetPFParticles(),2.,0.8,0.6);

  //soft drop
  fastjet::PseudoJet groomed_jet;
  Softdrop->GetJet(topjet, calc->GetPFParticles(),0.1,2.0,groomed_jet);
  m_softdrop_mass=groomed_jet.m();


  // jet constituents & jet charge
  std::vector<PFParticle> jetconsts = calc->GetJetPFParticles(&topjet);
  m_number_of_constituents = jetconsts.size();
  m_number_of_charged_constituents = 0;
  m_jet_charge = calc->JetCharge(&topjet);
  for(int i=0; i< m_number_of_constituents; ++i){
    if( fabs(jetconsts[i].charge())>0.01) {
      m_number_of_charged_constituents ++;
    }
  }
  m_weighted_jet_charge = calc->EnergyWeightedJetCharge(&topjet);
  m_weighted_jet_charge_02 = calc->EnergyWeightedJetCharge(&topjet, 0.2);
  m_weighted_jet_charge_04 = calc->EnergyWeightedJetCharge(&topjet, 0.4);
  m_weighted_jet_charge_06 = calc->EnergyWeightedJetCharge(&topjet, 0.6);
  m_weighted_jet_charge_08 = calc->EnergyWeightedJetCharge(&topjet, 0.8);

  m_first_jet_moment = calc->JetMoment(&topjet,1);
  m_second_jet_moment = calc->JetMoment(&topjet,2);

  // jet shape
  m_psi_02 = calc->IntegratedJetShape( &topjet, 0.2, 0.0 , e_CA8);
  m_psi_04 = calc->IntegratedJetShape( &topjet, 0.4, 0.0 , e_CA8);
  m_psi_06 = calc->IntegratedJetShape( &topjet, 0.6, 0.0 , e_CA8);
  
  // HEP TopTag
  m_HEPTopTag = HepTopTag(topjet);

  // CMS TopTag
  double dum1, dum2;
  int idum;
  m_CMSTopTag = TopTag(topjet, dum1, idum, dum2);
  

  LorentzVector allsubjets(0,0,0,0);
  
  for(int j=0; j<topjet.numberOfDaughters(); ++j){
    allsubjets += topjet.subjets()[j].v4();
  }

  if(!allsubjets.isTimelike()){
    m_mass=0;
  } else {
    m_mass = allsubjets.M();
  }
  
  std::vector<Particle> subjets = topjet.subjets();
  sort(subjets.begin(), subjets.end(), HigherPt());

  if (m_nsubs>=1) {
    m_sub1_px = subjets[0].v4().px();
    m_sub1_py = subjets[0].v4().py();
    m_sub1_pz = subjets[0].v4().pz();
    if (subjets[0].v4().isTimelike()){
      m_sub1_mass = subjets[0].v4().mass();
    }
  }  

  if (m_nsubs>=2) {
    m_sub2_px = subjets[1].v4().px();
    m_sub2_py = subjets[1].v4().py();
    m_sub2_pz = subjets[1].v4().pz();
    if (subjets[1].v4().isTimelike()){
      m_sub2_mass = subjets[1].v4().mass();
    }
    if ( (subjets[0].v4()+subjets[1].v4()).isTimelike() ){
      m_m12=(subjets[0].v4()+subjets[1].v4()).M();
    }
  }

  if (m_nsubs>=3) {
    m_sub3_px = subjets[2].v4().px();
    m_sub3_py = subjets[2].v4().py();
    m_sub3_pz = subjets[2].v4().pz();
    if (subjets[2].v4().isTimelike()){
      m_sub3_mass = subjets[2].v4().mass();
    }
    if( (subjets[0].v4()+subjets[2].v4()).isTimelike() ){
      m_m13=(subjets[0].v4()+subjets[2].v4()).M();
    }
    
    if( (subjets[1].v4()+subjets[2].v4()).isTimelike() ){
      m_m23 = (subjets[1].v4()+subjets[2].v4()).M();   
    } 
  }

  if (m_nsubs>=4) {
    m_sub4_px = subjets[3].v4().px();
    m_sub4_py = subjets[3].v4().py();
    m_sub4_pz = subjets[3].v4().pz();
    if (subjets[3].v4().isTimelike()){
      m_sub4_mass = subjets[3].v4().mass();
    }
  }


  // calculate pruned masses
  std::vector<fastjet::PseudoJet> jets = jp.GetFastJet(2.0);   // something large to make sure jet is inside radius
  if(jets.empty()){
      m_logger << WARNING << "TMVATreeFiller::FillTopJetProperties: no jet found!" << SLogger::endmsg; 
  }
  else{
    fastjet::PseudoJet pjet = jp.GetPrunedJet(jets[0]);
    std::vector<fastjet::PseudoJet> prunedsubjets;
    if (pjet.constituents().size()>=2){
        prunedsubjets = pjet.exclusive_subjets(2);
    }
    if (pjet.constituents().size()>=3){
        prunedsubjets = pjet.exclusive_subjets(3);
    }

    unsigned int pnsubs = prunedsubjets.size();

    fastjet::PseudoJet psubjets(0,0,0,0);
    
    for(unsigned int j=0; j<pnsubs; ++j){
        psubjets += pjet.pieces()[j];
    }

    m_pruned_mass = psubjets.m();

    if (pnsubs>=2) {
        m_pruned_m12 = (prunedsubjets[0]+prunedsubjets[1]).m();
    }

    if (pnsubs>=3) {
        m_pruned_m13 = (prunedsubjets[0]+prunedsubjets[2]).m();
        m_pruned_m23 = (prunedsubjets[1]+prunedsubjets[2]).m();
    }
  }

  //helicity angle , subjet pt
 
  if(m_nsubs>0) m_subjet1pt=sqrt(pow(subjets[0].v4().Px(),2)+pow(subjets[0].v4().Py(),2));
  if(m_nsubs>1){
    TLorentzVector subjet1(subjets[0].v4().Px(),subjets[0].v4().Py(),subjets[0].v4().Pz(),subjets[0].v4().E());
    TLorentzVector subjet2(subjets[1].v4().Px(),subjets[1].v4().Py(),subjets[1].v4().Pz(),subjets[1].v4().E());
    m_subjet1pt=sqrt(pow(subjets[0].v4().Px(),2)+pow(subjets[0].v4().Py(),2));
    m_subjet2pt=sqrt(pow(subjets[1].v4().Px(),2)+pow(subjets[1].v4().Py(),2));
    m_HelAng12= HelicityAngle(subjet1,subjet2);
  }
  if(m_nsubs>2){
    TLorentzVector subjet1(subjets[0].v4().Px(),subjets[0].v4().Py(),subjets[0].v4().Pz(),subjets[0].v4().E());
    TLorentzVector subjet2(subjets[1].v4().Px(),subjets[1].v4().Py(),subjets[1].v4().Pz(),subjets[1].v4().E());
    TLorentzVector subjet3(subjets[2].v4().Px(),subjets[2].v4().Py(),subjets[2].v4().Pz(),subjets[2].v4().E());
    m_subjet1pt=sqrt(pow(subjets[0].v4().Px(),2)+pow(subjets[0].v4().Py(),2));
    m_subjet2pt=sqrt(pow(subjets[1].v4().Px(),2)+pow(subjets[1].v4().Py(),2));
    m_subjet3pt=sqrt(pow(subjets[2].v4().Px(),2)+pow(subjets[2].v4().Py(),2));
    m_HelAng12= HelicityAngle(subjet1,subjet2);
    m_HelAng13= HelicityAngle(subjet1,subjet3);
    m_HelAng23= HelicityAngle(subjet2,subjet3);
    }
 
}


Double_t TMVATreeFiller::CalcDR(GenParticle tj, GenParticle gen)
{
  
  // protection against non-existant gen particle
  if (gen.pt()<0.0001) return 9999.;

  return tj.deltaR(gen);

}
