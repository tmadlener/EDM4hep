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


MCRecoCaloAssociation::MCRecoCaloAssociation() : m_obj(new MCRecoCaloAssociationObj()) {
  m_obj->acquire();
}

MCRecoCaloAssociation::MCRecoCaloAssociation(float weight) : m_obj(new MCRecoCaloAssociationObj()) {
  m_obj->acquire();
  m_obj->data.weight = weight;
}

MCRecoCaloAssociation::MCRecoCaloAssociation(const MCRecoCaloAssociation& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

MCRecoCaloAssociation& MCRecoCaloAssociation::operator=(const MCRecoCaloAssociation& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

MCRecoCaloAssociation::MCRecoCaloAssociation( MCRecoCaloAssociationObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

MCRecoCaloAssociation MCRecoCaloAssociation::clone() const {
  return {new MCRecoCaloAssociationObj(*m_obj)};
}

MCRecoCaloAssociation::~MCRecoCaloAssociation() {
  if (m_obj) m_obj->release();
}
MCRecoCaloAssociation::operator ConstMCRecoCaloAssociation() const { return ConstMCRecoCaloAssociation(m_obj); }

const float& MCRecoCaloAssociation::getWeight() const { return m_obj->data.weight; }

const ::edm4hep::ConstCalorimeterHit MCRecoCaloAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return ::edm4hep::ConstCalorimeterHit(nullptr);
  }
  return ::edm4hep::ConstCalorimeterHit(*(m_obj->m_rec));
}

const ::edm4hep::ConstSimCalorimeterHit MCRecoCaloAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return ::edm4hep::ConstSimCalorimeterHit(nullptr);
  }
  return ::edm4hep::ConstSimCalorimeterHit(*(m_obj->m_sim));
}


void MCRecoCaloAssociation::setWeight(float value) { m_obj->data.weight = value; }

void MCRecoCaloAssociation::setRec(::edm4hep::ConstCalorimeterHit value) {
  if (m_obj->m_rec) delete m_obj->m_rec;
  m_obj->m_rec = new ::edm4hep::ConstCalorimeterHit(value);
}

void MCRecoCaloAssociation::setSim(::edm4hep::ConstSimCalorimeterHit value) {
  if (m_obj->m_sim) delete m_obj->m_sim;
  m_obj->m_sim = new ::edm4hep::ConstSimCalorimeterHit(value);
}







bool MCRecoCaloAssociation::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID MCRecoCaloAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool MCRecoCaloAssociation::operator==(const ConstMCRecoCaloAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstMCRecoCaloAssociation& value) {
  o << " id: " << value.id() << '\n';
  o << " weight : " << value.getWeight() << '\n';

  o << " rec : " << value.getRec().id() << '\n';
  o << " sim : " << value.getSim().id() << '\n';


  return o;
}

} // namespace edm4hep

