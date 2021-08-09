// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ClusterDATA_H
#define EDM4HEP_ClusterDATA_H

#include "edm4hep/Vector3f.h"
#include <array>

namespace edm4hep {


/** @class ClusterData
 *  Calorimeter Hit Cluster
 *  @author: F.Gaede, DESY
 */
class ClusterData {
public:
  int type{}; ///< flagword that defines the type of cluster. Bits 16-31 are used internally.
  float energy{}; ///< energy of the cluster [GeV]
  float energyError{}; ///< error on the energy
  ::edm4hep::Vector3f position{}; ///< position of the cluster.
  std::array<float, 6> positionError{}; ///< covariance matrix of the position (6 Parameters)
  float iTheta{}; ///< intrinsic direction of cluster at position  Theta. Not to be confused with direction cluster is seen from IP.
  float phi{}; ///< intrinsic direction of cluster at position - Phi. Not to be confused with direction cluster is seen from IP.
  ::edm4hep::Vector3f directionError{}; ///< covariance matrix of the direction (3 Parameters)

  unsigned int shapeParameters_begin{};
  unsigned int shapeParameters_end{};
  unsigned int hitContributions_begin{};
  unsigned int hitContributions_end{};
  unsigned int subdetectorEnergies_begin{};
  unsigned int subdetectorEnergies_end{};
  unsigned int clusters_begin{};
  unsigned int clusters_end{};
  unsigned int hits_begin{};
  unsigned int hits_end{};
  unsigned int particleIDs_begin{};
  unsigned int particleIDs_end{};
};

} // namespace edm4hep


#endif
