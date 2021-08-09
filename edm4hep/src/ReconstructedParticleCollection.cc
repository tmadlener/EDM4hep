// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ReconstructedParticleCollection.h"

#include "edm4hep/ClusterCollection.h"
#include "edm4hep/ParticleIDCollection.h"
#include "edm4hep/ReconstructedParticleCollection.h"
#include "edm4hep/TrackCollection.h"
#include "edm4hep/VertexCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


ReconstructedParticleCollection::ReconstructedParticleCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_clusters(new std::vector<edm4hep::ConstCluster>()),
  m_rel_tracks(new std::vector<edm4hep::ConstTrack>()),
  m_rel_particles(new std::vector<edm4hep::ConstReconstructedParticle>()),
  m_rel_particleIDs(new std::vector<edm4hep::ConstParticleID>()),
  m_rel_startVertex(new std::vector<edm4hep::ConstVertex>()),
  m_rel_particleIDUsed(new std::vector<edm4hep::ConstParticleID>()),
  m_data(new ReconstructedParticleDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

ReconstructedParticleCollection::~ReconstructedParticleCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_clusters) delete m_rel_clusters;
  if (m_rel_tracks) delete m_rel_tracks;
  if (m_rel_particles) delete m_rel_particles;
  if (m_rel_particleIDs) delete m_rel_particleIDs;
  if (m_rel_startVertex) delete m_rel_startVertex;
  if (m_rel_particleIDUsed) delete m_rel_particleIDUsed;
}

ConstReconstructedParticle ReconstructedParticleCollection::operator[](unsigned int index) const {
  return ConstReconstructedParticle(m_entries[index]);
}

ConstReconstructedParticle ReconstructedParticleCollection::at(unsigned int index) const {
  return ConstReconstructedParticle(m_entries.at(index));
}

ReconstructedParticle ReconstructedParticleCollection::operator[](unsigned int index) {
  return ReconstructedParticle(m_entries[index]);
}

ReconstructedParticle ReconstructedParticleCollection::at(unsigned int index) {
  return ReconstructedParticle(m_entries.at(index));
}

size_t ReconstructedParticleCollection::size() const {
  return m_entries.size();
}

ReconstructedParticle ReconstructedParticleCollection::create() {
  auto obj = m_entries.emplace_back(new ReconstructedParticleObj());
  m_rel_clusters_tmp.push_back(obj->m_clusters);
  m_rel_tracks_tmp.push_back(obj->m_tracks);
  m_rel_particles_tmp.push_back(obj->m_particles);
  m_rel_particleIDs_tmp.push_back(obj->m_particleIDs);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return ReconstructedParticle(obj);
}

void ReconstructedParticleCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  // clear relations to clusters. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_clusters_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_clusters_tmp.clear();
  for (auto& item : (*m_rel_clusters)) { item.unlink(); }
  m_rel_clusters->clear();

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

  // clear relations to particles. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_particles_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_particles_tmp.clear();
  for (auto& item : (*m_rel_particles)) { item.unlink(); }
  m_rel_particles->clear();

  // clear relations to particleIDs. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_particleIDs_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_particleIDs_tmp.clear();
  for (auto& item : (*m_rel_particleIDs)) { item.unlink(); }
  m_rel_particleIDs->clear();

  for (auto& item : (*m_rel_startVertex)) { item.unlink(); }
  m_rel_startVertex->clear();

  for (auto& item : (*m_rel_particleIDUsed)) { item.unlink(); }
  m_rel_particleIDUsed->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void ReconstructedParticleCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  int clusters_index = 0;
  int tracks_index = 0;
  int particles_index = 0;
  int particleIDs_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].clusters_begin = clusters_index;
    (*m_data)[i].clusters_end += clusters_index;
    clusters_index = (*m_data)[i].clusters_end;
    for (const auto& it : (*m_rel_clusters_tmp[i])) {
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

    (*m_data)[i].particles_begin = particles_index;
    (*m_data)[i].particles_end += particles_index;
    particles_index = (*m_data)[i].particles_end;
    for (const auto& it : (*m_rel_particles_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[2]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].particleIDs_begin = particleIDs_index;
    (*m_data)[i].particleIDs_end += particleIDs_index;
    particleIDs_index = (*m_data)[i].particleIDs_end;
    for (const auto& it : (*m_rel_particleIDs_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[3]->emplace_back(it.getObjectID());
    }

  }
  for (auto& obj : m_entries) {
    if (obj->m_startVertex) {
      m_refCollections[4]->emplace_back(obj->m_startVertex->getObjectID());
    } else {
       m_refCollections[4]->push_back({podio::ObjectID::invalid, podio::ObjectID::invalid});
    }
  }

  for (auto& obj : m_entries) {
    if (obj->m_particleIDUsed) {
      m_refCollections[5]->emplace_back(obj->m_particleIDUsed->getObjectID());
    } else {
       m_refCollections[5]->push_back({podio::ObjectID::invalid, podio::ObjectID::invalid});
    }
  }

}

void ReconstructedParticleCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new ReconstructedParticleObj({index, m_collectionID}, data);

    obj->m_clusters = m_rel_clusters;
    obj->m_tracks = m_rel_tracks;
    obj->m_particles = m_rel_particles;
    obj->m_particleIDs = m_rel_particleIDs;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool ReconstructedParticleCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_refCollections[0]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
      CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::ClusterCollection* tmp_coll = static_cast<edm4hep::ClusterCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_clusters->emplace_back(tmp);
    } else {
      m_rel_clusters->emplace_back(nullptr);
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

  for (unsigned int i = 0, size = m_refCollections[2]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[2])[i];
    if (id.index != podio::ObjectID::invalid) {
      CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::ReconstructedParticleCollection* tmp_coll = static_cast<edm4hep::ReconstructedParticleCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_particles->emplace_back(tmp);
    } else {
      m_rel_particles->emplace_back(nullptr);
    }
  }

  for (unsigned int i = 0, size = m_refCollections[3]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[3])[i];
    if (id.index != podio::ObjectID::invalid) {
      CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::ParticleIDCollection* tmp_coll = static_cast<edm4hep::ParticleIDCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_particleIDs->emplace_back(tmp);
    } else {
      m_rel_particleIDs->emplace_back(nullptr);
    }
  }

  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[4])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::VertexCollection* tmp_coll = static_cast<edm4hep::VertexCollection*>(coll);
      m_entries[i]->m_startVertex = new ConstVertex((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_startVertex = nullptr;
    }
  }

  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[5])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::ParticleIDCollection* tmp_coll = static_cast<edm4hep::ParticleIDCollection*>(coll);
      m_entries[i]->m_particleIDUsed = new ConstParticleID((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_particleIDUsed = nullptr;
    }
  }


  return true; //TODO: check success
}

void ReconstructedParticleCollection::push_back(ConstReconstructedParticle object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

    m_rel_clusters_tmp.push_back(obj->m_clusters);
    m_rel_tracks_tmp.push_back(obj->m_tracks);
    m_rel_particles_tmp.push_back(obj->m_particles);
    m_rel_particleIDs_tmp.push_back(obj->m_particleIDs);
  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void ReconstructedParticleCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<ReconstructedParticleDataContainer*>(address);
}

ReconstructedParticle ReconstructedParticleCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ReconstructedParticle* ReconstructedParticleCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

ReconstructedParticleCollectionIterator& ReconstructedParticleCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstReconstructedParticle ReconstructedParticleConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstReconstructedParticle* ReconstructedParticleConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

ReconstructedParticleConstCollectionIterator& ReconstructedParticleConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const ReconstructedParticleCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:        type:      energy:                 momentum [ x, y, z]:           referencePoint [ x, y, z]:      charge:        mass:goodnessOfPID:   covMatrix:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getType() << " "
      << std::setw(12) << v[i].getEnergy() << " "
      << std::setw(12) << v[i].getMomentum() << " "
      << std::setw(12) << v[i].getReferencePoint() << " "
      << std::setw(12) << v[i].getCharge() << " "
      << std::setw(12) << v[i].getMass() << " "
      << std::setw(12) << v[i].getGoodnessOfPID() << " "
      << std::endl;

    o << "      clusters : ";
    for (unsigned j = 0, N = v[i].clusters_size(); j < N; ++j) {
      o << v[i].getClusters(j).id() << " ";
    }
    o << std::endl;
    o << "      tracks : ";
    for (unsigned j = 0, N = v[i].tracks_size(); j < N; ++j) {
      o << v[i].getTracks(j).id() << " ";
    }
    o << std::endl;
    o << "      particles : ";
    for (unsigned j = 0, N = v[i].particles_size(); j < N; ++j) {
      o << v[i].getParticles(j).id() << " ";
    }
    o << std::endl;
    o << "      particleIDs : ";
    for (unsigned j = 0, N = v[i].particleIDs_size(); j < N; ++j) {
      o << v[i].getParticleIDs(j).id() << " ";
    }
    o << std::endl;

    o << "      startVertex : ";
    o << v[i].getStartVertex().id() << std::endl;
    o << "      particleIDUsed : ";
    o << v[i].getParticleIDUsed().id() << std::endl;


  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

