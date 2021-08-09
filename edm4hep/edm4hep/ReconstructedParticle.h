// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ReconstructedParticle_H
#define EDM4HEP_ReconstructedParticle_H

#include "edm4hep/ReconstructedParticleConst.h"
#include "edm4hep/ReconstructedParticleObj.h"

#include "edm4hep/Cluster.h"
#include "edm4hep/ParticleID.h"
#include "edm4hep/Track.h"
#include "edm4hep/Vector3f.h"
#include <array>
#include <vector>
#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class Vertex;
class ConstVertex;
class ParticleID;
class ConstParticleID;
}


namespace edm4hep {


/** @class ReconstructedParticle
 *  Reconstructed Particle
 *  @author: F.Gaede, DESY
 */
class ReconstructedParticle {

  friend class ReconstructedParticleCollection;
  friend class ReconstructedParticleCollectionIterator;
  friend class ConstReconstructedParticle;

public:

  /// default constructor
  ReconstructedParticle();
  ReconstructedParticle(int type, float energy, edm4hep::Vector3f momentum, edm4hep::Vector3f referencePoint, float charge, float mass, float goodnessOfPID, std::array<float, 10> covMatrix);

  /// constructor from existing ReconstructedParticleObj
  ReconstructedParticle(ReconstructedParticleObj* obj);

  /// copy constructor
  ReconstructedParticle(const ReconstructedParticle& other);

  /// copy-assignment operator
  ReconstructedParticle& operator=(const ReconstructedParticle& other);

  /// support cloning (deep-copy)
  ReconstructedParticle clone() const;

  /// destructor
  ~ReconstructedParticle();

  /// conversion to const object
  operator ConstReconstructedParticle() const;

public:

  /// Access the type of reconstructed particle. Check/set collection parameters ReconstructedParticleTypeNames and ReconstructedParticleTypeValues.
  const int& getType() const;

  /// Access the [GeV] energy of the reconstructed particle. Four momentum state is not kept consistent internally.
  const float& getEnergy() const;

  /// Access the [GeV] particle momentum. Four momentum state is not kept consistent internally.
  const edm4hep::Vector3f& getMomentum() const;

  /// Access the [mm] reference, i.e. where the particle has been measured
  const edm4hep::Vector3f& getReferencePoint() const;

  /// Access the charge of the reconstructed particle.
  const float& getCharge() const;

  /// Access the [GeV] mass of the reconstructed particle, set independently from four vector. Four momentum state is not kept consistent internally.
  const float& getMass() const;

  /// Access the overall goodness of the PID on a scale of [0;1]
  const float& getGoodnessOfPID() const;

  /// Access the cvariance matrix of the reconstructed particle 4vector (10 parameters). Stored as lower triangle matrix of the four momentum (px,py,pz,E), i.e. cov(px,px), cov(py,##
  const std::array<float, 10>& getCovMatrix() const;
  /// Access item i of the cvariance matrix of the reconstructed particle 4vector (10 parameters). Stored as lower triangle matrix of the four momentum (px,py,pz,E), i.e. cov(px,px), cov(py,##
  const float& getCovMatrix(size_t i) const;

  /// Access the start vertex associated to this particle
  const ::edm4hep::ConstVertex getStartVertex() const;
  /// Access the particle Id used for the kinematics of this particle
  const ::edm4hep::ConstParticleID getParticleIDUsed() const;

  /// Set the type of reconstructed particle. Check/set collection parameters ReconstructedParticleTypeNames and ReconstructedParticleTypeValues.
  void setType(int value);

  /// Set the [GeV] energy of the reconstructed particle. Four momentum state is not kept consistent internally.
  void setEnergy(float value);

  /// Set the [GeV] particle momentum. Four momentum state is not kept consistent internally.
  void setMomentum(edm4hep::Vector3f value);
  /// Get reference to [GeV] particle momentum. Four momentum state is not kept consistent internally.
  edm4hep::Vector3f& momentum();

  /// Set the [mm] reference, i.e. where the particle has been measured
  void setReferencePoint(edm4hep::Vector3f value);
  /// Get reference to [mm] reference, i.e. where the particle has been measured
  edm4hep::Vector3f& referencePoint();

  /// Set the charge of the reconstructed particle.
  void setCharge(float value);

  /// Set the [GeV] mass of the reconstructed particle, set independently from four vector. Four momentum state is not kept consistent internally.
  void setMass(float value);

  /// Set the overall goodness of the PID on a scale of [0;1]
  void setGoodnessOfPID(float value);

  /// Set the cvariance matrix of the reconstructed particle 4vector (10 parameters). Stored as lower triangle matrix of the four momentum (px,py,pz,E), i.e. cov(px,px), cov(py,##
  void setCovMatrix(std::array<float, 10> value);
  void setCovMatrix(size_t i, float value);
  /// Get reference to cvariance matrix of the reconstructed particle 4vector (10 parameters). Stored as lower triangle matrix of the four momentum (px,py,pz,E), i.e. cov(px,px), cov(py,##
  std::array<float, 10>& covMatrix();


  /// Set the start vertex associated to this particle
  void setStartVertex(::edm4hep::ConstVertex value);
  /// Set the particle Id used for the kinematics of this particle
  void setParticleIDUsed(::edm4hep::ConstParticleID value);

  void addToClusters(::edm4hep::ConstCluster);
  unsigned int clusters_size() const;
  ::edm4hep::ConstCluster getClusters(unsigned int) const;
  std::vector<::edm4hep::ConstCluster>::const_iterator clusters_begin() const;
  std::vector<::edm4hep::ConstCluster>::const_iterator clusters_end() const;
  podio::RelationRange<::edm4hep::ConstCluster> getClusters() const;
  void addToTracks(::edm4hep::ConstTrack);
  unsigned int tracks_size() const;
  ::edm4hep::ConstTrack getTracks(unsigned int) const;
  std::vector<::edm4hep::ConstTrack>::const_iterator tracks_begin() const;
  std::vector<::edm4hep::ConstTrack>::const_iterator tracks_end() const;
  podio::RelationRange<::edm4hep::ConstTrack> getTracks() const;
  void addToParticles(::edm4hep::ConstReconstructedParticle);
  unsigned int particles_size() const;
  ::edm4hep::ConstReconstructedParticle getParticles(unsigned int) const;
  std::vector<::edm4hep::ConstReconstructedParticle>::const_iterator particles_begin() const;
  std::vector<::edm4hep::ConstReconstructedParticle>::const_iterator particles_end() const;
  podio::RelationRange<::edm4hep::ConstReconstructedParticle> getParticles() const;
  void addToParticleIDs(::edm4hep::ConstParticleID);
  unsigned int particleIDs_size() const;
  ::edm4hep::ConstParticleID getParticleIDs(unsigned int) const;
  std::vector<::edm4hep::ConstParticleID>::const_iterator particleIDs_begin() const;
  std::vector<::edm4hep::ConstParticleID>::const_iterator particleIDs_end() const;
  podio::RelationRange<::edm4hep::ConstParticleID> getParticleIDs() const;

 bool isCompound() { return particles_size() > 0 ;}
 //vertex where the particle decays This method actually returns the start vertex from the first daughter particle found.
 //TODO: edm4hep::Vertex  getEndVertex() { return  edm4hep::Vertex(  (getParticles(0).isAvailable() ? getParticles(0).getStartVertex() :  edm4hep::Vertex(0,0) ) ) ; }
 


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ReconstructedParticleObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ReconstructedParticle& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstReconstructedParticle& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ReconstructedParticle& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  ReconstructedParticleObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstReconstructedParticle& value);

} // namespace edm4hep


#endif
