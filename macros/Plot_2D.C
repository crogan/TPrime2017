#include <iostream>
#include <string>

#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TH2D.h>
#include <TStyle.h>

#include "RestFrames/RestFrames.hh"
#include "include/ReducedBase.hh"

using namespace std;
using namespace RestFrames;

string g_Path;
vector<string> g_File;
vector<string> g_Tree;
vector<string> g_Title;
string g_PlotTitle;
string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;
string g_Yname;
double g_Ymin;
double g_Ymax;
double g_NY;

using namespace RestFrames;

void Plot_2D(){
  RestFrames::SetStyle();

  // g_File.push_back("bkg/QCDPt.root");
  // g_PlotTitle = "QCD multijets";
  
  // g_File.push_back("bkg/TTJets.root");
  // g_File.push_back("bkg/ttHJets.root");
  // g_File.push_back("bkg/ttWJets.root");
  // g_File.push_back("bkg/ttZJets.root");
  // g_PlotTitle = "t #bar{t} + X";

  // g_File.push_back("bkg/ST_antitop.root");
  // g_Hist.push_back(ihist);
  // g_File.push_back("bkg/ST_top.root");
  // g_Hist.push_back(ihist);
  // g_File.push_back("bkg/tHQ.root");
  // g_Hist.push_back(ihist);
  // g_PlotTitle = "single t + X";

  // g_File.push_back("bkg/DYJets.root");
  // g_Hist.push_back(ihist);
  // g_File.push_back("bkg/WJets.root");
  // g_Hist.push_back(ihist);
  // g_File.push_back("bkg/WW.root");
  // g_Hist.push_back(ihist);
  // g_File.push_back("bkg/WZ.root");
  // g_Hist.push_back(ihist);
  // g_File.push_back("bkg/ZJets.root");
  // g_Hist.push_back(ihist);
  // g_File.push_back("bkg/ZZ.root");
  // g_Hist.push_back(ihist);
  // g_PlotTitle = "other";
 
  // g_File.push_back("signal/TbtH_1200_LH.root");
  // g_PlotTitle = "TbtH LH M_{T'} = 1.2 TeV";

  g_File.push_back("signal/TbtH_1500_LH.root");
  g_PlotTitle = "TbtH LH M_{T'} = 1.5 TeV";

  // g_File.push_back("signal/TbtH_1800_LH.root");
  // g_PlotTitle = "TbtH LH M_{T'} = 1.8 TeV";
 
  // g_File.push_back("signal/TttH_1200_RH.root");
  // g_PlotTitle = "TttH RH M_{T'} = 1.2 TeV";
 

  // g_File.push_back("signal/TttH_1500_RH.root");
  // g_Hist.push_back(ihist);
  // g_PlotTitle = "TttH RH M_{T'} = 1.5 TeV";
 

  // g_File.push_back("signal/TttH_1800_RH.root");
  // g_PlotTitle = "TttH RH M_{T'} = 1.8 TeV";
 

  // g_PlotTitle = "m_{#tilde{t}} = 300, m_{#tilde{#chi}} = 127 GeV";
  // g_File.push_back("NTUPLES/SIG/TT_300_127.root");
  // g_Tree.push_back("CompressedAnalysis");

  int Nsample = g_File.size();

  g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/TPrime_3p0/";
  
  //string g_Label = "No selection";
  string g_Label = "p_{T}^{ ISR} > 400 GeV";

  g_Xname = "R_{ISR}";
  g_Xmin = -1.;
  g_Xmax = 1.; 
  g_NX = 30;
  g_Yname = "PTISR";
  g_Ymin = -1.;
  g_Ymax = 1.;
  g_NY = 30.;

  TH2D* hist = new TH2D("hist","hist",
			g_NX,g_Xmin,g_Xmax,
			g_NY,g_Ymin,g_Ymax);

  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain("TPrime");
    chain->Add((g_Path+g_File[s]).c_str());

    ReducedBase* base = new ReducedBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);

      if(base->N_extra < 1)
       	continue;

      // if(base->M_Tp < 1500)
      //  	continue;

      TLorentzVector H,T;
      H.SetPtEtaPhiM( base->pT_higgs, base->eta_higgs, base->phi_higgs, base->mass_higgs );
      T.SetPtEtaPhiM( base->pT_top, base->eta_top, base->phi_top, base->mass_top );
      TLorentzVector Tp = H+T;
      TLorentzVector q;
      q.SetPtEtaPhiM( base->pT_q, base->eta_q, base->phi_q, base->mass_q );

      // double deta = 0;
      // if(base->N_extra > 1)
      // 	for(int i = 0; i < base->N_extra-1; i++)
      // 	  for(int j = i+1; j < base->N_extra; j++)
      // 	    if(fabs(base->eta_extrajet->at(i)-base->eta_extrajet->at(j)) > deta){
      // 	      deta = fabs(base->eta_extrajet->at(i)-base->eta_extrajet->at(j));

      TVector3 boost = Tp.BoostVector();
      T.Boost(-boost);
      double mycos = T.Vect().Unit().Dot(-boost.Unit());

      double v1 = (mycos-base->cosTq)/(2. - fabs(mycos+base->cosTq));
      double v2 = (mycos+base->cosTq)/(2. - fabs(mycos-base->cosTq));
      double v3 = sqrt(v1*v1+v2*v2)/sqrt(2);
      
      hist->Fill(base->cosTp, base->cosTq, base->weight);
      //hist->Fill(fabs(q.Rapidity()-Tp.Rapidity()), base->M_Tp, base->weight);
    }

    delete base;
    delete chain;
  }

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
    TCanvas* can = (TCanvas*) new TCanvas("can","can",700.,600);

    can->SetLeftMargin(0.15);
    can->SetRightMargin(0.22);
    can->SetBottomMargin(0.15);
    can->SetGridx();
    can->SetGridy();
    can->SetLogz();
    can->Draw();
    can->cd();
    hist->Draw("COLZ");
    hist->GetXaxis()->CenterTitle();
    hist->GetXaxis()->SetTitleFont(132);
    hist->GetXaxis()->SetTitleSize(0.06);
    hist->GetXaxis()->SetTitleOffset(1.06);
    hist->GetXaxis()->SetLabelFont(132);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetXaxis()->SetTitle(g_Xname.c_str());
    hist->GetYaxis()->CenterTitle();
    hist->GetYaxis()->SetTitleFont(132);
    hist->GetYaxis()->SetTitleSize(0.06);
    hist->GetYaxis()->SetTitleOffset(1.12);
    hist->GetYaxis()->SetLabelFont(132);
    hist->GetYaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetTitle(g_Yname.c_str());
    hist->GetZaxis()->CenterTitle();
    hist->GetZaxis()->SetTitleFont(132);
    hist->GetZaxis()->SetTitleSize(0.06);
    hist->GetZaxis()->SetTitleOffset(1.3);
    hist->GetZaxis()->SetLabelFont(132);
    hist->GetZaxis()->SetLabelSize(0.05);
    hist->GetZaxis()->SetTitle("N_{evt} / bin / fb^{-1}");
    hist->GetZaxis()->SetRangeUser(0.9*hist->GetMinimum(0.0),1.1*hist->GetMaximum());

    TLatex l;
    l.SetTextFont(132);
    l.SetNDC();
    l.SetTextSize(0.05);
    l.SetTextFont(132);
    // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
    l.DrawLatex(0.5,0.943,g_PlotTitle.c_str());
    l.SetTextSize(0.04);
    l.SetTextFont(42);
    l.DrawLatex(0.01,0.943,"#bf{#it{ATLAS}} Internal 13 TeV Simulation");

    l.SetTextSize(0.04);
    l.SetTextFont(132);
    l.DrawLatex(0.64,0.04,g_Label.c_str());


}
