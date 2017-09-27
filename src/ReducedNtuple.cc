#include "ReducedNtuple.hh"

using namespace RestFrames;



ReducedNtuple::ReducedNtuple(TTree* tree)
  : NtupleBase<InputTreeBase>(tree)
{
  
}

ReducedNtuple::~ReducedNtuple() {
  
}

void ReducedNtuple::InitOutputTree(){
  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  if(name.find("_CRWT") != string::npos ||
     name.find("_VRWT") != string::npos)
    m_CRWT = true;
  else 
    m_CRWT = false;

  if( name.find("_CRZ") != string::npos)
    m_CRZ = true;
  else 
    m_CRZ = false;

  if( name.find("_CRY") != string::npos)
    m_CRY = true;
  else 
    m_CRY = false;

  if( name.find("Data") != string::npos)
    m_DATA = true;
  else 
    m_DATA = false;

  m_Tree = (TTree*) new TTree(name.c_str(), name.c_str());

  m_Tree->Branch("systWeights", &m_systWeights);
  m_Tree->Branch("btagSystWeights", &m_btagSystWeights);
  m_Tree->Branch("WZweight", &m_WZweight);
  m_Tree->Branch("PRWHash", &m_PRWHash);

  m_Tree->Branch("eventWeight", &m_eventWeight);
  m_Tree->Branch("pileupWeight", &m_pileupWeight);
  m_Tree->Branch("pileupWeightUp", &m_pileupWeightUp);
  m_Tree->Branch("pileupWeightDown", &m_pileupWeightDown);
  m_Tree->Branch("genWeight", &m_genWeight);
  m_Tree->Branch("normWeight", &m_normWeight);
  m_Tree->Branch("normWeightUp", &m_normWeightUp);
  m_Tree->Branch("normWeightDown", &m_normWeightDown);

  m_Tree->Branch("metTST", &m_metTST);
  m_Tree->Branch("metTSTPhi", &m_metTSTPhi);

  m_Tree->Branch("RunNumber", &m_RunNumber);
  m_Tree->Branch("EventNumber", &m_EventNumber);

  // special variables for DATA
  if(m_DATA){
    m_Tree->Branch("LumiBlockNumber", &m_LumiBlockNumber);
  }

  // special variables for control regions
  if(m_CRWT){
    m_Tree->Branch("MTW", &m_MTW);
    m_Tree->Branch("lep1Pt", &m_lep1Pt);
    m_Tree->Branch("lep1sign", &m_lep1sign);
    m_Tree->Branch("lep1Triggered", &m_lep1Triggered);
    m_Tree->Branch("lep1Signal", &m_lep1Signal);
  }

  if(m_CRZ){
    m_Tree->Branch("lep1Pt", &m_lep1Pt);
    m_Tree->Branch("lep2Pt", &m_lep2Pt);
    m_Tree->Branch("lep1Eta", &m_lep1Eta);
    m_Tree->Branch("lep2Eta", &m_lep2Eta);
    m_Tree->Branch("lep1Phi", &m_lep1Phi);
    m_Tree->Branch("lep2Phi", &m_lep2Phi);
    m_Tree->Branch("lep1sign", &m_lep1sign);
    m_Tree->Branch("lep2sign", &m_lep2sign);
    m_Tree->Branch("mll", &m_mll);
    m_Tree->Branch("Zpt", &m_Zpt);
    m_Tree->Branch("fakemet", &m_fakemet);
    m_Tree->Branch("fakemetPhi", &m_fakemetPhi);
    m_Tree->Branch("lep1Iso", &m_lep1Iso);
    m_Tree->Branch("lep2Iso", &m_lep2Iso);
    m_Tree->Branch("lep1DRjet", &m_lep1DRjet);
    m_Tree->Branch("lep2DRjet", &m_lep2DRjet);
    m_Tree->Branch("lep1jetJVF", &m_lep1jetJVF);
    m_Tree->Branch("lep2jetJVF", &m_lep2jetJVF);
    m_Tree->Branch("leptonWeight", &m_leptonWeight);
  }

  if(m_CRY){
    m_Tree->Branch("phSignal", &m_phSignal);
    m_Tree->Branch("phPt", &m_phPt);
    m_Tree->Branch("phTruthOrigin", &m_phTruthOrigin);
    m_Tree->Branch("phTopoetcone40", &m_phTopoetcone40);
    m_Tree->Branch("phPtcone20", &m_phPtcone20);
    m_Tree->Branch("phTight", &m_phTight);
  }
 
  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("veto", &m_veto);
  m_Tree->Branch("cleaning", &m_cleaning);
  m_Tree->Branch("timing", &m_timing);

  m_Tree->Branch("nBJet", &m_nBJet);
  m_Tree->Branch("nCJet", &m_nCJet);
  m_Tree->Branch("bTagWeight", &m_bTagWeight);
  m_Tree->Branch("m_jet1_eta", &m_jet1_eta);
  m_Tree->Branch("m_jet1_chf", &m_jet1_chf);
  m_Tree->Branch("m_jet1_FracSamplingMax", &m_jet1_FracSamplingMax);

  // QCD type A
  m_Tree->Branch("Rsib", &m_Rsib);
  m_Tree->Branch("deltaQCD", &m_deltaQCD);

  m_Tree->Branch("pTCM", &m_pTCM);
  m_Tree->Branch("pZCM", &m_pZCM);

  // trigger
  m_Tree->Branch("PP_VisShape", &m_PP_VisShape);
  m_Tree->Branch("MDR", &m_MDR);

  m_Tree->Branch("H2PP", &m_H2PP);

  // compressed 
  m_Tree->Branch("PTISR", &m_PTISR);
  m_Tree->Branch("RISR", &m_RISR);
  m_Tree->Branch("cosS", &m_cosS);
  m_Tree->Branch("dphiCMI", &m_dphiCMI);
  m_Tree->Branch("dphiISRI", &m_dphiISRI);
  m_Tree->Branch("MS", &m_MS);
  m_Tree->Branch("NV", &m_NV);
  m_Tree->Branch("NISR", &m_NISR);
  m_Tree->Branch("MISR", &m_MISR);
  m_Tree->Branch("MV", &m_MV);
  m_Tree->Branch("pTjV1", &m_pTjV1);
  m_Tree->Branch("pTjV2", &m_pTjV2);
  m_Tree->Branch("pTjV3", &m_pTjV3);
  m_Tree->Branch("pTjV4", &m_pTjV4);
  m_Tree->Branch("etajV1", &m_etajV1);
  m_Tree->Branch("etajV2", &m_etajV2);
  m_Tree->Branch("etajV3", &m_etajV3);
  m_Tree->Branch("etajV4", &m_etajV4);
  m_Tree->Branch("RPT_PTISR", &m_RPT_PTISR);

  m_Tree->Branch("cosPP", &m_cosPP);
  m_Tree->Branch("dphiVP", &m_dphiVP);
  m_Tree->Branch("dphiPPV", &m_dphiPPV);
  m_Tree->Branch("cosP", &m_cosP);
  m_Tree->Branch("sangle", &m_sangle);
  m_Tree->Branch("dangle", &m_dangle);
  m_Tree->Branch("dphiPa", &m_dphiPa);
  m_Tree->Branch("dphiPb", &m_dphiPb);
  m_Tree->Branch("ddphiP", &m_ddphiP);
  m_Tree->Branch("sdphiP", &m_sdphiP);

  // squark-direct specific
  m_Tree->Branch("H3PP", &m_H3PP);
  m_Tree->Branch("H4PP", &m_H4PP);
  m_Tree->Branch("HT3PP", &m_HT3PP);
  m_Tree->Branch("HT4PP", &m_HT4PP);
  m_Tree->Branch("R_H2PP_H3PP", &m_R_H2PP_H3PP);
  m_Tree->Branch("R_pTj2_HT3PP", &m_R_pTj2_HT3PP);
  m_Tree->Branch("RPZ_HT3PP", &m_RPZ_HT3PP);
  m_Tree->Branch("RPT_HT3PP", &m_RPT_HT3PP);

  // gluino-direct specific
  m_Tree->Branch("H5PP", &m_H5PP);
  m_Tree->Branch("H6PP", &m_H6PP);
  m_Tree->Branch("HT5PP", &m_HT5PP);
  m_Tree->Branch("HT6PP", &m_HT6PP);
  m_Tree->Branch("R_H2PP_H5PP", &m_R_H2PP_H5PP);
  m_Tree->Branch("R_HT5PP_H5PP", &m_R_HT5PP_H5PP);
  m_Tree->Branch("minR_pTj2i_HT3PPi", &m_minR_pTj2i_HT3PPi);
  m_Tree->Branch("maxR_H1PPi_H2PPi", &m_maxR_H1PPi_H2PPi);
  m_Tree->Branch("RPZ_HT5PP", &m_RPZ_HT5PP);
  m_Tree->Branch("RPT_HT5PP", &m_RPT_HT5PP);

  // GG onestep CC specific
  m_Tree->Branch("H9PP", &m_H9PP);
  m_Tree->Branch("H10PP", &m_H10PP);
  m_Tree->Branch("HT9PP", &m_HT9PP);
  m_Tree->Branch("HT10PP", &m_HT10PP);
  m_Tree->Branch("R_H2PP_H9PP", &m_R_H2PP_H9PP);
  m_Tree->Branch("R_HT9PP_H9PP", &m_R_HT9PP_H9PP);
  m_Tree->Branch("RPZ_HT9PP", &m_RPZ_HT9PP);
  m_Tree->Branch("RPT_HT9PP", &m_RPT_HT9PP);

  // P -frames 
  m_Tree->Branch("H2Pa", &m_H2Pa);
  m_Tree->Branch("H2Pb", &m_H2Pb);
  m_Tree->Branch("H3Pa", &m_H3Pa);
  m_Tree->Branch("H3Pb", &m_H3Pb);
  m_Tree->Branch("H4Pa", &m_H4Pa);
  m_Tree->Branch("H4Pb", &m_H4Pb);
  m_Tree->Branch("H5Pa", &m_H5Pa);
  m_Tree->Branch("H5Pb", &m_H5Pb);
  m_Tree->Branch("dH2o3P", &m_dH2o3P);

  // C -frames
  m_Tree->Branch("H2Ca", &m_H2Ca);
  m_Tree->Branch("H2Cb", &m_H2Cb);
  m_Tree->Branch("H3Ca", &m_H3Ca);
  m_Tree->Branch("H3Cb", &m_H3Cb);

  m_Tree->Branch("dphiPV1a", &m_dphiPV1a);
  m_Tree->Branch("dphiPV1b", &m_dphiPV1b);
  m_Tree->Branch("cosV1a", &m_cosV1a);
  m_Tree->Branch("cosV1b", &m_cosV1b);
  m_Tree->Branch("dphiCV2a", &m_dphiCV2a);
  m_Tree->Branch("dphiCV2b", &m_dphiCV2b);
  m_Tree->Branch("cosV2a", &m_cosV2a);
  m_Tree->Branch("cosV2b", &m_cosV2b);

  // other
  m_Tree->Branch("MET", &m_MET);
  m_Tree->Branch("Meff", &m_Meff);
  m_Tree->Branch("Aplan", &m_Aplan);
  m_Tree->Branch("dphi", &m_dphi);
  m_Tree->Branch("dphiR", &m_dphiR);

  m_Tree->Branch("dphiMin1", &m_dphiMin1);
  m_Tree->Branch("dphiMin2", &m_dphiMin2);
  m_Tree->Branch("dphiMin3", &m_dphiMin3);
  m_Tree->Branch("dphiMinAll", &m_dphiMinAll);

  m_Tree->Branch("NJet", &m_NJet);
  m_Tree->Branch("NJa", &m_NJa);
  m_Tree->Branch("NJb", &m_NJb);
  m_Tree->Branch("NJ1a", &m_NJ1a);
  m_Tree->Branch("NJ1b", &m_NJ1b);
  m_Tree->Branch("NJ2a", &m_NJ2a);
  m_Tree->Branch("NJ2b", &m_NJ2b);

  m_Tree->Branch("pT_jet1", &m_pT_jet1);
  m_Tree->Branch("pT_jet2", &m_pT_jet2);
  m_Tree->Branch("pT_jet3", &m_pT_jet3);
  m_Tree->Branch("pT_jet4", &m_pT_jet4);
  m_Tree->Branch("pT_jet5", &m_pT_jet5);
  m_Tree->Branch("pT_jet6", &m_pT_jet6);

  m_Tree->Branch("eta_jet1", &m_eta_jet1);
  m_Tree->Branch("eta_jet2", &m_eta_jet2);
  m_Tree->Branch("eta_jet3", &m_eta_jet3);
  m_Tree->Branch("eta_jet4", &m_eta_jet4);
  m_Tree->Branch("eta_jet5", &m_eta_jet5);
  m_Tree->Branch("eta_jet6", &m_eta_jet6);

  m_Tree->Branch("pTPP_jet1", &m_pTPP_jet1);
  m_Tree->Branch("pTPP_jet2", &m_pTPP_jet2);

  m_Tree->Branch("pT_jet1a", &m_pT_jet1a);
  m_Tree->Branch("pT_jet2a", &m_pT_jet2a);
  m_Tree->Branch("pT_jet1b", &m_pT_jet1b);
  m_Tree->Branch("pT_jet2b", &m_pT_jet2b);

  m_Tree->Branch("pTPP_jet1a", &m_pTPP_jet1a);
  m_Tree->Branch("pTPP_jet2a", &m_pTPP_jet2a);
  m_Tree->Branch("pTPP_jet3a", &m_pTPP_jet3a);
  m_Tree->Branch("pTPP_jet1b", &m_pTPP_jet1b);
  m_Tree->Branch("pTPP_jet2b", &m_pTPP_jet2b);
  m_Tree->Branch("pTPP_jet3b", &m_pTPP_jet3b);

  m_Tree->Branch("pPP_jet1a", &m_pPP_jet1a);
  m_Tree->Branch("pPP_jet2a", &m_pPP_jet2a);
  m_Tree->Branch("pPP_jet3a", &m_pPP_jet3a);
  m_Tree->Branch("pPP_jet1b", &m_pPP_jet1b);
  m_Tree->Branch("pPP_jet2b", &m_pPP_jet2b);
  m_Tree->Branch("pPP_jet3b", &m_pPP_jet3b);

  m_Tree->Branch("eta_jet1a", &m_eta_jet1a);
  m_Tree->Branch("eta_jet2a", &m_eta_jet2a);
  m_Tree->Branch("eta_jet3a", &m_eta_jet3a);
  m_Tree->Branch("eta_jet1b", &m_eta_jet1b);
  m_Tree->Branch("eta_jet2b", &m_eta_jet2b);
  m_Tree->Branch("eta_jet3b", &m_eta_jet3b);

  m_Tree->Branch("pTPP_Va", &m_pTPP_Va);
  m_Tree->Branch("pTPP_V1a", &m_pTPP_V1a);
  m_Tree->Branch("pTPP_V2a", &m_pTPP_V2a);
  m_Tree->Branch("pTPP_Vb", &m_pTPP_Vb);
  m_Tree->Branch("pTPP_V1b", &m_pTPP_V1b);
  m_Tree->Branch("pTPP_V2b", &m_pTPP_V2b);
  m_Tree->Branch("pTPP_Ia", &m_pTPP_Ia);
  m_Tree->Branch("pTPP_Ib", &m_pTPP_Ib);

  m_Tree->Branch("pTPP_V1a_3", &m_pTPP_V1a_3);
  m_Tree->Branch("pTPP_V2a_3", &m_pTPP_V2a_3);
  m_Tree->Branch("pTPP_V3a_3", &m_pTPP_V3a_3);
  m_Tree->Branch("pTPP_V1b_3", &m_pTPP_V1b_3);
  m_Tree->Branch("pTPP_V2b_3", &m_pTPP_V2b_3);
  m_Tree->Branch("pTPP_V3b_3", &m_pTPP_V3b_3);

  m_Tree->Branch("pPP_Va", &m_pPP_Va);
  m_Tree->Branch("pPP_V1a", &m_pPP_V1a);
  m_Tree->Branch("pPP_V2a", &m_pPP_V2a);
  m_Tree->Branch("pPP_Vb", &m_pPP_Vb);
  m_Tree->Branch("pPP_V1b", &m_pPP_V1b);
  m_Tree->Branch("pPP_V2b", &m_pPP_V2b);
  m_Tree->Branch("pPP_Ia", &m_pPP_Ia);
  m_Tree->Branch("pPP_Ib", &m_pPP_Ib);

  m_Tree->Branch("pPP_V1a_3", &m_pPP_V1a_3);
  m_Tree->Branch("pPP_V2a_3", &m_pPP_V2a_3);
  m_Tree->Branch("pPP_V3a_3", &m_pPP_V3a_3);
  m_Tree->Branch("pPP_V1b_3", &m_pPP_V1b_3);
  m_Tree->Branch("pPP_V2b_3", &m_pPP_V2b_3);
  m_Tree->Branch("pPP_V3b_3", &m_pPP_V3b_3);

  // 3-3 tree
  m_Tree->Branch("NJ1a_3", &m_NJ1a_3);
  m_Tree->Branch("NJ1b_3", &m_NJ1b_3);
  m_Tree->Branch("NJ2a_3", &m_NJ2a_3);
  m_Tree->Branch("NJ2b_3", &m_NJ2b_3);
  m_Tree->Branch("NJ3a_3", &m_NJ3a_3);
  m_Tree->Branch("NJ3b_3", &m_NJ3b_3);

  m_Tree->Branch("H7PP_3", &m_H7PP_3);
  m_Tree->Branch("H8PP_3", &m_H8PP_3);
  m_Tree->Branch("HT7PP_3", &m_HT7PP_3);
  m_Tree->Branch("HT8PP_3", &m_HT8PP_3);
  m_Tree->Branch("R_H2PP_H7PP_3", &m_R_H2PP_H7PP_3);
  m_Tree->Branch("R_HT7PP_H7PP_3", &m_R_HT7PP_H7PP_3);
  m_Tree->Branch("RPZ_HT7PP_3", &m_RPZ_HT7PP_3);
  m_Tree->Branch("RPT_HT7PP_3", &m_RPT_HT7PP_3);

  m_Tree->Branch("MJet", &m_MJet);
  m_Tree->Branch("MJa", &m_MJa);
  m_Tree->Branch("MJb", &m_MJb);
  m_Tree->Branch("MJ1a", &m_MJ1a);
  m_Tree->Branch("MJ1b", &m_MJ1b);
  m_Tree->Branch("MJ2a", &m_MJ2a);
  m_Tree->Branch("MJ2b", &m_MJ2b);

  m_Tree->Branch("MJ1a_3", &m_MJ1a_3);
  m_Tree->Branch("MJ1b_3", &m_MJ1b_3);
  m_Tree->Branch("MJ2a_3", &m_MJ2a_3);
  m_Tree->Branch("MJ2b_3", &m_MJ2b_3);
  m_Tree->Branch("MJ3a_3", &m_MJ3a_3);
  m_Tree->Branch("MJ3b_3", &m_MJ3b_3);

}

void ReducedNtuple::FillOutputTree(){

  TVector3 ETMiss = GetMET(); 

  vector<TLorentzVector> Jets; 
  GetJets(Jets, 50., 2.8); 

  // need two jets to play
  if(Jets.size() < 2) 
    return; 

  LAB->ClearEvent();

  vector<RFKey> jetID; 
  for(int i = 0; i < int(Jets.size()); i++){
    jetID.push_back(VIS->AddLabFrameFourVector(Jets[i]));
  }
  INV->SetLabFrameThreeVector(ETMiss);
  if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  m_NJet = Jets.size();
  m_NJ1a = VIS->GetNElementsInFrame(*V1a);
  m_NJ1b = VIS->GetNElementsInFrame(*V1b);
  m_NJ2a = VIS->GetNElementsInFrame(*V2a);
  m_NJ2b = VIS->GetNElementsInFrame(*V2b);
  m_NJa = m_NJ1a+m_NJ2a;
  m_NJb = m_NJ1b+m_NJ2b;

  if(ETMiss.Mag() < 200. || m_NJet < 2)
    return;

  m_dphiMin1   = DeltaPhiMin(Jets, ETMiss, 1);
  m_dphiMin2   = DeltaPhiMin(Jets, ETMiss, 2);
  m_dphiMin3   = DeltaPhiMin(Jets, ETMiss, 3);
  m_dphiMinAll = DeltaPhiMin(Jets, ETMiss);

  // 3-3 tree
  LAB_3->ClearEvent();
  vector<RFKey> jetID_3; 
  for(int i = 0; i < int(Jets.size()); i++){
    jetID_3.push_back(VIS_3->AddLabFrameFourVector(Jets[i]));
  }
  INV_3->SetLabFrameThreeVector(ETMiss);
  if(!LAB_3->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  m_NJ1a_3 = VIS_3->GetNElementsInFrame(*V1a_3);
  m_NJ1b_3 = VIS_3->GetNElementsInFrame(*V1b_3);
  m_NJ2a_3 = VIS_3->GetNElementsInFrame(*V2a_3);
  m_NJ2b_3 = VIS_3->GetNElementsInFrame(*V2b_3);
  m_NJ3a_3 = VIS_3->GetNElementsInFrame(*V3a_3);
  m_NJ3b_3 = VIS_3->GetNElementsInFrame(*V3b_3);

  // background tree
  LAB_bkg->ClearEvent();
  double HT = 0.;
  vector<RFKey> jetID_bkg; 
  for(int i = 0; i < int(Jets.size()); i++){
    TLorentzVector jet = Jets[i];
    jet.SetPtEtaPhiM(Jets[i].Pt(),0.0,Jets[i].Phi(),Jets[i].M());
    jetID_bkg.push_back(VIS_bkg->AddLabFrameFourVector(jet));
    HT += Jets[i].Pt();
  }
  INV_bkg->SetLabFrameThreeVector(ETMiss);
  if(!LAB_bkg->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  TLorentzVector Psib = I_bkg->GetSiblingFrame().GetFourVector(*LAB_bkg);
  TLorentzVector Pmet = I_bkg->GetFourVector(*LAB_bkg);
  
  m_Rsib = max(0.,Psib.Vect().Dot(Pmet.Vect().Unit()));
  m_Rsib = m_Rsib / (Pmet.Pt() + m_Rsib);
  
  TVector3 boostQCD = (Pmet+Psib).BoostVector();
  Psib.Boost(-boostQCD);
  double cosQCD = -1.*Psib.Vect().Unit().Dot(boostQCD.Unit());
  cosQCD = (1.-cosQCD)/2.;
  m_deltaQCD = (cosQCD-m_Rsib)/(cosQCD+m_Rsib);    
 
  // compressed tree
  LAB_ISR->ClearEvent();
  vector<RFKey> jetID_ISR; 
  for(int i = 0; i < int(Jets.size()); i++){
    TLorentzVector jet = Jets[i];
    jet.SetPtEtaPhiM(Jets[i].Pt(),0.0,Jets[i].Phi(),Jets[i].M());
    jetID_ISR.push_back(VIS_ISR->AddLabFrameFourVector(jet));
  }
  INV_ISR->SetLabFrameThreeVector(ETMiss);
  if(!LAB_ISR->AnalyzeEvent()) cout << "Something went wrong..." << endl;
 
  m_NV = VIS_ISR->GetNElementsInFrame(*V_ISR);
  m_NISR = VIS_ISR->GetNElementsInFrame(*ISR_ISR);

  if(m_NV < 1){
    m_PTISR = 0.;
    m_RISR = 0.;
    m_cosS = 0.;
    m_dphiCMI = 0.;
    m_dphiISRI = 0.;
    m_MS = 0.;
    m_MV = 0.;
    m_MISR = 0.;
    m_pTjV1 = 0.;
    m_pTjV2 = 0.;
    m_pTjV3 = 0.;
    m_pTjV4 = 0.;
    m_RPT_PTISR = 0.;
  } else {

    TVector3 vP_ISR = ISR_ISR->GetFourVector(*CM_ISR).Vect();
    TVector3 vP_I   = I_ISR->GetFourVector(*CM_ISR).Vect();

    m_PTISR = vP_ISR.Mag();
    m_MS    = S_ISR->GetMass();
    m_MV    = V_ISR->GetMass();
    m_MISR  = ISR_ISR->GetMass();

    if(m_PTISR > 0.)
      m_RISR = fabs(vP_I.Dot(vP_ISR.Unit())) / m_PTISR;
    else
      m_RISR = 0.;
   
    m_cosS  = S_ISR->GetCosDecayAngle();
    m_dphiCMI  = CM_ISR->GetDeltaPhiBoostVisible();
    m_dphiISRI = fabs(vP_ISR.DeltaPhi(vP_I));

    TLorentzVector PCM = CM_ISR->GetFourVector();
    m_RPT_PTISR = PCM.Pt() / ( PCM.Pt() + m_PTISR );

    int iN = 0;
    m_pTjV1 = 0.;
    m_pTjV2 = 0.;
    m_pTjV3 = 0.;
    m_pTjV4 = 0.;
    m_etajV1 = -5.;
    m_etajV2 = -5.;
    m_etajV3 = -5.;
    m_etajV4 = -5.;
    for(int i = 0; i < int(Jets.size()); i++){
      if(VIS_ISR->GetFrame(jetID_ISR[i]) == *V_ISR){
	if(iN == 0){
	  m_pTjV1 = Jets[i].Pt();
	  m_etajV1 = Jets[i].Eta();
	}
	if(iN == 1){
	  m_pTjV2 = Jets[i].Pt();
	  m_etajV2 = Jets[i].Eta();
	}
	if(iN == 2){
	  m_pTjV3 = Jets[i].Pt();
	  m_etajV3 = Jets[i].Eta();
	}
	if(iN == 3){
	  m_pTjV4 = Jets[i].Pt();
	  m_etajV4 = Jets[i].Eta();
	}
	iN++;
      }
    }
  }

  // signal variables
  TLorentzVector vP_Va = Pa->GetVisibleFourVector(*Pa);
  TLorentzVector vP_Vb = Pb->GetVisibleFourVector(*Pb);
  
  TLorentzVector vP_V1aPP = V1a->GetFourVector(*PP);
  TLorentzVector vP_V2aPP = V2a->GetFourVector(*PP);
  TLorentzVector vP_V1bPP = V1b->GetFourVector(*PP);
  TLorentzVector vP_V2bPP = V2b->GetFourVector(*PP);
  TLorentzVector vP_IaPP  = Ia->GetFourVector(*PP);
  TLorentzVector vP_IbPP  = Ib->GetFourVector(*PP);

  TLorentzVector vP_V1aPP_3 = V1a_3->GetFourVector(*PP_3);
  TLorentzVector vP_V2aPP_3 = V2a_3->GetFourVector(*PP_3);
  TLorentzVector vP_V3aPP_3 = V3a_3->GetFourVector(*PP_3);
  TLorentzVector vP_V1bPP_3 = V1b_3->GetFourVector(*PP_3);
  TLorentzVector vP_V2bPP_3 = V2b_3->GetFourVector(*PP_3);
  TLorentzVector vP_V3bPP_3 = V3b_3->GetFourVector(*PP_3);

  TLorentzVector vP_V1aPa = V1a->GetFourVector(*Pa);
  TLorentzVector vP_V2aPa = V2a->GetFourVector(*Pa);
  TLorentzVector vP_IaPa  = Ia->GetFourVector(*Pa);
  TLorentzVector vP_V1bPb = V1b->GetFourVector(*Pb);
  TLorentzVector vP_V2bPb = V2b->GetFourVector(*Pb);
  TLorentzVector vP_IbPb  = Ib->GetFourVector(*Pb);

  TLorentzVector vP_V1aPa_3 = V1a_3->GetFourVector(*Pa_3);
  TLorentzVector vP_V2aPa_3 = V2a_3->GetFourVector(*Pa_3);
  TLorentzVector vP_V3aPa_3 = V3a_3->GetFourVector(*Pa_3);
  TLorentzVector vP_V1bPb_3 = V1b_3->GetFourVector(*Pb_3);
  TLorentzVector vP_V2bPb_3 = V2b_3->GetFourVector(*Pb_3);
  TLorentzVector vP_V3bPb_3 = V3b_3->GetFourVector(*Pb_3);

  m_MJet = (vP_Va+vP_Vb).M();
  m_MJa = vP_Va.M();
  m_MJb = vP_Vb.M();
  m_MJ1a = vP_V1aPP.M();
  m_MJ1b = vP_V1bPP.M();
  m_MJ2a = vP_V2aPP.M();
  m_MJ2b = vP_V2bPP.M();

  m_MJ1a_3 = vP_V1aPP_3.M();
  m_MJ1b_3 = vP_V1bPP_3.M();
  m_MJ2a_3 = vP_V2aPP_3.M();
  m_MJ2b_3 = vP_V2bPP_3.M();
  m_MJ3a_3 = vP_V3aPP_3.M();
  m_MJ3b_3 = vP_V3bPP_3.M();

  m_H2PP = (vP_V1aPP + vP_V2aPP + vP_V1bPP + vP_V2bPP).P() + (vP_IaPP+vP_IbPP).P();
  m_H3PP = (vP_V1aPP + vP_V2aPP).P() + (vP_V1bPP + vP_V2bPP).P() + (vP_IaPP + vP_IbPP).P();
  m_H4PP = (vP_V1aPP + vP_V2aPP).P() + (vP_V1bPP + vP_V2bPP).P() + vP_IaPP.P() + vP_IbPP.P();
  m_H5PP = vP_V1aPP.P() + vP_V2aPP.P() + vP_V1bPP.P() + vP_V2bPP.P() + (vP_IaPP + vP_IbPP).P();
  m_H6PP = vP_V1aPP.P() + vP_V2aPP.P() + vP_V1bPP.P() + vP_V2bPP.P() + vP_IaPP.P() + vP_IbPP.P();

  m_H7PP_3 = vP_V1aPP_3.P() + vP_V2aPP_3.P() + vP_V3aPP_3.P() + 
             vP_V1bPP_3.P() + vP_V2bPP_3.P() + vP_V3bPP_3.P() + (vP_IaPP + vP_IbPP).P();
  m_H8PP_3 = vP_V1aPP_3.P() + vP_V2aPP_3.P() + vP_V3aPP_3.P() + 
             vP_V1bPP_3.P() + vP_V2bPP_3.P() + vP_V3bPP_3.P() + vP_IaPP.P() + vP_IbPP.P();

  m_H9PP  = 0.;
  m_H10PP = 0.;

  m_H2Pa = (vP_V1aPa + vP_V2aPa).P() + vP_IaPa.P();
  m_H2Pb = (vP_V1bPb + vP_V2bPb).P() + vP_IbPb.P();
  m_H3Pa = vP_V1aPa.P() + vP_V2aPa.P() + vP_IaPa.P();
  m_H3Pb = vP_V1bPb.P() + vP_V2bPb.P() + vP_IbPb.P();

  m_H4Pa = 0.;
  m_H4Pb = 0.;
  m_H5Pa = 0.;
  m_H5Pb = 0.;

  if(m_NJ1a > 1){
    m_H4Pa += SAV1a->GetChildFrame(0).GetMomentum(*Pa);
    m_H4Pa += SAV1a->GetChildFrame(1).GetMomentum(*Pa);
    m_H5Pa += m_H4Pa;
    m_H9PP += SAV1a->GetChildFrame(0).GetMomentum(*PP);
    m_H9PP += SAV1a->GetChildFrame(1).GetMomentum(*PP);
  } else {
    m_H4Pa += vP_V1aPa.P();
    m_H5Pa += vP_V1aPa.P();
    m_H9PP += vP_V1aPP.P();
  }
  if(m_NJ1b > 1){
    m_H4Pb += SAV1b->GetChildFrame(0).GetMomentum(*Pb);
    m_H4Pb += SAV1b->GetChildFrame(1).GetMomentum(*Pb);
    m_H5Pb += m_H4Pb;
    m_H9PP += SAV1b->GetChildFrame(0).GetMomentum(*PP);
    m_H9PP += SAV1b->GetChildFrame(1).GetMomentum(*PP);
  } else {
    m_H4Pb += vP_V1bPb.P();
    m_H5Pb += vP_V1bPb.P();
    m_H9PP += vP_V1bPP.P();
  }
  m_H4Pa += vP_V2aPa.P();
  m_H4Pb += vP_V2bPb.P();
  
  if(m_NJ2a > 1){
    m_H5Pa += SAV2a->GetChildFrame(0).GetMomentum(*Pa);
    m_H5Pa += SAV2a->GetChildFrame(1).GetMomentum(*Pa);
    m_H9PP += SAV2a->GetChildFrame(0).GetMomentum(*PP);
    m_H9PP += SAV2a->GetChildFrame(1).GetMomentum(*PP);
  } else {
    m_H5Pa += vP_V2aPa.P();
    m_H9PP += vP_V2aPP.P();
  }
  if(m_NJ2b > 1){
    m_H5Pb += SAV2b->GetChildFrame(0).GetMomentum(*Pb);
    m_H5Pb += SAV2b->GetChildFrame(1).GetMomentum(*Pb);
    m_H9PP += SAV2b->GetChildFrame(0).GetMomentum(*PP);
    m_H9PP += SAV2b->GetChildFrame(1).GetMomentum(*PP);
  } else {
    m_H5Pb += vP_V2bPb.P();
    m_H9PP += vP_V2bPP.P();
  }
  m_H4Pa += vP_IaPa.P();
  m_H5Pa += vP_IaPa.P();
  m_H4Pb += vP_IbPb.P();
  m_H5Pb += vP_IbPb.P();

  m_H10PP = m_H9PP;

  m_H9PP  += (vP_IaPP + vP_IbPP).P();
  m_H10PP += vP_IaPP.P() + vP_IbPP.P();

  TLorentzVector vP_IaCa  = Ia->GetFourVector(*Ca);
  TLorentzVector vP_IbCb  = Ib->GetFourVector(*Cb);

  m_H2Ca = 2.*vP_IaCa.P();
  m_H2Cb = 2.*vP_IbCb.P();
  if(m_NJ2a > 1)
    m_H3Ca = vP_IaCa.P()+
      SAV2a->GetChildFrame(0).GetMomentum(*Ca)+
      SAV2a->GetChildFrame(1).GetMomentum(*Ca);
  else 
    m_H3Ca = m_H2Ca;
  
  if(m_NJ2b > 1)
    m_H3Cb = vP_IbCb.P()+
      SAV2b->GetChildFrame(0).GetMomentum(*Cb)+
      SAV2b->GetChildFrame(1).GetMomentum(*Cb);
  else 
    m_H3Cb = m_H2Cb;

  TVector3 vP_PP = PP->GetFourVector(*LAB).Vect();
  
  m_PP_VisShape = PP->GetVisibleShape();
  m_MDR = m_PP_VisShape*PP->GetMass();
 
  
  m_cosPP = PP->GetCosDecayAngle();
  m_dphiVP = PP->GetDeltaPhiDecayVisible();
  m_dphiPPV = PP->GetDeltaPhiBoostVisible();
  m_cosP = Pa->GetCosDecayAngle(*Ia);
  m_dphiVP = (m_dphiVP-acos(-1.)/2.)/(acos(-1.)/2.);

  m_sangle = fabs(m_dphiVP + 2.*m_cosP)/3.;
  m_dangle = (2.*m_dphiVP - m_cosP)/3.;

  // gluino hemishpere variables
  m_dphiPa = Pa->GetDeltaPhiDecayPlanes(*Ca);
  m_dphiPb = Pb->GetDeltaPhiDecayPlanes(*Cb);

  double dphiA = m_dphiPa;
  double dphiB = m_dphiPb;
  if(dphiA > acos(-1.))
    dphiA = 2.*acos(-1.) - dphiA;
  if(dphiB > acos(-1.))
    dphiB = 2.*acos(-1.) - dphiB;
  m_ddphiP = (dphiA-dphiB)/acos(-1.);
  m_sdphiP = fabs(dphiA+dphiB)/2./acos(-1.);

  // inside gluino hemisphere variables
  m_dphiPV1a = Pa->GetDeltaPhiDecayPlanes(*SAV1a);
  m_dphiPV1b = Pb->GetDeltaPhiDecayPlanes(*SAV1b);
  m_cosV1a = SAV1a->GetCosDecayAngle();
  m_cosV1b = SAV1b->GetCosDecayAngle();
  m_dphiCV2a = Ca->GetDeltaPhiDecayPlanes(*SAV2a);
  m_dphiCV2b = Cb->GetDeltaPhiDecayPlanes(*SAV2b);
  m_cosV2a = SAV2a->GetCosDecayAngle();
  m_cosV2b = SAV2b->GetCosDecayAngle();

  m_MET = ETMiss.Pt();
  m_METphi = ETMiss.Phi();
  m_Meff = NTVars_meffInc;
  m_Aplan = NTExtraVars_Ap;
  m_dphi = NTVars_dPhi;
  m_dphiR = NTVars_dPhiR;

  m_pT_jet1  = Jets[0].Pt();
  m_eta_jet1 = Jets[0].Eta();
  m_pT_jet2  = Jets[1].Pt();
  m_eta_jet2 = Jets[1].Eta();
  if(m_NJet >= 3){
    m_pT_jet3  = Jets[2].Pt();
    m_eta_jet3 = Jets[2].Eta();
  } else {
    m_pT_jet3  = 0.;
    m_eta_jet3 = -5.;
  }
  if(m_NJet >= 4){
    m_pT_jet4  = Jets[3].Pt();
    m_eta_jet4 = Jets[3].Eta();
  } else { 
    m_pT_jet4  = 0.;
    m_eta_jet4 = -5.;
  }
  if(m_NJet >= 5){
    m_pT_jet5  = Jets[4].Pt();
    m_eta_jet5 = Jets[4].Eta();
  } else { 
    m_pT_jet5  = 0.;
    m_eta_jet5 = -5.;
  }
  if(m_NJet >= 6){
    m_pT_jet6  = Jets[5].Pt();
    m_eta_jet6 = Jets[5].Eta();
  } else {
    m_pT_jet6  = 0.;
    m_eta_jet6 = -5.;
  }

  m_pTPP_Va  = PP->GetTransverseMomentum(V1a->GetFourVector()+V2a->GetFourVector());
  m_pTPP_V1a = V1a->GetTransverseMomentum(*PP);
  m_pTPP_V2a = V2a->GetTransverseMomentum(*PP);
  m_pTPP_Vb  = PP->GetTransverseMomentum(V1b->GetFourVector()+V2b->GetFourVector());
  m_pTPP_V1b = V1b->GetTransverseMomentum(*PP);
  m_pTPP_V2b = V2b->GetTransverseMomentum(*PP);
  m_pTPP_Ia = Ia->GetTransverseMomentum(*PP);
  m_pTPP_Ib = Ib->GetTransverseMomentum(*PP);

  m_pTPP_V1a_3 = V1a_3->GetTransverseMomentum(*PP_3);
  m_pTPP_V2a_3 = V2a_3->GetTransverseMomentum(*PP_3);
  m_pTPP_V3a_3 = V3a_3->GetTransverseMomentum(*PP_3);
  m_pTPP_V1b_3 = V1b_3->GetTransverseMomentum(*PP_3);
  m_pTPP_V2b_3 = V2b_3->GetTransverseMomentum(*PP_3);
  m_pTPP_V3b_3 = V3b_3->GetTransverseMomentum(*PP_3);
  
  m_pPP_Va  = (V1a->GetFourVector(*PP)+V2a->GetFourVector(*PP)).P();
  m_pPP_V1a = V1a->GetMomentum(*PP);
  m_pPP_V2a = V2a->GetMomentum(*PP);
  m_pPP_Vb  = (V1b->GetFourVector(*PP)+V2b->GetFourVector(*PP)).P();
  m_pPP_V1b = V1b->GetMomentum(*PP);
  m_pPP_V2b = V2b->GetMomentum(*PP);
  m_pPP_Ia = Ia->GetMomentum(*PP);
  m_pPP_Ib = Ib->GetMomentum(*PP);

  m_pPP_V1a_3 = V1a_3->GetMomentum(*PP_3);
  m_pPP_V2a_3 = V2a_3->GetMomentum(*PP_3);
  m_pPP_V3a_3 = V3a_3->GetMomentum(*PP_3);
  m_pPP_V1b_3 = V1b_3->GetMomentum(*PP_3);
  m_pPP_V2b_3 = V2b_3->GetMomentum(*PP_3);
  m_pPP_V3b_3 = V3b_3->GetMomentum(*PP_3);

  m_pT_jet1a = 0.;
  m_pT_jet2a = 0.;
  m_pT_jet1b = 0.;
  m_pT_jet2b = 0.;

  int N = jetID.size();
  for(int j = 0; j < N; j++){
    RestFrame const& frame = VIS->GetFrame(jetID[j]);
    double pT = VIS->GetLabFrameFourVector(jetID[j]).Pt();

    if(V1a->IsSame(frame) || V2a->IsSame(frame)){
      if(pT > m_pT_jet1a){
	m_pT_jet2a = m_pT_jet1a;
	m_pT_jet1a = pT;
      } else {
	if(pT > m_pT_jet2a){
	  m_pT_jet2a = pT;
	} 
      }
    }
    if(V1b->IsSame(frame) || V2b->IsSame(frame)){
      if(pT > m_pT_jet1b){
	m_pT_jet2b = m_pT_jet1b;
	m_pT_jet1b = pT;
      } else {
	if(pT > m_pT_jet2b){
	  m_pT_jet2b = pT;
	} 
      }
    }
  }

  m_pTPP_jet1a = 0.;
  m_pTPP_jet2a = 0.;
  m_pTPP_jet3a = 0.;
  m_pTPP_jet1b = 0.;
  m_pTPP_jet2b = 0.;
  m_pTPP_jet3b = 0.;
  m_eta_jet1a = -5.;
  m_eta_jet2a = -5.;
  m_eta_jet3a = -5.;
  m_eta_jet1b = -5.;
  m_eta_jet2b = -5.;
  m_eta_jet3b = -5.;
  for(int j = 0; j < N; j++){
    RestFrame const& frame = VIS->GetFrame(jetID[j]);
    double pT = PP->GetTransverseMomentum(VIS->GetLabFrameFourVector(jetID[j]));
    double p  = PP->GetFourVector(VIS->GetLabFrameFourVector(jetID[j])).P();
    double eta = VIS->GetLabFrameFourVector(jetID[j]).Eta();

    if(V1a->IsSame(frame) || V2a->IsSame(frame)){
      if(pT > m_pTPP_jet1a){
	m_pTPP_jet3a = m_pTPP_jet2a;
	m_pPP_jet3a  = m_pPP_jet2a;
	m_eta_jet3a  = m_eta_jet2a;
	m_pTPP_jet2a = m_pTPP_jet1a;
	m_pPP_jet2a  = m_pPP_jet1a;
	m_eta_jet2a  = m_eta_jet1a;
	m_pTPP_jet1a = pT;
	m_pPP_jet1a  = p;
	m_eta_jet1a  = eta;
      } else {
	if(pT > m_pTPP_jet2a){
	  m_pTPP_jet3a = m_pTPP_jet2a;
	  m_pPP_jet3a  = m_pPP_jet2a;
	  m_eta_jet3a  = m_eta_jet2a;
	  m_pTPP_jet2a = pT;
	  m_pPP_jet2a  = p;
	  m_eta_jet2a  = eta;
	} else{
	  if(pT > m_pTPP_jet3a){
	    m_pTPP_jet3a = pT;
	    m_pPP_jet3a  = p;
	    m_eta_jet3a  = eta;
	  } 
	}
      }
    }
    if(V1b->IsSame(frame) || V2b->IsSame(frame)){
      if(pT > m_pTPP_jet1b){
	m_pTPP_jet3b = m_pTPP_jet2b;
	m_pPP_jet3b  = m_pPP_jet2b;
	m_eta_jet3b  = m_eta_jet2b;
	m_pTPP_jet2b = m_pTPP_jet1b;
	m_pPP_jet2b  = m_pPP_jet1b;
	m_eta_jet2b  = m_eta_jet1b;
	m_pTPP_jet1b = pT;
	m_pPP_jet1b  = p;
	m_eta_jet1b  = eta;
      } else {
	if(pT > m_pTPP_jet2b){
	  m_pTPP_jet3b = m_pTPP_jet2b;
	  m_pPP_jet3b  = m_pPP_jet2b;
	  m_eta_jet3b  = m_eta_jet2b;
	  m_pTPP_jet2b = pT;
	  m_pPP_jet2b  = p;
	  m_eta_jet2b  = eta;
	} else{
	  if(pT > m_pTPP_jet3b){
	    m_pTPP_jet3b = pT;
	    m_pPP_jet3b  = p;
	    m_eta_jet3b  = eta;
	  } 
	}
      }
    }
  }

  if(m_pTPP_jet1a > m_pTPP_jet1b){
    m_pTPP_jet1 = m_pTPP_jet1a;
    m_pTPP_jet2 = max(m_pTPP_jet1b,m_pTPP_jet2a);
  } else {
    m_pTPP_jet1 = m_pTPP_jet1b;
    m_pTPP_jet2 = max(m_pTPP_jet1a,m_pTPP_jet2b);
  }

  m_HT3PP = m_pTPP_Va + m_pTPP_Vb +
            m_H2PP/2.;
  m_HT4PP = m_pTPP_Va + m_pTPP_Vb +
            m_pTPP_Ia + m_pTPP_Ib;
  m_HT5PP = m_pTPP_V1a + m_pTPP_V1b +
            m_pTPP_V2a + m_pTPP_V2b +
            m_H2PP/2.;
  m_HT6PP = m_pTPP_V1a + m_pTPP_V1b +
            m_pTPP_V2a + m_pTPP_V2b +
            m_pTPP_Ia + m_pTPP_Ib;

  m_HT7PP_3 = m_pTPP_V1a_3 + m_pTPP_V1b_3 +
              m_pTPP_V2a_3 + m_pTPP_V2b_3 +
              m_pTPP_V3a_3 + m_pTPP_V3b_3 +
              m_H2PP/2.;
  m_HT8PP_3 = m_pTPP_V1a_3 + m_pTPP_V1b_3 +
              m_pTPP_V2a_3 + m_pTPP_V2b_3 +
              m_pTPP_V3a_3 + m_pTPP_V3b_3 +
              m_pTPP_Ia + m_pTPP_Ib;

  m_HT9PP = 0;
  if(m_NJ1a > 1){
    m_HT9PP += SAV1a->GetChildFrame(0).GetTransverseMomentum(*PP);
    m_HT9PP += SAV1a->GetChildFrame(1).GetTransverseMomentum(*PP);
  } else {
    m_HT9PP += m_pTPP_V1a;
  }
  if(m_NJ1b > 1){
    m_HT9PP += SAV1b->GetChildFrame(0).GetTransverseMomentum(*PP);
    m_HT9PP += SAV1b->GetChildFrame(1).GetTransverseMomentum(*PP);
  } else {
    m_HT9PP += m_pTPP_V1b;
  }
  if(m_NJ2a > 1){
    m_HT9PP += SAV2a->GetChildFrame(0).GetTransverseMomentum(*PP);
    m_HT9PP += SAV2a->GetChildFrame(1).GetTransverseMomentum(*PP);
  } else {
    m_HT9PP += m_pTPP_V2a;
  }
  if(m_NJ2b > 1){
    m_HT9PP += SAV2b->GetChildFrame(0).GetTransverseMomentum(*PP);
    m_HT9PP += SAV2b->GetChildFrame(1).GetTransverseMomentum(*PP);
  } else {
    m_HT9PP += m_pTPP_V2b;
  }

  m_HT10PP = m_HT9PP;
  m_HT9PP  += m_H2PP/2.;
  m_HT10PP += m_pTPP_Ia + m_pTPP_Ib;

  /// squark ratios
  m_R_H2PP_H3PP = m_H2PP/m_H3PP;
  m_R_pTj2_HT3PP = m_pTPP_jet2 / m_HT3PP;

  /// gluino ratios
  m_R_HT5PP_H5PP = m_HT5PP/m_H5PP;
  m_R_H2PP_H5PP = m_H2PP/m_H5PP;
  m_minR_pTj2i_HT3PPi = min(m_pTPP_jet2a/(m_pTPP_V1a+m_pTPP_V2a+m_pTPP_Ia),
			    m_pTPP_jet2b/(m_pTPP_V1b+m_pTPP_V2b+m_pTPP_Ib));
  m_maxR_H1PPi_H2PPi = max(m_pPP_Va/(m_pPP_V1a+m_pPP_V2a),m_pPP_Vb/(m_pPP_V1b+m_pPP_V2b));

   /// GG onestep ratios
  m_R_HT9PP_H9PP = m_HT5PP/m_H9PP;
  m_R_H2PP_H9PP = m_H2PP/m_H9PP;

  m_dH2o3P = m_H2Pa/m_H3Pa - m_H2Pb/m_H3Pb;

  /// 3-3 tree
  m_R_H2PP_H7PP_3 = m_H2PP/m_H7PP_3;
  m_R_HT7PP_H7PP_3 = m_HT7PP_3/m_H7PP_3;

  m_pTCM = vP_PP.Pt();
  m_pZCM = fabs(vP_PP.Pz());
  
  m_RPZ_HT3PP = m_pZCM / (m_pZCM + m_HT3PP);
  m_RPZ_HT5PP = m_pZCM / (m_pZCM + m_HT5PP);
  m_RPZ_HT9PP = m_pZCM / (m_pZCM + m_HT9PP);
  m_RPT_HT3PP = m_pTCM / (m_pTCM + m_HT3PP);
  m_RPT_HT5PP = m_pTCM / (m_pTCM + m_HT5PP);
  m_RPT_HT9PP = m_pTCM / (m_pTCM + m_HT9PP);

  m_RPZ_HT7PP_3 = m_pZCM / (m_pZCM + m_HT7PP_3);
  m_RPT_HT7PP_3 = m_pTCM / (m_pTCM + m_HT7PP_3);

  m_weight = GetEventWeight();
  m_veto = NTVars_veto;
  m_cleaning = NTVars_cleaning;
  m_timing = NTVars_timing;

  m_RunNumber = NTVars_RunNumber; 
  //m_EventNumber = NTVars_EventNumber;
  m_LumiBlockNumber = NTVars_LumiBlockNumber;
  m_nBJet = NTVars_nBJet;
  m_nCJet = NTVars_nCJet;
  //m_bTagWeight = NTVars_bTagWeight;
  m_bTagWeight = 1.;

  m_jet1_eta = jetEta->at(0);
  m_jet1_chf= NTVars_jet1Chf;
  if(jetFracSamplingMax->size() > 0)
    m_jet1_FracSamplingMax = jetFracSamplingMax->at(0);
  else
    m_jet1_FracSamplingMax = 0;

  if(m_CRWT){
    m_MTW = NTCRWTVars_mt;
    m_lep1Pt = NTCRWTVars_lep1Pt;
    m_lep1sign = NTCRWTVars_lep1sign;
    m_lep1Triggered = NTCRWTVars_lep1Triggered;
    m_lep1Signal = NTCRWTVars_lep1Signal;
  }

  if(m_CRZ){
    m_lep1Pt = NTCRZVars_lep1Pt;
    m_lep2Pt = NTCRZVars_lep2Pt;
    m_lep1Eta = NTCRZVars_lep1Eta;
    m_lep2Eta = NTCRZVars_lep2Eta;
    m_lep1Phi = NTCRZVars_lep1Phi;
    m_lep2Phi = NTCRZVars_lep2Phi;
    m_lep1sign = NTCRZVars_lep1sign;
    m_lep2sign = NTCRZVars_lep2sign;
    m_mll = NTCRZVars_mll;
    m_Zpt = NTCRZVars_Zpt;
    m_fakemet = NTCRZVars_fakemet;
    m_fakemetPhi = NTCRZVars_fakemetPhi;
    m_lep1Iso = NTCRZVars_lep1Iso;
    m_lep2Iso = NTCRZVars_lep2Iso;
    m_lep1DRjet = NTCRZVars_lep1DRjet;
    m_lep2DRjet = NTCRZVars_lep2DRjet;
    m_lep1jetJVF = NTCRZVars_lep1jetJVF;
    m_lep2jetJVF = NTCRZVars_lep2jetJVF;

    m_leptonWeight = NTCRZVars_leptonWeight;
  } else{
    if(systWeights->size() > 0)
      m_leptonWeight = systWeights->at(0);
    else
      m_leptonWeight = 1.;
  }

  if(m_CRY){
    m_phSignal = NTCRYVars_phSignal;
    m_phPt = NTCRYVars_phPt;
    m_phTruthOrigin = NTCRYVars_phTruthOrigin;
    m_phTopoetcone40 = NTCRYVars_phTopoetcone40;
    m_phPtcone20 = NTCRYVars_phPtcone20;
    // m_phTight = NTCRYVars_phTight; gone in v107
    m_phTight = 1.;
  }

  m_WZweight = NTVars_WZweight;
  //m_PRWHash  = NTVars_PRWHash;

  m_eventWeight = NTVars_eventWeight;
  m_pileupWeight = NTVars_pileupWeight;
  m_pileupWeightUp = NTVars_pileupWeightUp;
  m_pileupWeightDown = NTVars_pileupWeightDown;
  m_genWeight = NTVars_genWeight;
  m_normWeight = NTVars_normWeight;
  m_normWeightUp = NTVars_normWeightUp;
  m_normWeightDown = NTVars_normWeightDown;

  m_systWeights.clear();
  for(int i = 0; i < int(systWeights->size()); i++)
    m_systWeights.push_back(systWeights->at(i));
 
  m_btagSystWeights.clear();
  for(int i = 0; i < int(btagSystWeights->size()); i++)
    m_btagSystWeights.push_back(btagSystWeights->at(i));
 
  m_metTST = NTVars_metTST;
  m_metTSTPhi = NTVars_metTSTPhi;

  if(m_Tree)
    m_Tree->Fill();
}
