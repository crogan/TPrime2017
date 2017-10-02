//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Sep 30 19:49:30 2017 by ROOT version 5.34/34
// from TTree TPrime/TPrime
// found on file: TTJets.root
//////////////////////////////////////////////////////////

#ifndef ReducedBase_h
#define ReducedBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;

class ReducedBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         weight;
   Int_t           NPV;
   Int_t           NPU;
   Bool_t          isA;
   Bool_t          isB;
   Bool_t          isC;
   Bool_t          isD;
   Float_t         pT_top;
   Float_t         eta_top;
   Float_t         phi_top;
   Float_t         mass_top;
   Float_t         pT_higgs;
   Float_t         eta_higgs;
   Float_t         phi_higgs;
   Float_t         mass_higgs;
   Float_t         pT_top_sj0;
   Float_t         eta_top_sj0;
   Float_t         phi_top_sj0;
   Float_t         mass_top_sj0;
   Float_t         pT_top_sj1;
   Float_t         eta_top_sj1;
   Float_t         phi_top_sj1;
   Float_t         mass_top_sj1;
   Float_t         pT_higgs_sj0;
   Float_t         eta_higgs_sj0;
   Float_t         phi_higgs_sj0;
   Float_t         mass_higgs_sj0;
   Float_t         pT_higgs_sj1;
   Float_t         eta_higgs_sj1;
   Float_t         phi_higgs_sj1;
   Float_t         mass_higgs_sj1;
   vector<float>   *pT_extrajet;
   vector<float>   *eta_extrajet;
   vector<float>   *phi_extrajet;
   vector<float>   *mass_extrajet;
   Float_t         M_Tp;
   Float_t         pT_Tp;
   Float_t         cosTp;
   Float_t         cosH;
   Float_t         cosT;
   Float_t         cosTq;
   Float_t         dphiTpT;
   Float_t         dphiTpH;
   Float_t         dphiTH;
   Float_t         T;
   Float_t         Tm;
   Float_t         TT;
   Float_t         T_CM;
   Float_t         Tm_CM;
   Float_t         TT_CM;
   Float_t         M_extra;
   Int_t           N_extra;
   Float_t         pT_q;
   Float_t         eta_q;
   Float_t         phi_q;
   Float_t         mass_q;
   Float_t         EtaMax;

   // List of branches
   TBranch        *b_weight;   //!
   TBranch        *b_NPV;   //!
   TBranch        *b_NPU;   //!
   TBranch        *b_isA;   //!
   TBranch        *b_isB;   //!
   TBranch        *b_isC;   //!
   TBranch        *b_isD;   //!
   TBranch        *b_pT_top;   //!
   TBranch        *b_eta_top;   //!
   TBranch        *b_phi_top;   //!
   TBranch        *b_mass_top;   //!
   TBranch        *b_pT_higgs;   //!
   TBranch        *b_eta_higgs;   //!
   TBranch        *b_phi_higgs;   //!
   TBranch        *b_mass_higgs;   //!
   TBranch        *b_pT_top_sj0;   //!
   TBranch        *b_eta_top_sj0;   //!
   TBranch        *b_phi_top_sj0;   //!
   TBranch        *b_mass_top_sj0;   //!
   TBranch        *b_pT_top_sj1;   //!
   TBranch        *b_eta_top_sj1;   //!
   TBranch        *b_phi_top_sj1;   //!
   TBranch        *b_mass_top_sj1;   //!
   TBranch        *b_pT_higgs_sj0;   //!
   TBranch        *b_eta_higgs_sj0;   //!
   TBranch        *b_phi_higgs_sj0;   //!
   TBranch        *b_mass_higgs_sj0;   //!
   TBranch        *b_pT_higgs_sj1;   //!
   TBranch        *b_eta_higgs_sj1;   //!
   TBranch        *b_phi_higgs_sj1;   //!
   TBranch        *b_mass_higgs_sj1;   //!
   TBranch        *b_pT_extrajet;   //!
   TBranch        *b_eta_extrajet;   //!
   TBranch        *b_phi_extrajet;   //!
   TBranch        *b_mass_extrajet;   //!
   TBranch        *b_M_Tp;   //!
   TBranch        *b_pT_Tp;   //!
   TBranch        *b_cosTp;   //!
   TBranch        *b_cosH;   //!
   TBranch        *b_cosT;   //!
   TBranch        *b_cosTq;   //!
   TBranch        *b_dphiTpT;   //!
   TBranch        *b_dphiTpH;   //!
   TBranch        *b_dphiTH;   //!
   TBranch        *b_T;   //!
   TBranch        *b_Tm;   //!
   TBranch        *b_TT;   //!
   TBranch        *b_T_CM;   //!
   TBranch        *b_Tm_CM;   //!
   TBranch        *b_TT_CM;   //!
   TBranch        *b_M_extra;   //!
   TBranch        *b_N_extra;   //!
   TBranch        *b_pT_q;   //!
   TBranch        *b_eta_q;   //!
   TBranch        *b_phi_q;   //!
   TBranch        *b_mass_q;   //!
   TBranch        *b_EtaMax;   //!

   ReducedBase(TTree *tree=0);
   virtual ~ReducedBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

inline ReducedBase::ReducedBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TTJets.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("TTJets.root");
      }
      f->GetObject("TPrime",tree);

   }
   Init(tree);
}

inline ReducedBase::~ReducedBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t ReducedBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t ReducedBase::LoadTree(Long64_t entry)
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

inline void ReducedBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pT_extrajet = 0;
   eta_extrajet = 0;
   phi_extrajet = 0;
   mass_extrajet = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("NPV", &NPV, &b_NPV);
   fChain->SetBranchAddress("NPU", &NPU, &b_NPU);
   fChain->SetBranchAddress("isA", &isA, &b_isA);
   fChain->SetBranchAddress("isB", &isB, &b_isB);
   fChain->SetBranchAddress("isC", &isC, &b_isC);
   fChain->SetBranchAddress("isD", &isD, &b_isD);
   fChain->SetBranchAddress("pT_top", &pT_top, &b_pT_top);
   fChain->SetBranchAddress("eta_top", &eta_top, &b_eta_top);
   fChain->SetBranchAddress("phi_top", &phi_top, &b_phi_top);
   fChain->SetBranchAddress("mass_top", &mass_top, &b_mass_top);
   fChain->SetBranchAddress("pT_higgs", &pT_higgs, &b_pT_higgs);
   fChain->SetBranchAddress("eta_higgs", &eta_higgs, &b_eta_higgs);
   fChain->SetBranchAddress("phi_higgs", &phi_higgs, &b_phi_higgs);
   fChain->SetBranchAddress("mass_higgs", &mass_higgs, &b_mass_higgs);
   fChain->SetBranchAddress("pT_top_sj0", &pT_top_sj0, &b_pT_top_sj0);
   fChain->SetBranchAddress("eta_top_sj0", &eta_top_sj0, &b_eta_top_sj0);
   fChain->SetBranchAddress("phi_top_sj0", &phi_top_sj0, &b_phi_top_sj0);
   fChain->SetBranchAddress("mass_top_sj0", &mass_top_sj0, &b_mass_top_sj0);
   fChain->SetBranchAddress("pT_top_sj1", &pT_top_sj1, &b_pT_top_sj1);
   fChain->SetBranchAddress("eta_top_sj1", &eta_top_sj1, &b_eta_top_sj1);
   fChain->SetBranchAddress("phi_top_sj1", &phi_top_sj1, &b_phi_top_sj1);
   fChain->SetBranchAddress("mass_top_sj1", &mass_top_sj1, &b_mass_top_sj1);
   fChain->SetBranchAddress("pT_higgs_sj0", &pT_higgs_sj0, &b_pT_higgs_sj0);
   fChain->SetBranchAddress("eta_higgs_sj0", &eta_higgs_sj0, &b_eta_higgs_sj0);
   fChain->SetBranchAddress("phi_higgs_sj0", &phi_higgs_sj0, &b_phi_higgs_sj0);
   fChain->SetBranchAddress("mass_higgs_sj0", &mass_higgs_sj0, &b_mass_higgs_sj0);
   fChain->SetBranchAddress("pT_higgs_sj1", &pT_higgs_sj1, &b_pT_higgs_sj1);
//    fChain->SetBranchAddress("pT_higgs_sj1", &pT_higgs_sj1, &b_pT_higgs_sj1);
   fChain->SetBranchAddress("phi_higgs_sj1", &phi_higgs_sj1, &b_phi_higgs_sj1);
   fChain->SetBranchAddress("mass_higgs_sj1", &mass_higgs_sj1, &b_mass_higgs_sj1);
   fChain->SetBranchAddress("pT_extrajet", &pT_extrajet, &b_pT_extrajet);
   fChain->SetBranchAddress("eta_extrajet", &eta_extrajet, &b_eta_extrajet);
   fChain->SetBranchAddress("phi_extrajet", &phi_extrajet, &b_phi_extrajet);
   fChain->SetBranchAddress("mass_extrajet", &mass_extrajet, &b_mass_extrajet);
   fChain->SetBranchAddress("M_Tp", &M_Tp, &b_M_Tp);
   fChain->SetBranchAddress("pT_Tp", &pT_Tp, &b_pT_Tp);
   fChain->SetBranchAddress("cosTp", &cosTp, &b_cosTp);
   fChain->SetBranchAddress("cosH", &cosH, &b_cosH);
   fChain->SetBranchAddress("cosT", &cosT, &b_cosT);
   fChain->SetBranchAddress("cosTq", &cosTq, &b_cosTq);
   fChain->SetBranchAddress("dphiTpT", &dphiTpT, &b_dphiTpT);
   fChain->SetBranchAddress("dphiTpH", &dphiTpH, &b_dphiTpH);
   fChain->SetBranchAddress("dphiTH", &dphiTH, &b_dphiTH);
   fChain->SetBranchAddress("T", &T, &b_T);
   fChain->SetBranchAddress("Tm", &Tm, &b_Tm);
   fChain->SetBranchAddress("TT", &TT, &b_TT);
   fChain->SetBranchAddress("T_CM", &T_CM, &b_T_CM);
   fChain->SetBranchAddress("Tm_CM", &Tm_CM, &b_Tm_CM);
   fChain->SetBranchAddress("TT_CM", &TT_CM, &b_TT_CM);
   fChain->SetBranchAddress("M_extra", &M_extra, &b_M_extra);
   fChain->SetBranchAddress("N_extra", &N_extra, &b_N_extra);
   fChain->SetBranchAddress("pT_q", &pT_q, &b_pT_q);
   fChain->SetBranchAddress("eta_q", &eta_q, &b_eta_q);
   fChain->SetBranchAddress("phi_q", &phi_q, &b_phi_q);
   fChain->SetBranchAddress("mass_q", &mass_q, &b_mass_q);
   fChain->SetBranchAddress("EtaMax", &EtaMax, &b_EtaMax);
   Notify();
}

inline Bool_t ReducedBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void ReducedBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t ReducedBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
