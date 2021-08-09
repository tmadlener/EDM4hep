// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Cluster_H
#define EDM4HEP_Cluster_H

#include "edm4hep/ClusterConst.h"
#include "edm4hep/ClusterObj.h"

#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/ParticleID.h"
#include "edm4hep/Vector3f.h"
#include <array>
#include <vector>
#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class Cluster
 *  Calorimeter Hit Cluster
 *  @author: F.Gaede, DESY
 */
class Cluster {

  friend class ClusterCollection;
  friend class ClusterCollectionIterator;
  friend class ConstCluster;

public:

  /// default constructor
  Cluster();
  Cluster(int type, float energy, float energyError, edm4hep::Vector3f position, std::array<float, 6> positionError, float iTheta, float phi, edm4hep::Vector3f directionError);

  /// constructor from existing ClusterObj
  Cluster(ClusterObj* obj);

  /// copy constructor
  Cluster(const Cluster& other);

  /// copy-assignment operator
  Cluster& operator=(const Cluster& other);

  /// support cloning (deep-copy)
  Cluster clone() const;

  /// destructor
  ~Cluster();

  /// conversion to const object
  operator ConstCluster() const;

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



  /// Set the flagword that defines the type of cluster. Bits 16-31 are used internally.
  void setType(int value);

  /// Set the energy of the cluster [GeV]
  void setEnergy(float value);

  /// Set the error on the energy
  void setEnergyError(float value);

  /// Set the position of the cluster.
  void setPosition(edm4hep::Vector3f value);
  /// Get reference to position of the cluster.
  edm4hep::Vector3f& position();

  /// Set the covariance matrix of the position (6 Parameters)
  void setPositionError(std::array<float, 6> value);
  void setPositionError(size_t i, float value);
  /// Get reference to covariance matrix of the position (6 Parameters)
  std::array<float, 6>& positionError();

  /// Set the intrinsic direction of cluster at position  Theta. Not to be confused with direction cluster is seen from IP.
  void setITheta(float value);

  /// Set the intrinsic direction of cluster at position - Phi. Not to be confused with direction cluster is seen from IP.
  void setPhi(float value);

  /// Set the covariance matrix of the direction (3 Parameters)
  void setDirectionError(edm4hep::Vector3f value);
  /// Get reference to covariance matrix of the direction (3 Parameters)
  edm4hep::Vector3f& directionError();



  void addToClusters(::edm4hep::ConstCluster);
  unsigned int clusters_size() const;
  ::edm4hep::ConstCluster getClusters(unsigned int) const;
  std::vector<::edm4hep::ConstCluster>::const_iterator clusters_begin() const;
  std::vector<::edm4hep::ConstCluster>::const_iterator clusters_end() const;
  podio::RelationRange<::edm4hep::ConstCluster> getClusters() const;
  void addToHits(::edm4hep::ConstCalorimeterHit);
  unsigned int hits_size() const;
  ::edm4hep::ConstCalorimeterHit getHits(unsigned int) const;
  std::vector<::edm4hep::ConstCalorimeterHit>::const_iterator hits_begin() const;
  std::vector<::edm4hep::ConstCalorimeterHit>::const_iterator hits_end() const;
  podio::RelationRange<::edm4hep::ConstCalorimeterHit> getHits() const;
  void addToParticleIDs(::edm4hep::ConstParticleID);
  unsigned int particleIDs_size() const;
  ::edm4hep::ConstParticleID getParticleIDs(unsigned int) const;
  std::vector<::edm4hep::ConstParticleID>::const_iterator particleIDs_begin() const;
  std::vector<::edm4hep::ConstParticleID>::const_iterator particleIDs_end() const;
  podio::RelationRange<::edm4hep::ConstParticleID> getParticleIDs() const;
  void addToShapeParameters(float);
  unsigned int shapeParameters_size() const;
  float getShapeParameters(unsigned int) const;
  std::vector<float>::const_iterator shapeParameters_begin() const;
  std::vector<float>::const_iterator shapeParameters_end() const;
  podio::RelationRange<float> getShapeParameters() const;
  void addToHitContributions(float);
  unsigned int hitContributions_size() const;
  float getHitContributions(unsigned int) const;
  std::vector<float>::const_iterator hitContributions_begin() const;
  std::vector<float>::const_iterator hitContributions_end() const;
  podio::RelationRange<float> getHitContributions() const;
  void addToSubdetectorEnergies(float);
  unsigned int subdetectorEnergies_size() const;
  float getSubdetectorEnergies(unsigned int) const;
  std::vector<float>::const_iterator subdetectorEnergies_begin() const;
  std::vector<float>::const_iterator subdetectorEnergies_end() const;
  podio::RelationRange<float> getSubdetectorEnergies() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ClusterObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const Cluster& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstCluster& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const Cluster& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  ClusterObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstCluster& value);

} // namespace edm4hep


#endif
