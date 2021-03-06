#ifndef LSDetectorConstruction_h
#define LSDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4MaterialTable.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4Cons.hh"
#include "globals.hh"

#include <cmath>

class G4VPhysicalVolume;
class G4LogicalVolume;

class LSDetectorConstruction : public G4VUserDetectorConstruction {
public:
  LSDetectorConstruction();
  virtual ~LSDetectorConstruction();
  virtual G4VPhysicalVolume* Construct();
  virtual void ConstructSDandField();
  virtual void BuildMaterial();

private:
  /**
   * Detector Modification
   * The nominal length of the CO2 tube is 2m. This parameter allows changing the length of the CO2 tube.
   * Remember this is half of the additional length. It can be negative if you want a tube shorter than 2m.
   */
  G4double halfTubeLengthAddition = 0.50 * m;

  /**
   * WORLD
   * The names hx, hy, hz indicates the value is just half of the actual dimension.
   */
  G4double world_hx = 20 * m;
  G4double world_hy = 20 * m;
  G4double world_hz = 20 * m;
  G4Box * worldBox;
  G4LogicalVolume * worldLog;
  G4VPhysicalVolume * worldPhy;

  /**
   * Target VOLUME
   */

  G4Tubs * targetBox;
  G4LogicalVolume * targetLog;
  G4VPhysicalVolume * targetPhy;

  G4Tubs * CO2Box;
  G4LogicalVolume * CO2Log;
  G4VPhysicalVolume * CO2Phy;

  /**
   * Detector VOLUME
   * The names hx, hy, hz indicates the value is just half of the actual dimension.
   */
  G4double detector_hx = 0.05 * m;
  G4double detector_hy = 0.05 * m;
  G4double detector_radius = 4*2.54*cm;
  G4double detector_hz = 0.0001 * m;
  G4Tubs * detectorBox;
  G4LogicalVolume * detectorLog;
  G4VPhysicalVolume * detectorPhy;

  /**
   * Mirror VOLUME
   */
  G4double mirror_hx = 0.5 * m;
  G4double mirror_hy = 0.5 * m;
  G4double mirror_hz = 0.001 * m;
  G4Box * mirrorBox;
  G4LogicalVolume * mirrorLog;
  G4VPhysicalVolume * mirrorPhy;

  /**
   * CONE
   */
  G4Cons* cone;
  G4LogicalVolume * coneLog;
  G4VPhysicalVolume * conePhy;

  /**
   * MATERIALS
   */
  G4Material * fAir;
  G4Material * fAl;
  G4Material * fCO2;
  G4Material * fN2;
};

#endif
