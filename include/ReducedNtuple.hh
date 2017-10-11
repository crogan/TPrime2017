#ifndef ReducedNtuple_h
#define ReducedNtuple_h

#include "NtupleBase.hh"
#include "InputTreeBase.hh"
#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class ReducedNtuple : public NtupleBase<InputTreeBase> {

public:
  ReducedNtuple(TTree* tree = 0);
  virtual ~ReducedNtuple();

private:
  void InitOutputTree();
  void FillOutputTree();

  float m_weight;
  int   m_NPV;
  int   m_NPU; 

  bool  m_isA;
  bool  m_isB;
  bool  m_isC;
  bool  m_isD;

  // AK8 candidate 4-vectors
  float m_pT_top;
  float m_eta_top;
  float m_phi_top;
  float m_mass_top;
  float m_pT_higgs;
  float m_eta_higgs;
  float m_phi_higgs;
  float m_mass_higgs;

  float m_tau1_top;
  float m_tau2_top;
  float m_tau3_top;
  float m_tau1_higgs;
  float m_tau2_higgs;
  float m_tau3_higgs;

  // subjet 4-vectors ("0" is leading CSV score from each)
  float m_pT_top_sj0;
  float m_eta_top_sj0;
  float m_phi_top_sj0;
  float m_mass_top_sj0;
  float m_pT_top_sj1;
  float m_eta_top_sj1;
  float m_phi_top_sj1;
  float m_mass_top_sj1;
  float m_pT_higgs_sj0;
  float m_eta_higgs_sj0;
  float m_phi_higgs_sj0;
  float m_mass_higgs_sj0;
  float m_pT_higgs_sj1;
  float m_eta_higgs_sj1;
  float m_phi_higgs_sj1;
  float m_mass_higgs_sj1;

  // extra-jet 4-vectors
  vector<float> m_pT_extrajet;
  vector<float> m_eta_extrajet;
  vector<float> m_phi_extrajet;
  vector<float> m_mass_extrajet;
  vector<float> m_CSV_extrajet;
 
  float m_M_extra;
  int m_N_extra;
  float m_pT_q;
  float m_eta_q;
  float m_phi_q;
  float m_mass_q;

  float m_EtaMax;

  // pre-calc variables
  float m_M_Tp;
  float m_pT_Tp;

  float m_cosTp; // wrt T
  float m_cosH;
  float m_cosT;
  float m_cosTq;
  float m_dphiTH;
  float m_dphiTpH;
  float m_dphiTpT;

  float m_T;
  float m_Tm;
  float m_TT;
  float m_T_CM;
  float m_Tm_CM;
  float m_TT_CM;

  // leptons
  vector<float> m_pT_ele_clean;
  vector<float> m_eta_ele_clean;
  vector<float> m_phi_ele_clean;
  vector<float> m_E_ele_clean;

  vector<float> m_pT_mu_clean;
  vector<float> m_eta_mu_clean;
  vector<float> m_phi_mu_clean;
  vector<float> m_E_mu_clean;

  // RestFrames stuff
  LabRecoFrame*       LAB;
  DecayRecoFrame*     Tp;
  DecayRecoFrame*     T;
  DecayRecoFrame*     H;
  VisibleRecoFrame*   T0;
  VisibleRecoFrame*   T1;
  VisibleRecoFrame*   H0;
  VisibleRecoFrame*   H1;

};

#endif
