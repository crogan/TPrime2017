#include "ReducedNtuple.hh"

using namespace RestFrames;

ReducedNtuple::ReducedNtuple(TTree* tree)
  : NtupleBase<InputTreeBase>(tree)
{

  m_SignalTriggerList.push_back("AK8PFJet360_TrimMass30_v");
  m_SignalTriggerList.push_back("AK8DiPFJet280_200_TrimMass30_v");
  m_SignalTriggerList.push_back("AK8PFHT700_TrimR0p1PT0p03Mass50_v");
  m_SignalTriggerList.push_back("AK8PFJet450_v");
  m_SignalTriggerList.push_back("PFHT800_v");
  m_SignalTriggerList.push_back("AK8PFJet360_TrimMass30_v");
  m_SignalTriggerList.push_back("AK8DiPFJet300_200_TrimMass30_v");
  m_SignalTriggerList.push_back("AK8PFHT700_TrimR0p1PT0p03Mass50_v");
  m_SignalTriggerList.push_back("AK8PFJet450_v");
  m_SignalTriggerList.push_back("PFHT900_v");

  m_N_SignalTriggerList = m_SignalTriggerList.size();
  
  LAB = new LabRecoFrame("LAB","lab");
  Tp = new DecayRecoFrame("Tp","T'");
  T  = new DecayRecoFrame("T","top");
  H  = new DecayRecoFrame("H","H");
  T0 = new VisibleRecoFrame("V1a","V_{1a}");
  T1 = new VisibleRecoFrame("V1b","V_{1b}");
  H0 = new VisibleRecoFrame("V2a","V_{2a}");
  H1 = new VisibleRecoFrame("V2b","V_{2b}");

  LAB->SetChildFrame(*Tp);
  Tp->AddChildFrame(*T);
  Tp->AddChildFrame(*H);
  T->AddChildFrame(*T0);
  T->AddChildFrame(*T1);
  H->AddChildFrame(*H0);
  H->AddChildFrame(*H1);

  LAB->InitializeTree(); 
  LAB->InitializeAnalysis(); 
}

ReducedNtuple::~ReducedNtuple() {
   delete LAB;
   delete Tp;
   delete T;
   delete H;
   delete T0;
   delete T1;
   delete H0;
   delete H1;
}

void ReducedNtuple::InitOutputTree(){
  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  m_Tree = (TTree*) new TTree("TPrime", "TPrime");

  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("NPV", &m_NPV);
  m_Tree->Branch("NPU", &m_NPU); 

  m_Tree->Branch("isA", &m_isA);
  m_Tree->Branch("isB", &m_isB);
  m_Tree->Branch("isC", &m_isC);
  m_Tree->Branch("isD", &m_isD);

  //trigger
  m_Tree->Branch("SignalTrigger", &m_SignalTrigger);;

  // AK8 candidate 4-vectors
  m_Tree->Branch("pT_top", &m_pT_top);
  m_Tree->Branch("eta_top", &m_eta_top);
  m_Tree->Branch("phi_top", &m_phi_top);
  m_Tree->Branch("mass_top", &m_mass_top);
  m_Tree->Branch("pT_higgs", &m_pT_higgs);
  m_Tree->Branch("eta_higgs", &m_eta_higgs);
  m_Tree->Branch("phi_higgs", &m_phi_higgs);
  m_Tree->Branch("mass_higgs", &m_mass_higgs);

  m_Tree->Branch("mass_softdrop_top", &m_mass_softdrop_top);
  m_Tree->Branch("mass_softdrop_higgs", &m_mass_softdrop_higgs);
  m_Tree->Branch("mass_pruned_top", &m_mass_pruned_top);
  m_Tree->Branch("mass_pruned_higgs", &m_mass_pruned_higgs);

  m_Tree->Branch("tau1_top", &m_tau1_top);
  m_Tree->Branch("tau2_top", &m_tau2_top);
  m_Tree->Branch("tau3_top", &m_tau3_top);
  m_Tree->Branch("tau1_higgs", &m_tau1_higgs);
  m_Tree->Branch("tau2_higgs", &m_tau2_higgs);
  m_Tree->Branch("tau3_higgs", &m_tau3_higgs);

  // subjet 4-vectors ("0" is leading CSV score from each)
  m_Tree->Branch("pT_top_sj0", &m_pT_top_sj0);
  m_Tree->Branch("eta_top_sj0", &m_eta_top_sj0);
  m_Tree->Branch("phi_top_sj0", &m_phi_top_sj0);
  m_Tree->Branch("mass_top_sj0", &m_mass_top_sj0);
  m_Tree->Branch("pT_top_sj1", &m_pT_top_sj1);
  m_Tree->Branch("eta_top_sj1", &m_eta_top_sj1);
  m_Tree->Branch("phi_top_sj1", &m_phi_top_sj1);
  m_Tree->Branch("mass_top_sj1", &m_mass_top_sj1);
  m_Tree->Branch("pT_higgs_sj0", &m_pT_higgs_sj0);
  m_Tree->Branch("eta_higgs_sj0", &m_eta_higgs_sj0);
  m_Tree->Branch("phi_higgs_sj0", &m_phi_higgs_sj0);
  m_Tree->Branch("mass_higgs_sj0", &m_mass_higgs_sj0);
  m_Tree->Branch("pT_higgs_sj1", &m_pT_higgs_sj1);
  m_Tree->Branch("eta_higgs_sj1", &m_eta_higgs_sj1);
  m_Tree->Branch("phi_higgs_sj1", &m_phi_higgs_sj1);
  m_Tree->Branch("mass_higgs_sj1", &m_mass_higgs_sj1);

  m_Tree->Branch("csv_top_sj0", &m_csv_top_sj0);
  m_Tree->Branch("csv_top_sj1", &m_csv_top_sj1);
  m_Tree->Branch("csv_higgs_sj0", &m_csv_higgs_sj0);
  m_Tree->Branch("csv_higgs_sj1", &m_csv_higgs_sj1);

  // extra-jet 4-vectors
  m_Tree->Branch("pT_extrajet", &m_pT_extrajet);
  m_Tree->Branch("eta_extrajet", &m_eta_extrajet);
  m_Tree->Branch("phi_extrajet", &m_phi_extrajet);
  m_Tree->Branch("mass_extrajet", &m_mass_extrajet);
  m_Tree->Branch("CSV_extrajet", &m_CSV_extrajet);
 
  // pre-calc variables
  m_Tree->Branch("M_Tp", &m_M_Tp);
  m_Tree->Branch("pT_Tp", &m_pT_Tp);

  m_Tree->Branch("cosTp", &m_cosTp); // wrt T
  m_Tree->Branch("cosH", &m_cosH);
  m_Tree->Branch("cosT", &m_cosT);
  m_Tree->Branch("cosTq", &m_cosTq);
  m_Tree->Branch("dphiTpT", &m_dphiTpT);
  m_Tree->Branch("dphiTpH", &m_dphiTpH);
  m_Tree->Branch("dphiTH", &m_dphiTH);

  m_Tree->Branch("T", &m_T);
  m_Tree->Branch("Tm", &m_Tm);
  m_Tree->Branch("TT", &m_TT);
  m_Tree->Branch("T_CM", &m_T_CM);
  m_Tree->Branch("Tm_CM", &m_Tm_CM);
  m_Tree->Branch("TT_CM", &m_TT_CM);

  m_Tree->Branch("M_extra", &m_M_extra);
  m_Tree->Branch("N_extra", &m_N_extra);
  m_Tree->Branch("pT_q", &m_pT_q);
  m_Tree->Branch("eta_q", &m_eta_q);
  m_Tree->Branch("phi_q", &m_phi_q);
  m_Tree->Branch("mass_q", &m_mass_q);

  m_Tree->Branch("EtaMax", &m_EtaMax);

  m_Tree->Branch("pT_ele_clean", &m_pT_ele_clean);
  m_Tree->Branch("eta_ele_clean", &m_eta_ele_clean);
  m_Tree->Branch("phi_ele_clean", &m_phi_ele_clean);
  m_Tree->Branch("E_ele_clean", &m_E_ele_clean);

  m_Tree->Branch("pT_mu_clean", &m_pT_mu_clean);
  m_Tree->Branch("eta_mu_clean", &m_eta_mu_clean);
  m_Tree->Branch("phi_mu_clean", &m_phi_mu_clean);
  m_Tree->Branch("E_mu_clean", &m_E_mu_clean);
}

void ReducedNtuple::FillOutputTree(){

  m_weight = GetEventWeight();
  m_NPV = SelectedEvent_npv;
  m_NPU = SelectedEvent_npuTrue; 

  vector<TLorentzVector> Jets; 
  GetJets(Jets, 30.); 

  // need four AK4 jets to play
  if(Jets.size() < 4) 
    return; 

  vector<TLorentzVector> FatJets; 
  GetLargeRJets(FatJets, 30.); 

  // Need two AK8 jets
  if(FatJets.size() < 2) 
    return; 

  // trigger preselection
  if(FatJets[0].Pt()+FatJets[1].Pt() < 850.)
    return;

  if(FatJets[0].Pt() < 400.)
    return;

  // if(SelectedEvent_isRegionNotABCD)
  //   return;
  
  m_EvtPreselection += m_weight; 

  // need to match higgs/top to lead AK8's
  int ihiggs[2];
  int itop[2];
  for(int i = 0; i < 2; i++){
    ihiggs[i] = -1;
    itop[i] = -1;
  }

  m_isA = SelectedEvent_isRegionA;
  m_isB = SelectedEvent_isRegionB;
  m_isC = SelectedEvent_isRegionC;
  m_isD = SelectedEvent_isRegionD;
  
  TLorentzVector Higgs;
  TLorentzVector Top;

  vector<double>* ptTop;
  vector<double>* etaTop;
  vector<double>* phiTop;
  vector<double>* MTop;
  vector<double>* tau1Top;
  vector<double>* tau2Top;
  vector<double>* tau3Top;
  vector<double>* SoftDropMassTop;
  vector<double>* PrunedMassTop;

  vector<double>* ptH;
  vector<double>* etaH;
  vector<double>* phiH;
  vector<double>* MH;
  vector<double>* tau1H;
  vector<double>* tau2H;
  vector<double>* tau3H;
  vector<double>* SoftDropMassH;
  vector<double>* PrunedMassH;

  if(!(m_isA || m_isB || m_isC || m_isD))
     return;
  
  if(m_isA){
    ptTop  = ptAntiTopTagged;
    etaTop = etaAntiTopTagged;
    phiTop = phiAntiTopTagged;
    MTop   = MAntiTopTagged;
    tau1Top = tau1AntiTopTagged;
    tau2Top = tau2AntiTopTagged;
    tau3Top = tau3AntiTopTagged;
    SoftDropMassTop = SoftDropMassAntiTopTagged;
    PrunedMassTop   = PrunedMassAntiTopTagged;

    ptH  = ptAntiHTagged;
    etaH = etaAntiHTagged;
    phiH = phiAntiHTagged;
    MH  = MAntiHTagged;
    tau1H = tau1AntiHTagged;
    tau2H = tau2AntiHTagged;
    tau3H = tau3AntiHTagged;
    SoftDropMassH = SoftDropMassAntiHTagged;
    PrunedMassH   = PrunedMassAntiHTagged;
  }
  if(m_isB){
    ptTop  = ptTopTagged;
    etaTop = etaTopTagged;
    phiTop = phiTopTagged;
    MTop   = MTopTagged;
    tau1Top = tau1TopTagged;
    tau2Top = tau2TopTagged;
    tau3Top = tau3TopTagged;
    SoftDropMassTop = SoftDropMassTopTagged;
    PrunedMassTop   = PrunedMassTopTagged;

    ptH  = ptAntiHTagged;
    etaH = etaAntiHTagged;
    phiH = phiAntiHTagged;
    MH  = MAntiHTagged;
    tau1H = tau1AntiHTagged;
    tau2H = tau2AntiHTagged;
    tau3H = tau3AntiHTagged;
    SoftDropMassH = SoftDropMassAntiHTagged;
    PrunedMassH   = PrunedMassAntiHTagged;
  }
  if(m_isC){
    ptTop  = ptAntiTopTagged;
    etaTop = etaAntiTopTagged;
    phiTop = phiAntiTopTagged;
    MTop   = MAntiTopTagged;
    tau1Top = tau1AntiTopTagged;
    tau2Top = tau2AntiTopTagged;
    tau3Top = tau3AntiTopTagged;
    SoftDropMassTop = SoftDropMassAntiTopTagged;
    PrunedMassTop   = PrunedMassAntiTopTagged;

    ptH  = ptHTagged;
    etaH = etaHTagged;
    phiH = phiHTagged;
    MH  = MHTagged;
    tau1H = tau1HTagged;
    tau2H = tau2HTagged;
    tau3H = tau3HTagged;
    SoftDropMassH = SoftDropMassHTagged;
    PrunedMassH   = PrunedMassHTagged;
  }
  if(m_isD){
    ptTop  = ptTopTagged;
    etaTop = etaTopTagged;
    phiTop = phiTopTagged;
    MTop   = MTopTagged;
    tau1Top = tau1TopTagged;
    tau2Top = tau2TopTagged;
    tau3Top = tau3TopTagged;
    SoftDropMassTop = SoftDropMassTopTagged;
    PrunedMassTop   = PrunedMassTopTagged;

    ptH  = ptHTagged;
    etaH = etaHTagged;
    phiH = phiHTagged;
    MH  = MHTagged;
    tau1H = tau1HTagged;
    tau2H = tau2HTagged;
    tau3H = tau3HTagged;
    SoftDropMassH = SoftDropMassHTagged;
    PrunedMassH   = PrunedMassHTagged;
  }
  
  for(int ijet = 0; ijet < 2; ijet++){
    
    // loop through higgs tags
    int NH = ptH->size();
    for(int h = 0; h < NH; h++){
      Higgs.SetPtEtaPhiM( ptH->at(h), 
			  etaH->at(h),
			  phiH->at(h),
			  MH->at(h) );
      if(FatJets[ijet].DeltaR(Higgs) < 0.0001){
	ihiggs[ijet] = h;
	break;
      }
    }
    // loop through top tags
    int NT = ptTop->size();
    for(int t = 0; t < NT; t++){
      Top.SetPtEtaPhiM( ptTop->at(t), 
			etaTop->at(t),
			phiTop->at(t),
			MTop->at(t) );
      if(FatJets[ijet].DeltaR(Top) < 0.0001){
	itop[ijet] = t;
	break;
      }
    }
  }

  m_SignalTrigger = false;

  // int Ntrig = SelectedEvent_trigName->size();
  // for(int s = 0; s < m_N_SignalTriggerList; s++){
  //   for(int t = 0; t < Ntrig; t++){
  //     if(SelectedEvent_trigName->at(t).find(m_SignalTriggerList[s]) != string::npos){
  // 	if(SelectedEvent_trigBit->at(t)){
  // 	  m_SignalTrigger = true;
  // 	  break;
  // 	}
  //     }
  //   }
  //   if(m_SignalTrigger) break;
  // }
  
  // int m_N_SignalTriggerList;
  // vector<string> m_SignalTriggerList;
  
  // cout << SelectedEvent_trigBit->size() << " " << SelectedEvent_trigName->size() << endl;
  // int Ntrig = SelectedEvent_trigName->size();
  // for(int t = 0; t < Ntrig; t++){
  //   cout << SelectedEvent_trigName->at(t) << endl;
  // }
  // cout << endl << endl;
  
// vector<double>  *SelectedEvent_trigBit;
  // vector<string>  *SelectedEvent_trigName;

  // m_isA = false;
  // m_isB = false;
  // m_isC = false;
  // m_isD = false;

  // make sure there is a good Higgs/top combo
  int ih = -1;
  int it = -1;
  if( itop[0] >= 0 && ihiggs[1] >= 0 ){
    ih = ihiggs[1];
    it = itop[0];
    itop[0] = 1;
    ihiggs[1] = 1;
    itop[1] = -1;
    ihiggs[0] = -1;
  } else {
    if( itop[1] >= 0 && ihiggs[0] >= 0 ){
      ih = ihiggs[0];
      it = itop[1];
      itop[0] = -1;
      ihiggs[1] = -1;
      itop[1] = 1;
      ihiggs[0] = 1;
    } else {
      return;
    }
  }

  Higgs.SetPtEtaPhiM( ptH->at(ih), 
		      etaH->at(ih),
		      phiH->at(ih),
		      MH->at(ih) );
  Top.SetPtEtaPhiM( ptTop->at(it), 
		    etaTop->at(it),
		    phiTop->at(it),
		    MTop->at(it) );

  m_tau1_top = tau1Top->at(it);
  m_tau2_top = tau2Top->at(it);
  m_tau3_top = tau3Top->at(it);
  m_tau1_higgs = tau1H->at(ih);
  m_tau2_higgs = tau2H->at(ih);
  m_tau3_higgs = tau3H->at(ih);

  m_mass_softdrop_top   = SoftDropMassTop->at(it);
  m_mass_softdrop_higgs = SoftDropMassH->at(ih);
  m_mass_pruned_top   = PrunedMassTop->at(it);
  m_mass_pruned_higgs = PrunedMassH->at(ih);

  m_pT_top   = Top.Pt();
  m_eta_top  = Top.Eta();
  m_phi_top  = Top.Phi();
  m_mass_top = Top.M();
  m_pT_higgs   = Higgs.Pt();
  m_eta_higgs  = Higgs.Eta();
  m_phi_higgs  = Higgs.Phi();
  m_mass_higgs = Higgs.M();

  m_M_Tp  = (Higgs+Top).M();
  m_pT_Tp = (Higgs+Top).Pt();

  TLorentzVector Higgs0, Higgs1;
  TLorentzVector Top0, Top1;

  for(int ijet = 0; ijet < 2; ijet++){
    TLorentzVector j1, j2;
    j1.SetPtEtaPhiE( sj0ptAK8->at(ijet),
		     sj0etaAK8->at(ijet),
		     sj0phiAK8->at(ijet),
		     sj0EnergyAK8->at(ijet) );
    j2.SetPtEtaPhiE( sj1ptAK8->at(ijet),
		     sj1etaAK8->at(ijet),
		     sj1phiAK8->at(ijet),
		     sj1EnergyAK8->at(ijet) );
    double csv1 = sj0CSVAK8->at(ijet);
    double csv2 = sj1CSVAK8->at(ijet);
    if(sj0CSVAK8->at(ijet) < sj1CSVAK8->at(ijet)){
      TLorentzVector temp = j1;
      double csvtemp = csv1;
      j1 = j2;
      csv1 = csv2;
      j2 = temp;
      csv2 = csvtemp;
    }
    if(ihiggs[ijet] > 0){
      Higgs0 = j1;
      Higgs1 = j2;
      m_csv_higgs_sj0 = csv1;
      m_csv_higgs_sj1 = csv2;
    } else {
      Top0 = j1;
      Top1 = j2;
      m_csv_top_sj0 = csv1;
      m_csv_top_sj1 = csv2;
    }
  }

  m_pT_top_sj0   = Top0.Pt();
  m_eta_top_sj0  = Top0.Eta();
  m_phi_top_sj0  = Top0.Phi();
  m_mass_top_sj0 = Top0.M();
  m_pT_top_sj1   = Top1.Pt();
  m_eta_top_sj1  = Top1.Eta();
  m_phi_top_sj1  = Top1.Phi();
  m_mass_top_sj1 = Top1.M();
  m_pT_higgs_sj0   = Higgs0.Pt();
  m_eta_higgs_sj0  = Higgs0.Eta();
  m_phi_higgs_sj0  = Higgs0.Phi();
  m_mass_higgs_sj0 = Higgs0.M();
  m_pT_higgs_sj1   = Higgs1.Pt();
  m_eta_higgs_sj1  = Higgs1.Eta();
  m_phi_higgs_sj1  = Higgs1.Phi();
  m_mass_higgs_sj1 = Higgs1.M();

  // "extra" jet stuff
  vector<TLorentzVector> ExtraJets;
  TLorentzVector AllJets(0.,0.,0.,0.);
  int Nj =  Jets.size();

  TLorentzVector fjet(0.,0.,0.,0.);
  m_eta_q = 0.; 
  m_EtaMax = 0.;

  m_pT_extrajet.clear();
  m_eta_extrajet.clear();
  m_phi_extrajet.clear();
  m_mass_extrajet.clear();
  
  for(int i = 0; i < Nj; i++){
    if(fabs(Jets[i].Eta()) > fabs(m_EtaMax))
      m_EtaMax = Jets[i].Eta();

    // NOTE: extra jets are _all_ jets in this run
    // if(Jets[i].DeltaR( FatJets[0] ) < 1. ||
    //    Jets[i].DeltaR( FatJets[1] ) < 1.) continue;

    ExtraJets.push_back(Jets[i]);
    AllJets += Jets[i];
    m_pT_extrajet.push_back(Jets[i].Pt());
    m_eta_extrajet.push_back(Jets[i].Eta());
    m_phi_extrajet.push_back(Jets[i].Phi());
    m_mass_extrajet.push_back(Jets[i].M());
    m_CSV_extrajet.push_back(csvAK4->at(i));
    if(fabs(Jets[i].Eta()) > fabs(m_eta_q)){
      fjet = Jets[i];
      m_eta_q = Jets[i].Eta();
    }
  }

  m_M_extra = AllJets.M();
  m_N_extra = ExtraJets.size();
  if(m_N_extra > 0){
    m_pT_q = fjet.Pt();
    m_eta_q = fjet.Eta();
    m_phi_q = fjet.Phi();
    m_mass_q = fjet.M();
  } else {
    m_pT_q = 0;
    m_eta_q = 0;
    m_phi_q = 0;
    m_mass_q = 0;
  }
  

  vector<double> eigenvalues;
  MomTensorCalc(ExtraJets, eigenvalues, 1., true);
  m_T  = eigenvalues[0];
  m_Tm = eigenvalues[2];
  MomTensorCalc(ExtraJets, eigenvalues, 1., false);
  m_TT = eigenvalues[0];

  TVector3 CMboost = AllJets.BoostVector();
  Nj = ExtraJets.size();
  for(int i = 0; i < Nj; i++)
    ExtraJets[i].Boost(-CMboost);
  
  MomTensorCalc(ExtraJets, eigenvalues, 1., true);
  m_T_CM  = eigenvalues[0];
  m_Tm_CM = eigenvalues[2];
  MomTensorCalc(ExtraJets, eigenvalues, 1., false);
  m_TT_CM = eigenvalues[0];

  // RestFrames stuff

  LAB->ClearEvent();
  T0->SetLabFrameFourVector(Top0);
  T1->SetLabFrameFourVector(Top1);
  H0->SetLabFrameFourVector(Higgs0);
  H1->SetLabFrameFourVector(Higgs1);
  if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  //m_cosTp = Tp->GetCosDecayAngle();
  m_cosH  = H->GetCosDecayAngle();
  m_cosT  = T->GetCosDecayAngle();
  m_dphiTH = T->GetDeltaPhiDecayPlanes(*H);
  m_dphiTpH = Tp->GetDeltaPhiDecayPlanes(*H);
  m_dphiTpT = Tp->GetDeltaPhiDecayPlanes(*T);

  CMboost = (Higgs+Top).BoostVector();
  Top.Boost(-CMboost);
  m_cosTp = Top.Vect().Unit().Dot(-CMboost.Unit());
  if(ExtraJets.size() > 0){
    fjet.Boost(-CMboost);
    m_cosTq = Top.Vect().Unit().Dot( fjet.Vect().Unit() );
  } else {
    m_cosTq = 0;
  }

  // leptons
  m_pT_ele_clean.clear();
  m_eta_ele_clean.clear();
  m_phi_ele_clean.clear();
  m_E_ele_clean.clear();
  m_pT_mu_clean.clear();
  m_eta_mu_clean.clear();
  m_phi_mu_clean.clear();
  m_E_mu_clean.clear();

  int Nele = ptCleanedEl->size();
  for(int i = 0; i < Nele; i++){
    m_pT_ele_clean.push_back(ptCleanedEl->at(i));
    m_eta_ele_clean.push_back(etaCleanedEl->at(i));
    m_phi_ele_clean.push_back(phiCleanedEl->at(i));
    m_E_ele_clean.push_back(ECleanedEl->at(i));
  }
  
  int Nmu = ptCleanedMu->size();
  for(int i = 0; i < Nmu; i++){
    m_pT_mu_clean.push_back(ptCleanedMu->at(i));
    m_eta_mu_clean.push_back(etaCleanedMu->at(i));
    m_phi_mu_clean.push_back(phiCleanedMu->at(i));
    m_E_mu_clean.push_back(ECleanedMu->at(i));
  }

  m_EvtSelected += m_weight;

  if(m_Tree)
    m_Tree->Fill();
}
