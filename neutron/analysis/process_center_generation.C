#include <iostream>


void process_center_generation(){
  TFile in_file("/home/lev/geant4/my_projects/mag_course_proj/neutron/output/center_generation.root");
  auto tree = in_file.Get<TTree>("count");
  std::cout << tree << std::endl;
  double count;
  tree->SetBranchAddress("count", &count);
  TH1F* h1 = new TH1F("center neutrons", "center neutrons", 250, 0, 1000); 

  for (int i = 0; i < tree->GetEntries(); ++i) {
    tree->GetEntry(i);
    h1->Fill(count);
  }

  auto c1 = new TCanvas("c1","c1",200,10,700,500);
  h1->GetXaxis()->SetTitle("N gamma");
  h1->GetYaxis()->SetTitle("count");
  h1->Draw(); 
  c1->SaveAs("neutrons_center.png");
}