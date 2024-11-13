#ifndef PRIMARY_GENERATOR_ACTION_BASE_H
#define PRIMARY_GENERATOR_ACTION_BASE_H

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"

#include <string>

class G4ParticleGun;
class G4Event;

class PrimaryGeneratorActionBase : public G4VUserPrimaryGeneratorAction{

public:
  PrimaryGeneratorActionBase(const std::string& pName, const G4double& pEnergy);
  virtual ~PrimaryGeneratorActionBase();

  void GeneratePrimaries(G4Event*) override;
 
protected:

  G4ThreeVector GenerateRandomDirection();
  virtual G4ThreeVector GenerateParticlePosition() = 0;

private:
  std::string particleName;
  G4double particleEnergy;

  G4ParticleGun* fParticleGun = nullptr; 

};

#endif // PRIMARY_GENERATOR_ACTION_BASE_H