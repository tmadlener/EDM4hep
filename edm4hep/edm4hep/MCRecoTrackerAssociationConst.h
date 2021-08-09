// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstMCRecoTrackerAssociation_H
#define EDM4HEP_ConstMCRecoTrackerAssociation_H

#include "edm4hep/MCRecoTrackerAssociationObj.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class TrackerHit;
class ConstTrackerHit;
class SimTrackerHit;
class ConstSimTrackerHit;
}


namespace edm4hep {


/** @class ConstMCRecoTrackerAssociation
 *  Association between a TrackerHit and the corresponding simulated TrackerHit
 *  @author: C. Bernet, B. Hegner
 */
class ConstMCRecoTrackerAssociation {

  friend class MCRecoTrackerAssociation;
  friend class MCRecoTrackerAssociationCollection;
  friend class MCRecoTrackerAssociationConstCollectionIterator;

public:
  /// default constructor
  ConstMCRecoTrackerAssociation();
  ConstMCRecoTrackerAssociation(float weight);

  /// constructor from existing MCRecoTrackerAssociationObj
  ConstMCRecoTrackerAssociation(MCRecoTrackerAssociationObj* obj);

  /// copy constructor
  ConstMCRecoTrackerAssociation(const ConstMCRecoTrackerAssociation& other);

  /// copy-assignment operator
  ConstMCRecoTrackerAssociation& operator=(const ConstMCRecoTrackerAssociation& other);

  /// support cloning (deep-copy)
  ConstMCRecoTrackerAssociation clone() const;

  /// destructor
  ~ConstMCRecoTrackerAssociation();


public:

  /// Access the weight of this association
  const float& getWeight() const;


  /// Access the reference to the reconstructed hit
  const ::edm4hep::ConstTrackerHit getRec() const;
  /// Access the reference to the simulated hit
  const ::edm4hep::ConstSimTrackerHit getSim() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoTrackerAssociationObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstMCRecoTrackerAssociation& other) const { return m_obj == other.m_obj; }
  bool operator==(const MCRecoTrackerAssociation& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstMCRecoTrackerAssociation& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  MCRecoTrackerAssociationObj* m_obj;
};

} // namespace edm4hep


#endif
