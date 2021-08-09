// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawCalorimeterHit_H
#define EDM4HEP_RawCalorimeterHit_H

#include "edm4hep/RawCalorimeterHitConst.h"
#include "edm4hep/RawCalorimeterHitObj.h"

#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class RawCalorimeterHit
 *  Raw calorimeter hit
 *  @author: F.Gaede, DESY
 */
class RawCalorimeterHit {

  friend class RawCalorimeterHitCollection;
  friend class RawCalorimeterHitCollectionIterator;
  friend class ConstRawCalorimeterHit;

public:

  /// default constructor
  RawCalorimeterHit();
  RawCalorimeterHit(unsigned long long cellID, int amplitude, int timeStamp);

  /// constructor from existing RawCalorimeterHitObj
  RawCalorimeterHit(RawCalorimeterHitObj* obj);

  /// copy constructor
  RawCalorimeterHit(const RawCalorimeterHit& other);

  /// copy-assignment operator
  RawCalorimeterHit& operator=(const RawCalorimeterHit& other);

  /// support cloning (deep-copy)
  RawCalorimeterHit clone() const;

  /// destructor
  ~RawCalorimeterHit();

  /// conversion to const object
  operator ConstRawCalorimeterHit() const;

public:

  /// Access the detector specific (geometrical) cell id.
  const unsigned long long& getCellID() const;

  /// Access the amplitude of the hit in ADC counts.
  const int& getAmplitude() const;

  /// Access the time stamp for the hit.
  const int& getTimeStamp() const;



  /// Set the detector specific (geometrical) cell id.
  void setCellID(unsigned long long value);

  /// Set the amplitude of the hit in ADC counts.
  void setAmplitude(int value);

  /// Set the time stamp for the hit.
  void setTimeStamp(int value);






  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RawCalorimeterHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const RawCalorimeterHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstRawCalorimeterHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const RawCalorimeterHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  RawCalorimeterHitObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstRawCalorimeterHit& value);

} // namespace edm4hep


#endif
