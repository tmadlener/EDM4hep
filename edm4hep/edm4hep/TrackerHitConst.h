// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstTrackerHit_H
#define EDM4HEP_ConstTrackerHit_H

#include "edm4hep/TrackerHitObj.h"

#include "edm4hep/ObjectID.h"
#include "edm4hep/Vector3d.h"
#include <array>
#include <vector>
#include "podio/ObjectID.h"
#include "podio/GenericWrapper.h"



namespace edm4hep {


/** @class ConstTrackerHit
 *  Tracker hit
 *  @author: F.Gaede, DESY
 */
class ConstTrackerHit {

  friend class TrackerHit;
  friend class TrackerHitCollection;
  friend class TrackerHitConstCollectionIterator;
  friend class ConstTrackerHitWrapper;
  template<typename...>
  friend class podio::GenericWrapper;

public:
  using ObjPtrT = TrackerHitObj*;
  /// default constructor
  ConstTrackerHit();
  ConstTrackerHit(unsigned long long cellID, int type, int quality, float time, float eDep, float eDepError, float edx, edm4hep::Vector3d position, std::array<float, 6> covMatrix);

  /// constructor from existing TrackerHitObj
  ConstTrackerHit(TrackerHitObj* obj);

  /// copy constructor
  ConstTrackerHit(const ConstTrackerHit& other);

  /// copy-assignment operator
  ConstTrackerHit& operator=(const ConstTrackerHit& other);

  /// support cloning (deep-copy)
  ConstTrackerHit clone() const;

  /// destructor
  ~ConstTrackerHit();


public:

  /// Access the ID of the sensor that created this hit
  const unsigned long long& getCellID() const;

  /// Access the type of raw data hit, either one of edm4hep::TPCHIT, edm4hep::SIMTRACKERHIT - see collection parameters "TrackerHitTypeNames" and "TrackerHitTypeValues".
  const int& getType() const;

  /// Access the quality bit flag of the hit.
  const int& getQuality() const;

  /// Access the time of the hit.
  const float& getTime() const;

  /// Access the energy deposited on the hit [GeV].
  const float& getEDep() const;

  /// Access the error measured on EDep [GeV].
  const float& getEDepError() const;

  /// Access the dE/dx of the hit in [GeV/mm].
  const float& getEdx() const;

  /// Access the hit position in [mm].
  const edm4hep::Vector3d& getPosition() const;

  /// Access the covariance of the position (x,y,z), stored as lower triangle matrix. i.e. cov(x,x) , cov(y,x) , cov(y,y) , cov(z,x) , cov(z,y) , cov(z,z)
  const std::array<float, 6>& getCovMatrix() const;
  /// Access item i of the covariance of the position (x,y,z), stored as lower triangle matrix. i.e. cov(x,x) , cov(y,x) , cov(y,y) , cov(z,x) , cov(z,y) , cov(z,z)
  const float& getCovMatrix(size_t i) const;


  unsigned int rawHits_size() const;
  edm4hep::ObjectID getRawHits(unsigned int) const;
  std::vector<edm4hep::ObjectID>::const_iterator rawHits_begin() const;
  std::vector<edm4hep::ObjectID>::const_iterator rawHits_end() const;
  podio::RelationRange<edm4hep::ObjectID> getRawHits() const;


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackerHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstTrackerHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const TrackerHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstTrackerHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  TrackerHitObj* m_obj;
};

} // namespace edm4hep


#endif
