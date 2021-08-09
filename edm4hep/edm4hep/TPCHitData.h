// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TPCHitDATA_H
#define EDM4HEP_TPCHitDATA_H


namespace edm4hep {


/** @class TPCHitData
 *  Time Projection Chamber Hit
 *  @author: F.Gaede, DESY
 */
class TPCHitData {
public:
  unsigned long long cellID{}; ///< detector specific cell id.
  int quality{}; ///< quality flag for the hit.
  float time{}; ///< time of the hit.
  float charge{}; ///< integrated charge of the hit.

  unsigned int rawDataWords_begin{};
  unsigned int rawDataWords_end{};
};

} // namespace edm4hep


#endif
