// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CaloHitContributionOBJ_H
#define EDM4HEP_CaloHitContributionOBJ_H

// data model specific includes
#include "edm4hep/CaloHitContributionData.h"

#include "podio/ObjBase.h"

// forward declarations
namespace edm4hep {
class ConstMCParticle;
}


namespace edm4hep {

class CaloHitContribution;
class ConstCaloHitContribution;

class CaloHitContributionObj : public podio::ObjBase {
public:
  /// constructor
  CaloHitContributionObj();
  /// copy constructor (does a deep-copy of relation containers)
  CaloHitContributionObj(const CaloHitContributionObj&);
  /// constructor from ObjectID and CaloHitContributionData
  /// does not initialize the internal relation containers
  CaloHitContributionObj(const podio::ObjectID id, CaloHitContributionData data);
  /// No assignment operator
  CaloHitContributionObj& operator=(const CaloHitContributionObj&) = delete;
  virtual ~CaloHitContributionObj();

public:
  CaloHitContributionData data;
  ::edm4hep::ConstMCParticle* m_particle{nullptr};
};

} // namespace edm4hep


#endif
