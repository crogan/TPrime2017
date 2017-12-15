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

  // g_File.push_back("QCDPt.root");
  // g_PlotTitle = "QCD multijets";
  
  g_File.push_back("bkg/TTJets.root");
  g_File.push_back("bkg/ttHJets.root");
  g_File.push_back("bkg/ttWJets.root");
  g_File.push_back("bkg/ttZJets.root");
  g_PlotTitle = "t #bar{t} + X";

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
 
  // g_File.push_back("signal/TbtH_1000_LH.root");
  // g_PlotTitle = "TbtH LH M_{T'} = 1.2 TeV";

  // //g_File.push_back("signal/TbtH_1500_LH.root");
  // //g_PlotTitle = "TbtH LH M_{T'} = 1.5 TeV";

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

  g_Path = "/Users/crogan/Dropbox/SAMPLES/Tprime/12_10_17/";
  
  //string g_Label = "No selection";
  string g_Label = "Region D";


  g_Xname = "(P_{T}^{top}-p_{T}^{higgs})/M_{T'}";
  g_Xmin = -1.;
  g_Xmax = 1.; 
  g_NX = 30;
  g_Yname = "|#eta_{top}| - |#eta_{higgs}|";
  g_Ymin = 300.;
  g_Ymax = 1000.;
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
      
      // if(base->N_extra < 1)
      //  	continue;

      // if(base->M_Tp < 1200)
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
      double PCM = T.P();
      double PtCM = T.Pt();
      double mycos = T.Vect().Unit().Dot(-boost.Unit());
      TVector3 TT = T.Vect();
      TT.SetZ(0.);
      TVector3 BT = boost;
      BT.SetZ(0.);
      double mycosT = TT.Unit().Dot(-BT.Unit());
      T.Boost(boost);

      
      double v1 = (mycos-base->cosTq)/(2. - fabs(mycos+base->cosTq));
      double v2 = (mycos+base->cosTq)/(2. - fabs(mycos-base->cosTq));
      double v3 = sqrt(v1*v1+v2*v2)/sqrt(2);

      double etaMax = 0.;
      vector<TLorentzVector> P4_extra;

      int Nj = base->pT_extrajet->size();
      bool H_annul = false;
      for(int j = 0; j < Nj; j++){
      	TLorentzVector jet;
      	jet.SetPtEtaPhiM(base->pT_extrajet->at(j),
      			 base->eta_extrajet->at(j),
      			 base->phi_extrajet->at(j),
      			 base->mass_extrajet->at(j));
	if(jet.DeltaR(H) > 0.55 && jet.DeltaR(H) < 0.9)
	  H_annul = true;
	
 	if(jet.DeltaR(H) < 1.2 || jet.DeltaR(T) < 1.2)
	  continue;
	
	if(fabs(jet.Eta()) > etaMax)
	  etaMax = fabs(jet.Eta());

	P4_extra.push_back(jet);
      }

      if(!base->isD) continue;

      int Nextra = P4_extra.size();
      if( Nextra < 2) continue;

      if(etaMax < 2.4) continue;
      if(H_annul) continue;

      if(H.Pt() < 300.) continue;
      if(T.Pt() < 400.) continue;

      double HT4 = H.Pt() + T.Pt() + P4_extra[0].Pt() + P4_extra[1].Pt();
      if(HT4 < 900) continue;
      //if(H.Pt() + T.Pt()  < 850.) continue;

      double MTp = (H+T).M() - H.M() - T.M() + 300.;

      T.SetZ(0.);
      H.SetZ(0.);

      TVector3 P3_T = T.Vect();
      TVector3 P3_H = H.Vect();
      
      P3_T.SetZ(0.);
      P3_H.SetZ(0.);

      double val = (P3_T + P3_H).Unit().Dot(P3_H);
      

      P3_T = P3_T - P3_T.Dot(P3_T+P3_H)/(P3_T+P3_H).Mag2()*(P3_T+P3_H);
      val /= P3_T.Mag();

      //double chi = (H.Rapidity() - T.Rapidity())/fabs(H.Rapidity() - T.Rapidity())*exp(fabs(H.Rapidity() - T.Rapidity()));
      double chiT = (T.Pt() - H.Pt())/MTp;

      //double chiT = (sqrt(T.Pz()*T.Pz()) - sqrt(H.Pz()*H.Pz()))/MTp;

      // double chi = (T.Eta() - H.Eta());

      hist->Fill((H.Pt())/PCM, H.Pt(), base->weight);
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
    l.DrawLatex(0.6,0.943,g_PlotTitle.c_str());
    l.SetTextSize(0.04);
    l.SetTextFont(42);
    l.DrawLatex(0.01,0.943,"#bf{#it{CMS}} Internal 13 TeV Simulation");

    l.SetTextSize(0.04);
    l.SetTextFont(132);
    l.DrawLatex(0.74,0.04,g_Label.c_str());


}
