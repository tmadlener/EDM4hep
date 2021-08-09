// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstVertex_H
#define EDM4HEP_ConstVertex_H

#include "edm4hep/VertexObj.h"

#include "edm4hep/Vector3f.h"
#include <array>
#include <vector>
#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class ConstReconstructedParticle;
}


namespace edm4hep {


/** @class ConstVertex
 *  Vertex
 *  @author: F.Gaede, DESY
 */
class ConstVertex {

  friend class Vertex;
  friend class VertexCollection;
  friend class VertexConstCollectionIterator;

public:
  /// default constructor
  ConstVertex();
  ConstVertex(int primary, float chi2, float probability, edm4hep::Vector3f position, std::array<float, 6> covMatrix, int algorithmType);

  /// constructor from existing VertexObj
  ConstVertex(VertexObj* obj);

  /// copy constructor
  ConstVertex(const ConstVertex& other);

  /// copy-assignment operator
  ConstVertex& operator=(const ConstVertex& other);

  /// support cloning (deep-copy)
  ConstVertex clone() const;

  /// destructor
  ~ConstVertex();


public:

  /// Access the boolean flag, if vertex is the primary vertex of the event
  const int& getPrimary() const;

  /// Access the chi-squared of the vertex fit
  const float& getChi2() const;

  /// Access the probability of the vertex fit
  const float& getProbability() const;

  /// Access the [mm] position of the vertex.
  const edm4hep::Vector3f& getPosition() const;

  /// Access the covariance matrix of the position (stored as lower triangle matrix, i.e. cov(xx),cov(y,x),cov(z,x),cov(y,y),... )
  const std::array<float, 6>& getCovMatrix() const;
  /// Access item i of the covariance matrix of the position (stored as lower triangle matrix, i.e. cov(xx),cov(y,x),cov(z,x),cov(y,y),... )
  const float& getCovMatrix(size_t i) const;
  /// Access the type code for the algorithm that has been used to create the vertex - check/set the collection parameters AlgorithmName and AlgorithmType.
  const int& getAlgorithmType() const;


  /// Access the reconstructed particle associated to this vertex.
  const ::edm4hep::ConstReconstructedParticle getAssociatedParticle() const;

  unsigned int parameters_size() const;
  float getParameters(unsigned int) const;
  std::vector<float>::const_iterator parameters_begin() const;
  std::vector<float>::const_iterator parameters_end() const;
  podio::RelationRange<float> getParameters() const;


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from VertexObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstVertex& other) const { return m_obj == other.m_obj; }
  bool operator==(const Vertex& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstVertex& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  VertexObj* m_obj;
};

} // namespace edm4hep


#endif
