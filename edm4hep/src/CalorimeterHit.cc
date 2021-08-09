// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/CalorimeterHitConst.h"
#include "edm4hep/CalorimeterHitObj.h"
#include "edm4hep/CalorimeterHitData.h"
#include "edm4hep/CalorimeterHitCollection.h"


#include <ostream>

namespace edm4hep {


CalorimeterHit::CalorimeterHit() : m_obj(new CalorimeterHitObj()) {
  m_obj->acquire();
}

CalorimeterHit::CalorimeterHit(unsigned long long cellID, float energy, float energyError, float time, edm4hep::Vector3f position, int type) : m_obj(new CalorimeterHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.energy = energy;
  m_obj->data.energyError = energyError;
  m_obj->data.time = time;
  m_obj->data.position = position;
  m_obj->data.type = type;
}

CalorimeterHit::CalorimeterHit(const CalorimeterHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

CalorimeterHit& CalorimeterHit::operator=(const CalorimeterHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

CalorimeterHit::CalorimeterHit( CalorimeterHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

CalorimeterHit CalorimeterHit::clone() const {
  return {new CalorimeterHitObj(*m_obj)};
}

CalorimeterHit::~CalorimeterHit() {
  if (m_obj) m_obj->release();
}
CalorimeterHit::operator ConstCalorimeterHit() const { return ConstCalorimeterHit(m_obj); }

const unsigned long long& CalorimeterHit::getCellID() const { return m_obj->data.cellID; }
const float& CalorimeterHit::getEnergy() const { return m_obj->data.energy; }
const float& CalorimeterHit::getEnergyError() const { return m_obj->data.energyError; }
const float& CalorimeterHit::getTime() const { return m_obj->data.time; }
const edm4hep::Vector3f& CalorimeterHit::getPosition() const { return m_obj->data.position; }
const int& CalorimeterHit::getType() const { return m_obj->data.type; }


void CalorimeterHit::setCellID(unsigned long long value) { m_obj->data.cellID = value; }
void CalorimeterHit::setEnergy(float value) { m_obj->data.energy = value; }
void CalorimeterHit::setEnergyError(float value) { m_obj->data.energyError = value; }
void CalorimeterHit::setTime(float value) { m_obj->data.time = value; }
void CalorimeterHit::setPosition(edm4hep::Vector3f value) { m_obj->data.position = value; }
edm4hep::Vector3f& CalorimeterHit::position() { return m_obj->data.position; }
void CalorimeterHit::setType(int value) { m_obj->data.type = value; }







bool CalorimeterHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID CalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool CalorimeterHit::operator==(const ConstCalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstCalorimeterHit& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " energyError : " << value.getEnergyError() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " type : " << value.getType() << '\n';



  return o;
}

} // namespace edm4hep

