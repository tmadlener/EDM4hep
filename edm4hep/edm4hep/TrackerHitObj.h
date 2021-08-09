// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHitOBJ_H
#define EDM4HEP_TrackerHitOBJ_H

// data model specific includes
#include "edm4hep/TrackerHitData.h"
#include "edm4hep/ObjectID.h"
#include "podio/RelationRange.h"
#include <vector>

#include "podio/ObjBase.h"
#include <vector>


namespace edm4hep {

class TrackerHit;
class ConstTrackerHit;

class TrackerHitObj : public podio::ObjBase {
public:
  /// constructor
  TrackerHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  TrackerHitObj(const TrackerHitObj&);
  /// constructor from ObjectID and TrackerHitData
  /// does not initialize the internal relation containers
  TrackerHitObj(const podio::ObjectID id, TrackerHitData data);
  /// No assignment operator
  TrackerHitObj& operator=(const TrackerHitObj&) = delete;
  virtual ~TrackerHitObj();

public:
  TrackerHitData data;
  std::vector<edm4hep::ObjectID>* m_rawHits{nullptr};
};

} // namespace edm4hep


#endif
