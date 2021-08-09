// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCParticleConst.h"
#include "edm4hep/MCParticleObj.h"
#include "edm4hep/MCParticleData.h"
#include "edm4hep/MCParticleCollection.h"


#include <ostream>

namespace edm4hep {


ConstMCParticle::ConstMCParticle() : m_obj(new MCParticleObj()) {
  m_obj->acquire();
}

ConstMCParticle::ConstMCParticle(int PDG, int generatorStatus, int simulatorStatus, float charge, float time, double mass, edm4hep::Vector3d vertex, edm4hep::Vector3d endpoint, edm4hep::Vector3f momentum, edm4hep::Vector3f momentumAtEndpoint, edm4hep::Vector3f spin, edm4hep::Vector2i colorFlow) : m_obj(new MCParticleObj()) {
  m_obj->acquire();
  m_obj->data.PDG = PDG;
  m_obj->data.generatorStatus = generatorStatus;
  m_obj->data.simulatorStatus = simulatorStatus;
  m_obj->data.charge = charge;
  m_obj->data.time = time;
  m_obj->data.mass = mass;
  m_obj->data.vertex = vertex;
  m_obj->data.endpoint = endpoint;
  m_obj->data.momentum = momentum;
  m_obj->data.momentumAtEndpoint = momentumAtEndpoint;
  m_obj->data.spin = spin;
  m_obj->data.colorFlow = colorFlow;
}

ConstMCParticle::ConstMCParticle(const ConstMCParticle& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstMCParticle& ConstMCParticle::operator=(const ConstMCParticle& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstMCParticle::ConstMCParticle( MCParticleObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstMCParticle ConstMCParticle::clone() const {
  return {new MCParticleObj(*m_obj)};
}

ConstMCParticle::~ConstMCParticle() {
  if (m_obj) m_obj->release();
}
const int& ConstMCParticle::getPDG() const { return m_obj->data.PDG; }
const int& ConstMCParticle::getGeneratorStatus() const { return m_obj->data.generatorStatus; }
const int& ConstMCParticle::getSimulatorStatus() const { return m_obj->data.simulatorStatus; }
const float& ConstMCParticle::getCharge() const { return m_obj->data.charge; }
const float& ConstMCParticle::getTime() const { return m_obj->data.time; }
const double& ConstMCParticle::getMass() const { return m_obj->data.mass; }
const edm4hep::Vector3d& ConstMCParticle::getVertex() const { return m_obj->data.vertex; }
const edm4hep::Vector3d& ConstMCParticle::getEndpoint() const { return m_obj->data.endpoint; }
const edm4hep::Vector3f& ConstMCParticle::getMomentum() const { return m_obj->data.momentum; }
const edm4hep::Vector3f& ConstMCParticle::getMomentumAtEndpoint() const { return m_obj->data.momentumAtEndpoint; }
const edm4hep::Vector3f& ConstMCParticle::getSpin() const { return m_obj->data.spin; }
const edm4hep::Vector2i& ConstMCParticle::getColorFlow() const { return m_obj->data.colorFlow; }



std::vector<::edm4hep::ConstMCParticle>::const_iterator ConstMCParticle::parents_begin() const {
  auto ret_value = m_obj->m_parents->begin();
  std::advance(ret_value, m_obj->data.parents_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstMCParticle>::const_iterator ConstMCParticle::parents_end() const {
  auto ret_value = m_obj->m_parents->begin();
  std::advance(ret_value, m_obj->data.parents_end);
  return ret_value;
}

unsigned int ConstMCParticle::parents_size() const {
  return m_obj->data.parents_end - m_obj->data.parents_begin;
}

::edm4hep::ConstMCParticle ConstMCParticle::getParents(unsigned int index) const {
  if (parents_size() > index) {
    return m_obj->m_parents->at(m_obj->data.parents_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstMCParticle> ConstMCParticle::getParents() const {
  auto begin = m_obj->m_parents->begin();
  std::advance(begin, m_obj->data.parents_begin);
  auto end = m_obj->m_parents->begin();
  std::advance(end, m_obj->data.parents_end);
  return {begin, end};
}


std::vector<::edm4hep::ConstMCParticle>::const_iterator ConstMCParticle::daughters_begin() const {
  auto ret_value = m_obj->m_daughters->begin();
  std::advance(ret_value, m_obj->data.daughters_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstMCParticle>::const_iterator ConstMCParticle::daughters_end() const {
  auto ret_value = m_obj->m_daughters->begin();
  std::advance(ret_value, m_obj->data.daughters_end);
  return ret_value;
}

unsigned int ConstMCParticle::daughters_size() const {
  return m_obj->data.daughters_end - m_obj->data.daughters_begin;
}

::edm4hep::ConstMCParticle ConstMCParticle::getDaughters(unsigned int index) const {
  if (daughters_size() > index) {
    return m_obj->m_daughters->at(m_obj->data.daughters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstMCParticle> ConstMCParticle::getDaughters() const {
  auto begin = m_obj->m_daughters->begin();
  std::advance(begin, m_obj->data.daughters_begin);
  auto end = m_obj->m_daughters->begin();
  std::advance(end, m_obj->data.daughters_end);
  return {begin, end};
}





bool ConstMCParticle::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstMCParticle::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstMCParticle::operator==(const MCParticle& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

