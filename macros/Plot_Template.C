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
#include <TFitResult.h>
#include <TMatrixDSym.h>

#include "include/fit_functions.hh"


using namespace std;

string g_Path;
vector<string> g_File;
vector<string> g_Hist;
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

void Plot_Template(){
  setstyle(0);

  bool DO_BAND = true;
  int REBIN = 10;
  
  vector<int> g_Color;
  g_Color.push_back(kBlue+2);
  g_Color.push_back(kRed+2);
  g_Color.push_back(kGreen+2);
  g_Color.push_back(kMagenta+2);
  g_Color.push_back(kCyan+2);
  g_Color.push_back(kOrange+2);

  g_File.push_back("13Dec17/templates_tZ_ptSum850_annulus_0p55-0p9_12Dec17.root");
  g_Hist.push_back("MTP_regionA_QCD");
  //g_PlotTitle = "t #bar{t}+jets Region A";
  g_PlotTitle = "QCD Region B";
  
  int Nsample = g_File.size();

  g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/templates/";
  
  g_Xname = "#tilde{M}_{T'} [GeV]";

  vector<TH1F*> hist;

  vector<TH1F*> hist_func[3];

  
  for(int s = 0; s < Nsample; s++){
    TFile* f = new TFile((g_Path+g_File[s]).c_str(), "READ");

    char* hname = new char[100];
    sprintf(hname, "hist_%d", s);
    char* hname0 = new char[100];
    sprintf(hname0, "hist_%d_0", s);
    char* hname1 = new char[100];
    sprintf(hname1, "hist_%d_1", s);
    char* hname2 = new char[100];
    sprintf(hname2, "hist_%d_2", s);
  
    TH1F* hist_temp = (TH1F*) f->Get(g_Hist[s].c_str());
    if(hist_temp){
      hist.push_back( (TH1F*)hist_temp->Clone(hname) );
      hist_func[0].push_back( (TH1F*)hist_temp->Clone(hname0) );
      hist_func[1].push_back( (TH1F*)hist_temp->Clone(hname1) );
      hist_func[2].push_back( (TH1F*)hist_temp->Clone(hname2) );
      for(int i = 0; i < 3; i++)
	hist_func[i][s]->Reset();
    }
    else
      cout << "NO HIST" << endl;

  }

  int Nhist = hist.size();

  vector<TF1*> vfunc;

  TF1 *f_temp = new TF1("temp","[0]*exp([1]*x)", 1100., 2500);
  
  for(int h = 0; h < Nhist; h++){
    //hist[h]->Rebin(REBIN);
    // for(int i = 0; i < 3; i++)
    //   hist_func[i][h]->Rebin(REBIN);
    
    char fname[50];
    sprintf(fname, "func_%d", h);
    vfunc.push_back(new TF1(fname, GausExp, 
			    750., 3000., 5));

  // double S = par[0];
  // double mu = par[1];
  // double sig1 = par[2];
  // double sig2 = par[3];
  // double A = par[4];

    vfunc[h]->SetParName(0, "S");
    vfunc[h]->SetParName(1, "#mu");
    vfunc[h]->SetParName(2, "#sigma_{left}");
    vfunc[h]->SetParName(3, "#sigma_{right}");
    vfunc[h]->SetParName(4, "N");

    hist[h]->Fit(f_temp,"LLER");
    
    // initial values
    vfunc[h]->SetParameter(0, f_temp->GetParameter(1));
    vfunc[h]->SetParameter(1, 1000.);
    vfunc[h]->SetParameter(2, 50.);
    vfunc[h]->SetParameter(3, 220.);
    vfunc[h]->SetParameter(4, f_temp->GetParameter(0));

    // vfunc[h]->SetParLimits(0, 1000,1500.);
    //vfunc[h]->SetParLimits(1, 800.,1200.);
    //vfunc[h]->SetParLimits(2, 1000,1500.);
    //vfunc[h]->SetParameter(3, 10.);

    // vfunc[h]->Draw();
    
    TFitResultPtr result = hist[h]->Fit(fname, "SLLER");

    double CHI2 = 0.;
    double NCHI2 = 0;
    
    if(DO_BAND){
    int Nbins = hist[h]->GetNbinsX();
    for(int b = 0; b < Nbins; b++){
      cout << "bin # " << b << endl;
      double x0 = hist[h]->GetXaxis()->GetBinLowEdge(b+1);
      double x1 = hist[h]->GetXaxis()->GetBinUpEdge(b+1);
      double val = vfunc[h]->Integral(x0,x1);
      double valerr = vfunc[h]->IntegralError(x0,x1,result->GetParams(),
      		      result->GetCovarianceMatrix().GetMatrixArray());
      double Nchi2 = vfunc[h]->GetChisquare()/vfunc[h]->GetNDF();
      cout << Nchi2 << " !!!!!!!!!!! " << sqrt(Nchi2) << endl;

      NCHI2 += 1.;
      CHI2 += pow(hist[h]->GetBinContent(b+1)-val/(x1-x0), 2.)/
	(valerr*valerr/(x1-x0)/(x1-x0) + hist[h]->GetBinError(b+1)*hist[h]->GetBinError(b+1));
      
      // if(Nchi2 > 1)
      // 	valerr *= sqrt(Nchi2);
      valerr = sqrt(valerr*valerr + 0.02*0.02*val*val);
      
      //double valerr = 0;
      hist_func[0][h]->SetBinContent(b+1, val/(x1-x0)*REBIN);
      hist_func[0][h]->SetBinError(b+1, valerr/(x1-x0)*REBIN);
      hist_func[1][h]->SetBinContent(b+1, (val+valerr)/(x1-x0));
      hist_func[2][h]->SetBinContent(b+1, (val-valerr)/(x1-x0));
    }
    cout << CHI2 << " " << NCHI2 << endl;
    if(CHI2/NCHI2 > 1)
      for(int b = 0; b < Nbins; b++)
	hist_func[0][h]->SetBinError(b+1, hist_func[0][h]->GetBinError(b+1)*sqrt(CHI2/NCHI2));
    }
  }

  //return;
  
  double max = -1.;
  int imax = -1;
  for(int i = 0; i < Nhist; i++){
    hist[i]->Rebin(REBIN);
    //hist[i]->Scale(1./hist[i]->Integral());
    if(hist[i]->GetMaximum() > max){
      max = hist[i]->GetMaximum();
      imax = i;
    }
  }
  
  float width = hist[0]->GetBinWidth(1);
  char *yaxis = new char[100];
  sprintf(yaxis,"Events / %0.0f GeV", width);

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
  hist[imax]->GetYaxis()->SetTitle(yaxis);
  //hist[imax]->GetYaxis()->SetRangeUser(0.0001, hist[imax]->GetMaximum()*1.1);
  //hist[imax]->GetYaxis()->SetTitle(yaxis);
  //hist[imax]->GetYaxis()->SetTitle("N_{evt} / fb^{-1}");
  int Ntype[3];

  for(int i = 0; i < Nhist; i++){
    hist[i]->SetLineColor(g_Color[i]);
    hist[i]->SetLineWidth(3);
    hist[i]->SetMarkerColor(g_Color[i]);
    hist[i]->SetMarkerSize(0);
    hist[i]->SetFillColor(kWhite);
    hist[i]->Draw("SAME");
    if(DO_BAND){
      hist_func[0][i]->SetFillColor(kGreen+10);
      hist_func[0][i]->Draw("SAME E3");
      hist[i]->Draw("SAME");
    } else {
      vfunc[i]->Draw("SAME");
    }
    // hist_func[1][i]->Draw("SAME");
    //hist_func[2][i]->Draw("SAME");
  }

  // TLegend* leg = new TLegend(0.1588,0.68,0.3946,0.8947);
  // leg->SetTextFont(132);
  // leg->SetTextSize(0.045);
  // leg->SetFillColor(kWhite);
  // leg->SetLineColor(kWhite);
  // leg->SetShadowColor(kWhite);
  // leg->AddEntry(hist[0], "M_{T'} default", "l");
  // leg->AddEntry(hist[1], "#tilde{M}_{T'}", "l");
  // leg->AddEntry(hist[2], "M_{T'}(m_{soft})", "l");
  // leg->AddEntry(hist[3], "#tilde{M}_{T'}(m_{soft})", "l");
  // leg->AddEntry(hist[4], "#tilde{M}_{T'} \"hybrid\"", "l");
  // // leg->AddEntry(hist[1], "#tilde{M}_{T'}", "l");
  // // leg->AddEntry(hist[2], "fixed p_{top/Higgs}", "l");
  // // leg->AddEntry(hist[3], "fixed E_{top/Higgs}", "l");
  // leg->SetLineColor(kWhite);
  // leg->SetFillColor(kWhite);
  // leg->SetShadowColor(kWhite);
  // leg->Draw("SAME");

  TLatex l;
  l.SetTextFont(132);
  l.SetNDC();
  l.SetTextSize(0.05);
  l.SetTextFont(132);
  // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
  l.DrawLatex(0.6,0.943,g_PlotTitle.c_str());
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.15,0.943,"#bf{#it{CMS}} 13 TeV Simulation");	

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
