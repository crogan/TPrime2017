#include <TH1D.h>
#include <iostream>

#include "AnalysisBase.hh"
#include "InputTreeBase.hh"
#include "TMatrixDSym.h"
#include "TVectorD.h"

using namespace std;

template <class Base>
AnalysisBase<Base>::AnalysisBase(TTree* tree)
  : Base(tree)
{
  m_CurrentFile = -1;
  m_DSID = -1;
  m_Nevent = 0.;
  m_Label  = "";
  m_XSEC = 0.;
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
  m_XSEC = m_IDtoXSEC[m_Label];
  return;
}

template <class Base>
void AnalysisBase<Base>::AddNevent(double nevt){
  m_Nevent = nevt;
  return;
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

template <class Base>
void AnalysisBase<Base>::MomTensorCalc(vector<TLorentzVector>& input, vector<double>& eigenvalues, double power, bool threeD){

  eigenvalues.clear();
  
  int N = input.size();

  if(threeD){
    if(N <= 0){
      for(int i = 0; i < 3; i++) eigenvalues.push_back(0.);
      return;
    }
    if(N == 1){
      eigenvalues.push_back(1.);
      for(int i = 0; i < 2; i++) eigenvalues.push_back(0.);
      return;
    }
    
    TMatrixDSym momTensor(3);
    momTensor.Zero();

    double norm = 0.;
    double P = 0.;
    double pnorm = 0.;
    for(int i = 0; i < N; i++){
      P = input[i].P();
      if( P > 0. ){
	norm += pow(P, power);
	pnorm = pow(P, power - 2.);
	momTensor(0,0) += pnorm*input[i].Px()*input[i].Px();
	momTensor(0,1) += pnorm*input[i].Px()*input[i].Py();
	momTensor(0,2) += pnorm*input[i].Px()*input[i].Pz();
	momTensor(1,0) += pnorm*input[i].Py()*input[i].Px();
	momTensor(1,1) += pnorm*input[i].Py()*input[i].Py();
	momTensor(1,2) += pnorm*input[i].Py()*input[i].Pz();
	momTensor(2,0) += pnorm*input[i].Pz()*input[i].Px();
	momTensor(2,1) += pnorm*input[i].Pz()*input[i].Py();
	momTensor(2,2) += pnorm*input[i].Pz()*input[i].Pz();
      }
    }
    if(norm > 0.){
      momTensor = (1./norm)*momTensor;
      TVectorD evalues(3);
      momTensor.EigenVectors(evalues);
      for(int i = 0; i < 3; i++) eigenvalues.push_back(evalues(i));
      return;
    } else {
      for(int i = 0; i < 3; i++) eigenvalues.push_back(0.);
      return;
    }

  } else { // transverse
    if(N <= 0){
      for(int i = 0; i < 2; i++) eigenvalues.push_back(0.);
      return;
    }
    if(N == 1){
      eigenvalues.push_back(1.);
      eigenvalues.push_back(0.);
      return;
    }

    TMatrixDSym momTensor(2);
    momTensor.Zero();

    double norm = 0.;
    double P = 0.;
    double pnorm = 0.;
    for(int i = 0; i < N; i++){
      P = input[i].Pt();
      if( P > 0. ){
	norm += pow(P, power);
	pnorm = pow(P, power - 2.);
	momTensor(0,0) += pnorm*input[i].Px()*input[i].Px();
	momTensor(0,1) += pnorm*input[i].Px()*input[i].Py();
	momTensor(1,0) += pnorm*input[i].Py()*input[i].Px();
	momTensor(1,1) += pnorm*input[i].Py()*input[i].Py();
      }
    }
    if(norm > 0.){
      momTensor = (1./norm)*momTensor;
      TVectorD evalues(2);
      momTensor.EigenVectors(evalues);
      for(int i = 0; i < 2; i++) eigenvalues.push_back(evalues(i));
      return;
    } else{
      for(int i = 0; i < 2; i++) eigenvalues.push_back(0.);
      return;
    }

  }
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
  if(m_Nevent > 0.){
    double ret = 1000.*m_XSEC*SelectedEvent_EvtWeight*SelectedEvent_EvtWtPV/m_Nevent;
    return ret;
  }
  else
    return 0.;
}

// template <>
// TVector3 AnalysisBase<ZeroLeptonBase>::GetMET(){
//   TVector3 met;
//   met.SetPtEtaPhi(NTVars_met,0.0,NTVars_metPhi);
//   return met;
// }

template <>
int AnalysisBase<InputTreeBase>::GetJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut){

  int Njet = ptAK4->size();
  for(int i = 0; i < Njet; i++){
    if((ptAK4->at(i) >= pt_cut) && (fabs(etaAK4->at(i)) < eta_cut || eta_cut < 0)){
      TLorentzVector JET;
      float mass = MAK4->at(i);
      if(std::isnan(mass))
	mass = 0;
      if(std::isinf(mass))
	mass = 0;
      if(mass < 0.)
	mass = 0.;
      JET.SetPtEtaPhiM( ptAK4->at(i), etaAK4->at(i), phiAK4->at(i), mass );
      JETs.push_back(JET);
    }
  }
  return 0.;

}

template<>
int AnalysisBase<InputTreeBase>::GetLargeRJets(vector<TLorentzVector>& JETs, double pt_cut, double eta_cut){
  
  int Njet = ptAK8->size();
  for(int i = 0; i < Njet; i++){
    if((ptAK8->at(i) >= pt_cut) && (fabs(etaAK8->at(i)) < eta_cut || eta_cut < 0)){
      TLorentzVector JET;
      float mass = MAK8->at(i);
      if(std::isnan(mass))
	mass = 0;
      if(std::isinf(mass))
	mass = 0;
      if(mass < 0.)
	mass = 0.;
      JET.SetPtEtaPhiM( ptAK8->at(i), etaAK8->at(i), phiAK8->at(i), mass );
      JETs.push_back(JET);
    }
  }
  return 0.;

}

template class AnalysisBase<InputTreeBase>;

