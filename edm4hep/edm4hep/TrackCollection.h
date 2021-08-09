// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackCollection_H
#define EDM4HEP_TrackCollection_H

// datamodel specific includes
#include "edm4hep/TrackData.h"
#include "edm4hep/Track.h"
#include "edm4hep/TrackObj.h"

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


using TrackDataContainer = std::vector<TrackData>;
using TrackObjPointerContainer = std::deque<TrackObj*>;

class TrackCollectionIterator {
public:
  TrackCollectionIterator(size_t index, const TrackObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  TrackCollectionIterator(const TrackCollectionIterator&) = delete;
  TrackCollectionIterator& operator=(const TrackCollectionIterator&) = delete;

  bool operator!=(const TrackCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  Track operator*();
  Track* operator->();
  TrackCollectionIterator& operator++();

private:
  size_t m_index;
  Track m_object;
  const TrackObjPointerContainer* m_collection;
};


class TrackConstCollectionIterator {
public:
  TrackConstCollectionIterator(size_t index, const TrackObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  TrackConstCollectionIterator(const TrackConstCollectionIterator&) = delete;
  TrackConstCollectionIterator& operator=(const TrackConstCollectionIterator&) = delete;

  bool operator!=(const TrackConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstTrack operator*();
  ConstTrack* operator->();
  TrackConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstTrack m_object;
  const TrackObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class TrackCollection : public podio::CollectionBase {

public:
  using const_iterator = TrackConstCollectionIterator;
  using iterator = TrackCollectionIterator;

  TrackCollection();
  TrackCollection(const TrackCollection& ) = delete;
  TrackCollection& operator=(const TrackCollection& ) = delete;
//  TrackCollection(TrackVector* data, int collectionID);
  ~TrackCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  TrackCollection* operator->() { return (TrackCollection*) this; }

  /// Append a new object to the collection, and return this object.
  Track create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  Track create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::Track"); }

  /// Returns the const object of given index
  ConstTrack operator[](unsigned int index) const;
  /// Returns the object of a given index
  Track operator[](unsigned int index);
  /// Returns the const object of given index
  ConstTrack at(unsigned int index) const;
  /// Returns the object of given index
  Track at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstTrack object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (TrackObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
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
  std::vector<TrackData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<int, arraysize> type() const;
  template<size_t arraysize>
  const std::array<float, arraysize> chi2() const;
  template<size_t arraysize>
  const std::array<int, arraysize> ndf() const;
  template<size_t arraysize>
  const std::array<float, arraysize> dEdx() const;
  template<size_t arraysize>
  const std::array<float, arraysize> dEdxError() const;
  template<size_t arraysize>
  const std::array<float, arraysize> radiusOfInnermostHit() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  TrackObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstTrackerHit>* m_rel_trackerHits; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstTrackerHit>*> m_rel_trackerHits_tmp{}; ///< Relation buffer for internal book-keeping
  std::vector<edm4hep::ConstTrack>* m_rel_tracks; ///< Relation buffer for read / write
  std::vector<std::vector<edm4hep::ConstTrack>*> m_rel_tracks_tmp{}; ///< Relation buffer for internal book-keeping

  // members to handle vector members
  std::vector<int>* m_vec_subDetectorHitNumbers; /// combined vector of all objects in collection
  std::vector<std::vector<int>*> m_vecs_subDetectorHitNumbers{}; /// pointers to individual member vectors
  std::vector<edm4hep::TrackState>* m_vec_trackStates; /// combined vector of all objects in collection
  std::vector<std::vector<edm4hep::TrackState>*> m_vecs_trackStates{}; /// pointers to individual member vectors
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  TrackDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const TrackCollection& v);

template<typename... Args>
Track TrackCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new TrackObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return Track(obj);
}

template<size_t arraysize>
const std::array<int, arraysize> TrackCollection::type() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.type;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TrackCollection::chi2() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.chi2;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<int, arraysize> TrackCollection::ndf() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.ndf;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TrackCollection::dEdx() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.dEdx;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TrackCollection::dEdxError() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.dEdxError;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> TrackCollection::radiusOfInnermostHit() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.radiusOfInnermostHit;
  }
  return tmp;
}


} // namespace edm4hep


#endif
