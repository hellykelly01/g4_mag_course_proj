#include <string>


void process_gamma_E(){

  TFile in_file("/home/lev/geant4/my_projects/mag_course_proj/neutron/output/gamma_E_center.root");
  auto tree = in_file.Get<TTree>("E_gamma");
  double E_gamma;
  tree->SetBranchAddress("E_gamma", &E_gamma);
  TH1F* h1 = new TH1F("total gamma E", "total gamma E", 200, 0, 10); 

  for (int i = 0; i < tree->GetEntries(); ++i) {
    tree->GetEntry(i);
    h1->Fill(E_gamma);
  }

  auto c1 = new TCanvas("c1","c1",200,10,700,500);
  h1->GetXaxis()->SetTitle("E gamma");
  h1->GetYaxis()->SetTitle("count");
  h1->Draw(); 
  c1->SaveAs("total_E_gamma_center.png");
}