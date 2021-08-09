// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/SimTrackerHitObj.h"
#include "edm4hep/MCParticleConst.h"
namespace edm4hep {

SimTrackerHitObj::SimTrackerHitObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_MCParticle(nullptr)
{  }

SimTrackerHitObj::SimTrackerHitObj(const podio::ObjectID id_, SimTrackerHitData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

SimTrackerHitObj::SimTrackerHitObj(const SimTrackerHitObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_MCParticle(nullptr)
{
  if (other.m_MCParticle) {
    m_MCParticle = new ::edm4hep::ConstMCParticle(*(other.m_MCParticle));
  }
}

SimTrackerHitObj::~SimTrackerHitObj() {

  if (m_MCParticle) delete m_MCParticle;
}
} // namespace edm4hep

