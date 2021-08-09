// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ReconstructedParticleDATA_H
#define EDM4HEP_ReconstructedParticleDATA_H

#include "edm4hep/Vector3f.h"
#include <array>

namespace edm4hep {


/** @class ReconstructedParticleData
 *  Reconstructed Particle
 *  @author: F.Gaede, DESY
 */
class ReconstructedParticleData {
public:
  int type{}; ///< type of reconstructed particle. Check/set collection parameters ReconstructedParticleTypeNames and ReconstructedParticleTypeValues.
  float energy{}; ///< [GeV] energy of the reconstructed particle. Four momentum state is not kept consistent internally.
  ::edm4hep::Vector3f momentum{}; ///< [GeV] particle momentum. Four momentum state is not kept consistent internally.
  ::edm4hep::Vector3f referencePoint{}; ///< [mm] reference, i.e. where the particle has been measured
  float charge{}; ///< charge of the reconstructed particle.
  float mass{}; ///< [GeV] mass of the reconstructed particle, set independently from four vector. Four momentum state is not kept consistent internally.
  float goodnessOfPID{}; ///< overall goodness of the PID on a scale of [0;1]
  std::array<float, 10> covMatrix{}; ///< cvariance matrix of the reconstructed particle 4vector (10 parameters). Stored as lower triangle matrix of the four momentum (px,py,pz,E), i.e. cov(px,px), cov(py,##

  unsigned int clusters_begin{};
  unsigned int clusters_end{};
  unsigned int tracks_begin{};
  unsigned int tracks_end{};
  unsigned int particles_begin{};
  unsigned int particles_end{};
  unsigned int particleIDs_begin{};
  unsigned int particleIDs_end{};
};

} // namespace edm4hep


#endif
