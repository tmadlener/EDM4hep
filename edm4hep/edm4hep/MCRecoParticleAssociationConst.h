// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstMCRecoParticleAssociation_H
#define EDM4HEP_ConstMCRecoParticleAssociation_H

#include "edm4hep/MCRecoParticleAssociationObj.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class ConstReconstructedParticle;
class MCParticle;
class ConstMCParticle;
}


namespace edm4hep {


/** @class ConstMCRecoParticleAssociation
 *  Used to keep track of the correspondence between MC and reconstructed particles
 *  @author: C. Bernet, B. Hegner
 */
class ConstMCRecoParticleAssociation {

  friend class MCRecoParticleAssociation;
  friend class MCRecoParticleAssociationCollection;
  friend class MCRecoParticleAssociationConstCollectionIterator;

public:
  /// default constructor
  ConstMCRecoParticleAssociation();
  ConstMCRecoParticleAssociation(float weight);

  /// constructor from existing MCRecoParticleAssociationObj
  ConstMCRecoParticleAssociation(MCRecoParticleAssociationObj* obj);

  /// copy constructor
  ConstMCRecoParticleAssociation(const ConstMCRecoParticleAssociation& other);

  /// copy-assignment operator
  ConstMCRecoParticleAssociation& operator=(const ConstMCRecoParticleAssociation& other);

  /// support cloning (deep-copy)
  ConstMCRecoParticleAssociation clone() const;

  /// destructor
  ~ConstMCRecoParticleAssociation();


public:

  /// Access the weight of this association
  const float& getWeight() const;


  /// Access the reference to the reconstructed particle
  const ::edm4hep::ConstReconstructedParticle getRec() const;
  /// Access the reference to the Monte-Carlo particle
  const ::edm4hep::ConstMCParticle getSim() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCRecoParticleAssociationObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstMCRecoParticleAssociation& other) const { return m_obj == other.m_obj; }
  bool operator==(const MCRecoParticleAssociation& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstMCRecoParticleAssociation& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  MCRecoParticleAssociationObj* m_obj;
};

} // namespace edm4hep


#endif
