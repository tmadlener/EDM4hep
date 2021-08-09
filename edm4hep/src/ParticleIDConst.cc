// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/ParticleID.h"
#include "edm4hep/ParticleIDConst.h"
#include "edm4hep/ParticleIDObj.h"
#include "edm4hep/ParticleIDData.h"
#include "edm4hep/ParticleIDCollection.h"


#include <ostream>

namespace edm4hep {


ConstParticleID::ConstParticleID() : m_obj(new ParticleIDObj()) {
  m_obj->acquire();
}

ConstParticleID::ConstParticleID(int type, int PDG, int algorithmType, float likelihood) : m_obj(new ParticleIDObj()) {
  m_obj->acquire();
  m_obj->data.type = type;
  m_obj->data.PDG = PDG;
  m_obj->data.algorithmType = algorithmType;
  m_obj->data.likelihood = likelihood;
}

ConstParticleID::ConstParticleID(const ConstParticleID& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstParticleID& ConstParticleID::operator=(const ConstParticleID& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstParticleID::ConstParticleID( ParticleIDObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstParticleID ConstParticleID::clone() const {
  return {new ParticleIDObj(*m_obj)};
}

ConstParticleID::~ConstParticleID() {
  if (m_obj) m_obj->release();
}
const int& ConstParticleID::getType() const { return m_obj->data.type; }
const int& ConstParticleID::getPDG() const { return m_obj->data.PDG; }
const int& ConstParticleID::getAlgorithmType() const { return m_obj->data.algorithmType; }
const float& ConstParticleID::getLikelihood() const { return m_obj->data.likelihood; }



std::vector<float>::const_iterator ConstParticleID::parameters_begin() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator ConstParticleID::parameters_end() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_end);
  return ret_value;
}

unsigned int ConstParticleID::parameters_size() const {
  return m_obj->data.parameters_end - m_obj->data.parameters_begin;
}

float ConstParticleID::getParameters(unsigned int index) const {
  if (parameters_size() > index) {
    return m_obj->m_parameters->at(m_obj->data.parameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> ConstParticleID::getParameters() const {
  auto begin = m_obj->m_parameters->begin();
  std::advance(begin, m_obj->data.parameters_begin);
  auto end = m_obj->m_parameters->begin();
  std::advance(end, m_obj->data.parameters_end);
  return {begin, end};
}





bool ConstParticleID::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstParticleID::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstParticleID::operator==(const ParticleID& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

