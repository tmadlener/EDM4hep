// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstRawCalorimeterHit_H
#define EDM4HEP_ConstRawCalorimeterHit_H

#include "edm4hep/RawCalorimeterHitObj.h"

#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstRawCalorimeterHit
 *  Raw calorimeter hit
 *  @author: F.Gaede, DESY
 */
class ConstRawCalorimeterHit {

  friend class RawCalorimeterHit;
  friend class RawCalorimeterHitCollection;
  friend class RawCalorimeterHitConstCollectionIterator;

public:
  /// default constructor
  ConstRawCalorimeterHit();
  ConstRawCalorimeterHit(unsigned long long cellID, int amplitude, int timeStamp);

  /// constructor from existing RawCalorimeterHitObj
  ConstRawCalorimeterHit(RawCalorimeterHitObj* obj);

  /// copy constructor
  ConstRawCalorimeterHit(const ConstRawCalorimeterHit& other);

  /// copy-assignment operator
  ConstRawCalorimeterHit& operator=(const ConstRawCalorimeterHit& other);

  /// support cloning (deep-copy)
  ConstRawCalorimeterHit clone() const;

  /// destructor
  ~ConstRawCalorimeterHit();


public:

  /// Access the detector specific (geometrical) cell id.
  const unsigned long long& getCellID() const;

  /// Access the amplitude of the hit in ADC counts.
  const int& getAmplitude() const;

  /// Access the time stamp for the hit.
  const int& getTimeStamp() const;





  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RawCalorimeterHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstRawCalorimeterHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const RawCalorimeterHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstRawCalorimeterHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  RawCalorimeterHitObj* m_obj;
};

} // namespace edm4hep


#endif
