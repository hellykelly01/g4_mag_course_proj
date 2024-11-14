#include <string>


void process_lifespan(){

  TFile in_file("/home/lev/geant4/my_projects/mag_course_proj/neutron/output/lifespan.root");
  auto tree = in_file.Get<TTree>("lifespan");
  double lifespan;
  tree->SetBranchAddress("lifespan", &lifespan);
  TH1F* h1 = new TH1F("neutron lifespan", "neutron lifespan", 200, 0, 200); 

  for (int i = 0; i < tree->GetEntries(); ++i) {
    tree->GetEntry(i);
    h1->Fill(lifespan);
  }

  auto c1 = new TCanvas("c1","c1",200,10,700,500);
  h1->GetXaxis()->SetTitle("microsec");
  h1->GetYaxis()->SetTitle("count");
  auto fit_res = h1->Fit("expo", "RS", "", 20, 180);
  TLatex* latex = new TLatex();
  latex->SetNDC(); // Set the text to be in Normalized Device Coordinates (NDC)
  latex->SetTextSize(0.05); // Adjust the text size as needed

  h1->Draw(); 
  std::string lettering = "#tau = ";
  lettering += std::to_string(1/ abs(fit_res->Parameter(1)));
  lettering += " microsec";
  latex->DrawLatex(0.5, 0.5, lettering.c_str());
  c1->SaveAs("neutron_lifespan.png");
}