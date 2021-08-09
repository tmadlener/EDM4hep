// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCParticleDATA_H
#define EDM4HEP_MCParticleDATA_H

#include "edm4hep/Vector2i.h"
#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"

namespace edm4hep {


/** @class MCParticleData
 *  The Monte Carlo particle - based on the lcio::MCParticle.
 *  @author: F.Gaede, DESY
 */
class MCParticleData {
public:
  int PDG{}; ///< PDG code of the particle
  int generatorStatus{}; ///< status of the particle as defined by the generator
  int simulatorStatus{}; ///< status of the particle from the simulation program - use BIT constants below
  float charge{}; ///< particle charge
  float time{}; ///< creation time of the particle in [ns] wrt. the event, e.g. for preassigned decays or decays in flight from the simulator.
  double mass{}; ///< mass of the particle in [GeV]
  ::edm4hep::Vector3d vertex{}; ///< production vertex of the particle in [mm].
  ::edm4hep::Vector3d endpoint{}; ///< endpoint of the particle in [mm]
  ::edm4hep::Vector3f momentum{}; ///< particle 3-momentum at the production vertex in [GeV]
  ::edm4hep::Vector3f momentumAtEndpoint{}; ///< particle 3-momentum at the endpoint in [GeV]
  ::edm4hep::Vector3f spin{}; ///< spin (helicity) vector of the particle.
  ::edm4hep::Vector2i colorFlow{}; ///< color flow as defined by the generator

  unsigned int parents_begin{};
  unsigned int parents_end{};
  unsigned int daughters_begin{};
  unsigned int daughters_end{};
};

} // namespace edm4hep


#endif
