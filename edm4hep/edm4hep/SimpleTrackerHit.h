// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimpleTrackerHit_H
#define EDM4HEP_SimpleTrackerHit_H

#include "edm4hep/SimpleTrackerHitConst.h"
#include "edm4hep/SimpleTrackerHitObj.h"

#include "edm4hep/Vector3d.h"
#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class SimpleTrackerHit
 *  Simple tracker hit for TrackerHitWrapper tests
 *  @author: T.Madlener, DESY
 */
class SimpleTrackerHit {

  friend class SimpleTrackerHitCollection;
  friend class SimpleTrackerHitCollectionIterator;
  friend class ConstSimpleTrackerHit;
  friend class TrackerHitWrapper;
  friend class ConstTrackerHitWrapper;

public:

  /// default constructor
  SimpleTrackerHit();
  SimpleTrackerHit(edm4hep::Vector3d position);

  /// constructor from existing SimpleTrackerHitObj
  SimpleTrackerHit(SimpleTrackerHitObj* obj);

  /// copy constructor
  SimpleTrackerHit(const SimpleTrackerHit& other);

  /// copy-assignment operator
  SimpleTrackerHit& operator=(const SimpleTrackerHit& other);

  /// support cloning (deep-copy)
  SimpleTrackerHit clone() const;

  /// destructor
  ~SimpleTrackerHit();

  /// conversion to const object
  operator ConstSimpleTrackerHit() const;

public:

  /// Access the hit position in [mm]
  const edm4hep::Vector3d& getPosition() const;



  /// Set the hit position in [mm]
  void setPosition(edm4hep::Vector3d value);
  /// Get reference to hit position in [mm]
  edm4hep::Vector3d& position();






  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimpleTrackerHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const SimpleTrackerHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstSimpleTrackerHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const SimpleTrackerHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimpleTrackerHitObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstSimpleTrackerHit& value);

} // namespace edm4hep


#endif
