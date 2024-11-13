#ifndef TRACKING_ACTION_H
#define TRACKING_ACTION_H

#include "G4UserTrackingAction.hh"

class TrackingAction : public G4UserTrackingAction{
public:
  void PostUserTrackingAction(const G4Track*) override;
};

#endif // TRACKING_ACTION_H