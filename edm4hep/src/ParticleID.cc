// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/ParticleID.h"
#include "edm4hep/ParticleIDConst.h"
#include "edm4hep/ParticleIDObj.h"
#include "edm4hep/ParticleIDData.h"
#include "edm4hep/ParticleIDCollection.h"


#include <ostream>

namespace edm4hep {


ParticleID::ParticleID() : m_obj(new ParticleIDObj()) {
  m_obj->acquire();
}

ParticleID::ParticleID(int type, int PDG, int algorithmType, float likelihood) : m_obj(new ParticleIDObj()) {
  m_obj->acquire();
  m_obj->data.type = type;
  m_obj->data.PDG = PDG;
  m_obj->data.algorithmType = algorithmType;
  m_obj->data.likelihood = likelihood;
}

ParticleID::ParticleID(const ParticleID& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ParticleID& ParticleID::operator=(const ParticleID& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ParticleID::ParticleID( ParticleIDObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ParticleID ParticleID::clone() const {
  return {new ParticleIDObj(*m_obj)};
}

ParticleID::~ParticleID() {
  if (m_obj) m_obj->release();
}
ParticleID::operator ConstParticleID() const { return ConstParticleID(m_obj); }

const int& ParticleID::getType() const { return m_obj->data.type; }
const int& ParticleID::getPDG() const { return m_obj->data.PDG; }
const int& ParticleID::getAlgorithmType() const { return m_obj->data.algorithmType; }
const float& ParticleID::getLikelihood() const { return m_obj->data.likelihood; }


void ParticleID::setType(int value) { m_obj->data.type = value; }
void ParticleID::setPDG(int value) { m_obj->data.PDG = value; }
void ParticleID::setAlgorithmType(int value) { m_obj->data.algorithmType = value; }
void ParticleID::setLikelihood(float value) { m_obj->data.likelihood = value; }


void ParticleID::addToParameters(float component) {
  m_obj->m_parameters->push_back(component);
  m_obj->data.parameters_end++;
}

std::vector<float>::const_iterator ParticleID::parameters_begin() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator ParticleID::parameters_end() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_end);
  return ret_value;
}

unsigned int ParticleID::parameters_size() const {
  return m_obj->data.parameters_end - m_obj->data.parameters_begin;
}

float ParticleID::getParameters(unsigned int index) const {
  if (parameters_size() > index) {
    return m_obj->m_parameters->at(m_obj->data.parameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> ParticleID::getParameters() const {
  auto begin = m_obj->m_parameters->begin();
  std::advance(begin, m_obj->data.parameters_begin);
  auto end = m_obj->m_parameters->begin();
  std::advance(end, m_obj->data.parameters_end);
  return {begin, end};
}






bool ParticleID::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ParticleID::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ParticleID::operator==(const ConstParticleID& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstParticleID& value) {
  o << " id: " << value.id() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " PDG : " << value.getPDG() << '\n';
  o << " algorithmType : " << value.getAlgorithmType() << '\n';
  o << " likelihood : " << value.getLikelihood() << '\n';


  o << " parameters : ";
  for (unsigned i = 0; i < value.parameters_size(); ++i) {
    o << value.getParameters(i) << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

