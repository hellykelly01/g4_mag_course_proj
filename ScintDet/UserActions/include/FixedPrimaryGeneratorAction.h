#ifndef FIXED_PRIMARY_GENERATOR_ACTION_H
#define FIXED_PRIMARY_GENERATOR_ACTION_H

#include "PrimaryGeneratorActionBase.h"

class FixedPrimaryGeneratorAction : public PrimaryGeneratorActionBase{
public:
  FixedPrimaryGeneratorAction(const std::string& pName, const G4double& pEnergy);
  void SetPosition(const G4ThreeVector& position) { primaryPosition = position; }
protected:
  G4ThreeVector GenerateParticlePosition() override;

private:
  G4ThreeVector primaryPosition;
};

#endif // FIXED_PRIMARY_GENERATOR_ACTION_H