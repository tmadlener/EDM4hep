// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ReconstructedParticleOBJ_H
#define EDM4HEP_ReconstructedParticleOBJ_H

// data model specific includes
#include "edm4hep/ReconstructedParticleData.h"
#include "edm4hep/Cluster.h"
#include "edm4hep/ParticleID.h"
#include "edm4hep/Track.h"
#include "podio/RelationRange.h"
#include <vector>

#include "podio/ObjBase.h"
#include <vector>
// forward declarations
namespace edm4hep {
class ConstVertex;
class ConstParticleID;
}


namespace edm4hep {

class ReconstructedParticle;
class ConstReconstructedParticle;

class ReconstructedParticleObj : public podio::ObjBase {
public:
  /// constructor
  ReconstructedParticleObj();
  /// copy constructor (does a deep-copy of relation containers)
  ReconstructedParticleObj(const ReconstructedParticleObj&);
  /// constructor from ObjectID and ReconstructedParticleData
  /// does not initialize the internal relation containers
  ReconstructedParticleObj(const podio::ObjectID id, ReconstructedParticleData data);
  /// No assignment operator
  ReconstructedParticleObj& operator=(const ReconstructedParticleObj&) = delete;
  virtual ~ReconstructedParticleObj();

public:
  ReconstructedParticleData data;
  ::edm4hep::ConstVertex* m_startVertex{nullptr};
  ::edm4hep::ConstParticleID* m_particleIDUsed{nullptr};
  std::vector<::edm4hep::ConstCluster>* m_clusters{nullptr};
  std::vector<::edm4hep::ConstTrack>* m_tracks{nullptr};
  std::vector<::edm4hep::ConstReconstructedParticle>* m_particles{nullptr};
  std::vector<::edm4hep::ConstParticleID>* m_particleIDs{nullptr};
};

} // namespace edm4hep


#endif
