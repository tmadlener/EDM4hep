// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_VertexCollection_H
#define EDM4HEP_VertexCollection_H

// datamodel specific includes
#include "edm4hep/VertexData.h"
#include "edm4hep/Vertex.h"
#include "edm4hep/VertexObj.h"

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


using VertexDataContainer = std::vector<VertexData>;
using VertexObjPointerContainer = std::deque<VertexObj*>;

class VertexCollectionIterator {
public:
  VertexCollectionIterator(size_t index, const VertexObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  VertexCollectionIterator(const VertexCollectionIterator&) = delete;
  VertexCollectionIterator& operator=(const VertexCollectionIterator&) = delete;

  bool operator!=(const VertexCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  Vertex operator*();
  Vertex* operator->();
  VertexCollectionIterator& operator++();

private:
  size_t m_index;
  Vertex m_object;
  const VertexObjPointerContainer* m_collection;
};


class VertexConstCollectionIterator {
public:
  VertexConstCollectionIterator(size_t index, const VertexObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  VertexConstCollectionIterator(const VertexConstCollectionIterator&) = delete;
  VertexConstCollectionIterator& operator=(const VertexConstCollectionIterator&) = delete;

  bool operator!=(const VertexConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstVertex operator*();
  ConstVertex* operator->();
  VertexConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstVertex m_object;
  const VertexObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class VertexCollection : public podio::CollectionBase {

public:
  using const_iterator = VertexConstCollectionIterator;
  using iterator = VertexCollectionIterator;

  VertexCollection();
  VertexCollection(const VertexCollection& ) = delete;
  VertexCollection& operator=(const VertexCollection& ) = delete;
//  VertexCollection(VertexVector* data, int collectionID);
  ~VertexCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  VertexCollection* operator->() { return (VertexCollection*) this; }

  /// Append a new object to the collection, and return this object.
  Vertex create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  Vertex create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::Vertex"); }

  /// Returns the const object of given index
  ConstVertex operator[](unsigned int index) const;
  /// Returns the object of a given index
  Vertex operator[](unsigned int index);
  /// Returns the const object of given index
  ConstVertex at(unsigned int index) const;
  /// Returns the object of given index
  Vertex at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstVertex object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (VertexObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<VertexData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<int, arraysize> primary() const;
  template<size_t arraysize>
  const std::array<float, arraysize> chi2() const;
  template<size_t arraysize>
  const std::array<float, arraysize> probability() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> position() const;
  template<size_t arraysize>
  const std::array<std::array<float, 6>, arraysize> covMatrix() const;
  template<size_t arraysize>
  const std::array<int, arraysize> algorithmType() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  VertexObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstReconstructedParticle>* m_rel_associatedParticle; ///< Relation buffer for read / write

  // members to handle vector members
  std::vector<float>* m_vec_parameters; /// combined vector of all objects in collection
  std::vector<std::vector<float>*> m_vecs_parameters{}; /// pointers to individual member vectors
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  VertexDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const VertexCollection& v);

template<typename... Args>
Vertex VertexCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new VertexObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return Vertex(obj);
}

template<size_t arraysize>
const std::array<int, arraysize> VertexCollection::primary() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.primary;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> VertexCollection::chi2() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.chi2;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> VertexCollection::probability() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.probability;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> VertexCollection::position() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.position;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<std::array<float, 6>, arraysize> VertexCollection::covMatrix() const {
  std::array<std::array<float, 6>, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.covMatrix;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> VertexCollection::algorithmType() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.algorithmType;
  }
  return tmp;
}


} // namespace edm4hep


#endif
