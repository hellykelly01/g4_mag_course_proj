#include "FixedPrimaryGeneratorAction.h"

#include "G4Sphere.hh"
#include "G4LogicalVolumeStore.hh"

#include <exception>

FixedPrimaryGeneratorAction::FixedPrimaryGeneratorAction(const std::string& pName, const G4double& pEnergy) :
  PrimaryGeneratorActionBase(pName, pEnergy){}
   

G4ThreeVector FixedPrimaryGeneratorAction::GenerateParticlePosition() {
  if(primaryPosition.mag() > 1.0){
    throw std::runtime_error("Position in FixedPrimaryGeneratorAction must be normalized");
  }
  auto store = G4LogicalVolumeStore::GetInstance();
  G4double R = dynamic_cast<G4Sphere*>(store->GetVolume("ScintSphere")->GetSolid())->GetOuterRadius();
  return primaryPosition * R;
}
