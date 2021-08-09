// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCParticleObj.h"
#include "edm4hep/MCParticle.h"
namespace edm4hep {

MCParticleObj::MCParticleObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_parents(new std::vector<::edm4hep::ConstMCParticle>()),
  m_daughters(new std::vector<::edm4hep::ConstMCParticle>())
{  }

MCParticleObj::MCParticleObj(const podio::ObjectID id_, MCParticleData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

MCParticleObj::MCParticleObj(const MCParticleObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_parents(new std::vector<::edm4hep::ConstMCParticle>(*(other.m_parents))),
  m_daughters(new std::vector<::edm4hep::ConstMCParticle>(*(other.m_daughters)))
{
}

MCParticleObj::~MCParticleObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_parents;
    delete m_daughters;
  }

}
} // namespace edm4hep

