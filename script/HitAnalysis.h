//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep 10 12:52:21 2018 by ROOT version 6.12/06
// from TTree HitTree/Hit Statistics
// found on file: ./CerenkovHit_3d5m_M16.root
//////////////////////////////////////////////////////////

#ifndef HitAnalysis_h
#define HitAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class HitAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           eventHit;
   Double_t        wavelengthHit;

   // List of branches
   TBranch        *b_eventHit;   //!
   TBranch        *b_wavelengthHit;   //!

   HitAnalysis(TTree *tree=0);
   virtual ~HitAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual double   Loop(double threshold);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HitAnalysis_cxx
HitAnalysis::HitAnalysis(TTree *tree) : fChain(0)
{
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../cmake-build-debug/CerenkovHit_1d5m_R5912-03Mod2.root.NewBeam.N2");
      if (!f || !f->IsOpen()) {
         f = new TFile("../cmake-build-debug/CerenkovHit_1d5m_R5912-03Mod2.root.NewBeam.N2");
      }
      f->GetObject("HitTree",tree);

   }
   Init(tree);
}

HitAnalysis::~HitAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HitAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HitAnalysis::LoadTree(Long64_t entry)
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

void HitAnalysis::Init(TTree *tree)
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

   fChain->SetBranchAddress("eventHit", &eventHit, &b_eventHit);
   fChain->SetBranchAddress("wavelengthHit", &wavelengthHit, &b_wavelengthHit);
   Notify();
}

Bool_t HitAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HitAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HitAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HitAnalysis_cxx
