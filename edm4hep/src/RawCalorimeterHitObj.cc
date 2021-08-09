// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RawCalorimeterHitObj.h"
namespace edm4hep {

RawCalorimeterHitObj::RawCalorimeterHitObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data()
{  }

RawCalorimeterHitObj::RawCalorimeterHitObj(const podio::ObjectID id_, RawCalorimeterHitData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

RawCalorimeterHitObj::RawCalorimeterHitObj(const RawCalorimeterHitObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data)
{
}

RawCalorimeterHitObj::~RawCalorimeterHitObj() {

}
} // namespace edm4hep

