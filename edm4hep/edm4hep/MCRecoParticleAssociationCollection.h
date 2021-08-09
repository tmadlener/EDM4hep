// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCRecoParticleAssociationCollection_H
#define EDM4HEP_MCRecoParticleAssociationCollection_H

// datamodel specific includes
#include "edm4hep/MCRecoParticleAssociationData.h"
#include "edm4hep/MCRecoParticleAssociation.h"
#include "edm4hep/MCRecoParticleAssociationObj.h"

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


using MCRecoParticleAssociationDataContainer = std::vector<MCRecoParticleAssociationData>;
using MCRecoParticleAssociationObjPointerContainer = std::deque<MCRecoParticleAssociationObj*>;

class MCRecoParticleAssociationCollectionIterator {
public:
  MCRecoParticleAssociationCollectionIterator(size_t index, const MCRecoParticleAssociationObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  MCRecoParticleAssociationCollectionIterator(const MCRecoParticleAssociationCollectionIterator&) = delete;
  MCRecoParticleAssociationCollectionIterator& operator=(const MCRecoParticleAssociationCollectionIterator&) = delete;

  bool operator!=(const MCRecoParticleAssociationCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  MCRecoParticleAssociation operator*();
  MCRecoParticleAssociation* operator->();
  MCRecoParticleAssociationCollectionIterator& operator++();

private:
  size_t m_index;
  MCRecoParticleAssociation m_object;
  const MCRecoParticleAssociationObjPointerContainer* m_collection;
};


class MCRecoParticleAssociationConstCollectionIterator {
public:
  MCRecoParticleAssociationConstCollectionIterator(size_t index, const MCRecoParticleAssociationObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  MCRecoParticleAssociationConstCollectionIterator(const MCRecoParticleAssociationConstCollectionIterator&) = delete;
  MCRecoParticleAssociationConstCollectionIterator& operator=(const MCRecoParticleAssociationConstCollectionIterator&) = delete;

  bool operator!=(const MCRecoParticleAssociationConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstMCRecoParticleAssociation operator*();
  ConstMCRecoParticleAssociation* operator->();
  MCRecoParticleAssociationConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstMCRecoParticleAssociation m_object;
  const MCRecoParticleAssociationObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class MCRecoParticleAssociationCollection : public podio::CollectionBase {

public:
  using const_iterator = MCRecoParticleAssociationConstCollectionIterator;
  using iterator = MCRecoParticleAssociationCollectionIterator;

  MCRecoParticleAssociationCollection();
  MCRecoParticleAssociationCollection(const MCRecoParticleAssociationCollection& ) = delete;
  MCRecoParticleAssociationCollection& operator=(const MCRecoParticleAssociationCollection& ) = delete;
//  MCRecoParticleAssociationCollection(MCRecoParticleAssociationVector* data, int collectionID);
  ~MCRecoParticleAssociationCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  MCRecoParticleAssociationCollection* operator->() { return (MCRecoParticleAssociationCollection*) this; }

  /// Append a new object to the collection, and return this object.
  MCRecoParticleAssociation create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  MCRecoParticleAssociation create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::MCRecoParticleAssociation"); }

  /// Returns the const object of given index
  ConstMCRecoParticleAssociation operator[](unsigned int index) const;
  /// Returns the object of a given index
  MCRecoParticleAssociation operator[](unsigned int index);
  /// Returns the const object of given index
  ConstMCRecoParticleAssociation at(unsigned int index) const;
  /// Returns the object of given index
  MCRecoParticleAssociation at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstMCRecoParticleAssociation object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (MCRecoParticleAssociationObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<MCRecoParticleAssociationData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<float, arraysize> weight() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  MCRecoParticleAssociationObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstReconstructedParticle>* m_rel_rec; ///< Relation buffer for read / write
  std::vector<edm4hep::ConstMCParticle>* m_rel_sim; ///< Relation buffer for read / write

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  MCRecoParticleAssociationDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const MCRecoParticleAssociationCollection& v);

template<typename... Args>
MCRecoParticleAssociation MCRecoParticleAssociationCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new MCRecoParticleAssociationObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return MCRecoParticleAssociation(obj);
}

template<size_t arraysize>
const std::array<float, arraysize> MCRecoParticleAssociationCollection::weight() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.weight;
  }
  return tmp;
}


} // namespace edm4hep


#endif
