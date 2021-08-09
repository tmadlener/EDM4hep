// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoTrackerAssociationCollection_H
#define EDM4HEP_MCRecoTrackerAssociationCollection_H

// datamodel specific includes
#include "edm4hep/MCRecoTrackerAssociationData.h"
#include "edm4hep/MCRecoTrackerAssociation.h"
#include "edm4hep/MCRecoTrackerAssociationObj.h"

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


using MCRecoTrackerAssociationDataContainer = std::vector<MCRecoTrackerAssociationData>;
using MCRecoTrackerAssociationObjPointerContainer = std::deque<MCRecoTrackerAssociationObj*>;

class MCRecoTrackerAssociationCollectionIterator {
public:
  MCRecoTrackerAssociationCollectionIterator(size_t index, const MCRecoTrackerAssociationObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  MCRecoTrackerAssociationCollectionIterator(const MCRecoTrackerAssociationCollectionIterator&) = delete;
  MCRecoTrackerAssociationCollectionIterator& operator=(const MCRecoTrackerAssociationCollectionIterator&) = delete;

  bool operator!=(const MCRecoTrackerAssociationCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  MCRecoTrackerAssociation operator*();
  MCRecoTrackerAssociation* operator->();
  MCRecoTrackerAssociationCollectionIterator& operator++();

private:
  size_t m_index;
  MCRecoTrackerAssociation m_object;
  const MCRecoTrackerAssociationObjPointerContainer* m_collection;
};


class MCRecoTrackerAssociationConstCollectionIterator {
public:
  MCRecoTrackerAssociationConstCollectionIterator(size_t index, const MCRecoTrackerAssociationObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  MCRecoTrackerAssociationConstCollectionIterator(const MCRecoTrackerAssociationConstCollectionIterator&) = delete;
  MCRecoTrackerAssociationConstCollectionIterator& operator=(const MCRecoTrackerAssociationConstCollectionIterator&) = delete;

  bool operator!=(const MCRecoTrackerAssociationConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstMCRecoTrackerAssociation operator*();
  ConstMCRecoTrackerAssociation* operator->();
  MCRecoTrackerAssociationConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstMCRecoTrackerAssociation m_object;
  const MCRecoTrackerAssociationObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class MCRecoTrackerAssociationCollection : public podio::CollectionBase {

public:
  using const_iterator = MCRecoTrackerAssociationConstCollectionIterator;
  using iterator = MCRecoTrackerAssociationCollectionIterator;

  MCRecoTrackerAssociationCollection();
  MCRecoTrackerAssociationCollection(const MCRecoTrackerAssociationCollection& ) = delete;
  MCRecoTrackerAssociationCollection& operator=(const MCRecoTrackerAssociationCollection& ) = delete;
//  MCRecoTrackerAssociationCollection(MCRecoTrackerAssociationVector* data, int collectionID);
  ~MCRecoTrackerAssociationCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  MCRecoTrackerAssociationCollection* operator->() { return (MCRecoTrackerAssociationCollection*) this; }

  /// Append a new object to the collection, and return this object.
  MCRecoTrackerAssociation create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  MCRecoTrackerAssociation create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::MCRecoTrackerAssociation"); }

  /// Returns the const object of given index
  ConstMCRecoTrackerAssociation operator[](unsigned int index) const;
  /// Returns the object of a given index
  MCRecoTrackerAssociation operator[](unsigned int index);
  /// Returns the const object of given index
  ConstMCRecoTrackerAssociation at(unsigned int index) const;
  /// Returns the object of given index
  MCRecoTrackerAssociation at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstMCRecoTrackerAssociation object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (MCRecoTrackerAssociationObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<MCRecoTrackerAssociationData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<float, arraysize> weight() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  MCRecoTrackerAssociationObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstTrackerHit>* m_rel_rec; ///< Relation buffer for read / write
  std::vector<edm4hep::ConstSimTrackerHit>* m_rel_sim; ///< Relation buffer for read / write

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  MCRecoTrackerAssociationDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const MCRecoTrackerAssociationCollection& v);

template<typename... Args>
MCRecoTrackerAssociation MCRecoTrackerAssociationCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new MCRecoTrackerAssociationObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return MCRecoTrackerAssociation(obj);
}

template<size_t arraysize>
const std::array<float, arraysize> MCRecoTrackerAssociationCollection::weight() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.weight;
  }
  return tmp;
}


} // namespace edm4hep


#endif
