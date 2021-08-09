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


ConstCaloHitContribution::ConstCaloHitContribution() : m_obj(new CaloHitContributionObj()) {
  m_obj->acquire();
}

ConstCaloHitContribution::ConstCaloHitContribution(int PDG, float energy, float time, edm4hep::Vector3f stepPosition) : m_obj(new CaloHitContributionObj()) {
  m_obj->acquire();
  m_obj->data.PDG = PDG;
  m_obj->data.energy = energy;
  m_obj->data.time = time;
  m_obj->data.stepPosition = stepPosition;
}

ConstCaloHitContribution::ConstCaloHitContribution(const ConstCaloHitContribution& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstCaloHitContribution& ConstCaloHitContribution::operator=(const ConstCaloHitContribution& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstCaloHitContribution::ConstCaloHitContribution( CaloHitContributionObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstCaloHitContribution ConstCaloHitContribution::clone() const {
  return {new CaloHitContributionObj(*m_obj)};
}

ConstCaloHitContribution::~ConstCaloHitContribution() {
  if (m_obj) m_obj->release();
}
const int& ConstCaloHitContribution::getPDG() const { return m_obj->data.PDG; }
const float& ConstCaloHitContribution::getEnergy() const { return m_obj->data.energy; }
const float& ConstCaloHitContribution::getTime() const { return m_obj->data.time; }
const edm4hep::Vector3f& ConstCaloHitContribution::getStepPosition() const { return m_obj->data.stepPosition; }

const ::edm4hep::ConstMCParticle ConstCaloHitContribution::getParticle() const {
  if (!m_obj->m_particle) {
    return ::edm4hep::ConstMCParticle(nullptr);
  }
  return ::edm4hep::ConstMCParticle(*(m_obj->m_particle));
}






bool ConstCaloHitContribution::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstCaloHitContribution::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstCaloHitContribution::operator==(const CaloHitContribution& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

