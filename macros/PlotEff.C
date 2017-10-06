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
#include <TObjArray.h>
#include <TEfficiency.h>
#include <TH1D.h>
#include <TChain.h>
#include <TGraphAsymmErrors.h>
#include <TStyle.h>

#include "RestFrames/RestFrames.hh"
#include "include/ReducedBase.hh"

string g_Path;
vector<string> g_File;
vector<int> g_Hist;
vector<string> g_Title;
vector<int> g_Color;

string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;

void PlotEff(){
  RestFrames::SetStyle();

  int ihist = 0;

  g_File.push_back("bkg/QCDPt.root");
  g_Hist.push_back(ihist);
  g_Title.push_back("QCD multijets");
  g_Color.push_back(kBlue+2);
  ihist++;
  
  g_File.push_back("bkg/TTJets.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/ttHJets.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/ttWJets.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/ttZJets.root");
  g_Hist.push_back(ihist);
  g_Title.push_back("t #bar{t} + X");
  g_Color.push_back(kRed+2);
  ihist++;

  g_File.push_back("bkg/ST_antitop.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/ST_top.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/tHQ.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/DYJets.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/WJets.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/WW.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/WZ.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/ZJets.root");
  g_Hist.push_back(ihist);
  g_File.push_back("bkg/ZZ.root");
  g_Hist.push_back(ihist);
  g_Title.push_back("other bkg.");
  g_Color.push_back(kGreen+2);
  ihist++;

  int Nsample = g_File.size();
  int Nhist = ihist;

  g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/TPrime_1p0/";
  

  g_Xname = "M_{T'} [GeV]";
  g_Xmin = 800.;
  g_Xmax = 2200.;

  g_NX = 25;


  TH1D* h_NUM[Nhist];
  TH1D* h_DEN[Nhist];
  for(int i = 0; i < Nhist; i++){
    h_NUM[i] = new TH1D(("h_NUM"+to_string(i)).c_str(),
			("h_NUM"+to_string(i)).c_str(),
			g_NX,g_Xmin,g_Xmax);
    h_DEN[i] = new TH1D(("h_DEN"+to_string(i)).c_str(),
			("h_DEN"+to_string(i)).c_str(),
			g_NX,g_Xmin,g_Xmax);
    h_NUM[i]->Sumw2();
    h_DEN[i]->Sumw2();
  }
  
  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain("TPrime");
    chain->Add((g_Path+g_File[s]).c_str());

    ReducedBase* base = new ReducedBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);

      // if(base->N_extra < 1)
      //  	continue;

     
      h_DEN[g_Hist[s]]->Fill(base->M_Tp, base->weight);

      bool eveto  = false;
      bool muveto = false;

      TLorentzVector L;
      TLorentzVector H;
      H.SetPtEtaPhiM( base->pT_higgs, base->eta_higgs, base->phi_higgs, base->mass_higgs );
      if(base->pT_mu_clean->size() > 0 && base->pT_mu_clean->at(0) >= 55.){
	L.SetPtEtaPhiE(base->pT_mu_clean->at(0),
		       base->eta_mu_clean->at(0),
		       base->phi_mu_clean->at(0),
		       base->E_mu_clean->at(0));
	if(H.DeltaR(L) > 1.) muveto = true;
      }
      if(base->pT_ele_clean->size() > 0 && base->pT_ele_clean->at(0) >= 55.){
	L.SetPtEtaPhiE(base->pT_ele_clean->at(0),
		       base->eta_ele_clean->at(0),
		       base->phi_ele_clean->at(0),
		       base->E_ele_clean->at(0));
	if(H.DeltaR(L) > 1.) eveto = true;
      }

      if(muveto || eveto){
	h_NUM[g_Hist[s]]->Fill(base->M_Tp, base->weight);
      }
    }
    delete base;
    delete chain;
  }

  vector<TGraphAsymmErrors*> gr;
  for(int i = 0; i < Nhist; i++){
    gr.push_back(new TGraphAsymmErrors(h_NUM[i], h_DEN[i]));
    gr[i]->SetLineWidth(2);
    gr[i]->SetMarkerSize(0);
    gr[i]->SetMarkerColor(g_Color[i]);
    gr[i]->SetLineColor(g_Color[i]);
    gr[i]->SetMarkerColor(g_Color[i]);
  }
 
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
  TCanvas* can = (TCanvas*) new TCanvas("can","can",600.,500);

  can->SetLeftMargin(0.13);
  can->SetRightMargin(0.04);
  can->SetBottomMargin(0.15);
  can->SetTopMargin(0.085);
  can->SetGridx();
  can->SetGridy();
  can->Draw();
  can->cd();
  for(int s = 0; s < g_NX; s++){
    h_NUM[0]->SetBinContent(s+1, 0.);
    h_NUM[0]->SetBinError(s+1, 0.);
  }
 
  h_NUM[0]->SetLineColor(kBlack);
  h_NUM[0]->Draw();
  h_NUM[0]->GetXaxis()->CenterTitle();
  h_NUM[0]->GetXaxis()->SetTitleFont(132);
  h_NUM[0]->GetXaxis()->SetTitleSize(0.06);
  h_NUM[0]->GetXaxis()->SetTitleOffset(1.06);
  h_NUM[0]->GetXaxis()->SetLabelFont(132);
  h_NUM[0]->GetXaxis()->SetLabelSize(0.05);
  h_NUM[0]->GetXaxis()->SetTitle(g_Xname.c_str());
  h_NUM[0]->GetYaxis()->CenterTitle();
  h_NUM[0]->GetYaxis()->SetTitleFont(132);
  h_NUM[0]->GetYaxis()->SetTitleSize(0.06);
  h_NUM[0]->GetYaxis()->SetTitleOffset(1.);
  h_NUM[0]->GetYaxis()->SetLabelFont(132);
  h_NUM[0]->GetYaxis()->SetLabelSize(0.05);
  h_NUM[0]->GetYaxis()->SetTitle("1 - #epsilon lepton veto [w/ #Delta R (lep, Higgs) > 1]");
  h_NUM[0]->GetYaxis()->SetRangeUser(0., 1.);
  for(int i = 0; i < Nhist; i++)
    gr[i]->Draw("P same");
 

  TLatex l;
  l.SetTextFont(132);
  l.SetNDC();
  l.SetTextSize(0.045);
  l.SetTextFont(132);
  // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
  l.DrawLatex(0.71,0.943, "Region D Selection");
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.13,0.943,"#bf{#it{CMS}} 13 TeV Simulation");

  TLegend* leg = new TLegend(0.16,0.686,0.334,0.886);
  leg->SetTextFont(132);
  leg->SetTextSize(0.045);
  leg->SetFillColor(kWhite);
  leg->SetLineColor(kWhite);
  leg->SetShadowColor(kWhite);
  for(int i = 0; i < Nhist; i++)
    leg->AddEntry(gr[i], g_Title[i].c_str());
  leg->SetLineColor(kWhite);
  leg->SetFillColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->Draw("SAME");
  
  
}
