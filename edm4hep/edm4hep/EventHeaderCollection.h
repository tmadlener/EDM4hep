// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_EventHeaderCollection_H
#define EDM4HEP_EventHeaderCollection_H

// datamodel specific includes
#include "edm4hep/EventHeaderData.h"
#include "edm4hep/EventHeader.h"
#include "edm4hep/EventHeaderObj.h"

// podio specific includes
#include "podio/ICollectionProvider.h"
#include "podio/CollectionBase.h"
#include "podio/CollectionIDTable.h"

#include <string>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <ostream>

namespace edm4hep {


using EventHeaderDataContainer = std::vector<EventHeaderData>;
using EventHeaderObjPointerContainer = std::deque<EventHeaderObj*>;

class EventHeaderCollectionIterator {
public:
  EventHeaderCollectionIterator(size_t index, const EventHeaderObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  EventHeaderCollectionIterator(const EventHeaderCollectionIterator&) = delete;
  EventHeaderCollectionIterator& operator=(const EventHeaderCollectionIterator&) = delete;

  bool operator!=(const EventHeaderCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  EventHeader operator*();
  EventHeader* operator->();
  EventHeaderCollectionIterator& operator++();

private:
  size_t m_index;
  EventHeader m_object;
  const EventHeaderObjPointerContainer* m_collection;
};


class EventHeaderConstCollectionIterator {
public:
  EventHeaderConstCollectionIterator(size_t index, const EventHeaderObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  EventHeaderConstCollectionIterator(const EventHeaderConstCollectionIterator&) = delete;
  EventHeaderConstCollectionIterator& operator=(const EventHeaderConstCollectionIterator&) = delete;

  bool operator!=(const EventHeaderConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstEventHeader operator*();
  ConstEventHeader* operator->();
  EventHeaderConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstEventHeader m_object;
  const EventHeaderObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class EventHeaderCollection : public podio::CollectionBase {

public:
  using const_iterator = EventHeaderConstCollectionIterator;
  using iterator = EventHeaderCollectionIterator;

  EventHeaderCollection();
  EventHeaderCollection(const EventHeaderCollection& ) = delete;
  EventHeaderCollection& operator=(const EventHeaderCollection& ) = delete;
//  EventHeaderCollection(EventHeaderVector* data, int collectionID);
  ~EventHeaderCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  EventHeaderCollection* operator->() { return (EventHeaderCollection*) this; }

  /// Append a new object to the collection, and return this object.
  EventHeader create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  EventHeader create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::EventHeader"); }

  /// Returns the const object of given index
  ConstEventHeader operator[](unsigned int index) const;
  /// Returns the object of a given index
  EventHeader operator[](unsigned int index);
  /// Returns the const object of given index
  ConstEventHeader at(unsigned int index) const;
  /// Returns the object of given index
  EventHeader at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstEventHeader object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (EventHeaderObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
    );
    m_isValid = true;
  };

  unsigned getID() const override final {
    return m_collectionID;
  }

  bool isValid() const override final {
    return m_isValid;
  }

  // support for the iterator protocol
  iterator begin() {
    return iterator(0, &m_entries);
  }
  const_iterator begin() const {
    return const_iterator(0, &m_entries);
  }
  iterator end() {
    return iterator(m_entries.size(), &m_entries);
  }
  const_iterator end() const {
    return const_iterator(m_entries.size(), &m_entries);
  }

  /// returns the address of the pointer to the data buffer
  void* getBufferAddress() override final { return (void*)&m_data; }

  /// Returns the pointer to the data buffer
  std::vector<EventHeaderData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<int, arraysize> eventNumber() const;
  template<size_t arraysize>
  const std::array<int, arraysize> runNumber() const;
  template<size_t arraysize>
  const std::array<unsigned long long, arraysize> timeStamp() const;
  template<size_t arraysize>
  const std::array<float, arraysize> weight() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  EventHeaderObjPointerContainer m_entries;

  // members to handle 1-to-N-relations

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  EventHeaderDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const EventHeaderCollection& v);

template<typename... Args>
EventHeader EventHeaderCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new EventHeaderObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return EventHeader(obj);
}

template<size_t arraysize>
const std::array<int, arraysize> EventHeaderCollection::eventNumber() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.eventNumber;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> EventHeaderCollection::runNumber() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.runNumber;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<unsigned long long, arraysize> EventHeaderCollection::timeStamp() const {
  std::array<unsigned long long, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.timeStamp;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> EventHeaderCollection::weight() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.weight;
  }
  return tmp;
}


} // namespace edm4hep


#endif
