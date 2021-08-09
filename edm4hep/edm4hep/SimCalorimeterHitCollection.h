// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimCalorimeterHitCollection_H
#define EDM4HEP_SimCalorimeterHitCollection_H

// datamodel specific includes
#include "edm4hep/SimCalorimeterHitData.h"
#include "edm4hep/SimCalorimeterHit.h"
#include "edm4hep/SimCalorimeterHitObj.h"

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


using SimCalorimeterHitDataContainer = std::vector<SimCalorimeterHitData>;
using SimCalorimeterHitObjPointerContainer = std::deque<SimCalorimeterHitObj*>;

class SimCalorimeterHitCollectionIterator {
public:
  SimCalorimeterHitCollectionIterator(size_t index, const SimCalorimeterHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  SimCalorimeterHitCollectionIterator(const SimCalorimeterHitCollectionIterator&) = delete;
  SimCalorimeterHitCollectionIterator& operator=(const SimCalorimeterHitCollectionIterator&) = delete;

  bool operator!=(const SimCalorimeterHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  SimCalorimeterHit operator*();
  SimCalorimeterHit* operator->();
  SimCalorimeterHitCollectionIterator& operator++();

private:
  size_t m_index;
  SimCalorimeterHit m_object;
  const SimCalorimeterHitObjPointerContainer* m_collection;
};


class SimCalorimeterHitConstCollectionIterator {
public:
  SimCalorimeterHitConstCollectionIterator(size_t index, const SimCalorimeterHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  SimCalorimeterHitConstCollectionIterator(const SimCalorimeterHitConstCollectionIterator&) = delete;
  SimCalorimeterHitConstCollectionIterator& operator=(const SimCalorimeterHitConstCollectionIterator&) = delete;

  bool operator!=(const SimCalorimeterHitConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstSimCalorimeterHit operator*();
  ConstSimCalorimeterHit* operator->();
  SimCalorimeterHitConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstSimCalorimeterHit m_object;
  const SimCalorimeterHitObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class SimCalorimeterHitCollection : public podio::CollectionBase {

public:
  using const_iterator = SimCalorimeterHitConstCollectionIterator;
  using iterator = SimCalorimeterHitCollectionIterator;

  SimCalorimeterHitCollection();
  SimCalorimeterHitCollection(const SimCalorimeterHitCollection& ) = delete;
  SimCalorimeterHitCollection& operator=(const SimCalorimeterHitCollection& ) = delete;
//  SimCalorimeterHitCollection(SimCalorimeterHitVector* data, int collectionID);
  ~SimCalorimeterHitCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  SimCalorimeterHitCollection* operator->() { return (SimCalorimeterHitCollection*) this; }

  /// Append a new object to the collection, and return this object.
  SimCalorimeterHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  SimCalorimeterHit create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::SimCalorimeterHit"); }

  /// Returns the const object of given index
  ConstSimCalorimeterHit operator[](unsigned int index) const;
  /// Returns the object of a given index
  SimCalorimeterHit operator[](unsigned int index);
  /// Returns the const object of given index
  ConstSimCalorimeterHit at(unsigned int index) const;
  /// Returns the object of given index
  SimCalorimeterHit at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstSimCalorimeterHit object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (SimCalorimeterHitObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<SimCalorimeterHitData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<unsigned long long, arraysize> cellID() const;
  template<size_t arraysize>
  const std::array<float, arraysize> energy() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> position() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  SimCalorimeterHitObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstCaloHitContribution>* m_rel_contributions; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstCaloHitContribution>*> m_rel_contributions_tmp{}; ///< Relation buffer for internal book-keeping

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  SimCalorimeterHitDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const SimCalorimeterHitCollection& v);

template<typename... Args>
SimCalorimeterHit SimCalorimeterHitCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new SimCalorimeterHitObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return SimCalorimeterHit(obj);
}

template<size_t arraysize>
const std::array<unsigned long long, arraysize> SimCalorimeterHitCollection::cellID() const {
  std::array<unsigned long long, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.cellID;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> SimCalorimeterHitCollection::energy() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.energy;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> SimCalorimeterHitCollection::position() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.position;
  }
  return tmp;
}


} // namespace edm4hep


#endif
