// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

// datamodel specific includes
#include "edm4hep/EventHeader.h"
#include "edm4hep/EventHeaderConst.h"
#include "edm4hep/EventHeaderObj.h"
#include "edm4hep/EventHeaderData.h"
#include "edm4hep/EventHeaderCollection.h"


#include <ostream>

namespace edm4hep {


EventHeader::EventHeader() : m_obj(new EventHeaderObj()) {
  m_obj->acquire();
}

EventHeader::EventHeader(int eventNumber, int runNumber, unsigned long long timeStamp, float weight) : m_obj(new EventHeaderObj()) {
  m_obj->acquire();
  m_obj->data.eventNumber = eventNumber;
  m_obj->data.runNumber = runNumber;
  m_obj->data.timeStamp = timeStamp;
  m_obj->data.weight = weight;
}

EventHeader::EventHeader(const EventHeader& other) : m_obj(other.m_obj) {
  m_obj->acquire();
}

EventHeader& EventHeader::operator=(const EventHeader& other) {
  if (m_obj) m_obj->release();
  m_obj = other.m_obj;
  return *this;
}

EventHeader::EventHeader( EventHeaderObj* obj) : m_obj(obj) {
  if (m_obj) m_obj->acquire();
}

EventHeader EventHeader::clone() const {
  return {new EventHeaderObj(*m_obj)};
}

EventHeader::~EventHeader() {
  if (m_obj) m_obj->release();
}
EventHeader::operator ConstEventHeader() const { return ConstEventHeader(m_obj); }

const int& EventHeader::getEventNumber() const { return m_obj->data.eventNumber; }
const int& EventHeader::getRunNumber() const { return m_obj->data.runNumber; }
const unsigned long long& EventHeader::getTimeStamp() const { return m_obj->data.timeStamp; }
const float& EventHeader::getWeight() const { return m_obj->data.weight; }


void EventHeader::setEventNumber(int value) { m_obj->data.eventNumber = value; }
void EventHeader::setRunNumber(int value) { m_obj->data.runNumber = value; }
void EventHeader::setTimeStamp(unsigned long long value) { m_obj->data.timeStamp = value; }
void EventHeader::setWeight(float value) { m_obj->data.weight = value; }







bool EventHeader::isAvailable() const {
  if (m_obj) {
    return true;
  }
  return false;
}

const podio::ObjectID EventHeader::getObjectID() const {
  if (m_obj) {
    return m_obj->id;
  }
  return podio::ObjectID{podio::ObjectID::invalid, podio::ObjectID::invalid};
}

bool EventHeader::operator==(const ConstEventHeader& other) const {
  return m_obj == other.m_obj;
}

std::ostream& operator<<(std::ostream& o, const ConstEventHeader& value) {
  o << " id: " << value.id() << '\n';
  o << " eventNumber : " << value.getEventNumber() << '\n';
  o << " runNumber : " << value.getRunNumber() << '\n';
  o << " timeStamp : " << value.getTimeStamp() << '\n';
  o << " weight : " << value.getWeight() << '\n';



  return o;
}

} // namespace edm4hep

