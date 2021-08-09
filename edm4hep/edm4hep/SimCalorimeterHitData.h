// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimCalorimeterHitDATA_H
#define EDM4HEP_SimCalorimeterHitDATA_H

#include "edm4hep/Vector3f.h"

namespace edm4hep {


/** @class SimCalorimeterHitData
 *  Simulated calorimeter hit
 *  @author: F.Gaede, DESY
 */
class SimCalorimeterHitData {
public:
  unsigned long long cellID{}; ///< ID of the sensor that created this hit
  float energy{}; ///< energy of the hit in [GeV].
  ::edm4hep::Vector3f position{}; ///< position of the hit in world coordinates.

  unsigned int contributions_begin{};
  unsigned int contributions_end{};
};

} // namespace edm4hep


#endif
