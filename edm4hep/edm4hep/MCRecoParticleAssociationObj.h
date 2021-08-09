// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoParticleAssociationOBJ_H
#define EDM4HEP_MCRecoParticleAssociationOBJ_H

// data model specific includes
#include "edm4hep/MCRecoParticleAssociationData.h"

#include "podio/ObjBase.h"

// forward declarations
namespace edm4hep {
class ConstReconstructedParticle;
class ConstMCParticle;
}


namespace edm4hep {

class MCRecoParticleAssociation;
class ConstMCRecoParticleAssociation;

class MCRecoParticleAssociationObj : public podio::ObjBase {
public:
  /// constructor
  MCRecoParticleAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCRecoParticleAssociationObj(const MCRecoParticleAssociationObj&);
  /// constructor from ObjectID and MCRecoParticleAssociationData
  /// does not initialize the internal relation containers
  MCRecoParticleAssociationObj(const podio::ObjectID id, MCRecoParticleAssociationData data);
  /// No assignment operator
  MCRecoParticleAssociationObj& operator=(const MCRecoParticleAssociationObj&) = delete;
  virtual ~MCRecoParticleAssociationObj();

public:
  MCRecoParticleAssociationData data;
  ::edm4hep::ConstReconstructedParticle* m_rec{nullptr};
  ::edm4hep::ConstMCParticle* m_sim{nullptr};
};

} // namespace edm4hep


#endif
