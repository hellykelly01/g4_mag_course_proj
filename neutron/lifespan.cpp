#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "FTFP_BERT.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"


#include "DetectorConstructionBase.h"
#include "ActionInitialization.h"
#include "RunAction.h"
#include "TrackingAction.h"
#include "FixedPrimaryGeneratorAction.h"
#include "G4SystemOfUnits.hh" 


int main(int argc, char* argv[]){

  auto runManager = new G4RunManager;

  G4VModularPhysicsList* physicsList = new FTFP_BERT;
  physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
  G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
  physicsList->RegisterPhysics(opticalPhysics);
  runManager->SetUserInitialization(physicsList);

  ActionInitialization* AI = new ActionInitialization;
  FixedPrimaryGeneratorAction* FPGA = new FixedPrimaryGeneratorAction("neutron", 0.01 * MeV);
  FPGA->SetPosition(G4ThreeVector(0, 0, 0));
  AI->RegisterPrimaryGeneratorAction(FPGA);
  RunAction* RA = new RunAction("/home/lev/geant4/my_projects/mag_course_proj/neutron/output/lifespan.root");
  RA->SetHistName("lifespan, microsec");
  AI->RegisterRunAction(RA);
  AI->RegisterTrackingAction(new TrackingAction);
  runManager->SetUserInitialization(AI);

  runManager->SetUserInitialization(new DetectorConstructionBase);

  runManager->Initialize();
  runManager->BeamOn(1000);

  delete runManager;
  return 0;
}