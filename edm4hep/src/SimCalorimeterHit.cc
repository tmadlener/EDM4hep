// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/SimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHitConst.h"
#include "edm4hep/SimCalorimeterHitObj.h"
#include "edm4hep/SimCalorimeterHitData.h"
#include "edm4hep/SimCalorimeterHitCollection.h"


#include <ostream>

namespace edm4hep {


SimCalorimeterHit::SimCalorimeterHit() : m_obj(new SimCalorimeterHitObj()) {
  m_obj->acquire();
}

SimCalorimeterHit::SimCalorimeterHit(unsigned long long cellID, float energy, edm4hep::Vector3f position) : m_obj(new SimCalorimeterHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.energy = energy;
  m_obj->data.position = position;
}

SimCalorimeterHit::SimCalorimeterHit(const SimCalorimeterHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

SimCalorimeterHit& SimCalorimeterHit::operator=(const SimCalorimeterHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

SimCalorimeterHit::SimCalorimeterHit( SimCalorimeterHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

SimCalorimeterHit SimCalorimeterHit::clone() const {
  return {new SimCalorimeterHitObj(*m_obj)};
}

SimCalorimeterHit::~SimCalorimeterHit() {
  if (m_obj) m_obj->release();
}
SimCalorimeterHit::operator ConstSimCalorimeterHit() const { return ConstSimCalorimeterHit(m_obj); }

const unsigned long long& SimCalorimeterHit::getCellID() const { return m_obj->data.cellID; }
const float& SimCalorimeterHit::getEnergy() const { return m_obj->data.energy; }
const edm4hep::Vector3f& SimCalorimeterHit::getPosition() const { return m_obj->data.position; }


void SimCalorimeterHit::setCellID(unsigned long long value) { m_obj->data.cellID = value; }
void SimCalorimeterHit::setEnergy(float value) { m_obj->data.energy = value; }
void SimCalorimeterHit::setPosition(edm4hep::Vector3f value) { m_obj->data.position = value; }
edm4hep::Vector3f& SimCalorimeterHit::position() { return m_obj->data.position; }


void SimCalorimeterHit::addToContributions(::edm4hep::ConstCaloHitContribution component) {
  m_obj->m_contributions->push_back(component);
  m_obj->data.contributions_end++;
}

std::vector<::edm4hep::ConstCaloHitContribution>::const_iterator SimCalorimeterHit::contributions_begin() const {
  auto ret_value = m_obj->m_contributions->begin();
  std::advance(ret_value, m_obj->data.contributions_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstCaloHitContribution>::const_iterator SimCalorimeterHit::contributions_end() const {
  auto ret_value = m_obj->m_contributions->begin();
  std::advance(ret_value, m_obj->data.contributions_end);
  return ret_value;
}

unsigned int SimCalorimeterHit::contributions_size() const {
  return m_obj->data.contributions_end - m_obj->data.contributions_begin;
}

::edm4hep::ConstCaloHitContribution SimCalorimeterHit::getContributions(unsigned int index) const {
  if (contributions_size() > index) {
    return m_obj->m_contributions->at(m_obj->data.contributions_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstCaloHitContribution> SimCalorimeterHit::getContributions() const {
  auto begin = m_obj->m_contributions->begin();
  std::advance(begin, m_obj->data.contributions_begin);
  auto end = m_obj->m_contributions->begin();
  std::advance(end, m_obj->data.contributions_end);
  return {begin, end};
}






bool SimCalorimeterHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID SimCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool SimCalorimeterHit::operator==(const ConstSimCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstSimCalorimeterHit& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " position : " << value.getPosition() << '\n';


  o << " contributions : ";
  for (unsigned i = 0; i < value.contributions_size(); ++i) {
    o << value.getContributions(i) << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

