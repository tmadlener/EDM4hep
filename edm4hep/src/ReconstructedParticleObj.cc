// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ReconstructedParticleObj.h"
#include "edm4hep/ParticleIDConst.h"
#include "edm4hep/ReconstructedParticle.h"
#include "edm4hep/VertexConst.h"
namespace edm4hep {

ReconstructedParticleObj::ReconstructedParticleObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_startVertex(nullptr),
  m_particleIDUsed(nullptr),
  m_clusters(new std::vector<::edm4hep::ConstCluster>()),
  m_tracks(new std::vector<::edm4hep::ConstTrack>()),
  m_particles(new std::vector<::edm4hep::ConstReconstructedParticle>()),
  m_particleIDs(new std::vector<::edm4hep::ConstParticleID>())
{  }

ReconstructedParticleObj::ReconstructedParticleObj(const podio::ObjectID id_, ReconstructedParticleData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

ReconstructedParticleObj::ReconstructedParticleObj(const ReconstructedParticleObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_startVertex(nullptr),
  m_particleIDUsed(nullptr),
  m_clusters(new std::vector<::edm4hep::ConstCluster>(*(other.m_clusters))),
  m_tracks(new std::vector<::edm4hep::ConstTrack>(*(other.m_tracks))),
  m_particles(new std::vector<::edm4hep::ConstReconstructedParticle>(*(other.m_particles))),
  m_particleIDs(new std::vector<::edm4hep::ConstParticleID>(*(other.m_particleIDs)))
{
  if (other.m_startVertex) {
    m_startVertex = new ::edm4hep::ConstVertex(*(other.m_startVertex));
  }
  if (other.m_particleIDUsed) {
    m_particleIDUsed = new ::edm4hep::ConstParticleID(*(other.m_particleIDUsed));
  }
}

ReconstructedParticleObj::~ReconstructedParticleObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_clusters;
    delete m_tracks;
    delete m_particles;
    delete m_particleIDs;
  }

  if (m_startVertex) delete m_startVertex;
  if (m_particleIDUsed) delete m_particleIDUsed;
}
} // namespace edm4hep

