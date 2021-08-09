// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ParticleIDCollection_H
#define EDM4HEP_ParticleIDCollection_H

// datamodel specific includes
#include "edm4hep/ParticleIDData.h"
#include "edm4hep/ParticleID.h"
#include "edm4hep/ParticleIDObj.h"

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


using ParticleIDDataContainer = std::vector<ParticleIDData>;
using ParticleIDObjPointerContainer = std::deque<ParticleIDObj*>;

class ParticleIDCollectionIterator {
public:
  ParticleIDCollectionIterator(size_t index, const ParticleIDObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  ParticleIDCollectionIterator(const ParticleIDCollectionIterator&) = delete;
  ParticleIDCollectionIterator& operator=(const ParticleIDCollectionIterator&) = delete;

  bool operator!=(const ParticleIDCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ParticleID operator*();
  ParticleID* operator->();
  ParticleIDCollectionIterator& operator++();

private:
  size_t m_index;
  ParticleID m_object;
  const ParticleIDObjPointerContainer* m_collection;
};


class ParticleIDConstCollectionIterator {
public:
  ParticleIDConstCollectionIterator(size_t index, const ParticleIDObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  ParticleIDConstCollectionIterator(const ParticleIDConstCollectionIterator&) = delete;
  ParticleIDConstCollectionIterator& operator=(const ParticleIDConstCollectionIterator&) = delete;

  bool operator!=(const ParticleIDConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstParticleID operator*();
  ConstParticleID* operator->();
  ParticleIDConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstParticleID m_object;
  const ParticleIDObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class ParticleIDCollection : public podio::CollectionBase {

public:
  using const_iterator = ParticleIDConstCollectionIterator;
  using iterator = ParticleIDCollectionIterator;

  ParticleIDCollection();
  ParticleIDCollection(const ParticleIDCollection& ) = delete;
  ParticleIDCollection& operator=(const ParticleIDCollection& ) = delete;
//  ParticleIDCollection(ParticleIDVector* data, int collectionID);
  ~ParticleIDCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  ParticleIDCollection* operator->() { return (ParticleIDCollection*) this; }

  /// Append a new object to the collection, and return this object.
  ParticleID create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  ParticleID create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::ParticleID"); }

  /// Returns the const object of given index
  ConstParticleID operator[](unsigned int index) const;
  /// Returns the object of a given index
  ParticleID operator[](unsigned int index);
  /// Returns the const object of given index
  ConstParticleID at(unsigned int index) const;
  /// Returns the object of given index
  ParticleID at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstParticleID object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (ParticleIDObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<ParticleIDData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<int, arraysize> type() const;
  template<size_t arraysize>
  const std::array<int, arraysize> PDG() const;
  template<size_t arraysize>
  const std::array<int, arraysize> algorithmType() const;
  template<size_t arraysize>
  const std::array<float, arraysize> likelihood() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  ParticleIDObjPointerContainer m_entries;

  // members to handle 1-to-N-relations

  // members to handle vector members
  std::vector<float>* m_vec_parameters; /// combined vector of all objects in collection
  std::vector<std::vector<float>*> m_vecs_parameters{}; /// pointers to individual member vectors
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  ParticleIDDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const ParticleIDCollection& v);

template<typename... Args>
ParticleID ParticleIDCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new ParticleIDObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return ParticleID(obj);
}

template<size_t arraysize>
const std::array<int, arraysize> ParticleIDCollection::type() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.type;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> ParticleIDCollection::PDG() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.PDG;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> ParticleIDCollection::algorithmType() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.algorithmType;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ParticleIDCollection::likelihood() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.likelihood;
  }
  return tmp;
}


} // namespace edm4hep


#endif
