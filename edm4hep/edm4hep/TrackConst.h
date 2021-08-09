// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstTrack_H
#define EDM4HEP_ConstTrack_H

#include "edm4hep/TrackObj.h"

#include "edm4hep/TrackState.h"
#include "edm4hep/TrackerHit.h"
#include <vector>
#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstTrack
 *  Reconstructed track
 *  @author: F.Gaede, DESY
 */
class ConstTrack {

  friend class Track;
  friend class TrackCollection;
  friend class TrackConstCollectionIterator;

public:
  /// default constructor
  ConstTrack();
  ConstTrack(int type, float chi2, int ndf, float dEdx, float dEdxError, float radiusOfInnermostHit);

  /// constructor from existing TrackObj
  ConstTrack(TrackObj* obj);

  /// copy constructor
  ConstTrack(const ConstTrack& other);

  /// copy-assignment operator
  ConstTrack& operator=(const ConstTrack& other);

  /// support cloning (deep-copy)
  ConstTrack clone() const;

  /// destructor
  ~ConstTrack();


public:

  /// Access the flagword that defines the type of track.Bits 16-31 are used internally
  const int& getType() const;

  /// Access the Chi^2 of the track fit
  const float& getChi2() const;

  /// Access the number of degrees of freedom of the track fit
  const int& getNdf() const;

  /// Access the dEdx of the track.
  const float& getDEdx() const;

  /// Access the error of dEdx.
  const float& getDEdxError() const;

  /// Access the radius of the innermost hit that has been used in the track fit
  const float& getRadiusOfInnermostHit() const;



  unsigned int trackerHits_size() const;
  ::edm4hep::ConstTrackerHit getTrackerHits(unsigned int) const;
  std::vector<::edm4hep::ConstTrackerHit>::const_iterator trackerHits_begin() const;
  std::vector<::edm4hep::ConstTrackerHit>::const_iterator trackerHits_end() const;
  podio::RelationRange<::edm4hep::ConstTrackerHit> getTrackerHits() const;
  unsigned int tracks_size() const;
  ::edm4hep::ConstTrack getTracks(unsigned int) const;
  std::vector<::edm4hep::ConstTrack>::const_iterator tracks_begin() const;
  std::vector<::edm4hep::ConstTrack>::const_iterator tracks_end() const;
  podio::RelationRange<::edm4hep::ConstTrack> getTracks() const;
  unsigned int subDetectorHitNumbers_size() const;
  int getSubDetectorHitNumbers(unsigned int) const;
  std::vector<int>::const_iterator subDetectorHitNumbers_begin() const;
  std::vector<int>::const_iterator subDetectorHitNumbers_end() const;
  podio::RelationRange<int> getSubDetectorHitNumbers() const;
  unsigned int trackStates_size() const;
  edm4hep::TrackState getTrackStates(unsigned int) const;
  std::vector<edm4hep::TrackState>::const_iterator trackStates_begin() const;
  std::vector<edm4hep::TrackState>::const_iterator trackStates_end() const;
  podio::RelationRange<edm4hep::TrackState> getTrackStates() const;


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstTrack& other) const { return m_obj == other.m_obj; }
  bool operator==(const Track& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstTrack& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  TrackObj* m_obj;
};

} // namespace edm4hep


#endif
