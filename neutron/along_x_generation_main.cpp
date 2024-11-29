#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "Shielding.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"
#include "G4ParticleHPManager.hh"

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

  G4VModularPhysicsList* physicsList = new Shielding;
  physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  physicsList->RegisterPhysics(opticalPhysics);
  runManager->SetUserInitialization(physicsList);

  ActionInitialization* AI = new ActionInitialization;
  FixedPrimaryGeneratorAction* FPGA = new FixedPrimaryGeneratorAction("neutron", 0.01 * MeV);
  AI->RegisterPrimaryGeneratorAction(FPGA);
  RunAction* RA = new RunAction("/home/lev/geant4/my_projects/mag_course_proj/neutron/output/along_x_generation.root");
  AI->RegisterRunAction(RA);
  runManager->SetUserInitialization(AI);

  runManager->SetUserInitialization(new SensitiveDetectorConstruction);

  G4ParticleHPManager::GetInstance()->SetUseOnlyPhotoEvaporation(true);
  G4ParticleHPManager::GetInstance()->SetDoNotAdjustFinalState(true);
  G4ParticleHPManager::GetInstance()->SetSkipMissingIsotopes(true);


  runManager->Initialize();

  std::vector<double> x_pos = {-0.95, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.95};

  for (const double& x : x_pos){
    std::cout << "x = " << x << std::endl;
    FPGA->SetPosition(G4ThreeVector(x, 0, 0));
    RA->SetHistName(wrap_number(x));
    runManager->GeometryHasBeenModified();
    runManager->BeamOn(3000);
  }

  delete runManager;
  return 0;
}