// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoCaloAssociation_H
#define EDM4HEP_MCRecoCaloAssociation_H

#include "edm4hep/MCRecoCaloAssociationConst.h"
#include "edm4hep/MCRecoCaloAssociationObj.h"

#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class CalorimeterHit;
class ConstCalorimeterHit;
class SimCalorimeterHit;
class ConstSimCalorimeterHit;
}


namespace edm4hep {


/** @class MCRecoCaloAssociation
 *  Association between a CaloHit and the corresponding simulated CaloHit
 *  @author: C. Bernet, B. Hegner
 */
class MCRecoCaloAssociation {

  friend class MCRecoCaloAssociationCollection;
  friend class MCRecoCaloAssociationCollectionIterator;
  friend class ConstMCRecoCaloAssociation;

public:

  /// default constructor
  MCRecoCaloAssociation();
  MCRecoCaloAssociation(float weight);

  /// constructor from existing MCRecoCaloAssociationObj
  MCRecoCaloAssociation(MCRecoCaloAssociationObj* obj);

  /// copy constructor
  MCRecoCaloAssociation(const MCRecoCaloAssociation& other);

  /// copy-assignment operator
  MCRecoCaloAssociation& operator=(const MCRecoCaloAssociation& other);

  /// support cloning (deep-copy)
  MCRecoCaloAssociation clone() const;

  /// destructor
  ~MCRecoCaloAssociation();

  /// conversion to const object
  operator ConstMCRecoCaloAssociation() const;

public:

  /// Access the weight of this association
  const float& getWeight() const;


  /// Access the reference to the reconstructed hit
  const ::edm4hep::ConstCalorimeterHit getRec() const;
  /// Access the reference to the simulated hit
  const ::edm4hep::ConstSimCalorimeterHit getSim() const;

  /// Set the weight of this association
  void setWeight(float value);


  /// Set the reference to the reconstructed hit
  void setRec(::edm4hep::ConstCalorimeterHit value);
  /// Set the reference to the simulated hit
  void setSim(::edm4hep::ConstSimCalorimeterHit value);




  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoCaloAssociationObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const MCRecoCaloAssociation& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstMCRecoCaloAssociation& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoCaloAssociation& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  MCRecoCaloAssociationObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstMCRecoCaloAssociation& value);

} // namespace edm4hep


#endif
