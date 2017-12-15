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
#include <TH2D.h>
#include <TChain.h>
#include <TGraphAsymmErrors.h>
#include <TStyle.h>

#include "RestFrames/RestFrames.hh"
#include "include/TriggerBase.hh"

string g_Path;
vector<string> g_File;
vector<int> g_Hist;
vector<string> g_Title;
vector<int> g_Color;

string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;

void PlotTriggerEff(){
  RestFrames::SetStyle();

  string ifile = "/Users/crogan/Dropbox/SAMPLES/Tprime/trigger/DATA_2016.root";
  
  g_Xname = "#tilde{M}_{T'} [GeV]";
  //g_Xname = "p_{T}^{AK8,1} + p_{T}^{AK8,2} + p_{T}^{extra,1} + p_{T}^{extra,2} [GeV]";
  g_Xmin = 400.;
  g_Xmax = 2000.;

  g_NX = 100;

  int Nhist = 1;

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
  
  TH2D* h_NUM_2D = new TH2D("h_NUM2D", "h_NUM2D",
			    50,600.,1500,
			    50,600.,1500);
  TH2D* h_DEN_2D = new TH2D("h_DEN2D", "h_DEN2D",
			    50,600.,1500,
			    50,600.,1500);


  TChain* chain_NUM = new TChain("anatest/tree");
  chain_NUM->Add(ifile.c_str());

  TriggerBase* base = new TriggerBase(chain_NUM);

  int Nentry = base->fChain->GetEntries();
  for(int e = 0; e < Nentry; e++){

    int mymod = Nentry/10;
    if(mymod < 1)
      mymod = 1;
    if(e%mymod == 0)
      cout << " event = " << e << " : " << Nentry << endl;

    //if(e%1000 != 0) continue;

    base->GetEntry(e);

    int NAK8 = base->ptAK8->size();
    if(NAK8 < 2)
      continue;

    int NAK4 = base->ptAK4->size();
    if(NAK4 < 4)
      continue;

    TLorentzVector P4_AK8[2];
    vector<TLorentzVector> P4_extraAK4;

    for(int i = 0; i < 2; i++){
      P4_AK8[i].SetPtEtaPhiM(base->ptAK8->at(i),
			     base->etaAK8->at(i),
			     base->phiAK8->at(i),
			     base->MAK8->at(i));
    }

    double etaMax = 0.;
    TLorentzVector jet;
    for(int i = 0; i < NAK4; i++){
      jet.SetPtEtaPhiM(base->ptAK4->at(i),
		       base->etaAK4->at(i),
		       base->phiAK4->at(i),
		       base->MAK4->at(i));
      if(jet.DeltaR(P4_AK8[0]) < 1.2 ||
	 jet.DeltaR(P4_AK8[1]) < 1.2)
	continue;

      if(fabs(jet.Eta()) > etaMax)
	etaMax = fabs(jet.Eta());

      P4_extraAK4.push_back(jet);
    }

    int Nextra = P4_extraAK4.size();

    double MTp = (P4_AK8[0]+P4_AK8[1]).M() - P4_AK8[0].M() - P4_AK8[1].M() + 300.;

    double sumPT_AK8 = P4_AK8[0].Pt()+P4_AK8[1].Pt();

    if(sumPT_AK8 < 850. || Nextra < 2) continue;

    // if(P4_AK8[0].Pt() < 400.) continue;
    // if(P4_AK8[1].Pt() < 400.) continue;

    double HT4 = sumPT_AK8 + P4_extraAK4[0].Pt() + P4_extraAK4[1].Pt();

    h_NUM_2D->Fill(HT4, sumPT_AK8);

    // if(HT4 < 900.) continue;
    

    //h_NUM[0]->Fill(MTp);
    h_NUM[0]->Fill(MTp);

  }
   
  delete base;
  delete chain_NUM;

  TChain* chain_DEN = new TChain("ana/tree");
  chain_DEN->Add(ifile.c_str());
 
  base = (TriggerBase*) new TriggerBase(chain_DEN);
  
  Nentry = base->fChain->GetEntries();
  for(int e = 0; e < Nentry; e++){

    int mymod = Nentry/10;
    if(mymod < 1)
      mymod = 1;
    if(e%mymod == 0)
      cout << " event = " << e << " : " << Nentry << endl;

    //if(e%1000 != 0) continue;

    base->GetEntry(e);

     int NAK8 = base->ptAK8->size();
    if(NAK8 < 2)
      continue;

    int NAK4 = base->ptAK4->size();
    if(NAK4 < 4)
      continue;

    TLorentzVector P4_AK8[2];
    vector<TLorentzVector> P4_extraAK4;

    for(int i = 0; i < 2; i++){
      P4_AK8[i].SetPtEtaPhiM(base->ptAK8->at(i),
			     base->etaAK8->at(i),
			     base->phiAK8->at(i),
			     base->MAK8->at(i));
    }

    double etaMax = 0.;
    TLorentzVector jet;
    for(int i = 0; i < NAK4; i++){
      jet.SetPtEtaPhiM(base->ptAK4->at(i),
		       base->etaAK4->at(i),
		       base->phiAK4->at(i),
		       base->MAK4->at(i));
      if(jet.DeltaR(P4_AK8[0]) < 1.2 ||
	 jet.DeltaR(P4_AK8[1]) < 1.2)
	continue;

      if(fabs(jet.Eta()) > etaMax)
	etaMax = fabs(jet.Eta());

      P4_extraAK4.push_back(jet);
    }

    int Nextra = P4_extraAK4.size();

    double MTp = (P4_AK8[0]+P4_AK8[1]).M() - P4_AK8[0].M() - P4_AK8[1].M() + 300.;

    double sumPT_AK8 = P4_AK8[0].Pt()+P4_AK8[1].Pt();

    if(sumPT_AK8 < 850. || Nextra < 2) continue;

    double HT4 = sumPT_AK8 + P4_extraAK4[0].Pt() + P4_extraAK4[1].Pt();

    // if(P4_AK8[0].Pt() < 400.) continue;
    // if(P4_AK8[1].Pt() < 400.) continue;

    h_DEN_2D->Fill(HT4, sumPT_AK8);

   // if(HT4 < 900.) continue; 

    //h_DEN[0]->Fill(MTp);
    h_DEN[0]->Fill(MTp);
  }

  //h_DEN[0]->Add(h_NUM[0]);

  delete base;
  delete chain_DEN;

  g_Color.push_back(kBlue+2);

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
  h_NUM[0]->GetYaxis()->SetTitle("#epsilon trigger OR");
  h_NUM[0]->GetYaxis()->SetRangeUser(0., 1.);
  for(int i = 0; i < Nhist; i++)
    gr[i]->Draw("P same");
 

  TLatex l;
  l.SetTextFont(132);
  l.SetNDC();
  l.SetTextSize(0.045);
  l.SetTextFont(132);
  // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
  l.DrawLatex(0.71,0.943, "pre-selection");
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.13,0.943,"#bf{#it{CMS}} Internal 13 TeV");

  // TLegend* leg = new TLegend(0.16,0.686,0.334,0.886);
  // leg->SetTextFont(132);
  // leg->SetTextSize(0.045);
  // leg->SetFillColor(kWhite);
  // leg->SetLineColor(kWhite);
  // leg->SetShadowColor(kWhite);
  // for(int i = 0; i < Nhist; i++)
  //   leg->AddEntry(gr[i], g_Title[i].c_str());
  // leg->SetLineColor(kWhite);
  // leg->SetFillColor(kWhite);
  // leg->SetShadowColor(kWhite);
  // leg->Draw("SAME");
  
  h_NUM_2D->Divide(h_DEN_2D);
  TCanvas* can2D = (TCanvas*) new TCanvas("can2D","can2D",700.,600);

    can2D->SetLeftMargin(0.15);
    can2D->SetRightMargin(0.22);
    can2D->SetBottomMargin(0.15);
    can2D->SetGridx();
    can2D->SetGridy();
    //can2D->SetLogz();
    can2D->Draw();
    can2D->cd();
    h_NUM_2D->Draw("COLZ");
    h_NUM_2D->GetXaxis()->CenterTitle();
    h_NUM_2D->GetXaxis()->SetTitleFont(132);
    h_NUM_2D->GetXaxis()->SetTitleSize(0.06);
    h_NUM_2D->GetXaxis()->SetTitleOffset(1.06);
    h_NUM_2D->GetXaxis()->SetLabelFont(132);
    h_NUM_2D->GetXaxis()->SetLabelSize(0.05);
    h_NUM_2D->GetXaxis()->SetTitle(g_Xname.c_str());
    h_NUM_2D->GetYaxis()->CenterTitle();
    h_NUM_2D->GetYaxis()->SetTitleFont(132);
    h_NUM_2D->GetYaxis()->SetTitleSize(0.06);
    h_NUM_2D->GetYaxis()->SetTitleOffset(1.12);
    h_NUM_2D->GetYaxis()->SetLabelFont(132);
    h_NUM_2D->GetYaxis()->SetLabelSize(0.05);
    h_NUM_2D->GetYaxis()->SetTitle("#tilde{M}_{T'} [GeV]");
    h_NUM_2D->GetZaxis()->CenterTitle();
    h_NUM_2D->GetZaxis()->SetTitleFont(132);
    h_NUM_2D->GetZaxis()->SetTitleSize(0.06);
    h_NUM_2D->GetZaxis()->SetTitleOffset(1.3);
    h_NUM_2D->GetZaxis()->SetLabelFont(132);
    h_NUM_2D->GetZaxis()->SetLabelSize(0.05);
    h_NUM_2D->GetZaxis()->SetTitle("#epsilon trigger OR");
    //h_NUM_2D->GetZaxis()->SetRangeUser(0.9*h_NUM_2D->GetMinimum(0.0),1.1*h_NUM_2D->GetMaximum());

    l.SetTextFont(132);
    l.SetNDC();
    l.SetTextSize(0.05);
    l.SetTextFont(132);
    // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
    l.DrawLatex(0.6,0.943,"pre-selection");
    l.SetTextSize(0.04);
    l.SetTextFont(42);
    l.DrawLatex(0.01,0.943,"#bf{#it{CMS}} Internal 13 TeV");

}
