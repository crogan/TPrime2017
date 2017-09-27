#ifndef ReducedNtuple_h
#define ReducedNtuple_h

#include "NtupleBase.hh"
#include "ZeroLeptonBase.hh"
#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class ReducedNtuple : public NtupleBase<ZeroLeptonBase> {

public:
  ReducedNtuple(TTree* tree = 0);
  virtual ~ReducedNtuple();

private:
  void InitOutputTree();
  void FillOutputTree();

  vector<float>   m_systWeights;
  vector<float>   m_btagSystWeights;
  float           m_WZweight;
  ULong64_t       m_PRWHash;

  Float_t m_eventWeight;
  Float_t m_pileupWeight;
  Float_t m_pileupWeightUp;
  Float_t m_pileupWeightDown;
  Float_t m_genWeight;
  Float_t m_normWeight;
  Float_t m_normWeightUp;
  Float_t m_normWeightDown;

  float m_metTST;
  float m_metTSTPhi;

  bool m_DATA;
  bool m_CRZ;
  bool m_CRWT;
  bool m_CRY;

  // Data
  UInt_t m_RunNumber;
  UInt_t m_EventNumber;
  UInt_t m_LumiBlockNumber;

  // CRWT
  float m_MTW;
  float m_lep1Pt;
  int m_lep1sign;
  UInt_t m_lep1Triggered;
  Int_t m_lep1Signal;

 
  // CRZ
  float m_leptonWeight;

  // extra CRZ
  Float_t         m_lep2Pt;
  Float_t         m_lep1Eta;
  Float_t         m_lep2Eta;
  Float_t         m_lep1Phi;
  Float_t         m_lep2Phi;
  Int_t           m_lep2sign;
  Float_t         m_mll;
  Float_t         m_Zpt;
  Float_t         m_fakemet;
  Float_t         m_fakemetPhi;
  Float_t         m_lep1Iso;
  Float_t         m_lep2Iso;
  Float_t         m_lep1DRjet;
  Float_t         m_lep2DRjet;
  Float_t         m_lep1jetJVF;
  Float_t         m_lep2jetJVF;

  // CRY
  bool m_phSignal;
  float m_phPt;
  int m_phTruthOrigin;
  float m_phTopoetcone40;
  float m_phPtcone20;
  int m_phTight;

  // common variables for output tree
  float m_weight;
  UInt_t m_veto;
  UInt_t m_cleaning;
  UInt_t m_timing;

  int m_nBJet;
  int m_nCJet;
  float m_bTagWeight;
  float m_jet1_eta;
  float m_jet1_chf;
  float m_jet1_FracSamplingMax;


  // QCD Type A
  float m_Rsib;
  float m_deltaQCD;

  float m_pTCM;
  float m_pZCM;

   // trigger related
  float m_PP_VisShape;
  float m_MDR;

  // compressed 
  float m_PTISR;
  float m_RISR;
  float m_cosS;
  float m_dphiCMI;
  float m_dphiISRI;
  float m_MS;
  int m_NV;
  int m_NISR;
  float m_MISR;
  float m_MV;
  float m_pTjV1;
  float m_pTjV2;
  float m_pTjV3;
  float m_pTjV4;
  float m_etajV1;
  float m_etajV2;
  float m_etajV3;
  float m_etajV4;
  float m_RPT_PTISR; // QCD type B

  // angles
  float m_cosPP;
  float m_dphiVP;
  float m_dphiPPV;
  float m_cosP;
  float m_sangle;
  float m_dangle;
  float m_dphiPa;
  float m_dphiPb;
  float m_ddphiP;
  float m_sdphiP;
  
  float m_H2PP;

  // sqark-direct specific
  float m_H3PP;
  float m_H4PP;
  float m_HT3PP;
  float m_HT4PP;
  float m_R_H2PP_H3PP;
  float m_R_pTj2_HT3PP;
  float m_RPZ_HT3PP;
  float m_RPT_HT3PP;

  // gluino-direct specific
  float m_H5PP;
  float m_H6PP;
  float m_HT5PP;
  float m_HT6PP;
  float m_R_H2PP_H5PP;
  float m_R_HT5PP_H5PP;
  float m_minR_pTj2i_HT3PPi;
  float m_maxR_H1PPi_H2PPi;
  float m_RPZ_HT5PP;
  float m_RPT_HT5PP;

  // GG onestep CC specific (old)
  float m_H9PP;
  float m_H10PP;
  float m_HT9PP;
  float m_HT10PP;
  float m_R_H2PP_H9PP;
  float m_R_HT9PP_H9PP;
  float m_RPZ_HT9PP;
  float m_RPT_HT9PP;

  // 3-3
  float m_H7PP_3;
  float m_H8PP_3;
  float m_HT7PP_3;
  float m_HT8PP_3;
  float m_R_H2PP_H7PP_3;
  float m_R_HT7PP_H7PP_3;
  float m_RPZ_HT7PP_3;
  float m_RPT_HT7PP_3;

  // P frames
  float m_H2Pa;
  float m_H2Pb;
  float m_H3Pa;
  float m_H3Pb;
  float m_H4Pa;
  float m_H4Pb;
  float m_H5Pa;
  float m_H5Pb;
  float m_dH2o3P;

  // C frames
  float m_H2Ca;
  float m_H2Cb;
  float m_H3Ca;
  float m_H3Cb;

  float m_dphiPV1a;
  float m_dphiPV1b;
  float m_cosV1a;
  float m_cosV1b;
  float m_dphiCV2a;
  float m_dphiCV2b;
  float m_cosV2a;
  float m_cosV2b;

  // standard 0 lep
  float m_MET;
  float m_METphi;
  float m_Meff;
  float m_Aplan;
  float m_dphi;
  float m_dphiR;

  float m_dphiMin1;
  float m_dphiMin2;
  float m_dphiMin3;
  float m_dphiMinAll;

  float m_NJet;
  float m_NJa;
  float m_NJb;
  float m_NJ1a;
  float m_NJ1b;
  float m_NJ2a;
  float m_NJ2b;

  float m_NJ1a_3;
  float m_NJ1b_3;
  float m_NJ2a_3;
  float m_NJ2b_3;
  float m_NJ3a_3;
  float m_NJ3b_3;

  float m_MJet;
  float m_MJa;
  float m_MJb;
  float m_MJ1a;
  float m_MJ1b;
  float m_MJ2a;
  float m_MJ2b;

  float m_MJ1a_3;
  float m_MJ1b_3;
  float m_MJ2a_3;
  float m_MJ2b_3;
  float m_MJ3a_3;
  float m_MJ3b_3;

  float m_pT_jet1;
  float m_pT_jet2;
  float m_pT_jet3;
  float m_pT_jet4;
  float m_pT_jet5;
  float m_pT_jet6;

  float m_eta_jet1;
  float m_eta_jet2;
  float m_eta_jet3;
  float m_eta_jet4;
  float m_eta_jet5;
  float m_eta_jet6;
 
  float m_pTPP_jet1;
  float m_pTPP_jet2;

  float m_pT_jet1a;
  float m_pT_jet2a;
  float m_pT_jet1b;
  float m_pT_jet2b;

  float m_pTPP_jet1a;
  float m_pTPP_jet2a;
  float m_pTPP_jet3a;
  float m_pTPP_jet1b;
  float m_pTPP_jet2b;
  float m_pTPP_jet3b;

  float m_eta_jet1a;
  float m_eta_jet2a;
  float m_eta_jet3a;
  float m_eta_jet1b;
  float m_eta_jet2b;
  float m_eta_jet3b;

  float m_pPP_jet1a;
  float m_pPP_jet2a;
  float m_pPP_jet3a;
  float m_pPP_jet1b;
  float m_pPP_jet2b;
  float m_pPP_jet3b;

  float m_pTPP_Va;
  float m_pTPP_V1a;
  float m_pTPP_V2a;
  float m_pTPP_Vb;
  float m_pTPP_V1b;
  float m_pTPP_V2b;
  float m_pTPP_Ia;
  float m_pTPP_Ib;

  float m_pTPP_V1a_3;
  float m_pTPP_V2a_3;
  float m_pTPP_V3a_3;
  float m_pTPP_V1b_3;
  float m_pTPP_V2b_3;
  float m_pTPP_V3b_3;

  float m_pPP_Va;
  float m_pPP_V1a;
  float m_pPP_V2a;
  float m_pPP_Vb;
  float m_pPP_V1b;
  float m_pPP_V2b;
  float m_pPP_Ia;
  float m_pPP_Ib;

  float m_pPP_V1a_3;
  float m_pPP_V2a_3;
  float m_pPP_V3a_3;
  float m_pPP_V1b_3;
  float m_pPP_V2b_3;
  float m_pPP_V3b_3;
  
  // RestFrames stuff
  LabRecoFrame*       LAB;
  DecayRecoFrame*     PP;
  DecayRecoFrame*     Pa;
  DecayRecoFrame*     Pb;
  DecayRecoFrame*     Ca;
  DecayRecoFrame*     Cb;
  SelfAssemblingRecoFrame* SAV1a;
  SelfAssemblingRecoFrame* SAV1b;
  SelfAssemblingRecoFrame* SAV2a;
  SelfAssemblingRecoFrame* SAV2b;
  VisibleRecoFrame*   V1a;
  VisibleRecoFrame*   V1b;
  VisibleRecoFrame*   V2a;
  VisibleRecoFrame*   V2b;
  InvisibleRecoFrame* Ia;
  InvisibleRecoFrame* Ib;

  InvisibleGroup*    INV;
  CombinatoricGroup* VIS;

  SetMassInvJigsaw*     InvMassJigsaw;
  SetRapidityInvJigsaw* InvRapidityJigsaw;
  ContraBoostInvJigsaw* InvCBJigsaw;
  MinMassesCombJigsaw*  CombPPJigsaw;
  MinMassesCombJigsaw*  CombPaJigsaw;
  MinMassesCombJigsaw*  CombPbJigsaw;
  
  LabRecoFrame*            LAB_bkg;
  SelfAssemblingRecoFrame* S_bkg;
  VisibleRecoFrame*        V_bkg;
  InvisibleRecoFrame*      I_bkg;

  InvisibleGroup*    INV_bkg;
  CombinatoricGroup* VIS_bkg;

  SetMassInvJigsaw*     InvMass_bkg;
  SetRapidityInvJigsaw* InvRapidity_bkg;

  LabRecoFrame*       LAB_ISR;
  DecayRecoFrame*     CM_ISR;
  DecayRecoFrame*     S_ISR;
  VisibleRecoFrame*   ISR_ISR;
  VisibleRecoFrame*   V_ISR;
  InvisibleRecoFrame* I_ISR;

  InvisibleGroup* INV_ISR;
  CombinatoricGroup* VIS_ISR;

  SetMassInvJigsaw* InvMass_ISR;
  MinMassesCombJigsaw* SplitVis_ISR;

  // 3-3 tree
  LabRecoFrame*       LAB_3;
  DecayRecoFrame*     PP_3;
  DecayRecoFrame*     Pa_3;
  DecayRecoFrame*     Pb_3;
  VisibleRecoFrame*   V1a_3;
  VisibleRecoFrame*   V1b_3;
  VisibleRecoFrame*   V2a_3;
  VisibleRecoFrame*   V2b_3;
  VisibleRecoFrame*   V3a_3;
  VisibleRecoFrame*   V3b_3;
  InvisibleRecoFrame* Ia_3;
  InvisibleRecoFrame* Ib_3;

  InvisibleGroup*    INV_3;
  CombinatoricGroup* VIS_3;

  SetMassInvJigsaw*     InvMassJigsaw_3;
  SetRapidityInvJigsaw* InvRapidityJigsaw_3;
  ContraBoostInvJigsaw* InvCBJigsaw_3;
  MinMassesCombJigsaw*  CombPPJigsaw_3;
  MinMassesSqCombJigsaw*  CombPaJigsaw_3;
  MinMassesSqCombJigsaw*  CombPbJigsaw_3;

};

#endif
