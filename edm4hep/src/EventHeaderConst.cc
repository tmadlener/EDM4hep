// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/EventHeader.h"
#include "edm4hep/EventHeaderConst.h"
#include "edm4hep/EventHeaderObj.h"
#include "edm4hep/EventHeaderData.h"
#include "edm4hep/EventHeaderCollection.h"


#include <ostream>

namespace edm4hep {


ConstEventHeader::ConstEventHeader() : m_obj(new EventHeaderObj()) {
  m_obj->acquire();
}

ConstEventHeader::ConstEventHeader(int eventNumber, int runNumber, unsigned long long timeStamp, float weight) : m_obj(new EventHeaderObj()) {
  m_obj->acquire();
  m_obj->data.eventNumber = eventNumber;
  m_obj->data.runNumber = runNumber;
  m_obj->data.timeStamp = timeStamp;
  m_obj->data.weight = weight;
}

ConstEventHeader::ConstEventHeader(const ConstEventHeader& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

ConstEventHeader& ConstEventHeader::operator=(const ConstEventHeader& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

ConstEventHeader::ConstEventHeader( EventHeaderObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

ConstEventHeader ConstEventHeader::clone() const {
  return {new EventHeaderObj(*m_obj)};
}

ConstEventHeader::~ConstEventHeader() {
  if (m_obj) m_obj->release();
}
const int& ConstEventHeader::getEventNumber() const { return m_obj->data.eventNumber; }
const int& ConstEventHeader::getRunNumber() const { return m_obj->data.runNumber; }
const unsigned long long& ConstEventHeader::getTimeStamp() const { return m_obj->data.timeStamp; }
const float& ConstEventHeader::getWeight() const { return m_obj->data.weight; }






bool ConstEventHeader::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID ConstEventHeader::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool ConstEventHeader::operator==(const EventHeader& other) const {
  return m_obj == other.m_obj;
}

} // namespace edm4hep

