#include <iostream>
#include <string>


inline std::string unwrap_number(const std::string& str){
  if (str.size() < 3) {
    return ""; 
  } else {
    return str.substr(1, str.size() - 2); 
  }
}

int get_n_trees(const TFile& dir){
  int count = 0;
  TIter next(dir.GetListOfKeys());
  while (next()) count++;
  return count;
}

void process_along_axis_generation(){
  TFile in_file("/home/lev/geant4/my_projects/mag_course_proj/positron/output/along_z_generation.root");
  const int nPoints = get_n_trees(in_file);
  Double_t x[nPoints];
  Double_t y[nPoints];
  Double_t ex[nPoints];
  Double_t ey[nPoints];
  TIter next(in_file.GetListOfKeys());
  int i = 0;
  while (TObject *obj = next()){
    auto tree = in_file.Get<TTree>(obj->GetName());
    tree->Draw(obj->GetName());
    TH1F *htemp = (TH1F*)gPad->GetPrimitive("htemp");
    x[i] = std::stod(unwrap_number(obj->GetName()));
    ex[i] = 0;
    y[i] = htemp->GetMean();
    ey[i] = htemp->GetStdDev();
    std::cout << x[i] << " -> " << y[i] << " +/- " << ey[i] << std::endl;
    ++i;
  }
  auto c1 = new TCanvas("c1","A Simple Graph with error bars",200,10,700,500);
  TGraphErrors* gr = new TGraphErrors(nPoints, x, y, ex, ey);
    
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->SetTitle("response function");
  gr->GetXaxis()->SetTitle("Z");
  gr->GetYaxis()->SetTitle("count");
  gr->GetYaxis()->SetRangeUser(0, 400);
  gr->Draw("ALP");
  c1->SaveAs("positrons_along_z.png");
}