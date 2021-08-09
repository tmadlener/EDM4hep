// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackDATA_H
#define EDM4HEP_TrackDATA_H


namespace edm4hep {


/** @class TrackData
 *  Reconstructed track
 *  @author: F.Gaede, DESY
 */
class TrackData {
public:
  int type{}; ///< flagword that defines the type of track.Bits 16-31 are used internally
  float chi2{}; ///< Chi^2 of the track fit
  int ndf{}; ///< number of degrees of freedom of the track fit
  float dEdx{}; ///< dEdx of the track.
  float dEdxError{}; ///< error of dEdx.
  float radiusOfInnermostHit{}; ///< radius of the innermost hit that has been used in the track fit

  unsigned int subDetectorHitNumbers_begin{};
  unsigned int subDetectorHitNumbers_end{};
  unsigned int trackStates_begin{};
  unsigned int trackStates_end{};
  unsigned int trackerHits_begin{};
  unsigned int trackerHits_end{};
  unsigned int tracks_begin{};
  unsigned int tracks_end{};
};

} // namespace edm4hep


#endif
