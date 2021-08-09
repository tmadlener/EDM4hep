// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoCaloAssociation.h"
#include "edm4hep/MCRecoCaloAssociationConst.h"
#include "edm4hep/MCRecoCaloAssociationObj.h"
#include "edm4hep/MCRecoCaloAssociationData.h"
#include "edm4hep/MCRecoCaloAssociationCollection.h"

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/SimCalorimeterHit.h"

#include <ostream>

namespace edm4hep {


ConstMCRecoCaloAssociation::ConstMCRecoCaloAssociation() : m_obj(new MCRecoCaloAssociationObj()) {
  m_obj->acquire();
}

ConstMCRecoCaloAssociation::ConstMCRecoCaloAssociation(float weight) : m_obj(new MCRecoCaloAssociationObj()) {
  m_obj->acquire();
  m_obj->data.weight = weight;
}

ConstMCRecoCaloAssociation::ConstMCRecoCaloAssociation(const ConstMCRecoCaloAssociation& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstMCRecoCaloAssociation& ConstMCRecoCaloAssociation::operator=(const ConstMCRecoCaloAssociation& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstMCRecoCaloAssociation::ConstMCRecoCaloAssociation( MCRecoCaloAssociationObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstMCRecoCaloAssociation ConstMCRecoCaloAssociation::clone() const {
  return {new MCRecoCaloAssociationObj(*m_obj)};
}

ConstMCRecoCaloAssociation::~ConstMCRecoCaloAssociation() {
  if (m_obj) m_obj->release();
}
const float& ConstMCRecoCaloAssociation::getWeight() const { return m_obj->data.weight; }

const ::edm4hep::ConstCalorimeterHit ConstMCRecoCaloAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return ::edm4hep::ConstCalorimeterHit(nullptr);
  }
  return ::edm4hep::ConstCalorimeterHit(*(m_obj->m_rec));
}

const ::edm4hep::ConstSimCalorimeterHit ConstMCRecoCaloAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return ::edm4hep::ConstSimCalorimeterHit(nullptr);
  }
  return ::edm4hep::ConstSimCalorimeterHit(*(m_obj->m_sim));
}






bool ConstMCRecoCaloAssociation::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstMCRecoCaloAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstMCRecoCaloAssociation::operator==(const MCRecoCaloAssociation& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

