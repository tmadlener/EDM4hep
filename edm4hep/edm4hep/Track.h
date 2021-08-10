// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Track_H
#define EDM4HEP_Track_H

#include "edm4hep/TrackConst.h"
#include "edm4hep/TrackObj.h"

#include "edm4hep/TrackState.h"
#include "edm4hep/TrackerHit.h"
#include <vector>
#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class Track
 *  Reconstructed track
 *  @author: F.Gaede, DESY
 */
class Track {

  friend class TrackCollection;
  friend class TrackCollectionIterator;
  friend class ConstTrack;

public:

  /// default constructor
  Track();
  Track(int type, float chi2, int ndf, float dEdx, float dEdxError, float radiusOfInnermostHit);

  /// constructor from existing TrackObj
  Track(TrackObj* obj);

  /// copy constructor
  Track(const Track& other);

  /// copy-assignment operator
  Track& operator=(const Track& other);

  /// support cloning (deep-copy)
  Track clone() const;

  /// destructor
  ~Track();

  /// conversion to const object
  operator ConstTrack() const;

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



  /// Set the flagword that defines the type of track.Bits 16-31 are used internally
  void setType(int value);

  /// Set the Chi^2 of the track fit
  void setChi2(float value);

  /// Set the number of degrees of freedom of the track fit
  void setNdf(int value);

  /// Set the dEdx of the track.
  void setDEdx(float value);

  /// Set the error of dEdx.
  void setDEdxError(float value);

  /// Set the radius of the innermost hit that has been used in the track fit
  void setRadiusOfInnermostHit(float value);



  void addToTrackerHits(::edm4hep::ConstTrackerHitWrapper);
  unsigned int trackerHits_size() const;
  ::edm4hep::ConstTrackerHitWrapper getTrackerHits(unsigned int) const;
  std::vector<::edm4hep::ConstTrackerHitWrapper>::const_iterator trackerHits_begin() const;
  std::vector<::edm4hep::ConstTrackerHitWrapper>::const_iterator trackerHits_end() const;
  podio::RelationRange<::edm4hep::ConstTrackerHitWrapper> getTrackerHits() const;
  void addToTracks(::edm4hep::ConstTrack);
  unsigned int tracks_size() const;
  ::edm4hep::ConstTrack getTracks(unsigned int) const;
  std::vector<::edm4hep::ConstTrack>::const_iterator tracks_begin() const;
  std::vector<::edm4hep::ConstTrack>::const_iterator tracks_end() const;
  podio::RelationRange<::edm4hep::ConstTrack> getTracks() const;
  void addToSubDetectorHitNumbers(int);
  unsigned int subDetectorHitNumbers_size() const;
  int getSubDetectorHitNumbers(unsigned int) const;
  std::vector<int>::const_iterator subDetectorHitNumbers_begin() const;
  std::vector<int>::const_iterator subDetectorHitNumbers_end() const;
  podio::RelationRange<int> getSubDetectorHitNumbers() const;
  void addToTrackStates(edm4hep::TrackState);
  unsigned int trackStates_size() const;
  edm4hep::TrackState getTrackStates(unsigned int) const;
  std::vector<edm4hep::TrackState>::const_iterator trackStates_begin() const;
  std::vector<edm4hep::TrackState>::const_iterator trackStates_end() const;
  podio::RelationRange<edm4hep::TrackState> getTrackStates() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from TrackObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const Track& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstTrack& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const Track& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  TrackObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstTrack& value);

} // namespace edm4hep


#endif
