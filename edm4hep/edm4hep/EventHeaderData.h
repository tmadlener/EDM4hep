// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_EventHeaderDATA_H
#define EDM4HEP_EventHeaderDATA_H


namespace edm4hep {


/** @class EventHeaderData
 *  Event Header. Additional parameters are assumed to go into the metadata tree.
 *  @author: F.Gaede
 */
class EventHeaderData {
public:
  int eventNumber{}; ///< event number
  int runNumber{}; ///< run number
  unsigned long long timeStamp{}; ///< time stamp
  float weight{}; ///< event weight

};

} // namespace edm4hep


#endif
