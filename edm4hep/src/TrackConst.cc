// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/Track.h"
#include "edm4hep/TrackConst.h"
#include "edm4hep/TrackObj.h"
#include "edm4hep/TrackData.h"
#include "edm4hep/TrackCollection.h"


#include <ostream>

namespace edm4hep {


ConstTrack::ConstTrack() : m_obj(new TrackObj()) {
  m_obj->acquire();
}

ConstTrack::ConstTrack(int type, float chi2, int ndf, float dEdx, float dEdxError, float radiusOfInnermostHit) : m_obj(new TrackObj()) {
  m_obj->acquire();
  m_obj->data.type = type;
  m_obj->data.chi2 = chi2;
  m_obj->data.ndf = ndf;
  m_obj->data.dEdx = dEdx;
  m_obj->data.dEdxError = dEdxError;
  m_obj->data.radiusOfInnermostHit = radiusOfInnermostHit;
}

ConstTrack::ConstTrack(const ConstTrack& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstTrack& ConstTrack::operator=(const ConstTrack& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstTrack::ConstTrack( TrackObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstTrack ConstTrack::clone() const {
  return {new TrackObj(*m_obj)};
}

ConstTrack::~ConstTrack() {
  if (m_obj) m_obj->release();
}
const int& ConstTrack::getType() const { return m_obj->data.type; }
const float& ConstTrack::getChi2() const { return m_obj->data.chi2; }
const int& ConstTrack::getNdf() const { return m_obj->data.ndf; }
const float& ConstTrack::getDEdx() const { return m_obj->data.dEdx; }
const float& ConstTrack::getDEdxError() const { return m_obj->data.dEdxError; }
const float& ConstTrack::getRadiusOfInnermostHit() const { return m_obj->data.radiusOfInnermostHit; }



std::vector<::edm4hep::ConstTrackerHit>::const_iterator ConstTrack::trackerHits_begin() const {
  auto ret_value = m_obj->m_trackerHits->begin();
  std::advance(ret_value, m_obj->data.trackerHits_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstTrackerHit>::const_iterator ConstTrack::trackerHits_end() const {
  auto ret_value = m_obj->m_trackerHits->begin();
  std::advance(ret_value, m_obj->data.trackerHits_end);
  return ret_value;
}

unsigned int ConstTrack::trackerHits_size() const {
  return m_obj->data.trackerHits_end - m_obj->data.trackerHits_begin;
}

::edm4hep::ConstTrackerHit ConstTrack::getTrackerHits(unsigned int index) const {
  if (trackerHits_size() > index) {
    return m_obj->m_trackerHits->at(m_obj->data.trackerHits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstTrackerHit> ConstTrack::getTrackerHits() const {
  auto begin = m_obj->m_trackerHits->begin();
  std::advance(begin, m_obj->data.trackerHits_begin);
  auto end = m_obj->m_trackerHits->begin();
  std::advance(end, m_obj->data.trackerHits_end);
  return {begin, end};
}


std::vector<::edm4hep::ConstTrack>::const_iterator ConstTrack::tracks_begin() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstTrack>::const_iterator ConstTrack::tracks_end() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_end);
  return ret_value;
}

unsigned int ConstTrack::tracks_size() const {
  return m_obj->data.tracks_end - m_obj->data.tracks_begin;
}

::edm4hep::ConstTrack ConstTrack::getTracks(unsigned int index) const {
  if (tracks_size() > index) {
    return m_obj->m_tracks->at(m_obj->data.tracks_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstTrack> ConstTrack::getTracks() const {
  auto begin = m_obj->m_tracks->begin();
  std::advance(begin, m_obj->data.tracks_begin);
  auto end = m_obj->m_tracks->begin();
  std::advance(end, m_obj->data.tracks_end);
  return {begin, end};
}


std::vector<int>::const_iterator ConstTrack::subDetectorHitNumbers_begin() const {
  auto ret_value = m_obj->m_subDetectorHitNumbers->begin();
  std::advance(ret_value, m_obj->data.subDetectorHitNumbers_begin);
  return ret_value;
}

std::vector<int>::const_iterator ConstTrack::subDetectorHitNumbers_end() const {
  auto ret_value = m_obj->m_subDetectorHitNumbers->begin();
  std::advance(ret_value, m_obj->data.subDetectorHitNumbers_end);
  return ret_value;
}

unsigned int ConstTrack::subDetectorHitNumbers_size() const {
  return m_obj->data.subDetectorHitNumbers_end - m_obj->data.subDetectorHitNumbers_begin;
}

int ConstTrack::getSubDetectorHitNumbers(unsigned int index) const {
  if (subDetectorHitNumbers_size() > index) {
    return m_obj->m_subDetectorHitNumbers->at(m_obj->data.subDetectorHitNumbers_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<int> ConstTrack::getSubDetectorHitNumbers() const {
  auto begin = m_obj->m_subDetectorHitNumbers->begin();
  std::advance(begin, m_obj->data.subDetectorHitNumbers_begin);
  auto end = m_obj->m_subDetectorHitNumbers->begin();
  std::advance(end, m_obj->data.subDetectorHitNumbers_end);
  return {begin, end};
}


std::vector<edm4hep::TrackState>::const_iterator ConstTrack::trackStates_begin() const {
  auto ret_value = m_obj->m_trackStates->begin();
  std::advance(ret_value, m_obj->data.trackStates_begin);
  return ret_value;
}

std::vector<edm4hep::TrackState>::const_iterator ConstTrack::trackStates_end() const {
  auto ret_value = m_obj->m_trackStates->begin();
  std::advance(ret_value, m_obj->data.trackStates_end);
  return ret_value;
}

unsigned int ConstTrack::trackStates_size() const {
  return m_obj->data.trackStates_end - m_obj->data.trackStates_begin;
}

edm4hep::TrackState ConstTrack::getTrackStates(unsigned int index) const {
  if (trackStates_size() > index) {
    return m_obj->m_trackStates->at(m_obj->data.trackStates_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::TrackState> ConstTrack::getTrackStates() const {
  auto begin = m_obj->m_trackStates->begin();
  std::advance(begin, m_obj->data.trackStates_begin);
  auto end = m_obj->m_trackStates->begin();
  std::advance(end, m_obj->data.trackStates_end);
  return {begin, end};
}





bool ConstTrack::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstTrack::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstTrack::operator==(const Track& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

