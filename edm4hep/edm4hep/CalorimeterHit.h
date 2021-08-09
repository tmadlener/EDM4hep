// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CalorimeterHit_H
#define EDM4HEP_CalorimeterHit_H

#include "edm4hep/CalorimeterHitConst.h"
#include "edm4hep/CalorimeterHitObj.h"

#include "edm4hep/Vector3f.h"
#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class CalorimeterHit
 *  Calorimeter hit
 *  @author: F.Gaede, DESY
 */
class CalorimeterHit {

  friend class CalorimeterHitCollection;
  friend class CalorimeterHitCollectionIterator;
  friend class ConstCalorimeterHit;

public:

  /// default constructor
  CalorimeterHit();
  CalorimeterHit(unsigned long long cellID, float energy, float energyError, float time, edm4hep::Vector3f position, int type);

  /// constructor from existing CalorimeterHitObj
  CalorimeterHit(CalorimeterHitObj* obj);

  /// copy constructor
  CalorimeterHit(const CalorimeterHit& other);

  /// copy-assignment operator
  CalorimeterHit& operator=(const CalorimeterHit& other);

  /// support cloning (deep-copy)
  CalorimeterHit clone() const;

  /// destructor
  ~CalorimeterHit();

  /// conversion to const object
  operator ConstCalorimeterHit() const;

public:

  /// Access the detector specific (geometrical) cell id.
  const unsigned long long& getCellID() const;

  /// Access the energy of the hit in [GeV].
  const float& getEnergy() const;

  /// Access the error of the hit energy in [GeV].
  const float& getEnergyError() const;

  /// Access the time of the hit in [ns].
  const float& getTime() const;

  /// Access the position of the hit in world coordinates.
  const edm4hep::Vector3f& getPosition() const;

  /// Access the type of hit. Mapping of integer types to names via collection parameters "CalorimeterHitTypeNames" and "CalorimeterHitTypeValues".
  const int& getType() const;



  /// Set the detector specific (geometrical) cell id.
  void setCellID(unsigned long long value);

  /// Set the energy of the hit in [GeV].
  void setEnergy(float value);

  /// Set the error of the hit energy in [GeV].
  void setEnergyError(float value);

  /// Set the time of the hit in [ns].
  void setTime(float value);

  /// Set the position of the hit in world coordinates.
  void setPosition(edm4hep::Vector3f value);
  /// Get reference to position of the hit in world coordinates.
  edm4hep::Vector3f& position();

  /// Set the type of hit. Mapping of integer types to names via collection parameters "CalorimeterHitTypeNames" and "CalorimeterHitTypeValues".
  void setType(int value);






  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from CalorimeterHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const CalorimeterHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstCalorimeterHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const CalorimeterHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  CalorimeterHitObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstCalorimeterHit& value);

} // namespace edm4hep


#endif
