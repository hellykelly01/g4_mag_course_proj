#include "SensitiveDetectorConstruction.h"
#include "PrimitivePhotonCounter.h"

#include "G4LogicalVolumeStore.hh"
#include "G4SDManager.hh"

void SensitiveDetectorConstruction::ConstructSDandField(){
  PrimitivePhotonCounter* SD = new PrimitivePhotonCounter("PrimitivePhotonCounter");
  G4SDManager::GetSDMpointer()->AddNewDetector(SD);
  G4LogicalVolumeStore::GetInstance()->GetVolume("PhotoMultiplier")->SetSensitiveDetector(SD);
}