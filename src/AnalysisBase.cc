#include <TH1D.h>
#include <iostream>

#include "AnalysisBase.hh"
#include "InputTreeBase.hh"

using namespace std;

template <class Base>
AnalysisBase<Base>::AnalysisBase(TTree* tree)
  : Base(tree)
{
  m_CurrentFile = -1;
  m_DSID = -1;
  m_Nevent = 0.;
  m_Label  = "";
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
void AnalysisBase<Base>::AddLabel(string& label){
  m_Label = label;
}

template <class Base>
void AnalysisBase<Base>::AddNevent(double nevt){
  m_Nevent = nevt;
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
void AnalysisBase<Base>::InitXSECmap() {}

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
void AnalysisBase<InputTreeBase>::InitXSECmap() {
  m_IDtoXSEC["TTJets"] =        831.76;
  m_IDtoXSEC["WJets"] =         95.14;
  m_IDtoXSEC["QCDHT100"] =      27540000;
  m_IDtoXSEC["QCDHT200"] =      2000000;
  m_IDtoXSEC["QCDHT300"] =      351300;
  m_IDtoXSEC["QCDHT500"] =      31630;
  m_IDtoXSEC["QCDHT700"] =      6831;
  m_IDtoXSEC["QCDHT1000"] =     1207;
  m_IDtoXSEC["QCDHT1500"] =     119.9;
  m_IDtoXSEC["QCDHT2000"] =     25.24;
  m_IDtoXSEC["QCDPt80"] =      2762530;
  m_IDtoXSEC["QCDPt120"] =     471100;
  m_IDtoXSEC["QCDPt170"] =     117276.; 
  m_IDtoXSEC["QCDPt300"] =     7823.;
  m_IDtoXSEC["QCDPt470"] =     648.2;
  m_IDtoXSEC["QCDPt600"] =     186.9;
  m_IDtoXSEC["QCDPt800"] =     32.293;
  m_IDtoXSEC["QCDPt1000"] =    9.4183;
  m_IDtoXSEC["QCDPt1400"] =    0.84265;
  m_IDtoXSEC["QCDPt1800"] =    0.114943;
  m_IDtoXSEC["QCDPt2400"] =    0.00682981;
  m_IDtoXSEC["QCDPt3200"] =    0.000165445;
  m_IDtoXSEC["ST"] =            35.6;
  m_IDtoXSEC["ZJets"] =         6.97;
  m_IDtoXSEC["DYJets"] =         1187; //LO
  m_IDtoXSEC["ttZJets"] =       0.616; //LO
  m_IDtoXSEC["ttWJets"] =       0.511; //LO
  m_IDtoXSEC["tHQ"] =           0.2608;
  m_IDtoXSEC["WW"] =            28.7;
  m_IDtoXSEC["ZZ"] =            6.842;

  m_IDtoXSEC["TbtH_800_LH"] = 0.241; // *(0.5*0.5)*0.25 = 0.0625
  m_IDtoXSEC["TttH_800_LH"] = 0.0456; // *(0.5*0.5)*0.50 = 0.1250
  m_IDtoXSEC["TbtH_800_RH"] = 0.241;
  m_IDtoXSEC["TttH_800_RH"] = 0.0456;

  m_IDtoXSEC["TbtH_900_LH"] = 0.170; // *(0.5*0.5)*0.25 = 0.0625
  m_IDtoXSEC["TttH_900_LH"] = 0.0339; // *(0.5*0.5)*0.50 = 0.1250
  m_IDtoXSEC["TbtH_900_RH"] = 0.170;
  m_IDtoXSEC["TttH_900_RH"] = 0.0339;

  m_IDtoXSEC["TbtH_1000_LH"] = 0.122; // *(0.5*0.5)*0.25 = 0.0625
  m_IDtoXSEC["TttH_1000_LH"] = 0.0254; // *(0.5*0.5)*0.50 = 0.1250
  m_IDtoXSEC["TbtH_1000_RH"] = 0.122;
  m_IDtoXSEC["TttH_1000_RH"] = 0.0254;

  m_IDtoXSEC["TbtH_1100_LH"] = 0.0844;
  m_IDtoXSEC["TttH_1100_LH"] = 0.0190;
  m_IDtoXSEC["TbtH_1100_RH"] = 0.0844;
  m_IDtoXSEC["TttH_1100_RH"] = 0.0190;

  m_IDtoXSEC["TbtH_1200_LH"] = 0.0614;
  m_IDtoXSEC["TttH_1200_LH"] = 0.0145;
  m_IDtoXSEC["TbtH_1200_RH"] = 0.0614;
  m_IDtoXSEC["TttH_1200_RH"] = 0.0145;

  m_IDtoXSEC["TbtH_1300_LH"] = 0.0448;
  m_IDtoXSEC["TttH_1300_LH"] = 0.0112;
  m_IDtoXSEC["TbtH_1300_RH"] = 0.0448;
  m_IDtoXSEC["TttH_1300_RH"] = 0.0112;

  m_IDtoXSEC["TbtH_1400_LH"] = 0.0338;
  m_IDtoXSEC["TttH_1400_LH"] = 0.00865;
  m_IDtoXSEC["TbtH_1400_RH"] = 0.0338;
  m_IDtoXSEC["TttH_1400_RH"] = 0.00865;

  m_IDtoXSEC["TbtH_1500_LH"] = 0.0255;
  m_IDtoXSEC["TttH_1500_LH"] = 0.00675;
  m_IDtoXSEC["TbtH_1500_RH"] = 0.0255;
  m_IDtoXSEC["TttH_1500_RH"] = 0.00675;

  m_IDtoXSEC["TbtH_1600_LH"] = 0.0191;
  m_IDtoXSEC["TttH_1600_LH"] = 0.00525;
  m_IDtoXSEC["TbtH_1600_RH"] = 0.0191;
  m_IDtoXSEC["TttH_1600_RH"] = 0.00525;

  m_IDtoXSEC["TbtH_1700_LH"] = 0.0144;
  m_IDtoXSEC["TttH_1700_LH"] = 0.00413;
  m_IDtoXSEC["TbtH_1700_RH"] = 0.0144;
  m_IDtoXSEC["TttH_1700_RH"] = 0.00413;

  m_IDtoXSEC["TbtH_1800_LH"] = 0.0109;
  m_IDtoXSEC["TttH_1800_LH"] = 0.00324;
  m_IDtoXSEC["TbtH_1800_RH"] = 0.0109;
  m_IDtoXSEC["TttH_1800_RH"] = 0.00324;

  m_IDtoXSEC["TbtH_1000_10p_LH"] = 0.122; // *(0.5*0.5)*0.25 = 0.0625
  m_IDtoXSEC["TttH_1000_10p_LH"] = 0.0254; // *(0.5*0.5)*0.50 = 0.1250
  m_IDtoXSEC["TbtH_1000_10p_RH"] = 0.122;
  m_IDtoXSEC["TttH_1000_10p_RH"] = 0.0254;

  m_IDtoXSEC["TbtH_1100_10p_LH"] = 0.0844;
  m_IDtoXSEC["TttH_1100_10p_LH"] = 0.0190;
  m_IDtoXSEC["TbtH_1100_10p_RH"] = 0.0844;
  m_IDtoXSEC["TttH_1100_10p_RH"] = 0.0190;

  m_IDtoXSEC["TbtH_1200_10p_LH"] = 0.0614;
  m_IDtoXSEC["TttH_1200_10p_LH"] = 0.0145;
  m_IDtoXSEC["TbtH_1200_10p_RH"] = 0.0614;
  m_IDtoXSEC["TttH_1200_10p_RH"] = 0.0145;

  m_IDtoXSEC["TbtH_1300_10p_LH"] = 0.0448;
  m_IDtoXSEC["TttH_1300_10p_LH"] = 0.0112;
  m_IDtoXSEC["TbtH_1300_10p_RH"] = 0.0448;
  m_IDtoXSEC["TttH_1300_10p_RH"] = 0.0112;

  m_IDtoXSEC["TbtH_1400_10p_LH"] = 0.0338;
  m_IDtoXSEC["TttH_1400_10p_LH"] = 0.00865;
  m_IDtoXSEC["TbtH_1400_10p_RH"] = 0.0338;
  m_IDtoXSEC["TttH_1400_10p_RH"] = 0.00865;

  m_IDtoXSEC["TbtH_1500_10p_LH"] = 0.0255;
  m_IDtoXSEC["TttH_1500_10p_LH"] = 0.00675;
  m_IDtoXSEC["TbtH_1500_10p_RH"] = 0.0255;
  m_IDtoXSEC["TttH_1500_10p_RH"] = 0.00675;

  m_IDtoXSEC["TbtH_1600_10p_LH"] = 0.0191;
  m_IDtoXSEC["TttH_1600_10p_LH"] = 0.00525;
  m_IDtoXSEC["TbtH_1600_10p_RH"] = 0.0191;
  m_IDtoXSEC["TttH_1600_10p_RH"] = 0.00525;

  m_IDtoXSEC["TbtH_1700_10p_LH"] = 0.0144;
  m_IDtoXSEC["TttH_1700_10p_LH"] = 0.00413;
  m_IDtoXSEC["TbtH_1700_10p_RH"] = 0.0144;
  m_IDtoXSEC["TttH_1700_10p_RH"] = 0.00413;

  m_IDtoXSEC["TbtH_1800_10p_LH"] = 0.0109;
  m_IDtoXSEC["TttH_1800_10p_LH"] = 0.00324;
  m_IDtoXSEC["TbtH_1800_10p_RH"] = 0.0109;
  m_IDtoXSEC["TttH_1800_10p_RH"] = 0.00324;

  m_IDtoXSEC["TbtH_2000_10p_LH"] = 0.00638;
  m_IDtoXSEC["TttH_2000_10p_LH"] = 0.00203;
  m_IDtoXSEC["TbtH_2000_10p_RH"] = 0.00638;
  m_IDtoXSEC["TttH_2000_10p_RH"] = 0.00203;

  m_IDtoXSEC["TbtH_2400_10p_LH"] = 0.00222;
  m_IDtoXSEC["TttH_2400_10p_LH"] = 0.000283;
  m_IDtoXSEC["TbtH_2400_10p_RH"] = 0.00222;
  m_IDtoXSEC["TttH_2400_10p_RH"] = 0.000283;

  m_IDtoXSEC["TbtH_2600_10p_LH"] = 0.00122;
  m_IDtoXSEC["TttH_2600_10p_LH"] = 0.000155;
  m_IDtoXSEC["TbtH_2600_10p_RH"] = 0.00122;
  m_IDtoXSEC["TttH_2600_10p_RH"] = 0.000155;

  m_IDtoXSEC["TbtH_1000_20p_LH"] = 0.122; // *(0.5*0.5)*0.25 = 0.0625
  m_IDtoXSEC["TttH_1000_20p_LH"] = 0.0254; // *(0.5*0.5)*0.50 = 0.1250
  m_IDtoXSEC["TbtH_1000_20p_RH"] = 0.122;
  m_IDtoXSEC["TttH_1000_20p_RH"] = 0.0254;

  m_IDtoXSEC["TbtH_1100_20p_LH"] = 0.0844;
  m_IDtoXSEC["TttH_1100_20p_LH"] = 0.0190;
  m_IDtoXSEC["TbtH_1100_20p_RH"] = 0.0844;
  m_IDtoXSEC["TttH_1100_20p_RH"] = 0.0190;

  m_IDtoXSEC["TbtH_1200_20p_LH"] = 0.0614;
  m_IDtoXSEC["TttH_1200_20p_LH"] = 0.0145;
  m_IDtoXSEC["TbtH_1200_20p_RH"] = 0.0614;
  m_IDtoXSEC["TttH_1200_20p_RH"] = 0.0145;

  m_IDtoXSEC["TbtH_1300_20p_LH"] = 0.0448;
  m_IDtoXSEC["TttH_1300_20p_LH"] = 0.0112;
  m_IDtoXSEC["TbtH_1300_20p_RH"] = 0.0448;
  m_IDtoXSEC["TttH_1300_20p_RH"] = 0.0112;

  m_IDtoXSEC["TbtH_1400_20p_LH"] = 0.0338;
  m_IDtoXSEC["TttH_1400_20p_LH"] = 0.00865;
  m_IDtoXSEC["TbtH_1400_20p_RH"] = 0.0338;
  m_IDtoXSEC["TttH_1400_20p_RH"] = 0.00865;

  m_IDtoXSEC["TbtH_1500_20p_LH"] = 0.0255;
  m_IDtoXSEC["TttH_1500_20p_LH"] = 0.00675;
  m_IDtoXSEC["TbtH_1500_20p_RH"] = 0.0255;
  m_IDtoXSEC["TttH_1500_20p_RH"] = 0.00675;

  m_IDtoXSEC["TbtH_1600_20p_LH"] = 0.0191;
  m_IDtoXSEC["TttH_1600_20p_LH"] = 0.00525;
  m_IDtoXSEC["TbtH_1600_20p_RH"] = 0.0191;
  m_IDtoXSEC["TttH_1600_20p_RH"] = 0.00525;

  m_IDtoXSEC["TbtH_1700_20p_LH"] = 0.0144;
  m_IDtoXSEC["TttH_1700_20p_LH"] = 0.00413;
  m_IDtoXSEC["TbtH_1700_20p_RH"] = 0.0144;
  m_IDtoXSEC["TttH_1700_20p_RH"] = 0.00413;

  m_IDtoXSEC["TbtH_1800_20p_LH"] = 0.0109;
  m_IDtoXSEC["TttH_1800_20p_LH"] = 0.00324;
  m_IDtoXSEC["TbtH_1800_20p_RH"] = 0.0109;
  m_IDtoXSEC["TttH_1800_20p_RH"] = 0.00324;

  m_IDtoXSEC["TbtH_2000_20p_LH"] = 0.00638;
  m_IDtoXSEC["TttH_2000_20p_LH"] = 0.00203;
  m_IDtoXSEC["TbtH_2000_20p_RH"] = 0.00638;
  m_IDtoXSEC["TttH_2000_20p_RH"] = 0.00203;

  m_IDtoXSEC["TbtH_2400_20p_LH"] = 0.00222;
  m_IDtoXSEC["TttH_2400_20p_LH"] = 0.000283;
  m_IDtoXSEC["TbtH_2400_20p_RH"] = 0.00222;
  m_IDtoXSEC["TttH_2400_20p_RH"] = 0.000283;

  m_IDtoXSEC["TbtH_2600_20p_LH"] = 0.00122;
  m_IDtoXSEC["TttH_2600_20p_LH"] = 0.000155;
  m_IDtoXSEC["TbtH_2600_20p_RH"] = 0.00122;
  m_IDtoXSEC["TttH_2600_20p_RH"] = 0.000155;

  m_IDtoXSEC["TbtH_1000_30p_LH"] = 0.122; // *(0.5*0.5)*0.25 = 0.0625
  m_IDtoXSEC["TttH_1000_30p_LH"] = 0.0254; // *(0.5*0.5)*0.50 = 0.1250
  m_IDtoXSEC["TbtH_1000_30p_RH"] = 0.122;
  m_IDtoXSEC["TttH_1000_30p_RH"] = 0.0254;

  m_IDtoXSEC["TbtH_1100_30p_LH"] = 0.0844;
  m_IDtoXSEC["TttH_1100_30p_LH"] = 0.0190;
  m_IDtoXSEC["TbtH_1100_30p_RH"] = 0.0844;
  m_IDtoXSEC["TttH_1100_30p_RH"] = 0.0190;

  m_IDtoXSEC["TbtH_1200_30p_LH"] = 0.0614;
  m_IDtoXSEC["TttH_1200_30p_LH"] = 0.0145;
  m_IDtoXSEC["TbtH_1200_30p_RH"] = 0.0614;
  m_IDtoXSEC["TttH_1200_30p_RH"] = 0.0145;

  m_IDtoXSEC["TbtH_1300_30p_LH"] = 0.0448;
  m_IDtoXSEC["TttH_1300_30p_LH"] = 0.0112;
  m_IDtoXSEC["TbtH_1300_30p_RH"] = 0.0448;
  m_IDtoXSEC["TttH_1300_30p_RH"] = 0.0112;

  m_IDtoXSEC["TbtH_1400_30p_LH"] = 0.0338;
  m_IDtoXSEC["TttH_1400_30p_LH"] = 0.00865;
  m_IDtoXSEC["TbtH_1400_30p_RH"] = 0.0338;
  m_IDtoXSEC["TttH_1400_30p_RH"] = 0.00865;

  m_IDtoXSEC["TbtH_1500_30p_LH"] = 0.0255;
  m_IDtoXSEC["TttH_1500_30p_LH"] = 0.00675;
  m_IDtoXSEC["TbtH_1500_30p_RH"] = 0.0255;
  m_IDtoXSEC["TttH_1500_30p_RH"] = 0.00675;

  m_IDtoXSEC["TbtH_1600_30p_LH"] = 0.0191;
  m_IDtoXSEC["TttH_1600_30p_LH"] = 0.00525;
  m_IDtoXSEC["TbtH_1600_30p_RH"] = 0.0191;
  m_IDtoXSEC["TttH_1600_30p_RH"] = 0.00525;

  m_IDtoXSEC["TbtH_1700_30p_LH"] = 0.0144;
  m_IDtoXSEC["TttH_1700_30p_LH"] = 0.00413;
  m_IDtoXSEC["TbtH_1700_30p_RH"] = 0.0144;
  m_IDtoXSEC["TttH_1700_30p_RH"] = 0.00413;

  m_IDtoXSEC["TbtH_1800_30p_LH"] = 0.0109;
  m_IDtoXSEC["TttH_1800_30p_LH"] = 0.00324;
  m_IDtoXSEC["TbtH_1800_30p_RH"] = 0.0109;
  m_IDtoXSEC["TttH_1800_30p_RH"] = 0.00324;

  m_IDtoXSEC["TbtH_2000_30p_LH"] = 0.00638;
  m_IDtoXSEC["TttH_2000_30p_LH"] = 0.00203;
  m_IDtoXSEC["TbtH_2000_30p_RH"] = 0.00638;
  m_IDtoXSEC["TttH_2000_30p_RH"] = 0.00203;

  m_IDtoXSEC["TbtH_2400_30p_LH"] = 0.00222;
  m_IDtoXSEC["TttH_2400_30p_LH"] = 0.000283;
  m_IDtoXSEC["TbtH_2400_30p_RH"] = 0.00222;
  m_IDtoXSEC["TttH_2400_30p_RH"] = 0.000283;

  m_IDtoXSEC["TbtH_2600_30p_LH"] = 0.00122;
  m_IDtoXSEC["TttH_2600_30p_LH"] = 0.000155;
  m_IDtoXSEC["TbtH_2600_30p_RH"] = 0.00122;
  m_IDtoXSEC["TttH_2600_30p_RH"] = 0.000155;
  m_IDtoXSEC["TbtZ_1200_RH"] = 0.0614;
  m_IDtoXSEC["TbtZ_1800_RH"] = 0.0109;
  
}

template <>
double AnalysisBase<InputTreeBase>::GetEventWeight(){
  // if(m_IDtoNEVT[m_DSID] <= 0. || NTVars_eventWeight <= 0.) return 0.;
  // return 1000.*m_IDtoXSEC[m_DSID]*NTVars_eventWeight/m_IDtoNEVT[m_DSID];
  // if(NTVars_eventWeight <= 0. || NTVars_normWeight <= 0.)
  //   return 0.;
  if(m_Nevent > 0.)
    return 1000.*m_IDtoXSEC[m_Label]*SelectedEvent_EvtWeight*SelectedEvent_EvtWtPV/m_Nevent;
  else
    return 0.;
}

// template <>
// TVector3 AnalysisBase<ZeroLeptonBase>::GetMET(){
//   TVector3 met;
//   met.SetPtEtaPhi(NTVars_met,0.0,NTVars_metPhi);
//   return met;
// }

// template <>
// int AnalysisBase<ZeroLeptonBase>::GetJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut){
//   // hack for R__unzip errors
//   int Njet = std::min(jetPt->size(),std::min(jetEta->size(),std::min(jetPhi->size(),jetM->size())));
//   for(int i = 0; i < Njet; i++){
//     if((jetPt->at(i) >= pt_cut) && (fabs(jetEta->at(i)) < eta_cut || eta_cut < 0)){
//       TLorentzVector JET;
//       float mass = jetM->at(i);
//       if(std::isnan(mass))
// 	mass = 0;
//       if(std::isinf(mass))
// 	mass = 0;
//       if(mass < 0.)
// 	mass = 0.;
//       JET.SetPtEtaPhiM( jetPt->at(i), jetEta->at(i), jetPhi->at(i), mass );
//       JETs.push_back(JET);
//     }
//   }
//   return 0.;
// }

// template<>
// int AnalysisBase<ChicagoBase>::GetLargeRJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut){
//   int Njet = jet_largeR_pt->size();
//   int NTOP = 0;
//   for(int i = 0; i < Njet; i++){
//     if((jet_largeR_pt->at(i) >= pt_cut) && (fabs(jet_largeR_eta->at(i)) < eta_cut)){
//       TLorentzVector JET;
//       JET.SetPtEtaPhiM(jet_largeR_pt->at(i)/1000.,jet_largeR_eta->at(i),jet_largeR_phi->at(i),jet_largeR_m->at(i)/1000.);
//       JETs.push_back(JET);
//       if(jet_largeR_isTopLoose->at(i))
//         NTOP++;
//     }
//   }
//   return NTOP;
// }

template class AnalysisBase<InputTreeBase>;

