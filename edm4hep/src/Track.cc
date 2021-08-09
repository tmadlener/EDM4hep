// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/Track.h"
#include "edm4hep/TrackConst.h"
#include "edm4hep/TrackObj.h"
#include "edm4hep/TrackData.h"
#include "edm4hep/TrackCollection.h"


#include <ostream>

namespace edm4hep {


Track::Track() : m_obj(new TrackObj()) {
  m_obj->acquire();
}

Track::Track(int type, float chi2, int ndf, float dEdx, float dEdxError, float radiusOfInnermostHit) : m_obj(new TrackObj()) {
  m_obj->acquire();
  m_obj->data.type = type;
  m_obj->data.chi2 = chi2;
  m_obj->data.ndf = ndf;
  m_obj->data.dEdx = dEdx;
  m_obj->data.dEdxError = dEdxError;
  m_obj->data.radiusOfInnermostHit = radiusOfInnermostHit;
}

Track::Track(const Track& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

Track& Track::operator=(const Track& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

Track::Track( TrackObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

Track Track::clone() const {
  return {new TrackObj(*m_obj)};
}

Track::~Track() {
  if (m_obj) m_obj->release();
}
Track::operator ConstTrack() const { return ConstTrack(m_obj); }

const int& Track::getType() const { return m_obj->data.type; }
const float& Track::getChi2() const { return m_obj->data.chi2; }
const int& Track::getNdf() const { return m_obj->data.ndf; }
const float& Track::getDEdx() const { return m_obj->data.dEdx; }
const float& Track::getDEdxError() const { return m_obj->data.dEdxError; }
const float& Track::getRadiusOfInnermostHit() const { return m_obj->data.radiusOfInnermostHit; }


void Track::setType(int value) { m_obj->data.type = value; }
void Track::setChi2(float value) { m_obj->data.chi2 = value; }
void Track::setNdf(int value) { m_obj->data.ndf = value; }
void Track::setDEdx(float value) { m_obj->data.dEdx = value; }
void Track::setDEdxError(float value) { m_obj->data.dEdxError = value; }
void Track::setRadiusOfInnermostHit(float value) { m_obj->data.radiusOfInnermostHit = value; }


void Track::addToTrackerHits(::edm4hep::ConstTrackerHit component) {
  m_obj->m_trackerHits->push_back(component);
  m_obj->data.trackerHits_end++;
}

std::vector<::edm4hep::ConstTrackerHit>::const_iterator Track::trackerHits_begin() const {
  auto ret_value = m_obj->m_trackerHits->begin();
  std::advance(ret_value, m_obj->data.trackerHits_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstTrackerHit>::const_iterator Track::trackerHits_end() const {
  auto ret_value = m_obj->m_trackerHits->begin();
  std::advance(ret_value, m_obj->data.trackerHits_end);
  return ret_value;
}

unsigned int Track::trackerHits_size() const {
  return m_obj->data.trackerHits_end - m_obj->data.trackerHits_begin;
}

::edm4hep::ConstTrackerHit Track::getTrackerHits(unsigned int index) const {
  if (trackerHits_size() > index) {
    return m_obj->m_trackerHits->at(m_obj->data.trackerHits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstTrackerHit> Track::getTrackerHits() const {
  auto begin = m_obj->m_trackerHits->begin();
  std::advance(begin, m_obj->data.trackerHits_begin);
  auto end = m_obj->m_trackerHits->begin();
  std::advance(end, m_obj->data.trackerHits_end);
  return {begin, end};
}

void Track::addToTracks(::edm4hep::ConstTrack component) {
  m_obj->m_tracks->push_back(component);
  m_obj->data.tracks_end++;
}

std::vector<::edm4hep::ConstTrack>::const_iterator Track::tracks_begin() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_begin);
  return ret_value;
}

std::vector<::edm4hep::ConstTrack>::const_iterator Track::tracks_end() const {
  auto ret_value = m_obj->m_tracks->begin();
  std::advance(ret_value, m_obj->data.tracks_end);
  return ret_value;
}

unsigned int Track::tracks_size() const {
  return m_obj->data.tracks_end - m_obj->data.tracks_begin;
}

::edm4hep::ConstTrack Track::getTracks(unsigned int index) const {
  if (tracks_size() > index) {
    return m_obj->m_tracks->at(m_obj->data.tracks_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<::edm4hep::ConstTrack> Track::getTracks() const {
  auto begin = m_obj->m_tracks->begin();
  std::advance(begin, m_obj->data.tracks_begin);
  auto end = m_obj->m_tracks->begin();
  std::advance(end, m_obj->data.tracks_end);
  return {begin, end};
}

void Track::addToSubDetectorHitNumbers(int component) {
  m_obj->m_subDetectorHitNumbers->push_back(component);
  m_obj->data.subDetectorHitNumbers_end++;
}

std::vector<int>::const_iterator Track::subDetectorHitNumbers_begin() const {
  auto ret_value = m_obj->m_subDetectorHitNumbers->begin();
  std::advance(ret_value, m_obj->data.subDetectorHitNumbers_begin);
  return ret_value;
}

std::vector<int>::const_iterator Track::subDetectorHitNumbers_end() const {
  auto ret_value = m_obj->m_subDetectorHitNumbers->begin();
  std::advance(ret_value, m_obj->data.subDetectorHitNumbers_end);
  return ret_value;
}

unsigned int Track::subDetectorHitNumbers_size() const {
  return m_obj->data.subDetectorHitNumbers_end - m_obj->data.subDetectorHitNumbers_begin;
}

int Track::getSubDetectorHitNumbers(unsigned int index) const {
  if (subDetectorHitNumbers_size() > index) {
    return m_obj->m_subDetectorHitNumbers->at(m_obj->data.subDetectorHitNumbers_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<int> Track::getSubDetectorHitNumbers() const {
  auto begin = m_obj->m_subDetectorHitNumbers->begin();
  std::advance(begin, m_obj->data.subDetectorHitNumbers_begin);
  auto end = m_obj->m_subDetectorHitNumbers->begin();
  std::advance(end, m_obj->data.subDetectorHitNumbers_end);
  return {begin, end};
}

void Track::addToTrackStates(edm4hep::TrackState component) {
  m_obj->m_trackStates->push_back(component);
  m_obj->data.trackStates_end++;
}

std::vector<edm4hep::TrackState>::const_iterator Track::trackStates_begin() const {
  auto ret_value = m_obj->m_trackStates->begin();
  std::advance(ret_value, m_obj->data.trackStates_begin);
  return ret_value;
}

std::vector<edm4hep::TrackState>::const_iterator Track::trackStates_end() const {
  auto ret_value = m_obj->m_trackStates->begin();
  std::advance(ret_value, m_obj->data.trackStates_end);
  return ret_value;
}

unsigned int Track::trackStates_size() const {
  return m_obj->data.trackStates_end - m_obj->data.trackStates_begin;
}

edm4hep::TrackState Track::getTrackStates(unsigned int index) const {
  if (trackStates_size() > index) {
    return m_obj->m_trackStates->at(m_obj->data.trackStates_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::TrackState> Track::getTrackStates() const {
  auto begin = m_obj->m_trackStates->begin();
  std::advance(begin, m_obj->data.trackStates_begin);
  auto end = m_obj->m_trackStates->begin();
  std::advance(end, m_obj->data.trackStates_end);
  return {begin, end};
}






bool Track::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID Track::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool Track::operator==(const ConstTrack& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstTrack& value) {
  o << " id: " << value.id() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " chi2 : " << value.getChi2() << '\n';
  o << " ndf : " << value.getNdf() << '\n';
  o << " dEdx : " << value.getDEdx() << '\n';
  o << " dEdxError : " << value.getDEdxError() << '\n';
  o << " radiusOfInnermostHit : " << value.getRadiusOfInnermostHit() << '\n';


  o << " trackerHits : ";
  for (unsigned i = 0; i < value.trackerHits_size(); ++i) {
    o << value.getTrackerHits(i) << " ";
  }
  o << '\n';
  o << " tracks : ";
  for (unsigned i = 0; i < value.tracks_size(); ++i) {
    o << value.getTracks(i).id() << " ";
  }
  o << '\n';
  o << " subDetectorHitNumbers : ";
  for (unsigned i = 0; i < value.subDetectorHitNumbers_size(); ++i) {
    o << value.getSubDetectorHitNumbers(i) << " ";
  }
  o << '\n';
  o << " trackStates : ";
  for (unsigned i = 0; i < value.trackStates_size(); ++i) {
    o << value.getTrackStates(i) << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

