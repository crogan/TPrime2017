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
#include <TColor.h>
#include <TColorWheel.h>
#include <TH1D.h>
#include <TStyle.h>
#include <TLorentzVector.h>

#include "include/ReducedBase.hh"


using namespace std;

string g_Path;
vector<string> g_File;
vector<string> g_Tree;
vector<int> g_Hist;
vector<string> g_Title;
vector<bool> g_Bkg;
double g_Lumi;
string g_PlotTitle;
string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;

TColor *icolor[9][2];
int color_list[4][10];
int style_list[4][10];

void setstyle(int istyle);

double MTprime(TLorentzVector Top, TLorentzVector Higgs, int type = 0, float mTsoft = 175., float mHsoft = 125.);
double g_mHiggs;
double g_mTop;

std::pair<float,float> GetInterval(vector<float>& MT, float sigma);

void Plot_MTprime(){
  setstyle(0);

  g_mHiggs = 125.;
  g_mTop   = 175.;
  
  vector<int> g_Color;
  g_Color.push_back(kBlue+2);
  g_Color.push_back(kRed+2);
  g_Color.push_back(kGreen+2);
  g_Color.push_back(kMagenta+2);
  g_Color.push_back(kCyan+2);
  g_Color.push_back(kOrange+2);
  
  // g_File.push_back("signal/TbtH_1200_LH.root");
  // g_PlotTitle = "TbtH LH m_{T'} = 1.2 TeV";

  g_File.push_back("signal/TttH_1200_RH.root");
  g_PlotTitle = "TttH RH m_{T'} = 1.2 TeV";

  // g_File.push_back("signal/TbtH_1500_LH.root");
  // g_PlotTitle = "TbtH LH m_{T'} = 1.5 TeV";

  // g_File.push_back("signal/TttH_1500_RH.root");
  // g_PlotTitle = "TttH RH m_{T'} = 1.5 TeV";
  
  int Nsample = g_File.size();

  g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/12_10_17/";
  
  g_Xname = "M_{T} alternatives [GeV]";
  g_Xmin = 800.;
  g_Xmax = 1400.;

  // g_Xmin = 0.;
  // g_Xmax = 1.;
  g_NX = 40;

  int Nhist = 4;

  TH1D* hist[Nhist];
  vector<vector<float> > vMT;
  for(int i = 0; i < Nhist; i++){
    vMT.push_back(vector<float>());
    hist[i] = new TH1D(("h"+to_string(i)).c_str(),
		       ("h"+to_string(i)).c_str(),
		       g_NX,g_Xmin,g_Xmax);
  }

  
  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain("TPrime");
    chain->Add((g_Path+g_File[s]).c_str());

    ReducedBase* base = new ReducedBase(chain);

    int Nentry = base->fChain->GetEntries();

    cout << "Sample " << s << " | " << Nsample << endl;
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);
      if(e%(max(1,Nentry/10)) == 0)
	cout << "event " << e << " | " << Nentry << endl;

      TLorentzVector Top, Higgs;
      Top.SetPtEtaPhiM( base->pT_top,
			base->eta_top,
			base->phi_top,
			base->mass_top );
      Higgs.SetPtEtaPhiM( base->pT_higgs,
			  base->eta_higgs,
			  base->phi_higgs,
			  base->mass_higgs );

      if(Top.Pt() + Higgs.Pt() < 850.)
	continue;

      if(!base->isD)
	continue;
      
      int Njet = base->pT_extrajet->size();
      double etaMax = 0.;
      bool annulus = false;
      TLorentzVector jet;
      int Nextra = 0;
      for(int i = 0; i < Njet; i++){
	jet.SetPtEtaPhiM( base->pT_extrajet->at(i),
			  base->eta_extrajet->at(i),
			  base->phi_extrajet->at(i),
			  base->mass_extrajet->at(i) );
	if(jet.DeltaR(Higgs) > 0.55 && jet.DeltaR(Higgs) < 0.9)
	  annulus = true;
	if(jet.DeltaR(Higgs) < 1.2 || jet.DeltaR(Top) < 1.2)
	  continue;

	Nextra++;
	if(fabs(jet.Eta()) > etaMax)
	  etaMax = fabs(jet.Eta());
      }
      
      if(Nextra < 2)
	continue;

      if(annulus)
	continue;

      
      
      for(int h = 0; h < Nhist; h++){
	double MT = MTprime(Top, Higgs, h, base->mass_softdrop_top, base->mass_softdrop_higgs);
	hist[h]->Fill(MT, base->weight);
	vMT[h].push_back(MT);
	//hist[h]->Fill(base->tau3_top/base->tau2_top, base->weight);
      }

    }

    delete base;
    delete chain;
  }

  // Get Intervals
  vector<pair<float,float> > intervals;
  for(int i = 0; i < Nhist; i++){
    sort(vMT[i].begin(),vMT[i].end());
    intervals.push_back(GetInterval(vMT[i], 0.5));
    cout << intervals[i].first << " " << intervals[i].second << endl;
  }
    
  double max = -1.;
  int imax = -1;
  for(int i = 0; i < Nhist; i++){
    hist[i]->Scale(1./hist[i]->Integral());
    if(hist[i]->GetMaximum() > max){
      max = hist[i]->GetMaximum();
      imax = i;
    }
  }
  
  float width = hist[0]->GetBinWidth(1);
  char *yaxis = new char[100];
  sprintf(yaxis,"Events / %f", width);

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
  hist[imax]->Draw();
  hist[imax]->GetXaxis()->CenterTitle();
  hist[imax]->GetXaxis()->SetTitleFont(132);
  hist[imax]->GetXaxis()->SetTitleSize(0.06);
  hist[imax]->GetXaxis()->SetTitleOffset(1.06);
  hist[imax]->GetXaxis()->SetLabelFont(132);
  hist[imax]->GetXaxis()->SetLabelSize(0.05);
  hist[imax]->GetXaxis()->SetTitle(g_Xname.c_str());
  hist[imax]->GetYaxis()->CenterTitle();
  hist[imax]->GetYaxis()->SetTitleFont(132);
  hist[imax]->GetYaxis()->SetTitleSize(0.06);
  hist[imax]->GetYaxis()->SetTitleOffset(1.);
  hist[imax]->GetYaxis()->SetLabelFont(132);
  hist[imax]->GetYaxis()->SetLabelSize(0.05);
  hist[imax]->GetYaxis()->SetTitle("a. u.");
  hist[imax]->GetYaxis()->SetRangeUser(0.0001, hist[imax]->GetMaximum()*1.1);
  //hist[imax]->GetYaxis()->SetTitle(yaxis);
  //hist[imax]->GetYaxis()->SetTitle("N_{evt} / fb^{-1}");
  int Ntype[3];

  Ntype[0] = 0;
  for(int i = 0; i < Nhist; i++){
    hist[i]->SetLineColor(g_Color[i]);
    hist[i]->SetLineWidth(3);
    hist[i]->SetMarkerColor(g_Color[i]);
    hist[i]->SetMarkerSize(0);
    hist[i]->SetFillColor(kWhite);
    Ntype[0]++;
    hist[i]->Draw("SAME");
  }

  TLegend* leg = new TLegend(0.1588,0.68,0.3946,0.8947);
  leg->SetTextFont(132);
  leg->SetTextSize(0.045);
  leg->SetFillColor(kWhite);
  leg->SetLineColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->AddEntry(hist[0], "M_{T} default", "l");
  // leg->AddEntry(hist[1], "#tilde{M}_{T}", "l");
  // leg->AddEntry(hist[2], "M_{T}(m_{soft})", "l");
  // leg->AddEntry(hist[3], "#tilde{M}_{T}(m_{soft})", "l");
  // leg->AddEntry(hist[4], "#tilde{M}_{T} \"hybrid\"", "l");
  leg->AddEntry(hist[1], "#tilde{M}_{T}", "l");
  leg->AddEntry(hist[2], "fixed p_{top/Higgs}", "l");
  leg->AddEntry(hist[3], "fixed E_{top/Higgs}", "l");
  leg->SetLineColor(kWhite);
  leg->SetFillColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->Draw("SAME");

  TLatex l;
  l.SetTextFont(132);
  l.SetNDC();
  l.SetTextSize(0.05);
  l.SetTextFont(132);
  // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
  l.DrawLatex(0.6,0.943,g_PlotTitle.c_str());
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.14,0.943,"#bf{#it{CMS}} Simulation Preliminary");	

  // l.SetTextSize(0.045);
  // l.SetTextFont(132);
  // string bla = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(g_lumi))+" fb^{-1},  #Delta_{N#scale[0.8]{bkg}} = ";
  // bla += to_string(int(g_deltaNbkg))+" %";
  // l.DrawLatex(0.61,0.943,bla.c_str());


}

void setstyle(int istyle) {
	
  // For the canvas:
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetCanvasDefH(300); //Height of canvas
  gStyle->SetCanvasDefW(600); //Width of canvas
  gStyle->SetCanvasDefX(0);   //POsition on screen
  gStyle->SetCanvasDefY(0);
	
  // For the Pad:
  gStyle->SetPadBorderMode(0);
  // gStyle->SetPadBorderSize(Width_t size = 1);
  gStyle->SetPadColor(kWhite);
  gStyle->SetPadGridX(false);
  gStyle->SetPadGridY(false);
  gStyle->SetGridColor(0);
  gStyle->SetGridStyle(3);
  gStyle->SetGridWidth(1);
	
  // For the frame:
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameBorderSize(1);
  gStyle->SetFrameFillColor(0);
  gStyle->SetFrameFillStyle(0);
  gStyle->SetFrameLineColor(1);
  gStyle->SetFrameLineStyle(1);
  gStyle->SetFrameLineWidth(1);
	
  // set the paper & margin sizes
  gStyle->SetPaperSize(20,26);
  gStyle->SetPadTopMargin(0.065);
  gStyle->SetPadRightMargin(0.065);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.17);
	
  // use large Times-Roman fonts
  gStyle->SetTitleFont(132,"xyz");  // set the all 3 axes title font
  gStyle->SetTitleFont(132," ");    // set the pad title font
  gStyle->SetTitleSize(0.06,"xyz"); // set the 3 axes title size
  gStyle->SetTitleSize(0.06," ");   // set the pad title size
  gStyle->SetLabelFont(132,"xyz");
  gStyle->SetLabelSize(0.05,"xyz");
  gStyle->SetLabelColor(1,"xyz");
  gStyle->SetTextFont(132);
  gStyle->SetTextSize(0.08);
  gStyle->SetStatFont(132);
	
  // use bold lines and markers
  gStyle->SetMarkerStyle(8);
  gStyle->SetHistLineWidth(1.85);
  gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
	
  //..Get rid of X error bars
  gStyle->SetErrorX(0.001);
	
  // do not display any of the standard histogram decorations
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
	
  // put tick marks on top and RHS of plots
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
	
  // set a decent palette
  gStyle->SetPalette(1);
	
  gStyle->cd();
	
  TColorWheel *w = new TColorWheel();
	
  icolor[0][1] = new TColor(1390, 0.90, 0.60, 0.60, ""); //red
  icolor[0][0] = new TColor(1391, 0.70, 0.25, 0.25, "");
  icolor[1][1] = new TColor(1392, 0.87, 0.87, 0.91, ""); //blue
  icolor[1][0] = new TColor(1393, 0.59, 0.58, 0.91, "");
  icolor[2][1] = new TColor(1394, 0.65, 0.55, 0.85, ""); //violet (gamma)
  icolor[2][0] = new TColor(1395, 0.49, 0.26, 0.64, "");
  icolor[3][1] = new TColor(1396, 0.95, 0.95, 0.60, ""); // yellow (alpha)
  icolor[3][0] = new TColor(1397, 0.95, 0.95, 0.00, "");
  icolor[4][1] = new TColor(1398, 0.75, 0.92, 0.68, ""); //green (2beta+gamma)
  icolor[4][0] = new TColor(1399, 0.36, 0.57, 0.30, "");
  icolor[5][1] = new TColor(1400, 0.97, 0.50, 0.09, ""); // orange
  icolor[5][0] = new TColor(1401, 0.76, 0.34, 0.09, "");
  icolor[6][1] = new TColor(1402, 0.97, 0.52, 0.75, ""); // pink
  icolor[6][0] = new TColor(1403, 0.76, 0.32, 0.51, "");
  icolor[7][1] = new TColor(1404, 0.49, 0.60, 0.82, ""); // dark blue (kpnn)
  icolor[7][0] = new TColor(1405, 0.43, 0.48, 0.52, "");
  icolor[8][1] = new TColor(1406, 0.70, 0.70, 0.70, "");  // black
  icolor[8][0] = new TColor(1407, 0.40, 0.40, 0.40, "");
	
	
  if(istyle == 0){
		
    //SM MC
    color_list[3][0] = kCyan+3;
		
    //DATA
    color_list[0][0] = 1;
    color_list[0][1] = 2;
    color_list[0][2] = 4;
    style_list[0][0] = 20;
    style_list[0][1] = 23;
		
    //BKG MC
    color_list[1][0] = 0;
    color_list[1][3] = kGreen-9; //Light green
    color_list[1][5] = kOrange-2; //dark blue
    color_list[1][4] = kGreen+3; //yellow
    color_list[1][1] = kBlue-10; //light blue
    color_list[1][2] = kBlue+4; //dark green
    style_list[1][0] = 1001;
    style_list[1][1] = 1001;
    style_list[1][2] = 3002;
    style_list[1][3] = 1001;
    style_list[1][4] = 1001;
    style_list[1][5] = 1001;
		
    //SIG MC
    color_list[2][0] = 1;
    color_list[2][1] = 1;
    color_list[2][2] = 1;
    style_list[2][0] = 2;
    style_list[2][1] = 5;
  }
  if(istyle == 1){
		
    //SM MC
    color_list[3][0] = kSpring+4;
		
    //DATA
    color_list[0][0] = 1;
    color_list[0][1] = 2;
    color_list[0][2] = 4;
    style_list[0][0] = 20;
    style_list[0][1] = 23;
		
    //BKG MC
    color_list[1][0] = 0;
    color_list[1][1] = kGreen-9; //Light green
    color_list[1][2] = kGreen+3; //dark blue
    color_list[1][3] = kYellow-7; //yellow
    color_list[1][4] = kBlue-10; //light blue
    color_list[1][5] = kBlue+4; //dark blue
    style_list[1][0] = 1001;
    style_list[1][1] = 1001;
    style_list[1][2] = 3002;
    style_list[1][3] = 1001;
    style_list[1][4] = 1001;
    style_list[1][5] = 1001;
		
    //SIG MC
    color_list[2][0] = 1;
    color_list[2][1] = 1;
    color_list[2][2] = 1;
    style_list[2][0] = 2;
    style_list[2][1] = 5;
  }
  if(istyle == 2){
		
    //SM MC
    color_list[3][0] = kMagenta+2;
		
    //DATA
    color_list[0][0] = 1;
    color_list[0][1] = 2;
    color_list[0][2] = 4;
    style_list[0][0] = 20;
    style_list[0][1] = 23;
		
    //BKG MC
    color_list[1][0] = 0;
    color_list[1][3] = kRed-9; //Light green
    color_list[1][5] = kRed+3; //dark blue
    color_list[1][4] = kYellow-7; //yellow
    color_list[1][1] = kMagenta-10; //light blue
    color_list[1][2] = kMagenta+4; //dark green
    style_list[1][0] = 1001;
    style_list[1][1] = 1001;
    style_list[1][2] = 3002;
    style_list[1][3] = 1001;
    style_list[1][4] = 1001;
    style_list[1][5] = 1001;
		
    //SIG MC
    color_list[2][0] = 1;
    color_list[2][1] = 1;
    color_list[2][2] = 1;
    style_list[2][0] = 2;
    style_list[2][1] = 5;
  }
	
}

double MTprime(TLorentzVector Top, TLorentzVector Higgs, int type, float mTsoft, float mHsoft){
  if(type == 0){
    return (Top+Higgs).M();
  }
  if(type == 1){
    return (Top+Higgs).M() - Top.M() - Higgs.M() + g_mHiggs + g_mTop;
  }
  // if(type == 2){
  //   Top.SetPtEtaPhiM( Top.Pt(),
  // 		      Top.Eta(),
  // 		      Top.Phi(),
  // 		      mTsoft );
  //   Higgs.SetPtEtaPhiM( Higgs.Pt(),
  // 			Higgs.Eta(),
  // 			Higgs.Phi(),
  // 			mHsoft );
  //   return (Top+Higgs).M();
  // }
  // if(type == 3){
  //   Top.SetPtEtaPhiM( Top.Pt(),
  // 		      Top.Eta(),
  // 		      Top.Phi(),
  // 		      mTsoft );
  //   Higgs.SetPtEtaPhiM( Higgs.Pt(),
  // 			Higgs.Eta(),
  // 			Higgs.Phi(),
  // 			mHsoft );
  //   return (Top+Higgs).M() - Top.M() - Higgs.M() + g_mHiggs + g_mTop;
  // }
  // if(type == 4){
  //   return (Top+Higgs).M() - mTsoft - mHsoft + g_mHiggs + g_mTop;
  // }

  
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
  /*
  if(type == 4){
    return ((g_mTop/Top.M())*Top+(g_mHiggs/Higgs.M())*Higgs).M();
  }
  if(type == 5){
    TVector3 boost = (Top+Higgs).BoostVector();
    Top.Boost(-boost);
    Higgs.Boost(-boost);
    return sqrt(Top.P()*Top.P()+g_mTop*g_mTop)+sqrt(Higgs.P()*Higgs.P()+g_mHiggs*g_mHiggs);
  }
  */
  


}

std::pair<float,float> GetInterval(vector<float>& MT, float sigma){
  double P = TMath::Erf(sigma/sqrt(2.));
  int N = MT.size();

  double Dmin = fabs(MT[N-1]-MT[0]);

  int interval = N*P-1;

  int imin = 0, jmin = 0;
  for(int i = 0; i < N - interval; i++){
    double D = fabs(MT[i+interval]-MT[i]);
    if(D < Dmin){
      Dmin = D;
      imin = i;
      jmin = imin+interval;
    }
  }

  pair<float,float> ret(MT[imin],MT[jmin]);
  return ret;
}
