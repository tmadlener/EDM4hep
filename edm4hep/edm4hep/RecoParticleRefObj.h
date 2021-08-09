// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecoParticleRefOBJ_H
#define EDM4HEP_RecoParticleRefOBJ_H

// data model specific includes
#include "edm4hep/RecoParticleRefData.h"

#include "podio/ObjBase.h"

// forward declarations
namespace edm4hep {
class ConstReconstructedParticle;
}


namespace edm4hep {

class RecoParticleRef;
class ConstRecoParticleRef;

class RecoParticleRefObj : public podio::ObjBase {
public:
  /// constructor
  RecoParticleRefObj();
  /// copy constructor (does a deep-copy of relation containers)
  RecoParticleRefObj(const RecoParticleRefObj&);
  /// constructor from ObjectID and RecoParticleRefData
  /// does not initialize the internal relation containers
  RecoParticleRefObj(const podio::ObjectID id, RecoParticleRefData data);
  /// No assignment operator
  RecoParticleRefObj& operator=(const RecoParticleRefObj&) = delete;
  virtual ~RecoParticleRefObj();

public:
  RecoParticleRefData data;
  ::edm4hep::ConstReconstructedParticle* m_particle{nullptr};
};

} // namespace edm4hep


#endif
