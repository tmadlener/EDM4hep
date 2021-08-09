// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/CaloHitContributionObj.h"
#include "edm4hep/MCParticleConst.h"
namespace edm4hep {

CaloHitContributionObj::CaloHitContributionObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_particle(nullptr)
{  }

CaloHitContributionObj::CaloHitContributionObj(const podio::ObjectID id_, CaloHitContributionData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

CaloHitContributionObj::CaloHitContributionObj(const CaloHitContributionObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_particle(nullptr)
{
  if (other.m_particle) {
    m_particle = new ::edm4hep::ConstMCParticle(*(other.m_particle));
  }
}

CaloHitContributionObj::~CaloHitContributionObj() {

  if (m_particle) delete m_particle;
}
} // namespace edm4hep

