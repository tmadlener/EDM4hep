// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoCaloAssociationCollection_H
#define EDM4HEP_MCRecoCaloAssociationCollection_H

// datamodel specific includes
#include "edm4hep/MCRecoCaloAssociationData.h"
#include "edm4hep/MCRecoCaloAssociation.h"
#include "edm4hep/MCRecoCaloAssociationObj.h"

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


using MCRecoCaloAssociationDataContainer = std::vector<MCRecoCaloAssociationData>;
using MCRecoCaloAssociationObjPointerContainer = std::deque<MCRecoCaloAssociationObj*>;

class MCRecoCaloAssociationCollectionIterator {
public:
  MCRecoCaloAssociationCollectionIterator(size_t index, const MCRecoCaloAssociationObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  MCRecoCaloAssociationCollectionIterator(const MCRecoCaloAssociationCollectionIterator&) = delete;
  MCRecoCaloAssociationCollectionIterator& operator=(const MCRecoCaloAssociationCollectionIterator&) = delete;

  bool operator!=(const MCRecoCaloAssociationCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  MCRecoCaloAssociation operator*();
  MCRecoCaloAssociation* operator->();
  MCRecoCaloAssociationCollectionIterator& operator++();

private:
  size_t m_index;
  MCRecoCaloAssociation m_object;
  const MCRecoCaloAssociationObjPointerContainer* m_collection;
};


class MCRecoCaloAssociationConstCollectionIterator {
public:
  MCRecoCaloAssociationConstCollectionIterator(size_t index, const MCRecoCaloAssociationObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  MCRecoCaloAssociationConstCollectionIterator(const MCRecoCaloAssociationConstCollectionIterator&) = delete;
  MCRecoCaloAssociationConstCollectionIterator& operator=(const MCRecoCaloAssociationConstCollectionIterator&) = delete;

  bool operator!=(const MCRecoCaloAssociationConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstMCRecoCaloAssociation operator*();
  ConstMCRecoCaloAssociation* operator->();
  MCRecoCaloAssociationConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstMCRecoCaloAssociation m_object;
  const MCRecoCaloAssociationObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class MCRecoCaloAssociationCollection : public podio::CollectionBase {

public:
  using const_iterator = MCRecoCaloAssociationConstCollectionIterator;
  using iterator = MCRecoCaloAssociationCollectionIterator;

  MCRecoCaloAssociationCollection();
  MCRecoCaloAssociationCollection(const MCRecoCaloAssociationCollection& ) = delete;
  MCRecoCaloAssociationCollection& operator=(const MCRecoCaloAssociationCollection& ) = delete;
//  MCRecoCaloAssociationCollection(MCRecoCaloAssociationVector* data, int collectionID);
  ~MCRecoCaloAssociationCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  MCRecoCaloAssociationCollection* operator->() { return (MCRecoCaloAssociationCollection*) this; }

  /// Append a new object to the collection, and return this object.
  MCRecoCaloAssociation create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  MCRecoCaloAssociation create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::MCRecoCaloAssociation"); }

  /// Returns the const object of given index
  ConstMCRecoCaloAssociation operator[](unsigned int index) const;
  /// Returns the object of a given index
  MCRecoCaloAssociation operator[](unsigned int index);
  /// Returns the const object of given index
  ConstMCRecoCaloAssociation at(unsigned int index) const;
  /// Returns the object of given index
  MCRecoCaloAssociation at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstMCRecoCaloAssociation object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (MCRecoCaloAssociationObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<MCRecoCaloAssociationData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<float, arraysize> weight() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  MCRecoCaloAssociationObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstCalorimeterHit>* m_rel_rec; ///< Relation buffer for read / write
  std::vector<edm4hep::ConstSimCalorimeterHit>* m_rel_sim; ///< Relation buffer for read / write

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  MCRecoCaloAssociationDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const MCRecoCaloAssociationCollection& v);

template<typename... Args>
MCRecoCaloAssociation MCRecoCaloAssociationCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new MCRecoCaloAssociationObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return MCRecoCaloAssociation(obj);
}

template<size_t arraysize>
const std::array<float, arraysize> MCRecoCaloAssociationCollection::weight() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.weight;
  }
  return tmp;
}


} // namespace edm4hep


#endif
