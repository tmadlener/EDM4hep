// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimTrackerHitCollection_H
#define EDM4HEP_SimTrackerHitCollection_H

// datamodel specific includes
#include "edm4hep/SimTrackerHitData.h"
#include "edm4hep/SimTrackerHit.h"
#include "edm4hep/SimTrackerHitObj.h"

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


using SimTrackerHitDataContainer = std::vector<SimTrackerHitData>;
using SimTrackerHitObjPointerContainer = std::deque<SimTrackerHitObj*>;

class SimTrackerHitCollectionIterator {
public:
  SimTrackerHitCollectionIterator(size_t index, const SimTrackerHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  SimTrackerHitCollectionIterator(const SimTrackerHitCollectionIterator&) = delete;
  SimTrackerHitCollectionIterator& operator=(const SimTrackerHitCollectionIterator&) = delete;

  bool operator!=(const SimTrackerHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  SimTrackerHit operator*();
  SimTrackerHit* operator->();
  SimTrackerHitCollectionIterator& operator++();

private:
  size_t m_index;
  SimTrackerHit m_object;
  const SimTrackerHitObjPointerContainer* m_collection;
};


class SimTrackerHitConstCollectionIterator {
public:
  SimTrackerHitConstCollectionIterator(size_t index, const SimTrackerHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  SimTrackerHitConstCollectionIterator(const SimTrackerHitConstCollectionIterator&) = delete;
  SimTrackerHitConstCollectionIterator& operator=(const SimTrackerHitConstCollectionIterator&) = delete;

  bool operator!=(const SimTrackerHitConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstSimTrackerHit operator*();
  ConstSimTrackerHit* operator->();
  SimTrackerHitConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstSimTrackerHit m_object;
  const SimTrackerHitObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class SimTrackerHitCollection : public podio::CollectionBase {

public:
  using const_iterator = SimTrackerHitConstCollectionIterator;
  using iterator = SimTrackerHitCollectionIterator;

  SimTrackerHitCollection();
  SimTrackerHitCollection(const SimTrackerHitCollection& ) = delete;
  SimTrackerHitCollection& operator=(const SimTrackerHitCollection& ) = delete;
//  SimTrackerHitCollection(SimTrackerHitVector* data, int collectionID);
  ~SimTrackerHitCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  SimTrackerHitCollection* operator->() { return (SimTrackerHitCollection*) this; }

  /// Append a new object to the collection, and return this object.
  SimTrackerHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  SimTrackerHit create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::SimTrackerHit"); }

  /// Returns the const object of given index
  ConstSimTrackerHit operator[](unsigned int index) const;
  /// Returns the object of a given index
  SimTrackerHit operator[](unsigned int index);
  /// Returns the const object of given index
  ConstSimTrackerHit at(unsigned int index) const;
  /// Returns the object of given index
  SimTrackerHit at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstSimTrackerHit object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (SimTrackerHitObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<SimTrackerHitData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<unsigned long long, arraysize> cellID() const;
  template<size_t arraysize>
  const std::array<float, arraysize> EDep() const;
  template<size_t arraysize>
  const std::array<float, arraysize> time() const;
  template<size_t arraysize>
  const std::array<float, arraysize> pathLength() const;
  template<size_t arraysize>
  const std::array<int, arraysize> quality() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3d, arraysize> position() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> momentum() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  SimTrackerHitObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstMCParticle>* m_rel_MCParticle; ///< Relation buffer for read / write

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  SimTrackerHitDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const SimTrackerHitCollection& v);

template<typename... Args>
SimTrackerHit SimTrackerHitCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new SimTrackerHitObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return SimTrackerHit(obj);
}

template<size_t arraysize>
const std::array<unsigned long long, arraysize> SimTrackerHitCollection::cellID() const {
  std::array<unsigned long long, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.cellID;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> SimTrackerHitCollection::EDep() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.EDep;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> SimTrackerHitCollection::time() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.time;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> SimTrackerHitCollection::pathLength() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.pathLength;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> SimTrackerHitCollection::quality() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.quality;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3d, arraysize> SimTrackerHitCollection::position() const {
  std::array<edm4hep::Vector3d, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.position;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> SimTrackerHitCollection::momentum() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.momentum;
  }
  return tmp;
}


} // namespace edm4hep


#endif
