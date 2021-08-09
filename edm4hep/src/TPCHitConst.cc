// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/TPCHit.h"
#include "edm4hep/TPCHitConst.h"
#include "edm4hep/TPCHitObj.h"
#include "edm4hep/TPCHitData.h"
#include "edm4hep/TPCHitCollection.h"


#include <ostream>

namespace edm4hep {


ConstTPCHit::ConstTPCHit() : m_obj(new TPCHitObj()) {
  m_obj->acquire();
}

ConstTPCHit::ConstTPCHit(unsigned long long cellID, int quality, float time, float charge) : m_obj(new TPCHitObj()) {
  m_obj->acquire();
  m_obj->data.cellID = cellID;
  m_obj->data.quality = quality;
  m_obj->data.time = time;
  m_obj->data.charge = charge;
}

ConstTPCHit::ConstTPCHit(const ConstTPCHit& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstTPCHit& ConstTPCHit::operator=(const ConstTPCHit& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstTPCHit::ConstTPCHit( TPCHitObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstTPCHit ConstTPCHit::clone() const {
  return {new TPCHitObj(*m_obj)};
}

ConstTPCHit::~ConstTPCHit() {
  if (m_obj) m_obj->release();
}
const unsigned long long& ConstTPCHit::getCellID() const { return m_obj->data.cellID; }
const int& ConstTPCHit::getQuality() const { return m_obj->data.quality; }
const float& ConstTPCHit::getTime() const { return m_obj->data.time; }
const float& ConstTPCHit::getCharge() const { return m_obj->data.charge; }



std::vector<int>::const_iterator ConstTPCHit::rawDataWords_begin() const {
  auto ret_value = m_obj->m_rawDataWords->begin();
  std::advance(ret_value, m_obj->data.rawDataWords_begin);
  return ret_value;
}

std::vector<int>::const_iterator ConstTPCHit::rawDataWords_end() const {
  auto ret_value = m_obj->m_rawDataWords->begin();
  std::advance(ret_value, m_obj->data.rawDataWords_end);
  return ret_value;
}

unsigned int ConstTPCHit::rawDataWords_size() const {
  return m_obj->data.rawDataWords_end - m_obj->data.rawDataWords_begin;
}

int ConstTPCHit::getRawDataWords(unsigned int index) const {
  if (rawDataWords_size() > index) {
    return m_obj->m_rawDataWords->at(m_obj->data.rawDataWords_begin + index);
  }
  throw std::out_of_range("index out of bounds for existing references");
}

podio::RelationRange<int> ConstTPCHit::getRawDataWords() const {
  auto begin = m_obj->m_rawDataWords->begin();
  std::advance(begin, m_obj->data.rawDataWords_begin);
  auto end = m_obj->m_rawDataWords->begin();
  std::advance(end, m_obj->data.rawDataWords_end);
  return {begin, end};
}





bool ConstTPCHit::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstTPCHit::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstTPCHit::operator==(const TPCHit& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

