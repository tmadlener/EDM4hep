// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimpleTrackerHitCollection_H
#define EDM4HEP_SimpleTrackerHitCollection_H

// datamodel specific includes
#include "edm4hep/SimpleTrackerHitData.h"
#include "edm4hep/SimpleTrackerHit.h"
#include "edm4hep/SimpleTrackerHitObj.h"

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


using SimpleTrackerHitDataContainer = std::vector<SimpleTrackerHitData>;
using SimpleTrackerHitObjPointerContainer = std::deque<SimpleTrackerHitObj*>;

class SimpleTrackerHitCollectionIterator {
public:
  SimpleTrackerHitCollectionIterator(size_t index, const SimpleTrackerHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  SimpleTrackerHitCollectionIterator(const SimpleTrackerHitCollectionIterator&) = delete;
  SimpleTrackerHitCollectionIterator& operator=(const SimpleTrackerHitCollectionIterator&) = delete;

  bool operator!=(const SimpleTrackerHitCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  SimpleTrackerHit operator*();
  SimpleTrackerHit* operator->();
  SimpleTrackerHitCollectionIterator& operator++();

private:
  size_t m_index;
  SimpleTrackerHit m_object;
  const SimpleTrackerHitObjPointerContainer* m_collection;
};


class SimpleTrackerHitConstCollectionIterator {
public:
  SimpleTrackerHitConstCollectionIterator(size_t index, const SimpleTrackerHitObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  SimpleTrackerHitConstCollectionIterator(const SimpleTrackerHitConstCollectionIterator&) = delete;
  SimpleTrackerHitConstCollectionIterator& operator=(const SimpleTrackerHitConstCollectionIterator&) = delete;

  bool operator!=(const SimpleTrackerHitConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstSimpleTrackerHit operator*();
  ConstSimpleTrackerHit* operator->();
  SimpleTrackerHitConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstSimpleTrackerHit m_object;
  const SimpleTrackerHitObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class SimpleTrackerHitCollection : public podio::CollectionBase {

public:
  using const_iterator = SimpleTrackerHitConstCollectionIterator;
  using iterator = SimpleTrackerHitCollectionIterator;

  SimpleTrackerHitCollection();
  SimpleTrackerHitCollection(const SimpleTrackerHitCollection& ) = delete;
  SimpleTrackerHitCollection& operator=(const SimpleTrackerHitCollection& ) = delete;
//  SimpleTrackerHitCollection(SimpleTrackerHitVector* data, int collectionID);
  ~SimpleTrackerHitCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  SimpleTrackerHitCollection* operator->() { return (SimpleTrackerHitCollection*) this; }

  /// Append a new object to the collection, and return this object.
  SimpleTrackerHit create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  SimpleTrackerHit create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::SimpleTrackerHit"); }

  /// Returns the const object of given index
  ConstSimpleTrackerHit operator[](unsigned int index) const;
  /// Returns the object of a given index
  SimpleTrackerHit operator[](unsigned int index);
  /// Returns the const object of given index
  ConstSimpleTrackerHit at(unsigned int index) const;
  /// Returns the object of given index
  SimpleTrackerHit at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstSimpleTrackerHit object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (SimpleTrackerHitObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<SimpleTrackerHitData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<edm4hep::Vector3d, arraysize> position() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  SimpleTrackerHitObjPointerContainer m_entries;

  // members to handle 1-to-N-relations

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  SimpleTrackerHitDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const SimpleTrackerHitCollection& v);

template<typename... Args>
SimpleTrackerHit SimpleTrackerHitCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new SimpleTrackerHitObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return SimpleTrackerHit(obj);
}

template<size_t arraysize>
const std::array<edm4hep::Vector3d, arraysize> SimpleTrackerHitCollection::position() const {
  std::array<edm4hep::Vector3d, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.position;
  }
  return tmp;
}


} // namespace edm4hep


#endif
