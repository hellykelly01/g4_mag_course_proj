#ifndef ACTION_INITIALIZATION_H
#define ACTION_INITIALIZATION_H

#include "G4VUserActionInitialization.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4UserRunAction.hh"
#include "G4UserTrackingAction.hh"

class ActionInitialization : public G4VUserActionInitialization
{
public:
  ActionInitialization() = default;
  ~ActionInitialization() override = default;
  
  void RegisterPrimaryGeneratorAction(G4VUserPrimaryGeneratorAction* PGA);
  void RegisterRunAction(G4UserRunAction* RA);
  void RegisterTrackingAction(G4UserTrackingAction* TA);

  void Build() const override;
private:
  G4VUserPrimaryGeneratorAction* userPrimaryGeneratorAction{nullptr};
  G4UserRunAction* userRunAction{nullptr};
  G4UserTrackingAction* userTrackingAction{nullptr};
};



#endif // ACTION_INITIALIZATION_H