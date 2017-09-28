//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Sep 27 11:16:51 2017 by ROOT version 5.34/25
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
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxSelectedEvent_lhewts = 1;

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
   Double_t        SelectedEvent_ht;
   Int_t           SelectedEvent_nAK4;
   Int_t           SelectedEvent_nAK8;
   Bool_t          SelectedEvent_isRegionA;
   Bool_t          SelectedEvent_isRegionB;
   Bool_t          SelectedEvent_isRegionC;
   Bool_t          SelectedEvent_isRegionD;
   Bool_t          SelectedEvent_isRegionNotABCD;
   Int_t           SelectedEvent_lhewts_;
   Int_t           SelectedEvent_lhewts_first[kMaxSelectedEvent_lhewts];   //[SelectedEvent_lhewts_]
   Double_t        SelectedEvent_lhewts_second[kMaxSelectedEvent_lhewts];   //[SelectedEvent_lhewts_]
   Double_t        SelectedEvent_isotropy;
   Double_t        SelectedEvent_circularity;
   Double_t        SelectedEvent_sphericity;
   Double_t        SelectedEvent_aplanarity;
   Double_t        SelectedEvent_C;
   Double_t        SelectedEvent_D;
   Double_t        SelectedEvent_thrust;
   Double_t        SelectedEvent_thrustminor;
   vector<int>     *idxAK4;
   vector<double>  *ptAK4;
   vector<double>  *etaAK4;
   vector<double>  *phiAK4;
   vector<double>  *MAK4;
   vector<double>  *csvAK4;
   vector<double>  *partonFlavourAK4;
   vector<double>  *hadronFlavourAK4;
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
   TBranch        *b_ht;   //!
   TBranch        *b_nAK4;   //!
   TBranch        *b_nAK8;   //!
   TBranch        *b_isRegionA;   //!
   TBranch        *b_isRegionB;   //!
   TBranch        *b_isRegionC;   //!
   TBranch        *b_isRegionD;   //!
   TBranch        *b_isRegionNotABCD;   //!
   TBranch        *b_SelectedEvent_lhewts_;   //!
   TBranch        *b_SelectedEvent_lhewts_first;   //!
   TBranch        *b_SelectedEvent_lhewts_second;   //!
   TBranch        *b_isotropy;   //!
   TBranch        *b_circularity;   //!
   TBranch        *b_sphericity;   //!
   TBranch        *b_aplanarity;   //!
   TBranch        *b_C;   //!
   TBranch        *b_D;   //!
   TBranch        *b_thrust;   //!
   TBranch        *b_thrustminor;   //!
   TBranch        *b_idxAK4;   //!
   TBranch        *b_ptAK4;   //!
   TBranch        *b_etaAK4;   //!
   TBranch        *b_phiAK4;   //!
   TBranch        *b_MAK4;   //!
   TBranch        *b_csvAK4;   //!
   TBranch        *b_partonFlavourAK4;   //!
   TBranch        *b_hadronFlavourAK4;   //!
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
   idxAK4 = 0;
   ptAK4 = 0;
   etaAK4 = 0;
   phiAK4 = 0;
   MAK4 = 0;
   csvAK4 = 0;
   partonFlavourAK4 = 0;
   hadronFlavourAK4 = 0;
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
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

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
   fChain->SetBranchAddress("SelectedEvent_ht", &SelectedEvent_ht, &b_ht);
   fChain->SetBranchAddress("SelectedEvent_nAK4", &SelectedEvent_nAK4, &b_nAK4);
   fChain->SetBranchAddress("SelectedEvent_nAK8", &SelectedEvent_nAK8, &b_nAK8);
   fChain->SetBranchAddress("SelectedEvent_isRegionA", &SelectedEvent_isRegionA, &b_isRegionA);
   fChain->SetBranchAddress("SelectedEvent_isRegionB", &SelectedEvent_isRegionB, &b_isRegionB);
   fChain->SetBranchAddress("SelectedEvent_isRegionC", &SelectedEvent_isRegionC, &b_isRegionC);
   fChain->SetBranchAddress("SelectedEvent_isRegionD", &SelectedEvent_isRegionD, &b_isRegionD);
   fChain->SetBranchAddress("SelectedEvent_isRegionNotABCD", &SelectedEvent_isRegionNotABCD, &b_isRegionNotABCD);
   fChain->SetBranchAddress("SelectedEvent_lhewts", &SelectedEvent_lhewts_, &b_SelectedEvent_lhewts_);
   fChain->SetBranchAddress("SelectedEvent_lhewts.first", SelectedEvent_lhewts_first, &b_SelectedEvent_lhewts_first);
   fChain->SetBranchAddress("SelectedEvent_lhewts.second", SelectedEvent_lhewts_second, &b_SelectedEvent_lhewts_second);
   fChain->SetBranchAddress("SelectedEvent_isotropy", &SelectedEvent_isotropy, &b_isotropy);
   fChain->SetBranchAddress("SelectedEvent_circularity", &SelectedEvent_circularity, &b_circularity);
   fChain->SetBranchAddress("SelectedEvent_sphericity", &SelectedEvent_sphericity, &b_sphericity);
   fChain->SetBranchAddress("SelectedEvent_aplanarity", &SelectedEvent_aplanarity, &b_aplanarity);
   fChain->SetBranchAddress("SelectedEvent_C", &SelectedEvent_C, &b_C);
   fChain->SetBranchAddress("SelectedEvent_D", &SelectedEvent_D, &b_D);
   fChain->SetBranchAddress("SelectedEvent_thrust", &SelectedEvent_thrust, &b_thrust);
   fChain->SetBranchAddress("SelectedEvent_thrustminor", &SelectedEvent_thrustminor, &b_thrustminor);
   fChain->SetBranchAddress("idxAK4", &idxAK4, &b_idxAK4);
   fChain->SetBranchAddress("ptAK4", &ptAK4, &b_ptAK4);
   fChain->SetBranchAddress("etaAK4", &etaAK4, &b_etaAK4);
   fChain->SetBranchAddress("phiAK4", &phiAK4, &b_phiAK4);
   fChain->SetBranchAddress("MAK4", &MAK4, &b_MAK4);
   fChain->SetBranchAddress("csvAK4", &csvAK4, &b_csvAK4);
   fChain->SetBranchAddress("partonFlavourAK4", &partonFlavourAK4, &b_partonFlavourAK4);
   fChain->SetBranchAddress("hadronFlavourAK4", &hadronFlavourAK4, &b_hadronFlavourAK4);
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

