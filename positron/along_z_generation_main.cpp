#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "FTFP_BERT.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"


#include "SensitiveDetectorConstruction.h"
#include "ActionInitialization.h"
#include "RunAction.h"
#include "FixedPrimaryGeneratorAction.h"
#include "G4SystemOfUnits.hh" 

#include <string>
#include <vector>
#include <iostream>

inline std::string wrap_number(const double& num){
  return std::string("\"") + std::to_string(num) + std::string("\"");
}


int main(int argc, char* argv[]){

  auto runManager = new G4RunManager;

  G4VModularPhysicsList* physicsList = new FTFP_BERT;
  physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  physicsList->RegisterPhysics(opticalPhysics);
  runManager->SetUserInitialization(physicsList);

  ActionInitialization* AI = new ActionInitialization;
  FixedPrimaryGeneratorAction* FPGA = new FixedPrimaryGeneratorAction("e+", 3 * MeV);
  AI->RegisterPrimaryGeneratorAction(FPGA);
  RunAction* RA = new RunAction("/home/lev/geant4/my_projects/mag_course_proj/positron/output/along_z_generation.root");
  AI->RegisterRunAction(RA);
  runManager->SetUserInitialization(AI);

  runManager->SetUserInitialization(new SensitiveDetectorConstruction);

  runManager->Initialize();

  std::vector<double> z_pos = {-0.99, -0.95, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.95, 0.99};

  for (const double& z : z_pos){
    std::cout << "z = " << z << std::endl;
    FPGA->SetPosition(G4ThreeVector(0, 0, z));
    RA->SetHistName(wrap_number(z));
    runManager->GeometryHasBeenModified();
    runManager->BeamOn(2500);
  }

  delete runManager;
  return 0;
}