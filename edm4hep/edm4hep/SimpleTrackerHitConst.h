// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstSimpleTrackerHit_H
#define EDM4HEP_ConstSimpleTrackerHit_H

#include "edm4hep/SimpleTrackerHitObj.h"

#include "edm4hep/Vector3d.h"
#include "podio/ObjectID.h"
#include "podio/GenericWrapper.h"



namespace edm4hep {


/** @class ConstSimpleTrackerHit
 *  Simple tracker hit for TrackerHitWrapper tests
 *  @author: T.Madlener, DESY
 */
class ConstSimpleTrackerHit {

  friend class SimpleTrackerHit;
  friend class SimpleTrackerHitCollection;
  friend class SimpleTrackerHitConstCollectionIterator;
  friend class ConstTrackerHitWrapper;
  template<typename...>
  friend class podio::GenericWrapper;

public:
  using ObjPtrT = SimpleTrackerHitObj*;
  /// default constructor
  ConstSimpleTrackerHit();
  ConstSimpleTrackerHit(edm4hep::Vector3d position);

  /// constructor from existing SimpleTrackerHitObj
  ConstSimpleTrackerHit(SimpleTrackerHitObj* obj);

  /// copy constructor
  ConstSimpleTrackerHit(const ConstSimpleTrackerHit& other);

  /// copy-assignment operator
  ConstSimpleTrackerHit& operator=(const ConstSimpleTrackerHit& other);

  /// support cloning (deep-copy)
  ConstSimpleTrackerHit clone() const;

  /// destructor
  ~ConstSimpleTrackerHit();


public:

  /// Access the hit position in [mm]
  const edm4hep::Vector3d& getPosition() const;





  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimpleTrackerHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstSimpleTrackerHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const SimpleTrackerHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstSimpleTrackerHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimpleTrackerHitObj* m_obj;
};

} // namespace edm4hep


#endif
