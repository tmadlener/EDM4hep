// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_MCParticleCollection_H
#define EDM4HEP_MCParticleCollection_H

// datamodel specific includes
#include "edm4hep/MCParticleData.h"
#include "edm4hep/MCParticle.h"
#include "edm4hep/MCParticleObj.h"

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


using MCParticleDataContainer = std::vector<MCParticleData>;
using MCParticleObjPointerContainer = std::deque<MCParticleObj*>;

class MCParticleCollectionIterator {
public:
  MCParticleCollectionIterator(size_t index, const MCParticleObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  MCParticleCollectionIterator(const MCParticleCollectionIterator&) = delete;
  MCParticleCollectionIterator& operator=(const MCParticleCollectionIterator&) = delete;

  bool operator!=(const MCParticleCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  MCParticle operator*();
  MCParticle* operator->();
  MCParticleCollectionIterator& operator++();

private:
  size_t m_index;
  MCParticle m_object;
  const MCParticleObjPointerContainer* m_collection;
};


class MCParticleConstCollectionIterator {
public:
  MCParticleConstCollectionIterator(size_t index, const MCParticleObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  MCParticleConstCollectionIterator(const MCParticleConstCollectionIterator&) = delete;
  MCParticleConstCollectionIterator& operator=(const MCParticleConstCollectionIterator&) = delete;

  bool operator!=(const MCParticleConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstMCParticle operator*();
  ConstMCParticle* operator->();
  MCParticleConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstMCParticle m_object;
  const MCParticleObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class MCParticleCollection : public podio::CollectionBase {

public:
  using const_iterator = MCParticleConstCollectionIterator;
  using iterator = MCParticleCollectionIterator;

  MCParticleCollection();
  MCParticleCollection(const MCParticleCollection& ) = delete;
  MCParticleCollection& operator=(const MCParticleCollection& ) = delete;
//  MCParticleCollection(MCParticleVector* data, int collectionID);
  ~MCParticleCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  MCParticleCollection* operator->() { return (MCParticleCollection*) this; }

  /// Append a new object to the collection, and return this object.
  MCParticle create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  MCParticle create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::MCParticle"); }

  /// Returns the const object of given index
  ConstMCParticle operator[](unsigned int index) const;
  /// Returns the object of a given index
  MCParticle operator[](unsigned int index);
  /// Returns the const object of given index
  ConstMCParticle at(unsigned int index) const;
  /// Returns the object of given index
  MCParticle at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstMCParticle object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (MCParticleObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<MCParticleData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<int, arraysize> PDG() const;
  template<size_t arraysize>
  const std::array<int, arraysize> generatorStatus() const;
  template<size_t arraysize>
  const std::array<int, arraysize> simulatorStatus() const;
  template<size_t arraysize>
  const std::array<float, arraysize> charge() const;
  template<size_t arraysize>
  const std::array<float, arraysize> time() const;
  template<size_t arraysize>
  const std::array<double, arraysize> mass() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3d, arraysize> vertex() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3d, arraysize> endpoint() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> momentum() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> momentumAtEndpoint() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> spin() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector2i, arraysize> colorFlow() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  MCParticleObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstMCParticle>* m_rel_parents; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstMCParticle>*> m_rel_parents_tmp{}; ///< Relation buffer for internal book-keeping
  std::vector<edm4hep::ConstMCParticle>* m_rel_daughters; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstMCParticle>*> m_rel_daughters_tmp{}; ///< Relation buffer for internal book-keeping

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  MCParticleDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const MCParticleCollection& v);

template<typename... Args>
MCParticle MCParticleCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new MCParticleObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return MCParticle(obj);
}

template<size_t arraysize>
const std::array<int, arraysize> MCParticleCollection::PDG() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.PDG;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> MCParticleCollection::generatorStatus() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.generatorStatus;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> MCParticleCollection::simulatorStatus() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.simulatorStatus;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> MCParticleCollection::charge() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.charge;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> MCParticleCollection::time() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.time;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<double, arraysize> MCParticleCollection::mass() const {
  std::array<double, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.mass;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3d, arraysize> MCParticleCollection::vertex() const {
  std::array<edm4hep::Vector3d, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.vertex;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3d, arraysize> MCParticleCollection::endpoint() const {
  std::array<edm4hep::Vector3d, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.endpoint;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> MCParticleCollection::momentum() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.momentum;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> MCParticleCollection::momentumAtEndpoint() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.momentumAtEndpoint;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> MCParticleCollection::spin() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.spin;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector2i, arraysize> MCParticleCollection::colorFlow() const {
  std::array<edm4hep::Vector2i, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.colorFlow;
  }
  return tmp;
}


} // namespace edm4hep


#endif
