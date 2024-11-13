#ifndef UNIFORM_PRIMARY_GENERATOR_ACTION_H
#define UNIFORM_PRIMARY_GENERATOR_ACTION_H

#include "PrimaryGeneratorActionBase.h"

class UniformPrimaryGeneratorAction : public PrimaryGeneratorActionBase{

public:
  using PrimaryGeneratorActionBase::PrimaryGeneratorActionBase;

protected:

  G4ThreeVector GenerateParticlePosition() override;
};

#endif // UNIFORM_PRIMARY_GENERATOR_ACTION_H