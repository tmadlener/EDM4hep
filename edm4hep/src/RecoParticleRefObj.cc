// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RecoParticleRefObj.h"
#include "edm4hep/ReconstructedParticleConst.h"
namespace edm4hep {

RecoParticleRefObj::RecoParticleRefObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_particle(nullptr)
{  }

RecoParticleRefObj::RecoParticleRefObj(const podio::ObjectID id_, RecoParticleRefData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

RecoParticleRefObj::RecoParticleRefObj(const RecoParticleRefObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_particle(nullptr)
{
  if (other.m_particle) {
    m_particle = new ::edm4hep::ConstReconstructedParticle(*(other.m_particle));
  }
}

RecoParticleRefObj::~RecoParticleRefObj() {

  if (m_particle) delete m_particle;
}
} // namespace edm4hep

