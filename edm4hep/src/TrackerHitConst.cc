// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/TrackerHit.h"
#include "edm4hep/TrackerHitConst.h"
#include "edm4hep/TrackerHitObj.h"
#include "edm4hep/TrackerHitData.h"
#include "edm4hep/TrackerHitCollection.h"


#include <ostream>

namespace edm4hep {


ConstTrackerHit::ConstTrackerHit() : m_obj(new TrackerHitObj()) {
  m_obj->acquire();
}

ConstTrackerHit::ConstTrackerHit(unsigned long long cellID, int type, int quality, float time, float eDep, float eDepError, float edx, edm4hep::Vector3d position, std::array<float, 6> covMatrix) : m_obj(new TrackerHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.type = type;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.eDep = eDep;
  m_obj->data.eDepError = eDepError;
  m_obj->data.edx = edx;
  m_obj->data.position = position;
  m_obj->data.covMatrix = covMatrix;
}

ConstTrackerHit::ConstTrackerHit(const ConstTrackerHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstTrackerHit& ConstTrackerHit::operator=(const ConstTrackerHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstTrackerHit::ConstTrackerHit( TrackerHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstTrackerHit ConstTrackerHit::clone() const {
  return {new TrackerHitObj(*m_obj)};
}

ConstTrackerHit::~ConstTrackerHit() {
  if (m_obj) m_obj->release();
}
const unsigned long long& ConstTrackerHit::getCellID() const { return m_obj->data.cellID; }
const int& ConstTrackerHit::getType() const { return m_obj->data.type; }
const int& ConstTrackerHit::getQuality() const { return m_obj->data.quality; }
const float& ConstTrackerHit::getTime() const { return m_obj->data.time; }
const float& ConstTrackerHit::getEDep() const { return m_obj->data.eDep; }
const float& ConstTrackerHit::getEDepError() const { return m_obj->data.eDepError; }
const float& ConstTrackerHit::getEdx() const { return m_obj->data.edx; }
const edm4hep::Vector3d& ConstTrackerHit::getPosition() const { return m_obj->data.position; }
const std::array<float, 6>& ConstTrackerHit::getCovMatrix() const { return m_obj->data.covMatrix; }
const float& ConstTrackerHit::getCovMatrix(size_t i) const { return m_obj->data.covMatrix.at(i); }



std::vector<edm4hep::ObjectID>::const_iterator ConstTrackerHit::rawHits_begin() const {
  auto ret_value = m_obj->m_rawHits->begin();
  std::advance(ret_value, m_obj->data.rawHits_begin);
  return ret_value;
}

std::vector<edm4hep::ObjectID>::const_iterator ConstTrackerHit::rawHits_end() const {
  auto ret_value = m_obj->m_rawHits->begin();
  std::advance(ret_value, m_obj->data.rawHits_end);
  return ret_value;
}

unsigned int ConstTrackerHit::rawHits_size() const {
  return m_obj->data.rawHits_end - m_obj->data.rawHits_begin;
}

edm4hep::ObjectID ConstTrackerHit::getRawHits(unsigned int index) const {
  if (rawHits_size() > index) {
    return m_obj->m_rawHits->at(m_obj->data.rawHits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::ObjectID> ConstTrackerHit::getRawHits() const {
  auto begin = m_obj->m_rawHits->begin();
  std::advance(begin, m_obj->data.rawHits_begin);
  auto end = m_obj->m_rawHits->begin();
  std::advance(end, m_obj->data.rawHits_end);
  return {begin, end};
}





bool ConstTrackerHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstTrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstTrackerHit::operator==(const TrackerHit& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

