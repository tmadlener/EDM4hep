// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/SimpleTrackerHit.h"
#include "edm4hep/SimpleTrackerHitConst.h"
#include "edm4hep/SimpleTrackerHitObj.h"
#include "edm4hep/SimpleTrackerHitData.h"
#include "edm4hep/SimpleTrackerHitCollection.h"


#include <ostream>

namespace edm4hep {


SimpleTrackerHit::SimpleTrackerHit() : m_obj(new SimpleTrackerHitObj()) {
  m_obj->acquire();
}

SimpleTrackerHit::SimpleTrackerHit(edm4hep::Vector3d position) : m_obj(new SimpleTrackerHitObj()) {
  m_obj->acquire();
  m_obj->data.position = position;
}

SimpleTrackerHit::SimpleTrackerHit(const SimpleTrackerHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

SimpleTrackerHit& SimpleTrackerHit::operator=(const SimpleTrackerHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

SimpleTrackerHit::SimpleTrackerHit( SimpleTrackerHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

SimpleTrackerHit SimpleTrackerHit::clone() const {
  return {new SimpleTrackerHitObj(*m_obj)};
}

SimpleTrackerHit::~SimpleTrackerHit() {
  if (m_obj) m_obj->release();
}
SimpleTrackerHit::operator ConstSimpleTrackerHit() const { return ConstSimpleTrackerHit(m_obj); }

const edm4hep::Vector3d& SimpleTrackerHit::getPosition() const { return m_obj->data.position; }


void SimpleTrackerHit::setPosition(edm4hep::Vector3d value) { m_obj->data.position = value; }
edm4hep::Vector3d& SimpleTrackerHit::position() { return m_obj->data.position; }







bool SimpleTrackerHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID SimpleTrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool SimpleTrackerHit::operator==(const ConstSimpleTrackerHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstSimpleTrackerHit& value) {
  o << " id: " << value.id() << '\n';
  o << " position : " << value.getPosition() << '\n';



  return o;
}

} // namespace edm4hep

