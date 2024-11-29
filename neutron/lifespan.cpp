#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "Shielding.hh"

#include "DetectorConstructionBase.h"
#include "ActionInitialization.h"
#include "RunAction.h"
#include "TrackingAction.h"
#include "FixedPrimaryGeneratorAction.h"
#include "UniformPrimaryGeneratorAction.h"
#include "G4SystemOfUnits.hh" 


int main(int argc, char* argv[]){

  auto runManager = new G4RunManager;
  runManager->SetUserInitialization(new Shielding);

  ActionInitialization* AI = new ActionInitialization;
  FixedPrimaryGeneratorAction* FPGA = new FixedPrimaryGeneratorAction("neutron", 0.01 * MeV);
  FPGA->SetPosition(G4ThreeVector(0.95, 0, 0));
  AI->RegisterPrimaryGeneratorAction(FPGA);
 // AI->RegisterPrimaryGeneratorAction(new UniformPrimaryGeneratorAction("neutron", 0.01 * MeV));
  RunAction* RA = new RunAction("/home/lev/geant4/my_projects/mag_course_proj/neutron/output/edge_lifespan.root");
  RA->SetHistName("lifespan");
  AI->RegisterRunAction(RA);
  AI->RegisterTrackingAction(new TrackingAction);
  runManager->SetUserInitialization(AI);

  runManager->SetUserInitialization(new DetectorConstructionBase);

  runManager->Initialize();
  runManager->BeamOn(10000);

  delete runManager;
  return 0;
}