// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackerHitCollection_H
#define EDM4HEP_TrackerHitCollection_H

// datamodel specific includes
#include "edm4hep/TrackerHitData.h"
#include "edm4hep/TrackerHit.h"
#include "edm4hep/TrackerHitObj.h"

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


using TrackerHitDataContainer = std::vector<TrackerHitData>;
using TrackerHitObjPointerContainer = std::deque<TrackerHitObj*>;

class TrackerHitCollectionIterator {
public:
  TrackerHitCollectionIterator(size_t index, const TrackerHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  TrackerHitCollectionIterator(const TrackerHitCollectionIterator&) = delete;
  TrackerHitCollectionIterator& operator=(const TrackerHitCollectionIterator&) = delete;

  bool operator!=(const TrackerHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  TrackerHit operator*();
  TrackerHit* operator->();
  TrackerHitCollectionIterator& operator++();

private:
  size_t m_index;
  TrackerHit m_object;
  const TrackerHitObjPointerContainer* m_collection;
};


class TrackerHitConstCollectionIterator {
public:
  TrackerHitConstCollectionIterator(size_t index, const TrackerHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  TrackerHitConstCollectionIterator(const TrackerHitConstCollectionIterator&) = delete;
  TrackerHitConstCollectionIterator& operator=(const TrackerHitConstCollectionIterator&) = delete;

  bool operator!=(const TrackerHitConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstTrackerHit operator*();
  ConstTrackerHit* operator->();
  TrackerHitConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstTrackerHit m_object;
  const TrackerHitObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class TrackerHitCollection : public podio::CollectionBase {

public:
  using const_iterator = TrackerHitConstCollectionIterator;
  using iterator = TrackerHitCollectionIterator;

  TrackerHitCollection();
  TrackerHitCollection(const TrackerHitCollection& ) = delete;
  TrackerHitCollection& operator=(const TrackerHitCollection& ) = delete;
//  TrackerHitCollection(TrackerHitVector* data, int collectionID);
  ~TrackerHitCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  TrackerHitCollection* operator->() { return (TrackerHitCollection*) this; }

  /// Append a new object to the collection, and return this object.
  TrackerHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  TrackerHit create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::TrackerHit"); }

  /// Returns the const object of given index
  ConstTrackerHit operator[](unsigned int index) const;
  /// Returns the object of a given index
  TrackerHit operator[](unsigned int index);
  /// Returns the const object of given index
  ConstTrackerHit at(unsigned int index) const;
  /// Returns the object of given index
  TrackerHit at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstTrackerHit object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (TrackerHitObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<TrackerHitData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<unsigned long long, arraysize> cellID() const;
  template<size_t arraysize>
  const std::array<int, arraysize> type() const;
  template<size_t arraysize>
  const std::array<int, arraysize> quality() const;
  template<size_t arraysize>
  const std::array<float, arraysize> time() const;
  template<size_t arraysize>
  const std::array<float, arraysize> eDep() const;
  template<size_t arraysize>
  const std::array<float, arraysize> eDepError() const;
  template<size_t arraysize>
  const std::array<float, arraysize> edx() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3d, arraysize> position() const;
  template<size_t arraysize>
  const std::array<std::array<float, 6>, arraysize> covMatrix() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  TrackerHitObjPointerContainer m_entries;

  // members to handle 1-to-N-relations

  // members to handle vector members
  std::vector<edm4hep::ObjectID>* m_vec_rawHits; /// combined vector of all objects in collection
  std::vector<std::vector<edm4hep::ObjectID>*> m_vecs_rawHits{}; /// pointers to individual member vectors
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  TrackerHitDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const TrackerHitCollection& v);

template<typename... Args>
TrackerHit TrackerHitCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new TrackerHitObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return TrackerHit(obj);
}

template<size_t arraysize>
const std::array<unsigned long long, arraysize> TrackerHitCollection::cellID() const {
  std::array<unsigned long long, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.cellID;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> TrackerHitCollection::type() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.type;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> TrackerHitCollection::quality() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.quality;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TrackerHitCollection::time() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.time;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TrackerHitCollection::eDep() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.eDep;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TrackerHitCollection::eDepError() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.eDepError;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TrackerHitCollection::edx() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.edx;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3d, arraysize> TrackerHitCollection::position() const {
  std::array<edm4hep::Vector3d, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.position;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<std::array<float, 6>, arraysize> TrackerHitCollection::covMatrix() const {
  std::array<std::array<float, 6>, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.covMatrix;
  }
  return tmp;
}


} // namespace edm4hep


#endif
