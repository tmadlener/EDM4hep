// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/SimCalorimeterHitObj.h"
namespace edm4hep {

SimCalorimeterHitObj::SimCalorimeterHitObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_contributions(new std::vector<::edm4hep::ConstCaloHitContribution>())
{  }

SimCalorimeterHitObj::SimCalorimeterHitObj(const podio::ObjectID id_, SimCalorimeterHitData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

SimCalorimeterHitObj::SimCalorimeterHitObj(const SimCalorimeterHitObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_contributions(new std::vector<::edm4hep::ConstCaloHitContribution>(*(other.m_contributions)))
{
}

SimCalorimeterHitObj::~SimCalorimeterHitObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_contributions;
  }

}
} // namespace edm4hep

