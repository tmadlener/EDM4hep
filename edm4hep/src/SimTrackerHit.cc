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


SimTrackerHit::SimTrackerHit() : m_obj(new SimTrackerHitObj()) {
  m_obj->acquire();
}

SimTrackerHit::SimTrackerHit(unsigned long long cellID, float EDep, float time, float pathLength, int quality, edm4hep::Vector3d position, edm4hep::Vector3f momentum) : m_obj(new SimTrackerHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.EDep = EDep;
  m_obj->data.time = time;
  m_obj->data.pathLength = pathLength;
  m_obj->data.quality = quality;
  m_obj->data.position = position;
  m_obj->data.momentum = momentum;
}

SimTrackerHit::SimTrackerHit(const SimTrackerHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

SimTrackerHit& SimTrackerHit::operator=(const SimTrackerHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

SimTrackerHit::SimTrackerHit( SimTrackerHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

SimTrackerHit SimTrackerHit::clone() const {
  return {new SimTrackerHitObj(*m_obj)};
}

SimTrackerHit::~SimTrackerHit() {
  if (m_obj) m_obj->release();
}
SimTrackerHit::operator ConstSimTrackerHit() const { return ConstSimTrackerHit(m_obj); }

const unsigned long long& SimTrackerHit::getCellID() const { return m_obj->data.cellID; }
const float& SimTrackerHit::getEDep() const { return m_obj->data.EDep; }
const float& SimTrackerHit::getTime() const { return m_obj->data.time; }
const float& SimTrackerHit::getPathLength() const { return m_obj->data.pathLength; }
const int& SimTrackerHit::getQuality() const { return m_obj->data.quality; }
const edm4hep::Vector3d& SimTrackerHit::getPosition() const { return m_obj->data.position; }
const edm4hep::Vector3f& SimTrackerHit::getMomentum() const { return m_obj->data.momentum; }

const ::edm4hep::ConstMCParticle SimTrackerHit::getMCParticle() const {
  if (!m_obj->m_MCParticle) {
    return ::edm4hep::ConstMCParticle(nullptr);
  }
  return ::edm4hep::ConstMCParticle(*(m_obj->m_MCParticle));
}


void SimTrackerHit::setCellID(unsigned long long value) { m_obj->data.cellID = value; }
void SimTrackerHit::setEDep(float value) { m_obj->data.EDep = value; }
void SimTrackerHit::setTime(float value) { m_obj->data.time = value; }
void SimTrackerHit::setPathLength(float value) { m_obj->data.pathLength = value; }
void SimTrackerHit::setQuality(int value) { m_obj->data.quality = value; }
void SimTrackerHit::setPosition(edm4hep::Vector3d value) { m_obj->data.position = value; }
edm4hep::Vector3d& SimTrackerHit::position() { return m_obj->data.position; }
void SimTrackerHit::setMomentum(edm4hep::Vector3f value) { m_obj->data.momentum = value; }
edm4hep::Vector3f& SimTrackerHit::momentum() { return m_obj->data.momentum; }

void SimTrackerHit::setMCParticle(::edm4hep::ConstMCParticle value) {
  if (m_obj->m_MCParticle) delete m_obj->m_MCParticle;
  m_obj->m_MCParticle = new ::edm4hep::ConstMCParticle(value);
}







bool SimTrackerHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID SimTrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool SimTrackerHit::operator==(const ConstSimTrackerHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstSimTrackerHit& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " EDep : " << value.getEDep() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " pathLength : " << value.getPathLength() << '\n';
  o << " quality : " << value.getQuality() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " momentum : " << value.getMomentum() << '\n';

  o << " MCParticle : " << value.getMCParticle().id() << '\n';


  return o;
}

} // namespace edm4hep

