#include "TLorentzVector.h"
#include "TVector3.h"

#include "TPrimeOptimization.hh"

TPrimeOptimization::TPrimeOptimization()
  : OptimizationBase<ReducedBase>() {}

TPrimeOptimization::~TPrimeOptimization() {}

double TPrimeOptimization::GetEventWeight(){
  if(m_Base)
    return m_Base->weight;
  else
    return 0.;
}

bool TPrimeOptimization::PassBaseline(){

  if(m_Base->N_extra < 1)
    return false;

  return true;
}

void TPrimeOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();

  // mass window center
  m_CutMin.push_back(1000.);
  m_CutMax.push_back(2000.);
  m_CutN.push_back(10);
  m_CutVal.push_back(0.);

  // mass window size
  // m_CutMin.push_back(0.15);
  // m_CutMax.push_back(0.01);
  // m_CutN.push_back(1);
  // m_CutVal.push_back(0.);

  // Higgs pT
  // m_CutMin.push_back(300.);
  // m_CutMax.push_back(1000.);
  // m_CutN.push_back(14);
  // m_CutVal.push_back(0.);

  // top pT
  // m_CutMin.push_back(300.);
  // m_CutMax.push_back(1000.);
  // m_CutN.push_back(14);
  // m_CutVal.push_back(0.);

  // Higgs pT ratio
  m_CutMin.push_back(0.1);
  m_CutMax.push_back(0.4);
  m_CutN.push_back(12);
  m_CutVal.push_back(0.);

  // top pT ratio
  m_CutMin.push_back(0.1);
  m_CutMax.push_back(0.4);
  m_CutN.push_back(12);
  m_CutVal.push_back(0.);

  // // Nextra
  // m_CutMin.push_back(1.);
  // m_CutMax.push_back(4.);
  // m_CutN.push_back(1);
  // m_CutVal.push_back(0.);

  // eta_q
  m_CutMin.push_back(1.);
  m_CutMax.push_back(3.2);
  m_CutN.push_back(11);
  m_CutVal.push_back(0.);

  // cosTp
  m_CutMin.push_back(1.);
  m_CutMax.push_back(0.0);
  m_CutN.push_back(10);
  m_CutVal.push_back(0.);

  // cosTq
  m_CutMin.push_back(1.);
  m_CutMax.push_back(0.0);
  m_CutN.push_back(10);
  m_CutVal.push_back(0.);
  

  m_N_Cut = m_CutN.size();
}

int TPrimeOptimization::EvaluateCuts(){
  int icut = 0;

  // if(m_Base->M_Tp < m_CutVal[icut]*(1.-m_CutVal[icut+1]) ||
  //    m_Base->M_Tp > m_CutVal[icut]*(1.+m_CutVal[icut+1]))
  //   return icut;
  // icut++;
  // icut++;

  // if(m_Base->M_Tp < m_CutVal[icut]*(1.-0.10) ||
  //    m_Base->M_Tp > m_CutVal[icut]*(1.+0.2))
  //   return icut;
  // icut++;

  if(m_Base->M_Tp < m_CutVal[icut]*(1.))
    return icut;
  icut++;

  // if(m_Base->pT_higgs < m_CutVal[icut])
  //   return icut;
  // icut++;
  
  // if(m_Base->pT_top < m_CutVal[icut])
  //   return icut;
  // icut++;

  double RpTtop = m_Base->pT_top / (m_Base->pT_top+m_Base->M_Tp);
  double RpThiggs = m_Base->pT_higgs / (m_Base->pT_higgs+m_Base->M_Tp);
  
  if(RpThiggs < m_CutVal[icut])
    return icut;
  icut++;
  
  if(RpTtop < m_CutVal[icut])
    return icut;
  icut++;

  // if(m_Base->N_extra < m_CutVal[icut])
  //   return icut;
  // icut++;

  if(fabs(m_Base->eta_q) < m_CutVal[icut])
    return icut;
  icut++;

  // TLorentzVector H,T;
  // H.SetPtEtaPhiM( m_Base->pT_higgs, m_Base->eta_higgs, m_Base->phi_higgs, m_Base->mass_higgs );
  // T.SetPtEtaPhiM( m_Base->pT_top, m_Base->eta_top, m_Base->phi_top, m_Base->mass_top );
  // TLorentzVector Tp = H+T;
  // TLorentzVector q;
  // q.SetPtEtaPhiM( m_Base->pT_q, m_Base->eta_q, m_Base->phi_q, m_Base->mass_q );
  
  // TVector3 boost = Tp.BoostVector();
  // T.Boost(-boost);
  // double mycos = T.Vect().Unit().Dot(-boost.Unit());
  
  // double v1 = (m_Base->cosTp-m_Base->cosTq)/(2. - fabs(m_Base->cosTp+m_Base->cosTq));
  // double v2 = (m_Base->cosTp+m_Base->cosTq)/(2. - fabs(m_Base->cosTp-m_Base->cosTq));

  double v1 = (m_Base->cosTp-m_Base->cosTq)/2.;
  double v2 = (m_Base->cosTp+m_Base->cosTq)/2.;

  if(fabs(m_Base->cosTp) > m_CutVal[icut])
    return icut;
  icut++;
  
  if(fabs(m_Base->cosTq) > m_CutVal[icut])
    return icut;
  icut++;
      
  return -1;
}
