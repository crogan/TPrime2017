//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 15 12:02:24 2017 by ROOT version 5.34/25
// from TTree tree/TtHT
// found on file: TTJets.root
//////////////////////////////////////////////////////////

#ifndef InputTreeBase_h
#define InputTreeBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <utility>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxSelectedEvent_lhewts = 254;
   const Int_t kMaxisotropy_ExtraAK4 = 1;
   const Int_t kMaxcircularity_ExtraAK4 = 1;
   const Int_t kMaxsphericity_ExtraAK4 = 1;
   const Int_t kMaxaplanarity_ExtraAK4 = 1;
   const Int_t kMaxC_ExtraAK4 = 1;
   const Int_t kMaxD_ExtraAK4 = 1;
   const Int_t kMaxthrust_ExtraAK4 = 1;
   const Int_t kMaxthrustminor_ExtraAK4 = 1;
   const Int_t kMaxcosThetaT = 1;

using namespace std;

class InputTreeBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           SelectedEvent_runno;
   Int_t           SelectedEvent_lumisec;
   Int_t           SelectedEvent_evtno;
   Int_t           SelectedEvent_bcno;
   Int_t           SelectedEvent_time;
   Double_t        SelectedEvent_htHat;
   Double_t        SelectedEvent_EvtWeight;
   Double_t        SelectedEvent_EvtWtPV;
   Double_t        SelectedEvent_EvtWtPVBG;
   Double_t        SelectedEvent_EvtWtPVH;
   Double_t        SelectedEvent_EvtWtPVLow;
   Double_t        SelectedEvent_EvtWtPVHigh;
   Double_t        SelectedEvent_EvtWtHT;
   Double_t        SelectedEvent_EvtWtHTUp;
   Double_t        SelectedEvent_EvtWtHTDown;
   Int_t           SelectedEvent_npv;
   Int_t           SelectedEvent_npuTrue;
   Double_t        SelectedEvent_toptagsf;
   Double_t        SelectedEvent_toptagsf_Up;
   Double_t        SelectedEvent_toptagsf_Down;
   Double_t        SelectedEvent_btagsf;
   Double_t        SelectedEvent_btagsf_bcUp;
   Double_t        SelectedEvent_btagsf_bcDown;
   Double_t        SelectedEvent_btagsf_lUp;
   Double_t        SelectedEvent_btagsf_lDown;
   Double_t        SelectedEvent_mtprime;
   Double_t        SelectedEvent_mtprimeDummy;
   Double_t        SelectedEvent_mtprimeDummyA;
   Double_t        SelectedEvent_mtprimeDummyC;
   Double_t        SelectedEvent_mtprime_corr;
   Double_t        SelectedEvent_mtprimeDummy_corr;
   Double_t        SelectedEvent_mtprimeDummyA_corr;
   Double_t        SelectedEvent_mtprimeDummyC_corr;
   Double_t        SelectedEvent_ht;
   Int_t           SelectedEvent_nAK4;
   Int_t           SelectedEvent_nAK8;
   Int_t           SelectedEvent_nEl;
   Int_t           SelectedEvent_nMu;
   Int_t           SelectedEvent_nCleanedEl;
   Int_t           SelectedEvent_nCleanedMu;
   Bool_t          SelectedEvent_isRegionA;
   Bool_t          SelectedEvent_isRegionB;
   Bool_t          SelectedEvent_isRegionC;
   Bool_t          SelectedEvent_isRegionD;
   Bool_t          SelectedEvent_isRegionNotABCD;
   Int_t           SelectedEvent_lhewts_;
   Int_t           SelectedEvent_lhewts_first[kMaxSelectedEvent_lhewts];   //[SelectedEvent_lhewts_]
   Double_t        SelectedEvent_lhewts_second[kMaxSelectedEvent_lhewts];   //[SelectedEvent_lhewts_]
   vector<double>  *SelectedEvent_trigBit;
   vector<string>  *SelectedEvent_trigName;
   Double_t        SelectedEvent_isotropy;
   Double_t        SelectedEvent_circularity;
   Double_t        SelectedEvent_sphericity;
   Double_t        SelectedEvent_aplanarity;
   Double_t        SelectedEvent_C;
   Double_t        SelectedEvent_D;
   Double_t        SelectedEvent_thrust;
   Double_t        SelectedEvent_thrustminor;
   Double_t        SelectedEvent_isotropy_ExtraAK4;
   Double_t        SelectedEvent_circularity_ExtraAK4;
   Double_t        SelectedEvent_sphericity_ExtraAK4;
   Double_t        SelectedEvent_aplanarity_ExtraAK4;
   Double_t        SelectedEvent_C_ExtraAK4;
   Double_t        SelectedEvent_D_ExtraAK4;
   Double_t        SelectedEvent_thrust_ExtraAK4;
   Double_t        SelectedEvent_thrustminor_ExtraAK4;
   Double_t        SelectedEvent_cosThetaT;
   vector<int>     *idxAK4;
   vector<double>  *ptAK4;
   vector<double>  *etaAK4;
   vector<double>  *phiAK4;
   vector<double>  *MAK4;
   vector<double>  *csvAK4;
   vector<double>  *partonFlavourAK4;
   vector<double>  *hadronFlavourAK4;
   vector<int>     *idxExtraAK4;
   vector<double>  *ptExtraAK4;
   vector<double>  *etaExtraAK4;
   vector<double>  *phiExtraAK4;
   vector<double>  *MExtraAK4;
   vector<double>  *csvExtraAK4;
   vector<double>  *partonFlavourExtraAK4;
   vector<double>  *hadronFlavourExtraAK4;
   vector<int>     *idxAK8;
   vector<double>  *ptAK8;
   vector<double>  *etaAK8;
   vector<double>  *phiAK8;
   vector<double>  *MAK8;
   vector<double>  *SoftDropMassAK8;
   vector<double>  *PrunedMassAK8;
   vector<double>  *tau1AK8;
   vector<double>  *tau2AK8;
   vector<double>  *tau3AK8;
   vector<double>  *csvAK8;
   vector<double>  *partonFlavourAK8;
   vector<double>  *hadronFlavourAK8;
   vector<double>  *doubleBAK8;
   vector<double>  *sj0CSVAK8;
   vector<double>  *sj1CSVAK8;
   vector<double>  *hadronFlavourSJ0AK8;
   vector<double>  *hadronFlavourSJ1AK8;
   vector<double>  *sj0ptAK8;
   vector<double>  *sj1ptAK8;
   vector<double>  *sj0etaAK8;
   vector<double>  *sj1etaAK8;
   vector<double>  *sj0phiAK8;
   vector<double>  *sj1phiAK8;
   vector<double>  *sj0EnergyAK8;
   vector<double>  *sj1EnergyAK8;
   vector<int>     *idxHTagged;
   vector<double>  *ptHTagged;
   vector<double>  *etaHTagged;
   vector<double>  *phiHTagged;
   vector<double>  *MHTagged;
   vector<double>  *SoftDropMassHTagged;
   vector<double>  *PrunedMassHTagged;
   vector<double>  *tau1HTagged;
   vector<double>  *tau2HTagged;
   vector<double>  *tau3HTagged;
   vector<double>  *csvHTagged;
   vector<double>  *partonFlavourHTagged;
   vector<double>  *hadronFlavourHTagged;
   vector<double>  *doubleBHTagged;
   vector<double>  *sj0CSVHTagged;
   vector<double>  *sj1CSVHTagged;
   vector<double>  *hadronFlavourSJ0HTagged;
   vector<double>  *hadronFlavourSJ1HTagged;
   vector<double>  *sj0ptHTagged;
   vector<double>  *sj1ptHTagged;
   vector<double>  *sj0etaHTagged;
   vector<double>  *sj1etaHTagged;
   vector<double>  *sj0phiHTagged;
   vector<double>  *sj1phiHTagged;
   vector<double>  *sj0EnergyHTagged;
   vector<double>  *sj1EnergyHTagged;
   vector<int>     *idxAntiHTagged;
   vector<double>  *ptAntiHTagged;
   vector<double>  *etaAntiHTagged;
   vector<double>  *phiAntiHTagged;
   vector<double>  *MAntiHTagged;
   vector<double>  *SoftDropMassAntiHTagged;
   vector<double>  *PrunedMassAntiHTagged;
   vector<double>  *tau1AntiHTagged;
   vector<double>  *tau2AntiHTagged;
   vector<double>  *tau3AntiHTagged;
   vector<double>  *csvAntiHTagged;
   vector<double>  *partonFlavourAntiHTagged;
   vector<double>  *hadronFlavourAntiHTagged;
   vector<double>  *doubleBAntiHTagged;
   vector<double>  *sj0CSVAntiHTagged;
   vector<double>  *sj1CSVAntiHTagged;
   vector<double>  *hadronFlavourSJ0AntiHTagged;
   vector<double>  *hadronFlavourSJ1AntiHTagged;
   vector<double>  *sj0ptAntiHTagged;
   vector<double>  *sj1ptAntiHTagged;
   vector<double>  *sj0etaAntiHTagged;
   vector<double>  *sj1etaAntiHTagged;
   vector<double>  *sj0phiAntiHTagged;
   vector<double>  *sj1phiAntiHTagged;
   vector<double>  *sj0EnergyAntiHTagged;
   vector<double>  *sj1EnergyAntiHTagged;
   vector<int>     *idxTopTagged;
   vector<double>  *ptTopTagged;
   vector<double>  *etaTopTagged;
   vector<double>  *phiTopTagged;
   vector<double>  *MTopTagged;
   vector<double>  *SoftDropMassTopTagged;
   vector<double>  *PrunedMassTopTagged;
   vector<double>  *tau1TopTagged;
   vector<double>  *tau2TopTagged;
   vector<double>  *tau3TopTagged;
   vector<double>  *csvTopTagged;
   vector<double>  *partonFlavourTopTagged;
   vector<double>  *hadronFlavourTopTagged;
   vector<double>  *doubleBTopTagged;
   vector<double>  *sj0CSVTopTagged;
   vector<double>  *sj1CSVTopTagged;
   vector<double>  *hadronFlavourSJ0TopTagged;
   vector<double>  *hadronFlavourSJ1TopTagged;
   vector<double>  *sj0ptTopTagged;
   vector<double>  *sj1ptTopTagged;
   vector<double>  *sj0etaTopTagged;
   vector<double>  *sj1etaTopTagged;
   vector<double>  *sj0phiTopTagged;
   vector<double>  *sj1phiTopTagged;
   vector<double>  *sj0EnergyTopTagged;
   vector<double>  *sj1EnergyTopTagged;
   vector<int>     *idxAntiTopTagged;
   vector<double>  *ptAntiTopTagged;
   vector<double>  *etaAntiTopTagged;
   vector<double>  *phiAntiTopTagged;
   vector<double>  *MAntiTopTagged;
   vector<double>  *SoftDropMassAntiTopTagged;
   vector<double>  *PrunedMassAntiTopTagged;
   vector<double>  *tau1AntiTopTagged;
   vector<double>  *tau2AntiTopTagged;
   vector<double>  *tau3AntiTopTagged;
   vector<double>  *csvAntiTopTagged;
   vector<double>  *partonFlavourAntiTopTagged;
   vector<double>  *hadronFlavourAntiTopTagged;
   vector<double>  *doubleBAntiTopTagged;
   vector<double>  *sj0CSVAntiTopTagged;
   vector<double>  *sj1CSVAntiTopTagged;
   vector<double>  *hadronFlavourSJ0AntiTopTagged;
   vector<double>  *hadronFlavourSJ1AntiTopTagged;
   vector<double>  *sj0ptAntiTopTagged;
   vector<double>  *sj1ptAntiTopTagged;
   vector<double>  *sj0etaAntiTopTagged;
   vector<double>  *sj1etaAntiTopTagged;
   vector<double>  *sj0phiAntiTopTagged;
   vector<double>  *sj1phiAntiTopTagged;
   vector<double>  *sj0EnergyAntiTopTagged;
   vector<double>  *sj1EnergyAntiTopTagged;
   vector<int>     *idxZTagged;
   vector<double>  *ptZTagged;
   vector<double>  *etaZTagged;
   vector<double>  *phiZTagged;
   vector<double>  *MZTagged;
   vector<double>  *SoftDropMassZTagged;
   vector<double>  *PrunedMassZTagged;
   vector<double>  *tau1ZTagged;
   vector<double>  *tau2ZTagged;
   vector<double>  *tau3ZTagged;
   vector<double>  *csvZTagged;
   vector<double>  *partonFlavourZTagged;
   vector<double>  *hadronFlavourZTagged;
   vector<double>  *doubleBZTagged;
   vector<double>  *sj0CSVZTagged;
   vector<double>  *sj1CSVZTagged;
   vector<double>  *hadronFlavourSJ0ZTagged;
   vector<double>  *hadronFlavourSJ1ZTagged;
   vector<double>  *sj0ptZTagged;
   vector<double>  *sj1ptZTagged;
   vector<double>  *sj0etaZTagged;
   vector<double>  *sj1etaZTagged;
   vector<double>  *sj0phiZTagged;
   vector<double>  *sj1phiZTagged;
   vector<double>  *sj0EnergyZTagged;
   vector<double>  *sj1EnergyZTagged;
   vector<int>     *idxAntiZTagged;
   vector<double>  *ptAntiZTagged;
   vector<double>  *etaAntiZTagged;
   vector<double>  *phiAntiZTagged;
   vector<double>  *MAntiZTagged;
   vector<double>  *SoftDropMassAntiZTagged;
   vector<double>  *PrunedMassAntiZTagged;
   vector<double>  *tau1AntiZTagged;
   vector<double>  *tau2AntiZTagged;
   vector<double>  *tau3AntiZTagged;
   vector<double>  *csvAntiZTagged;
   vector<double>  *partonFlavourAntiZTagged;
   vector<double>  *hadronFlavourAntiZTagged;
   vector<double>  *doubleBAntiZTagged;
   vector<double>  *sj0CSVAntiZTagged;
   vector<double>  *sj1CSVAntiZTagged;
   vector<double>  *hadronFlavourSJ0AntiZTagged;
   vector<double>  *hadronFlavourSJ1AntiZTagged;
   vector<double>  *sj0ptAntiZTagged;
   vector<double>  *sj1ptAntiZTagged;
   vector<double>  *sj0etaAntiZTagged;
   vector<double>  *sj1etaAntiZTagged;
   vector<double>  *sj0phiAntiZTagged;
   vector<double>  *sj1phiAntiZTagged;
   vector<double>  *sj0EnergyAntiZTagged;
   vector<double>  *sj1EnergyAntiZTagged;
   vector<int>     *idxEl;
   vector<double>  *ptEl;
   vector<double>  *etaEl;
   vector<double>  *phiEl;
   vector<double>  *EEl;
   vector<double>  *IsoDREl;
   vector<double>  *dR_Iso2DEl;
   vector<double>  *ptrel_Iso2DEl;
   vector<double>  *IsoDRAfterIso2DEl;
   vector<int>     *idxCleanedEl;
   vector<double>  *ptCleanedEl;
   vector<double>  *etaCleanedEl;
   vector<double>  *phiCleanedEl;
   vector<double>  *ECleanedEl;
   vector<int>     *idxMu;
   vector<double>  *ptMu;
   vector<double>  *etaMu;
   vector<double>  *phiMu;
   vector<double>  *EMu;
   vector<double>  *IsoDRMu;
   vector<double>  *dR_Iso2DMu;
   vector<double>  *ptrel_Iso2DMu;
   vector<double>  *IsoDRAfterIso2DMu;
   vector<int>     *idxCleanedMu;
   vector<double>  *ptCleanedMu;
   vector<double>  *etaCleanedMu;
   vector<double>  *phiCleanedMu;
   vector<double>  *ECleanedMu;

   // List of branches
   TBranch        *b_SelectedEvent_runno;   //!
   TBranch        *b_SelectedEvent_lumisec;   //!
   TBranch        *b_SelectedEvent_evtno;   //!
   TBranch        *b_SelectedEvent_bcno;   //!
   TBranch        *b_SelectedEvent_time;   //!
   TBranch        *b_SelectedEvent_htHat;   //!
   TBranch        *b_EvtWeight;   //!
   TBranch        *b_EvtWtPV;   //!
   TBranch        *b_EvtWtPVBG;   //!
   TBranch        *b_EvtWtPVH;   //!
   TBranch        *b_EvtWtPVLow;   //!
   TBranch        *b_EvtWtPVHigh;   //!
   TBranch        *b_EvtWtHT;   //!
   TBranch        *b_EvtWtHTUp;   //!
   TBranch        *b_EvtWtHTDown;   //!
   TBranch        *b_npv;   //!
   TBranch        *b_npuTrue;   //!
   TBranch        *b_toptagsf;   //!
   TBranch        *b_toptagsf_Up;   //!
   TBranch        *b_toptagsf_Down;   //!
   TBranch        *b_btagsf;   //!
   TBranch        *b_btagsf_bcUp;   //!
   TBranch        *b_btagsf_bcDown;   //!
   TBranch        *b_btagsf_lUp;   //!
   TBranch        *b_btagsf_lDown;   //!
   TBranch        *b_mtprime;   //!
   TBranch        *b_mtprimeDummy;   //!
   TBranch        *b_mtprimeDummyA;   //!
   TBranch        *b_mtprimeDummyC;   //!
   TBranch        *b_mtprime_corr;   //!
   TBranch        *b_mtprimeDummy_corr;   //!
   TBranch        *b_mtprimeDummyA_corr;   //!
   TBranch        *b_mtprimeDummyC_corr;   //!
   TBranch        *b_ht;   //!
   TBranch        *b_nAK4;   //!
   TBranch        *b_nAK8;   //!
   TBranch        *b_nEl;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_nCleanedEl;   //!
   TBranch        *b_nCleanedMu;   //!
   TBranch        *b_isRegionA;   //!
   TBranch        *b_isRegionB;   //!
   TBranch        *b_isRegionC;   //!
   TBranch        *b_isRegionD;   //!
   TBranch        *b_isRegionNotABCD;   //!
   TBranch        *b_SelectedEvent_lhewts_;   //!
   TBranch        *b_SelectedEvent_lhewts_first;   //!
   TBranch        *b_SelectedEvent_lhewts_second;   //!
   TBranch        *b_SelectedEvent_trigBit;   //!
   TBranch        *b_SelectedEvent_trigName;   //!
   TBranch        *b_isotropy;   //!
   TBranch        *b_circularity;   //!
   TBranch        *b_sphericity;   //!
   TBranch        *b_aplanarity;   //!
   TBranch        *b_C;   //!
   TBranch        *b_D;   //!
   TBranch        *b_thrust;   //!
   TBranch        *b_thrustminor;   //!
   TBranch        *b_isotropy_ExtraAK4_;   //!
   TBranch        *b_circularity_ExtraAK4_;   //!
   TBranch        *b_sphericity_ExtraAK4_;   //!
   TBranch        *b_aplanarity_ExtraAK4_;   //!
   TBranch        *b_C_ExtraAK4_;   //!
   TBranch        *b_D_ExtraAK4_;   //!
   TBranch        *b_thrust_ExtraAK4_;   //!
   TBranch        *b_thrustminor_ExtraAK4_;   //!
   TBranch        *b_cosThetaT_;   //!
   TBranch        *b_idxAK4;   //!
   TBranch        *b_ptAK4;   //!
   TBranch        *b_etaAK4;   //!
   TBranch        *b_phiAK4;   //!
   TBranch        *b_MAK4;   //!
   TBranch        *b_csvAK4;   //!
   TBranch        *b_partonFlavourAK4;   //!
   TBranch        *b_hadronFlavourAK4;   //!
   TBranch        *b_idxExtraAK4;   //!
   TBranch        *b_ptExtraAK4;   //!
   TBranch        *b_etaExtraAK4;   //!
   TBranch        *b_phiExtraAK4;   //!
   TBranch        *b_MExtraAK4;   //!
   TBranch        *b_csvExtraAK4;   //!
   TBranch        *b_partonFlavourExtraAK4;   //!
   TBranch        *b_hadronFlavourExtraAK4;   //!
   TBranch        *b_idxAK8;   //!
   TBranch        *b_ptAK8;   //!
   TBranch        *b_etaAK8;   //!
   TBranch        *b_phiAK8;   //!
   TBranch        *b_MAK8;   //!
   TBranch        *b_SoftDropMassAK8;   //!
   TBranch        *b_PrunedMassAK8;   //!
   TBranch        *b_tau1AK8;   //!
   TBranch        *b_tau2AK8;   //!
   TBranch        *b_tau3AK8;   //!
   TBranch        *b_csvAK8;   //!
   TBranch        *b_partonFlavourAK8;   //!
   TBranch        *b_hadronFlavourAK8;   //!
   TBranch        *b_doubleBAK8;   //!
   TBranch        *b_sj0CSVAK8;   //!
   TBranch        *b_sj1CSVAK8;   //!
   TBranch        *b_hadronFlavourSJ0AK8;   //!
   TBranch        *b_hadronFlavourSJ1AK8;   //!
   TBranch        *b_sj0ptAK8;   //!
   TBranch        *b_sj1ptAK8;   //!
   TBranch        *b_sj0etaAK8;   //!
   TBranch        *b_sj1etaAK8;   //!
   TBranch        *b_sj0phiAK8;   //!
   TBranch        *b_sj1phiAK8;   //!
   TBranch        *b_sj0EnergyAK8;   //!
   TBranch        *b_sj1EnergyAK8;   //!
   TBranch        *b_idxHTagged;   //!
   TBranch        *b_ptHTagged;   //!
   TBranch        *b_etaHTagged;   //!
   TBranch        *b_phiHTagged;   //!
   TBranch        *b_MHTagged;   //!
   TBranch        *b_SoftDropMassHTagged;   //!
   TBranch        *b_PrunedMassHTagged;   //!
   TBranch        *b_tau1HTagged;   //!
   TBranch        *b_tau2HTagged;   //!
   TBranch        *b_tau3HTagged;   //!
   TBranch        *b_csvHTagged;   //!
   TBranch        *b_partonFlavourHTagged;   //!
   TBranch        *b_hadronFlavourHTagged;   //!
   TBranch        *b_doubleBHTagged;   //!
   TBranch        *b_sj0CSVHTagged;   //!
   TBranch        *b_sj1CSVHTagged;   //!
   TBranch        *b_hadronFlavourSJ0HTagged;   //!
   TBranch        *b_hadronFlavourSJ1HTagged;   //!
   TBranch        *b_sj0ptHTagged;   //!
   TBranch        *b_sj1ptHTagged;   //!
   TBranch        *b_sj0etaHTagged;   //!
   TBranch        *b_sj1etaHTagged;   //!
   TBranch        *b_sj0phiHTagged;   //!
   TBranch        *b_sj1phiHTagged;   //!
   TBranch        *b_sj0EnergyHTagged;   //!
   TBranch        *b_sj1EnergyHTagged;   //!
   TBranch        *b_idxAntiHTagged;   //!
   TBranch        *b_ptAntiHTagged;   //!
   TBranch        *b_etaAntiHTagged;   //!
   TBranch        *b_phiAntiHTagged;   //!
   TBranch        *b_MAntiHTagged;   //!
   TBranch        *b_SoftDropMassAntiHTagged;   //!
   TBranch        *b_PrunedMassAntiHTagged;   //!
   TBranch        *b_tau1AntiHTagged;   //!
   TBranch        *b_tau2AntiHTagged;   //!
   TBranch        *b_tau3AntiHTagged;   //!
   TBranch        *b_csvAntiHTagged;   //!
   TBranch        *b_partonFlavourAntiHTagged;   //!
   TBranch        *b_hadronFlavourAntiHTagged;   //!
   TBranch        *b_doubleBAntiHTagged;   //!
   TBranch        *b_sj0CSVAntiHTagged;   //!
   TBranch        *b_sj1CSVAntiHTagged;   //!
   TBranch        *b_hadronFlavourSJ0AntiHTagged;   //!
   TBranch        *b_hadronFlavourSJ1AntiHTagged;   //!
   TBranch        *b_sj0ptAntiHTagged;   //!
   TBranch        *b_sj1ptAntiHTagged;   //!
   TBranch        *b_sj0etaAntiHTagged;   //!
   TBranch        *b_sj1etaAntiHTagged;   //!
   TBranch        *b_sj0phiAntiHTagged;   //!
   TBranch        *b_sj1phiAntiHTagged;   //!
   TBranch        *b_sj0EnergyAntiHTagged;   //!
   TBranch        *b_sj1EnergyAntiHTagged;   //!
   TBranch        *b_idxTopTagged;   //!
   TBranch        *b_ptTopTagged;   //!
   TBranch        *b_etaTopTagged;   //!
   TBranch        *b_phiTopTagged;   //!
   TBranch        *b_MTopTagged;   //!
   TBranch        *b_SoftDropMassTopTagged;   //!
   TBranch        *b_PrunedMassTopTagged;   //!
   TBranch        *b_tau1TopTagged;   //!
   TBranch        *b_tau2TopTagged;   //!
   TBranch        *b_tau3TopTagged;   //!
   TBranch        *b_csvTopTagged;   //!
   TBranch        *b_partonFlavourTopTagged;   //!
   TBranch        *b_hadronFlavourTopTagged;   //!
   TBranch        *b_doubleBTopTagged;   //!
   TBranch        *b_sj0CSVTopTagged;   //!
   TBranch        *b_sj1CSVTopTagged;   //!
   TBranch        *b_hadronFlavourSJ0TopTagged;   //!
   TBranch        *b_hadronFlavourSJ1TopTagged;   //!
   TBranch        *b_sj0ptTopTagged;   //!
   TBranch        *b_sj1ptTopTagged;   //!
   TBranch        *b_sj0etaTopTagged;   //!
   TBranch        *b_sj1etaTopTagged;   //!
   TBranch        *b_sj0phiTopTagged;   //!
   TBranch        *b_sj1phiTopTagged;   //!
   TBranch        *b_sj0EnergyTopTagged;   //!
   TBranch        *b_sj1EnergyTopTagged;   //!
   TBranch        *b_idxAntiTopTagged;   //!
   TBranch        *b_ptAntiTopTagged;   //!
   TBranch        *b_etaAntiTopTagged;   //!
   TBranch        *b_phiAntiTopTagged;   //!
   TBranch        *b_MAntiTopTagged;   //!
   TBranch        *b_SoftDropMassAntiTopTagged;   //!
   TBranch        *b_PrunedMassAntiTopTagged;   //!
   TBranch        *b_tau1AntiTopTagged;   //!
   TBranch        *b_tau2AntiTopTagged;   //!
   TBranch        *b_tau3AntiTopTagged;   //!
   TBranch        *b_csvAntiTopTagged;   //!
   TBranch        *b_partonFlavourAntiTopTagged;   //!
   TBranch        *b_hadronFlavourAntiTopTagged;   //!
   TBranch        *b_doubleBAntiTopTagged;   //!
   TBranch        *b_sj0CSVAntiTopTagged;   //!
   TBranch        *b_sj1CSVAntiTopTagged;   //!
   TBranch        *b_hadronFlavourSJ0AntiTopTagged;   //!
   TBranch        *b_hadronFlavourSJ1AntiTopTagged;   //!
   TBranch        *b_sj0ptAntiTopTagged;   //!
   TBranch        *b_sj1ptAntiTopTagged;   //!
   TBranch        *b_sj0etaAntiTopTagged;   //!
   TBranch        *b_sj1etaAntiTopTagged;   //!
   TBranch        *b_sj0phiAntiTopTagged;   //!
   TBranch        *b_sj1phiAntiTopTagged;   //!
   TBranch        *b_sj0EnergyAntiTopTagged;   //!
   TBranch        *b_sj1EnergyAntiTopTagged;   //!
   TBranch        *b_idxZTagged;   //!
   TBranch        *b_ptZTagged;   //!
   TBranch        *b_etaZTagged;   //!
   TBranch        *b_phiZTagged;   //!
   TBranch        *b_MZTagged;   //!
   TBranch        *b_SoftDropMassZTagged;   //!
   TBranch        *b_PrunedMassZTagged;   //!
   TBranch        *b_tau1ZTagged;   //!
   TBranch        *b_tau2ZTagged;   //!
   TBranch        *b_tau3ZTagged;   //!
   TBranch        *b_csvZTagged;   //!
   TBranch        *b_partonFlavourZTagged;   //!
   TBranch        *b_hadronFlavourZTagged;   //!
   TBranch        *b_doubleBZTagged;   //!
   TBranch        *b_sj0CSVZTagged;   //!
   TBranch        *b_sj1CSVZTagged;   //!
   TBranch        *b_hadronFlavourSJ0ZTagged;   //!
   TBranch        *b_hadronFlavourSJ1ZTagged;   //!
   TBranch        *b_sj0ptZTagged;   //!
   TBranch        *b_sj1ptZTagged;   //!
   TBranch        *b_sj0etaZTagged;   //!
   TBranch        *b_sj1etaZTagged;   //!
   TBranch        *b_sj0phiZTagged;   //!
   TBranch        *b_sj1phiZTagged;   //!
   TBranch        *b_sj0EnergyZTagged;   //!
   TBranch        *b_sj1EnergyZTagged;   //!
   TBranch        *b_idxAntiZTagged;   //!
   TBranch        *b_ptAntiZTagged;   //!
   TBranch        *b_etaAntiZTagged;   //!
   TBranch        *b_phiAntiZTagged;   //!
   TBranch        *b_MAntiZTagged;   //!
   TBranch        *b_SoftDropMassAntiZTagged;   //!
   TBranch        *b_PrunedMassAntiZTagged;   //!
   TBranch        *b_tau1AntiZTagged;   //!
   TBranch        *b_tau2AntiZTagged;   //!
   TBranch        *b_tau3AntiZTagged;   //!
   TBranch        *b_csvAntiZTagged;   //!
   TBranch        *b_partonFlavourAntiZTagged;   //!
   TBranch        *b_hadronFlavourAntiZTagged;   //!
   TBranch        *b_doubleBAntiZTagged;   //!
   TBranch        *b_sj0CSVAntiZTagged;   //!
   TBranch        *b_sj1CSVAntiZTagged;   //!
   TBranch        *b_hadronFlavourSJ0AntiZTagged;   //!
   TBranch        *b_hadronFlavourSJ1AntiZTagged;   //!
   TBranch        *b_sj0ptAntiZTagged;   //!
   TBranch        *b_sj1ptAntiZTagged;   //!
   TBranch        *b_sj0etaAntiZTagged;   //!
   TBranch        *b_sj1etaAntiZTagged;   //!
   TBranch        *b_sj0phiAntiZTagged;   //!
   TBranch        *b_sj1phiAntiZTagged;   //!
   TBranch        *b_sj0EnergyAntiZTagged;   //!
   TBranch        *b_sj1EnergyAntiZTagged;   //!
   TBranch        *b_idxEl;   //!
   TBranch        *b_ptEl;   //!
   TBranch        *b_etaEl;   //!
   TBranch        *b_phiEl;   //!
   TBranch        *b_EEl;   //!
   TBranch        *b_IsoDREl;   //!
   TBranch        *b_dR_Iso2DEl;   //!
   TBranch        *b_ptrel_Iso2DEl;   //!
   TBranch        *b_IsoDRAfterIso2DEl;   //!
   TBranch        *b_idxCleanedEl;   //!
   TBranch        *b_ptCleanedEl;   //!
   TBranch        *b_etaCleanedEl;   //!
   TBranch        *b_phiCleanedEl;   //!
   TBranch        *b_ECleanedEl;   //!
   TBranch        *b_idxMu;   //!
   TBranch        *b_ptMu;   //!
   TBranch        *b_etaMu;   //!
   TBranch        *b_phiMu;   //!
   TBranch        *b_EMu;   //!
   TBranch        *b_IsoDRMu;   //!
   TBranch        *b_dR_Iso2DMu;   //!
   TBranch        *b_ptrel_Iso2DMu;   //!
   TBranch        *b_IsoDRAfterIso2DMu;   //!
   TBranch        *b_idxCleanedMu;   //!
   TBranch        *b_ptCleanedMu;   //!
   TBranch        *b_etaCleanedMu;   //!
   TBranch        *b_phiCleanedMu;   //!
   TBranch        *b_ECleanedMu;   //!

   InputTreeBase(TTree *tree=0);
   virtual ~InputTreeBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif


inline InputTreeBase::InputTreeBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TTJets.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("TTJets.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("TTJets.root:/anaCHS");
      dir->GetObject("tree",tree);

   }
   Init(tree);
}

inline InputTreeBase::~InputTreeBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t InputTreeBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t InputTreeBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

inline void InputTreeBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   SelectedEvent_trigBit = 0;
   SelectedEvent_trigName = 0;
   idxAK4 = 0;
   ptAK4 = 0;
   etaAK4 = 0;
   phiAK4 = 0;
   MAK4 = 0;
   csvAK4 = 0;
   partonFlavourAK4 = 0;
   hadronFlavourAK4 = 0;
   idxExtraAK4 = 0;
   ptExtraAK4 = 0;
   etaExtraAK4 = 0;
   phiExtraAK4 = 0;
   MExtraAK4 = 0;
   csvExtraAK4 = 0;
   partonFlavourExtraAK4 = 0;
   hadronFlavourExtraAK4 = 0;
   idxAK8 = 0;
   ptAK8 = 0;
   etaAK8 = 0;
   phiAK8 = 0;
   MAK8 = 0;
   SoftDropMassAK8 = 0;
   PrunedMassAK8 = 0;
   tau1AK8 = 0;
   tau2AK8 = 0;
   tau3AK8 = 0;
   csvAK8 = 0;
   partonFlavourAK8 = 0;
   hadronFlavourAK8 = 0;
   doubleBAK8 = 0;
   sj0CSVAK8 = 0;
   sj1CSVAK8 = 0;
   hadronFlavourSJ0AK8 = 0;
   hadronFlavourSJ1AK8 = 0;
   sj0ptAK8 = 0;
   sj1ptAK8 = 0;
   sj0etaAK8 = 0;
   sj1etaAK8 = 0;
   sj0phiAK8 = 0;
   sj1phiAK8 = 0;
   sj0EnergyAK8 = 0;
   sj1EnergyAK8 = 0;
   idxHTagged = 0;
   ptHTagged = 0;
   etaHTagged = 0;
   phiHTagged = 0;
   MHTagged = 0;
   SoftDropMassHTagged = 0;
   PrunedMassHTagged = 0;
   tau1HTagged = 0;
   tau2HTagged = 0;
   tau3HTagged = 0;
   csvHTagged = 0;
   partonFlavourHTagged = 0;
   hadronFlavourHTagged = 0;
   doubleBHTagged = 0;
   sj0CSVHTagged = 0;
   sj1CSVHTagged = 0;
   hadronFlavourSJ0HTagged = 0;
   hadronFlavourSJ1HTagged = 0;
   sj0ptHTagged = 0;
   sj1ptHTagged = 0;
   sj0etaHTagged = 0;
   sj1etaHTagged = 0;
   sj0phiHTagged = 0;
   sj1phiHTagged = 0;
   sj0EnergyHTagged = 0;
   sj1EnergyHTagged = 0;
   idxAntiHTagged = 0;
   ptAntiHTagged = 0;
   etaAntiHTagged = 0;
   phiAntiHTagged = 0;
   MAntiHTagged = 0;
   SoftDropMassAntiHTagged = 0;
   PrunedMassAntiHTagged = 0;
   tau1AntiHTagged = 0;
   tau2AntiHTagged = 0;
   tau3AntiHTagged = 0;
   csvAntiHTagged = 0;
   partonFlavourAntiHTagged = 0;
   hadronFlavourAntiHTagged = 0;
   doubleBAntiHTagged = 0;
   sj0CSVAntiHTagged = 0;
   sj1CSVAntiHTagged = 0;
   hadronFlavourSJ0AntiHTagged = 0;
   hadronFlavourSJ1AntiHTagged = 0;
   sj0ptAntiHTagged = 0;
   sj1ptAntiHTagged = 0;
   sj0etaAntiHTagged = 0;
   sj1etaAntiHTagged = 0;
   sj0phiAntiHTagged = 0;
   sj1phiAntiHTagged = 0;
   sj0EnergyAntiHTagged = 0;
   sj1EnergyAntiHTagged = 0;
   idxTopTagged = 0;
   ptTopTagged = 0;
   etaTopTagged = 0;
   phiTopTagged = 0;
   MTopTagged = 0;
   SoftDropMassTopTagged = 0;
   PrunedMassTopTagged = 0;
   tau1TopTagged = 0;
   tau2TopTagged = 0;
   tau3TopTagged = 0;
   csvTopTagged = 0;
   partonFlavourTopTagged = 0;
   hadronFlavourTopTagged = 0;
   doubleBTopTagged = 0;
   sj0CSVTopTagged = 0;
   sj1CSVTopTagged = 0;
   hadronFlavourSJ0TopTagged = 0;
   hadronFlavourSJ1TopTagged = 0;
   sj0ptTopTagged = 0;
   sj1ptTopTagged = 0;
   sj0etaTopTagged = 0;
   sj1etaTopTagged = 0;
   sj0phiTopTagged = 0;
   sj1phiTopTagged = 0;
   sj0EnergyTopTagged = 0;
   sj1EnergyTopTagged = 0;
   idxAntiTopTagged = 0;
   ptAntiTopTagged = 0;
   etaAntiTopTagged = 0;
   phiAntiTopTagged = 0;
   MAntiTopTagged = 0;
   SoftDropMassAntiTopTagged = 0;
   PrunedMassAntiTopTagged = 0;
   tau1AntiTopTagged = 0;
   tau2AntiTopTagged = 0;
   tau3AntiTopTagged = 0;
   csvAntiTopTagged = 0;
   partonFlavourAntiTopTagged = 0;
   hadronFlavourAntiTopTagged = 0;
   doubleBAntiTopTagged = 0;
   sj0CSVAntiTopTagged = 0;
   sj1CSVAntiTopTagged = 0;
   hadronFlavourSJ0AntiTopTagged = 0;
   hadronFlavourSJ1AntiTopTagged = 0;
   sj0ptAntiTopTagged = 0;
   sj1ptAntiTopTagged = 0;
   sj0etaAntiTopTagged = 0;
   sj1etaAntiTopTagged = 0;
   sj0phiAntiTopTagged = 0;
   sj1phiAntiTopTagged = 0;
   sj0EnergyAntiTopTagged = 0;
   sj1EnergyAntiTopTagged = 0;
   idxZTagged = 0;
   ptZTagged = 0;
   etaZTagged = 0;
   phiZTagged = 0;
   MZTagged = 0;
   SoftDropMassZTagged = 0;
   PrunedMassZTagged = 0;
   tau1ZTagged = 0;
   tau2ZTagged = 0;
   tau3ZTagged = 0;
   csvZTagged = 0;
   partonFlavourZTagged = 0;
   hadronFlavourZTagged = 0;
   doubleBZTagged = 0;
   sj0CSVZTagged = 0;
   sj1CSVZTagged = 0;
   hadronFlavourSJ0ZTagged = 0;
   hadronFlavourSJ1ZTagged = 0;
   sj0ptZTagged = 0;
   sj1ptZTagged = 0;
   sj0etaZTagged = 0;
   sj1etaZTagged = 0;
   sj0phiZTagged = 0;
   sj1phiZTagged = 0;
   sj0EnergyZTagged = 0;
   sj1EnergyZTagged = 0;
   idxAntiZTagged = 0;
   ptAntiZTagged = 0;
   etaAntiZTagged = 0;
   phiAntiZTagged = 0;
   MAntiZTagged = 0;
   SoftDropMassAntiZTagged = 0;
   PrunedMassAntiZTagged = 0;
   tau1AntiZTagged = 0;
   tau2AntiZTagged = 0;
   tau3AntiZTagged = 0;
   csvAntiZTagged = 0;
   partonFlavourAntiZTagged = 0;
   hadronFlavourAntiZTagged = 0;
   doubleBAntiZTagged = 0;
   sj0CSVAntiZTagged = 0;
   sj1CSVAntiZTagged = 0;
   hadronFlavourSJ0AntiZTagged = 0;
   hadronFlavourSJ1AntiZTagged = 0;
   sj0ptAntiZTagged = 0;
   sj1ptAntiZTagged = 0;
   sj0etaAntiZTagged = 0;
   sj1etaAntiZTagged = 0;
   sj0phiAntiZTagged = 0;
   sj1phiAntiZTagged = 0;
   sj0EnergyAntiZTagged = 0;
   sj1EnergyAntiZTagged = 0;
   idxEl = 0;
   ptEl = 0;
   etaEl = 0;
   phiEl = 0;
   EEl = 0;
   IsoDREl = 0;
   dR_Iso2DEl = 0;
   ptrel_Iso2DEl = 0;
   IsoDRAfterIso2DEl = 0;
   idxCleanedEl = 0;
   ptCleanedEl = 0;
   etaCleanedEl = 0;
   phiCleanedEl = 0;
   ECleanedEl = 0;
   idxMu = 0;
   ptMu = 0;
   etaMu = 0;
   phiMu = 0;
   EMu = 0;
   IsoDRMu = 0;
   dR_Iso2DMu = 0;
   ptrel_Iso2DMu = 0;
   IsoDRAfterIso2DMu = 0;
   idxCleanedMu = 0;
   ptCleanedMu = 0;
   etaCleanedMu = 0;
   phiCleanedMu = 0;
   ECleanedMu = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchStatus("SelectedEvent_lhewts*", 0);
   fChain->SetBranchStatus("SelectedEvent_trigBit", 0);
   fChain->SetBranchStatus("SelectedEvent_trigName", 0);

   fChain->SetBranchAddress("SelectedEvent_runno", &SelectedEvent_runno, &b_SelectedEvent_runno);
   fChain->SetBranchAddress("SelectedEvent_lumisec", &SelectedEvent_lumisec, &b_SelectedEvent_lumisec);
   fChain->SetBranchAddress("SelectedEvent_evtno", &SelectedEvent_evtno, &b_SelectedEvent_evtno);
   fChain->SetBranchAddress("SelectedEvent_bcno", &SelectedEvent_bcno, &b_SelectedEvent_bcno);
   fChain->SetBranchAddress("SelectedEvent_time", &SelectedEvent_time, &b_SelectedEvent_time);
   fChain->SetBranchAddress("SelectedEvent_htHat", &SelectedEvent_htHat, &b_SelectedEvent_htHat);
   fChain->SetBranchAddress("SelectedEvent_EvtWeight", &SelectedEvent_EvtWeight, &b_EvtWeight);
   fChain->SetBranchAddress("SelectedEvent_EvtWtPV", &SelectedEvent_EvtWtPV, &b_EvtWtPV);
   fChain->SetBranchAddress("SelectedEvent_EvtWtPVBG", &SelectedEvent_EvtWtPVBG, &b_EvtWtPVBG);
   fChain->SetBranchAddress("SelectedEvent_EvtWtPVH", &SelectedEvent_EvtWtPVH, &b_EvtWtPVH);
   fChain->SetBranchAddress("SelectedEvent_EvtWtPVLow", &SelectedEvent_EvtWtPVLow, &b_EvtWtPVLow);
   fChain->SetBranchAddress("SelectedEvent_EvtWtPVHigh", &SelectedEvent_EvtWtPVHigh, &b_EvtWtPVHigh);
   fChain->SetBranchAddress("SelectedEvent_EvtWtHT", &SelectedEvent_EvtWtHT, &b_EvtWtHT);
   fChain->SetBranchAddress("SelectedEvent_EvtWtHTUp", &SelectedEvent_EvtWtHTUp, &b_EvtWtHTUp);
   fChain->SetBranchAddress("SelectedEvent_EvtWtHTDown", &SelectedEvent_EvtWtHTDown, &b_EvtWtHTDown);
   fChain->SetBranchAddress("SelectedEvent_npv", &SelectedEvent_npv, &b_npv);
   fChain->SetBranchAddress("SelectedEvent_npuTrue", &SelectedEvent_npuTrue, &b_npuTrue);
   fChain->SetBranchAddress("SelectedEvent_toptagsf", &SelectedEvent_toptagsf, &b_toptagsf);
   fChain->SetBranchAddress("SelectedEvent_toptagsf_Up", &SelectedEvent_toptagsf_Up, &b_toptagsf_Up);
   fChain->SetBranchAddress("SelectedEvent_toptagsf_Down", &SelectedEvent_toptagsf_Down, &b_toptagsf_Down);
   fChain->SetBranchAddress("SelectedEvent_btagsf", &SelectedEvent_btagsf, &b_btagsf);
   fChain->SetBranchAddress("SelectedEvent_btagsf_bcUp", &SelectedEvent_btagsf_bcUp, &b_btagsf_bcUp);
   fChain->SetBranchAddress("SelectedEvent_btagsf_bcDown", &SelectedEvent_btagsf_bcDown, &b_btagsf_bcDown);
   fChain->SetBranchAddress("SelectedEvent_btagsf_lUp", &SelectedEvent_btagsf_lUp, &b_btagsf_lUp);
   fChain->SetBranchAddress("SelectedEvent_btagsf_lDown", &SelectedEvent_btagsf_lDown, &b_btagsf_lDown);
   fChain->SetBranchAddress("SelectedEvent_mtprime", &SelectedEvent_mtprime, &b_mtprime);
   fChain->SetBranchAddress("SelectedEvent_mtprimeDummy", &SelectedEvent_mtprimeDummy, &b_mtprimeDummy);
   fChain->SetBranchAddress("SelectedEvent_mtprimeDummyA", &SelectedEvent_mtprimeDummyA, &b_mtprimeDummyA);
   fChain->SetBranchAddress("SelectedEvent_mtprimeDummyC", &SelectedEvent_mtprimeDummyC, &b_mtprimeDummyC);
   fChain->SetBranchAddress("SelectedEvent_mtprime_corr", &SelectedEvent_mtprime_corr, &b_mtprime_corr);
   fChain->SetBranchAddress("SelectedEvent_mtprimeDummy_corr", &SelectedEvent_mtprimeDummy_corr, &b_mtprimeDummy_corr);
   fChain->SetBranchAddress("SelectedEvent_mtprimeDummyA_corr", &SelectedEvent_mtprimeDummyA_corr, &b_mtprimeDummyA_corr);
   fChain->SetBranchAddress("SelectedEvent_mtprimeDummyC_corr", &SelectedEvent_mtprimeDummyC_corr, &b_mtprimeDummyC_corr);
   fChain->SetBranchAddress("SelectedEvent_ht", &SelectedEvent_ht, &b_ht);
   fChain->SetBranchAddress("SelectedEvent_nAK4", &SelectedEvent_nAK4, &b_nAK4);
   fChain->SetBranchAddress("SelectedEvent_nAK8", &SelectedEvent_nAK8, &b_nAK8);
   fChain->SetBranchAddress("SelectedEvent_nEl", &SelectedEvent_nEl, &b_nEl);
   fChain->SetBranchAddress("SelectedEvent_nMu", &SelectedEvent_nMu, &b_nMu);
   fChain->SetBranchAddress("SelectedEvent_nCleanedEl", &SelectedEvent_nCleanedEl, &b_nCleanedEl);
   fChain->SetBranchAddress("SelectedEvent_nCleanedMu", &SelectedEvent_nCleanedMu, &b_nCleanedMu);
   fChain->SetBranchAddress("SelectedEvent_isRegionA", &SelectedEvent_isRegionA, &b_isRegionA);
   fChain->SetBranchAddress("SelectedEvent_isRegionB", &SelectedEvent_isRegionB, &b_isRegionB);
   fChain->SetBranchAddress("SelectedEvent_isRegionC", &SelectedEvent_isRegionC, &b_isRegionC);
   fChain->SetBranchAddress("SelectedEvent_isRegionD", &SelectedEvent_isRegionD, &b_isRegionD);
   fChain->SetBranchAddress("SelectedEvent_isRegionNotABCD", &SelectedEvent_isRegionNotABCD, &b_isRegionNotABCD);
   /* fChain->SetBranchAddress("SelectedEvent_lhewts", &SelectedEvent_lhewts_, &b_SelectedEvent_lhewts_); */
   /* fChain->SetBranchAddress("SelectedEvent_lhewts.first", SelectedEvent_lhewts_first, &b_SelectedEvent_lhewts_first); */
   /* fChain->SetBranchAddress("SelectedEvent_lhewts.second", SelectedEvent_lhewts_second, &b_SelectedEvent_lhewts_second); */
   fChain->SetBranchAddress("SelectedEvent_trigBit", &SelectedEvent_trigBit, &b_SelectedEvent_trigBit);
   fChain->SetBranchAddress("SelectedEvent_trigName", &SelectedEvent_trigName, &b_SelectedEvent_trigName);
   fChain->SetBranchAddress("SelectedEvent_isotropy", &SelectedEvent_isotropy, &b_isotropy);
   fChain->SetBranchAddress("SelectedEvent_circularity", &SelectedEvent_circularity, &b_circularity);
   fChain->SetBranchAddress("SelectedEvent_sphericity", &SelectedEvent_sphericity, &b_sphericity);
   fChain->SetBranchAddress("SelectedEvent_aplanarity", &SelectedEvent_aplanarity, &b_aplanarity);
   fChain->SetBranchAddress("SelectedEvent_C", &SelectedEvent_C, &b_C);
   fChain->SetBranchAddress("SelectedEvent_D", &SelectedEvent_D, &b_D);
   fChain->SetBranchAddress("SelectedEvent_thrust", &SelectedEvent_thrust, &b_thrust);
   fChain->SetBranchAddress("SelectedEvent_thrustminor", &SelectedEvent_thrustminor, &b_thrustminor);
   fChain->SetBranchAddress("SelectedEvent_isotropy_ExtraAK4", &SelectedEvent_isotropy_ExtraAK4, &b_isotropy_ExtraAK4_);
   fChain->SetBranchAddress("SelectedEvent_circularity_ExtraAK4", &SelectedEvent_circularity_ExtraAK4, &b_circularity_ExtraAK4_);
   fChain->SetBranchAddress("SelectedEvent_sphericity_ExtraAK4", &SelectedEvent_sphericity_ExtraAK4, &b_sphericity_ExtraAK4_);
   fChain->SetBranchAddress("SelectedEvent_aplanarity_ExtraAK4", &SelectedEvent_aplanarity_ExtraAK4, &b_aplanarity_ExtraAK4_);
   fChain->SetBranchAddress("SelectedEvent_C_ExtraAK4", &SelectedEvent_C_ExtraAK4, &b_C_ExtraAK4_);
   fChain->SetBranchAddress("SelectedEvent_D_ExtraAK4", &SelectedEvent_D_ExtraAK4, &b_D_ExtraAK4_);
   fChain->SetBranchAddress("SelectedEvent_thrust_ExtraAK4", &SelectedEvent_thrust_ExtraAK4, &b_thrust_ExtraAK4_);
   fChain->SetBranchAddress("SelectedEvent_thrustminor_ExtraAK4", &SelectedEvent_thrustminor_ExtraAK4, &b_thrustminor_ExtraAK4_);
   fChain->SetBranchAddress("SelectedEvent_cosThetaT", &SelectedEvent_cosThetaT, &b_cosThetaT_);
   fChain->SetBranchAddress("idxAK4", &idxAK4, &b_idxAK4);
   fChain->SetBranchAddress("ptAK4", &ptAK4, &b_ptAK4);
   fChain->SetBranchAddress("etaAK4", &etaAK4, &b_etaAK4);
   fChain->SetBranchAddress("phiAK4", &phiAK4, &b_phiAK4);
   fChain->SetBranchAddress("MAK4", &MAK4, &b_MAK4);
   fChain->SetBranchAddress("csvAK4", &csvAK4, &b_csvAK4);
   fChain->SetBranchAddress("partonFlavourAK4", &partonFlavourAK4, &b_partonFlavourAK4);
   fChain->SetBranchAddress("hadronFlavourAK4", &hadronFlavourAK4, &b_hadronFlavourAK4);
   fChain->SetBranchAddress("idxExtraAK4", &idxExtraAK4, &b_idxExtraAK4);
   fChain->SetBranchAddress("ptExtraAK4", &ptExtraAK4, &b_ptExtraAK4);
   fChain->SetBranchAddress("etaExtraAK4", &etaExtraAK4, &b_etaExtraAK4);
   fChain->SetBranchAddress("phiExtraAK4", &phiExtraAK4, &b_phiExtraAK4);
   fChain->SetBranchAddress("MExtraAK4", &MExtraAK4, &b_MExtraAK4);
   fChain->SetBranchAddress("csvExtraAK4", &csvExtraAK4, &b_csvExtraAK4);
   fChain->SetBranchAddress("partonFlavourExtraAK4", &partonFlavourExtraAK4, &b_partonFlavourExtraAK4);
   fChain->SetBranchAddress("hadronFlavourExtraAK4", &hadronFlavourExtraAK4, &b_hadronFlavourExtraAK4);
   fChain->SetBranchAddress("idxAK8", &idxAK8, &b_idxAK8);
   fChain->SetBranchAddress("ptAK8", &ptAK8, &b_ptAK8);
   fChain->SetBranchAddress("etaAK8", &etaAK8, &b_etaAK8);
   fChain->SetBranchAddress("phiAK8", &phiAK8, &b_phiAK8);
   fChain->SetBranchAddress("MAK8", &MAK8, &b_MAK8);
   fChain->SetBranchAddress("SoftDropMassAK8", &SoftDropMassAK8, &b_SoftDropMassAK8);
   fChain->SetBranchAddress("PrunedMassAK8", &PrunedMassAK8, &b_PrunedMassAK8);
   fChain->SetBranchAddress("tau1AK8", &tau1AK8, &b_tau1AK8);
   fChain->SetBranchAddress("tau2AK8", &tau2AK8, &b_tau2AK8);
   fChain->SetBranchAddress("tau3AK8", &tau3AK8, &b_tau3AK8);
   fChain->SetBranchAddress("csvAK8", &csvAK8, &b_csvAK8);
   fChain->SetBranchAddress("partonFlavourAK8", &partonFlavourAK8, &b_partonFlavourAK8);
   fChain->SetBranchAddress("hadronFlavourAK8", &hadronFlavourAK8, &b_hadronFlavourAK8);
   fChain->SetBranchAddress("doubleBAK8", &doubleBAK8, &b_doubleBAK8);
   fChain->SetBranchAddress("sj0CSVAK8", &sj0CSVAK8, &b_sj0CSVAK8);
   fChain->SetBranchAddress("sj1CSVAK8", &sj1CSVAK8, &b_sj1CSVAK8);
   fChain->SetBranchAddress("hadronFlavourSJ0AK8", &hadronFlavourSJ0AK8, &b_hadronFlavourSJ0AK8);
   fChain->SetBranchAddress("hadronFlavourSJ1AK8", &hadronFlavourSJ1AK8, &b_hadronFlavourSJ1AK8);
   fChain->SetBranchAddress("sj0ptAK8", &sj0ptAK8, &b_sj0ptAK8);
   fChain->SetBranchAddress("sj1ptAK8", &sj1ptAK8, &b_sj1ptAK8);
   fChain->SetBranchAddress("sj0etaAK8", &sj0etaAK8, &b_sj0etaAK8);
   fChain->SetBranchAddress("sj1etaAK8", &sj1etaAK8, &b_sj1etaAK8);
   fChain->SetBranchAddress("sj0phiAK8", &sj0phiAK8, &b_sj0phiAK8);
   fChain->SetBranchAddress("sj1phiAK8", &sj1phiAK8, &b_sj1phiAK8);
   fChain->SetBranchAddress("sj0EnergyAK8", &sj0EnergyAK8, &b_sj0EnergyAK8);
   fChain->SetBranchAddress("sj1EnergyAK8", &sj1EnergyAK8, &b_sj1EnergyAK8);
   fChain->SetBranchAddress("idxHTagged", &idxHTagged, &b_idxHTagged);
   fChain->SetBranchAddress("ptHTagged", &ptHTagged, &b_ptHTagged);
   fChain->SetBranchAddress("etaHTagged", &etaHTagged, &b_etaHTagged);
   fChain->SetBranchAddress("phiHTagged", &phiHTagged, &b_phiHTagged);
   fChain->SetBranchAddress("MHTagged", &MHTagged, &b_MHTagged);
   fChain->SetBranchAddress("SoftDropMassHTagged", &SoftDropMassHTagged, &b_SoftDropMassHTagged);
   fChain->SetBranchAddress("PrunedMassHTagged", &PrunedMassHTagged, &b_PrunedMassHTagged);
   fChain->SetBranchAddress("tau1HTagged", &tau1HTagged, &b_tau1HTagged);
   fChain->SetBranchAddress("tau2HTagged", &tau2HTagged, &b_tau2HTagged);
   fChain->SetBranchAddress("tau3HTagged", &tau3HTagged, &b_tau3HTagged);
   fChain->SetBranchAddress("csvHTagged", &csvHTagged, &b_csvHTagged);
   fChain->SetBranchAddress("partonFlavourHTagged", &partonFlavourHTagged, &b_partonFlavourHTagged);
   fChain->SetBranchAddress("hadronFlavourHTagged", &hadronFlavourHTagged, &b_hadronFlavourHTagged);
   fChain->SetBranchAddress("doubleBHTagged", &doubleBHTagged, &b_doubleBHTagged);
   fChain->SetBranchAddress("sj0CSVHTagged", &sj0CSVHTagged, &b_sj0CSVHTagged);
   fChain->SetBranchAddress("sj1CSVHTagged", &sj1CSVHTagged, &b_sj1CSVHTagged);
   fChain->SetBranchAddress("hadronFlavourSJ0HTagged", &hadronFlavourSJ0HTagged, &b_hadronFlavourSJ0HTagged);
   fChain->SetBranchAddress("hadronFlavourSJ1HTagged", &hadronFlavourSJ1HTagged, &b_hadronFlavourSJ1HTagged);
   fChain->SetBranchAddress("sj0ptHTagged", &sj0ptHTagged, &b_sj0ptHTagged);
   fChain->SetBranchAddress("sj1ptHTagged", &sj1ptHTagged, &b_sj1ptHTagged);
   fChain->SetBranchAddress("sj0etaHTagged", &sj0etaHTagged, &b_sj0etaHTagged);
   fChain->SetBranchAddress("sj1etaHTagged", &sj1etaHTagged, &b_sj1etaHTagged);
   fChain->SetBranchAddress("sj0phiHTagged", &sj0phiHTagged, &b_sj0phiHTagged);
   fChain->SetBranchAddress("sj1phiHTagged", &sj1phiHTagged, &b_sj1phiHTagged);
   fChain->SetBranchAddress("sj0EnergyHTagged", &sj0EnergyHTagged, &b_sj0EnergyHTagged);
   fChain->SetBranchAddress("sj1EnergyHTagged", &sj1EnergyHTagged, &b_sj1EnergyHTagged);
   fChain->SetBranchAddress("idxAntiHTagged", &idxAntiHTagged, &b_idxAntiHTagged);
   fChain->SetBranchAddress("ptAntiHTagged", &ptAntiHTagged, &b_ptAntiHTagged);
   fChain->SetBranchAddress("etaAntiHTagged", &etaAntiHTagged, &b_etaAntiHTagged);
   fChain->SetBranchAddress("phiAntiHTagged", &phiAntiHTagged, &b_phiAntiHTagged);
   fChain->SetBranchAddress("MAntiHTagged", &MAntiHTagged, &b_MAntiHTagged);
   fChain->SetBranchAddress("SoftDropMassAntiHTagged", &SoftDropMassAntiHTagged, &b_SoftDropMassAntiHTagged);
   fChain->SetBranchAddress("PrunedMassAntiHTagged", &PrunedMassAntiHTagged, &b_PrunedMassAntiHTagged);
   fChain->SetBranchAddress("tau1AntiHTagged", &tau1AntiHTagged, &b_tau1AntiHTagged);
   fChain->SetBranchAddress("tau2AntiHTagged", &tau2AntiHTagged, &b_tau2AntiHTagged);
   fChain->SetBranchAddress("tau3AntiHTagged", &tau3AntiHTagged, &b_tau3AntiHTagged);
   fChain->SetBranchAddress("csvAntiHTagged", &csvAntiHTagged, &b_csvAntiHTagged);
   fChain->SetBranchAddress("partonFlavourAntiHTagged", &partonFlavourAntiHTagged, &b_partonFlavourAntiHTagged);
   fChain->SetBranchAddress("hadronFlavourAntiHTagged", &hadronFlavourAntiHTagged, &b_hadronFlavourAntiHTagged);
   fChain->SetBranchAddress("doubleBAntiHTagged", &doubleBAntiHTagged, &b_doubleBAntiHTagged);
   fChain->SetBranchAddress("sj0CSVAntiHTagged", &sj0CSVAntiHTagged, &b_sj0CSVAntiHTagged);
   fChain->SetBranchAddress("sj1CSVAntiHTagged", &sj1CSVAntiHTagged, &b_sj1CSVAntiHTagged);
   fChain->SetBranchAddress("hadronFlavourSJ0AntiHTagged", &hadronFlavourSJ0AntiHTagged, &b_hadronFlavourSJ0AntiHTagged);
   fChain->SetBranchAddress("hadronFlavourSJ1AntiHTagged", &hadronFlavourSJ1AntiHTagged, &b_hadronFlavourSJ1AntiHTagged);
   fChain->SetBranchAddress("sj0ptAntiHTagged", &sj0ptAntiHTagged, &b_sj0ptAntiHTagged);
   fChain->SetBranchAddress("sj1ptAntiHTagged", &sj1ptAntiHTagged, &b_sj1ptAntiHTagged);
   fChain->SetBranchAddress("sj0etaAntiHTagged", &sj0etaAntiHTagged, &b_sj0etaAntiHTagged);
   fChain->SetBranchAddress("sj1etaAntiHTagged", &sj1etaAntiHTagged, &b_sj1etaAntiHTagged);
   fChain->SetBranchAddress("sj0phiAntiHTagged", &sj0phiAntiHTagged, &b_sj0phiAntiHTagged);
   fChain->SetBranchAddress("sj1phiAntiHTagged", &sj1phiAntiHTagged, &b_sj1phiAntiHTagged);
   fChain->SetBranchAddress("sj0EnergyAntiHTagged", &sj0EnergyAntiHTagged, &b_sj0EnergyAntiHTagged);
   fChain->SetBranchAddress("sj1EnergyAntiHTagged", &sj1EnergyAntiHTagged, &b_sj1EnergyAntiHTagged);
   fChain->SetBranchAddress("idxTopTagged", &idxTopTagged, &b_idxTopTagged);
   fChain->SetBranchAddress("ptTopTagged", &ptTopTagged, &b_ptTopTagged);
   fChain->SetBranchAddress("etaTopTagged", &etaTopTagged, &b_etaTopTagged);
   fChain->SetBranchAddress("phiTopTagged", &phiTopTagged, &b_phiTopTagged);
   fChain->SetBranchAddress("MTopTagged", &MTopTagged, &b_MTopTagged);
   fChain->SetBranchAddress("SoftDropMassTopTagged", &SoftDropMassTopTagged, &b_SoftDropMassTopTagged);
   fChain->SetBranchAddress("PrunedMassTopTagged", &PrunedMassTopTagged, &b_PrunedMassTopTagged);
   fChain->SetBranchAddress("tau1TopTagged", &tau1TopTagged, &b_tau1TopTagged);
   fChain->SetBranchAddress("tau2TopTagged", &tau2TopTagged, &b_tau2TopTagged);
   fChain->SetBranchAddress("tau3TopTagged", &tau3TopTagged, &b_tau3TopTagged);
   fChain->SetBranchAddress("csvTopTagged", &csvTopTagged, &b_csvTopTagged);
   fChain->SetBranchAddress("partonFlavourTopTagged", &partonFlavourTopTagged, &b_partonFlavourTopTagged);
   fChain->SetBranchAddress("hadronFlavourTopTagged", &hadronFlavourTopTagged, &b_hadronFlavourTopTagged);
   fChain->SetBranchAddress("doubleBTopTagged", &doubleBTopTagged, &b_doubleBTopTagged);
   fChain->SetBranchAddress("sj0CSVTopTagged", &sj0CSVTopTagged, &b_sj0CSVTopTagged);
   fChain->SetBranchAddress("sj1CSVTopTagged", &sj1CSVTopTagged, &b_sj1CSVTopTagged);
   fChain->SetBranchAddress("hadronFlavourSJ0TopTagged", &hadronFlavourSJ0TopTagged, &b_hadronFlavourSJ0TopTagged);
   fChain->SetBranchAddress("hadronFlavourSJ1TopTagged", &hadronFlavourSJ1TopTagged, &b_hadronFlavourSJ1TopTagged);
   fChain->SetBranchAddress("sj0ptTopTagged", &sj0ptTopTagged, &b_sj0ptTopTagged);
   fChain->SetBranchAddress("sj1ptTopTagged", &sj1ptTopTagged, &b_sj1ptTopTagged);
   fChain->SetBranchAddress("sj0etaTopTagged", &sj0etaTopTagged, &b_sj0etaTopTagged);
   fChain->SetBranchAddress("sj1etaTopTagged", &sj1etaTopTagged, &b_sj1etaTopTagged);
   fChain->SetBranchAddress("sj0phiTopTagged", &sj0phiTopTagged, &b_sj0phiTopTagged);
   fChain->SetBranchAddress("sj1phiTopTagged", &sj1phiTopTagged, &b_sj1phiTopTagged);
   fChain->SetBranchAddress("sj0EnergyTopTagged", &sj0EnergyTopTagged, &b_sj0EnergyTopTagged);
   fChain->SetBranchAddress("sj1EnergyTopTagged", &sj1EnergyTopTagged, &b_sj1EnergyTopTagged);
   fChain->SetBranchAddress("idxAntiTopTagged", &idxAntiTopTagged, &b_idxAntiTopTagged);
   fChain->SetBranchAddress("ptAntiTopTagged", &ptAntiTopTagged, &b_ptAntiTopTagged);
   fChain->SetBranchAddress("etaAntiTopTagged", &etaAntiTopTagged, &b_etaAntiTopTagged);
   fChain->SetBranchAddress("phiAntiTopTagged", &phiAntiTopTagged, &b_phiAntiTopTagged);
   fChain->SetBranchAddress("MAntiTopTagged", &MAntiTopTagged, &b_MAntiTopTagged);
   fChain->SetBranchAddress("SoftDropMassAntiTopTagged", &SoftDropMassAntiTopTagged, &b_SoftDropMassAntiTopTagged);
   fChain->SetBranchAddress("PrunedMassAntiTopTagged", &PrunedMassAntiTopTagged, &b_PrunedMassAntiTopTagged);
   fChain->SetBranchAddress("tau1AntiTopTagged", &tau1AntiTopTagged, &b_tau1AntiTopTagged);
   fChain->SetBranchAddress("tau2AntiTopTagged", &tau2AntiTopTagged, &b_tau2AntiTopTagged);
   fChain->SetBranchAddress("tau3AntiTopTagged", &tau3AntiTopTagged, &b_tau3AntiTopTagged);
   fChain->SetBranchAddress("csvAntiTopTagged", &csvAntiTopTagged, &b_csvAntiTopTagged);
   fChain->SetBranchAddress("partonFlavourAntiTopTagged", &partonFlavourAntiTopTagged, &b_partonFlavourAntiTopTagged);
   fChain->SetBranchAddress("hadronFlavourAntiTopTagged", &hadronFlavourAntiTopTagged, &b_hadronFlavourAntiTopTagged);
   fChain->SetBranchAddress("doubleBAntiTopTagged", &doubleBAntiTopTagged, &b_doubleBAntiTopTagged);
   fChain->SetBranchAddress("sj0CSVAntiTopTagged", &sj0CSVAntiTopTagged, &b_sj0CSVAntiTopTagged);
   fChain->SetBranchAddress("sj1CSVAntiTopTagged", &sj1CSVAntiTopTagged, &b_sj1CSVAntiTopTagged);
   fChain->SetBranchAddress("hadronFlavourSJ0AntiTopTagged", &hadronFlavourSJ0AntiTopTagged, &b_hadronFlavourSJ0AntiTopTagged);
   fChain->SetBranchAddress("hadronFlavourSJ1AntiTopTagged", &hadronFlavourSJ1AntiTopTagged, &b_hadronFlavourSJ1AntiTopTagged);
   fChain->SetBranchAddress("sj0ptAntiTopTagged", &sj0ptAntiTopTagged, &b_sj0ptAntiTopTagged);
   fChain->SetBranchAddress("sj1ptAntiTopTagged", &sj1ptAntiTopTagged, &b_sj1ptAntiTopTagged);
   fChain->SetBranchAddress("sj0etaAntiTopTagged", &sj0etaAntiTopTagged, &b_sj0etaAntiTopTagged);
   fChain->SetBranchAddress("sj1etaAntiTopTagged", &sj1etaAntiTopTagged, &b_sj1etaAntiTopTagged);
   fChain->SetBranchAddress("sj0phiAntiTopTagged", &sj0phiAntiTopTagged, &b_sj0phiAntiTopTagged);
   fChain->SetBranchAddress("sj1phiAntiTopTagged", &sj1phiAntiTopTagged, &b_sj1phiAntiTopTagged);
   fChain->SetBranchAddress("sj0EnergyAntiTopTagged", &sj0EnergyAntiTopTagged, &b_sj0EnergyAntiTopTagged);
   fChain->SetBranchAddress("sj1EnergyAntiTopTagged", &sj1EnergyAntiTopTagged, &b_sj1EnergyAntiTopTagged);
   fChain->SetBranchAddress("idxZTagged", &idxZTagged, &b_idxZTagged);
   fChain->SetBranchAddress("ptZTagged", &ptZTagged, &b_ptZTagged);
   fChain->SetBranchAddress("etaZTagged", &etaZTagged, &b_etaZTagged);
   fChain->SetBranchAddress("phiZTagged", &phiZTagged, &b_phiZTagged);
   fChain->SetBranchAddress("MZTagged", &MZTagged, &b_MZTagged);
   fChain->SetBranchAddress("SoftDropMassZTagged", &SoftDropMassZTagged, &b_SoftDropMassZTagged);
   fChain->SetBranchAddress("PrunedMassZTagged", &PrunedMassZTagged, &b_PrunedMassZTagged);
   fChain->SetBranchAddress("tau1ZTagged", &tau1ZTagged, &b_tau1ZTagged);
   fChain->SetBranchAddress("tau2ZTagged", &tau2ZTagged, &b_tau2ZTagged);
   fChain->SetBranchAddress("tau3ZTagged", &tau3ZTagged, &b_tau3ZTagged);
   fChain->SetBranchAddress("csvZTagged", &csvZTagged, &b_csvZTagged);
   fChain->SetBranchAddress("partonFlavourZTagged", &partonFlavourZTagged, &b_partonFlavourZTagged);
   fChain->SetBranchAddress("hadronFlavourZTagged", &hadronFlavourZTagged, &b_hadronFlavourZTagged);
   fChain->SetBranchAddress("doubleBZTagged", &doubleBZTagged, &b_doubleBZTagged);
   fChain->SetBranchAddress("sj0CSVZTagged", &sj0CSVZTagged, &b_sj0CSVZTagged);
   fChain->SetBranchAddress("sj1CSVZTagged", &sj1CSVZTagged, &b_sj1CSVZTagged);
   fChain->SetBranchAddress("hadronFlavourSJ0ZTagged", &hadronFlavourSJ0ZTagged, &b_hadronFlavourSJ0ZTagged);
   fChain->SetBranchAddress("hadronFlavourSJ1ZTagged", &hadronFlavourSJ1ZTagged, &b_hadronFlavourSJ1ZTagged);
   fChain->SetBranchAddress("sj0ptZTagged", &sj0ptZTagged, &b_sj0ptZTagged);
   fChain->SetBranchAddress("sj1ptZTagged", &sj1ptZTagged, &b_sj1ptZTagged);
   fChain->SetBranchAddress("sj0etaZTagged", &sj0etaZTagged, &b_sj0etaZTagged);
   fChain->SetBranchAddress("sj1etaZTagged", &sj1etaZTagged, &b_sj1etaZTagged);
   fChain->SetBranchAddress("sj0phiZTagged", &sj0phiZTagged, &b_sj0phiZTagged);
   fChain->SetBranchAddress("sj1phiZTagged", &sj1phiZTagged, &b_sj1phiZTagged);
   fChain->SetBranchAddress("sj0EnergyZTagged", &sj0EnergyZTagged, &b_sj0EnergyZTagged);
   fChain->SetBranchAddress("sj1EnergyZTagged", &sj1EnergyZTagged, &b_sj1EnergyZTagged);
   fChain->SetBranchAddress("idxAntiZTagged", &idxAntiZTagged, &b_idxAntiZTagged);
   fChain->SetBranchAddress("ptAntiZTagged", &ptAntiZTagged, &b_ptAntiZTagged);
   fChain->SetBranchAddress("etaAntiZTagged", &etaAntiZTagged, &b_etaAntiZTagged);
   fChain->SetBranchAddress("phiAntiZTagged", &phiAntiZTagged, &b_phiAntiZTagged);
   fChain->SetBranchAddress("MAntiZTagged", &MAntiZTagged, &b_MAntiZTagged);
   fChain->SetBranchAddress("SoftDropMassAntiZTagged", &SoftDropMassAntiZTagged, &b_SoftDropMassAntiZTagged);
   fChain->SetBranchAddress("PrunedMassAntiZTagged", &PrunedMassAntiZTagged, &b_PrunedMassAntiZTagged);
   fChain->SetBranchAddress("tau1AntiZTagged", &tau1AntiZTagged, &b_tau1AntiZTagged);
   fChain->SetBranchAddress("tau2AntiZTagged", &tau2AntiZTagged, &b_tau2AntiZTagged);
   fChain->SetBranchAddress("tau3AntiZTagged", &tau3AntiZTagged, &b_tau3AntiZTagged);
   fChain->SetBranchAddress("csvAntiZTagged", &csvAntiZTagged, &b_csvAntiZTagged);
   fChain->SetBranchAddress("partonFlavourAntiZTagged", &partonFlavourAntiZTagged, &b_partonFlavourAntiZTagged);
   fChain->SetBranchAddress("hadronFlavourAntiZTagged", &hadronFlavourAntiZTagged, &b_hadronFlavourAntiZTagged);
   fChain->SetBranchAddress("doubleBAntiZTagged", &doubleBAntiZTagged, &b_doubleBAntiZTagged);
   fChain->SetBranchAddress("sj0CSVAntiZTagged", &sj0CSVAntiZTagged, &b_sj0CSVAntiZTagged);
   fChain->SetBranchAddress("sj1CSVAntiZTagged", &sj1CSVAntiZTagged, &b_sj1CSVAntiZTagged);
   fChain->SetBranchAddress("hadronFlavourSJ0AntiZTagged", &hadronFlavourSJ0AntiZTagged, &b_hadronFlavourSJ0AntiZTagged);
   fChain->SetBranchAddress("hadronFlavourSJ1AntiZTagged", &hadronFlavourSJ1AntiZTagged, &b_hadronFlavourSJ1AntiZTagged);
   fChain->SetBranchAddress("sj0ptAntiZTagged", &sj0ptAntiZTagged, &b_sj0ptAntiZTagged);
   fChain->SetBranchAddress("sj1ptAntiZTagged", &sj1ptAntiZTagged, &b_sj1ptAntiZTagged);
   fChain->SetBranchAddress("sj0etaAntiZTagged", &sj0etaAntiZTagged, &b_sj0etaAntiZTagged);
   fChain->SetBranchAddress("sj1etaAntiZTagged", &sj1etaAntiZTagged, &b_sj1etaAntiZTagged);
   fChain->SetBranchAddress("sj0phiAntiZTagged", &sj0phiAntiZTagged, &b_sj0phiAntiZTagged);
   fChain->SetBranchAddress("sj1phiAntiZTagged", &sj1phiAntiZTagged, &b_sj1phiAntiZTagged);
   fChain->SetBranchAddress("sj0EnergyAntiZTagged", &sj0EnergyAntiZTagged, &b_sj0EnergyAntiZTagged);
   fChain->SetBranchAddress("sj1EnergyAntiZTagged", &sj1EnergyAntiZTagged, &b_sj1EnergyAntiZTagged);
   fChain->SetBranchAddress("idxEl", &idxEl, &b_idxEl);
   fChain->SetBranchAddress("ptEl", &ptEl, &b_ptEl);
   fChain->SetBranchAddress("etaEl", &etaEl, &b_etaEl);
   fChain->SetBranchAddress("phiEl", &phiEl, &b_phiEl);
   fChain->SetBranchAddress("EEl", &EEl, &b_EEl);
   fChain->SetBranchAddress("IsoDREl", &IsoDREl, &b_IsoDREl);
   fChain->SetBranchAddress("dR_Iso2DEl", &dR_Iso2DEl, &b_dR_Iso2DEl);
   fChain->SetBranchAddress("ptrel_Iso2DEl", &ptrel_Iso2DEl, &b_ptrel_Iso2DEl);
   fChain->SetBranchAddress("IsoDRAfterIso2DEl", &IsoDRAfterIso2DEl, &b_IsoDRAfterIso2DEl);
   fChain->SetBranchAddress("idxCleanedEl", &idxCleanedEl, &b_idxCleanedEl);
   fChain->SetBranchAddress("ptCleanedEl", &ptCleanedEl, &b_ptCleanedEl);
   fChain->SetBranchAddress("etaCleanedEl", &etaCleanedEl, &b_etaCleanedEl);
   fChain->SetBranchAddress("phiCleanedEl", &phiCleanedEl, &b_phiCleanedEl);
   fChain->SetBranchAddress("ECleanedEl", &ECleanedEl, &b_ECleanedEl);
   fChain->SetBranchAddress("idxMu", &idxMu, &b_idxMu);
   fChain->SetBranchAddress("ptMu", &ptMu, &b_ptMu);
   fChain->SetBranchAddress("etaMu", &etaMu, &b_etaMu);
   fChain->SetBranchAddress("phiMu", &phiMu, &b_phiMu);
   fChain->SetBranchAddress("EMu", &EMu, &b_EMu);
   fChain->SetBranchAddress("IsoDRMu", &IsoDRMu, &b_IsoDRMu);
   fChain->SetBranchAddress("dR_Iso2DMu", &dR_Iso2DMu, &b_dR_Iso2DMu);
   fChain->SetBranchAddress("ptrel_Iso2DMu", &ptrel_Iso2DMu, &b_ptrel_Iso2DMu);
   fChain->SetBranchAddress("IsoDRAfterIso2DMu", &IsoDRAfterIso2DMu, &b_IsoDRAfterIso2DMu);
   fChain->SetBranchAddress("idxCleanedMu", &idxCleanedMu, &b_idxCleanedMu);
   fChain->SetBranchAddress("ptCleanedMu", &ptCleanedMu, &b_ptCleanedMu);
   fChain->SetBranchAddress("etaCleanedMu", &etaCleanedMu, &b_etaCleanedMu);
   fChain->SetBranchAddress("phiCleanedMu", &phiCleanedMu, &b_phiCleanedMu);
   fChain->SetBranchAddress("ECleanedMu", &ECleanedMu, &b_ECleanedMu);
   Notify();
}

inline Bool_t InputTreeBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void InputTreeBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t InputTreeBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
