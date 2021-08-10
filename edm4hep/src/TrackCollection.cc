// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackCollection.h"

#include "edm4hep/TrackCollection.h"
#include "edm4hep/TrackerHitCollection.h"
#include "edm4hep/SimpleTrackerHitCollection.h"
#include <numeric>

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


TrackCollection::TrackCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_trackerHits(new std::vector<edm4hep::ConstTrackerHitWrapper>()),
  m_rel_tracks(new std::vector<edm4hep::ConstTrack>()),
  m_vec_subDetectorHitNumbers(new std::vector<int>()),
  m_vec_trackStates(new std::vector<edm4hep::TrackState>()),
  m_data(new TrackDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_vecmem_info.emplace_back("int", &m_vec_subDetectorHitNumbers);
  m_vecmem_info.emplace_back("edm4hep::TrackState", &m_vec_trackStates);
}

TrackCollection::~TrackCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_trackerHits) delete m_rel_trackerHits;
  if (m_rel_tracks) delete m_rel_tracks;
  if (m_vec_subDetectorHitNumbers) delete m_vec_subDetectorHitNumbers;
  if (m_vec_trackStates) delete m_vec_trackStates;
}

ConstTrack TrackCollection::operator[](unsigned int index) const {
  return ConstTrack(m_entries[index]);
}

ConstTrack TrackCollection::at(unsigned int index) const {
  return ConstTrack(m_entries.at(index));
}

Track TrackCollection::operator[](unsigned int index) {
  return Track(m_entries[index]);
}

Track TrackCollection::at(unsigned int index) {
  return Track(m_entries.at(index));
}

size_t TrackCollection::size() const {
  return m_entries.size();
}

Track TrackCollection::create() {
  auto obj = m_entries.emplace_back(new TrackObj());
  m_rel_trackerHits_tmp.push_back(obj->m_trackerHits);
  m_rel_tracks_tmp.push_back(obj->m_tracks);
  m_vecs_subDetectorHitNumbers.push_back(obj->m_subDetectorHitNumbers);
  m_vecs_trackStates.push_back(obj->m_trackStates);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return Track(obj);
}

void TrackCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  // clear relations to trackerHits. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_trackerHits_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_trackerHits_tmp.clear();
  for (auto& item : (*m_rel_trackerHits)) { item.unlink(); }
  m_rel_trackerHits->clear();

  // clear relations to tracks. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_tracks_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_tracks_tmp.clear();
  for (auto& item : (*m_rel_tracks)) { item.unlink(); }
  m_rel_tracks->clear();

  m_vec_subDetectorHitNumbers->clear();
  for (auto& vec : m_vecs_subDetectorHitNumbers) { delete vec; }
  m_vecs_subDetectorHitNumbers.clear();

  m_vec_trackStates->clear();
  for (auto& vec : m_vecs_trackStates) { delete vec; }
  m_vecs_trackStates.clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void TrackCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  int trackerHits_index = 0;
  int tracks_index = 0;
  const auto subDetectorHitNumbers_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const TrackObj* obj) { return sum + obj->m_subDetectorHitNumbers->size(); });
  m_vec_subDetectorHitNumbers->reserve(subDetectorHitNumbers_size);
  int subDetectorHitNumbers_index = 0;
  const auto trackStates_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const TrackObj* obj) { return sum + obj->m_trackStates->size(); });
  m_vec_trackStates->reserve(trackStates_size);
  int trackStates_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].trackerHits_begin = trackerHits_index;
    (*m_data)[i].trackerHits_end += trackerHits_index;
    trackerHits_index = (*m_data)[i].trackerHits_end;
    for (const auto& it : (*m_rel_trackerHits_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[0]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].tracks_begin = tracks_index;
    (*m_data)[i].tracks_end += tracks_index;
    tracks_index = (*m_data)[i].tracks_end;
    for (const auto& it : (*m_rel_tracks_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[1]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].subDetectorHitNumbers_begin = subDetectorHitNumbers_index;
    (*m_data)[i].subDetectorHitNumbers_end += subDetectorHitNumbers_index;
    subDetectorHitNumbers_index = (*m_data)[i].subDetectorHitNumbers_end;
    for (const auto& it : (*m_vecs_subDetectorHitNumbers[i])) { m_vec_subDetectorHitNumbers->push_back(it); }

    (*m_data)[i].trackStates_begin = trackStates_index;
    (*m_data)[i].trackStates_end += trackStates_index;
    trackStates_index = (*m_data)[i].trackStates_end;
    for (const auto& it : (*m_vecs_trackStates[i])) { m_vec_trackStates->push_back(it); }

  }
}

void TrackCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new TrackObj({index, m_collectionID}, data);

    obj->m_trackerHits = m_rel_trackerHits;
    obj->m_tracks = m_rel_tracks;
    obj->m_subDetectorHitNumbers = m_vec_subDetectorHitNumbers;
    obj->m_trackStates = m_vec_trackStates;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool TrackCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_refCollections[0]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
      CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      if (coll->getValueTypeName() == "edm4hep::TrackerHit") {
        edm4hep::TrackerHitCollection* tmp_coll = static_cast<edm4hep::TrackerHitCollection*>(coll);
        const auto tmp = (*tmp_coll)[id.index];
        m_rel_trackerHits->emplace_back(tmp); 
      } else if (coll->getValueTypeName() == "edm4hep::SimpleTrackerHit") {
        edm4hep::SimpleTrackerHitCollection* tmp_coll = static_cast<edm4hep::SimpleTrackerHitCollection*>(coll);
        const auto tmp = (*tmp_coll)[id.index];
        m_rel_trackerHits->emplace_back(tmp);
      }


    } else {
      m_rel_trackerHits->emplace_back(static_cast<TrackerHitObj*>(nullptr));
    }
  }

  for (unsigned int i = 0, size = m_refCollections[1]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[1])[i];
    if (id.index != podio::ObjectID::invalid) {
      CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::TrackCollection* tmp_coll = static_cast<edm4hep::TrackCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_tracks->emplace_back(tmp);
    } else {
      m_rel_tracks->emplace_back(nullptr);
    }
  }


  return true; //TODO: check success
}

void TrackCollection::push_back(ConstTrack object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

    m_rel_trackerHits_tmp.push_back(obj->m_trackerHits);
    m_rel_tracks_tmp.push_back(obj->m_tracks);
    m_vecs_subDetectorHitNumbers.push_back(obj->m_subDetectorHitNumbers);
    m_vecs_trackStates.push_back(obj->m_trackStates);
  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void TrackCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<TrackDataContainer*>(address);
}

Track TrackCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

Track* TrackCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

TrackCollectionIterator& TrackCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstTrack TrackConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstTrack* TrackConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

TrackConstCollectionIterator& TrackConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const TrackCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:        type:        chi2:         ndf:        dEdx:   dEdxError:radiusOfInnermostHit:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getType() << " "
      << std::setw(12) << v[i].getChi2() << " "
      << std::setw(12) << v[i].getNdf() << " "
      << std::setw(12) << v[i].getDEdx() << " "
      << std::setw(12) << v[i].getDEdxError() << " "
      << std::setw(12) << v[i].getRadiusOfInnermostHit() << " "
      << std::endl;

    o << "      trackerHits : ";
    for (unsigned j = 0, N = v[i].trackerHits_size(); j < N; ++j) {
      o << v[i].getTrackerHits(j).id() << " ";
    }
    o << std::endl;
    o << "      tracks : ";
    for (unsigned j = 0, N = v[i].tracks_size(); j < N; ++j) {
      o << v[i].getTracks(j).id() << " ";
    }
    o << std::endl;


    o << "      subDetectorHitNumbers : ";
    for (unsigned j = 0, N = v[i].subDetectorHitNumbers_size(); j < N; ++j) {
      o << v[i].getSubDetectorHitNumbers(j) << " ";
    }
    o << std::endl;
    o << "      trackStates : ";
    for (unsigned j = 0, N = v[i].trackStates_size(); j < N; ++j) {
      o << v[i].getTrackStates(j) << " ";
    }
    o << std::endl;

  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

