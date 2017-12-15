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

   if(!m_Base->isD) return false;

  TLorentzVector H,T;
  H.SetPtEtaPhiM( m_Base->pT_higgs, m_Base->eta_higgs, m_Base->phi_higgs, m_Base->mass_higgs );
  T.SetPtEtaPhiM( m_Base->pT_top, m_Base->eta_top, m_Base->phi_top, m_Base->mass_top );
  int Nj = m_Base->pT_extrajet->size();
  int Nextra = 0;
  int Nbtag = 0;
  vector<TLorentzVector> jets;
  double MaxEta = 0;
  TLorentzVector bjet;
  double bjetCSV = 0.;

  if(H.Pt() < 300) return false;
  if(T.Pt() < 400) return false;

  bool H_annul = false;
  for(int j = 0; j < Nj; j++){
    TLorentzVector jet;
    jet.SetPtEtaPhiM(m_Base->pT_extrajet->at(j),
		     m_Base->eta_extrajet->at(j),
		     m_Base->phi_extrajet->at(j),
		     m_Base->mass_extrajet->at(j));
    if(jet.DeltaR(H) > 0.55 && jet.DeltaR(H) < 0.9) return false;
     
    if(jet.DeltaR(T) < 1.2 || jet.DeltaR(H) < 1.2) continue;
    
    Nextra++;
    jets.push_back(jet);
    if(fabs(jet.Eta()) > MaxEta)
      MaxEta = fabs(jet.Eta());
    if(m_Base->CSV_extrajet->at(j) > bjetCSV){
      bjetCSV = m_Base->CSV_extrajet->at(j);
      bjet = jet;
    }
       
  }

  if(Nextra < 2) return false;
  if(MaxEta < 2.4) return false;
   
  if(H.Pt() + T.Pt() + jets[0].Pt() + jets[1].Pt() < 900.) return false;

  return true;
}

void TPrimeOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();

  // mass window center
  m_CutMin.push_back(850.);
  m_CutMax.push_back(2050.);
  m_CutN.push_back(24);
  m_CutVal.push_back(0.);

  // pT asymmetry cut
  m_CutMin.push_back(0.4);
  m_CutMax.push_back(0.);
  m_CutN.push_back(80);
  m_CutVal.push_back(0.);

  // tau32 top
  // m_CutMin.push_back(2.);
  // m_CutMax.push_back(4.);
  // m_CutN.push_back(2);
  // m_CutVal.push_back(0.);

  // // Nextra
  // m_CutMin.push_back(2.);
  // m_CutMax.push_back(6.);
  // m_CutN.push_back(2);
  // m_CutVal.push_back(0.);
  
  // // Nbtag
  // m_CutMin.push_back(0.);
  // m_CutMax.push_back(2.);
  // m_CutN.push_back(2);
  // m_CutVal.push_back(0.);

  // H isolation veto
  // m_CutMin.push_back(0.85);
  // m_CutMax.push_back(0.4);
  // m_CutN.push_back(18);
  // m_CutVal.push_back(0.);

  // dR for extra
  // m_CutMin.push_back(1.3);
  // m_CutMax.push_back(0.85);
  // m_CutN.push_back(9);
  // m_CutVal.push_back(0.);
  
  // Max Eta
  // m_CutMin.push_back(3.5);
  // m_CutMax.push_back(4.5);
  // m_CutN.push_back(1);
  // m_CutVal.push_back(0.);
  
  // Higgs tau32
  // m_CutMin.push_back(0.2);
  // m_CutMax.push_back(0.9);
  // m_CutN.push_back(28);
  // m_CutVal.push_back(0.);

  // Higgs pT
  // m_CutMin.push_back(300.);
  // m_CutMax.push_back(1200.);
  // m_CutN.push_back(18);
  // m_CutVal.push_back(0.);

  // top pT
  // m_CutMin.push_back(300.);
  // m_CutMax.push_back(1000.);
  // m_CutN.push_back(14);
  // m_CutVal.push_back(0.);

  // Higgs pT ratio
  // m_CutMin.push_back(0.1);
  // m_CutMax.push_back(0.4);
  // m_CutN.push_back(12);
  // m_CutVal.push_back(0.);

  // top pT ratio
  // m_CutMin.push_back(0.1);
  // m_CutMax.push_back(0.4);
  // m_CutN.push_back(12);
  // m_CutVal.push_back(0.);

  // eta_q
  // m_CutMin.push_back(1.);
  // m_CutMax.push_back(3.2);
  // m_CutN.push_back(11);
  // m_CutVal.push_back(0.);

  // cosTp min
  // m_CutMin.push_back(-1.);
  // m_CutMax.push_back(-.2);
  // m_CutN.push_back(40.);
  // m_CutVal.push_back(0.);

  // // cosTp max
  m_CutMin.push_back(1.);
  m_CutMax.push_back(0.2);
  m_CutN.push_back(40.);
  m_CutVal.push_back(0.);

  // cosTq
  // m_CutMin.push_back(1.);
  // m_CutMax.push_back(0.0);
  // m_CutN.push_back(10);
  // m_CutVal.push_back(0.);
  
  m_N_Cut = m_CutN.size();
}

int TPrimeOptimization::EvaluateCuts(){
  int icut = 0;

  // if(m_Base->M_Tp < m_CutVal[icut]*(1.-m_CutVal[icut+1]) ||
  //    m_Base->M_Tp > m_CutVal[icut]*(1.+m_CutVal[icut+1]))
  //   return icut;
  // icut++;
  // icut++;

  double MT = m_Base->M_Tp - m_Base->mass_top - m_Base->mass_higgs + 300.;
  
  if(MT < m_CutVal[icut]*(1.-0.1) ||
     MT > m_CutVal[icut]*(1.+0.15))
    return icut;
  icut++;

  // tau32 top
  // double tau32 = m_Base->tau3_top/m_Base->tau2_top;
  // if(m_CutVal[icut] == 0. && tau32 > 0.81)
  //   return icut;
  // if(m_CutVal[icut] == 1. && tau32 > 0.67)
  //   return icut;
  // if(m_CutVal[icut] == 2. && tau32 > 0.57)
  //   return icut;
  // if(m_CutVal[icut] == 3. && tau32 > 0.5)
  //   return icut;
  // icut++;

  TLorentzVector H,T;
  H.SetPtEtaPhiM( m_Base->pT_higgs, m_Base->eta_higgs, m_Base->phi_higgs, m_Base->mass_higgs );
  T.SetPtEtaPhiM( m_Base->pT_top, m_Base->eta_top, m_Base->phi_top, m_Base->mass_top );

  TLorentzVector Tp = H+T;


  if((T.Pt()-H.Pt())/MT > m_CutVal[icut])
    return icut;
  icut++;

  TVector3 boost = Tp.BoostVector();
  T.Boost(-boost);
  double mycos = T.Vect().Unit().Dot(-boost.Unit());

  // if(H.Pt() < m_CutVal[icut])
  //   return icut;
  // icut++;

  if(fabs(mycos) > m_CutVal[icut])
    return icut;
  icut++;

  // if(mycos > m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(Nbtag == 0)
  //   return icut;
   
  // if(Nextra < m_CutVal[icut])
  //   return icut;
  // icut++;

  // double dRapid = 0;
  // double dbEta = 0;
  // for(int i = 0; i < Nextra; i++){
  //   if(fabs(jets[i].Eta() - bjet.Eta()) > dbEta){
  //     dbEta = fabs(jets[i].Eta() - bjet.Eta());
  //   }
  //   for(int j = i+1; j < Nextra; j++){
  //     double dRap = fabs(jets[i].Eta()-jets[j].Eta());
  //     if(dRap > dRapid) dRapid = dRap;
  //   }
  // }

  // if(dRapid < m_CutVal[icut])
  //   return icut;
  // icut++;
   
  // if(m_Base->tau3_higgs/m_Base->tau2_higgs < m_CutVal[icut])
  //   return icut;
  // icut++;
  
  // if(m_Base->M_Tp < m_CutVal[icut]*(1.))
  //   return icut;
  // icut++;

  // if(m_Base->pT_higgs < m_CutVal[icut])
  //   return icut;
  // icut++;
  
  // if(m_Base->pT_top < m_CutVal[icut])
  //   return icut;
  // icut++;

  // double RpTtop = m_Base->pT_top / (m_Base->pT_top+m_Base->M_Tp);
  // double RpThiggs = m_Base->pT_higgs / (m_Base->pT_higgs+m_Base->M_Tp);
  
  // if(RpThiggs < m_CutVal[icut])
  //   return icut;
  // icut++;
  
  // if(RpTtop < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(fabs(m_Base->eta_q) < m_CutVal[icut])
  //   return icut;
  // icut++;

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

  // double v1 = (m_Base->cosTp-m_Base->cosTq)/2.;
  // double v2 = (m_Base->cosTp+m_Base->cosTq)/2.;

  // if(fabs(m_Base->cosTp) > m_CutVal[icut])
  //   return icut;
  // icut++;
  
  // if(fabs(m_Base->cosTq) > m_CutVal[icut])
  //   return icut;
  // icut++;
      
  return -1;
}
