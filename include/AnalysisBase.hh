#ifndef AnalysisBase_h
#define AnalysisBase_h

#include <iostream>

#include <TTree.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TH1D.h>

using namespace std;

template <class Base>
class AnalysisBase : public Base {

public:
  AnalysisBase(TTree* tree = 0);
  virtual ~AnalysisBase();

  virtual Int_t GetEntry(Long64_t entry);

  virtual TVector3 GetMET();
  virtual int GetJets(vector<TLorentzVector>& JETs, double pt_cut = -1, double eta_cut = -1);
  virtual int GetJetsBtag(vector<pair<TLorentzVector,bool> >& JETs, double pt_cut = -1, double eta_cut = -1){ return 0; }
  virtual int GetLargeRJets(vector<TLorentzVector>& JETs, double pt_cut = -1, double eta_cut = -1);
  double DeltaPhiMin(const vector<TLorentzVector>& JETs, const TVector3& MET, int N = -1);
  double DeltaPhiMin(const vector<pair<TLorentzVector, bool> >& JETs, const TVector3& MET, int N = -1);

protected:
  virtual double GetEventWeight();


private:
  int m_CurrentFile;
  int m_DSID;
  map<int,double> m_IDtoNEVT;
  map<int,double> m_IDtoXSEC;

  void NewFile();
  void InitXSECmap();
};

#endif









