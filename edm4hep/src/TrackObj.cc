// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackObj.h"
#include "edm4hep/Track.h"
namespace edm4hep {

TrackObj::TrackObj() :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(),
  m_trackerHits(new std::vector<::edm4hep::ConstTrackerHit>()),
  m_tracks(new std::vector<::edm4hep::ConstTrack>()),
  m_subDetectorHitNumbers(new std::vector<int>()),
  m_trackStates(new std::vector<edm4hep::TrackState>())
{  }

TrackObj::TrackObj(const podio::ObjectID id_, TrackData data_) :
  ObjBase{id_, 0}, data(data_)
{  }

TrackObj::TrackObj(const TrackObj& other) :
  ObjBase{{podio::ObjectID::untracked, podio::ObjectID::untracked}, 0},
  data(other.data),
  m_trackerHits(new std::vector<::edm4hep::ConstTrackerHit>(*(other.m_trackerHits))),
  m_tracks(new std::vector<::edm4hep::ConstTrack>(*(other.m_tracks))),
  m_subDetectorHitNumbers(new std::vector<int>(*(other.m_subDetectorHitNumbers))),
  m_trackStates(new std::vector<edm4hep::TrackState>(*(other.m_trackStates)))
{
}

TrackObj::~TrackObj() {
  if (id.index == podio::ObjectID::untracked) {
    delete m_trackerHits;
    delete m_tracks;
    delete m_subDetectorHitNumbers;
    delete m_trackStates;
  }

}
} // namespace edm4hep

