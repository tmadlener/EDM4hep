// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCRecoTrackerAssociationObj.h"
#include "edm4hep/SimTrackerHitConst.h"
#include "edm4hep/TrackerHitConst.h"
namespace edm4hep {

MCRecoTrackerAssociationObj::MCRecoTrackerAssociationObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_rec(nullptr),
  m_sim(nullptr)
{  }

MCRecoTrackerAssociationObj::MCRecoTrackerAssociationObj(const podio::ObjectID id_, MCRecoTrackerAssociationData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

MCRecoTrackerAssociationObj::MCRecoTrackerAssociationObj(const MCRecoTrackerAssociationObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_rec(nullptr),
  m_sim(nullptr)
{
  if (other.m_rec) {
    m_rec = new ::edm4hep::ConstTrackerHit(*(other.m_rec));
  }
  if (other.m_sim) {
    m_sim = new ::edm4hep::ConstSimTrackerHit(*(other.m_sim));
  }
}

MCRecoTrackerAssociationObj::~MCRecoTrackerAssociationObj() {

  if (m_rec) delete m_rec;
  if (m_sim) delete m_sim;
}
} // namespace edm4hep

