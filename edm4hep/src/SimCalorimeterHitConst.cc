// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/SimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHitConst.h"
#include "edm4hep/SimCalorimeterHitObj.h"
#include "edm4hep/SimCalorimeterHitData.h"
#include "edm4hep/SimCalorimeterHitCollection.h"


#include <ostream>

namespace edm4hep {


ConstSimCalorimeterHit::ConstSimCalorimeterHit() : m_obj(new SimCalorimeterHitObj()) {
  m_obj->acquire();
}

ConstSimCalorimeterHit::ConstSimCalorimeterHit(unsigned long long cellID, float energy, edm4hep::Vector3f position) : m_obj(new SimCalorimeterHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.energy = energy;
  m_obj->data.position = position;
}

ConstSimCalorimeterHit::ConstSimCalorimeterHit(const ConstSimCalorimeterHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstSimCalorimeterHit& ConstSimCalorimeterHit::operator=(const ConstSimCalorimeterHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstSimCalorimeterHit::ConstSimCalorimeterHit( SimCalorimeterHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstSimCalorimeterHit ConstSimCalorimeterHit::clone() const {
  return {new SimCalorimeterHitObj(*m_obj)};
}

ConstSimCalorimeterHit::~ConstSimCalorimeterHit() {
  if (m_obj) m_obj->release();
}
const unsigned long long& ConstSimCalorimeterHit::getCellID() const { return m_obj->data.cellID; }
const float& ConstSimCalorimeterHit::getEnergy() const { return m_obj->data.energy; }
const edm4hep::Vector3f& ConstSimCalorimeterHit::getPosition() const { return m_obj->data.position; }



std::vector<::edm4hep::ConstCaloHitContribution>::const_iterator ConstSimCalorimeterHit::contributions_begin() const {
  auto ret_value = m_obj->m_contributions->begin();
  std::advance(ret_value, m_obj->data.contributions_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstCaloHitContribution>::const_iterator ConstSimCalorimeterHit::contributions_end() const {
  auto ret_value = m_obj->m_contributions->begin();
  std::advance(ret_value, m_obj->data.contributions_end);
  return ret_value;
}

unsigned int ConstSimCalorimeterHit::contributions_size() const {
  return m_obj->data.contributions_end - m_obj->data.contributions_begin;
}

::edm4hep::ConstCaloHitContribution ConstSimCalorimeterHit::getContributions(unsigned int index) const {
  if (contributions_size() > index) {
    return m_obj->m_contributions->at(m_obj->data.contributions_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstCaloHitContribution> ConstSimCalorimeterHit::getContributions() const {
  auto begin = m_obj->m_contributions->begin();
  std::advance(begin, m_obj->data.contributions_begin);
  auto end = m_obj->m_contributions->begin();
  std::advance(end, m_obj->data.contributions_end);
  return {begin, end};
}





bool ConstSimCalorimeterHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstSimCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstSimCalorimeterHit::operator==(const SimCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

