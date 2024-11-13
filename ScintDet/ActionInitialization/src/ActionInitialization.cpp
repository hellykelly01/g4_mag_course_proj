#include "ActionInitialization.h"

void ActionInitialization::RegisterPrimaryGeneratorAction(G4VUserPrimaryGeneratorAction* PGA) { userPrimaryGeneratorAction = PGA; }

void ActionInitialization::RegisterRunAction(G4UserRunAction* RA) { userRunAction = RA; }

void ActionInitialization::RegisterTrackingAction(G4UserTrackingAction* TA) { userTrackingAction = TA; }

void ActionInitialization::Build() const {
  if(userPrimaryGeneratorAction){
    SetUserAction(userPrimaryGeneratorAction);
  }
  if(userRunAction){
    SetUserAction(userRunAction);
  }
  if(userTrackingAction){
    SetUserAction(userTrackingAction);
  }
  
}