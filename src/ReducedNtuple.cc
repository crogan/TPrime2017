#include "ReducedNtuple.hh"

using namespace RestFrames;

ReducedNtuple::ReducedNtuple(TTree* tree)
  : NtupleBase<InputTreeBase>(tree)
{
  
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

  // AK8 candidate 4-vectors
  m_Tree->Branch("pT_top", &m_pT_top);
  m_Tree->Branch("eta_top", &m_eta_top);
  m_Tree->Branch("phi_top", &m_phi_top);
  m_Tree->Branch("mass_top", &m_mass_top);
  m_Tree->Branch("pT_higgs", &m_pT_higgs);
  m_Tree->Branch("eta_higgs", &m_eta_higgs);
  m_Tree->Branch("phi_higgs", &m_phi_higgs);
  m_Tree->Branch("mass_higgs", &m_mass_higgs);

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

  // extra-jet 4-vectors
  m_Tree->Branch("pT_extrajet", &m_pT_extrajet);
  m_Tree->Branch("eta_extrajet", &m_eta_extrajet);
  m_Tree->Branch("phi_extrajet", &m_phi_extrajet);
  m_Tree->Branch("mass_extrajet", &m_mass_extrajet);
 
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
}

void ReducedNtuple::FillOutputTree(){

  m_weight = GetEventWeight();
  m_NPV = SelectedEvent_npv;
  m_NPU = SelectedEvent_npuTrue; 
  m_isA = SelectedEvent_isRegionA;
  m_isB = SelectedEvent_isRegionB;
  m_isC = SelectedEvent_isRegionC;
  m_isD = SelectedEvent_isRegionD;

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

  // need to match higgs/top to lead AK8's
  int ihiggs[2];
  int itop[2];
  for(int i = 0; i < 2; i++){
    ihiggs[i] = -1;
    itop[i] = -1;
  }

  TLorentzVector Higgs;
  TLorentzVector Top;

  for(int ijet = 0; ijet < 2; ijet++){
    
    // loop through higgs tags
    int NH = ptHTagged->size();
    for(int h = 0; h < NH; h++){
      Higgs.SetPtEtaPhiM( ptHTagged->at(h), 
			etaHTagged->at(h),
			phiHTagged->at(h),
			MHTagged->at(h) );
      if(FatJets[ijet].DeltaR(Higgs) < 0.0001){
	ihiggs[ijet] = h;
	break;
      }
    }
    // loop through top tags
    int NT = ptTopTagged->size();
    for(int t = 0; t < NT; t++){
      Top.SetPtEtaPhiM( ptTopTagged->at(t), 
			etaTopTagged->at(t),
			phiTopTagged->at(t),
			MTopTagged->at(t) );
      if(FatJets[ijet].DeltaR(Top) < 0.0001){
	itop[ijet] = t;
	break;
      }
    }
  }

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
  Higgs.SetPtEtaPhiM( ptHTagged->at(ih), 
		      etaHTagged->at(ih),
		      phiHTagged->at(ih),
		      MHTagged->at(ih) );
  Top.SetPtEtaPhiM( ptTopTagged->at(it), 
		    etaTopTagged->at(it),
		    phiTopTagged->at(it),
		    MTopTagged->at(it) );

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
    if(sj0CSVAK8->at(ijet) < sj1CSVAK8->at(ijet)){
      TLorentzVector temp = j1;
      j1 = j2;
      j2 = temp;
    }
    if(ihiggs[ijet] > 0){
      Higgs0 = j1;
      Higgs1 = j2;
    } else {
      Top0 = j1;
      Top1 = j2;
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

    if(Jets[i].DeltaR( FatJets[0] ) < 1. ||
       Jets[i].DeltaR( FatJets[1] ) < 1.) continue;
    ExtraJets.push_back(Jets[i]);
    AllJets += Jets[i];
    m_pT_extrajet.push_back(Jets[i].Pt());
    m_eta_extrajet.push_back(Jets[i].Eta());
    m_phi_extrajet.push_back(Jets[i].Phi());
    m_mass_extrajet.push_back(Jets[i].M());
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

  if(m_Tree)
    m_Tree->Fill();
}
