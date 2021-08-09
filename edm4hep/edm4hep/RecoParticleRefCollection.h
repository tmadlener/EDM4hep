// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecoParticleRefCollection_H
#define EDM4HEP_RecoParticleRefCollection_H

// datamodel specific includes
#include "edm4hep/RecoParticleRefData.h"
#include "edm4hep/RecoParticleRef.h"
#include "edm4hep/RecoParticleRefObj.h"

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


using RecoParticleRefDataContainer = std::vector<RecoParticleRefData>;
using RecoParticleRefObjPointerContainer = std::deque<RecoParticleRefObj*>;

class RecoParticleRefCollectionIterator {
public:
  RecoParticleRefCollectionIterator(size_t index, const RecoParticleRefObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  RecoParticleRefCollectionIterator(const RecoParticleRefCollectionIterator&) = delete;
  RecoParticleRefCollectionIterator& operator=(const RecoParticleRefCollectionIterator&) = delete;

  bool operator!=(const RecoParticleRefCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  RecoParticleRef operator*();
  RecoParticleRef* operator->();
  RecoParticleRefCollectionIterator& operator++();

private:
  size_t m_index;
  RecoParticleRef m_object;
  const RecoParticleRefObjPointerContainer* m_collection;
};


class RecoParticleRefConstCollectionIterator {
public:
  RecoParticleRefConstCollectionIterator(size_t index, const RecoParticleRefObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  RecoParticleRefConstCollectionIterator(const RecoParticleRefConstCollectionIterator&) = delete;
  RecoParticleRefConstCollectionIterator& operator=(const RecoParticleRefConstCollectionIterator&) = delete;

  bool operator!=(const RecoParticleRefConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstRecoParticleRef operator*();
  ConstRecoParticleRef* operator->();
  RecoParticleRefConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstRecoParticleRef m_object;
  const RecoParticleRefObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class RecoParticleRefCollection : public podio::CollectionBase {

public:
  using const_iterator = RecoParticleRefConstCollectionIterator;
  using iterator = RecoParticleRefCollectionIterator;

  RecoParticleRefCollection();
  RecoParticleRefCollection(const RecoParticleRefCollection& ) = delete;
  RecoParticleRefCollection& operator=(const RecoParticleRefCollection& ) = delete;
//  RecoParticleRefCollection(RecoParticleRefVector* data, int collectionID);
  ~RecoParticleRefCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  RecoParticleRefCollection* operator->() { return (RecoParticleRefCollection*) this; }

  /// Append a new object to the collection, and return this object.
  RecoParticleRef create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  RecoParticleRef create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::RecoParticleRef"); }

  /// Returns the const object of given index
  ConstRecoParticleRef operator[](unsigned int index) const;
  /// Returns the object of a given index
  RecoParticleRef operator[](unsigned int index);
  /// Returns the const object of given index
  ConstRecoParticleRef at(unsigned int index) const;
  /// Returns the object of given index
  RecoParticleRef at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstRecoParticleRef object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (RecoParticleRefObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<RecoParticleRefData>* _getBuffer() { return m_data; }


private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  RecoParticleRefObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstReconstructedParticle>* m_rel_particle; ///< Relation buffer for read / write

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  RecoParticleRefDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const RecoParticleRefCollection& v);

template<typename... Args>
RecoParticleRef RecoParticleRefCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new RecoParticleRefObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return RecoParticleRef(obj);
}


} // namespace edm4hep


#endif
