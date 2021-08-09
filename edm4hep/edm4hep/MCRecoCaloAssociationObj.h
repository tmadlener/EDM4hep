// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoCaloAssociationOBJ_H
#define EDM4HEP_MCRecoCaloAssociationOBJ_H

// data model specific includes
#include "edm4hep/MCRecoCaloAssociationData.h"

#include "podio/ObjBase.h"

// forward declarations
namespace edm4hep {
class ConstCalorimeterHit;
class ConstSimCalorimeterHit;
}


namespace edm4hep {

class MCRecoCaloAssociation;
class ConstMCRecoCaloAssociation;

class MCRecoCaloAssociationObj : public podio::ObjBase {
public:
  /// constructor
  MCRecoCaloAssociationObj();
  /// copy constructor (does a deep-copy of relation containers)
  MCRecoCaloAssociationObj(const MCRecoCaloAssociationObj&);
  /// constructor from ObjectID and MCRecoCaloAssociationData
  /// does not initialize the internal relation containers
  MCRecoCaloAssociationObj(const podio::ObjectID id, MCRecoCaloAssociationData data);
  /// No assignment operator
  MCRecoCaloAssociationObj& operator=(const MCRecoCaloAssociationObj&) = delete;
  virtual ~MCRecoCaloAssociationObj();

public:
  MCRecoCaloAssociationData data;
  ::edm4hep::ConstCalorimeterHit* m_rec{nullptr};
  ::edm4hep::ConstSimCalorimeterHit* m_sim{nullptr};
};

} // namespace edm4hep


#endif
