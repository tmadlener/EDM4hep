// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ParticleIDObj.h"
namespace edm4hep {

ParticleIDObj::ParticleIDObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_parameters(new std::vector<float>())
{  }

ParticleIDObj::ParticleIDObj(const podio::ObjectID id_, ParticleIDData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

ParticleIDObj::ParticleIDObj(const ParticleIDObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_parameters(new std::vector<float>(*(other.m_parameters)))
{
}

ParticleIDObj::~ParticleIDObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_parameters;
  }

}
} // namespace edm4hep

