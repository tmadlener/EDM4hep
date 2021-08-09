// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstCalorimeterHit_H
#define EDM4HEP_ConstCalorimeterHit_H

#include "edm4hep/CalorimeterHitObj.h"

#include "edm4hep/Vector3f.h"
#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstCalorimeterHit
 *  Calorimeter hit
 *  @author: F.Gaede, DESY
 */
class ConstCalorimeterHit {

  friend class CalorimeterHit;
  friend class CalorimeterHitCollection;
  friend class CalorimeterHitConstCollectionIterator;

public:
  /// default constructor
  ConstCalorimeterHit();
  ConstCalorimeterHit(unsigned long long cellID, float energy, float energyError, float time, edm4hep::Vector3f position, int type);

  /// constructor from existing CalorimeterHitObj
  ConstCalorimeterHit(CalorimeterHitObj* obj);

  /// copy constructor
  ConstCalorimeterHit(const ConstCalorimeterHit& other);

  /// copy-assignment operator
  ConstCalorimeterHit& operator=(const ConstCalorimeterHit& other);

  /// support cloning (deep-copy)
  ConstCalorimeterHit clone() const;

  /// destructor
  ~ConstCalorimeterHit();


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





  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from CalorimeterHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstCalorimeterHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const CalorimeterHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstCalorimeterHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  CalorimeterHitObj* m_obj;
};

} // namespace edm4hep


#endif
