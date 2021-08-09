// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCRecoParticleAssociationObj.h"
#include "edm4hep/MCParticleConst.h"
#include "edm4hep/ReconstructedParticleConst.h"
namespace edm4hep {

MCRecoParticleAssociationObj::MCRecoParticleAssociationObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_rec(nullptr),
  m_sim(nullptr)
{  }

MCRecoParticleAssociationObj::MCRecoParticleAssociationObj(const podio::ObjectID id_, MCRecoParticleAssociationData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

MCRecoParticleAssociationObj::MCRecoParticleAssociationObj(const MCRecoParticleAssociationObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_rec(nullptr),
  m_sim(nullptr)
{
  if (other.m_rec) {
    m_rec = new ::edm4hep::ConstReconstructedParticle(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new ::edm4hep::ConstMCParticle(*(other.m_sim));
  }
}

MCRecoParticleAssociationObj::~MCRecoParticleAssociationObj() {

  if (m_rec) delete m_rec;
  if (m_sim) delete m_sim;
}
} // namespace edm4hep

