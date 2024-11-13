#ifndef SENSITIVE_DETECTOR_CONSTRUCTION
#define SENSITIVE_DETECTOR_CONSTRUCTION

#include "DetectorConstructionBase.h"

class SensitiveDetectorConstruction : public DetectorConstructionBase{
public:
  SensitiveDetectorConstruction() = default;
  ~SensitiveDetectorConstruction() = default;
  void ConstructSDandField() override;
};

#endif // SENSITIVE_DETECTOR_CONSTRUCTION