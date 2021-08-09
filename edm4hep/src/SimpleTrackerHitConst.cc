// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/SimpleTrackerHit.h"
#include "edm4hep/SimpleTrackerHitConst.h"
#include "edm4hep/SimpleTrackerHitObj.h"
#include "edm4hep/SimpleTrackerHitData.h"
#include "edm4hep/SimpleTrackerHitCollection.h"


#include <ostream>

namespace edm4hep {


ConstSimpleTrackerHit::ConstSimpleTrackerHit() : m_obj(new SimpleTrackerHitObj()) {
  m_obj->acquire();
}

ConstSimpleTrackerHit::ConstSimpleTrackerHit(edm4hep::Vector3d position) : m_obj(new SimpleTrackerHitObj()) {
  m_obj->acquire();
  m_obj->data.position = position;
}

ConstSimpleTrackerHit::ConstSimpleTrackerHit(const ConstSimpleTrackerHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstSimpleTrackerHit& ConstSimpleTrackerHit::operator=(const ConstSimpleTrackerHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstSimpleTrackerHit::ConstSimpleTrackerHit( SimpleTrackerHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstSimpleTrackerHit ConstSimpleTrackerHit::clone() const {
  return {new SimpleTrackerHitObj(*m_obj)};
}

ConstSimpleTrackerHit::~ConstSimpleTrackerHit() {
  if (m_obj) m_obj->release();
}
const edm4hep::Vector3d& ConstSimpleTrackerHit::getPosition() const { return m_obj->data.position; }






bool ConstSimpleTrackerHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstSimpleTrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstSimpleTrackerHit::operator==(const SimpleTrackerHit& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

