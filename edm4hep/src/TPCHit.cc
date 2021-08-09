// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/TPCHit.h"
#include "edm4hep/TPCHitConst.h"
#include "edm4hep/TPCHitObj.h"
#include "edm4hep/TPCHitData.h"
#include "edm4hep/TPCHitCollection.h"


#include <ostream>

namespace edm4hep {


TPCHit::TPCHit() : m_obj(new TPCHitObj()) {
  m_obj->acquire();
}

TPCHit::TPCHit(unsigned long long cellID, int quality, float time, float charge) : m_obj(new TPCHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.charge = charge;
}

TPCHit::TPCHit(const TPCHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

TPCHit& TPCHit::operator=(const TPCHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

TPCHit::TPCHit( TPCHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

TPCHit TPCHit::clone() const {
  return {new TPCHitObj(*m_obj)};
}

TPCHit::~TPCHit() {
  if (m_obj) m_obj->release();
}
TPCHit::operator ConstTPCHit() const { return ConstTPCHit(m_obj); }

const unsigned long long& TPCHit::getCellID() const { return m_obj->data.cellID; }
const int& TPCHit::getQuality() const { return m_obj->data.quality; }
const float& TPCHit::getTime() const { return m_obj->data.time; }
const float& TPCHit::getCharge() const { return m_obj->data.charge; }


void TPCHit::setCellID(unsigned long long value) { m_obj->data.cellID = value; }
void TPCHit::setQuality(int value) { m_obj->data.quality = value; }
void TPCHit::setTime(float value) { m_obj->data.time = value; }
void TPCHit::setCharge(float value) { m_obj->data.charge = value; }


void TPCHit::addToRawDataWords(int component) {
  m_obj->m_rawDataWords->push_back(component);
  m_obj->data.rawDataWords_end++;
}

std::vector<int>::const_iterator TPCHit::rawDataWords_begin() const {
  auto ret_value = m_obj->m_rawDataWords->begin();
  std::advance(ret_value, m_obj->data.rawDataWords_begin);
  return ret_value;
}

std::vector<int>::const_iterator TPCHit::rawDataWords_end() const {
  auto ret_value = m_obj->m_rawDataWords->begin();
  std::advance(ret_value, m_obj->data.rawDataWords_end);
  return ret_value;
}

unsigned int TPCHit::rawDataWords_size() const {
  return m_obj->data.rawDataWords_end - m_obj->data.rawDataWords_begin;
}

int TPCHit::getRawDataWords(unsigned int index) const {
  if (rawDataWords_size() > index) {
    return m_obj->m_rawDataWords->at(m_obj->data.rawDataWords_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<int> TPCHit::getRawDataWords() const {
  auto begin = m_obj->m_rawDataWords->begin();
  std::advance(begin, m_obj->data.rawDataWords_begin);
  auto end = m_obj->m_rawDataWords->begin();
  std::advance(end, m_obj->data.rawDataWords_end);
  return {begin, end};
}






bool TPCHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID TPCHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool TPCHit::operator==(const ConstTPCHit& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstTPCHit& value) {
  o << " id: " << value.id() << '\n';
  o << " cellID : " << value.getCellID() << '\n';
  o << " quality : " << value.getQuality() << '\n';
  o << " time : " << value.getTime() << '\n';
  o << " charge : " << value.getCharge() << '\n';


  o << " rawDataWords : ";
  for (unsigned i = 0; i < value.rawDataWords_size(); ++i) {
    o << value.getRawDataWords(i) << " ";
  }
  o << '\n';

  return o;
}

} // namespace edm4hep

