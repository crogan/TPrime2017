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
#include "include/EventCount.hh"

double MTprime(TLorentzVector Top, TLorentzVector Higgs, int type = 0);
double g_mHiggs;
double g_mTop;

std::pair<float,float> GetInterval(vector<float>& MT, float sigma);

void PlotSampleBkg(){

  g_mHiggs = 125.;
  g_mTop   = 175.;
  
  vector<int> g_Color;
  g_Color.push_back(kBlue+2);
  g_Color.push_back(kRed+2);
  g_Color.push_back(kGreen+2);
  g_Color.push_back(kMagenta+2);
  g_Color.push_back(kCyan+2);
  g_Color.push_back(kOrange+2);
  
  vector<string> g_Files;

  // g_Files.push_back("TbtH_800_LH.root");
  // g_Files.push_back("TbtH_800_RH.root");
  // g_Files.push_back("TbtH_900_LH.root");
  // g_Files.push_back("TbtH_900_RH.root");
  // g_Files.push_back("TbtH_1000_LH.root");
  // g_Files.push_back("TbtH_1000_RH.root");
  // g_Files.push_back("TbtH_1100_LH.root");
  // g_Files.push_back("TbtH_1100_RH.root");
  // g_Files.push_back("TbtH_1200_LH.root");
  // g_Files.push_back("TbtH_1200_RH.root");
  // g_Files.push_back("TbtH_1300_LH.root");
  // g_Files.push_back("TbtH_1300_RH.root");
  // g_Files.push_back("TbtH_1400_LH.root");
  // g_Files.push_back("TbtH_1400_RH.root");
  // g_Files.push_back("TbtH_1500_LH.root");
  // g_Files.push_back("TbtH_1500_RH.root");
  // g_Files.push_back("TbtH_1700_LH.root");
  // g_Files.push_back("TbtH_1700_RH.root");
  // g_Files.push_back("TbtH_1800_LH.root");
  // g_Files.push_back("TbtH_1800_RH.root");

  g_Files.push_back("TttH_800_LH.root");
  g_Files.push_back("TttH_800_RH.root");
  g_Files.push_back("TttH_900_RH.root");
  g_Files.push_back("TttH_1000_LH.root");
  g_Files.push_back("TttH_1000_RH.root");
  g_Files.push_back("TttH_1100_LH.root");
  g_Files.push_back("TttH_1100_RH.root");
  g_Files.push_back("TttH_1200_LH.root");
  g_Files.push_back("TttH_1200_RH.root");
  g_Files.push_back("TttH_1300_LH.root");
  g_Files.push_back("TttH_1300_RH.root");
  g_Files.push_back("TttH_1400_LH.root");
  g_Files.push_back("TttH_1400_RH.root");
  g_Files.push_back("TttH_1500_LH.root");
  g_Files.push_back("TttH_1500_RH.root");
  g_Files.push_back("TttH_1700_LH.root");
  g_Files.push_back("TttH_1700_RH.root");
  g_Files.push_back("TttH_1800_LH.root");
  g_Files.push_back("TttH_1800_RH.root");

  int Nfile = g_Files.size();

  string g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/signal/";

  int Nhist = 5; // different types of MTprime calc

  
  vector<vector<float> > vMT;
  for(int i = 0; i < Nhist; i++){
    vMT.push_back(vector<float>());
  }

  float mean[Nhist][Nfile];
  float low[Nhist][3][Nfile];
  float high[Nhist][3][Nfile];

  double x[Nhist][Nfile];
  double y[Nhist][3][Nfile];
  
  TH1D* hist = (TH1D*) new TH1D("hist", "hist", Nfile, -0.5, double(Nfile)-0.5);
 
  for(int f = 0; f < Nfile; f++){
    // clear vectors
    for(int i = 0; i < Nhist; i++){
      vMT[i].clear();
      mean[i][f] = 0.;
    }
    
    TChain* chain = new TChain("TPrime");
    chain->Add((g_Path+g_Files[f]).c_str());
    ReducedBase* base = new ReducedBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);

      if(base->tau3_top/base->tau2_top > 0.57)
      	continue;
      
      TLorentzVector Top, Higgs;
      Top.SetPtEtaPhiM( base->pT_top,
			base->eta_top,
			base->phi_top,
			base->mass_top );
      Higgs.SetPtEtaPhiM( base->pT_higgs,
			  base->eta_higgs,
			  base->phi_higgs,
			  base->mass_higgs );
      
      for(int h = 0; h < Nhist; h++){
	double MT = MTprime(Top, Higgs, h);
	vMT[h].push_back(MT);
	mean[h][f] += MT;
      }
      
    }
    delete base;
    delete chain;
   
    pair<float,float> interval;
    for(int h = 0; h < Nhist; h++){
      sort(vMT[h].begin(),vMT[h].end());
      mean[h][f] /= vMT[h].size();

      x[h][f] = f + ((Nhist+2.)/2. - h-1.5)*float(1./(Nhist+2));
      for(int s = 0; s < 3; s++){
	interval = GetInterval(vMT[h], 0.5*(s+1));
	low[h][s][f] = interval.first;
	high[h][s][f] = interval.second;

	y[h][s][f] = 0.;
	
	//cout << interval.first << " " << interval.second << endl;
      }
    }
    
  }

  // Now loop over backgrounds...
  vector<string> g_BkgFiles;
  g_BkgFiles.push_back("bkg/QCDPt.root");
  g_BkgFiles.push_back("bkg/TTJets.root");
  //g_BkgFiles.push_back("bkg/ttHJets.root");
  g_BkgFiles.push_back("bkg/ttWJets.root");
  g_BkgFiles.push_back("bkg/ttZJets.root");
  g_BkgFiles.push_back("bkg/ST_antitop.root");
  g_BkgFiles.push_back("bkg/ST_top.root");
  g_BkgFiles.push_back("bkg/tHQ.root");
  //g_BkgFiles.push_back("bkg/DYJets.root");
  g_BkgFiles.push_back("bkg/WJets.root");
  g_BkgFiles.push_back("bkg/WW.root");
  g_BkgFiles.push_back("bkg/WZ.root");
  g_BkgFiles.push_back("bkg/ZJets.root");
  g_BkgFiles.push_back("bkg/ZZ.root");

  int NBkgfile = g_BkgFiles.size();

  string g_BkgPath = "/Users/crogan/Dropbox/SAMPLES/Tprime/";

  for(int b = 0; b < NBkgfile; b++){
    
    TChain* chain = new TChain("TPrime");
    chain->Add((g_BkgPath+g_BkgFiles[b]).c_str());
    ReducedBase* base = new ReducedBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);

      if(base->tau3_top/base->tau2_top > 0.57)
      	continue;
      
      TLorentzVector Top, Higgs;
      Top.SetPtEtaPhiM( base->pT_top,
			base->eta_top,
			base->phi_top,
			base->mass_top );
      Higgs.SetPtEtaPhiM( base->pT_higgs,
			  base->eta_higgs,
			  base->phi_higgs,
			  base->mass_higgs );
      
      for(int h = 0; h < Nhist; h++){
	double MT = MTprime(Top, Higgs, h);

	for(int f = 0; f < Nfile; f++){
	  for(int s = 0; s < 3; s++){
	    if(MT >= low[h][s][f] && MT <= high[h][s][f])
	      y[h][s][f] += base->weight;
	  }
	}
      }
    }
    delete base;
    delete chain;
  }

  for(int f = 0; f < Nfile; f++){
    for(int s = 0; s < 3; s++){
      for(int h = Nhist-1; h >= 0; h--){
  	y[h][s][f] /= y[0][s][f];
      }
    }
  }
  
  
  TGraph* gr[Nhist][3];
  
  for(int h = 0; h < Nhist; h++){
    for(int s = 0; s < 3; s++){
      gr[h][s] = (TGraph*) new TGraph(Nfile, x[h], y[h][s]);
      if(s == 0){
	gr[h][s]->SetLineWidth(0);
	gr[h][s]->SetMarkerSize(1);
	gr[h][s]->SetMarkerStyle(3);
      }
      if(s == 1){
	gr[h][s]->SetLineWidth(0);
	gr[h][s]->SetMarkerSize(1);
	gr[h][s]->SetMarkerStyle(3);
      }
      if(s == 2){
	gr[h][s]->SetLineWidth(0);
	gr[h][s]->SetMarkerSize(1);
	gr[h][s]->SetMarkerStyle(3);
      }
      gr[h][s]->SetMarkerColor(g_Color[h]);
      gr[h][s]->SetLineColor(g_Color[h]);
      gr[h][s]->SetFillColor(kWhite);
    }
  }
 
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
    // hist->SetBinContent(s+1, 0.);
    // hist->SetBinError(s+1, 0.);
    string label = g_Files[s];
    if(label.find(".root") != string::npos )
      label.erase(label.find(".root"));
    hist->GetXaxis()->SetBinLabel(s+1,label.c_str());
  }
  hist->LabelsOption("v","X");
  hist->SetLineColor(kBlack);
  hist->Draw();
  hist->GetXaxis()->CenterTitle();
  hist->GetXaxis()->SetTitleFont(132);
  hist->GetXaxis()->SetTitleSize(0.06);
  hist->GetXaxis()->SetTitleOffset(1.06);
  hist->GetXaxis()->SetLabelFont(132);
  hist->GetXaxis()->SetLabelSize(0.05);
  //h_NUM[0]->GetXaxis()->SetTitle("Signal");
  hist->GetYaxis()->CenterTitle();
  hist->GetYaxis()->SetTitleFont(132);
  hist->GetYaxis()->SetTitleSize(0.06);
  hist->GetYaxis()->SetTitleOffset(1.);
  hist->GetYaxis()->SetLabelFont(132);
  hist->GetYaxis()->SetLabelSize(0.05);
  hist->GetYaxis()->SetTitle("< N_{B} > in 1 #sigma relative to default M_{T'}");
  hist->GetYaxis()->SetRangeUser(0., 70.);
  for(int i = 0; i < Nhist; i++)
    gr[i][2]->Draw("P same");
 

  TLatex l;
  l.SetTextFont(132);
  l.SetNDC();
  l.SetTextSize(0.045);
  l.SetTextFont(132);
  // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
  l.DrawLatex(0.58,0.943, "Region D Selection, #epsilon_{top} = 0.3");
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.13,0.943,"#bf{#it{CMS}} 13 TeV Simulation");

  TLegend* leg = new TLegend(0.1588,0.68,0.3946,0.8947);
  leg->SetTextFont(132);
  leg->SetTextSize(0.045);
  leg->SetFillColor(kWhite);
  leg->SetLineColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->AddEntry(gr[0][0], "M_{T'} default", "p");
  leg->AddEntry(gr[1][0], "#tilde{M}_{T'}", "p");
  leg->AddEntry(gr[2][0], "fixed p_{top/Higgs}", "p");
  leg->AddEntry(gr[3][0], "fixed E_{top/Higgs}", "p");
  leg->SetLineColor(kWhite);
  leg->SetFillColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->Draw("SAME");
  
  
}

double MTprime(TLorentzVector Top, TLorentzVector Higgs, int type){
  if(type == 0){
    return (Top+Higgs).M();
  }
  if(type == 1){
    return (Top+Higgs).M() - Top.M() - Higgs.M() + g_mHiggs + g_mTop;
  }
  if(type == 2){
    Top.SetPtEtaPhiM( Top.Pt(), Top.Eta(), Top.Phi(), g_mTop);
    Higgs.SetPtEtaPhiM( Higgs.Pt(), Higgs.Eta(), Higgs.Phi(), g_mHiggs);
    return (Top+Higgs).M();
  }
  if(type == 3){
    double Ptop = sqrt(Top.E()*Top.E() - g_mTop*g_mTop);
    Top.SetPtEtaPhiE( Top.Pt()*Ptop/Top.P(), Top.Eta(), Top.Phi(), Top.E());
    double Phiggs = sqrt(Higgs.E()*Higgs.E() - g_mHiggs*g_mHiggs);
    Higgs.SetPtEtaPhiE( Higgs.Pt()*Phiggs/Higgs.P(), Higgs.Eta(), Higgs.Phi(), Higgs.E());
    return (Top+Higgs).M();
  }
  if(type == 4){
    return ((g_mTop/Top.M())*Top+(g_mHiggs/Higgs.M())*Higgs).M();
  }
  if(type == 5){
    TVector3 boost = (Top+Higgs).BoostVector();
    Top.Boost(-boost);
    Higgs.Boost(-boost);
    return sqrt(Top.P()*Top.P()+g_mTop*g_mTop)+sqrt(Higgs.P()*Higgs.P()+g_mHiggs*g_mHiggs);
  }

}

std::pair<float,float> GetInterval(vector<float>& MT, float sigma){
  double P = TMath::Erf(sigma/sqrt(2.));
  int N = MT.size();

  double Dmin = fabs(MT[N-1]-MT[0]);
  int imin = 0;
  for(int i = 0; i < N-1; i++)
    if(fabs(MT[i+1]-MT[i]) < Dmin){
      Dmin = fabs(MT[i+1]-MT[i]);
      imin = i;
    }

  int jmin = imin+1;
  int interval = N*P-2;
  while(interval > 0){
    if(imin == 0){
      interval--;
      jmin++;
      continue;
    }
    if(jmin == N-1){
      interval--;
      imin--;
      continue;
    }
    if( fabs(MT[imin]-MT[imin-1]) < fabs(MT[jmin+1]-MT[jmin]) ){
      interval--;
      imin--;
      continue;
    } else {
      interval--;
      jmin++;
      continue;
    }
  }

  pair<float,float> ret(MT[imin],MT[jmin]);
  return ret;
}
