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


ReconstructedParticle::ReconstructedParticle() : m_obj(new ReconstructedParticleObj()) {
  m_obj->acquire();
}

ReconstructedParticle::ReconstructedParticle(int type, float energy, edm4hep::Vector3f momentum, edm4hep::Vector3f referencePoint, float charge, float mass, float goodnessOfPID, std::array<float, 10> covMatrix) : m_obj(new ReconstructedParticleObj()) {
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

ReconstructedParticle::ReconstructedParticle(const ReconstructedParticle& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ReconstructedParticle& ReconstructedParticle::operator=(const ReconstructedParticle& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ReconstructedParticle::ReconstructedParticle( ReconstructedParticleObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ReconstructedParticle ReconstructedParticle::clone() const {
  return {new ReconstructedParticleObj(*m_obj)};
}

ReconstructedParticle::~ReconstructedParticle() {
  if (m_obj) m_obj->release();
}
ReconstructedParticle::operator ConstReconstructedParticle() const { return ConstReconstructedParticle(m_obj); }

const int& ReconstructedParticle::getType() const { return m_obj->data.type; }
const float& ReconstructedParticle::getEnergy() const { return m_obj->data.energy; }
const edm4hep::Vector3f& ReconstructedParticle::getMomentum() const { return m_obj->data.momentum; }
const edm4hep::Vector3f& ReconstructedParticle::getReferencePoint() const { return m_obj->data.referencePoint; }
const float& ReconstructedParticle::getCharge() const { return m_obj->data.charge; }
const float& ReconstructedParticle::getMass() const { return m_obj->data.mass; }
const float& ReconstructedParticle::getGoodnessOfPID() const { return m_obj->data.goodnessOfPID; }
const std::array<float, 10>& ReconstructedParticle::getCovMatrix() const { return m_obj->data.covMatrix; }
const float& ReconstructedParticle::getCovMatrix(size_t i) const { return m_obj->data.covMatrix.at(i); }

const ::edm4hep::ConstVertex ReconstructedParticle::getStartVertex() const {
  if (!m_obj->m_startVertex) {
    return ::edm4hep::ConstVertex(nullptr);
  }
  return ::edm4hep::ConstVertex(*(m_obj->m_startVertex));
}

const ::edm4hep::ConstParticleID ReconstructedParticle::getParticleIDUsed() const {
  if (!m_obj->m_particleIDUsed) {
    return ::edm4hep::ConstParticleID(nullptr);
  }
  return ::edm4hep::ConstParticleID(*(m_obj->m_particleIDUsed));
}


void ReconstructedParticle::setType(int value) { m_obj->data.type = value; }
void ReconstructedParticle::setEnergy(float value) { m_obj->data.energy = value; }
void ReconstructedParticle::setMomentum(edm4hep::Vector3f value) { m_obj->data.momentum = value; }
edm4hep::Vector3f& ReconstructedParticle::momentum() { return m_obj->data.momentum; }
void ReconstructedParticle::setReferencePoint(edm4hep::Vector3f value) { m_obj->data.referencePoint = value; }
edm4hep::Vector3f& ReconstructedParticle::referencePoint() { return m_obj->data.referencePoint; }
void ReconstructedParticle::setCharge(float value) { m_obj->data.charge = value; }
void ReconstructedParticle::setMass(float value) { m_obj->data.mass = value; }
void ReconstructedParticle::setGoodnessOfPID(float value) { m_obj->data.goodnessOfPID = value; }
void ReconstructedParticle::setCovMatrix(std::array<float, 10> value) { m_obj->data.covMatrix = value; }
void ReconstructedParticle::setCovMatrix(size_t i, float value) { m_obj->data.covMatrix.at(i) = value; }
std::array<float, 10>& ReconstructedParticle::covMatrix() { return m_obj->data.covMatrix; }

void ReconstructedParticle::setStartVertex(::edm4hep::ConstVertex value) {
  if (m_obj->m_startVertex) delete m_obj->m_startVertex;
  m_obj->m_startVertex = new ::edm4hep::ConstVertex(value);
}

void ReconstructedParticle::setParticleIDUsed(::edm4hep::ConstParticleID value) {
  if (m_obj->m_particleIDUsed) delete m_obj->m_particleIDUsed;
  m_obj->m_particleIDUsed = new ::edm4hep::ConstParticleID(value);
}


void ReconstructedParticle::addToClusters(::edm4hep::ConstCluster component) {
  m_obj->m_clusters->push_back(component);
  m_obj->data.clusters_end++;
}

std::vector<::edm4hep::ConstCluster>::const_iterator ReconstructedParticle::clusters_begin() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstCluster>::const_iterator ReconstructedParticle::clusters_end() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_end);
  return ret_value;
}

unsigned int ReconstructedParticle::clusters_size() const {
  return m_obj->data.clusters_end - m_obj->data.clusters_begin;
}

::edm4hep::ConstCluster ReconstructedParticle::getClusters(unsigned int index) const {
  if (clusters_size() > index) {
    return m_obj->m_clusters->at(m_obj->data.clusters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstCluster> ReconstructedParticle::getClusters() const {
  auto begin = m_obj->m_clusters->begin();
  std::advance(begin, m_obj->data.clusters_begin);
  auto end = m_obj->m_clusters->begin();
  std::advance(end, m_obj->data.clusters_end);
  return {begin, end};
}

void ReconstructedParticle::addToTracks(::edm4hep::ConstTrack component) {
  m_obj->m_tracks->push_back(component);
  m_obj->data.tracks_end++;
}

std::vector<::edm4hep::ConstTrack>::const_iterator ReconstructedParticle::tracks_begin() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstTrack>::const_iterator ReconstructedParticle::tracks_end() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_end);
  return ret_value;
}

unsigned int ReconstructedParticle::tracks_size() const {
  return m_obj->data.tracks_end - m_obj->data.tracks_begin;
}

::edm4hep::ConstTrack ReconstructedParticle::getTracks(unsigned int index) const {
  if (tracks_size() > index) {
    return m_obj->m_tracks->at(m_obj->data.tracks_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstTrack> ReconstructedParticle::getTracks() const {
  auto begin = m_obj->m_tracks->begin();
  std::advance(begin, m_obj->data.tracks_begin);
  auto end = m_obj->m_tracks->begin();
  std::advance(end, m_obj->data.tracks_end);
  return {begin, end};
}

void ReconstructedParticle::addToParticles(::edm4hep::ConstReconstructedParticle component) {
  m_obj->m_particles->push_back(component);
  m_obj->data.particles_end++;
}

std::vector<::edm4hep::ConstReconstructedParticle>::const_iterator ReconstructedParticle::particles_begin() const {
  auto ret_value = m_obj->m_particles->begin();
  std::advance(ret_value, m_obj->data.particles_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstReconstructedParticle>::const_iterator ReconstructedParticle::particles_end() const {
  auto ret_value = m_obj->m_particles->begin();
  std::advance(ret_value, m_obj->data.particles_end);
  return ret_value;
}

unsigned int ReconstructedParticle::particles_size() const {
  return m_obj->data.particles_end - m_obj->data.particles_begin;
}

::edm4hep::ConstReconstructedParticle ReconstructedParticle::getParticles(unsigned int index) const {
  if (particles_size() > index) {
    return m_obj->m_particles->at(m_obj->data.particles_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstReconstructedParticle> ReconstructedParticle::getParticles() const {
  auto begin = m_obj->m_particles->begin();
  std::advance(begin, m_obj->data.particles_begin);
  auto end = m_obj->m_particles->begin();
  std::advance(end, m_obj->data.particles_end);
  return {begin, end};
}

void ReconstructedParticle::addToParticleIDs(::edm4hep::ConstParticleID component) {
  m_obj->m_particleIDs->push_back(component);
  m_obj->data.particleIDs_end++;
}

std::vector<::edm4hep::ConstParticleID>::const_iterator ReconstructedParticle::particleIDs_begin() const {
  auto ret_value = m_obj->m_particleIDs->begin();
  std::advance(ret_value, m_obj->data.particleIDs_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstParticleID>::const_iterator ReconstructedParticle::particleIDs_end() const {
  auto ret_value = m_obj->m_particleIDs->begin();
  std::advance(ret_value, m_obj->data.particleIDs_end);
  return ret_value;
}

unsigned int ReconstructedParticle::particleIDs_size() const {
  return m_obj->data.particleIDs_end - m_obj->data.particleIDs_begin;
}

::edm4hep::ConstParticleID ReconstructedParticle::getParticleIDs(unsigned int index) const {
  if (particleIDs_size() > index) {
    return m_obj->m_particleIDs->at(m_obj->data.particleIDs_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstParticleID> ReconstructedParticle::getParticleIDs() const {
  auto begin = m_obj->m_particleIDs->begin();
  std::advance(begin, m_obj->data.particleIDs_begin);
  auto end = m_obj->m_particleIDs->begin();
  std::advance(end, m_obj->data.particleIDs_end);
  return {begin, end};
}






bool ReconstructedParticle::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ReconstructedParticle::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ReconstructedParticle::operator==(const ConstReconstructedParticle& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstReconstructedParticle& value) {
  o << " id: " << value.id() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " momentum : " << value.getMomentum() << '\n';
  o << " referencePoint : " << value.getReferencePoint() << '\n';
  o << " charge : " << value.getCharge() << '\n';
  o << " mass : " << value.getMass() << '\n';
  o << " goodnessOfPID : " << value.getGoodnessOfPID() << '\n';
  o << " covMatrix : ";
  for (size_t i = 0; i < 10; ++i) {
    o << value.getCovMatrix()[i] << "|";
  }
  o << '\n';

  o << " startVertex : " << value.getStartVertex().id() << '\n';
  o << " particleIDUsed : " << value.getParticleIDUsed().id() << '\n';

  o << " clusters : ";
  for (unsigned i = 0; i < value.clusters_size(); ++i) {
    o << value.getClusters(i) << " ";
  }
  o << '\n';
  o << " tracks : ";
  for (unsigned i = 0; i < value.tracks_size(); ++i) {
    o << value.getTracks(i) << " ";
  }
  o << '\n';
  o << " particles : ";
  for (unsigned i = 0; i < value.particles_size(); ++i) {
    o << value.getParticles(i).id() << " ";
  }
  o << '\n';
  o << " particleIDs : ";
  for (unsigned i = 0; i < value.particleIDs_size(); ++i) {
    o << value.getParticleIDs(i) << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

