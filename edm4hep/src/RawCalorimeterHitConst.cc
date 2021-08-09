// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/RawCalorimeterHit.h"
#include "edm4hep/RawCalorimeterHitConst.h"
#include "edm4hep/RawCalorimeterHitObj.h"
#include "edm4hep/RawCalorimeterHitData.h"
#include "edm4hep/RawCalorimeterHitCollection.h"


#include <ostream>

namespace edm4hep {


ConstRawCalorimeterHit::ConstRawCalorimeterHit() : m_obj(new RawCalorimeterHitObj()) {
  m_obj->acquire();
}

ConstRawCalorimeterHit::ConstRawCalorimeterHit(unsigned long long cellID, int amplitude, int timeStamp) : m_obj(new RawCalorimeterHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.amplitude = amplitude;
  m_obj->data.timeStamp = timeStamp;
}

ConstRawCalorimeterHit::ConstRawCalorimeterHit(const ConstRawCalorimeterHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstRawCalorimeterHit& ConstRawCalorimeterHit::operator=(const ConstRawCalorimeterHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstRawCalorimeterHit::ConstRawCalorimeterHit( RawCalorimeterHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstRawCalorimeterHit ConstRawCalorimeterHit::clone() const {
  return {new RawCalorimeterHitObj(*m_obj)};
}

ConstRawCalorimeterHit::~ConstRawCalorimeterHit() {
  if (m_obj) m_obj->release();
}
const unsigned long long& ConstRawCalorimeterHit::getCellID() const { return m_obj->data.cellID; }
const int& ConstRawCalorimeterHit::getAmplitude() const { return m_obj->data.amplitude; }
const int& ConstRawCalorimeterHit::getTimeStamp() const { return m_obj->data.timeStamp; }






bool ConstRawCalorimeterHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstRawCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstRawCalorimeterHit::operator==(const RawCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

