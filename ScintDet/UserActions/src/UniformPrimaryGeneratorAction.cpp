#include "UniformPrimaryGeneratorAction.h"

#include "G4LogicalVolumeStore.hh"
#include "G4Sphere.hh"
#include "Randomize.hh"

G4ThreeVector UniformPrimaryGeneratorAction::GenerateParticlePosition(){
  auto store = G4LogicalVolumeStore::GetInstance();
  G4double R = dynamic_cast<G4Sphere*>(store->GetVolume("ScintSphere")->GetSolid())->GetOuterRadius();
  G4double r = R * pow(G4UniformRand(), 1.0 / 3.0);
  return GenerateRandomDirection() * r;
}