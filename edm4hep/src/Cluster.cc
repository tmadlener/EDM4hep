// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/Cluster.h"
#include "edm4hep/ClusterConst.h"
#include "edm4hep/ClusterObj.h"
#include "edm4hep/ClusterData.h"
#include "edm4hep/ClusterCollection.h"


#include <ostream>

namespace edm4hep {


Cluster::Cluster() : m_obj(new ClusterObj()) {
  m_obj->acquire();
}

Cluster::Cluster(int type, float energy, float energyError, edm4hep::Vector3f position, std::array<float, 6> positionError, float iTheta, float phi, edm4hep::Vector3f directionError) : m_obj(new ClusterObj()) {
  m_obj->acquire();
  m_obj->data.type = type;
  m_obj->data.energy = energy;
  m_obj->data.energyError = energyError;
  m_obj->data.position = position;
  m_obj->data.positionError = positionError;
  m_obj->data.iTheta = iTheta;
  m_obj->data.phi = phi;
  m_obj->data.directionError = directionError;
}

Cluster::Cluster(const Cluster& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

Cluster& Cluster::operator=(const Cluster& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

Cluster::Cluster( ClusterObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

Cluster Cluster::clone() const {
  return {new ClusterObj(*m_obj)};
}

Cluster::~Cluster() {
  if (m_obj) m_obj->release();
}
Cluster::operator ConstCluster() const { return ConstCluster(m_obj); }

const int& Cluster::getType() const { return m_obj->data.type; }
const float& Cluster::getEnergy() const { return m_obj->data.energy; }
const float& Cluster::getEnergyError() const { return m_obj->data.energyError; }
const edm4hep::Vector3f& Cluster::getPosition() const { return m_obj->data.position; }
const std::array<float, 6>& Cluster::getPositionError() const { return m_obj->data.positionError; }
const float& Cluster::getPositionError(size_t i) const { return m_obj->data.positionError.at(i); }
const float& Cluster::getITheta() const { return m_obj->data.iTheta; }
const float& Cluster::getPhi() const { return m_obj->data.phi; }
const edm4hep::Vector3f& Cluster::getDirectionError() const { return m_obj->data.directionError; }


void Cluster::setType(int value) { m_obj->data.type = value; }
void Cluster::setEnergy(float value) { m_obj->data.energy = value; }
void Cluster::setEnergyError(float value) { m_obj->data.energyError = value; }
void Cluster::setPosition(edm4hep::Vector3f value) { m_obj->data.position = value; }
edm4hep::Vector3f& Cluster::position() { return m_obj->data.position; }
void Cluster::setPositionError(std::array<float, 6> value) { m_obj->data.positionError = value; }
void Cluster::setPositionError(size_t i, float value) { m_obj->data.positionError.at(i) = value; }
std::array<float, 6>& Cluster::positionError() { return m_obj->data.positionError; }
void Cluster::setITheta(float value) { m_obj->data.iTheta = value; }
void Cluster::setPhi(float value) { m_obj->data.phi = value; }
void Cluster::setDirectionError(edm4hep::Vector3f value) { m_obj->data.directionError = value; }
edm4hep::Vector3f& Cluster::directionError() { return m_obj->data.directionError; }


void Cluster::addToClusters(::edm4hep::ConstCluster component) {
  m_obj->m_clusters->push_back(component);
  m_obj->data.clusters_end++;
}

std::vector<::edm4hep::ConstCluster>::const_iterator Cluster::clusters_begin() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstCluster>::const_iterator Cluster::clusters_end() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_end);
  return ret_value;
}

unsigned int Cluster::clusters_size() const {
  return m_obj->data.clusters_end - m_obj->data.clusters_begin;
}

::edm4hep::ConstCluster Cluster::getClusters(unsigned int index) const {
  if (clusters_size() > index) {
    return m_obj->m_clusters->at(m_obj->data.clusters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstCluster> Cluster::getClusters() const {
  auto begin = m_obj->m_clusters->begin();
  std::advance(begin, m_obj->data.clusters_begin);
  auto end = m_obj->m_clusters->begin();
  std::advance(end, m_obj->data.clusters_end);
  return {begin, end};
}

void Cluster::addToHits(::edm4hep::ConstCalorimeterHit component) {
  m_obj->m_hits->push_back(component);
  m_obj->data.hits_end++;
}

std::vector<::edm4hep::ConstCalorimeterHit>::const_iterator Cluster::hits_begin() const {
  auto ret_value = m_obj->m_hits->begin();
  std::advance(ret_value, m_obj->data.hits_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstCalorimeterHit>::const_iterator Cluster::hits_end() const {
  auto ret_value = m_obj->m_hits->begin();
  std::advance(ret_value, m_obj->data.hits_end);
  return ret_value;
}

unsigned int Cluster::hits_size() const {
  return m_obj->data.hits_end - m_obj->data.hits_begin;
}

::edm4hep::ConstCalorimeterHit Cluster::getHits(unsigned int index) const {
  if (hits_size() > index) {
    return m_obj->m_hits->at(m_obj->data.hits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstCalorimeterHit> Cluster::getHits() const {
  auto begin = m_obj->m_hits->begin();
  std::advance(begin, m_obj->data.hits_begin);
  auto end = m_obj->m_hits->begin();
  std::advance(end, m_obj->data.hits_end);
  return {begin, end};
}

void Cluster::addToParticleIDs(::edm4hep::ConstParticleID component) {
  m_obj->m_particleIDs->push_back(component);
  m_obj->data.particleIDs_end++;
}

std::vector<::edm4hep::ConstParticleID>::const_iterator Cluster::particleIDs_begin() const {
  auto ret_value = m_obj->m_particleIDs->begin();
  std::advance(ret_value, m_obj->data.particleIDs_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstParticleID>::const_iterator Cluster::particleIDs_end() const {
  auto ret_value = m_obj->m_particleIDs->begin();
  std::advance(ret_value, m_obj->data.particleIDs_end);
  return ret_value;
}

unsigned int Cluster::particleIDs_size() const {
  return m_obj->data.particleIDs_end - m_obj->data.particleIDs_begin;
}

::edm4hep::ConstParticleID Cluster::getParticleIDs(unsigned int index) const {
  if (particleIDs_size() > index) {
    return m_obj->m_particleIDs->at(m_obj->data.particleIDs_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstParticleID> Cluster::getParticleIDs() const {
  auto begin = m_obj->m_particleIDs->begin();
  std::advance(begin, m_obj->data.particleIDs_begin);
  auto end = m_obj->m_particleIDs->begin();
  std::advance(end, m_obj->data.particleIDs_end);
  return {begin, end};
}

void Cluster::addToShapeParameters(float component) {
  m_obj->m_shapeParameters->push_back(component);
  m_obj->data.shapeParameters_end++;
}

std::vector<float>::const_iterator Cluster::shapeParameters_begin() const {
  auto ret_value = m_obj->m_shapeParameters->begin();
  std::advance(ret_value, m_obj->data.shapeParameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator Cluster::shapeParameters_end() const {
  auto ret_value = m_obj->m_shapeParameters->begin();
  std::advance(ret_value, m_obj->data.shapeParameters_end);
  return ret_value;
}

unsigned int Cluster::shapeParameters_size() const {
  return m_obj->data.shapeParameters_end - m_obj->data.shapeParameters_begin;
}

float Cluster::getShapeParameters(unsigned int index) const {
  if (shapeParameters_size() > index) {
    return m_obj->m_shapeParameters->at(m_obj->data.shapeParameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> Cluster::getShapeParameters() const {
  auto begin = m_obj->m_shapeParameters->begin();
  std::advance(begin, m_obj->data.shapeParameters_begin);
  auto end = m_obj->m_shapeParameters->begin();
  std::advance(end, m_obj->data.shapeParameters_end);
  return {begin, end};
}

void Cluster::addToHitContributions(float component) {
  m_obj->m_hitContributions->push_back(component);
  m_obj->data.hitContributions_end++;
}

std::vector<float>::const_iterator Cluster::hitContributions_begin() const {
  auto ret_value = m_obj->m_hitContributions->begin();
  std::advance(ret_value, m_obj->data.hitContributions_begin);
  return ret_value;
}

std::vector<float>::const_iterator Cluster::hitContributions_end() const {
  auto ret_value = m_obj->m_hitContributions->begin();
  std::advance(ret_value, m_obj->data.hitContributions_end);
  return ret_value;
}

unsigned int Cluster::hitContributions_size() const {
  return m_obj->data.hitContributions_end - m_obj->data.hitContributions_begin;
}

float Cluster::getHitContributions(unsigned int index) const {
  if (hitContributions_size() > index) {
    return m_obj->m_hitContributions->at(m_obj->data.hitContributions_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> Cluster::getHitContributions() const {
  auto begin = m_obj->m_hitContributions->begin();
  std::advance(begin, m_obj->data.hitContributions_begin);
  auto end = m_obj->m_hitContributions->begin();
  std::advance(end, m_obj->data.hitContributions_end);
  return {begin, end};
}

void Cluster::addToSubdetectorEnergies(float component) {
  m_obj->m_subdetectorEnergies->push_back(component);
  m_obj->data.subdetectorEnergies_end++;
}

std::vector<float>::const_iterator Cluster::subdetectorEnergies_begin() const {
  auto ret_value = m_obj->m_subdetectorEnergies->begin();
  std::advance(ret_value, m_obj->data.subdetectorEnergies_begin);
  return ret_value;
}

std::vector<float>::const_iterator Cluster::subdetectorEnergies_end() const {
  auto ret_value = m_obj->m_subdetectorEnergies->begin();
  std::advance(ret_value, m_obj->data.subdetectorEnergies_end);
  return ret_value;
}

unsigned int Cluster::subdetectorEnergies_size() const {
  return m_obj->data.subdetectorEnergies_end - m_obj->data.subdetectorEnergies_begin;
}

float Cluster::getSubdetectorEnergies(unsigned int index) const {
  if (subdetectorEnergies_size() > index) {
    return m_obj->m_subdetectorEnergies->at(m_obj->data.subdetectorEnergies_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> Cluster::getSubdetectorEnergies() const {
  auto begin = m_obj->m_subdetectorEnergies->begin();
  std::advance(begin, m_obj->data.subdetectorEnergies_begin);
  auto end = m_obj->m_subdetectorEnergies->begin();
  std::advance(end, m_obj->data.subdetectorEnergies_end);
  return {begin, end};
}






bool Cluster::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID Cluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool Cluster::operator==(const ConstCluster& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstCluster& value) {
  o << " id: " << value.id() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " energyError : " << value.getEnergyError() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " positionError : ";
  for (size_t i = 0; i < 6; ++i) {
    o << value.getPositionError()[i] << "|";
  }
  o << '\n';
  o << " iTheta : " << value.getITheta() << '\n';
  o << " phi : " << value.getPhi() << '\n';
  o << " directionError : " << value.getDirectionError() << '\n';


  o << " clusters : ";
  for (unsigned i = 0; i < value.clusters_size(); ++i) {
    o << value.getClusters(i).id() << " ";
  }
  o << '\n';
  o << " hits : ";
  for (unsigned i = 0; i < value.hits_size(); ++i) {
    o << value.getHits(i) << " ";
  }
  o << '\n';
  o << " particleIDs : ";
  for (unsigned i = 0; i < value.particleIDs_size(); ++i) {
    o << value.getParticleIDs(i) << " ";
  }
  o << '\n';
  o << " shapeParameters : ";
  for (unsigned i = 0; i < value.shapeParameters_size(); ++i) {
    o << value.getShapeParameters(i) << " ";
  }
  o << '\n';
  o << " hitContributions : ";
  for (unsigned i = 0; i < value.hitContributions_size(); ++i) {
    o << value.getHitContributions(i) << " ";
  }
  o << '\n';
  o << " subdetectorEnergies : ";
  for (unsigned i = 0; i < value.subdetectorEnergies_size(); ++i) {
    o << value.getSubdetectorEnergies(i) << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

