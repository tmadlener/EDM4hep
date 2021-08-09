// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/TrackerHit.h"
#include "edm4hep/TrackerHitConst.h"
#include "edm4hep/TrackerHitObj.h"
#include "edm4hep/TrackerHitData.h"
#include "edm4hep/TrackerHitCollection.h"


#include <ostream>

namespace edm4hep {


TrackerHit::TrackerHit() : m_obj(new TrackerHitObj()) {
  m_obj->acquire();
}

TrackerHit::TrackerHit(unsigned long long cellID, int type, int quality, float time, float eDep, float eDepError, float edx, edm4hep::Vector3d position, std::array<float, 6> covMatrix) : m_obj(new TrackerHitObj()) {
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

TrackerHit::TrackerHit(const TrackerHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

TrackerHit& TrackerHit::operator=(const TrackerHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

TrackerHit::TrackerHit( TrackerHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

TrackerHit TrackerHit::clone() const {
  return {new TrackerHitObj(*m_obj)};
}

TrackerHit::~TrackerHit() {
  if (m_obj) m_obj->release();
}
TrackerHit::operator ConstTrackerHit() const { return ConstTrackerHit(m_obj); }

const unsigned long long& TrackerHit::getCellID() const { return m_obj->data.cellID; }
const int& TrackerHit::getType() const { return m_obj->data.type; }
const int& TrackerHit::getQuality() const { return m_obj->data.quality; }
const float& TrackerHit::getTime() const { return m_obj->data.time; }
const float& TrackerHit::getEDep() const { return m_obj->data.eDep; }
const float& TrackerHit::getEDepError() const { return m_obj->data.eDepError; }
const float& TrackerHit::getEdx() const { return m_obj->data.edx; }
const edm4hep::Vector3d& TrackerHit::getPosition() const { return m_obj->data.position; }
const std::array<float, 6>& TrackerHit::getCovMatrix() const { return m_obj->data.covMatrix; }
const float& TrackerHit::getCovMatrix(size_t i) const { return m_obj->data.covMatrix.at(i); }


void TrackerHit::setCellID(unsigned long long value) { m_obj->data.cellID = value; }
void TrackerHit::setType(int value) { m_obj->data.type = value; }
void TrackerHit::setQuality(int value) { m_obj->data.quality = value; }
void TrackerHit::setTime(float value) { m_obj->data.time = value; }
void TrackerHit::setEDep(float value) { m_obj->data.eDep = value; }
void TrackerHit::setEDepError(float value) { m_obj->data.eDepError = value; }
void TrackerHit::setEdx(float value) { m_obj->data.edx = value; }
void TrackerHit::setPosition(edm4hep::Vector3d value) { m_obj->data.position = value; }
edm4hep::Vector3d& TrackerHit::position() { return m_obj->data.position; }
void TrackerHit::setCovMatrix(std::array<float, 6> value) { m_obj->data.covMatrix = value; }
void TrackerHit::setCovMatrix(size_t i, float value) { m_obj->data.covMatrix.at(i) = value; }
std::array<float, 6>& TrackerHit::covMatrix() { return m_obj->data.covMatrix; }


void TrackerHit::addToRawHits(edm4hep::ObjectID component) {
  m_obj->m_rawHits->push_back(component);
  m_obj->data.rawHits_end++;
}

std::vector<edm4hep::ObjectID>::const_iterator TrackerHit::rawHits_begin() const {
  auto ret_value = m_obj->m_rawHits->begin();
  std::advance(ret_value, m_obj->data.rawHits_begin);
  return ret_value;
}

std::vector<edm4hep::ObjectID>::const_iterator TrackerHit::rawHits_end() const {
  auto ret_value = m_obj->m_rawHits->begin();
  std::advance(ret_value, m_obj->data.rawHits_end);
  return ret_value;
}

unsigned int TrackerHit::rawHits_size() const {
  return m_obj->data.rawHits_end - m_obj->data.rawHits_begin;
}

edm4hep::ObjectID TrackerHit::getRawHits(unsigned int index) const {
  if (rawHits_size() > index) {
    return m_obj->m_rawHits->at(m_obj->data.rawHits_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<edm4hep::ObjectID> TrackerHit::getRawHits() const {
  auto begin = m_obj->m_rawHits->begin();
  std::advance(begin, m_obj->data.rawHits_begin);
  auto end = m_obj->m_rawHits->begin();
  std::advance(end, m_obj->data.rawHits_end);
  return {begin, end};
}






bool TrackerHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID TrackerHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool TrackerHit::operator==(const ConstTrackerHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstTrackerHit& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " type : " << value.getType() << '\n';
  o << " quality : " << value.getQuality() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " eDep : " << value.getEDep() << '\n';
  o << " eDepError : " << value.getEDepError() << '\n';
  o << " edx : " << value.getEdx() << '\n';
  o << " position : " << value.getPosition() << '\n';
  o << " covMatrix : ";
  for (size_t i = 0; i < 6; ++i) {
    o << value.getCovMatrix()[i] << "|";
  }
  o << '\n';


  o << " rawHits : ";
  for (unsigned i = 0; i < value.rawHits_size(); ++i) {
    o << value.getRawHits(i) << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

