// C++ includes
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <dirent.h>

// ROOT includes
#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TList.h>
#include <TH1F.h>
#include <TFitResult.h>
#include <TMatrixDSym.h>
#include <TF1.h>

#include "include/fit_functions.hh"

using namespace std;

/// Main function that runs the analysis algorithm on the
/// specified input files
int main(int argc, char* argv[]) {

  bool DO_ERR = false;
  
  /// Gets the list of input files and chains
  /// them into a single TChain
  char inputFileName[1000];
  char outputFileName[1000];

  bool GOT_IFILE = false;
  bool GOT_OFILE = false;

  if ( argc < 2 ){
    cout << "Error at Input: please specify an input file name and an output filename:" << endl; 
    cout << "  Example:      ./SmoothTemplates.x -ifile=input.root -ofile=output.root"  << endl;
    
    return 1;
  }
  for (int i=0;i<argc;i++){
    if (strncmp(argv[i],"-ifile",6)==0){
      sscanf(argv[i],"-ifile=%s",  inputFileName);
      GOT_IFILE = true;
    }
    if (strncmp(argv[i],"-ofile",6)==0){
      sscanf(argv[i],"-ofile=%s",  outputFileName);
      GOT_OFILE = true;
    }
  }
  if(!(GOT_IFILE && GOT_OFILE)){
    cout << "Error at Input: please specify an input file name and an output filename:" << endl; 
    cout << "  Example:      ./SmoothTemplates.x -ifile=input.root -ofile=output.root"  << endl;
    
    return 1;
  }

  gROOT->ProcessLine("#include <vector>");

  vector<string> histonames;
  vector<string> systnames;
  
  std::cout << "Processing histograms from file " << inputFileName << " :" << endl;
    
  TFile* F = TFile::Open( inputFileName );
  TObjLink* link = F->GetListOfKeys()->FirstLink();

  TFile* fout = new TFile(outputFileName, "RECREATE");
  
  while(link){
    string name = link->GetObject()->GetName();

    // only keep histograms beginning with MTP
    if(name.find("MTP") == string::npos){
      link = link->Next();
      continue;
    }

    // pass these histograms through unchanged
    if( (name.find("TbtH") != string::npos) ||
	(name.find("TbtZ") != string::npos) ||
	(name.find("TttH") != string::npos) ||
	(name.find("TttZ") != string::npos)){
      TH1F* htemp = (TH1F*) F->Get(name.c_str());
      fout->cd();
      htemp->Write();
      htemp->Delete();
      link = link->Next();
      continue;
    }

    // write data histograms unchanged but
    // save for later use
    if(name.find("data") != string::npos){
      histonames.push_back(name);
      TH1F* htemp = (TH1F*) F->Get(name.c_str());
      fout->cd();
      htemp->Write();
      htemp->Delete();
      link = link->Next();
      continue;
    }

    // don't keep any 'MC' histograms
    if(name.find("_MC_") != string::npos){
      link = link->Next();
      continue;
    }

    // don't keep regionD_QCD
    if(name.find("regionD_QCD") != string::npos){
      link = link->Next();
      continue;
    }

    // don't keep any region D "est" histograms
    // going to remake these
    if(name.find("regionD_est") != string::npos){
      link = link->Next();
      continue;
    }

    histonames.push_back(name);

    // Use regionA_TTJets to get
    // list of systematics
    if( (name.find("regionA_TTJets") != string::npos) &&
	(name != "MTP_regionA_TTJets")){
      string stemp = name;
      stemp.erase(stemp.begin(),
		  stemp.begin()+stemp.find("TTJets")+6);
      systnames.push_back(stemp);
    }
    
    
    link = link->Next();
  }

  systnames.push_back("_lup"); // cludge for different named syst...

  vector<string> regionnames;
  regionnames.push_back("regionA");
  regionnames.push_back("regionB");
  regionnames.push_back("regionC");
  regionnames.push_back("regionD");
  
  int Nhist = histonames.size();
  int Nsyst = systnames.size();
  int Nreg  = regionnames.size();

  // for(int i = 0; i < Nsyst; i++)
  //   cout << systnames[i] << endl;
  
  map<string, map<string, TH1F*> > hist_data;
  map<string, map<string, TH1F*> > hist_TTJets;
  map<string, map<string, TH1F*> > hist_QCD;
  map<string, map<string, TH1F*> > hist_Other;
  
  for(int i = 0; i < Nhist; i++){
    string hname = histonames[i];
    TH1F* input_hist = (TH1F*) F->Get(hname.c_str());
    char* sname = new char[500];
    sprintf(sname,"hist_%d", i);
    TH1F* new_hist = (TH1F*) input_hist->Clone(sname);
    input_hist->Delete();

    hname.erase(hname.begin(),
		hname.begin()+hname.find("MTP")+4);
    string sregion = hname;
    sregion.erase(sregion.begin()+7,
		  sregion.end());
    hname.erase(hname.begin(),
		hname.begin()+8);

    string systname = "";
    for(int s = 0; s < Nsyst; s++){
      if( hname.find(systnames[s]) != string::npos ){
	systname = systnames[s];
	hname.erase(hname.begin()+hname.find(systname),
		    hname.end());
	break;
      }
    }

    // second part of cludge...
    if(systname == "_lup")
      systname = "_lUp";
    
    if(hname.find("data") != string::npos){
      if(hist_data.count(sregion) == 0){
	hist_data[sregion] = = new_hist;
	continue;
      }
    }

    if(hname == "TTJets"){
      if(hist_TTJets.count(sregion) == 0)
	hist_TTJets[sregion] = map<string, TH1F*>();
      if(hist_TTJets[sregion].count(systname) == 0)
	hist_TTJets[sregion][systname] = new_hist;
      continue;
    }
    if(hname == "QCD"){
      if(hist_QCD.count(sregion) == 0)
	hist_QCD[sregion] = map<string, TH1F*>();
      if(hist_QCD[sregion].count(systname) == 0)
	hist_QCD[sregion][systname] = new_hist;
      continue;
    }

    // Other
    if(hist_Other.count(sregion) == 0)
      hist_Other[sregion] = map<string, TH1F*>();
    if(hist_Other[sregion].count(systname) == 0){
      hist_Other[sregion][systname] = new_hist;
    } else {
      hist_Other[sregion][systname]->Add(new_hist);
      new_hist->Delete();
    }
  }

  systnames.pop_back(); // lup cludge
  systnames.push_back("");
  Nsyst = systnames.size();

  TF1 *f_exp = new TF1("f_exp","[0]*exp([1]*x)", 1100., 2500);
  TF1 *f_nom = new TF1("f_nom", GausExp, 750., 3000., 5);
  
  f_nom->SetParName(0, "S");
  f_nom->SetParName(1, "#mu");
  f_nom->SetParName(2, "#sigma_{left}");
  f_nom->SetParName(3, "#sigma_{right}");
  f_nom->SetParName(4, "N");

  // Do QCD Fits in region A, use for other QCD regions
  // and also for "Other" backgrounds
  if(hist_QCD.count("regionA") == 0)
    return 0;

  int Nbins;
  TH1F* hist = nullptr;
  // QCD Region A Fits
  for(int s = 0; s < Nsyst; s++){
    if(hist_QCD["regionA"].count(systnames[s]) == 0)
      continue;
    
    hist = hist_QCD["regionA"][systnames[s]];
    // exponential fit of tail to get starting values
    hist->Fit(f_exp,"LLERQ");

    // initial values for fit
    f_nom->SetParameter(0, f_exp->GetParameter(1));
    f_nom->SetParameter(1, 1000.);
    f_nom->SetParameter(2, 50.);
    f_nom->SetParameter(3, 220.);
    f_nom->SetParameter(4, f_exp->GetParameter(0));

    for(int i = 0; i < 5; i++){
      f_nom->ReleaseParameter(i);
    }
    TFitResultPtr result = hist->Fit("f_nom", "SLLERQ");

    // set function parameters to result
    for(int i = 0; i < 5; i++){
      f_nom->SetParameter(i, result->GetParams()[i]);
    }
    
    Nbins = hist->GetNbinsX();
    for(int b = 0; b < Nbins; b++){
      if(DO_ERR){
	double x0 = hist->GetXaxis()->GetBinLowEdge(b+1);
	double x1 = hist->GetXaxis()->GetBinUpEdge(b+1);
	double val = f_nom->Integral(x0,x1);
	hist->SetBinContent(b+1, val/(x1-x0));
	double valerr = f_nom->IntegralError(x0,x1,result->GetParams(),
					     result->GetCovarianceMatrix().GetMatrixArray());
	hist->SetBinError(b+1, valerr/(x1-x0));
      } else {
	double xC = hist->GetXaxis()->GetBinCenter(b+1);
	double val = f_nom->Eval(xC);
	hist->SetBinContent(b+1, val);
      }
    }

    for(int i = 0; i < 4; i++){
      f_nom->FixParameter(i, result->GetParams()[i]);
    }

    // fix shape parameters while floating normalization for other QCD region fits
    for(int r = 1; r < Nreg; r++){
      if(hist_QCD.count(regionnames[r]) == 0)
	continue;
      if(hist_QCD[regionnames[r]].count(systnames[s]) == 0)
	continue;
      
      hist = hist_QCD[regionnames[r]][systnames[s]];
      TFitResultPtr new_res = hist->Fit("f_nom", "SLLERQ");
      
      f_nom->SetParameter(4, new_res->GetParams()[4]);
      Nbins = hist->GetNbinsX();
      for(int b = 0; b < Nbins; b++){
	if(DO_ERR){
	double x0 = hist->GetXaxis()->GetBinLowEdge(b+1);
	double x1 = hist->GetXaxis()->GetBinUpEdge(b+1);
	double val = f_nom->Integral(x0,x1);
	hist->SetBinContent(b+1, val/(x1-x0));
	double valerr = f_nom->IntegralError(x0,x1,new_res->GetParams(),
					     new_res->GetCovarianceMatrix().GetMatrixArray());
	hist->SetBinError(b+1, valerr/(x1-x0));
      } else {
	double xC = hist->GetXaxis()->GetBinCenter(b+1);
	double val = f_nom->Eval(xC);
	hist->SetBinContent(b+1, val);
      }
      }
    }

    // fix shape parameters while floating normalization for "Other" backgrounds
    for(int r = 0; r < Nreg; r++){
      if(hist_Other.count(regionnames[r]) == 0)
	continue;
      if(hist_Other[regionnames[r]].count(systnames[s]) == 0)
	continue;
      
      hist = hist_Other[regionnames[r]][systnames[s]];
      TFitResultPtr new_res = hist->Fit("f_nom", "SLLERQ");
      
      f_nom->SetParameter(4, new_res->GetParams()[4]);
      Nbins = hist->GetNbinsX();
      for(int b = 0; b < Nbins; b++){
	if(DO_ERR){
	double x0 = hist->GetXaxis()->GetBinLowEdge(b+1);
	double x1 = hist->GetXaxis()->GetBinUpEdge(b+1);
	double val = f_nom->Integral(x0,x1);
	hist->SetBinContent(b+1, val/(x1-x0));
	double valerr = f_nom->IntegralError(x0,x1,new_res->GetParams(),
					     new_res->GetCovarianceMatrix().GetMatrixArray());
	hist->SetBinError(b+1, valerr/(x1-x0));
      } else {
	double xC = hist->GetXaxis()->GetBinCenter(b+1);
	double val = f_nom->Eval(xC);
	hist->SetBinContent(b+1, val);
      }
      }
    }
    
  }

  // TTJets all region fits
  for(int r = 0; r < Nreg; r++){
    if(hist_TTJets.count(regionnames[r]) == 0)
      continue;
    for(int s = 0; s < Nsyst; s++){
      if(hist_TTJets[regionnames[r]].count(systnames[s]) == 0)
	continue;
    
      hist = hist_TTJets[regionnames[r]][systnames[s]];
      // exponential fit of tail to get starting values
      hist->Fit(f_exp,"LLERQ");

      // initial values for fit
      f_nom->SetParameter(0, f_exp->GetParameter(1));
      f_nom->SetParameter(1, 1000.);
      f_nom->SetParameter(2, 50.);
      f_nom->SetParameter(3, 220.);
      f_nom->SetParameter(4, f_exp->GetParameter(0));

      for(int i = 0; i < 5; i++){
	f_nom->ReleaseParameter(i);
      }
      TFitResultPtr result = hist->Fit("f_nom", "SLLERQ");

      // set function parameters to result
      for(int i = 0; i < 5; i++){
	f_nom->SetParameter(i, result->GetParams()[i]);
      }
    
      Nbins = hist->GetNbinsX();
      for(int b = 0; b < Nbins; b++){
	if(DO_ERR){
	double x0 = hist->GetXaxis()->GetBinLowEdge(b+1);
	double x1 = hist->GetXaxis()->GetBinUpEdge(b+1);
	double val = f_nom->Integral(x0,x1);
	hist->SetBinContent(b+1, val/(x1-x0));
	double valerr = f_nom->IntegralError(x0,x1,result->GetParams(),
					     result->GetCovarianceMatrix().GetMatrixArray());
	hist->SetBinError(b+1, valerr/(x1-x0));
      } else {
	double xC = hist->GetXaxis()->GetBinCenter(b+1);
	double val = f_nom->Eval(xC);
	hist->SetBinContent(b+1, val);
      }
      }
    }
  }
    
    
    

  // if(DO_BAND){
  // int Nbins = hist[h]->GetNbinsX();
  // for(int b = 0; b < Nbins; b++){
  //   cout << "bin # " << b << endl;
  //   double x0 = hist[h]->GetXaxis()->GetBinLowEdge(b+1);
  //   double x1 = hist[h]->GetXaxis()->GetBinUpEdge(b+1);
  //   double val = vfunc[h]->Integral(x0,x1);
  //   double valerr = vfunc[h]->IntegralError(x0,x1,result->GetParams(),
  //   		      result->GetCovarianceMatrix().GetMatrixArray());
  //   //double valerr = 0;
  //   hist_func[0][h]->SetBinContent(b+1, val/(x1-x0));
  //   hist_func[0][h]->SetBinError(b+1, valerr/(x1-x0));
  //   hist_func[1][h]->SetBinContent(b+1, (val+valerr)/(x1-x0));
  //   hist_func[2][h]->SetBinContent(b+1, (val-valerr)/(x1-x0));
  
  for(int r = 0; r < Nreg; r++){
    for(int s = 0; s < Nsyst; s++){
  	if(hist_QCD.count(regionnames[r]) > 0){
  	  if(hist_QCD[regionnames[r]].count(systnames[s]) > 0){
  	    fout->cd();
  	    string histname = "MTP_"+regionnames[r]+"_QCD"+systnames[s];
  	    hist_QCD[regionnames[r]][systnames[s]]->Write(histname.c_str());
  	  }
  	}
    }
  }

  for(int r = 0; r < Nreg; r++){
    for(int s = 0; s < Nsyst; s++){
      if(hist_TTJets.count(regionnames[r]) > 0){
	if(hist_TTJets[regionnames[r]].count(systnames[s]) > 0){
	  fout->cd();
	  string histname = "MTP_"+regionnames[r]+"_TTJets"+systnames[s];
	  hist_TTJets[regionnames[r]][systnames[s]]->Write(histname.c_str());
	}
      }
    }
  }
  
  for(int r = 0; r < Nreg; r++){
    for(int s = 0; s < Nsyst; s++){
  	if(hist_Other.count(regionnames[r]) > 0){
  	  if(hist_Other[regionnames[r]].count(systnames[s]) > 0){
  	    fout->cd();
  	    string histname = "MTP_"+regionnames[r]+"_Other"+systnames[s];
  	    hist_Other[regionnames[r]][systnames[s]]->Write(histname.c_str());
  	  }
  	}							    
    }
  }

     
 
  return 0;
}
