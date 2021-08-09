// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/Cluster.h"
#include "edm4hep/ClusterConst.h"
#include "edm4hep/ClusterObj.h"
#include "edm4hep/ClusterData.h"
#include "edm4hep/ClusterCollection.h"


#include <ostream>

namespace edm4hep {


ConstCluster::ConstCluster() : m_obj(new ClusterObj()) {
  m_obj->acquire();
}

ConstCluster::ConstCluster(int type, float energy, float energyError, edm4hep::Vector3f position, std::array<float, 6> positionError, float iTheta, float phi, edm4hep::Vector3f directionError) : m_obj(new ClusterObj()) {
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

ConstCluster::ConstCluster(const ConstCluster& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstCluster& ConstCluster::operator=(const ConstCluster& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstCluster::ConstCluster( ClusterObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstCluster ConstCluster::clone() const {
  return {new ClusterObj(*m_obj)};
}

ConstCluster::~ConstCluster() {
  if (m_obj) m_obj->release();
}
const int& ConstCluster::getType() const { return m_obj->data.type; }
const float& ConstCluster::getEnergy() const { return m_obj->data.energy; }
const float& ConstCluster::getEnergyError() const { return m_obj->data.energyError; }
const edm4hep::Vector3f& ConstCluster::getPosition() const { return m_obj->data.position; }
const std::array<float, 6>& ConstCluster::getPositionError() const { return m_obj->data.positionError; }
const float& ConstCluster::getPositionError(size_t i) const { return m_obj->data.positionError.at(i); }
const float& ConstCluster::getITheta() const { return m_obj->data.iTheta; }
const float& ConstCluster::getPhi() const { return m_obj->data.phi; }
const edm4hep::Vector3f& ConstCluster::getDirectionError() const { return m_obj->data.directionError; }



std::vector<::edm4hep::ConstCluster>::const_iterator ConstCluster::clusters_begin() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstCluster>::const_iterator ConstCluster::clusters_end() const {
  auto ret_value = m_obj->m_clusters->begin();
  std::advance(ret_value, m_obj->data.clusters_end);
  return ret_value;
}

unsigned int ConstCluster::clusters_size() const {
  return m_obj->data.clusters_end - m_obj->data.clusters_begin;
}

::edm4hep::ConstCluster ConstCluster::getClusters(unsigned int index) const {
  if (clusters_size() > index) {
    return m_obj->m_clusters->at(m_obj->data.clusters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstCluster> ConstCluster::getClusters() const {
  auto begin = m_obj->m_clusters->begin();
  std::advance(begin, m_obj->data.clusters_begin);
  auto end = m_obj->m_clusters->begin();
  std::advance(end, m_obj->data.clusters_end);
  return {begin, end};
}


std::vector<::edm4hep::ConstCalorimeterHit>::const_iterator ConstCluster::hits_begin() const {
  auto ret_value = m_obj->m_hits->begin();
  std::advance(ret_value, m_obj->data.hits_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstCalorimeterHit>::const_iterator ConstCluster::hits_end() const {
  auto ret_value = m_obj->m_hits->begin();
  std::advance(ret_value, m_obj->data.hits_end);
  return ret_value;
}

unsigned int ConstCluster::hits_size() const {
  return m_obj->data.hits_end - m_obj->data.hits_begin;
}

::edm4hep::ConstCalorimeterHit ConstCluster::getHits(unsigned int index) const {
  if (hits_size() > index) {
    return m_obj->m_hits->at(m_obj->data.hits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstCalorimeterHit> ConstCluster::getHits() const {
  auto begin = m_obj->m_hits->begin();
  std::advance(begin, m_obj->data.hits_begin);
  auto end = m_obj->m_hits->begin();
  std::advance(end, m_obj->data.hits_end);
  return {begin, end};
}


std::vector<::edm4hep::ConstParticleID>::const_iterator ConstCluster::particleIDs_begin() const {
  auto ret_value = m_obj->m_particleIDs->begin();
  std::advance(ret_value, m_obj->data.particleIDs_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstParticleID>::const_iterator ConstCluster::particleIDs_end() const {
  auto ret_value = m_obj->m_particleIDs->begin();
  std::advance(ret_value, m_obj->data.particleIDs_end);
  return ret_value;
}

unsigned int ConstCluster::particleIDs_size() const {
  return m_obj->data.particleIDs_end - m_obj->data.particleIDs_begin;
}

::edm4hep::ConstParticleID ConstCluster::getParticleIDs(unsigned int index) const {
  if (particleIDs_size() > index) {
    return m_obj->m_particleIDs->at(m_obj->data.particleIDs_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstParticleID> ConstCluster::getParticleIDs() const {
  auto begin = m_obj->m_particleIDs->begin();
  std::advance(begin, m_obj->data.particleIDs_begin);
  auto end = m_obj->m_particleIDs->begin();
  std::advance(end, m_obj->data.particleIDs_end);
  return {begin, end};
}


std::vector<float>::const_iterator ConstCluster::shapeParameters_begin() const {
  auto ret_value = m_obj->m_shapeParameters->begin();
  std::advance(ret_value, m_obj->data.shapeParameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator ConstCluster::shapeParameters_end() const {
  auto ret_value = m_obj->m_shapeParameters->begin();
  std::advance(ret_value, m_obj->data.shapeParameters_end);
  return ret_value;
}

unsigned int ConstCluster::shapeParameters_size() const {
  return m_obj->data.shapeParameters_end - m_obj->data.shapeParameters_begin;
}

float ConstCluster::getShapeParameters(unsigned int index) const {
  if (shapeParameters_size() > index) {
    return m_obj->m_shapeParameters->at(m_obj->data.shapeParameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> ConstCluster::getShapeParameters() const {
  auto begin = m_obj->m_shapeParameters->begin();
  std::advance(begin, m_obj->data.shapeParameters_begin);
  auto end = m_obj->m_shapeParameters->begin();
  std::advance(end, m_obj->data.shapeParameters_end);
  return {begin, end};
}


std::vector<float>::const_iterator ConstCluster::hitContributions_begin() const {
  auto ret_value = m_obj->m_hitContributions->begin();
  std::advance(ret_value, m_obj->data.hitContributions_begin);
  return ret_value;
}

std::vector<float>::const_iterator ConstCluster::hitContributions_end() const {
  auto ret_value = m_obj->m_hitContributions->begin();
  std::advance(ret_value, m_obj->data.hitContributions_end);
  return ret_value;
}

unsigned int ConstCluster::hitContributions_size() const {
  return m_obj->data.hitContributions_end - m_obj->data.hitContributions_begin;
}

float ConstCluster::getHitContributions(unsigned int index) const {
  if (hitContributions_size() > index) {
    return m_obj->m_hitContributions->at(m_obj->data.hitContributions_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> ConstCluster::getHitContributions() const {
  auto begin = m_obj->m_hitContributions->begin();
  std::advance(begin, m_obj->data.hitContributions_begin);
  auto end = m_obj->m_hitContributions->begin();
  std::advance(end, m_obj->data.hitContributions_end);
  return {begin, end};
}


std::vector<float>::const_iterator ConstCluster::subdetectorEnergies_begin() const {
  auto ret_value = m_obj->m_subdetectorEnergies->begin();
  std::advance(ret_value, m_obj->data.subdetectorEnergies_begin);
  return ret_value;
}

std::vector<float>::const_iterator ConstCluster::subdetectorEnergies_end() const {
  auto ret_value = m_obj->m_subdetectorEnergies->begin();
  std::advance(ret_value, m_obj->data.subdetectorEnergies_end);
  return ret_value;
}

unsigned int ConstCluster::subdetectorEnergies_size() const {
  return m_obj->data.subdetectorEnergies_end - m_obj->data.subdetectorEnergies_begin;
}

float ConstCluster::getSubdetectorEnergies(unsigned int index) const {
  if (subdetectorEnergies_size() > index) {
    return m_obj->m_subdetectorEnergies->at(m_obj->data.subdetectorEnergies_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> ConstCluster::getSubdetectorEnergies() const {
  auto begin = m_obj->m_subdetectorEnergies->begin();
  std::advance(begin, m_obj->data.subdetectorEnergies_begin);
  auto end = m_obj->m_subdetectorEnergies->begin();
  std::advance(end, m_obj->data.subdetectorEnergies_end);
  return {begin, end};
}





bool ConstCluster::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstCluster::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstCluster::operator==(const Cluster& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

