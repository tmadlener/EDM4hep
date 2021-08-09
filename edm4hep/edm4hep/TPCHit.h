// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TPCHit_H
#define EDM4HEP_TPCHit_H

#include "edm4hep/TPCHitConst.h"
#include "edm4hep/TPCHitObj.h"

#include <vector>
#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class TPCHit
 *  Time Projection Chamber Hit
 *  @author: F.Gaede, DESY
 */
class TPCHit {

  friend class TPCHitCollection;
  friend class TPCHitCollectionIterator;
  friend class ConstTPCHit;

public:

  /// default constructor
  TPCHit();
  TPCHit(unsigned long long cellID, int quality, float time, float charge);

  /// constructor from existing TPCHitObj
  TPCHit(TPCHitObj* obj);

  /// copy constructor
  TPCHit(const TPCHit& other);

  /// copy-assignment operator
  TPCHit& operator=(const TPCHit& other);

  /// support cloning (deep-copy)
  TPCHit clone() const;

  /// destructor
  ~TPCHit();

  /// conversion to const object
  operator ConstTPCHit() const;

public:

  /// Access the detector specific cell id.
  const unsigned long long& getCellID() const;

  /// Access the quality flag for the hit.
  const int& getQuality() const;

  /// Access the time of the hit.
  const float& getTime() const;

  /// Access the integrated charge of the hit.
  const float& getCharge() const;



  /// Set the detector specific cell id.
  void setCellID(unsigned long long value);

  /// Set the quality flag for the hit.
  void setQuality(int value);

  /// Set the time of the hit.
  void setTime(float value);

  /// Set the integrated charge of the hit.
  void setCharge(float value);



  void addToRawDataWords(int);
  unsigned int rawDataWords_size() const;
  int getRawDataWords(unsigned int) const;
  std::vector<int>::const_iterator rawDataWords_begin() const;
  std::vector<int>::const_iterator rawDataWords_end() const;
  podio::RelationRange<int> getRawDataWords() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TPCHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const TPCHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstTPCHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const TPCHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  TPCHitObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstTPCHit& value);

} // namespace edm4hep


#endif
