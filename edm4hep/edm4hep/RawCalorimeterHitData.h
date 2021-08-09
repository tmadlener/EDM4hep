// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawCalorimeterHitDATA_H
#define EDM4HEP_RawCalorimeterHitDATA_H


namespace edm4hep {


/** @class RawCalorimeterHitData
 *  Raw calorimeter hit
 *  @author: F.Gaede, DESY
 */
class RawCalorimeterHitData {
public:
  unsigned long long cellID{}; ///< detector specific (geometrical) cell id.
  int amplitude{}; ///< amplitude of the hit in ADC counts.
  int timeStamp{}; ///< time stamp for the hit.

};

} // namespace edm4hep


#endif
