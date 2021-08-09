// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/Vertex.h"
#include "edm4hep/VertexConst.h"
#include "edm4hep/VertexObj.h"
#include "edm4hep/VertexData.h"
#include "edm4hep/VertexCollection.h"

#include "edm4hep/ReconstructedParticle.h"

#include <ostream>

namespace edm4hep {


ConstVertex::ConstVertex() : m_obj(new VertexObj()) {
  m_obj->acquire();
}

ConstVertex::ConstVertex(int primary, float chi2, float probability, edm4hep::Vector3f position, std::array<float, 6> covMatrix, int algorithmType) : m_obj(new VertexObj()) {
  m_obj->acquire();
  m_obj->data.primary = primary;
  m_obj->data.chi2 = chi2;
  m_obj->data.probability = probability;
  m_obj->data.position = position;
  m_obj->data.covMatrix = covMatrix;
  m_obj->data.algorithmType = algorithmType;
}

ConstVertex::ConstVertex(const ConstVertex& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstVertex& ConstVertex::operator=(const ConstVertex& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstVertex::ConstVertex( VertexObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstVertex ConstVertex::clone() const {
  return {new VertexObj(*m_obj)};
}

ConstVertex::~ConstVertex() {
  if (m_obj) m_obj->release();
}
const int& ConstVertex::getPrimary() const { return m_obj->data.primary; }
const float& ConstVertex::getChi2() const { return m_obj->data.chi2; }
const float& ConstVertex::getProbability() const { return m_obj->data.probability; }
const edm4hep::Vector3f& ConstVertex::getPosition() const { return m_obj->data.position; }
const std::array<float, 6>& ConstVertex::getCovMatrix() const { return m_obj->data.covMatrix; }
const float& ConstVertex::getCovMatrix(size_t i) const { return m_obj->data.covMatrix.at(i); }
const int& ConstVertex::getAlgorithmType() const { return m_obj->data.algorithmType; }

const ::edm4hep::ConstReconstructedParticle ConstVertex::getAssociatedParticle() const {
  if (!m_obj->m_associatedParticle) {
    return ::edm4hep::ConstReconstructedParticle(nullptr);
  }
  return ::edm4hep::ConstReconstructedParticle(*(m_obj->m_associatedParticle));
}



std::vector<float>::const_iterator ConstVertex::parameters_begin() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator ConstVertex::parameters_end() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_end);
  return ret_value;
}

unsigned int ConstVertex::parameters_size() const {
  return m_obj->data.parameters_end - m_obj->data.parameters_begin;
}

float ConstVertex::getParameters(unsigned int index) const {
  if (parameters_size() > index) {
    return m_obj->m_parameters->at(m_obj->data.parameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> ConstVertex::getParameters() const {
  auto begin = m_obj->m_parameters->begin();
  std::advance(begin, m_obj->data.parameters_begin);
  auto end = m_obj->m_parameters->begin();
  std::advance(end, m_obj->data.parameters_end);
  return {begin, end};
}





bool ConstVertex::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstVertex::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstVertex::operator==(const Vertex& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

