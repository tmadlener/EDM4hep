// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/CaloHitContribution.h"
#include "edm4hep/CaloHitContributionConst.h"
#include "edm4hep/CaloHitContributionObj.h"
#include "edm4hep/CaloHitContributionData.h"
#include "edm4hep/CaloHitContributionCollection.h"

#include "edm4hep/MCParticle.h"

#include <ostream>

namespace edm4hep {


CaloHitContribution::CaloHitContribution() : m_obj(new CaloHitContributionObj()) {
  m_obj->acquire();
}

CaloHitContribution::CaloHitContribution(int PDG, float energy, float time, edm4hep::Vector3f stepPosition) : m_obj(new CaloHitContributionObj()) {
  m_obj->acquire();
  m_obj->data.PDG = PDG;
  m_obj->data.energy = energy;
  m_obj->data.time = time;
  m_obj->data.stepPosition = stepPosition;
}

CaloHitContribution::CaloHitContribution(const CaloHitContribution& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

CaloHitContribution& CaloHitContribution::operator=(const CaloHitContribution& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

CaloHitContribution::CaloHitContribution( CaloHitContributionObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

CaloHitContribution CaloHitContribution::clone() const {
  return {new CaloHitContributionObj(*m_obj)};
}

CaloHitContribution::~CaloHitContribution() {
  if (m_obj) m_obj->release();
}
CaloHitContribution::operator ConstCaloHitContribution() const { return ConstCaloHitContribution(m_obj); }

const int& CaloHitContribution::getPDG() const { return m_obj->data.PDG; }
const float& CaloHitContribution::getEnergy() const { return m_obj->data.energy; }
const float& CaloHitContribution::getTime() const { return m_obj->data.time; }
const edm4hep::Vector3f& CaloHitContribution::getStepPosition() const { return m_obj->data.stepPosition; }

const ::edm4hep::ConstMCParticle CaloHitContribution::getParticle() const {
  if (!m_obj->m_particle) {
    return ::edm4hep::ConstMCParticle(nullptr);
  }
  return ::edm4hep::ConstMCParticle(*(m_obj->m_particle));
}


void CaloHitContribution::setPDG(int value) { m_obj->data.PDG = value; }
void CaloHitContribution::setEnergy(float value) { m_obj->data.energy = value; }
void CaloHitContribution::setTime(float value) { m_obj->data.time = value; }
void CaloHitContribution::setStepPosition(edm4hep::Vector3f value) { m_obj->data.stepPosition = value; }
edm4hep::Vector3f& CaloHitContribution::stepPosition() { return m_obj->data.stepPosition; }

void CaloHitContribution::setParticle(::edm4hep::ConstMCParticle value) {
  if (m_obj->m_particle) delete m_obj->m_particle;
  m_obj->m_particle = new ::edm4hep::ConstMCParticle(value);
}







bool CaloHitContribution::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID CaloHitContribution::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool CaloHitContribution::operator==(const ConstCaloHitContribution& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstCaloHitContribution& value) {
  o << " id: " << value.id() << '\n';
  o << " PDG : " << value.getPDG() << '\n';
  o << " energy : " << value.getEnergy() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " stepPosition : " << value.getStepPosition() << '\n';

  o << " particle : " << value.getParticle().id() << '\n';


  return o;
}

} // namespace edm4hep

