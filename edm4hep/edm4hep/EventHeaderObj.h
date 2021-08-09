// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_EventHeaderOBJ_H
#define EDM4HEP_EventHeaderOBJ_H

// data model specific includes
#include "edm4hep/EventHeaderData.h"

#include "podio/ObjBase.h"



namespace edm4hep {

class EventHeader;
class ConstEventHeader;

class EventHeaderObj : public podio::ObjBase {
public:
  /// constructor
  EventHeaderObj();
  /// copy constructor (does a deep-copy of relation containers)
  EventHeaderObj(const EventHeaderObj&);
  /// constructor from ObjectID and EventHeaderData
  /// does not initialize the internal relation containers
  EventHeaderObj(const podio::ObjectID id, EventHeaderData data);
  /// No assignment operator
  EventHeaderObj& operator=(const EventHeaderObj&) = delete;
  virtual ~EventHeaderObj();

public:
  EventHeaderData data;
};

} // namespace edm4hep


#endif
