// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ReconstructedParticleCollection_H
#define EDM4HEP_ReconstructedParticleCollection_H

// datamodel specific includes
#include "edm4hep/ReconstructedParticleData.h"
#include "edm4hep/ReconstructedParticle.h"
#include "edm4hep/ReconstructedParticleObj.h"

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


using ReconstructedParticleDataContainer = std::vector<ReconstructedParticleData>;
using ReconstructedParticleObjPointerContainer = std::deque<ReconstructedParticleObj*>;

class ReconstructedParticleCollectionIterator {
public:
  ReconstructedParticleCollectionIterator(size_t index, const ReconstructedParticleObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  ReconstructedParticleCollectionIterator(const ReconstructedParticleCollectionIterator&) = delete;
  ReconstructedParticleCollectionIterator& operator=(const ReconstructedParticleCollectionIterator&) = delete;

  bool operator!=(const ReconstructedParticleCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ReconstructedParticle operator*();
  ReconstructedParticle* operator->();
  ReconstructedParticleCollectionIterator& operator++();

private:
  size_t m_index;
  ReconstructedParticle m_object;
  const ReconstructedParticleObjPointerContainer* m_collection;
};


class ReconstructedParticleConstCollectionIterator {
public:
  ReconstructedParticleConstCollectionIterator(size_t index, const ReconstructedParticleObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  ReconstructedParticleConstCollectionIterator(const ReconstructedParticleConstCollectionIterator&) = delete;
  ReconstructedParticleConstCollectionIterator& operator=(const ReconstructedParticleConstCollectionIterator&) = delete;

  bool operator!=(const ReconstructedParticleConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstReconstructedParticle operator*();
  ConstReconstructedParticle* operator->();
  ReconstructedParticleConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstReconstructedParticle m_object;
  const ReconstructedParticleObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class ReconstructedParticleCollection : public podio::CollectionBase {

public:
  using const_iterator = ReconstructedParticleConstCollectionIterator;
  using iterator = ReconstructedParticleCollectionIterator;

  ReconstructedParticleCollection();
  ReconstructedParticleCollection(const ReconstructedParticleCollection& ) = delete;
  ReconstructedParticleCollection& operator=(const ReconstructedParticleCollection& ) = delete;
//  ReconstructedParticleCollection(ReconstructedParticleVector* data, int collectionID);
  ~ReconstructedParticleCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  ReconstructedParticleCollection* operator->() { return (ReconstructedParticleCollection*) this; }

  /// Append a new object to the collection, and return this object.
  ReconstructedParticle create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  ReconstructedParticle create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::ReconstructedParticle"); }

  /// Returns the const object of given index
  ConstReconstructedParticle operator[](unsigned int index) const;
  /// Returns the object of a given index
  ReconstructedParticle operator[](unsigned int index);
  /// Returns the const object of given index
  ConstReconstructedParticle at(unsigned int index) const;
  /// Returns the object of given index
  ReconstructedParticle at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstReconstructedParticle object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (ReconstructedParticleObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<ReconstructedParticleData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<int, arraysize> type() const;
  template<size_t arraysize>
  const std::array<float, arraysize> energy() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> momentum() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> referencePoint() const;
  template<size_t arraysize>
  const std::array<float, arraysize> charge() const;
  template<size_t arraysize>
  const std::array<float, arraysize> mass() const;
  template<size_t arraysize>
  const std::array<float, arraysize> goodnessOfPID() const;
  template<size_t arraysize>
  const std::array<std::array<float, 10>, arraysize> covMatrix() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  ReconstructedParticleObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstCluster>* m_rel_clusters; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstCluster>*> m_rel_clusters_tmp{}; ///< Relation buffer for internal book-keeping
  std::vector<edm4hep::ConstTrack>* m_rel_tracks; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstTrack>*> m_rel_tracks_tmp{}; ///< Relation buffer for internal book-keeping
  std::vector<edm4hep::ConstReconstructedParticle>* m_rel_particles; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstReconstructedParticle>*> m_rel_particles_tmp{}; ///< Relation buffer for internal book-keeping
  std::vector<edm4hep::ConstParticleID>* m_rel_particleIDs; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstParticleID>*> m_rel_particleIDs_tmp{}; ///< Relation buffer for internal book-keeping
  std::vector<edm4hep::ConstVertex>* m_rel_startVertex; ///< Relation buffer for read / write
  std::vector<edm4hep::ConstParticleID>* m_rel_particleIDUsed; ///< Relation buffer for read / write

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  ReconstructedParticleDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const ReconstructedParticleCollection& v);

template<typename... Args>
ReconstructedParticle ReconstructedParticleCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new ReconstructedParticleObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return ReconstructedParticle(obj);
}

template<size_t arraysize>
const std::array<int, arraysize> ReconstructedParticleCollection::type() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.type;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ReconstructedParticleCollection::energy() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.energy;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> ReconstructedParticleCollection::momentum() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.momentum;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> ReconstructedParticleCollection::referencePoint() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.referencePoint;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ReconstructedParticleCollection::charge() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.charge;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ReconstructedParticleCollection::mass() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.mass;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> ReconstructedParticleCollection::goodnessOfPID() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.goodnessOfPID;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<std::array<float, 10>, arraysize> ReconstructedParticleCollection::covMatrix() const {
  std::array<std::array<float, 10>, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.covMatrix;
  }
  return tmp;
}


} // namespace edm4hep


#endif
