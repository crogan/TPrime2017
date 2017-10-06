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

void PlotSampleEff(){

  vector<string> g_Files;

  g_Files.push_back("TbtH_800_LH.root");
  g_Files.push_back("TbtH_800_RH.root");
  g_Files.push_back("TbtH_900_LH.root");
  g_Files.push_back("TbtH_900_RH.root");
  g_Files.push_back("TbtH_1000_10p_LH.root");
  g_Files.push_back("TbtH_1000_20p_LH.root");
  g_Files.push_back("TbtH_1000_30p_LH.root");
  g_Files.push_back("TbtH_1000_LH.root");
  g_Files.push_back("TbtH_1000_RH.root");
  g_Files.push_back("TbtH_1100_LH.root");
  g_Files.push_back("TbtH_1100_RH.root");
  g_Files.push_back("TbtH_1200_LH.root");
  g_Files.push_back("TbtH_1200_RH.root");
  g_Files.push_back("TbtH_1300_LH.root");
  g_Files.push_back("TbtH_1300_RH.root");
  g_Files.push_back("TbtH_1400_LH.root");
  g_Files.push_back("TbtH_1400_RH.root");
  g_Files.push_back("TbtH_1500_LH.root");
  g_Files.push_back("TbtH_1500_RH.root");
  g_Files.push_back("TbtH_1600_10p_LH.root");
  g_Files.push_back("TbtH_1700_LH.root");
  g_Files.push_back("TbtH_1700_RH.root");
  g_Files.push_back("TbtH_1800_LH.root");
  g_Files.push_back("TbtH_1800_RH.root");
  g_Files.push_back("TbtH_2000_10p_LH.root");
  g_Files.push_back("TbtH_2400_10p_LH.root");
  g_Files.push_back("TbtH_2600_10p_LH.root");

  // g_Files.push_back("TttH_800_LH.root");
  // g_Files.push_back("TttH_800_RH.root");
  // g_Files.push_back("TttH_900_RH.root");
  // g_Files.push_back("TttH_1000_LH.root");
  // g_Files.push_back("TttH_1000_RH.root");
  // g_Files.push_back("TttH_1100_LH.root");
  // g_Files.push_back("TttH_1100_RH.root");
  // g_Files.push_back("TttH_1200_LH.root");
  // g_Files.push_back("TttH_1200_RH.root");
  // g_Files.push_back("TttH_1300_LH.root");
  // g_Files.push_back("TttH_1300_RH.root");
  // g_Files.push_back("TttH_1400_LH.root");
  // g_Files.push_back("TttH_1400_RH.root");
  // g_Files.push_back("TttH_1500_LH.root");
  // g_Files.push_back("TttH_1500_RH.root");
  // g_Files.push_back("TttH_1700_LH.root");
  // g_Files.push_back("TttH_1700_RH.root");
  // g_Files.push_back("TttH_1800_LH.root");
  // g_Files.push_back("TttH_1800_RH.root");
  // g_Files.push_back("TttH_2000_10p_RH.root");
  // g_Files.push_back("TttH_2400_10p_RH.root");
  // g_Files.push_back("TttH_2600_10p_RH.root");

  int Nfile = g_Files.size();

  string g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/TPrime_1p0/signal/";

  TH1D* h_NUM[3];
  TH1D* h_DEN[3];

  for(int i = 0; i < 3; i++){
    char* sname = new char[10];
    sprintf(sname, "h_%d", i);
    h_NUM[i] = (TH1D*) new TH1D(("h_NUM"+string(sname)).c_str(),
				("h_NUM"+string(sname)).c_str(),
				Nfile, -0.5, double(Nfile)-0.5);
    h_DEN[i] = (TH1D*) new TH1D(("h_DEN"+string(sname)).c_str(),
				("h_DEN"+string(sname)).c_str(),
				Nfile, -0.5, double(Nfile)-0.5);
    h_NUM[i]->Sumw2();
    h_DEN[i]->Sumw2();
  }
 

  for(int f = 0; f < Nfile; f++){
    TChain* chain = new TChain("TPrime");
    chain->Add((g_Path+g_Files[f]).c_str());

    ReducedBase* base = new ReducedBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);

      if(base->N_extra < 1)
       	continue;

      for(int i = 0; i < 3; i++)
	h_DEN[i]->Fill(f, base->weight);

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

      if(muveto || eveto)
	h_NUM[0]->Fill(f, base->weight);
      if(eveto)
	h_NUM[1]->Fill(f, base->weight);
      if(muveto)
	h_NUM[2]->Fill(f, base->weight);
    }
    delete base;
    delete chain;
  }

  //TEfficiency* h_EFF = new TEfficiency(h_NUM, h_DEN);
  // h_Eff->Draw();
  TMultiGraph *mg = new TMultiGraph();
  TGraphAsymmErrors* gr[3];
  for(int i = 0; i < 3; i++){
    gr[i] = new TGraphAsymmErrors(h_NUM[i], h_DEN[i]);
    gr[i]->SetLineWidth(2);
    gr[i]->SetMarkerSize(0);
    mg->Add(gr[i]);
  }
  gr[0]->SetMarkerColor(kBlue+1);
  gr[1]->SetMarkerColor(kGreen+2);
  gr[2]->SetMarkerColor(kRed+1);
  gr[0]->SetLineColor(kBlue+1);
  gr[1]->SetLineColor(kGreen+2);
  gr[2]->SetLineColor(kRed+1);
  gr[0]->SetMarkerColor(kBlue+1);
  gr[1]->SetMarkerColor(kGreen+2);
  gr[2]->SetMarkerColor(kRed+1);
 
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
  TCanvas* can = (TCanvas*) new TCanvas("can","can",600.,500);

  can->SetLeftMargin(0.13);
  can->SetRightMargin(0.04);
  can->SetBottomMargin(0.28);
  can->SetTopMargin(0.085);
  can->SetGridx();
  can->SetGridy();
  can->Draw();
  can->cd();
  for(int s = 0; s < Nfile; s++){
    h_NUM[0]->SetBinContent(s+1, 0.);
    h_NUM[0]->SetBinError(s+1, 0.);
    string label = g_Files[s];
    if(label.find(".root") != string::npos )
      label.erase(label.find(".root"));
    h_NUM[0]->GetXaxis()->SetBinLabel(s+1,label.c_str());
  }
  h_NUM[0]->LabelsOption("v","X");
  h_NUM[0]->SetLineColor(kBlack);
  h_NUM[0]->Draw();
  h_NUM[0]->GetXaxis()->CenterTitle();
  h_NUM[0]->GetXaxis()->SetTitleFont(132);
  h_NUM[0]->GetXaxis()->SetTitleSize(0.06);
  h_NUM[0]->GetXaxis()->SetTitleOffset(1.06);
  h_NUM[0]->GetXaxis()->SetLabelFont(132);
  h_NUM[0]->GetXaxis()->SetLabelSize(0.05);
  //h_NUM[0]->GetXaxis()->SetTitle("Signal");
  h_NUM[0]->GetYaxis()->CenterTitle();
  h_NUM[0]->GetYaxis()->SetTitleFont(132);
  h_NUM[0]->GetYaxis()->SetTitleSize(0.06);
  h_NUM[0]->GetYaxis()->SetTitleOffset(1.);
  h_NUM[0]->GetYaxis()->SetLabelFont(132);
  h_NUM[0]->GetYaxis()->SetLabelSize(0.05);
  h_NUM[0]->GetYaxis()->SetTitle("1 - #epsilon lepton veto [w/ #Delta R (lep, Higgs) > 1]");
  h_NUM[0]->GetYaxis()->SetRangeUser(0., 1.);
  for(int i = 0; i < 3; i++)
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
  leg->AddEntry(gr[0], "e and #mu");
  leg->AddEntry(gr[1], "electron");
  leg->AddEntry(gr[2], "muon");
  leg->SetLineColor(kWhite);
  leg->SetFillColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->Draw("SAME");
  
  
}
