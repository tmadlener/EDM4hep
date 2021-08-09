// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/VertexObj.h"
#include "edm4hep/ReconstructedParticleConst.h"
namespace edm4hep {

VertexObj::VertexObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_associatedParticle(nullptr),
  m_parameters(new std::vector<float>())
{  }

VertexObj::VertexObj(const podio::ObjectID id_, VertexData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

VertexObj::VertexObj(const VertexObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_associatedParticle(nullptr),
  m_parameters(new std::vector<float>(*(other.m_parameters)))
{
  if (other.m_associatedParticle) {
    m_associatedParticle = new ::edm4hep::ConstReconstructedParticle(*(other.m_associatedParticle));
  }
}

VertexObj::~VertexObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_parameters;
  }

  if (m_associatedParticle) delete m_associatedParticle;
}
} // namespace edm4hep

