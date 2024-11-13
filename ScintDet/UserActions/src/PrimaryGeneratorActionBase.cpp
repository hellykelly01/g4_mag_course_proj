#include <cmath>

#include "PrimaryGeneratorActionBase.h"

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4Event.hh"
#include "Randomize.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4Sphere.hh"


G4ThreeVector PrimaryGeneratorActionBase::GenerateRandomDirection(){
  G4double theta = acos(1 - 2 * G4UniformRand());
  G4double phi = 2 * M_PI * G4UniformRand();
  return G4ThreeVector(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta));
}


PrimaryGeneratorActionBase::PrimaryGeneratorActionBase(const std::string& pName, const G4double& pEnergy) : particleName(pName), particleEnergy(pEnergy){
  fParticleGun = new G4ParticleGun(1);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName.c_str());
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleMomentumDirection(GenerateRandomDirection());
  fParticleGun->SetParticleEnergy(particleEnergy);

}

void PrimaryGeneratorActionBase::GeneratePrimaries(G4Event* event) {
  fParticleGun->SetParticlePosition(GenerateParticlePosition());
  fParticleGun->GeneratePrimaryVertex(event);

}

PrimaryGeneratorActionBase::~PrimaryGeneratorActionBase() { delete fParticleGun; }