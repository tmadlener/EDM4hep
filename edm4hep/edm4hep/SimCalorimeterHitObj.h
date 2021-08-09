// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimCalorimeterHitOBJ_H
#define EDM4HEP_SimCalorimeterHitOBJ_H

// data model specific includes
#include "edm4hep/SimCalorimeterHitData.h"
#include "edm4hep/CaloHitContribution.h"
#include "podio/RelationRange.h"
#include <vector>

#include "podio/ObjBase.h"
#include <vector>


namespace edm4hep {

class SimCalorimeterHit;
class ConstSimCalorimeterHit;

class SimCalorimeterHitObj : public podio::ObjBase {
public:
  /// constructor
  SimCalorimeterHitObj();
  /// copy constructor (does a deep-copy of relation containers)
  SimCalorimeterHitObj(const SimCalorimeterHitObj&);
  /// constructor from ObjectID and SimCalorimeterHitData
  /// does not initialize the internal relation containers
  SimCalorimeterHitObj(const podio::ObjectID id, SimCalorimeterHitData data);
  /// No assignment operator
  SimCalorimeterHitObj& operator=(const SimCalorimeterHitObj&) = delete;
  virtual ~SimCalorimeterHitObj();

public:
  SimCalorimeterHitData data;
  std::vector<::edm4hep::ConstCaloHitContribution>* m_contributions{nullptr};
};

} // namespace edm4hep


#endif
