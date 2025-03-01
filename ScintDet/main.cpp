#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "Shielding.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"


#include "SensitiveDetectorConstruction.h"
#include "ActionInitialization.h"
#include "RunAction.h"
#include "FixedPrimaryGeneratorAction.h"
#include "G4SystemOfUnits.hh" 

#include "G4AnalysisManager.hh"
#include <iostream>

int main(int argc, char* argv[]){

  auto runManager = new G4RunManager;

  G4VModularPhysicsList* physicsList = new Shielding;
  physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  physicsList->RegisterPhysics(opticalPhysics);
  runManager->SetUserInitialization(physicsList);

  ActionInitialization* AI = new ActionInitialization;
  FixedPrimaryGeneratorAction* FPGA = new FixedPrimaryGeneratorAction("neutron", 0.01 * MeV);
  FPGA->SetPosition(G4ThreeVector(0, 0, 0));
  AI->RegisterPrimaryGeneratorAction(FPGA);
  RunAction* RA = new RunAction("/home/lev/geant4/my_projects/mag_course_proj/ScintDet/build/test.root");
  RA->SetHistName("count");
  AI->RegisterRunAction(RA);
  runManager->SetUserInitialization(AI);

  runManager->SetUserInitialization(new SensitiveDetectorConstruction);

  runManager->Initialize();
  G4UIExecutive* ui = new G4UIExecutive(argc, argv);
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  ui->SessionStart();


  delete runManager;
  
  return 0;
}