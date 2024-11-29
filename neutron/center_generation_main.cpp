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
#include "TrackingAction.h"
#include "FixedPrimaryGeneratorAction.h"
#include "G4SystemOfUnits.hh" 


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
  FPGA->SetPosition(G4ThreeVector(0, 0, 0));
  RunAction* RA = new RunAction("/home/lev/geant4/my_projects/mag_course_proj/neutron/output/center_generation.root");
  RA->SetHistName("count");
  AI->RegisterRunAction(RA);
  runManager->SetUserInitialization(AI);

  runManager->SetUserInitialization(new SensitiveDetectorConstruction);

  G4ParticleHPManager::GetInstance()->SetUseOnlyPhotoEvaporation(true);
  G4ParticleHPManager::GetInstance()->SetDoNotAdjustFinalState(true);
  G4ParticleHPManager::GetInstance()->SetSkipMissingIsotopes(true);

  runManager->Initialize();
  runManager->BeamOn(5000);

  delete runManager;
  return 0;
}