// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstCluster_H
#define EDM4HEP_ConstCluster_H

#include "edm4hep/ClusterObj.h"

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/ParticleID.h"
#include "edm4hep/Vector3f.h"
#include <array>
#include <vector>
#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstCluster
 *  Calorimeter Hit Cluster
 *  @author: F.Gaede, DESY
 */
class ConstCluster {

  friend class Cluster;
  friend class ClusterCollection;
  friend class ClusterConstCollectionIterator;

public:
  /// default constructor
  ConstCluster();
  ConstCluster(int type, float energy, float energyError, edm4hep::Vector3f position, std::array<float, 6> positionError, float iTheta, float phi, edm4hep::Vector3f directionError);

  /// constructor from existing ClusterObj
  ConstCluster(ClusterObj* obj);

  /// copy constructor
  ConstCluster(const ConstCluster& other);

  /// copy-assignment operator
  ConstCluster& operator=(const ConstCluster& other);

  /// support cloning (deep-copy)
  ConstCluster clone() const;

  /// destructor
  ~ConstCluster();


public:

  /// Access the flagword that defines the type of cluster. Bits 16-31 are used internally.
  const int& getType() const;

  /// Access the energy of the cluster [GeV]
  const float& getEnergy() const;

  /// Access the error on the energy
  const float& getEnergyError() const;

  /// Access the position of the cluster.
  const edm4hep::Vector3f& getPosition() const;

  /// Access the covariance matrix of the position (6 Parameters)
  const std::array<float, 6>& getPositionError() const;
  /// Access item i of the covariance matrix of the position (6 Parameters)
  const float& getPositionError(size_t i) const;
  /// Access the intrinsic direction of cluster at position  Theta. Not to be confused with direction cluster is seen from IP.
  const float& getITheta() const;

  /// Access the intrinsic direction of cluster at position - Phi. Not to be confused with direction cluster is seen from IP.
  const float& getPhi() const;

  /// Access the covariance matrix of the direction (3 Parameters)
  const edm4hep::Vector3f& getDirectionError() const;



  unsigned int clusters_size() const;
  ::edm4hep::ConstCluster getClusters(unsigned int) const;
  std::vector<::edm4hep::ConstCluster>::const_iterator clusters_begin() const;
  std::vector<::edm4hep::ConstCluster>::const_iterator clusters_end() const;
  podio::RelationRange<::edm4hep::ConstCluster> getClusters() const;
  unsigned int hits_size() const;
  ::edm4hep::ConstCalorimeterHit getHits(unsigned int) const;
  std::vector<::edm4hep::ConstCalorimeterHit>::const_iterator hits_begin() const;
  std::vector<::edm4hep::ConstCalorimeterHit>::const_iterator hits_end() const;
  podio::RelationRange<::edm4hep::ConstCalorimeterHit> getHits() const;
  unsigned int particleIDs_size() const;
  ::edm4hep::ConstParticleID getParticleIDs(unsigned int) const;
  std::vector<::edm4hep::ConstParticleID>::const_iterator particleIDs_begin() const;
  std::vector<::edm4hep::ConstParticleID>::const_iterator particleIDs_end() const;
  podio::RelationRange<::edm4hep::ConstParticleID> getParticleIDs() const;
  unsigned int shapeParameters_size() const;
  float getShapeParameters(unsigned int) const;
  std::vector<float>::const_iterator shapeParameters_begin() const;
  std::vector<float>::const_iterator shapeParameters_end() const;
  podio::RelationRange<float> getShapeParameters() const;
  unsigned int hitContributions_size() const;
  float getHitContributions(unsigned int) const;
  std::vector<float>::const_iterator hitContributions_begin() const;
  std::vector<float>::const_iterator hitContributions_end() const;
  podio::RelationRange<float> getHitContributions() const;
  unsigned int subdetectorEnergies_size() const;
  float getSubdetectorEnergies(unsigned int) const;
  std::vector<float>::const_iterator subdetectorEnergies_begin() const;
  std::vector<float>::const_iterator subdetectorEnergies_end() const;
  podio::RelationRange<float> getSubdetectorEnergies() const;


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ClusterObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstCluster& other) const { return m_obj == other.m_obj; }
  bool operator==(const Cluster& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstCluster& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  ClusterObj* m_obj;
};

} // namespace edm4hep


#endif
