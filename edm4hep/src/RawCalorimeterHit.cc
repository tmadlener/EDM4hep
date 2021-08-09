// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/RawCalorimeterHit.h"
#include "edm4hep/RawCalorimeterHitConst.h"
#include "edm4hep/RawCalorimeterHitObj.h"
#include "edm4hep/RawCalorimeterHitData.h"
#include "edm4hep/RawCalorimeterHitCollection.h"


#include <ostream>

namespace edm4hep {


RawCalorimeterHit::RawCalorimeterHit() : m_obj(new RawCalorimeterHitObj()) {
  m_obj->acquire();
}

RawCalorimeterHit::RawCalorimeterHit(unsigned long long cellID, int amplitude, int timeStamp) : m_obj(new RawCalorimeterHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.amplitude = amplitude;
  m_obj->data.timeStamp = timeStamp;
}

RawCalorimeterHit::RawCalorimeterHit(const RawCalorimeterHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

RawCalorimeterHit& RawCalorimeterHit::operator=(const RawCalorimeterHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

RawCalorimeterHit::RawCalorimeterHit( RawCalorimeterHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

RawCalorimeterHit RawCalorimeterHit::clone() const {
  return {new RawCalorimeterHitObj(*m_obj)};
}

RawCalorimeterHit::~RawCalorimeterHit() {
  if (m_obj) m_obj->release();
}
RawCalorimeterHit::operator ConstRawCalorimeterHit() const { return ConstRawCalorimeterHit(m_obj); }

const unsigned long long& RawCalorimeterHit::getCellID() const { return m_obj->data.cellID; }
const int& RawCalorimeterHit::getAmplitude() const { return m_obj->data.amplitude; }
const int& RawCalorimeterHit::getTimeStamp() const { return m_obj->data.timeStamp; }


void RawCalorimeterHit::setCellID(unsigned long long value) { m_obj->data.cellID = value; }
void RawCalorimeterHit::setAmplitude(int value) { m_obj->data.amplitude = value; }
void RawCalorimeterHit::setTimeStamp(int value) { m_obj->data.timeStamp = value; }







bool RawCalorimeterHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID RawCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool RawCalorimeterHit::operator==(const ConstRawCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstRawCalorimeterHit& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " amplitude : " << value.getAmplitude() << '\n';
  o << " timeStamp : " << value.getTimeStamp() << '\n';



  return o;
}

} // namespace edm4hep

