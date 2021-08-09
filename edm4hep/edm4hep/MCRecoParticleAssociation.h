// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoParticleAssociation_H
#define EDM4HEP_MCRecoParticleAssociation_H

#include "edm4hep/MCRecoParticleAssociationConst.h"
#include "edm4hep/MCRecoParticleAssociationObj.h"

#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class ConstReconstructedParticle;
class MCParticle;
class ConstMCParticle;
}


namespace edm4hep {


/** @class MCRecoParticleAssociation
 *  Used to keep track of the correspondence between MC and reconstructed particles
 *  @author: C. Bernet, B. Hegner
 */
class MCRecoParticleAssociation {

  friend class MCRecoParticleAssociationCollection;
  friend class MCRecoParticleAssociationCollectionIterator;
  friend class ConstMCRecoParticleAssociation;

public:

  /// default constructor
  MCRecoParticleAssociation();
  MCRecoParticleAssociation(float weight);

  /// constructor from existing MCRecoParticleAssociationObj
  MCRecoParticleAssociation(MCRecoParticleAssociationObj* obj);

  /// copy constructor
  MCRecoParticleAssociation(const MCRecoParticleAssociation& other);

  /// copy-assignment operator
  MCRecoParticleAssociation& operator=(const MCRecoParticleAssociation& other);

  /// support cloning (deep-copy)
  MCRecoParticleAssociation clone() const;

  /// destructor
  ~MCRecoParticleAssociation();

  /// conversion to const object
  operator ConstMCRecoParticleAssociation() const;

public:

  /// Access the weight of this association
  const float& getWeight() const;


  /// Access the reference to the reconstructed particle
  const ::edm4hep::ConstReconstructedParticle getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const ::edm4hep::ConstMCParticle getSim() const;

  /// Set the weight of this association
  void setWeight(float value);


  /// Set the reference to the reconstructed particle
  void setRec(::edm4hep::ConstReconstructedParticle value);
  /// Set the reference to the Monte-Carlo particle
  void setSim(::edm4hep::ConstMCParticle value);




  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoParticleAssociationObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const MCRecoParticleAssociation& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstMCRecoParticleAssociation& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const MCRecoParticleAssociation& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  MCRecoParticleAssociationObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstMCRecoParticleAssociation& value);

} // namespace edm4hep


#endif
