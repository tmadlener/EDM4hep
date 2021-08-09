// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCRecoCaloAssociationObj.h"
#include "edm4hep/CalorimeterHitConst.h"
#include "edm4hep/SimCalorimeterHitConst.h"
namespace edm4hep {

MCRecoCaloAssociationObj::MCRecoCaloAssociationObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_rec(nullptr),
  m_sim(nullptr)
{  }

MCRecoCaloAssociationObj::MCRecoCaloAssociationObj(const podio::ObjectID id_, MCRecoCaloAssociationData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

MCRecoCaloAssociationObj::MCRecoCaloAssociationObj(const MCRecoCaloAssociationObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_rec(nullptr),
  m_sim(nullptr)
{
  if (other.m_rec) {
    m_rec = new ::edm4hep::ConstCalorimeterHit(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new ::edm4hep::ConstSimCalorimeterHit(*(other.m_sim));
  }
}

MCRecoCaloAssociationObj::~MCRecoCaloAssociationObj() {

  if (m_rec) delete m_rec;
  if (m_sim) delete m_sim;
}
} // namespace edm4hep

