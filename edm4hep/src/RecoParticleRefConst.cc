// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/RecoParticleRef.h"
#include "edm4hep/RecoParticleRefConst.h"
#include "edm4hep/RecoParticleRefObj.h"
#include "edm4hep/RecoParticleRefData.h"
#include "edm4hep/RecoParticleRefCollection.h"

#include "edm4hep/ReconstructedParticle.h"

#include <ostream>

namespace edm4hep {


ConstRecoParticleRef::ConstRecoParticleRef() : m_obj(new RecoParticleRefObj()) {
  m_obj->acquire();
}


ConstRecoParticleRef::ConstRecoParticleRef(const ConstRecoParticleRef& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstRecoParticleRef& ConstRecoParticleRef::operator=(const ConstRecoParticleRef& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstRecoParticleRef::ConstRecoParticleRef( RecoParticleRefObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstRecoParticleRef ConstRecoParticleRef::clone() const {
  return {new RecoParticleRefObj(*m_obj)};
}

ConstRecoParticleRef::~ConstRecoParticleRef() {
  if (m_obj) m_obj->release();
}

const ::edm4hep::ConstReconstructedParticle ConstRecoParticleRef::getParticle() const {
  if (!m_obj->m_particle) {
    return ::edm4hep::ConstReconstructedParticle(nullptr);
  }
  return ::edm4hep::ConstReconstructedParticle(*(m_obj->m_particle));
}






bool ConstRecoParticleRef::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstRecoParticleRef::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstRecoParticleRef::operator==(const RecoParticleRef& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

