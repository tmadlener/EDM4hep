// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TPCHitCollection_H
#define EDM4HEP_TPCHitCollection_H

// datamodel specific includes
#include "edm4hep/TPCHitData.h"
#include "edm4hep/TPCHit.h"
#include "edm4hep/TPCHitObj.h"

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


using TPCHitDataContainer = std::vector<TPCHitData>;
using TPCHitObjPointerContainer = std::deque<TPCHitObj*>;

class TPCHitCollectionIterator {
public:
  TPCHitCollectionIterator(size_t index, const TPCHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  TPCHitCollectionIterator(const TPCHitCollectionIterator&) = delete;
  TPCHitCollectionIterator& operator=(const TPCHitCollectionIterator&) = delete;

  bool operator!=(const TPCHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  TPCHit operator*();
  TPCHit* operator->();
  TPCHitCollectionIterator& operator++();

private:
  size_t m_index;
  TPCHit m_object;
  const TPCHitObjPointerContainer* m_collection;
};


class TPCHitConstCollectionIterator {
public:
  TPCHitConstCollectionIterator(size_t index, const TPCHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  TPCHitConstCollectionIterator(const TPCHitConstCollectionIterator&) = delete;
  TPCHitConstCollectionIterator& operator=(const TPCHitConstCollectionIterator&) = delete;

  bool operator!=(const TPCHitConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstTPCHit operator*();
  ConstTPCHit* operator->();
  TPCHitConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstTPCHit m_object;
  const TPCHitObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class TPCHitCollection : public podio::CollectionBase {

public:
  using const_iterator = TPCHitConstCollectionIterator;
  using iterator = TPCHitCollectionIterator;

  TPCHitCollection();
  TPCHitCollection(const TPCHitCollection& ) = delete;
  TPCHitCollection& operator=(const TPCHitCollection& ) = delete;
//  TPCHitCollection(TPCHitVector* data, int collectionID);
  ~TPCHitCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  TPCHitCollection* operator->() { return (TPCHitCollection*) this; }

  /// Append a new object to the collection, and return this object.
  TPCHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  TPCHit create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::TPCHit"); }

  /// Returns the const object of given index
  ConstTPCHit operator[](unsigned int index) const;
  /// Returns the object of a given index
  TPCHit operator[](unsigned int index);
  /// Returns the const object of given index
  ConstTPCHit at(unsigned int index) const;
  /// Returns the object of given index
  TPCHit at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstTPCHit object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (TPCHitObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<TPCHitData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<unsigned long long, arraysize> cellID() const;
  template<size_t arraysize>
  const std::array<int, arraysize> quality() const;
  template<size_t arraysize>
  const std::array<float, arraysize> time() const;
  template<size_t arraysize>
  const std::array<float, arraysize> charge() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  TPCHitObjPointerContainer m_entries;

  // members to handle 1-to-N-relations

  // members to handle vector members
  std::vector<int>* m_vec_rawDataWords; /// combined vector of all objects in collection
  std::vector<std::vector<int>*> m_vecs_rawDataWords{}; /// pointers to individual member vectors
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  TPCHitDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const TPCHitCollection& v);

template<typename... Args>
TPCHit TPCHitCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new TPCHitObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return TPCHit(obj);
}

template<size_t arraysize>
const std::array<unsigned long long, arraysize> TPCHitCollection::cellID() const {
  std::array<unsigned long long, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.cellID;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> TPCHitCollection::quality() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.quality;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TPCHitCollection::time() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.time;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TPCHitCollection::charge() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.charge;
  }
  return tmp;
}


} // namespace edm4hep


#endif
