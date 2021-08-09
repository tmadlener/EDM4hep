// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ParticleIDDATA_H
#define EDM4HEP_ParticleIDDATA_H


namespace edm4hep {


/** @class ParticleIDData
 *  ParticleID
 *  @author: F.Gaede, DESY
 */
class ParticleIDData {
public:
  int type{}; ///< userdefined type
  int PDG{}; ///< PDG code of this id - ( 999999 ) if unknown.
  int algorithmType{}; ///< type of the algorithm/module that created this hypothesis
  float likelihood{}; ///< likelihood of this hypothesis - in a user defined normalization.

  unsigned int parameters_begin{};
  unsigned int parameters_end{};
};

} // namespace edm4hep


#endif
