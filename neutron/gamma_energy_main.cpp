#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "Shielding.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"
#include "G4ParticleHPManager.hh"

#include "DetectorConstructionBase.h"
#include "ActionInitialization.h"
#include "StackingAction.h"
#include "RunAction.h"
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
  RunAction* RA = new RunAction("/home/lev/geant4/my_projects/mag_course_proj/neutron/output/gamma_E_center.root");
  RA->SetHistName("E_gamma");
  AI->RegisterRunAction(RA);
  AI->RegisterStackingAction(new StackingAction);
  runManager->SetUserInitialization(AI);

  runManager->SetUserInitialization(new DetectorConstructionBase);

  G4ParticleHPManager::GetInstance()->SetUseOnlyPhotoEvaporation(true);
  G4ParticleHPManager::GetInstance()->SetDoNotAdjustFinalState(true);
  G4ParticleHPManager::GetInstance()->SetSkipMissingIsotopes(true);

  runManager->Initialize();
  runManager->BeamOn(5000);

  delete runManager;
  return 0;
}