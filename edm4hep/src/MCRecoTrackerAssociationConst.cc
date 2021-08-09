// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoTrackerAssociation.h"
#include "edm4hep/MCRecoTrackerAssociationConst.h"
#include "edm4hep/MCRecoTrackerAssociationObj.h"
#include "edm4hep/MCRecoTrackerAssociationData.h"
#include "edm4hep/MCRecoTrackerAssociationCollection.h"

#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/TrackerHit.h"

#include <ostream>

namespace edm4hep {


ConstMCRecoTrackerAssociation::ConstMCRecoTrackerAssociation() : m_obj(new MCRecoTrackerAssociationObj()) {
  m_obj->acquire();
}

ConstMCRecoTrackerAssociation::ConstMCRecoTrackerAssociation(float weight) : m_obj(new MCRecoTrackerAssociationObj()) {
  m_obj->acquire();
  m_obj->data.weight = weight;
}

ConstMCRecoTrackerAssociation::ConstMCRecoTrackerAssociation(const ConstMCRecoTrackerAssociation& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstMCRecoTrackerAssociation& ConstMCRecoTrackerAssociation::operator=(const ConstMCRecoTrackerAssociation& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstMCRecoTrackerAssociation::ConstMCRecoTrackerAssociation( MCRecoTrackerAssociationObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstMCRecoTrackerAssociation ConstMCRecoTrackerAssociation::clone() const {
  return {new MCRecoTrackerAssociationObj(*m_obj)};
}

ConstMCRecoTrackerAssociation::~ConstMCRecoTrackerAssociation() {
  if (m_obj) m_obj->release();
}
const float& ConstMCRecoTrackerAssociation::getWeight() const { return m_obj->data.weight; }

const ::edm4hep::ConstTrackerHit ConstMCRecoTrackerAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return ::edm4hep::ConstTrackerHit(nullptr);
  }
  return ::edm4hep::ConstTrackerHit(*(m_obj->m_rec));
}

const ::edm4hep::ConstSimTrackerHit ConstMCRecoTrackerAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return ::edm4hep::ConstSimTrackerHit(nullptr);
  }
  return ::edm4hep::ConstSimTrackerHit(*(m_obj->m_sim));
}






bool ConstMCRecoTrackerAssociation::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstMCRecoTrackerAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstMCRecoTrackerAssociation::operator==(const MCRecoTrackerAssociation& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

