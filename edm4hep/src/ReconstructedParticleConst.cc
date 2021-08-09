// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/ReconstructedParticle.h"
#include "edm4hep/ReconstructedParticleConst.h"
#include "edm4hep/ReconstructedParticleObj.h"
#include "edm4hep/ReconstructedParticleData.h"
#include "edm4hep/ReconstructedParticleCollection.h"

#include "edm4hep/ParticleID.h"
#include "edm4hep/Vertex.h"

#include <ostream>

namespace edm4hep {


ConstReconstructedParticle::ConstReconstructedParticle() : m_obj(new ReconstructedParticleObj()) {
  m_obj->acquire();
}

ConstReconstructedParticle::ConstReconstructedParticle(int type, float energy, edm4hep::Vector3f momentum, edm4hep::Vector3f referencePoint, float charge, float mass, float goodnessOfPID, std::array<float, 10> covMatrix) : m_obj(new ReconstructedParticleObj()) {
  m_obj->acquire();
  m_obj->data.type = type;
  m_obj->data.energy = energy;
  m_obj->data.momentum = momentum;
  m_obj->data.referencePoint = referencePoint;
  m_obj->data.charge = charge;
  m_obj->data.mass = mass;
  m_obj->data.goodnessOfPID = goodnessOfPID;
  m_obj->data.covMatrix = covMatrix;
}

ConstReconstructedParticle::ConstReconstructedParticle(const ConstReconstructedParticle& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstReconstructedParticle& ConstReconstructedParticle::operator=(const ConstReconstructedParticle& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstReconstructedParticle::ConstReconstructedParticle( ReconstructedParticleObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstReconstructedParticle ConstReconstructedParticle::clone() const {
  return {new ReconstructedParticleObj(*m_obj)};
}

ConstReconstructedParticle::~ConstReconstructedParticle() {
  if (m_obj) m_obj->release();
}
const int& ConstReconstructedParticle::getType() const { return m_obj->data.type; }
const float& ConstReconstructedParticle::getEnergy() const { return m_obj->data.energy; }
const edm4hep::Vector3f& ConstReconstructedParticle::getMomentum() const { return m_obj->data.momentum; }
const edm4hep::Vector3f& ConstReconstructedParticle::getReferencePoint() const { return m_obj->data.referencePoint; }
const float& ConstReconstructedParticle::getCharge() const { return m_obj->data.charge; }
const float& ConstReconstructedParticle::getMass() const { return m_obj->data.mass; }
const float& ConstReconstructedParticle::getGoodnessOfPID() const { return m_obj->data.goodnessOfPID; }
const std::array<float, 10>& ConstReconstructedParticle::getCovMatrix() const { return m_obj->data.covMatrix; }
const float& ConstReconstructedParticle::getCovMatrix(size_t i) const { return m_obj->data.covMatrix.at(i); }

const ::edm4hep::ConstVertex ConstReconstructedParticle::getStartVertex() const {
  if (!m_obj->m_startVertex) {
    return ::edm4hep::ConstVertex(nullptr);
  }
  return ::edm4hep::ConstVertex(*(m_obj->m_startVertex));
}

const ::edm4hep::ConstParticleID ConstReconstructedParticle::getParticleIDUsed() const {
  if (!m_obj->m_particleIDUsed) {
    return ::edm4hep::ConstParticleID(nullptr);
  }
  return ::edm4hep::ConstParticleID(*(m_obj->m_particleIDUsed));
}



std::vector<::edm4hep::ConstCluster>::const_iterator ConstReconstructedParticle::clusters_begin() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstCluster>::const_iterator ConstReconstructedParticle::clusters_end() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_end);
  return ret_value;
}

unsigned int ConstReconstructedParticle::clusters_size() const {
  return m_obj->data.clusters_end - m_obj->data.clusters_begin;
}

::edm4hep::ConstCluster ConstReconstructedParticle::getClusters(unsigned int index) const {
  if (clusters_size() > index) {
    return m_obj->m_clusters->at(m_obj->data.clusters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstCluster> ConstReconstructedParticle::getClusters() const {
  auto begin = m_obj->m_clusters->begin();
  std::advance(begin, m_obj->data.clusters_begin);
  auto end = m_obj->m_clusters->begin();
  std::advance(end, m_obj->data.clusters_end);
  return {begin, end};
}


std::vector<::edm4hep::ConstTrack>::const_iterator ConstReconstructedParticle::tracks_begin() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstTrack>::const_iterator ConstReconstructedParticle::tracks_end() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_end);
  return ret_value;
}

unsigned int ConstReconstructedParticle::tracks_size() const {
  return m_obj->data.tracks_end - m_obj->data.tracks_begin;
}

::edm4hep::ConstTrack ConstReconstructedParticle::getTracks(unsigned int index) const {
  if (tracks_size() > index) {
    return m_obj->m_tracks->at(m_obj->data.tracks_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstTrack> ConstReconstructedParticle::getTracks() const {
  auto begin = m_obj->m_tracks->begin();
  std::advance(begin, m_obj->data.tracks_begin);
  auto end = m_obj->m_tracks->begin();
  std::advance(end, m_obj->data.tracks_end);
  return {begin, end};
}


std::vector<::edm4hep::ConstReconstructedParticle>::const_iterator ConstReconstructedParticle::particles_begin() const {
  auto ret_value = m_obj->m_particles->begin();
  std::advance(ret_value, m_obj->data.particles_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstReconstructedParticle>::const_iterator ConstReconstructedParticle::particles_end() const {
  auto ret_value = m_obj->m_particles->begin();
  std::advance(ret_value, m_obj->data.particles_end);
  return ret_value;
}

unsigned int ConstReconstructedParticle::particles_size() const {
  return m_obj->data.particles_end - m_obj->data.particles_begin;
}

::edm4hep::ConstReconstructedParticle ConstReconstructedParticle::getParticles(unsigned int index) const {
  if (particles_size() > index) {
    return m_obj->m_particles->at(m_obj->data.particles_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstReconstructedParticle> ConstReconstructedParticle::getParticles() const {
  auto begin = m_obj->m_particles->begin();
  std::advance(begin, m_obj->data.particles_begin);
  auto end = m_obj->m_particles->begin();
  std::advance(end, m_obj->data.particles_end);
  return {begin, end};
}


std::vector<::edm4hep::ConstParticleID>::const_iterator ConstReconstructedParticle::particleIDs_begin() const {
  auto ret_value = m_obj->m_particleIDs->begin();
  std::advance(ret_value, m_obj->data.particleIDs_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstParticleID>::const_iterator ConstReconstructedParticle::particleIDs_end() const {
  auto ret_value = m_obj->m_particleIDs->begin();
  std::advance(ret_value, m_obj->data.particleIDs_end);
  return ret_value;
}

unsigned int ConstReconstructedParticle::particleIDs_size() const {
  return m_obj->data.particleIDs_end - m_obj->data.particleIDs_begin;
}

::edm4hep::ConstParticleID ConstReconstructedParticle::getParticleIDs(unsigned int index) const {
  if (particleIDs_size() > index) {
    return m_obj->m_particleIDs->at(m_obj->data.particleIDs_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstParticleID> ConstReconstructedParticle::getParticleIDs() const {
  auto begin = m_obj->m_particleIDs->begin();
  std::advance(begin, m_obj->data.particleIDs_begin);
  auto end = m_obj->m_particleIDs->begin();
  std::advance(end, m_obj->data.particleIDs_end);
  return {begin, end};
}





bool ConstReconstructedParticle::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstReconstructedParticle::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstReconstructedParticle::operator==(const ReconstructedParticle& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

