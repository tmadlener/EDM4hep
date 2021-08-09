// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCParticleConst.h"
#include "edm4hep/MCParticleObj.h"
#include "edm4hep/MCParticleData.h"
#include "edm4hep/MCParticleCollection.h"


#include <ostream>

namespace edm4hep {


MCParticle::MCParticle() : m_obj(new MCParticleObj()) {
  m_obj->acquire();
}

MCParticle::MCParticle(int PDG, int generatorStatus, int simulatorStatus, float charge, float time, double mass, edm4hep::Vector3d vertex, edm4hep::Vector3d endpoint, edm4hep::Vector3f momentum, edm4hep::Vector3f momentumAtEndpoint, edm4hep::Vector3f spin, edm4hep::Vector2i colorFlow) : m_obj(new MCParticleObj()) {
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

MCParticle::MCParticle(const MCParticle& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

MCParticle& MCParticle::operator=(const MCParticle& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

MCParticle::MCParticle( MCParticleObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

MCParticle MCParticle::clone() const {
  return {new MCParticleObj(*m_obj)};
}

MCParticle::~MCParticle() {
  if (m_obj) m_obj->release();
}
MCParticle::operator ConstMCParticle() const { return ConstMCParticle(m_obj); }

const int& MCParticle::getPDG() const { return m_obj->data.PDG; }
const int& MCParticle::getGeneratorStatus() const { return m_obj->data.generatorStatus; }
const int& MCParticle::getSimulatorStatus() const { return m_obj->data.simulatorStatus; }
const float& MCParticle::getCharge() const { return m_obj->data.charge; }
const float& MCParticle::getTime() const { return m_obj->data.time; }
const double& MCParticle::getMass() const { return m_obj->data.mass; }
const edm4hep::Vector3d& MCParticle::getVertex() const { return m_obj->data.vertex; }
const edm4hep::Vector3d& MCParticle::getEndpoint() const { return m_obj->data.endpoint; }
const edm4hep::Vector3f& MCParticle::getMomentum() const { return m_obj->data.momentum; }
const edm4hep::Vector3f& MCParticle::getMomentumAtEndpoint() const { return m_obj->data.momentumAtEndpoint; }
const edm4hep::Vector3f& MCParticle::getSpin() const { return m_obj->data.spin; }
const edm4hep::Vector2i& MCParticle::getColorFlow() const { return m_obj->data.colorFlow; }


void MCParticle::setPDG(int value) { m_obj->data.PDG = value; }
void MCParticle::setGeneratorStatus(int value) { m_obj->data.generatorStatus = value; }
void MCParticle::setSimulatorStatus(int value) { m_obj->data.simulatorStatus = value; }
void MCParticle::setCharge(float value) { m_obj->data.charge = value; }
void MCParticle::setTime(float value) { m_obj->data.time = value; }
void MCParticle::setMass(double value) { m_obj->data.mass = value; }
void MCParticle::setVertex(edm4hep::Vector3d value) { m_obj->data.vertex = value; }
edm4hep::Vector3d& MCParticle::vertex() { return m_obj->data.vertex; }
void MCParticle::setEndpoint(edm4hep::Vector3d value) { m_obj->data.endpoint = value; }
edm4hep::Vector3d& MCParticle::endpoint() { return m_obj->data.endpoint; }
void MCParticle::setMomentum(edm4hep::Vector3f value) { m_obj->data.momentum = value; }
edm4hep::Vector3f& MCParticle::momentum() { return m_obj->data.momentum; }
void MCParticle::setMomentumAtEndpoint(edm4hep::Vector3f value) { m_obj->data.momentumAtEndpoint = value; }
edm4hep::Vector3f& MCParticle::momentumAtEndpoint() { return m_obj->data.momentumAtEndpoint; }
void MCParticle::setSpin(edm4hep::Vector3f value) { m_obj->data.spin = value; }
edm4hep::Vector3f& MCParticle::spin() { return m_obj->data.spin; }
void MCParticle::setColorFlow(edm4hep::Vector2i value) { m_obj->data.colorFlow = value; }
edm4hep::Vector2i& MCParticle::colorFlow() { return m_obj->data.colorFlow; }


void MCParticle::addToParents(::edm4hep::ConstMCParticle component) {
  m_obj->m_parents->push_back(component);
  m_obj->data.parents_end++;
}

std::vector<::edm4hep::ConstMCParticle>::const_iterator MCParticle::parents_begin() const {
  auto ret_value = m_obj->m_parents->begin();
  std::advance(ret_value, m_obj->data.parents_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstMCParticle>::const_iterator MCParticle::parents_end() const {
  auto ret_value = m_obj->m_parents->begin();
  std::advance(ret_value, m_obj->data.parents_end);
  return ret_value;
}

unsigned int MCParticle::parents_size() const {
  return m_obj->data.parents_end - m_obj->data.parents_begin;
}

::edm4hep::ConstMCParticle MCParticle::getParents(unsigned int index) const {
  if (parents_size() > index) {
    return m_obj->m_parents->at(m_obj->data.parents_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstMCParticle> MCParticle::getParents() const {
  auto begin = m_obj->m_parents->begin();
  std::advance(begin, m_obj->data.parents_begin);
  auto end = m_obj->m_parents->begin();
  std::advance(end, m_obj->data.parents_end);
  return {begin, end};
}

void MCParticle::addToDaughters(::edm4hep::ConstMCParticle component) {
  m_obj->m_daughters->push_back(component);
  m_obj->data.daughters_end++;
}

std::vector<::edm4hep::ConstMCParticle>::const_iterator MCParticle::daughters_begin() const {
  auto ret_value = m_obj->m_daughters->begin();
  std::advance(ret_value, m_obj->data.daughters_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstMCParticle>::const_iterator MCParticle::daughters_end() const {
  auto ret_value = m_obj->m_daughters->begin();
  std::advance(ret_value, m_obj->data.daughters_end);
  return ret_value;
}

unsigned int MCParticle::daughters_size() const {
  return m_obj->data.daughters_end - m_obj->data.daughters_begin;
}

::edm4hep::ConstMCParticle MCParticle::getDaughters(unsigned int index) const {
  if (daughters_size() > index) {
    return m_obj->m_daughters->at(m_obj->data.daughters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstMCParticle> MCParticle::getDaughters() const {
  auto begin = m_obj->m_daughters->begin();
  std::advance(begin, m_obj->data.daughters_begin);
  auto end = m_obj->m_daughters->begin();
  std::advance(end, m_obj->data.daughters_end);
  return {begin, end};
}






bool MCParticle::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID MCParticle::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool MCParticle::operator==(const ConstMCParticle& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstMCParticle& value) {
  o << " id: " << value.id() << '\n';
  o << " PDG : " << value.getPDG() << '\n';
  o << " generatorStatus : " << value.getGeneratorStatus() << '\n';
  o << " simulatorStatus : " << value.getSimulatorStatus() << '\n';
  o << " charge : " << value.getCharge() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " mass : " << value.getMass() << '\n';
  o << " vertex : " << value.getVertex() << '\n';
  o << " endpoint : " << value.getEndpoint() << '\n';
  o << " momentum : " << value.getMomentum() << '\n';
  o << " momentumAtEndpoint : " << value.getMomentumAtEndpoint() << '\n';
  o << " spin : " << value.getSpin() << '\n';
  o << " colorFlow : " << value.getColorFlow() << '\n';


  o << " parents : ";
  for (unsigned i = 0; i < value.parents_size(); ++i) {
    o << value.getParents(i).id() << " ";
  }
  o << '\n';
  o << " daughters : ";
  for (unsigned i = 0; i < value.daughters_size(); ++i) {
    o << value.getDaughters(i).id() << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

