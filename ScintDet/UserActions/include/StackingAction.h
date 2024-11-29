#ifndef STACKING_ACTION_H
#define STACKING_ACTION_H

#include "G4UserStackingAction.hh"

class StackingAction : public G4UserStackingAction{
public:
  void PrepareNewEvent() override;
  G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* aTrack) override;
private:
  double energy{0.0};
};

#endif // STACKING_ACTION_H