// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstTPCHit_H
#define EDM4HEP_ConstTPCHit_H

#include "edm4hep/TPCHitObj.h"

#include <vector>
#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstTPCHit
 *  Time Projection Chamber Hit
 *  @author: F.Gaede, DESY
 */
class ConstTPCHit {

  friend class TPCHit;
  friend class TPCHitCollection;
  friend class TPCHitConstCollectionIterator;

public:
  /// default constructor
  ConstTPCHit();
  ConstTPCHit(unsigned long long cellID, int quality, float time, float charge);

  /// constructor from existing TPCHitObj
  ConstTPCHit(TPCHitObj* obj);

  /// copy constructor
  ConstTPCHit(const ConstTPCHit& other);

  /// copy-assignment operator
  ConstTPCHit& operator=(const ConstTPCHit& other);

  /// support cloning (deep-copy)
  ConstTPCHit clone() const;

  /// destructor
  ~ConstTPCHit();


public:

  /// Access the detector specific cell id.
  const unsigned long long& getCellID() const;

  /// Access the quality flag for the hit.
  const int& getQuality() const;

  /// Access the time of the hit.
  const float& getTime() const;

  /// Access the integrated charge of the hit.
  const float& getCharge() const;



  unsigned int rawDataWords_size() const;
  int getRawDataWords(unsigned int) const;
  std::vector<int>::const_iterator rawDataWords_begin() const;
  std::vector<int>::const_iterator rawDataWords_end() const;
  podio::RelationRange<int> getRawDataWords() const;


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TPCHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstTPCHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const TPCHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstTPCHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  TPCHitObj* m_obj;
};

} // namespace edm4hep


#endif
