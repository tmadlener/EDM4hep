// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackerHitObj.h"
namespace edm4hep {

TrackerHitObj::TrackerHitObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_rawHits(new std::vector<edm4hep::ObjectID>())
{  }

TrackerHitObj::TrackerHitObj(const podio::ObjectID id_, TrackerHitData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

TrackerHitObj::TrackerHitObj(const TrackerHitObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_rawHits(new std::vector<edm4hep::ObjectID>(*(other.m_rawHits)))
{
}

TrackerHitObj::~TrackerHitObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_rawHits;
  }

}
} // namespace edm4hep

