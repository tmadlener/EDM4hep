// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimTrackerHitDATA_H
#define EDM4HEP_SimTrackerHitDATA_H

#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"

namespace edm4hep {


/** @class SimTrackerHitData
 *  Simulated tracker hit
 *  @author: F.Gaede, DESY
 */
class SimTrackerHitData {
public:
  unsigned long long cellID{}; ///< ID of the sensor that created this hit
  float EDep{}; ///< energy deposited in the hit [GeV].
  float time{}; ///< proper time of the hit in the lab frame in [ns].
  float pathLength{}; ///< path length of the particle in the sensitive material that resulted in this hit.
  int quality{}; ///< quality bit flag.
  ::edm4hep::Vector3d position{}; ///< the hit position in [mm].
  ::edm4hep::Vector3f momentum{}; ///< the 3-momentum of the particle at the hits position in [GeV]

};

} // namespace edm4hep


#endif
