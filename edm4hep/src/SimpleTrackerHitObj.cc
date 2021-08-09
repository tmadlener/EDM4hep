// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/SimpleTrackerHitObj.h"
namespace edm4hep {

SimpleTrackerHitObj::SimpleTrackerHitObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data()
{  }

SimpleTrackerHitObj::SimpleTrackerHitObj(const podio::ObjectID id_, SimpleTrackerHitData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

SimpleTrackerHitObj::SimpleTrackerHitObj(const SimpleTrackerHitObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data)
{
}

SimpleTrackerHitObj::~SimpleTrackerHitObj() {

}
} // namespace edm4hep

