// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ClusterOBJ_H
#define EDM4HEP_ClusterOBJ_H

// data model specific includes
#include "edm4hep/ClusterData.h"
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/ParticleID.h"
#include "podio/RelationRange.h"
#include <vector>

#include "podio/ObjBase.h"
#include <vector>


namespace edm4hep {

class Cluster;
class ConstCluster;

class ClusterObj : public podio::ObjBase {
public:
  /// constructor
  ClusterObj();
  /// copy constructor (does a deep-copy of relation containers)
  ClusterObj(const ClusterObj&);
  /// constructor from ObjectID and ClusterData
  /// does not initialize the internal relation containers
  ClusterObj(const podio::ObjectID id, ClusterData data);
  /// No assignment operator
  ClusterObj& operator=(const ClusterObj&) = delete;
  virtual ~ClusterObj();

public:
  ClusterData data;
  std::vector<::edm4hep::ConstCluster>* m_clusters{nullptr};
  std::vector<::edm4hep::ConstCalorimeterHit>* m_hits{nullptr};
  std::vector<::edm4hep::ConstParticleID>* m_particleIDs{nullptr};
  std::vector<float>* m_shapeParameters{nullptr};
  std::vector<float>* m_hitContributions{nullptr};
  std::vector<float>* m_subdetectorEnergies{nullptr};
};

} // namespace edm4hep


#endif
