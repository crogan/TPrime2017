//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct  6 19:43:46 2017 by ROOT version 5.34/34
// from TTree EventCount/EventCount
// found on file: TPrime_0p1/bkg/TTJets.root
//////////////////////////////////////////////////////////

#ifndef EventCount_h
#define EventCount_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class EventCount {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        EvtTotal;
   Double_t        EvtSample;
   Double_t        EvtPreselection;
   Double_t        EvtSelected;

   // List of branches
   TBranch        *b_EvtTotal;   //!
   TBranch        *b_EvtSample;   //!
   TBranch        *b_EvtPreselection;   //!
   TBranch        *b_EvtSelected;   //!

   EventCount(TTree *tree=0);
   virtual ~EventCount();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

inline EventCount::EventCount(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TPrime_0p1/bkg/TTJets.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("TPrime_0p1/bkg/TTJets.root");
      }
      f->GetObject("EventCount",tree);

   }
   Init(tree);
}

inline EventCount::~EventCount()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t EventCount::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t EventCount::LoadTree(Long64_t entry)
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

inline void EventCount::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EvtTotal", &EvtTotal, &b_EvtTotal);
   fChain->SetBranchAddress("EvtSample", &EvtSample, &b_EvtSample);
   fChain->SetBranchAddress("EvtPreselection", &EvtPreselection, &b_EvtPreselection);
   fChain->SetBranchAddress("EvtSelected", &EvtSelected, &b_EvtSelected);
   Notify();
}

inline Bool_t EventCount::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void EventCount::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t EventCount::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
