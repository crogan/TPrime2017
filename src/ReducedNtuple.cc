#include "ReducedNtuple.hh"

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

  //cout << GetEventWeight() << endl;

  TVector3 ETMiss = GetMET(); 

  vector<TLorentzVector> Jets; 
  GetJets(Jets, 50., 2.8); 

  // need two jets to play
  if(Jets.size() < 2) 
    return; 

  if(ETMiss.Mag() < 200. || m_NJet < 2)
    return;

  m_dphiMin1   = DeltaPhiMin(Jets, ETMiss, 1);
  m_dphiMin2   = DeltaPhiMin(Jets, ETMiss, 2);
  m_dphiMin3   = DeltaPhiMin(Jets, ETMiss, 3);
  m_dphiMinAll = DeltaPhiMin(Jets, ETMiss);

 

  // m_systWeights.clear();
  // for(int i = 0; i < int(systWeights->size()); i++)
  //   m_systWeights.push_back(systWeights->at(i));
 
  // m_btagSystWeights.clear();
  // for(int i = 0; i < int(btagSystWeights->size()); i++)
  //   m_btagSystWeights.push_back(btagSystWeights->at(i));
 
  // m_metTST = NTVars_metTST;
  // m_metTSTPhi = NTVars_metTSTPhi;

  if(m_Tree)
    m_Tree->Fill();
}
