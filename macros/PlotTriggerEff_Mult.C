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
string g_Label;

string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;

void PlotTriggerEff_Mult(){
  RestFrames::SetStyle();

  // g_Label = "Trigger Preselection";
  
  // g_File.push_back("03Feb17ReReco2016_Hset_noDenom_Signal/TbtH_M-1000_LH.root");
  // g_Title.push_back("TbtH LH M_{T'} = 1 TeV");

  // g_File.push_back("03Feb17ReReco2016_Hset_noDenom_Signal/TbtZ_M-1000_RH.root");
  // g_Title.push_back("TbtZ RH M_{T'} = 1 TeV");

  // g_File.push_back("03Feb17ReReco2016_Hset_noDenom_Signal/TbtH_M-1200_LH.root");
  // g_Title.push_back("TbtH LH M_{T'} = 1.2 TeV");

  // g_File.push_back("03Feb17ReReco2016_Hset_noDenom_Signal/TbtZ_M-1200_RH.root");
  // g_Title.push_back("TbtZ RH M_{T'} = 1.2 TeV");
  
  /*
  g_Label = "t #bar{t} + jets MC";
  
  g_File.push_back("03Feb17ReReco2016_Hset_noDenom_Signal/TT.root");
  g_Title.push_back("trigger preselction");
  
  g_File.push_back("03Feb17ReReco2016_IsoMu24_Signal/TT.root");
  g_Title.push_back("trigger preselction + HLT IsoMu24");
  */

  /*
  g_Label = "2016 Data (13 TeV) trigger preselection + HLT IsoMu24";
  
  g_File.push_back("03Feb17ReReco2016_IsoMu24Trig/Run2016BG03Feb2017.root");
  g_Title.push_back("B-G w/ PFHT800");
  
  g_File.push_back("03Feb17ReReco2016_IsoMu24_900_all_redo2_Trig/Run2016BG.root");
  g_Title.push_back("B-G w/ PFHT900");

  g_File.push_back("03Feb17ReReco2016_IsoMu24_900_all_redo2_Trig/Run2016H.root");
  g_Title.push_back("H w/ PFHT900");
  */

  /*
  g_Label = "trigger preselection + HLT IsoMu24";
  
  g_File.push_back("03Feb17ReReco2016_IsoMu24_900_all_redo2_Trig/Run2016BH.root");
  g_Title.push_back("2016 Data B-H w/ PFHT900");

  g_File.push_back("03Feb17ReReco2016_IsoMu24_Signal/TT.root");
  g_Title.push_back("t #bar{t} + jets MC");
  */
  
  
  //string ifile = "/Users/crogan/Dropbox/SAMPLES/Tprime/trigger/03Feb17ReReco2016_IsoMu24_900ALL_Trig/Run2016BG03Feb2017.root";
  //string ifile = "/Users/crogan/Dropbox/SAMPLES/Tprime/trigger/03Feb17ReReco2016_IsoMu24Trig/Run2016BG03Feb2017.root";
  //string ifile = "/Users/crogan/Dropbox/SAMPLES/Tprime/trigger/MU/DATA_2016.root";
  //string ifile = "/Users/crogan/Dropbox/SAMPLES/Tprime/trigger/MU/DATA_2016.root";

  g_Xname = "p_{T}^{AK8,1} + p_{T}^{AK8,2} [GeV]";
  g_Xmin = 800.;
  g_Xmax = 1800.;
  g_NX = 24;

  // g_Xname = "#tilde{M}_{T'} [GeV]";
  // g_Xmin = 800.;
  // g_Xmax = 2000.;
  // g_NX = 24;

  int Nhist = g_File.size();

  g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/trigger/";

  double offset = (g_Xmax-g_Xmin)/g_NX/Nhist;
  
  TH1D* h_NUM[Nhist];
  TH1D* h_DEN[Nhist];
  for(int i = 0; i < Nhist; i++){
    h_NUM[i] = new TH1D(("h_NUM"+to_string(i)).c_str(),
			("h_NUM"+to_string(i)).c_str(),
			g_NX,g_Xmin+i*offset,g_Xmax+i*offset);
    h_DEN[i] = new TH1D(("h_DEN"+to_string(i)).c_str(),
			("h_DEN"+to_string(i)).c_str(),
			g_NX,g_Xmin+i*offset,g_Xmax+i*offset);
    h_NUM[i]->Sumw2();
    h_DEN[i]->Sumw2();
  }

  for(int f = 0; f < Nhist; f++){
  
  
    TChain* chain_NUM = new TChain("anatest/tree");
    chain_NUM->Add((g_Path+g_File[f]).c_str());

    TriggerBase* base = new TriggerBase(chain_NUM);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){

      int mymod = Nentry/10;
      if(mymod < 1)
	mymod = 1;
      if(e%mymod == 0)
	cout << " event = " << e << " : " << Nentry << endl;

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

      if(base->SoftDropMassAK8->at(0) < 105. && base->SoftDropMassAK8->at(1) < 105.)
	continue;
      
      if(base->PrunedMassAK8->at(0) < 65. || base->PrunedMassAK8->at(1) < 65.)
	continue;

      double MTp = (P4_AK8[0]+P4_AK8[1]).M() - P4_AK8[0].M() - P4_AK8[1].M() + 300.;

      double sumPT_AK8 = P4_AK8[0].Pt()+P4_AK8[1].Pt();

      if(P4_AK8[0].Pt() < 400.) continue;
      if(P4_AK8[1].Pt() < 400.) continue;

      //if(sumPT_AK8 < 850.) continue;

      //h_NUM[f]->Fill(MTp);
      h_NUM[f]->Fill(sumPT_AK8);
    }
   
    delete base;
    delete chain_NUM;

    TChain* chain_DEN = new TChain("ana/tree");
    chain_DEN->Add((g_Path+g_File[f]).c_str());
 
    base = (TriggerBase*) new TriggerBase(chain_DEN);
  
    Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      
      int mymod = Nentry/10;
      if(mymod < 1)
	mymod = 1;
      if(e%mymod == 0)
	cout << " event = " << e << " : " << Nentry << endl;

      base->GetEntry(e);
      
      int NAK8 = base->ptAK8->size();
      if(NAK8 < 2)
	continue;
      
      int NAK4 = base->ptAK4->size();
      if(NAK4 < 4)
	continue;

      TLorentzVector P4_AK8[2];

      for(int i = 0; i < 2; i++){
	P4_AK8[i].SetPtEtaPhiM(base->ptAK8->at(i),
			       base->etaAK8->at(i),
			       base->phiAK8->at(i),
			       base->MAK8->at(i));
      }

      if(base->SoftDropMassAK8->at(0) < 105. && base->SoftDropMassAK8->at(1) < 105.)
	continue;
      
      if(base->PrunedMassAK8->at(0) < 65. || base->PrunedMassAK8->at(1) < 65.)
	continue;
      
      double MTp = (P4_AK8[0]+P4_AK8[1]).M() - P4_AK8[0].M() - P4_AK8[1].M() + 300.;
      
      double sumPT_AK8 = P4_AK8[0].Pt()+P4_AK8[1].Pt();

      if(P4_AK8[0].Pt() < 400.) continue;
      if(P4_AK8[1].Pt() < 400.) continue;
      
      //if(sumPT_AK8 < 850.) continue;
      
      //h_DEN[f]->Fill(MTp);
      h_DEN[f]->Fill(sumPT_AK8);
      
    }

    delete base;
    delete chain_DEN;
  }
    
  g_Color.push_back(kBlue+2);
  g_Color.push_back(kRed+2);
  g_Color.push_back(kGreen+2);
  g_Color.push_back(kMagenta+2);
  g_Color.push_back(kCyan+2);
  g_Color.push_back(kOrange+2);

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
  h_NUM[0]->GetYaxis()->SetTitle("#epsilon  trigger OR");
  h_NUM[0]->GetYaxis()->SetRangeUser(0., 1.);
  for(int i = 0; i < Nhist; i++)
    gr[i]->Draw("P same");
 

  TLatex l;
  l.SetTextFont(132);
  l.SetNDC();
  l.SetTextSize(0.045);
  l.SetTextFont(132);
  // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
  l.DrawLatex(0.5,0.943,g_Label.c_str());
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  //l.DrawLatex(0.01,0.943,"#bf{#it{CMS}} Preliminary - 35.9 fb^{-1} (13 TeV)");
  l.DrawLatex(0.13,0.943,"#bf{#it{CMS}} Preliminary");
  
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
