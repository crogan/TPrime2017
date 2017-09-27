#include <TH1D.h>
#include <iostream>

#include "AnalysisBase.hh"
#include "ZeroLeptonBase.hh"
#include "ChicagoBase.hh"
#include "SunBase.hh"

using namespace std;

template <class Base>
AnalysisBase<Base>::AnalysisBase(TTree* tree)
  : Base(tree)
{
  m_CurrentFile = -1;
  m_DSID = -1;
  InitXSECmap();
}

template <class Base>
AnalysisBase<Base>::~AnalysisBase() {}

template <class Base>
Int_t AnalysisBase<Base>::GetEntry(Long64_t entry){
  if (!Base::fChain) return 0;
  Int_t ret = Base::fChain->GetEntry(entry);

  // if(Base::fChain->GetTreeNumber() != m_CurrentFile)
  //   NewFile();

  return ret;
}

template <class Base>
void AnalysisBase<Base>::NewFile(){
  // m_CurrentFile = Base::fChain->GetTreeNumber();

  // TFile* F = ((TChain*)Base::fChain)->GetFile();
  // if(!F) return;

  // char *p, *q;
  // char fname[256];
  // sprintf(fname,"%s",F->GetName());
  // p = strtok(fname, "/");

  // q = p;
  // while(p){
  //   q = p;
  //   p = strtok(NULL,"/");
  // }
  // m_DSID = atoi(strtok(q,"."));

  // TH1D* h_counter = (TH1D*) F->Get("Counter_JobBookeeping_JobBookeeping");
  // int nevt_wgt = h_counter->GetBinContent(2);
  // m_IDtoNEVT[m_DSID] = nevt_wgt;

  // cout << "Initialized file " << F->GetName() << ": ";
  // cout << "   DSID   = " << m_DSID << endl;
  // cout << "   XSEC   = " << m_IDtoXSEC[m_DSID] << endl;
  // cout << "   Nevt^W = " << m_IDtoNEVT[m_DSID] << endl;
}

template <class Base>
double AnalysisBase<Base>::DeltaPhiMin(const vector<TLorentzVector>& JETs, const TVector3& MET, int N){
  double dphimin = acos(-1);
  int Njet = JETs.size();
  for(int i = 0; i < Njet; i++){
    if(N > 0 && i >= N) break;
    if(fabs(JETs[i].Vect().DeltaPhi(MET)) < dphimin) dphimin = fabs(JETs[i].Vect().DeltaPhi(MET));
  }
  return dphimin;
}

template <class Base>
double AnalysisBase<Base>::DeltaPhiMin(const vector<pair<TLorentzVector, bool> >& JETs, const TVector3& MET, int N){
  double dphimin = acos(-1);
  int Njet = JETs.size();
  for(int i = 0; i < Njet; i++){
    if(N > 0 && i >= N) break;
    if(fabs(JETs[i].first.Vect().DeltaPhi(MET)) < dphimin) dphimin = fabs(JETs[i].first.Vect().DeltaPhi(MET));
  }
  return dphimin;
}

template <class Base>
void AnalysisBase<Base>::InitXSECmap(){
  m_IDtoXSEC[410000] = 831.760000*1.*0.543*1.; // PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad
  m_IDtoXSEC[410011] = 43.739*1.*1.*1.; // PowhegPythiaEvtGen_P2012_singletop_tchan_lept_top
  m_IDtoXSEC[410012] = 25.778*1.*1.*1.; // PowhegPythiaEvtGen_P2012_singletop_tchan_lept_antitop
  m_IDtoXSEC[410013] = 34.009*1.*1.*1.; // PowhegPythiaEvtGen_P2012_Wt_inclusive_top
  m_IDtoXSEC[410014] = 33.989*1.*1.*1.; // PowhegPythiaEvtGen_P2012_Wt_inclusive_antitop
  m_IDtoXSEC[410015] = 3.5835*1.*1.*1.; // PowhegPythiaEvtGen_P2012_Wt_dilepton_top
  m_IDtoXSEC[410016] = 3.5814*1.*1.*1.; // PowhegPythiaEvtGen_P2012_Wt_dilepton_antitop
  m_IDtoXSEC[361100] = 11306.*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Wplusenu
  m_IDtoXSEC[361101] = 11306.*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Wplusmunu
  m_IDtoXSEC[361102] = 11306.*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Wplustaunu
  m_IDtoXSEC[361103] = 8282.6*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Wminusenu
  m_IDtoXSEC[361104] = 8282.6*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Wminusmunu
  m_IDtoXSEC[361105] = 8282.6*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Wminustaunu
  m_IDtoXSEC[361106] = 1901.2*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zee
  m_IDtoXSEC[361107] = 1901.2*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zmumu
  m_IDtoXSEC[361108] = 1901.2*1.*1.*1.; // PowhegPythia8EvtGen_AZNLOCTEQ6L1_Ztautau
  m_IDtoXSEC[361300] = 21283.*1.*0.890724*1.; // Sherpa_CT10_Wenu_Pt0_70_CVetoBVeto
  m_IDtoXSEC[361301] = 21379.*1.*0.049290*1.; // Sherpa_CT10_Wenu_Pt0_70_CFilterBVeto
  m_IDtoXSEC[361302] = 21392.*1.*0.059830*1.; // Sherpa_CT10_Wenu_Pt0_70_BFilter
  m_IDtoXSEC[361303] = 632.99*1.*0.728585*1.; // Sherpa_CT10_Wenu_Pt70_140_CVetoBVeto
  m_IDtoXSEC[361304] = 632.58*1.*0.176811*1.; // Sherpa_CT10_Wenu_Pt70_140_CFilterBVeto
  m_IDtoXSEC[361305] = 632.58*1.*0.097010*1.; // Sherpa_CT10_Wenu_Pt70_140_BFilter
  m_IDtoXSEC[361306] = 90.146*1.*0.681478*1.; // Sherpa_CT10_Wenu_Pt140_280_CVetoBVeto
  m_IDtoXSEC[361307] = 89.969*1.*0.205407*1.; // Sherpa_CT10_Wenu_Pt140_280_CFilterBVeto
  m_IDtoXSEC[361308] = 90.026*1.*0.111830*1.; // Sherpa_CT10_Wenu_Pt140_280_BFilter
  m_IDtoXSEC[361309] = 6.5305*1.*0.648400*1.; // Sherpa_CT10_Wenu_Pt280_500_CVetoBVeto
  m_IDtoXSEC[361310] = 6.6273*1.*0.223748*1.; // Sherpa_CT10_Wenu_Pt280_500_CFilterBVeto
  m_IDtoXSEC[361311] = 6.5447*1.*0.131507*1.; // Sherpa_CT10_Wenu_Pt280_500_BFilter
  m_IDtoXSEC[361312] = 0.41892*1.*0.623437*1.; // Sherpa_CT10_Wenu_Pt500_700_CVetoBVeto
  m_IDtoXSEC[361313] = 0.39861*1.*0.241068*1.; // Sherpa_CT10_Wenu_Pt500_700_CFilterBVeto
  m_IDtoXSEC[361314] = 0.39684*1.*0.162678*1.; // Sherpa_CT10_Wenu_Pt500_700_BFilter
  m_IDtoXSEC[361315] = 0.072864*1.*0.614236*1.; // Sherpa_CT10_Wenu_Pt700_1000_CVetoBVeto
  m_IDtoXSEC[361316] = 0.10164*1.*0.190750*1.; // Sherpa_CT10_Wenu_Pt700_1000_CFilterBVeto
  m_IDtoXSEC[361317] = 0.077232*1.*0.171531*1.; // Sherpa_CT10_Wenu_Pt700_1000_BFilter
  m_IDtoXSEC[361318] = 0.011665*1.*0.629245*1.; // Sherpa_CT10_Wenu_Pt1000_2000_CVetoBVeto
  m_IDtoXSEC[361319] = 0.010676*1.*0.235081*1.; // Sherpa_CT10_Wenu_Pt1000_2000_CFilterBVeto
  m_IDtoXSEC[361320] = 0.0093154*1.*0.190540*1.; // Sherpa_CT10_Wenu_Pt1000_2000_BFilter
  m_IDtoXSEC[361321] = 0.000034013*1.*0.638441*1.; // Sherpa_CT10_Wenu_Pt2000_E_CMS_CVetoBVeto
  m_IDtoXSEC[361322] = 0.00004555*1.*0.292825*1.; // Sherpa_CT10_Wenu_Pt2000_E_CMS_CFilterBVeto
  m_IDtoXSEC[361323] = 0.000052489*1.*0.168873*1.; // Sherpa_CT10_Wenu_Pt2000_E_CMS_BFilter
  m_IDtoXSEC[361324] = 21392.*1.*0.892516*1.; // Sherpa_CT10_Wmunu_Pt0_70_CVetoBVeto
  m_IDtoXSEC[361325] = 21376.*1.*0.047383*1.; // Sherpa_CT10_Wmunu_Pt0_70_CFilterBVeto
  m_IDtoXSEC[361326] = 21363.*1.*0.059698*1.; // Sherpa_CT10_Wmunu_Pt0_70_BFilter
  m_IDtoXSEC[361327] = 635.05*1.*0.728702*1.; // Sherpa_CT10_Wmunu_Pt70_140_CVetoBVeto
  m_IDtoXSEC[361328] = 632.11*1.*0.175784*1.; // Sherpa_CT10_Wmunu_Pt70_140_CFilterBVeto
  m_IDtoXSEC[361329] = 632.03*1.*0.097010*1.; // Sherpa_CT10_Wmunu_Pt70_140_BFilter
  m_IDtoXSEC[361330] = 90.022*1.*0.684293*1.; // Sherpa_CT10_Wmunu_Pt140_280_CVetoBVeto
  m_IDtoXSEC[361331] = 90.165*1.*0.203371*1.; // Sherpa_CT10_Wmunu_Pt140_280_CFilterBVeto
  m_IDtoXSEC[361332] = 90.301*1.*0.112122*1.; // Sherpa_CT10_Wmunu_Pt140_280_BFilter
  m_IDtoXSEC[361333] = 6.5108*1.*0.654506*1.; // Sherpa_CT10_Wmunu_Pt280_500_CVetoBVeto
  m_IDtoXSEC[361334] = 6.4747*1.*0.220116*1.; // Sherpa_CT10_Wmunu_Pt280_500_CFilterBVeto
  m_IDtoXSEC[361335] = 6.5897*1.*0.131153*1.; // Sherpa_CT10_Wmunu_Pt280_500_BFilter
  m_IDtoXSEC[361336] = 0.41351*1.*0.636388*1.; // Sherpa_CT10_Wmunu_Pt500_700_CVetoBVeto
  m_IDtoXSEC[361337] = 0.41386*1.*0.244595*1.; // Sherpa_CT10_Wmunu_Pt500_700_CFilterBVeto
  m_IDtoXSEC[361338] = 0.40969*1.*0.154635*1.; // Sherpa_CT10_Wmunu_Pt500_700_BFilter
  m_IDtoXSEC[361339] = 0.076726*1.*0.628224*1.; // Sherpa_CT10_Wmunu_Pt700_1000_CVetoBVeto
  m_IDtoXSEC[361340] = 0.0744*1.*0.228692*1.; // Sherpa_CT10_Wmunu_Pt700_1000_CFilterBVeto
  m_IDtoXSEC[361341] = 0.084611*1.*0.148041*1.; // Sherpa_CT10_Wmunu_Pt700_1000_BFilter
  m_IDtoXSEC[361342] = 0.010678*1.*0.603131*1.; // Sherpa_CT10_Wmunu_Pt1000_2000_CVetoBVeto
  m_IDtoXSEC[361343] = 0.0096763*1.*0.232036*1.; // Sherpa_CT10_Wmunu_Pt1000_2000_CFilterBVeto
  m_IDtoXSEC[361344] = 0.01146*1.*0.159623*1.; // Sherpa_CT10_Wmunu_Pt1000_2000_BFilter
  m_IDtoXSEC[361345] = 0.000044057*1.*0.617928*1.; // Sherpa_CT10_Wmunu_Pt2000_E_CMS_CVetoBVeto
  m_IDtoXSEC[361346] = 0.000058221*1.*0.305024*1.; // Sherpa_CT10_Wmunu_Pt2000_E_CMS_CFilterBVeto
  m_IDtoXSEC[361347] = 0.000035509*1.*0.194184*1.; // Sherpa_CT10_Wmunu_Pt2000_E_CMS_BFilter
  m_IDtoXSEC[361348] = 21386.*1.*0.891392*1.; // Sherpa_CT10_Wtaunu_Pt0_70_CVetoBVeto
  m_IDtoXSEC[361349] = 21378.*1.*0.048788*1.; // Sherpa_CT10_Wtaunu_Pt0_70_CFilterBVeto
  m_IDtoXSEC[361350] = 21389.*1.*0.059664*1.; // Sherpa_CT10_Wtaunu_Pt0_70_BFilter
  m_IDtoXSEC[361351] = 630.1*1.*0.725196*1.; // Sherpa_CT10_Wtaunu_Pt70_140_CVetoBVeto
  m_IDtoXSEC[361352] = 635.4*1.*0.176489*1.; // Sherpa_CT10_Wtaunu_Pt70_140_CFilterBVeto
  m_IDtoXSEC[361353] = 631.35*1.*0.095779*1.; // Sherpa_CT10_Wtaunu_Pt70_140_BFilter
  m_IDtoXSEC[361354] = 90.212*1.*0.683560*1.; // Sherpa_CT10_Wtaunu_Pt140_280_CVetoBVeto
  m_IDtoXSEC[361355] = 89.89*1.*0.205200*1.; // Sherpa_CT10_Wtaunu_Pt140_280_CFilterBVeto
  m_IDtoXSEC[361356] = 90.006*1.*0.112197*1.; // Sherpa_CT10_Wtaunu_Pt140_280_BFilter
  m_IDtoXSEC[361357] = 6.3912*1.*0.647441*1.; // Sherpa_CT10_Wtaunu_Pt280_500_CVetoBVeto
  m_IDtoXSEC[361358] = 6.7398*1.*0.218875*1.; // Sherpa_CT10_Wtaunu_Pt280_500_CFilterBVeto
  m_IDtoXSEC[361359] = 6.4933*1.*0.128123*1.; // Sherpa_CT10_Wtaunu_Pt280_500_BFilter
  m_IDtoXSEC[361360] = 0.41469*1.*0.628862*1.; // Sherpa_CT10_Wtaunu_Pt500_700_CVetoBVeto
  m_IDtoXSEC[361361] = 0.41459*1.*0.225923*1.; // Sherpa_CT10_Wtaunu_Pt500_700_CFilterBVeto
  m_IDtoXSEC[361362] = 0.41365*1.*0.156143*1.; // Sherpa_CT10_Wtaunu_Pt500_700_BFilter
  m_IDtoXSEC[361363] = 0.07929*1.*0.628224*1.; // Sherpa_CT10_Wtaunu_Pt700_1000_CVetoBVeto
  m_IDtoXSEC[361364] = 0.07821*1.*0.228692*1.; // Sherpa_CT10_Wtaunu_Pt700_1000_CFilterBVeto
  m_IDtoXSEC[361365] = 0.080632*1.*0.148041*1.; // Sherpa_CT10_Wtaunu_Pt700_1000_BFilter
  m_IDtoXSEC[361366] = 0.010612*1.*0.619569*1.; // Sherpa_CT10_Wtaunu_Pt1000_2000_CVetoBVeto
  m_IDtoXSEC[361367] = 0.010158*1.*0.233251*1.; // Sherpa_CT10_Wtaunu_Pt1000_2000_CFilterBVeto
  m_IDtoXSEC[361368] = 0.011285*1.*0.179060*1.; // Sherpa_CT10_Wtaunu_Pt1000_2000_BFilter
  m_IDtoXSEC[361369] = 0.000048638*1.*0.559602*1.; // Sherpa_CT10_Wtaunu_Pt2000_E_CMS_CVetoBVeto
  m_IDtoXSEC[361370] = 0.00005607*1.*0.234368*1.; // Sherpa_CT10_Wtaunu_Pt2000_E_CMS_CFilterBVeto
  m_IDtoXSEC[361371] = 0.000043334*1.*0.183287*1.; // Sherpa_CT10_Wtaunu_Pt2000_E_CMS_BFilter
  m_IDtoXSEC[361372] = 2206.7*1.*0.779029*1.; // Sherpa_CT10_Zee_Pt0_70_CVetoBVeto
  m_IDtoXSEC[361373] = 2206.5*1.*0.142377*1.; // Sherpa_CT10_Zee_Pt0_70_CFilterBVeto
  m_IDtoXSEC[361374] = 2203.*1.*0.079669*1.; // Sherpa_CT10_Zee_Pt0_70_BFilter
  m_IDtoXSEC[361375] = 75.523*1.*0.646123*1.; // Sherpa_CT10_Zee_Pt70_140_CVetoBVeto
  m_IDtoXSEC[361376] = 75.621*1.*0.218077*1.; // Sherpa_CT10_Zee_Pt70_140_CFilterBVeto
  m_IDtoXSEC[361377] = 76.658*1.*0.131190*1.; // Sherpa_CT10_Zee_Pt70_140_BFilter
  m_IDtoXSEC[361378] = 11.785*1.*0.617229*1.; // Sherpa_CT10_Zee_Pt140_280_CVetoBVeto
  m_IDtoXSEC[361379] = 11.49*1.*0.244908*1.; // Sherpa_CT10_Zee_Pt140_280_CFilterBVeto
  m_IDtoXSEC[361380] = 11.552*1.*0.151850*1.; // Sherpa_CT10_Zee_Pt140_280_BFilter
  m_IDtoXSEC[361381] = 0.84832*1.*0.587810*1.; // Sherpa_CT10_Zee_Pt280_500_CVetoBVeto
  m_IDtoXSEC[361382] = 0.84494*1.*0.260547*1.; // Sherpa_CT10_Zee_Pt280_500_CFilterBVeto
  m_IDtoXSEC[361383] = 0.85285*1.*0.153097*1.; // Sherpa_CT10_Zee_Pt280_500_BFilter
  m_IDtoXSEC[361384] = 0.053805*1.*0.577255*1.; // Sherpa_CT10_Zee_Pt500_700_CVetoBVeto
  m_IDtoXSEC[361385] = 0.054017*1.*0.273030*1.; // Sherpa_CT10_Zee_Pt500_700_CFilterBVeto
  m_IDtoXSEC[361386] = 0.056207*1.*0.158207*1.; // Sherpa_CT10_Zee_Pt500_700_BFilter
  m_IDtoXSEC[361387] = 0.010097*1.*0.574199*1.; // Sherpa_CT10_Zee_Pt700_1000_CVetoBVeto
  m_IDtoXSEC[361388] = 0.0097667*1.*0.304483*1.; // Sherpa_CT10_Zee_Pt700_1000_CFilterBVeto
  m_IDtoXSEC[361389] = 0.010265*1.*0.180582*1.; // Sherpa_CT10_Zee_Pt700_1000_BFilter
  m_IDtoXSEC[361390] = 0.001263*1.*0.516916*1.; // Sherpa_CT10_Zee_Pt1000_2000_CVetoBVeto
  m_IDtoXSEC[361391] = 0.0014567*1.*0.167678*1.; // Sherpa_CT10_Zee_Pt1000_2000_CFilterBVeto
  m_IDtoXSEC[361392] = 0.0012455*1.*0.197768*1.; // Sherpa_CT10_Zee_Pt1000_2000_BFilter
  m_IDtoXSEC[361393] = 0.0000057359*1.*0.535920*1.; // Sherpa_CT10_Zee_Pt2000_E_CMS_CVetoBVeto
  m_IDtoXSEC[361394] = 0.0000092786*1.*0.376833*1.; // Sherpa_CT10_Zee_Pt2000_E_CMS_CFilterBVeto
  m_IDtoXSEC[361395] = 0.000013172*1.*0.206350*1.; // Sherpa_CT10_Zee_Pt2000_E_CMS_BFilter
  m_IDtoXSEC[361396] = 2205.8*1.*0.778381*1.; // Sherpa_CT10_Zmumu_Pt0_70_CVetoBVeto
  m_IDtoXSEC[361397] = 2205.7*1.*0.141881*1.; // Sherpa_CT10_Zmumu_Pt0_70_CFilterBVeto
  m_IDtoXSEC[361398] = 2203.4*1.*0.079624*1.; // Sherpa_CT10_Zmumu_Pt0_70_BFilter
  m_IDtoXSEC[361399] = 75.822*1.*0.648837*1.; // Sherpa_CT10_Zmumu_Pt70_140_CVetoBVeto
  m_IDtoXSEC[361400] = 75.936*1.*0.216111*1.; // Sherpa_CT10_Zmumu_Pt70_140_CFilterBVeto
  m_IDtoXSEC[361401] = 75.977*1.*0.130293*1.; // Sherpa_CT10_Zmumu_Pt70_140_BFilter
  m_IDtoXSEC[361402] = 11.599*1.*0.617229*1.; // Sherpa_CT10_Zmumu_Pt140_280_CVetoBVeto
  m_IDtoXSEC[361403] = 11.599*1.*0.241249*1.; // Sherpa_CT10_Zmumu_Pt140_280_CFilterBVeto
  m_IDtoXSEC[361404] = 11.705*1.*0.148024*1.; // Sherpa_CT10_Zmumu_Pt140_280_BFilter
  m_IDtoXSEC[361405] = 0.869*1.*0.578196*1.; // Sherpa_CT10_Zmumu_Pt280_500_CVetoBVeto
  m_IDtoXSEC[361406] = 0.87544*1.*0.280660*1.; // Sherpa_CT10_Zmumu_Pt280_500_CFilterBVeto
  m_IDtoXSEC[361407] = 0.86458*1.*0.158625*1.; // Sherpa_CT10_Zmumu_Pt280_500_BFilter
  m_IDtoXSEC[361408] = 0.05564*1.*0.566372*1.; // Sherpa_CT10_Zmumu_Pt500_700_CVetoBVeto
  m_IDtoXSEC[361409] = 0.056776*1.*0.265874*1.; // Sherpa_CT10_Zmumu_Pt500_700_CFilterBVeto
  m_IDtoXSEC[361410] = 0.056196*1.*0.178239*1.; // Sherpa_CT10_Zmumu_Pt500_700_BFilter
  m_IDtoXSEC[361411] = 0.010459*1.*0.557185*1.; // Sherpa_CT10_Zmumu_Pt700_1000_CVetoBVeto
  m_IDtoXSEC[361412] = 0.0095255*1.*0.270653*1.; // Sherpa_CT10_Zmumu_Pt700_1000_CFilterBVeto
  m_IDtoXSEC[361413] = 0.0093901*1.*0.181793*1.; // Sherpa_CT10_Zmumu_Pt700_1000_BFilter
  m_IDtoXSEC[361414] = 0.0013495*1.*0.513214*1.; // Sherpa_CT10_Zmumu_Pt1000_2000_CVetoBVeto
  m_IDtoXSEC[361415] = 0.0015595*1.*0.353934*1.; // Sherpa_CT10_Zmumu_Pt1000_2000_CFilterBVeto
  m_IDtoXSEC[361416] = 0.0014846*1.*0.238860*1.; // Sherpa_CT10_Zmumu_Pt1000_2000_BFilter
  m_IDtoXSEC[361417] = 0.0000073382*1.*0.564858*1.; // Sherpa_CT10_Zmumu_Pt2000_E_CMS_CVetoBVeto
  m_IDtoXSEC[361418] = 0.0000064214*1.*0.384832*1.; // Sherpa_CT10_Zmumu_Pt2000_E_CMS_CFilterBVeto
  m_IDtoXSEC[361419] = 0.000011932*1.*0.281000*1.; // Sherpa_CT10_Zmumu_Pt2000_E_CMS_BFilter
  m_IDtoXSEC[361420] = 2196.4*1.*0.778140*1.; // Sherpa_CT10_Ztautau_Pt0_70_CVetoBVeto
  m_IDtoXSEC[361421] = 2204.*1.*0.142335*1.; // Sherpa_CT10_Ztautau_Pt0_70_CFilterBVeto
  m_IDtoXSEC[361422] = 2207.8*1.*0.078985*1.; // Sherpa_CT10_Ztautau_Pt0_70_BFilter
  m_IDtoXSEC[361423] = 76.229*1.*0.647945*1.; // Sherpa_CT10_Ztautau_Pt70_140_CVetoBVeto
  m_IDtoXSEC[361424] = 76.079*1.*0.222003*1.; // Sherpa_CT10_Ztautau_Pt70_140_CFilterBVeto
  m_IDtoXSEC[361425] = 76.318*1.*0.131159*1.; // Sherpa_CT10_Ztautau_Pt70_140_BFilter
  m_IDtoXSEC[361426] = 11.468*1.*0.614503*1.; // Sherpa_CT10_Ztautau_Pt140_280_CVetoBVeto
  m_IDtoXSEC[361427] = 11.624*1.*0.243135*1.; // Sherpa_CT10_Ztautau_Pt140_280_CFilterBVeto
  m_IDtoXSEC[361428] = 11.645*1.*0.140394*1.; // Sherpa_CT10_Ztautau_Pt140_280_BFilter
  m_IDtoXSEC[361429] = 0.85864*1.*0.573220*1.; // Sherpa_CT10_Ztautau_Pt280_500_CVetoBVeto
  m_IDtoXSEC[361430] = 0.86366*1.*0.253738*1.; // Sherpa_CT10_Ztautau_Pt280_500_CFilterBVeto
  m_IDtoXSEC[361431] = 0.90216*1.*0.159587*1.; // Sherpa_CT10_Ztautau_Pt280_500_BFilter
  m_IDtoXSEC[361432] = 0.054666*1.*0.563903*1.; // Sherpa_CT10_Ztautau_Pt500_700_CVetoBVeto
  m_IDtoXSEC[361433] = 0.055443*1.*0.266807*1.; // Sherpa_CT10_Ztautau_Pt500_700_CFilterBVeto
  m_IDtoXSEC[361434] = 0.055614*1.*0.167875*1.; // Sherpa_CT10_Ztautau_Pt500_700_BFilter
  m_IDtoXSEC[361435] = 0.008835*1.*0.565657*1.; // Sherpa_CT10_Ztautau_Pt700_1000_CVetoBVeto
  m_IDtoXSEC[361436] = 0.0098863*1.*0.346807*1.; // Sherpa_CT10_Ztautau_Pt700_1000_CFilterBVeto
  m_IDtoXSEC[361437] = 0.011322*1.*0.161007*1.; // Sherpa_CT10_Ztautau_Pt700_1000_BFilter
  m_IDtoXSEC[361438] = 0.0011582*1.*0.542538*1.; // Sherpa_CT10_Ztautau_Pt1000_2000_CVetoBVeto
  m_IDtoXSEC[361439] = 0.0012131*1.*0.419766*1.; // Sherpa_CT10_Ztautau_Pt1000_2000_CFilterBVeto
  m_IDtoXSEC[361440] = 0.0015868*1.*0.142217*1.; // Sherpa_CT10_Ztautau_Pt1000_2000_BFilter
  m_IDtoXSEC[361441] = 0.0000050133*1.*0.595406*1.; // Sherpa_CT10_Ztautau_Pt2000_E_CMS_CVetoBVeto
  m_IDtoXSEC[361442] = 0.0000056335*1.*0.359953*1.; // Sherpa_CT10_Ztautau_Pt2000_E_CMS_CFilterBVeto
  m_IDtoXSEC[361443] = 0.0000076959*1.*0.250389*1.; // Sherpa_CT10_Ztautau_Pt2000_E_CMS_BFilter
  m_IDtoXSEC[361444] = 11937.*1.*0.778461*1.; // Sherpa_CT10_Znunu_Pt0_70_CVetoBVeto
  m_IDtoXSEC[361445] = 11933.*1.*0.140128*1.; // Sherpa_CT10_Znunu_Pt0_70_CFilterBVeto
  m_IDtoXSEC[361446] = 11949.*1.*0.080034*1.; // Sherpa_CT10_Znunu_Pt0_70_BFilter
  m_IDtoXSEC[361447] = 428.25*1.*0.649778*1.; // Sherpa_CT10_Znunu_Pt70_140_CVetoBVeto
  m_IDtoXSEC[361448] = 427.67*1.*0.218630*1.; // Sherpa_CT10_Znunu_Pt70_140_CFilterBVeto
  m_IDtoXSEC[361449] = 428.59*1.*0.132849*1.; // Sherpa_CT10_Znunu_Pt70_140_BFilter
  m_IDtoXSEC[361450] = 65.902*1.*0.613840*1.; // Sherpa_CT10_Znunu_Pt140_280_CVetoBVeto
  m_IDtoXSEC[361451] = 65.796*1.*0.237656*1.; // Sherpa_CT10_Znunu_Pt140_280_CFilterBVeto
  m_IDtoXSEC[361452] = 66.149*1.*0.147665*1.; // Sherpa_CT10_Znunu_Pt140_280_BFilter
  m_IDtoXSEC[361453] = 4.8378*1.*0.581904*1.; // Sherpa_CT10_Znunu_Pt280_500_CVetoBVeto
  m_IDtoXSEC[361454] = 4.8408*1.*0.259102*1.; // Sherpa_CT10_Znunu_Pt280_500_CFilterBVeto
  m_IDtoXSEC[361455] = 4.8839*1.*0.162609*1.; // Sherpa_CT10_Znunu_Pt280_500_BFilter
  m_IDtoXSEC[361456] = 0.29329*1.*0.555049*1.; // Sherpa_CT10_Znunu_Pt500_700_CVetoBVeto
  m_IDtoXSEC[361457] = 0.30096*1.*0.266115*1.; // Sherpa_CT10_Znunu_Pt500_700_CFilterBVeto
  m_IDtoXSEC[361458] = 0.30345*1.*0.162536*1.; // Sherpa_CT10_Znunu_Pt500_700_BFilter
  m_IDtoXSEC[361459] = 0.053341*1.*0.578720*1.; // Sherpa_CT10_Znunu_Pt700_1000_CVetoBVeto
  m_IDtoXSEC[361460] = 0.054118*1.*0.303868*1.; // Sherpa_CT10_Znunu_Pt700_1000_CFilterBVeto
  m_IDtoXSEC[361461] = 0.056399*1.*0.195638*1.; // Sherpa_CT10_Znunu_Pt700_1000_BFilter
  m_IDtoXSEC[361462] = 0.0076507*1.*0.534707*1.; // Sherpa_CT10_Znunu_Pt1000_2000_CVetoBVeto
  m_IDtoXSEC[361463] = 0.0084891*1.*0.293818*1.; // Sherpa_CT10_Znunu_Pt1000_2000_CFilterBVeto
  m_IDtoXSEC[361464] = 0.0078858*1.*0.236149*1.; // Sherpa_CT10_Znunu_Pt1000_2000_BFilter
  m_IDtoXSEC[361465] = 0.000034976*1.*0.471457*1.; // Sherpa_CT10_Znunu_Pt2000_E_CMS_CVetoBVeto
  m_IDtoXSEC[361466] = 0.000021126*1.*0.254913*1.; // Sherpa_CT10_Znunu_Pt2000_E_CMS_CFilterBVeto
  m_IDtoXSEC[361467] = 0.000032459*1.*0.196395*1.; // Sherpa_CT10_Znunu_Pt2000_E_CMS_BFilter
  m_IDtoXSEC[361064] = 1.8446*1.*1.*1.; // Sherpa_CT10_lllvSFMinus
  m_IDtoXSEC[361065] = 3.6235*1.*1.*1.; // Sherpa_CT10_lllvOFMinus
  m_IDtoXSEC[361066] = 2.5656*1.*1.*1.; // Sherpa_CT10_lllvSFPlus
  m_IDtoXSEC[361067] = 5.0169*1.*1.*1.; // Sherpa_CT10_lllvOFPlus
  m_IDtoXSEC[361068] = 14.022*1.*1.*1.; // Sherpa_CT10_llvv
  m_IDtoXSEC[361069] = 0.025765*1.*1.*1.; // Sherpa_CT10_llvvjj_ss_EW4
  m_IDtoXSEC[361070] = 0.043375*1.*1.*1.; // Sherpa_CT10_llvvjj_ss_EW6
  m_IDtoXSEC[361071] = 0.042017*1.*1.*1.; // Sherpa_CT10_lllvjj_EW6
  m_IDtoXSEC[361072] = 0.1279*1.*1.*1.; // Sherpa_CT10_lllljj_EW6
  m_IDtoXSEC[361073] = 0.02095*1.*1.*1.; // Sherpa_CT10_ggllll
  m_IDtoXSEC[361077] = 0.85492*1.*1.*1.; // Sherpa_CT10_ggllvv
  m_IDtoXSEC[361081] = 25.995*1.*1.*1.; // Sherpa_CT10_WplvWmqq
  m_IDtoXSEC[361082] = 25.974*1.*1.*1.; // Sherpa_CT10_WpqqWmlv
  m_IDtoXSEC[361083] = 12.543*1.*1.*1.; // Sherpa_CT10_WlvZqq
  m_IDtoXSEC[361084] = 3.7583*1.*1.*1.; // Sherpa_CT10_WqqZll
  m_IDtoXSEC[361085] = 7.4151*1.*1.*1.; // Sherpa_CT10_WqqZvv
  m_IDtoXSEC[361039] = 34988.*1.*0.41028*1.; // Sherpa_CT10_SinglePhotonPt35_70_CVetoBVeto
  m_IDtoXSEC[361040] = 34986.*1.*0.48610*1.; // Sherpa_CT10_SinglePhotonPt35_70_CFilterBVeto
  m_IDtoXSEC[361041] = 35002.*1.*0.10372*1.; // Sherpa_CT10_SinglePhotonPt35_70_BFilter
  m_IDtoXSEC[361042] = 3129.*1.*0.39960*1.; // Sherpa_CT10_SinglePhotonPt70_140_CVetoBVeto
  m_IDtoXSEC[361043] = 3132.9*1.*0.48201*1.; // Sherpa_CT10_SinglePhotonPt70_140_CFilterBVeto
  m_IDtoXSEC[361044] = 3135.2*1.*0.11728*1.; // Sherpa_CT10_SinglePhotonPt70_140_BFilter
  m_IDtoXSEC[361045] = 247.41*1.*0.39265*1.; // Sherpa_CT10_SinglePhotonPt140_280_CVetoBVeto
  m_IDtoXSEC[361046] = 247.39*1.*0.47826*1.; // Sherpa_CT10_SinglePhotonPt140_280_CFilterBVeto
  m_IDtoXSEC[361047] = 249.37*1.*0.12874*1.; // Sherpa_CT10_SinglePhotonPt140_280_BFilter
  m_IDtoXSEC[361048] = 13.648*1.*0.38607*1.; // Sherpa_CT10_SinglePhotonPt280_500_CVetoBVeto
  m_IDtoXSEC[361049] = 13.617*1.*0.47349*1.; // Sherpa_CT10_SinglePhotonPt280_500_CFilterBVeto
  m_IDtoXSEC[361050] = 13.874*1.*0.14065*1.; // Sherpa_CT10_SinglePhotonPt280_500_BFilter
  m_IDtoXSEC[361051] = 0.92334*1.*0.37922*1.; // Sherpa_CT10_SinglePhotonPt500_1000_CVetoBVeto
  m_IDtoXSEC[361052] = 0.92185*1.*0.47149*1.; // Sherpa_CT10_SinglePhotonPt500_1000_CFilterBVeto
  m_IDtoXSEC[361053] = 0.93819*1.*0.14811*1.; // Sherpa_CT10_SinglePhotonPt500_1000_BFilter
  m_IDtoXSEC[361054] = 0.018432*1.*0.37058*1.; // Sherpa_CT10_SinglePhotonPt1000_2000_CVetoBVeto
  m_IDtoXSEC[361055] = 0.018388*1.*0.46648*1.; // Sherpa_CT10_SinglePhotonPt1000_2000_CFilterBVeto
  m_IDtoXSEC[361056] = 0.019046*1.*0.15750*1.; // Sherpa_CT10_SinglePhotonPt1000_2000_BFilter
  m_IDtoXSEC[361057] = 0.000079163*1.*0.38039*1.; // Sherpa_CT10_SinglePhotonPt2000_4000_CVetoBVeto
  m_IDtoXSEC[361058] = 0.000080515*1.*0.45148*1.; // Sherpa_CT10_SinglePhotonPt2000_4000_CFilterBVeto
  m_IDtoXSEC[361059] = 0.000082153*1.*0.16548*1.; // Sherpa_CT10_SinglePhotonPt2000_4000_BFilter
  m_IDtoXSEC[361060] = 0.0000000024843*1.*0.40351*1.; // Sherpa_CT10_SinglePhotonPt4000_CVetoBVeto
  m_IDtoXSEC[361061] = 0.0000000025134*1.*0.41612*1.; // Sherpa_CT10_SinglePhotonPt4000_CFilterBVeto
  m_IDtoXSEC[361062] = 0.0000000025431*1.*0.14831*1.; // Sherpa_CT10_SinglePhotonPt4000_BFilter
  m_IDtoXSEC[361000] = 78420000000*1.*0.97563*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ0
  m_IDtoXSEC[361001] = 78420000000*1.*0.024819*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ1
  m_IDtoXSEC[361002] = 2433400000*1.*0.010040*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ2
  m_IDtoXSEC[361003] = 26454000*1.*0.011798*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ3
  m_IDtoXSEC[361004] = 254640*1.*0.013440*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ4
  m_IDtoXSEC[361005] = 4553.6*1.*0.014577*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ5
  m_IDtoXSEC[361006] = 257.52*1.*0.010018*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ6
  m_IDtoXSEC[361007] = 016.214*1.*0.011120*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ7
  m_IDtoXSEC[361008] = 0.62505*1.*0.010331*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ8
  m_IDtoXSEC[361009] = 0.01964*1.*0.012110*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ9
  m_IDtoXSEC[361010] = 0.0011961*1.*0.0058921*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ10
  m_IDtoXSEC[361011] = 0.00004226*1.*0.0026753*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ11
  m_IDtoXSEC[361012] = 0.0000010367*1.*0.00042502*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ12
  m_IDtoXSEC[361020] = 78420000000*1.*1.024000*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ0W
  m_IDtoXSEC[361021] = 78420000000*1.*0.00067198*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ1W
  m_IDtoXSEC[361022] = 2433200000*1.*0.00033264*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ2W
  m_IDtoXSEC[361023] = 26454000*1.*0.00031953*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ3W
  m_IDtoXSEC[361024] = 254630*1.*0.00053009*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ4W
  m_IDtoXSEC[361025] = 4553.5*1.*0.00092325*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ5W
  m_IDtoXSEC[361026] = 257.53*1.*0.00094016*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ6W
  m_IDtoXSEC[361027] = 016.215*1.*0.00039282*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ7W
  m_IDtoXSEC[361028] = 0.62502*1.*0.010162*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ8W
  m_IDtoXSEC[361029] = 0.019639*1.*0.012054*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ9W
  m_IDtoXSEC[361030] = 0.0011962*1.*0.0058935*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ10W
  m_IDtoXSEC[361031] = 0.000042258*1.*0.0027015*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ11W
  m_IDtoXSEC[361032] = 0.0000010367*1.*0.00042502*1.; // Pythia8EvtGen_A14NNPDF23LO_jetjet_JZ12W
  m_IDtoXSEC[426001] = 421630000000*1.*0.0034956*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ1
  m_IDtoXSEC[426002] = 48024000000*1.*0.00041070*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ2
  m_IDtoXSEC[426003] = 1908400000*1.*0.00014988*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ3
  m_IDtoXSEC[426004] = 173620000*1.*0.000018654*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ4
  m_IDtoXSEC[426005] = 5259400*1.*0.000011846*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ5
  m_IDtoXSEC[426006] = 276120*1.*0.0000083645*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ6
  m_IDtoXSEC[426007] = 26410*1.*0.0000066710*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ7
  m_IDtoXSEC[426008] = 77.298*1.*0.000083211*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ8
  m_IDtoXSEC[426009] = 2.747*1.*0.000090501*1.; // PowhegPythia8EvtGen_A14_NNPDF23LO_CT10ME_jetjet_JZ9
  m_IDtoXSEC[370738] = 0.04995128*1.*1.*1.; // SS_direct_1000_400
  m_IDtoXSEC[370736] = 0.04995128*1.*1.*1.; // SS_direct_1000_0
  m_IDtoXSEC[370762] = 0.00377649*1.*1.*1.; // SS_direct_1400_0
  m_IDtoXSEC[370724] = 0.2307168*1.*1.*1.; // SS_direct_800_200
  m_IDtoXSEC[370723] = 0.2307168*1.*1.*1.; // SS_direct_800_0
  m_IDtoXSEC[370775] = 0.001188424*1.*1.*1.; // SS_direct_1600_0
  m_IDtoXSEC[370749] = 0.01302768*1.*1.*1.; // SS_direct_1200_0
  m_IDtoXSEC[370750] = 0.01302768*1.*1.*1.; // SS_direct_1200_200
  m_IDtoXSEC[406001] = 0.03517848*1.*1.*1.; // SS_direct_1050_0
  m_IDtoXSEC[370711] = 1.41316*1.*1.*1.; // SS_direct_600_400
  m_IDtoXSEC[370703] = 10.55848*1.*1.*1.; // SS_direct_425_375
  m_IDtoXSEC[370725] = 0.2307168*1.*1.*1.; // SS_direct_800_400
  m_IDtoXSEC[370901] = 98.0459*1.*1.*1.; // GG_direct_400_0
  m_IDtoXSEC[370902] = 9.20353*1.*1.*1.; // GG_direct_600_0
  m_IDtoXSEC[370903] = 8.30988*1.*1.*1.; // GG_direct_612_587
  m_IDtoXSEC[370904] = 7.15194*1.*1.*1.; // GG_direct_625_575
  m_IDtoXSEC[370905] = 5.60048*1.*1.*1.; // GG_direct_650_550
  m_IDtoXSEC[370907] = 3.22336*1.*1.*1.; // GG_direct_712_687
  m_IDtoXSEC[370908] = 2.81957*1.*1.*1.; // GG_direct_725_675
  m_IDtoXSEC[370909] = 2.26585*1.*1.*1.; // GG_direct_750_650
  m_IDtoXSEC[370912] = 1.36759*1.*1.*1.; // GG_direct_812_787
  m_IDtoXSEC[370913] = 1.2167*1.*1.*1.; // GG_direct_825_775
  m_IDtoXSEC[370915] = 0.996137*1.*1.*1.; // GG_direct_850_750
  m_IDtoXSEC[370916] = 0.677478*1.*1.*1.; // GG_direct_900_500
  m_IDtoXSEC[370917] = 0.677478*1.*1.*1.; // GG_direct_900_700
  m_IDtoXSEC[370918] = 0.627695*1.*1.*1.; // GG_direct_912_887
  m_IDtoXSEC[370919] = 0.561889*1.*1.*1.; // GG_direct_925_875
  m_IDtoXSEC[370920] = 0.466352*1.*1.*1.; // GG_direct_950_650
  m_IDtoXSEC[370924] = 0.325388*1.*1.*1.; // GG_direct_1000_800
  m_IDtoXSEC[370925] = 0.229367*1.*1.*1.; // GG_direct_1050_550
  m_IDtoXSEC[370927] = 0.163491*1.*1.*1.; // GG_direct_1100_100
  m_IDtoXSEC[370928] = 0.163491*1.*1.*1.; // GG_direct_1100_300
  m_IDtoXSEC[370929] = 0.163491*1.*1.*1.; // GG_direct_1100_500
  m_IDtoXSEC[370930] = 0.163491*1.*1.*1.; // GG_direct_1100_700
  m_IDtoXSEC[370931] = 0.163491*1.*1.*1.; // GG_direct_1100_900
  m_IDtoXSEC[370932] = 0.117687*1.*1.*1.; // GG_direct_1150_50
  m_IDtoXSEC[370933] = 0.117687*1.*1.*1.; // GG_direct_1150_250
  m_IDtoXSEC[370934] = 0.117687*1.*1.*1.; // GG_direct_1150_450
  m_IDtoXSEC[370935] = 0.117687*1.*1.*1.; // GG_direct_1150_650
  m_IDtoXSEC[370936] = 0.117687*1.*1.*1.; // GG_direct_1150_850
  m_IDtoXSEC[370937] = 0.0856418*1.*1.*1.; // GG_direct_1200_0
  m_IDtoXSEC[370939] = 0.0856418*1.*1.*1.; // GG_direct_1200_400
  m_IDtoXSEC[370940] = 0.0856418*1.*1.*1.; // GG_direct_1200_600
  m_IDtoXSEC[370941] = 0.0856418*1.*1.*1.; // GG_direct_1200_800
  m_IDtoXSEC[370942] = 0.0627027*1.*1.*1.; // GG_direct_1250_150
  m_IDtoXSEC[370944] = 0.0627027*1.*1.*1.; // GG_direct_1250_550
  m_IDtoXSEC[370946] = 0.0460525*1.*1.*1.; // GG_direct_1300_100
  m_IDtoXSEC[370947] = 0.0460525*1.*1.*1.; // GG_direct_1300_300
  m_IDtoXSEC[370948] = 0.0460525*1.*1.*1.; // GG_direct_1300_500
  m_IDtoXSEC[370949] = 0.0460525*1.*1.*1.; // GG_direct_1300_700
  m_IDtoXSEC[370950] = 0.0460525*1.*1.*1.; // GG_direct_1300_900
  m_IDtoXSEC[370951] = 0.0340187*1.*1.*1.; // GG_direct_1350_50
  m_IDtoXSEC[370952] = 0.0340187*1.*1.*1.; // GG_direct_1350_250
  m_IDtoXSEC[370953] = 0.0340187*1.*1.*1.; // GG_direct_1350_450
  m_IDtoXSEC[370956] = 0.0252977*1.*1.*1.; // GG_direct_1400_0
  m_IDtoXSEC[370957] = 0.0252977*1.*1.*1.; // GG_direct_1400_200
  m_IDtoXSEC[370958] = 0.0252977*1.*1.*1.; // GG_direct_1400_400
  m_IDtoXSEC[370960] = 0.0252977*1.*1.*1.; // GG_direct_1400_800
  m_IDtoXSEC[370961] = 0.0188887*1.*1.*1.; // GG_direct_1450_150
  m_IDtoXSEC[370963] = 0.0188887*1.*1.*1.; // GG_direct_1450_550
  m_IDtoXSEC[370964] = 0.0188887*1.*1.*1.; // GG_direct_1450_750
  m_IDtoXSEC[370965] = 0.0141903*1.*1.*1.; // GG_direct_1500_100
  m_IDtoXSEC[370966] = 0.0141903*1.*1.*1.; // GG_direct_1500_300
  m_IDtoXSEC[370969] = 0.0141903*1.*1.*1.; // GG_direct_1500_900
  m_IDtoXSEC[370970] = 0.0107027*1.*1.*1.; // GG_direct_1550_50
  m_IDtoXSEC[370971] = 0.0107027*1.*1.*1.; // GG_direct_1550_250
  m_IDtoXSEC[370972] = 0.0107027*1.*1.*1.; // GG_direct_1550_450
  m_IDtoXSEC[370974] = 0.0107027*1.*1.*1.; // GG_direct_1550_850
  m_IDtoXSEC[370975] = 0.00810078*1.*1.*1.; // GG_direct_1600_0
  m_IDtoXSEC[370976] = 0.00810078*1.*1.*1.; // GG_direct_1600_200
  m_IDtoXSEC[370977] = 0.00810078*1.*1.*1.; // GG_direct_1600_400
  m_IDtoXSEC[370978] = 0.00810078*1.*1.*1.; // GG_direct_1600_600
  m_IDtoXSEC[370979] = 0.00810078*1.*1.*1.; // GG_direct_1600_800
  m_IDtoXSEC[370980] = 0.00616072*1.*1.*1.; // GG_direct_1650_150
  m_IDtoXSEC[370981] = 0.00616072*1.*1.*1.; // GG_direct_1650_350
  m_IDtoXSEC[370982] = 0.00616072*1.*1.*1.; // GG_direct_1650_550
  m_IDtoXSEC[370983] = 0.00616072*1.*1.*1.; // GG_direct_1650_750
  m_IDtoXSEC[370984] = 0.00470323*1.*1.*1.; // GG_direct_1700_100
  m_IDtoXSEC[370986] = 0.00470323*1.*1.*1.; // GG_direct_1700_500
  m_IDtoXSEC[370987] = 0.00470323*1.*1.*1.; // GG_direct_1700_700
  m_IDtoXSEC[370988] = 0.00470323*1.*1.*1.; // GG_direct_1700_900
  m_IDtoXSEC[370989] = 0.00359842*1.*1.*1.; // GG_direct_1750_50
  m_IDtoXSEC[370990] = 0.00359842*1.*1.*1.; // GG_direct_1750_250
  m_IDtoXSEC[370992] = 0.00359842*1.*1.*1.; // GG_direct_1750_650
  m_IDtoXSEC[370994] = 0.00276133*1.*1.*1.; // GG_direct_1800_0
  m_IDtoXSEC[370995] = 0.00276133*1.*1.*1.; // GG_direct_1800_200
  m_IDtoXSEC[370998] = 0.00276133*1.*1.*1.; // GG_direct_1800_800
  m_IDtoXSEC[370999] = 0.00212345*1.*1.*1.; // GG_direct_1850_150
  m_IDtoXSEC[371002] = 0.00212345*1.*1.*1.; // GG_direct_1850_750
  m_IDtoXSEC[371004] = 0.00163547*1.*1.*1.; // GG_direct_1900_300
  m_IDtoXSEC[371005] = 0.00163547*1.*1.*1.; // GG_direct_1900_500
  m_IDtoXSEC[371006] = 0.00163547*1.*1.*1.; // GG_direct_1900_700
  m_IDtoXSEC[371007] = 0.00163547*1.*1.*1.; // GG_direct_1900_900
  m_IDtoXSEC[371008] = 0.0012642*1.*1.*1.; // GG_direct_1950_50
  m_IDtoXSEC[371009] = 0.0012642*1.*1.*1.; // GG_direct_1950_250
  m_IDtoXSEC[371010] = 0.0012642*1.*1.*1.; // GG_direct_1950_450
  m_IDtoXSEC[371011] = 0.0012642*1.*1.*1.; // GG_direct_1950_650
  m_IDtoXSEC[371012] = 0.0012642*1.*1.*1.; // GG_direct_1950_850
  m_IDtoXSEC[371013] = 0.000981077*1.*1.*1.; // GG_direct_2000_0
  m_IDtoXSEC[371014] = 0.000981077*1.*1.*1.; // GG_direct_2000_200
  m_IDtoXSEC[371016] = 0.000981077*1.*1.*1.; // GG_direct_2000_600
  m_IDtoXSEC[371017] = 0.000981077*1.*1.*1.; // GG_direct_2000_800
  m_IDtoXSEC[406000] = 0.0141903*1.*1.*1.; // GG_direct_1500_0
}

template <class Base>
double AnalysisBase<Base>::GetEventWeight(){
  return 0;
}

template <class Base>
TVector3 AnalysisBase<Base>::GetMET(){
  return TVector3(0.,0.,0.);
}

template <class Base>
int AnalysisBase<Base>::GetJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut) {
  return 0.;
}

template <class Base>
int AnalysisBase<Base>::GetLargeRJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut) {
  return 0.;
}

template <>
double AnalysisBase<ZeroLeptonBase>::GetEventWeight(){
  // if(m_IDtoNEVT[m_DSID] <= 0. || NTVars_eventWeight <= 0.) return 0.;
  // return 1000.*m_IDtoXSEC[m_DSID]*NTVars_eventWeight/m_IDtoNEVT[m_DSID];
  // if(NTVars_eventWeight <= 0. || NTVars_normWeight <= 0.)
  //   return 0.;
  return 1000.*NTVars_eventWeight*NTVars_normWeight*NTVars_WZweight;
  //return 1000.*NTVars_eventWeight*NTVars_normWeight*NTVars_pileupWeight;
  //return 1.;
}

template <>
TVector3 AnalysisBase<ZeroLeptonBase>::GetMET(){
  TVector3 met;
  met.SetPtEtaPhi(NTVars_met,0.0,NTVars_metPhi);
  return met;
}

template <>
int AnalysisBase<ZeroLeptonBase>::GetJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut){
  // hack for R__unzip errors
  int Njet = std::min(jetPt->size(),std::min(jetEta->size(),std::min(jetPhi->size(),jetM->size())));
  for(int i = 0; i < Njet; i++){
    if((jetPt->at(i) >= pt_cut) && (fabs(jetEta->at(i)) < eta_cut || eta_cut < 0)){
      TLorentzVector JET;
      float mass = jetM->at(i);
      if(std::isnan(mass))
	mass = 0;
      if(std::isinf(mass))
	mass = 0;
      if(mass < 0.)
	mass = 0.;
      JET.SetPtEtaPhiM( jetPt->at(i), jetEta->at(i), jetPhi->at(i), mass );
      JETs.push_back(JET);
    }
  }
  return 0.;
}

template <>
double AnalysisBase<ChicagoBase>::GetEventWeight(){
  return event_weight;
}

template <>
TVector3 AnalysisBase<ChicagoBase>::GetMET(){
  TVector3 met;
  met.SetXYZ(met_px,met_py,0.);
  return met;
}

template <>
int AnalysisBase<ChicagoBase>::GetJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut){
  int Njet = jet_pt->size();
  int NB = 0;
  for(int i = 0; i < Njet; i++){
    if((jet_pt->at(i) >= pt_cut) && (fabs(jet_eta->at(i)) < eta_cut || eta_cut < 0)){
      TLorentzVector JET;
      JET.SetPtEtaPhiM(jet_pt->at(i)/1000.,jet_eta->at(i),jet_phi->at(i),jet_m->at(i)/1000.);
      JETs.push_back(JET);
      if(jet_isB->at(i))
	NB++;
    }
  }
  return NB;
}

template<>
int AnalysisBase<ChicagoBase>::GetLargeRJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut){
  int Njet = jet_largeR_pt->size();
  int NTOP = 0;
  for(int i = 0; i < Njet; i++){
    if((jet_largeR_pt->at(i) >= pt_cut) && (fabs(jet_largeR_eta->at(i)) < eta_cut)){
      TLorentzVector JET;
      JET.SetPtEtaPhiM(jet_largeR_pt->at(i)/1000.,jet_largeR_eta->at(i),jet_largeR_phi->at(i),jet_largeR_m->at(i)/1000.);
      JETs.push_back(JET);
      if(jet_largeR_isTopLoose->at(i))
        NTOP++;
    }
  }
  return NTOP;
}

template <>
double AnalysisBase<SunBase>::GetEventWeight(){
  return fabs(m_weight);
}

template <>
TVector3 AnalysisBase<SunBase>::GetMET(){
  TVector3 met;
  met.SetPtEtaPhi(m_met_Et,0.,m_met_phi);
  return met;
}

template <>
int AnalysisBase<SunBase>::GetJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut){
  int Njet = m_jet_n;
  int NB = 0;
  for(int i = 0; i < Njet; i++){
    if((m_jet_pt->at(i) >= pt_cut) && (fabs(m_jet_eta->at(i)) < eta_cut || eta_cut < 0)){
      TLorentzVector JET;
      JET.SetPtEtaPhiE(m_jet_pt->at(i),m_jet_eta->at(i),m_jet_phi->at(i),m_jet_E->at(i));
      JETs.push_back(JET);
      if(m_jet_btag->at(i))
	NB++;
    }
  }
  return NB;
}

template <>
int AnalysisBase<SunBase>::GetJetsBtag(vector<pair<TLorentzVector, bool> >& JETs, double pt_cut, double eta_cut){
  int Njet = m_jet_n;
  int NB = 0;
  for(int i = 0; i < Njet; i++){
    if((m_jet_pt->at(i) >= pt_cut) && (fabs(m_jet_eta->at(i)) < eta_cut || eta_cut < 0)){
      TLorentzVector JET;
      JET.SetPtEtaPhiE(m_jet_pt->at(i),m_jet_eta->at(i),m_jet_phi->at(i),m_jet_E->at(i));
      JETs.push_back(pair<TLorentzVector,bool>(JET,m_jet_btag->at(i)));
      if(m_jet_btag->at(i))
	NB++;
    }
  }
  return NB;
}

template class AnalysisBase<ZeroLeptonBase>;
template class AnalysisBase<ChicagoBase>;
template class AnalysisBase<SunBase>;

