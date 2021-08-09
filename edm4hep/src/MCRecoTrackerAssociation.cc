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


MCRecoTrackerAssociation::MCRecoTrackerAssociation() : m_obj(new MCRecoTrackerAssociationObj()) {
  m_obj->acquire();
}

MCRecoTrackerAssociation::MCRecoTrackerAssociation(float weight) : m_obj(new MCRecoTrackerAssociationObj()) {
  m_obj->acquire();
  m_obj->data.weight = weight;
}

MCRecoTrackerAssociation::MCRecoTrackerAssociation(const MCRecoTrackerAssociation& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

MCRecoTrackerAssociation& MCRecoTrackerAssociation::operator=(const MCRecoTrackerAssociation& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

MCRecoTrackerAssociation::MCRecoTrackerAssociation( MCRecoTrackerAssociationObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

MCRecoTrackerAssociation MCRecoTrackerAssociation::clone() const {
  return {new MCRecoTrackerAssociationObj(*m_obj)};
}

MCRecoTrackerAssociation::~MCRecoTrackerAssociation() {
  if (m_obj) m_obj->release();
}
MCRecoTrackerAssociation::operator ConstMCRecoTrackerAssociation() const { return ConstMCRecoTrackerAssociation(m_obj); }

const float& MCRecoTrackerAssociation::getWeight() const { return m_obj->data.weight; }

const ::edm4hep::ConstTrackerHit MCRecoTrackerAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return ::edm4hep::ConstTrackerHit(nullptr);
  }
  return ::edm4hep::ConstTrackerHit(*(m_obj->m_rec));
}

const ::edm4hep::ConstSimTrackerHit MCRecoTrackerAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return ::edm4hep::ConstSimTrackerHit(nullptr);
  }
  return ::edm4hep::ConstSimTrackerHit(*(m_obj->m_sim));
}


void MCRecoTrackerAssociation::setWeight(float value) { m_obj->data.weight = value; }

void MCRecoTrackerAssociation::setRec(::edm4hep::ConstTrackerHit value) {
  if (m_obj->m_rec) delete m_obj->m_rec;
  m_obj->m_rec = new ::edm4hep::ConstTrackerHit(value);
}

void MCRecoTrackerAssociation::setSim(::edm4hep::ConstSimTrackerHit value) {
  if (m_obj->m_sim) delete m_obj->m_sim;
  m_obj->m_sim = new ::edm4hep::ConstSimTrackerHit(value);
}







bool MCRecoTrackerAssociation::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID MCRecoTrackerAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool MCRecoTrackerAssociation::operator==(const ConstMCRecoTrackerAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstMCRecoTrackerAssociation& value) {
  o << " id: " << value.id() << '\n';
  o << " weight : " << value.getWeight() << '\n';

  o << " rec : " << value.getRec().id() << '\n';
  o << " sim : " << value.getSim().id() << '\n';


  return o;
}

} // namespace edm4hep

