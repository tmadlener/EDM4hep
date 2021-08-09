// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CalorimeterHitCollection_H
#define EDM4HEP_CalorimeterHitCollection_H

// datamodel specific includes
#include "edm4hep/CalorimeterHitData.h"
#include "edm4hep/CalorimeterHit.h"
#include "edm4hep/CalorimeterHitObj.h"

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


using CalorimeterHitDataContainer = std::vector<CalorimeterHitData>;
using CalorimeterHitObjPointerContainer = std::deque<CalorimeterHitObj*>;

class CalorimeterHitCollectionIterator {
public:
  CalorimeterHitCollectionIterator(size_t index, const CalorimeterHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  CalorimeterHitCollectionIterator(const CalorimeterHitCollectionIterator&) = delete;
  CalorimeterHitCollectionIterator& operator=(const CalorimeterHitCollectionIterator&) = delete;

  bool operator!=(const CalorimeterHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  CalorimeterHit operator*();
  CalorimeterHit* operator->();
  CalorimeterHitCollectionIterator& operator++();

private:
  size_t m_index;
  CalorimeterHit m_object;
  const CalorimeterHitObjPointerContainer* m_collection;
};


class CalorimeterHitConstCollectionIterator {
public:
  CalorimeterHitConstCollectionIterator(size_t index, const CalorimeterHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  CalorimeterHitConstCollectionIterator(const CalorimeterHitConstCollectionIterator&) = delete;
  CalorimeterHitConstCollectionIterator& operator=(const CalorimeterHitConstCollectionIterator&) = delete;

  bool operator!=(const CalorimeterHitConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstCalorimeterHit operator*();
  ConstCalorimeterHit* operator->();
  CalorimeterHitConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstCalorimeterHit m_object;
  const CalorimeterHitObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class CalorimeterHitCollection : public podio::CollectionBase {

public:
  using const_iterator = CalorimeterHitConstCollectionIterator;
  using iterator = CalorimeterHitCollectionIterator;

  CalorimeterHitCollection();
  CalorimeterHitCollection(const CalorimeterHitCollection& ) = delete;
  CalorimeterHitCollection& operator=(const CalorimeterHitCollection& ) = delete;
//  CalorimeterHitCollection(CalorimeterHitVector* data, int collectionID);
  ~CalorimeterHitCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  CalorimeterHitCollection* operator->() { return (CalorimeterHitCollection*) this; }

  /// Append a new object to the collection, and return this object.
  CalorimeterHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  CalorimeterHit create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::CalorimeterHit"); }

  /// Returns the const object of given index
  ConstCalorimeterHit operator[](unsigned int index) const;
  /// Returns the object of a given index
  CalorimeterHit operator[](unsigned int index);
  /// Returns the const object of given index
  ConstCalorimeterHit at(unsigned int index) const;
  /// Returns the object of given index
  CalorimeterHit at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstCalorimeterHit object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (CalorimeterHitObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<CalorimeterHitData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<unsigned long long, arraysize> cellID() const;
  template<size_t arraysize>
  const std::array<float, arraysize> energy() const;
  template<size_t arraysize>
  const std::array<float, arraysize> energyError() const;
  template<size_t arraysize>
  const std::array<float, arraysize> time() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> position() const;
  template<size_t arraysize>
  const std::array<int, arraysize> type() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  CalorimeterHitObjPointerContainer m_entries;

  // members to handle 1-to-N-relations

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  CalorimeterHitDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const CalorimeterHitCollection& v);

template<typename... Args>
CalorimeterHit CalorimeterHitCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new CalorimeterHitObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return CalorimeterHit(obj);
}

template<size_t arraysize>
const std::array<unsigned long long, arraysize> CalorimeterHitCollection::cellID() const {
  std::array<unsigned long long, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.cellID;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> CalorimeterHitCollection::energy() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.energy;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> CalorimeterHitCollection::energyError() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.energyError;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> CalorimeterHitCollection::time() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.time;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> CalorimeterHitCollection::position() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.position;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> CalorimeterHitCollection::type() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.type;
  }
  return tmp;
}


} // namespace edm4hep


#endif
