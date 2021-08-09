// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RawCalorimeterHitCollection_H
#define EDM4HEP_RawCalorimeterHitCollection_H

// datamodel specific includes
#include "edm4hep/RawCalorimeterHitData.h"
#include "edm4hep/RawCalorimeterHit.h"
#include "edm4hep/RawCalorimeterHitObj.h"

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


using RawCalorimeterHitDataContainer = std::vector<RawCalorimeterHitData>;
using RawCalorimeterHitObjPointerContainer = std::deque<RawCalorimeterHitObj*>;

class RawCalorimeterHitCollectionIterator {
public:
  RawCalorimeterHitCollectionIterator(size_t index, const RawCalorimeterHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  RawCalorimeterHitCollectionIterator(const RawCalorimeterHitCollectionIterator&) = delete;
  RawCalorimeterHitCollectionIterator& operator=(const RawCalorimeterHitCollectionIterator&) = delete;

  bool operator!=(const RawCalorimeterHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  RawCalorimeterHit operator*();
  RawCalorimeterHit* operator->();
  RawCalorimeterHitCollectionIterator& operator++();

private:
  size_t m_index;
  RawCalorimeterHit m_object;
  const RawCalorimeterHitObjPointerContainer* m_collection;
};


class RawCalorimeterHitConstCollectionIterator {
public:
  RawCalorimeterHitConstCollectionIterator(size_t index, const RawCalorimeterHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  RawCalorimeterHitConstCollectionIterator(const RawCalorimeterHitConstCollectionIterator&) = delete;
  RawCalorimeterHitConstCollectionIterator& operator=(const RawCalorimeterHitConstCollectionIterator&) = delete;

  bool operator!=(const RawCalorimeterHitConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstRawCalorimeterHit operator*();
  ConstRawCalorimeterHit* operator->();
  RawCalorimeterHitConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstRawCalorimeterHit m_object;
  const RawCalorimeterHitObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class RawCalorimeterHitCollection : public podio::CollectionBase {

public:
  using const_iterator = RawCalorimeterHitConstCollectionIterator;
  using iterator = RawCalorimeterHitCollectionIterator;

  RawCalorimeterHitCollection();
  RawCalorimeterHitCollection(const RawCalorimeterHitCollection& ) = delete;
  RawCalorimeterHitCollection& operator=(const RawCalorimeterHitCollection& ) = delete;
//  RawCalorimeterHitCollection(RawCalorimeterHitVector* data, int collectionID);
  ~RawCalorimeterHitCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  RawCalorimeterHitCollection* operator->() { return (RawCalorimeterHitCollection*) this; }

  /// Append a new object to the collection, and return this object.
  RawCalorimeterHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  RawCalorimeterHit create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::RawCalorimeterHit"); }

  /// Returns the const object of given index
  ConstRawCalorimeterHit operator[](unsigned int index) const;
  /// Returns the object of a given index
  RawCalorimeterHit operator[](unsigned int index);
  /// Returns the const object of given index
  ConstRawCalorimeterHit at(unsigned int index) const;
  /// Returns the object of given index
  RawCalorimeterHit at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstRawCalorimeterHit object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (RawCalorimeterHitObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<RawCalorimeterHitData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<unsigned long long, arraysize> cellID() const;
  template<size_t arraysize>
  const std::array<int, arraysize> amplitude() const;
  template<size_t arraysize>
  const std::array<int, arraysize> timeStamp() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  RawCalorimeterHitObjPointerContainer m_entries;

  // members to handle 1-to-N-relations

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  RawCalorimeterHitDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const RawCalorimeterHitCollection& v);

template<typename... Args>
RawCalorimeterHit RawCalorimeterHitCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new RawCalorimeterHitObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return RawCalorimeterHit(obj);
}

template<size_t arraysize>
const std::array<unsigned long long, arraysize> RawCalorimeterHitCollection::cellID() const {
  std::array<unsigned long long, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.cellID;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> RawCalorimeterHitCollection::amplitude() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.amplitude;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> RawCalorimeterHitCollection::timeStamp() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.timeStamp;
  }
  return tmp;
}


} // namespace edm4hep


#endif
