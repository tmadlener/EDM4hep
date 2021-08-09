// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_VertexDATA_H
#define EDM4HEP_VertexDATA_H

#include "edm4hep/Vector3f.h"
#include <array>

namespace edm4hep {


/** @class VertexData
 *  Vertex
 *  @author: F.Gaede, DESY
 */
class VertexData {
public:
  int primary{}; ///< boolean flag, if vertex is the primary vertex of the event
  float chi2{}; ///< chi-squared of the vertex fit
  float probability{}; ///< probability of the vertex fit
  ::edm4hep::Vector3f position{}; ///< [mm] position of the vertex.
  std::array<float, 6> covMatrix{}; ///< covariance matrix of the position (stored as lower triangle matrix, i.e. cov(xx),cov(y,x),cov(z,x),cov(y,y),... )
  int algorithmType{}; ///< type code for the algorithm that has been used to create the vertex - check/set the collection parameters AlgorithmName and AlgorithmType.

  unsigned int parameters_begin{};
  unsigned int parameters_end{};
};

} // namespace edm4hep


#endif
