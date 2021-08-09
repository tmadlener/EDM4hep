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


RecoParticleRef::RecoParticleRef() : m_obj(new RecoParticleRefObj()) {
  m_obj->acquire();
}


RecoParticleRef::RecoParticleRef(const RecoParticleRef& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

RecoParticleRef& RecoParticleRef::operator=(const RecoParticleRef& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

RecoParticleRef::RecoParticleRef( RecoParticleRefObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

RecoParticleRef RecoParticleRef::clone() const {
  return {new RecoParticleRefObj(*m_obj)};
}

RecoParticleRef::~RecoParticleRef() {
  if (m_obj) m_obj->release();
}
RecoParticleRef::operator ConstRecoParticleRef() const { return ConstRecoParticleRef(m_obj); }


const ::edm4hep::ConstReconstructedParticle RecoParticleRef::getParticle() const {
  if (!m_obj->m_particle) {
    return ::edm4hep::ConstReconstructedParticle(nullptr);
  }
  return ::edm4hep::ConstReconstructedParticle(*(m_obj->m_particle));
}



void RecoParticleRef::setParticle(::edm4hep::ConstReconstructedParticle value) {
  if (m_obj->m_particle) delete m_obj->m_particle;
  m_obj->m_particle = new ::edm4hep::ConstReconstructedParticle(value);
}







bool RecoParticleRef::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID RecoParticleRef::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool RecoParticleRef::operator==(const ConstRecoParticleRef& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstRecoParticleRef& value) {
  o << " id: " << value.id() << '\n';

  o << " particle : " << value.getParticle().id() << '\n';


  return o;
}

} // namespace edm4hep

