// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Vertex_H
#define EDM4HEP_Vertex_H

#include "edm4hep/VertexConst.h"
#include "edm4hep/VertexObj.h"

#include "edm4hep/Vector3f.h"
#include <array>
#include <vector>
#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class ConstReconstructedParticle;
}


namespace edm4hep {


/** @class Vertex
 *  Vertex
 *  @author: F.Gaede, DESY
 */
class Vertex {

  friend class VertexCollection;
  friend class VertexCollectionIterator;
  friend class ConstVertex;

public:

  /// default constructor
  Vertex();
  Vertex(int primary, float chi2, float probability, edm4hep::Vector3f position, std::array<float, 6> covMatrix, int algorithmType);

  /// constructor from existing VertexObj
  Vertex(VertexObj* obj);

  /// copy constructor
  Vertex(const Vertex& other);

  /// copy-assignment operator
  Vertex& operator=(const Vertex& other);

  /// support cloning (deep-copy)
  Vertex clone() const;

  /// destructor
  ~Vertex();

  /// conversion to const object
  operator ConstVertex() const;

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

  /// Set the boolean flag, if vertex is the primary vertex of the event
  void setPrimary(int value);

  /// Set the chi-squared of the vertex fit
  void setChi2(float value);

  /// Set the probability of the vertex fit
  void setProbability(float value);

  /// Set the [mm] position of the vertex.
  void setPosition(edm4hep::Vector3f value);
  /// Get reference to [mm] position of the vertex.
  edm4hep::Vector3f& position();

  /// Set the covariance matrix of the position (stored as lower triangle matrix, i.e. cov(xx),cov(y,x),cov(z,x),cov(y,y),... )
  void setCovMatrix(std::array<float, 6> value);
  void setCovMatrix(size_t i, float value);
  /// Get reference to covariance matrix of the position (stored as lower triangle matrix, i.e. cov(xx),cov(y,x),cov(z,x),cov(y,y),... )
  std::array<float, 6>& covMatrix();

  /// Set the type code for the algorithm that has been used to create the vertex - check/set the collection parameters AlgorithmName and AlgorithmType.
  void setAlgorithmType(int value);


  /// Set the reconstructed particle associated to this vertex.
  void setAssociatedParticle(::edm4hep::ConstReconstructedParticle value);

  void addToParameters(float);
  unsigned int parameters_size() const;
  float getParameters(unsigned int) const;
  std::vector<float>::const_iterator parameters_begin() const;
  std::vector<float>::const_iterator parameters_end() const;
  podio::RelationRange<float> getParameters() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from VertexObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const Vertex& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstVertex& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const Vertex& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  VertexObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstVertex& value);

} // namespace edm4hep


#endif
