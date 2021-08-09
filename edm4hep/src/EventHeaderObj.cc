// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/EventHeaderObj.h"
namespace edm4hep {

EventHeaderObj::EventHeaderObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data()
{  }

EventHeaderObj::EventHeaderObj(const podio::ObjectID id_, EventHeaderData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

EventHeaderObj::EventHeaderObj(const EventHeaderObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data)
{
}

EventHeaderObj::~EventHeaderObj() {

}
} // namespace edm4hep

