// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/SimTrackerHitConst.h"
#include "edm4hep/SimTrackerHitObj.h"
#include "edm4hep/SimTrackerHitData.h"
#include "edm4hep/SimTrackerHitCollection.h"

#include "edm4hep/MCParticle.h"

#include <ostream>

namespace edm4hep {


ConstSimTrackerHit::ConstSimTrackerHit() : m_obj(new SimTrackerHitObj()) {
  m_obj->acquire();
}

ConstSimTrackerHit::ConstSimTrackerHit(unsigned long long cellID, float EDep, float time, float pathLength, int quality, edm4hep::Vector3d position, edm4hep::Vector3f momentum) : m_obj(new SimTrackerHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.EDep = EDep;
  m_obj->data.time = time;
  m_obj->data.pathLength = pathLength;
  m_obj->data.quality = quality;
  m_obj->data.position = position;
  m_obj->data.momentum = momentum;
}

ConstSimTrackerHit::ConstSimTrackerHit(const ConstSimTrackerHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstSimTrackerHit& ConstSimTrackerHit::operator=(const ConstSimTrackerHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstSimTrackerHit::ConstSimTrackerHit( SimTrackerHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstSimTrackerHit ConstSimTrackerHit::clone() const {
  return {new SimTrackerHitObj(*m_obj)};
}

ConstSimTrackerHit::~ConstSimTrackerHit() {
  if (m_obj) m_obj->release();
}
const unsigned long long& ConstSimTrackerHit::getCellID() const { return m_obj->data.cellID; }
const float& ConstSimTrackerHit::getEDep() const { return m_obj->data.EDep; }
const float& ConstSimTrackerHit::getTime() const { return m_obj->data.time; }
const float& ConstSimTrackerHit::getPathLength() const { return m_obj->data.pathLength; }
const int& ConstSimTrackerHit::getQuality() const { return m_obj->data.quality; }
const edm4hep::Vector3d& ConstSimTrackerHit::getPosition() const { return m_obj->data.position; }
const edm4hep::Vector3f& ConstSimTrackerHit::getMomentum() const { return m_obj->data.momentum; }

const ::edm4hep::ConstMCParticle ConstSimTrackerHit::getMCParticle() const {
  if (!m_obj->m_MCParticle) {
    return ::edm4hep::ConstMCParticle(nullptr);
  }
  return ::edm4hep::ConstMCParticle(*(m_obj->m_MCParticle));
}






bool ConstSimTrackerHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstSimTrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstSimTrackerHit::operator==(const SimTrackerHit& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

