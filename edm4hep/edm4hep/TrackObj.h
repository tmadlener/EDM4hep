// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackOBJ_H
#define EDM4HEP_TrackOBJ_H

// data model specific includes
#include "edm4hep/TrackData.h"
#include "edm4hep/TrackState.h"
#include "edm4hep/TrackerHit.h"
#include "podio/RelationRange.h"
#include <vector>

#include "podio/ObjBase.h"
#include <vector>


namespace edm4hep {

class Track;
class ConstTrack;

class TrackObj : public podio::ObjBase {
public:
  /// constructor
  TrackObj();
  /// copy constructor (does a deep-copy of relation containers)
  TrackObj(const TrackObj&);
  /// constructor from ObjectID and TrackData
  /// does not initialize the internal relation containers
  TrackObj(const podio::ObjectID id, TrackData data);
  /// No assignment operator
  TrackObj& operator=(const TrackObj&) = delete;
  virtual ~TrackObj();

public:
  TrackData data;
  std::vector<::edm4hep::ConstTrackerHit>* m_trackerHits{nullptr};
  std::vector<::edm4hep::ConstTrack>* m_tracks{nullptr};
  std::vector<int>* m_subDetectorHitNumbers{nullptr};
  std::vector<edm4hep::TrackState>* m_trackStates{nullptr};
};

} // namespace edm4hep


#endif
