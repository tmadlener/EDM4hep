// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/CalorimeterHitConst.h"
#include "edm4hep/CalorimeterHitObj.h"
#include "edm4hep/CalorimeterHitData.h"
#include "edm4hep/CalorimeterHitCollection.h"


#include <ostream>

namespace edm4hep {


ConstCalorimeterHit::ConstCalorimeterHit() : m_obj(new CalorimeterHitObj()) {
  m_obj->acquire();
}

ConstCalorimeterHit::ConstCalorimeterHit(unsigned long long cellID, float energy, float energyError, float time, edm4hep::Vector3f position, int type) : m_obj(new CalorimeterHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.energy = energy;
  m_obj->data.energyError = energyError;
  m_obj->data.time = time;
  m_obj->data.position = position;
  m_obj->data.type = type;
}

ConstCalorimeterHit::ConstCalorimeterHit(const ConstCalorimeterHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstCalorimeterHit& ConstCalorimeterHit::operator=(const ConstCalorimeterHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstCalorimeterHit::ConstCalorimeterHit( CalorimeterHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstCalorimeterHit ConstCalorimeterHit::clone() const {
  return {new CalorimeterHitObj(*m_obj)};
}

ConstCalorimeterHit::~ConstCalorimeterHit() {
  if (m_obj) m_obj->release();
}
const unsigned long long& ConstCalorimeterHit::getCellID() const { return m_obj->data.cellID; }
const float& ConstCalorimeterHit::getEnergy() const { return m_obj->data.energy; }
const float& ConstCalorimeterHit::getEnergyError() const { return m_obj->data.energyError; }
const float& ConstCalorimeterHit::getTime() const { return m_obj->data.time; }
const edm4hep::Vector3f& ConstCalorimeterHit::getPosition() const { return m_obj->data.position; }
const int& ConstCalorimeterHit::getType() const { return m_obj->data.type; }






bool ConstCalorimeterHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstCalorimeterHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstCalorimeterHit::operator==(const CalorimeterHit& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

