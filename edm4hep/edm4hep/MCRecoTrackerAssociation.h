// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackerAssociation_H
#define EDM4HEP_MCRecoTrackerAssociation_H

#include "edm4hep/MCRecoTrackerAssociationConst.h"
#include "edm4hep/MCRecoTrackerAssociationObj.h"

#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class TrackerHit;
class ConstTrackerHit;
class SimTrackerHit;
class ConstSimTrackerHit;
}


namespace edm4hep {


/** @class MCRecoTrackerAssociation
 *  Association between a TrackerHit and the corresponding simulated TrackerHit
 *  @author: C. Bernet, B. Hegner
 */
class MCRecoTrackerAssociation {

  friend class MCRecoTrackerAssociationCollection;
  friend class MCRecoTrackerAssociationCollectionIterator;
  friend class ConstMCRecoTrackerAssociation;

public:

  /// default constructor
  MCRecoTrackerAssociation();
  MCRecoTrackerAssociation(float weight);

  /// constructor from existing MCRecoTrackerAssociationObj
  MCRecoTrackerAssociation(MCRecoTrackerAssociationObj* obj);

  /// copy constructor
  MCRecoTrackerAssociation(const MCRecoTrackerAssociation& other);

  /// copy-assignment operator
  MCRecoTrackerAssociation& operator=(const MCRecoTrackerAssociation& other);

  /// support cloning (deep-copy)
  MCRecoTrackerAssociation clone() const;

  /// destructor
  ~MCRecoTrackerAssociation();

  /// conversion to const object
  operator ConstMCRecoTrackerAssociation() const;

public:

  /// Access the weight of this association
  const float& getWeight() const;


  /// Access the reference to the reconstructed hit
  const ::edm4hep::ConstTrackerHit getRec() const;
  /// Access the reference to the simulated hit
  const ::edm4hep::ConstSimTrackerHit getSim() const;

  /// Set the weight of this association
  void setWeight(float value);


  /// Set the reference to the reconstructed hit
  void setRec(::edm4hep::ConstTrackerHit value);
  /// Set the reference to the simulated hit
  void setSim(::edm4hep::ConstSimTrackerHit value);




  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoTrackerAssociationObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const MCRecoTrackerAssociation& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstMCRecoTrackerAssociation& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoTrackerAssociation& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  MCRecoTrackerAssociationObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstMCRecoTrackerAssociation& value);

} // namespace edm4hep


#endif
