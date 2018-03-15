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
#include <TF1.h>
#include <TPad.h>

//#include "include/fit_functions.hh"


using namespace std;

string g_Path;
string g_File_new;
string g_File_old;
vector<string> g_Hist_new;
vector<string> g_Hist_old;
vector<string> g_Label_new;
string g_Label_old;


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

void TemplateCompare(){
  setstyle(0);

  bool DO_BAND = true;
  int REBIN = 2;
  
  vector<int> g_Color;
  g_Color.push_back(kBlue+2);
  g_Color.push_back(kRed+2);
  g_Color.push_back(kGreen+2);
  g_Color.push_back(kMagenta+2);
  g_Color.push_back(kCyan+2);
  g_Color.push_back(kOrange+2);

  //g_File_new = "templates_tH_ptSum850_annulus_0p55-0p9_12Dec17_NEW.root";
  g_File_new = "test.root";
  g_Hist_new.push_back("MTP_regionA_Other");
  g_Label_new.push_back("Other smooth");
  g_Hist_new.push_back("MTP_regionA_TTJets");
  g_Label_new.push_back("t #bar{t} + jets smooth");
  g_Hist_new.push_back("MTP_regionA_QCD");
  g_Label_new.push_back("QCD smooth");

  //g_File_old = "templates_tZ_ptSum850_annulus_0p55-0p9_12Dec17.root";
  g_File_old = "test.root";
  //g_Hist_old.push_back("MTP_regionD_TTJets");
  g_Hist_old.push_back("MTP_regionA_data_obs");
  //g_Label_old = "t #bar{t} + jets MC";
  g_Label_old = "Data";

  g_PlotTitle = "Region C";
  
  int Nhist_new = g_Hist_new.size();
  int Nhist_old = g_Hist_old.size();

  g_Path = "./";
  //g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/templates/13Dec17/";
  
  g_Xname = "#tilde{M}_{T} [GeV]";

  vector<TH1F*> hist_new;
  vector<TH1F*> hist_old;

  for(int s = 0; s < Nhist_new; s++){
    TFile* f = new TFile((g_Path+g_File_new).c_str(), "READ");

    char* hname = new char[100];
    sprintf(hname, "histn_%d", s);
  
    TH1F* hist_temp = (TH1F*) f->Get(g_Hist_new[s].c_str());
    if(hist_temp){
      hist_new.push_back( (TH1F*)hist_temp->Clone(hname) );
      TF1* func = hist_new[hist_new.size()-1]->GetFunction("f_nom");
      // if(func)
      // 	func->Delete();
    }
    else
      cout << "NO HIST" << endl;
  }

  for(int s = 0; s < Nhist_old; s++){
    TFile* f = new TFile((g_Path+g_File_old).c_str(), "READ");

    char* hname = new char[100];
    sprintf(hname, "histo_%d", s);
  
    TH1F* hist_temp = (TH1F*) f->Get(g_Hist_old[s].c_str());
    if(hist_temp){
      hist_old.push_back( (TH1F*)hist_temp->Clone(hname) );
    }
    else
      cout << "NO HIST" << endl;
  }


  Nhist_new = hist_new.size();
  Nhist_old = hist_old.size();

  if(Nhist_old > 1){
    for(int i = 1; i < Nhist_old; i++){
      hist_old[0]->Add(hist_old[i]);
    }
  }

  if(Nhist_new > 1){
    hist_new.push_back((TH1F*)hist_new[0]->Clone("TotBack"));
    for(int i = 1; i < Nhist_new; i++){
      hist_new[Nhist_new]->Add(hist_new[i]);
    }
    g_Label_new.push_back("Total Background");
    Nhist_new++;
  }

  hist_old[0]->Rebin(REBIN);
  float width = hist_old[0]->GetBinWidth(1);
  char *yaxis = new char[100];
  sprintf(yaxis,"Events / %0.0f GeV", width);

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
  TCanvas* can = (TCanvas*) new TCanvas("can","can",850.,900);
  can->Draw();
  can->cd();
  TPad* top = new TPad("top","top", 0., 0.3, 1., 1.);
  top->Draw();
  top->cd();
  top->SetGridx();
  top->SetGridy();
  top->SetLeftMargin(0.13);
  top->SetRightMargin(0.04);
  top->SetBottomMargin(0.15);
  top->SetTopMargin(0.085);
  
  
  hist_old[0]->Draw();
  hist_old[0]->GetXaxis()->CenterTitle();
  hist_old[0]->GetXaxis()->SetTitleFont(132);
  hist_old[0]->GetXaxis()->SetTitleSize(0.06);
  hist_old[0]->GetXaxis()->SetTitleOffset(1.06);
  hist_old[0]->GetXaxis()->SetLabelFont(132);
  hist_old[0]->GetXaxis()->SetLabelSize(0.05);
  hist_old[0]->GetXaxis()->SetTitle(g_Xname.c_str());
  hist_old[0]->GetYaxis()->CenterTitle();
  hist_old[0]->GetYaxis()->SetTitleFont(132);
  hist_old[0]->GetYaxis()->SetTitleSize(0.06);
  hist_old[0]->GetYaxis()->SetTitleOffset(1.);
  hist_old[0]->GetYaxis()->SetLabelFont(132);
  hist_old[0]->GetYaxis()->SetLabelSize(0.05);
  hist_old[0]->GetYaxis()->SetTitle(yaxis);
  //hist[imax]->GetYaxis()->SetRangeUser(0.0001, hist[imax]->GetMaximum()*1.1);
  //hist[imax]->GetYaxis()->SetTitle(yaxis);
  //hist[imax]->GetYaxis()->SetTitle("N_{evt} / fb^{-1}");
  int Ntype[3];

  for(int i = Nhist_new-1; i >= 0; i--){
    hist_new[i]->Scale(REBIN);
    hist_new[i]->SetLineColor(g_Color[i]-11);
    hist_new[i]->SetLineWidth(3);
    hist_new[i]->SetMarkerColor(g_Color[i]-11);
    hist_new[i]->SetMarkerSize(0);
    hist_new[i]->SetFillColor(g_Color[i]-11);
    hist_new[i]->Draw("SAME E3");
  }
  
  hist_old[0]->SetLineColor(kBlack);
  hist_old[0]->SetLineWidth(2);
  hist_old[0]->SetMarkerColor(kBlack);
  hist_old[0]->SetMarkerSize(1);
  hist_old[0]->SetMarkerStyle(22);
  hist_old[0]->SetFillColor(kWhite);
  hist_old[0]->Draw("SAME");

  TLegend* leg = new TLegend(0.649811,0.637551,0.930425,0.853061);
  leg->SetTextFont(132);
  leg->SetTextSize(0.045);
  leg->SetFillColor(kWhite);
  leg->SetLineColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->AddEntry(hist_old[0], g_Label_old.c_str(), "p");
  for(int i = Nhist_new-1; i >= 0; i--){
    leg->AddEntry(hist_new[i], g_Label_new[i].c_str(), "f");
    
  }
  // leg->AddEntry(hist[0], "M_{T'} default", "l");
  // leg->AddEntry(hist[1], "#tilde{M}_{T'}", "l");
  // leg->AddEntry(hist[2], "M_{T'}(m_{soft})", "l");
  // leg->AddEntry(hist[3], "#tilde{M}_{T'}(m_{soft})", "l");
  // leg->AddEntry(hist[4], "#tilde{M}_{T'} \"hybrid\"", "l");
  // leg->AddEntry(hist[1], "#tilde{M}_{T'}", "l");
  // leg->AddEntry(hist[2], "fixed p_{top/Higgs}", "l");
  // leg->AddEntry(hist[3], "fixed E_{top/Higgs}", "l");
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
  l.DrawLatex(0.82,0.943,g_PlotTitle.c_str());
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.15,0.943,"#bf{#it{CMS}} Preliminary");	

  // l.SetTextSize(0.045);
  // l.SetTextFont(132);
  // string bla = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(g_lumi))+" fb^{-1},  #Delta_{N#scale[0.8]{bkg}} = ";
  // bla += to_string(int(g_deltaNbkg))+" %";
  // l.DrawLatex(0.61,0.943,bla.c_str());

  can->cd();

  TH1F* ratio = (TH1F*)hist_old[0]->Clone("Ratio");
  TH1F* DEN   = (TH1F*)hist_new[Nhist_new-1]->Clone("DEN");
  DEN->Scale(1./double(REBIN));
  DEN->Rebin(REBIN);
  ratio->Divide(DEN);

  TPad* bot = new TPad("bot","bot", 0., 0.0, 1., 0.4);
  bot->Draw();
  bot->cd();
  bot->SetGridx();
  bot->SetGridy();
  bot->SetLeftMargin(0.13);
  bot->SetRightMargin(0.04);
  bot->SetBottomMargin(0.25);
  bot->SetTopMargin(0.05);

  ratio->Draw();
  ratio->GetXaxis()->CenterTitle();
  ratio->GetXaxis()->SetTitleFont(132);
  ratio->GetXaxis()->SetTitleSize(0.1);
  ratio->GetXaxis()->SetTitleOffset(1.06);
  ratio->GetXaxis()->SetLabelFont(132);
  ratio->GetXaxis()->SetLabelSize(0.08);
  ratio->GetXaxis()->SetTitle(g_Xname.c_str());
  ratio->GetYaxis()->CenterTitle();
  ratio->GetYaxis()->SetTitleFont(132);
  ratio->GetYaxis()->SetTitleSize(0.11);
  ratio->GetYaxis()->SetTitleOffset(0.56);
  ratio->GetYaxis()->SetLabelFont(132);
  ratio->GetYaxis()->SetLabelSize(0.08);
  ratio->GetYaxis()->SetTitle("raw / smooth");
  ratio->GetYaxis()->SetRangeUser(0.0, 2.);

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
  //gStyle->SetErrorX(0.001);
	
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
