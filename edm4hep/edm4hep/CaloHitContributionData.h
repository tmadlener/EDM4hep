// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CaloHitContributionDATA_H
#define EDM4HEP_CaloHitContributionDATA_H

#include "edm4hep/Vector3f.h"

namespace edm4hep {


/** @class CaloHitContributionData
 *  Monte Carlo contribution to SimCalorimeterHit
 *  @author: F.Gaede, DESY
 */
class CaloHitContributionData {
public:
  int PDG{}; ///< PDG code of the shower particle that caused this contribution.
  float energy{}; ///< energy in [GeV] of the this contribution
  float time{}; ///< time in [ns] of this contribution
  ::edm4hep::Vector3f stepPosition{}; ///< position of this energy deposition (step)

};

} // namespace edm4hep


#endif
