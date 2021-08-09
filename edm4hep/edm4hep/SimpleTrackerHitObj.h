// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimpleTrackerHitOBJ_H
#define EDM4HEP_SimpleTrackerHitOBJ_H

// data model specific includes
#include "edm4hep/SimpleTrackerHitData.h"

#include "podio/ObjBase.h"



namespace edm4hep {

class SimpleTrackerHit;
class ConstSimpleTrackerHit;

class SimpleTrackerHitObj : public podio::ObjBase {
public:
  /// constructor
  SimpleTrackerHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  SimpleTrackerHitObj(const SimpleTrackerHitObj&);
  /// constructor from ObjectID and SimpleTrackerHitData
  /// does not initialize the internal relation containers
  SimpleTrackerHitObj(const podio::ObjectID id, SimpleTrackerHitData data);
  /// No assignment operator
  SimpleTrackerHitObj& operator=(const SimpleTrackerHitObj&) = delete;
  virtual ~SimpleTrackerHitObj();

public:
  SimpleTrackerHitData data;
};

} // namespace edm4hep


#endif
