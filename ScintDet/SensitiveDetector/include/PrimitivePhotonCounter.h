#ifndef ELECTRON_SENSITIVEDETECTOR_H
#define ELECTRON_SENSITIVEDETECTOR_H

#include "G4VSensitiveDetector.hh"

class PrimitivePhotonCounter : public G4VSensitiveDetector{
public:
  PrimitivePhotonCounter(G4String);
  ~PrimitivePhotonCounter() = default;

  void Initialize(G4HCofThisEvent*) override;
  void EndOfEvent(G4HCofThisEvent*) override;

protected:
  G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;

private:
  void ResetCounter();
  G4int GetCounter();

  G4int count;
};

#endif // ELECTRON_SENSITIVEDETECTOR_H
