// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/EventHeaderCollection.h"


// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


EventHeaderCollection::EventHeaderCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_data(new EventHeaderDataContainer()) {
}

EventHeaderCollection::~EventHeaderCollection() {
  clear();
  if (m_data) delete m_data;
}

ConstEventHeader EventHeaderCollection::operator[](unsigned int index) const {
  return ConstEventHeader(m_entries[index]);
}

ConstEventHeader EventHeaderCollection::at(unsigned int index) const {
  return ConstEventHeader(m_entries.at(index));
}

EventHeader EventHeaderCollection::operator[](unsigned int index) {
  return EventHeader(m_entries[index]);
}

EventHeader EventHeaderCollection::at(unsigned int index) {
  return EventHeader(m_entries.at(index));
}

size_t EventHeaderCollection::size() const {
  return m_entries.size();
}

EventHeader EventHeaderCollection::create() {
  auto obj = m_entries.emplace_back(new EventHeaderObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return EventHeader(obj);
}

void EventHeaderCollection::clear() {
  m_data->clear();
  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void EventHeaderCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }


}

void EventHeaderCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new EventHeaderObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool EventHeaderCollection::setReferences(const podio::ICollectionProvider* ) {

  return true; //TODO: check success
}

void EventHeaderCollection::push_back(ConstEventHeader object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void EventHeaderCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<EventHeaderDataContainer*>(address);
}

EventHeader EventHeaderCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

EventHeader* EventHeaderCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

EventHeaderCollectionIterator& EventHeaderCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstEventHeader EventHeaderConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstEventHeader* EventHeaderConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

EventHeaderConstCollectionIterator& EventHeaderConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const EventHeaderCollection& v) {
  const auto old_flags = o.flags();
  o << "          id: eventNumber:   runNumber:   timeStamp:      weight:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getEventNumber() << " "
      << std::setw(12) << v[i].getRunNumber() << " "
      << std::setw(12) << v[i].getTimeStamp() << " "
      << std::setw(12) << v[i].getWeight() << " "
      << std::endl;




  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

