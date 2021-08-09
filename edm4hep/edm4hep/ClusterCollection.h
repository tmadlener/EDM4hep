// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ClusterCollection_H
#define EDM4HEP_ClusterCollection_H

// datamodel specific includes
#include "edm4hep/ClusterData.h"
#include "edm4hep/Cluster.h"
#include "edm4hep/ClusterObj.h"

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


using ClusterDataContainer = std::vector<ClusterData>;
using ClusterObjPointerContainer = std::deque<ClusterObj*>;

class ClusterCollectionIterator {
public:
  ClusterCollectionIterator(size_t index, const ClusterObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  ClusterCollectionIterator(const ClusterCollectionIterator&) = delete;
  ClusterCollectionIterator& operator=(const ClusterCollectionIterator&) = delete;

  bool operator!=(const ClusterCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  Cluster operator*();
  Cluster* operator->();
  ClusterCollectionIterator& operator++();

private:
  size_t m_index;
  Cluster m_object;
  const ClusterObjPointerContainer* m_collection;
};


class ClusterConstCollectionIterator {
public:
  ClusterConstCollectionIterator(size_t index, const ClusterObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  ClusterConstCollectionIterator(const ClusterConstCollectionIterator&) = delete;
  ClusterConstCollectionIterator& operator=(const ClusterConstCollectionIterator&) = delete;

  bool operator!=(const ClusterConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstCluster operator*();
  ConstCluster* operator->();
  ClusterConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstCluster m_object;
  const ClusterObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class ClusterCollection : public podio::CollectionBase {

public:
  using const_iterator = ClusterConstCollectionIterator;
  using iterator = ClusterCollectionIterator;

  ClusterCollection();
  ClusterCollection(const ClusterCollection& ) = delete;
  ClusterCollection& operator=(const ClusterCollection& ) = delete;
//  ClusterCollection(ClusterVector* data, int collectionID);
  ~ClusterCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  ClusterCollection* operator->() { return (ClusterCollection*) this; }

  /// Append a new object to the collection, and return this object.
  Cluster create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  Cluster create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::Cluster"); }

  /// Returns the const object of given index
  ConstCluster operator[](unsigned int index) const;
  /// Returns the object of a given index
  Cluster operator[](unsigned int index);
  /// Returns the const object of given index
  ConstCluster at(unsigned int index) const;
  /// Returns the object of given index
  Cluster at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstCluster object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (ClusterObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<ClusterData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<int, arraysize> type() const;
  template<size_t arraysize>
  const std::array<float, arraysize> energy() const;
  template<size_t arraysize>
  const std::array<float, arraysize> energyError() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> position() const;
  template<size_t arraysize>
  const std::array<std::array<float, 6>, arraysize> positionError() const;
  template<size_t arraysize>
  const std::array<float, arraysize> iTheta() const;
  template<size_t arraysize>
  const std::array<float, arraysize> phi() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> directionError() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  ClusterObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstCluster>* m_rel_clusters; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstCluster>*> m_rel_clusters_tmp{}; ///< Relation buffer for internal book-keeping
  std::vector<edm4hep::ConstCalorimeterHit>* m_rel_hits; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstCalorimeterHit>*> m_rel_hits_tmp{}; ///< Relation buffer for internal book-keeping
  std::vector<edm4hep::ConstParticleID>* m_rel_particleIDs; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstParticleID>*> m_rel_particleIDs_tmp{}; ///< Relation buffer for internal book-keeping

  // members to handle vector members
  std::vector<float>* m_vec_shapeParameters; /// combined vector of all objects in collection
  std::vector<std::vector<float>*> m_vecs_shapeParameters{}; /// pointers to individual member vectors
  std::vector<float>* m_vec_hitContributions; /// combined vector of all objects in collection
  std::vector<std::vector<float>*> m_vecs_hitContributions{}; /// pointers to individual member vectors
  std::vector<float>* m_vec_subdetectorEnergies; /// combined vector of all objects in collection
  std::vector<std::vector<float>*> m_vecs_subdetectorEnergies{}; /// pointers to individual member vectors
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  ClusterDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const ClusterCollection& v);

template<typename... Args>
Cluster ClusterCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new ClusterObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return Cluster(obj);
}

template<size_t arraysize>
const std::array<int, arraysize> ClusterCollection::type() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.type;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ClusterCollection::energy() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.energy;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ClusterCollection::energyError() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.energyError;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> ClusterCollection::position() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.position;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<std::array<float, 6>, arraysize> ClusterCollection::positionError() const {
  std::array<std::array<float, 6>, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.positionError;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ClusterCollection::iTheta() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.iTheta;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ClusterCollection::phi() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.phi;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> ClusterCollection::directionError() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.directionError;
  }
  return tmp;
}


} // namespace edm4hep


#endif
