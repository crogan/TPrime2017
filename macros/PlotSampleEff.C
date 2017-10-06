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

  string g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/TPrime_3p0/";

  string SignalModel = "TbtH_1200_LH";
  string plot_title = "TbtH LH, m_{T'} = 1200 GeV";

  TH1D* h_NUM = new TH1D("h_NUM", "h_NUM", Nfile, -0.5, double(Nfile)-0.5);
  TH1D* h_DEN = new TH1D("h_DEN", "h_DEN", Nfile, -0.5, double(Nfile)-0.5);
  h_NUM->Sumw2();
  h_DEN->Sumw2();

  for(int f = 0; f < Nfile; f++){
    TChain* chain = new TChain("TPrime");
    chain->Add((g_Path+g_Files[f]).c_str());

    ReducedBase* base = new ReducedBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);

      if(base->N_extra < 1)
       	continue;
      
      h_DEN->Fill(f, base->weight);

      h_NUM->Fill(f, base->weight);
    }
    delete base;
    delete chain;
  }

  TEfficiency* h_EFF = new TEfficiency(h_NUM, h_DEN);

  
  
 
    // gr_fix[icut] = (TGraph*) new TGraph(Nval,x,y[0]);
    // gr_float[icut] = (TGraph*) new TGraph(Nval,x,y[1]);
    // gr_fix[icut]->SetLineWidth(4);
    // gr_fix[icut]->SetLineColor(kBlue+2);
    // gr_fix[icut]->SetFillColor(kWhite);
    // gr_fix[icut]->SetMarkerSize(0);
    // gr_float[icut]->SetLineWidth(4);
    // gr_float[icut]->SetLineStyle(7);
    // gr_float[icut]->SetLineColor(kGreen+3);
    // gr_float[icut]->SetFillColor(kWhite);
    // gr_float[icut]->SetMarkerSize(0);
    // mg[icut] = (TMultiGraph*) new TMultiGraph();
    // mg[icut]->Add(gr_fix[icut]);
    // mg[icut]->Add(gr_float[icut]);

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
  h_EFF->Draw();
  h_EFF->GetXaxis()->CenterTitle();
  h_EFF->GetXaxis()->SetTitleFont(132);
  h_EFF->GetXaxis()->SetTitleSize(0.06);
  h_EFF->GetXaxis()->SetTitleOffset(1.06);
  h_EFF->GetXaxis()->SetLabelFont(132);
  h_EFF->GetXaxis()->SetLabelSize(0.05);
  h_EFF->GetXaxis()->SetTitle("Signal");
  h_EFF->GetYaxis()->CenterTitle();
  h_EFF->GetYaxis()->SetTitleFont(132);
  h_EFF->GetYaxis()->SetTitleSize(0.06);
  h_EFF->GetYaxis()->SetTitleOffset(1.);
  h_EFF->GetYaxis()->SetLabelFont(132);
  h_EFF->GetYaxis()->SetLabelSize(0.05);
  h_EFF->GetYaxis()->SetTitle("a. u.");
  h_EFF->GetYaxis()->SetTitle("1 - #epsilon");
  //hist[imax]->GetYaxis()->SetTitle("N_{evt} / fb^{-1}");
    
    // if(icut == 0){
    //   leg = (TLegend*) new TLegend(0.688,0.22,0.93,0.42);
    //   leg->SetTextFont(132);
    //   leg->SetTextSize(0.06);
    //   leg->AddEntry(gr_fix[icut],"#vec{c} |_{global max}");
    //   leg->AddEntry(gr_float[icut],"#vec{c} |_{local max}");
    //   leg->SetFillColor(kWhite);
    //   leg->SetLineColor(kWhite);
    //   leg->SetShadowColor(kWhite);
    // } 
    // leg->Draw("SAME");

    // TLatex l;
    // l.SetTextFont(132);	
    // l.SetNDC();	
    // l.SetTextSize(0.04);
    // l.SetTextFont(132);
    // l.DrawLatex(0.17,0.855,plot_title.c_str());
    // l.SetTextSize(0.04);
    // l.SetTextFont(42);
    // l.DrawLatex(0.15,0.943,"#bf{#it{ATLAS}} Internal");
    // l.SetTextSize(0.045);
    // l.SetTextFont(132);
    // string bla = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(g_lumi))+" fb^{-1},  #Delta_{N#scale[0.8]{bkg}} = ";
    // bla += to_string(int(g_deltaNbkg))+" %";
    // l.DrawLatex(0.55,0.943,bla.c_str());
  
}
