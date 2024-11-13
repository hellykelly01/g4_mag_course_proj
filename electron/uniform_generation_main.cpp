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
#include "UniformPrimaryGeneratorAction.h"
#include "G4SystemOfUnits.hh" 


int main(int argc, char* argv[]){

  auto runManager = new G4RunManager;

  G4VModularPhysicsList* physicsList = new FTFP_BERT;
  physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  physicsList->RegisterPhysics(opticalPhysics);
  runManager->SetUserInitialization(physicsList);

  ActionInitialization* AI = new ActionInitialization;
  AI->RegisterPrimaryGeneratorAction(new UniformPrimaryGeneratorAction("e-", 1 * MeV));
  RunAction* RA = new RunAction("/home/lev/geant4/my_projects/mag_course_proj/electron/output/uniform_generation.root");
  RA->SetHistName("count");
  AI->RegisterRunAction(RA);
  runManager->SetUserInitialization(AI);

  runManager->SetUserInitialization(new SensitiveDetectorConstruction);

  runManager->Initialize();
  runManager->BeamOn(10000);

  delete runManager;
  return 0;
}