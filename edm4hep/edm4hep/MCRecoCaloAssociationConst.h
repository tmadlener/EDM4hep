// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstMCRecoCaloAssociation_H
#define EDM4HEP_ConstMCRecoCaloAssociation_H

#include "edm4hep/MCRecoCaloAssociationObj.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class CalorimeterHit;
class ConstCalorimeterHit;
class SimCalorimeterHit;
class ConstSimCalorimeterHit;
}


namespace edm4hep {


/** @class ConstMCRecoCaloAssociation
 *  Association between a CaloHit and the corresponding simulated CaloHit
 *  @author: C. Bernet, B. Hegner
 */
class ConstMCRecoCaloAssociation {

  friend class MCRecoCaloAssociation;
  friend class MCRecoCaloAssociationCollection;
  friend class MCRecoCaloAssociationConstCollectionIterator;

public:
  /// default constructor
  ConstMCRecoCaloAssociation();
  ConstMCRecoCaloAssociation(float weight);

  /// constructor from existing MCRecoCaloAssociationObj
  ConstMCRecoCaloAssociation(MCRecoCaloAssociationObj* obj);

  /// copy constructor
  ConstMCRecoCaloAssociation(const ConstMCRecoCaloAssociation& other);

  /// copy-assignment operator
  ConstMCRecoCaloAssociation& operator=(const ConstMCRecoCaloAssociation& other);

  /// support cloning (deep-copy)
  ConstMCRecoCaloAssociation clone() const;

  /// destructor
  ~ConstMCRecoCaloAssociation();


public:

  /// Access the weight of this association
  const float& getWeight() const;


  /// Access the reference to the reconstructed hit
  const ::edm4hep::ConstCalorimeterHit getRec() const;
  /// Access the reference to the simulated hit
  const ::edm4hep::ConstSimCalorimeterHit getSim() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoCaloAssociationObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstMCRecoCaloAssociation& other) const { return m_obj == other.m_obj; }
  bool operator==(const MCRecoCaloAssociation& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstMCRecoCaloAssociation& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  MCRecoCaloAssociationObj* m_obj;
};

} // namespace edm4hep


#endif
