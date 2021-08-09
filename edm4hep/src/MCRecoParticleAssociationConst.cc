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


ConstMCRecoParticleAssociation::ConstMCRecoParticleAssociation() : m_obj(new MCRecoParticleAssociationObj()) {
  m_obj->acquire();
}

ConstMCRecoParticleAssociation::ConstMCRecoParticleAssociation(float weight) : m_obj(new MCRecoParticleAssociationObj()) {
  m_obj->acquire();
  m_obj->data.weight = weight;
}

ConstMCRecoParticleAssociation::ConstMCRecoParticleAssociation(const ConstMCRecoParticleAssociation& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstMCRecoParticleAssociation& ConstMCRecoParticleAssociation::operator=(const ConstMCRecoParticleAssociation& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstMCRecoParticleAssociation::ConstMCRecoParticleAssociation( MCRecoParticleAssociationObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstMCRecoParticleAssociation ConstMCRecoParticleAssociation::clone() const {
  return {new MCRecoParticleAssociationObj(*m_obj)};
}

ConstMCRecoParticleAssociation::~ConstMCRecoParticleAssociation() {
  if (m_obj) m_obj->release();
}
const float& ConstMCRecoParticleAssociation::getWeight() const { return m_obj->data.weight; }

const ::edm4hep::ConstReconstructedParticle ConstMCRecoParticleAssociation::getRec() const {
  if (!m_obj->m_rec) {
    return ::edm4hep::ConstReconstructedParticle(nullptr);
  }
  return ::edm4hep::ConstReconstructedParticle(*(m_obj->m_rec));
}

const ::edm4hep::ConstMCParticle ConstMCRecoParticleAssociation::getSim() const {
  if (!m_obj->m_sim) {
    return ::edm4hep::ConstMCParticle(nullptr);
  }
  return ::edm4hep::ConstMCParticle(*(m_obj->m_sim));
}






bool ConstMCRecoParticleAssociation::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstMCRecoParticleAssociation::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstMCRecoParticleAssociation::operator==(const MCRecoParticleAssociation& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

