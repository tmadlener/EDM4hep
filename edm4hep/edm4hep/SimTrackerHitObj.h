// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimTrackerHitOBJ_H
#define EDM4HEP_SimTrackerHitOBJ_H

// data model specific includes
#include "edm4hep/SimTrackerHitData.h"

#include "podio/ObjBase.h"

// forward declarations
namespace edm4hep {
class ConstMCParticle;
}


namespace edm4hep {

class SimTrackerHit;
class ConstSimTrackerHit;

class SimTrackerHitObj : public podio::ObjBase {
public:
  /// constructor
  SimTrackerHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  SimTrackerHitObj(const SimTrackerHitObj&);
  /// constructor from ObjectID and SimTrackerHitData
  /// does not initialize the internal relation containers
  SimTrackerHitObj(const podio::ObjectID id, SimTrackerHitData data);
  /// No assignment operator
  SimTrackerHitObj& operator=(const SimTrackerHitObj&) = delete;
  virtual ~SimTrackerHitObj();

public:
  SimTrackerHitData data;
  ::edm4hep::ConstMCParticle* m_MCParticle{nullptr};
};

} // namespace edm4hep


#endif
