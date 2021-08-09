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


Vertex::Vertex() : m_obj(new VertexObj()) {
  m_obj->acquire();
}

Vertex::Vertex(int primary, float chi2, float probability, edm4hep::Vector3f position, std::array<float, 6> covMatrix, int algorithmType) : m_obj(new VertexObj()) {
  m_obj->acquire();
  m_obj->data.primary = primary;
  m_obj->data.chi2 = chi2;
  m_obj->data.probability = probability;
  m_obj->data.position = position;
  m_obj->data.covMatrix = covMatrix;
  m_obj->data.algorithmType = algorithmType;
}

Vertex::Vertex(const Vertex& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

Vertex& Vertex::operator=(const Vertex& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

Vertex::Vertex( VertexObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

Vertex Vertex::clone() const {
  return {new VertexObj(*m_obj)};
}

Vertex::~Vertex() {
  if (m_obj) m_obj->release();
}
Vertex::operator ConstVertex() const { return ConstVertex(m_obj); }

const int& Vertex::getPrimary() const { return m_obj->data.primary; }
const float& Vertex::getChi2() const { return m_obj->data.chi2; }
const float& Vertex::getProbability() const { return m_obj->data.probability; }
const edm4hep::Vector3f& Vertex::getPosition() const { return m_obj->data.position; }
const std::array<float, 6>& Vertex::getCovMatrix() const { return m_obj->data.covMatrix; }
const float& Vertex::getCovMatrix(size_t i) const { return m_obj->data.covMatrix.at(i); }
const int& Vertex::getAlgorithmType() const { return m_obj->data.algorithmType; }

const ::edm4hep::ConstReconstructedParticle Vertex::getAssociatedParticle() const {
  if (!m_obj->m_associatedParticle) {
    return ::edm4hep::ConstReconstructedParticle(nullptr);
  }
  return ::edm4hep::ConstReconstructedParticle(*(m_obj->m_associatedParticle));
}


void Vertex::setPrimary(int value) { m_obj->data.primary = value; }
void Vertex::setChi2(float value) { m_obj->data.chi2 = value; }
void Vertex::setProbability(float value) { m_obj->data.probability = value; }
void Vertex::setPosition(edm4hep::Vector3f value) { m_obj->data.position = value; }
edm4hep::Vector3f& Vertex::position() { return m_obj->data.position; }
void Vertex::setCovMatrix(std::array<float, 6> value) { m_obj->data.covMatrix = value; }
void Vertex::setCovMatrix(size_t i, float value) { m_obj->data.covMatrix.at(i) = value; }
std::array<float, 6>& Vertex::covMatrix() { return m_obj->data.covMatrix; }
void Vertex::setAlgorithmType(int value) { m_obj->data.algorithmType = value; }

void Vertex::setAssociatedParticle(::edm4hep::ConstReconstructedParticle value) {
  if (m_obj->m_associatedParticle) delete m_obj->m_associatedParticle;
  m_obj->m_associatedParticle = new ::edm4hep::ConstReconstructedParticle(value);
}


void Vertex::addToParameters(float component) {
  m_obj->m_parameters->push_back(component);
  m_obj->data.parameters_end++;
}

std::vector<float>::const_iterator Vertex::parameters_begin() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_begin);
  return ret_value;
}

std::vector<float>::const_iterator Vertex::parameters_end() const {
  auto ret_value = m_obj->m_parameters->begin();
  std::advance(ret_value, m_obj->data.parameters_end);
  return ret_value;
}

unsigned int Vertex::parameters_size() const {
  return m_obj->data.parameters_end - m_obj->data.parameters_begin;
}

float Vertex::getParameters(unsigned int index) const {
  if (parameters_size() > index) {
    return m_obj->m_parameters->at(m_obj->data.parameters_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<float> Vertex::getParameters() const {
  auto begin = m_obj->m_parameters->begin();
  std::advance(begin, m_obj->data.parameters_begin);
  auto end = m_obj->m_parameters->begin();
  std::advance(end, m_obj->data.parameters_end);
  return {begin, end};
}






bool Vertex::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID Vertex::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool Vertex::operator==(const ConstVertex& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstVertex& value) {
  o << " id: " << value.id() << '\n';
  o << " primary : " << value.getPrimary() << '\n';
  o << " chi2 : " << value.getChi2() << '\n';
  o << " probability : " << value.getProbability() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " covMatrix : ";
  for (size_t i = 0; i < 6; ++i) {
    o << value.getCovMatrix()[i] << "|";
  }
  o << '\n';
  o << " algorithmType : " << value.getAlgorithmType() << '\n';

  o << " associatedParticle : " << value.getAssociatedParticle().id() << '\n';

  o << " parameters : ";
  for (unsigned i = 0; i < value.parameters_size(); ++i) {
    o << value.getParameters(i) << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

