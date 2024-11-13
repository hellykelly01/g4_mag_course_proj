#ifndef DETECTOR_CONSTRUCTION_BASE_H
#define DETECTOR_CONSTRUCTION_BASE_H

#include "G4VUserDetectorConstruction.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;


class DetectorConstructionBase : public G4VUserDetectorConstruction
{
public:
  DetectorConstructionBase();
  ~DetectorConstructionBase() = default;

  G4VPhysicalVolume* Construct() override;

protected:
  void DefineMaterials();
  G4Material* fLAB;
  G4Material* fScintillator = nullptr;
  G4Material* fStainlessSteel = nullptr;
  G4Material* fPMMA = nullptr;

  G4RotationMatrix* CalcRotation(const G4ThreeVector& targetPosition);

  G4bool fCheckOverlaps = true;

};

#endif // DETECTOR_CONSTRUCTION_BASE_H

