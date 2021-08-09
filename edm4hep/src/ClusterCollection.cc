// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ClusterCollection.h"

#include "edm4hep/CalorimeterHitCollection.h"
#include "edm4hep/ClusterCollection.h"
#include "edm4hep/ParticleIDCollection.h"
#include <numeric>

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


ClusterCollection::ClusterCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_clusters(new std::vector<edm4hep::ConstCluster>()),
  m_rel_hits(new std::vector<edm4hep::ConstCalorimeterHit>()),
  m_rel_particleIDs(new std::vector<edm4hep::ConstParticleID>()),
  m_vec_shapeParameters(new std::vector<float>()),
  m_vec_hitContributions(new std::vector<float>()),
  m_vec_subdetectorEnergies(new std::vector<float>()),
  m_data(new ClusterDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_vecmem_info.emplace_back("float", &m_vec_shapeParameters);
  m_vecmem_info.emplace_back("float", &m_vec_hitContributions);
  m_vecmem_info.emplace_back("float", &m_vec_subdetectorEnergies);
}

ClusterCollection::~ClusterCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_clusters) delete m_rel_clusters;
  if (m_rel_hits) delete m_rel_hits;
  if (m_rel_particleIDs) delete m_rel_particleIDs;
  if (m_vec_shapeParameters) delete m_vec_shapeParameters;
  if (m_vec_hitContributions) delete m_vec_hitContributions;
  if (m_vec_subdetectorEnergies) delete m_vec_subdetectorEnergies;
}

ConstCluster ClusterCollection::operator[](unsigned int index) const {
  return ConstCluster(m_entries[index]);
}

ConstCluster ClusterCollection::at(unsigned int index) const {
  return ConstCluster(m_entries.at(index));
}

Cluster ClusterCollection::operator[](unsigned int index) {
  return Cluster(m_entries[index]);
}

Cluster ClusterCollection::at(unsigned int index) {
  return Cluster(m_entries.at(index));
}

size_t ClusterCollection::size() const {
  return m_entries.size();
}

Cluster ClusterCollection::create() {
  auto obj = m_entries.emplace_back(new ClusterObj());
  m_rel_clusters_tmp.push_back(obj->m_clusters);
  m_rel_hits_tmp.push_back(obj->m_hits);
  m_rel_particleIDs_tmp.push_back(obj->m_particleIDs);
  m_vecs_shapeParameters.push_back(obj->m_shapeParameters);
  m_vecs_hitContributions.push_back(obj->m_hitContributions);
  m_vecs_subdetectorEnergies.push_back(obj->m_subdetectorEnergies);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return Cluster(obj);
}

void ClusterCollection::clear() {
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

  // clear relations to hits. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_hits_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_hits_tmp.clear();
  for (auto& item : (*m_rel_hits)) { item.unlink(); }
  m_rel_hits->clear();

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

  m_vec_shapeParameters->clear();
  for (auto& vec : m_vecs_shapeParameters) { delete vec; }
  m_vecs_shapeParameters.clear();

  m_vec_hitContributions->clear();
  for (auto& vec : m_vecs_hitContributions) { delete vec; }
  m_vecs_hitContributions.clear();

  m_vec_subdetectorEnergies->clear();
  for (auto& vec : m_vecs_subdetectorEnergies) { delete vec; }
  m_vecs_subdetectorEnergies.clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void ClusterCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  int clusters_index = 0;
  int hits_index = 0;
  int particleIDs_index = 0;
  const auto shapeParameters_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const ClusterObj* obj) { return sum + obj->m_shapeParameters->size(); });
  m_vec_shapeParameters->reserve(shapeParameters_size);
  int shapeParameters_index = 0;
  const auto hitContributions_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const ClusterObj* obj) { return sum + obj->m_hitContributions->size(); });
  m_vec_hitContributions->reserve(hitContributions_size);
  int hitContributions_index = 0;
  const auto subdetectorEnergies_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const ClusterObj* obj) { return sum + obj->m_subdetectorEnergies->size(); });
  m_vec_subdetectorEnergies->reserve(subdetectorEnergies_size);
  int subdetectorEnergies_index = 0;
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

    (*m_data)[i].hits_begin = hits_index;
    (*m_data)[i].hits_end += hits_index;
    hits_index = (*m_data)[i].hits_end;
    for (const auto& it : (*m_rel_hits_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[1]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].particleIDs_begin = particleIDs_index;
    (*m_data)[i].particleIDs_end += particleIDs_index;
    particleIDs_index = (*m_data)[i].particleIDs_end;
    for (const auto& it : (*m_rel_particleIDs_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[2]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].shapeParameters_begin = shapeParameters_index;
    (*m_data)[i].shapeParameters_end += shapeParameters_index;
    shapeParameters_index = (*m_data)[i].shapeParameters_end;
    for (const auto& it : (*m_vecs_shapeParameters[i])) { m_vec_shapeParameters->push_back(it); }

    (*m_data)[i].hitContributions_begin = hitContributions_index;
    (*m_data)[i].hitContributions_end += hitContributions_index;
    hitContributions_index = (*m_data)[i].hitContributions_end;
    for (const auto& it : (*m_vecs_hitContributions[i])) { m_vec_hitContributions->push_back(it); }

    (*m_data)[i].subdetectorEnergies_begin = subdetectorEnergies_index;
    (*m_data)[i].subdetectorEnergies_end += subdetectorEnergies_index;
    subdetectorEnergies_index = (*m_data)[i].subdetectorEnergies_end;
    for (const auto& it : (*m_vecs_subdetectorEnergies[i])) { m_vec_subdetectorEnergies->push_back(it); }

  }
}

void ClusterCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new ClusterObj({index, m_collectionID}, data);

    obj->m_clusters = m_rel_clusters;
    obj->m_hits = m_rel_hits;
    obj->m_particleIDs = m_rel_particleIDs;
    obj->m_shapeParameters = m_vec_shapeParameters;
    obj->m_hitContributions = m_vec_hitContributions;
    obj->m_subdetectorEnergies = m_vec_subdetectorEnergies;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool ClusterCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
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
      edm4hep::CalorimeterHitCollection* tmp_coll = static_cast<edm4hep::CalorimeterHitCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_hits->emplace_back(tmp);
    } else {
      m_rel_hits->emplace_back(nullptr);
    }
  }

  for (unsigned int i = 0, size = m_refCollections[2]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[2])[i];
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


  return true; //TODO: check success
}

void ClusterCollection::push_back(ConstCluster object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

    m_rel_clusters_tmp.push_back(obj->m_clusters);
    m_rel_hits_tmp.push_back(obj->m_hits);
    m_rel_particleIDs_tmp.push_back(obj->m_particleIDs);
    m_vecs_shapeParameters.push_back(obj->m_shapeParameters);
    m_vecs_hitContributions.push_back(obj->m_hitContributions);
    m_vecs_subdetectorEnergies.push_back(obj->m_subdetectorEnergies);
  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void ClusterCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<ClusterDataContainer*>(address);
}

Cluster ClusterCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

Cluster* ClusterCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

ClusterCollectionIterator& ClusterCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstCluster ClusterConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstCluster* ClusterConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

ClusterConstCollectionIterator& ClusterConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const ClusterCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:        type:      energy: energyError:                 position [ x, y, z]:positionError:      iTheta:         phi:           directionError [ x, y, z]:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getType() << " "
      << std::setw(12) << v[i].getEnergy() << " "
      << std::setw(12) << v[i].getEnergyError() << " "
      << std::setw(12) << v[i].getPosition() << " "
      << std::setw(12) << v[i].getITheta() << " "
      << std::setw(12) << v[i].getPhi() << " "
      << std::setw(12) << v[i].getDirectionError() << " "
      << std::endl;

    o << "      clusters : ";
    for (unsigned j = 0, N = v[i].clusters_size(); j < N; ++j) {
      o << v[i].getClusters(j).id() << " ";
    }
    o << std::endl;
    o << "      hits : ";
    for (unsigned j = 0, N = v[i].hits_size(); j < N; ++j) {
      o << v[i].getHits(j).id() << " ";
    }
    o << std::endl;
    o << "      particleIDs : ";
    for (unsigned j = 0, N = v[i].particleIDs_size(); j < N; ++j) {
      o << v[i].getParticleIDs(j).id() << " ";
    }
    o << std::endl;


    o << "      shapeParameters : ";
    for (unsigned j = 0, N = v[i].shapeParameters_size(); j < N; ++j) {
      o << v[i].getShapeParameters(j) << " ";
    }
    o << std::endl;
    o << "      hitContributions : ";
    for (unsigned j = 0, N = v[i].hitContributions_size(); j < N; ++j) {
      o << v[i].getHitContributions(j) << " ";
    }
    o << std::endl;
    o << "      subdetectorEnergies : ";
    for (unsigned j = 0, N = v[i].subdetectorEnergies_size(); j < N; ++j) {
      o << v[i].getSubdetectorEnergies(j) << " ";
    }
    o << std::endl;

  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

