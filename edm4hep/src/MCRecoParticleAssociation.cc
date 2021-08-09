// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/MCRecoParticleAssociation.h"
#include "edm4hep/MCRecoParticleAssociationConst.h"
#include "edm4hep/MCRecoParticleAssociationObj.h"
#include "edm4hep/MCRecoParticleAssociationData.h"
#include "edm4hep/MCRecoParticleAssociationCollection.h"

#include "edm4hep/MCParticle.h"
#include "edm4hep/ReconstructedParticle.h"

#include <ostream>

namespace edm4hep {


MCRecoParticleAssociation::MCRecoParticleAssociation() : m_obj(new MCRecoParticleAssociationObj()) {
  m_obj->acquire();
}

MCRecoParticleAssociation::MCRecoParticleAssociation(float weight) : m_obj(new MCRecoParticleAssociationObj()) {
  m_obj->acquire();
  m_obj->data.weight = weight;
}

MCRecoParticleAssociation::MCRecoParticleAssociation(const MCRecoParticleAssociation& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

MCRecoParticleAssociation& MCRecoParticleAssociation::operator=(const MCRecoParticleAssociation& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

MCRecoParticleAssociation::MCRecoParticleAssociation( MCRecoParticleAssociationObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

MCRecoParticleAssociation MCRecoParticleAssociation::clone() const {
  return {new MCRecoParticleAssociationObj(*m_obj)};
}

MCRecoParticleAssociation::~MCRecoParticleAssociation() {
  if (m_obj) m_obj->release();
}
MCRecoParticleAssociation::operator ConstMCRecoParticleAssociation() const { return ConstMCRecoParticleAssociation(m_obj); }

const float& MCRecoParticleAssociation::getWeight() const { return m_obj->data.weight; }

const ::edm4hep::ConstReconstructedParticle MCRecoParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return ::edm4hep::ConstReconstructedParticle(nullptr);
  }
  return ::edm4hep::ConstReconstructedParticle(*(m_obj->m_rec));
}

const ::edm4hep::ConstMCParticle MCRecoParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return ::edm4hep::ConstMCParticle(nullptr);
  }
  return ::edm4hep::ConstMCParticle(*(m_obj->m_sim));
}


void MCRecoParticleAssociation::setWeight(float value) { m_obj->data.weight = value; }

void MCRecoParticleAssociation::setRec(::edm4hep::ConstReconstructedParticle value) {
  if (m_obj->m_rec) delete m_obj->m_rec;
  m_obj->m_rec = new ::edm4hep::ConstReconstructedParticle(value);
}

void MCRecoParticleAssociation::setSim(::edm4hep::ConstMCParticle value) {
  if (m_obj->m_sim) delete m_obj->m_sim;
  m_obj->m_sim = new ::edm4hep::ConstMCParticle(value);
}







bool MCRecoParticleAssociation::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID MCRecoParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool MCRecoParticleAssociation::operator==(const ConstMCRecoParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstMCRecoParticleAssociation& value) {
  o << " id: " << value.id() << '\n';
  o << " weight : " << value.getWeight() << '\n';

  o << " rec : " << value.getRec().id() << '\n';
  o << " sim : " << value.getSim().id() << '\n';


  return o;
}

} // namespace edm4hep

