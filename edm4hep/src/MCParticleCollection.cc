// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCParticleCollection.h"

#include "edm4hep/MCParticleCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


MCParticleCollection::MCParticleCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_parents(new std::vector<edm4hep::ConstMCParticle>()),
  m_rel_daughters(new std::vector<edm4hep::ConstMCParticle>()),
  m_data(new MCParticleDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

MCParticleCollection::~MCParticleCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_parents) delete m_rel_parents;
  if (m_rel_daughters) delete m_rel_daughters;
}

ConstMCParticle MCParticleCollection::operator[](unsigned int index) const {
  return ConstMCParticle(m_entries[index]);
}

ConstMCParticle MCParticleCollection::at(unsigned int index) const {
  return ConstMCParticle(m_entries.at(index));
}

MCParticle MCParticleCollection::operator[](unsigned int index) {
  return MCParticle(m_entries[index]);
}

MCParticle MCParticleCollection::at(unsigned int index) {
  return MCParticle(m_entries.at(index));
}

size_t MCParticleCollection::size() const {
  return m_entries.size();
}

MCParticle MCParticleCollection::create() {
  auto obj = m_entries.emplace_back(new MCParticleObj());
  m_rel_parents_tmp.push_back(obj->m_parents);
  m_rel_daughters_tmp.push_back(obj->m_daughters);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return MCParticle(obj);
}

void MCParticleCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  // clear relations to parents. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_parents_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_parents_tmp.clear();
  for (auto& item : (*m_rel_parents)) { item.unlink(); }
  m_rel_parents->clear();

  // clear relations to daughters. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_daughters_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_daughters_tmp.clear();
  for (auto& item : (*m_rel_daughters)) { item.unlink(); }
  m_rel_daughters->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void MCParticleCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  int parents_index = 0;
  int daughters_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].parents_begin = parents_index;
    (*m_data)[i].parents_end += parents_index;
    parents_index = (*m_data)[i].parents_end;
    for (const auto& it : (*m_rel_parents_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[0]->emplace_back(it.getObjectID());
    }

    (*m_data)[i].daughters_begin = daughters_index;
    (*m_data)[i].daughters_end += daughters_index;
    daughters_index = (*m_data)[i].daughters_end;
    for (const auto& it : (*m_rel_daughters_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[1]->emplace_back(it.getObjectID());
    }

  }
}

void MCParticleCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new MCParticleObj({index, m_collectionID}, data);

    obj->m_parents = m_rel_parents;
    obj->m_daughters = m_rel_daughters;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool MCParticleCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_refCollections[0]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
      CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::MCParticleCollection* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_parents->emplace_back(tmp);
    } else {
      m_rel_parents->emplace_back(nullptr);
    }
  }

  for (unsigned int i = 0, size = m_refCollections[1]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[1])[i];
    if (id.index != podio::ObjectID::invalid) {
      CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::MCParticleCollection* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_daughters->emplace_back(tmp);
    } else {
      m_rel_daughters->emplace_back(nullptr);
    }
  }


  return true; //TODO: check success
}

void MCParticleCollection::push_back(ConstMCParticle object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

    m_rel_parents_tmp.push_back(obj->m_parents);
    m_rel_daughters_tmp.push_back(obj->m_daughters);
  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void MCParticleCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<MCParticleDataContainer*>(address);
}

MCParticle MCParticleCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

MCParticle* MCParticleCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

MCParticleCollectionIterator& MCParticleCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstMCParticle MCParticleConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstMCParticle* MCParticleConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

MCParticleConstCollectionIterator& MCParticleConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const MCParticleCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:         PDG:generatorStatus:simulatorStatus:      charge:        time:        mass:                   vertex [ x, y, z]:                 endpoint [ x, y, z]:                 momentum [ x, y, z]:       momentumAtEndpoint [ x, y, z]:                     spin [ x, y, z]:       colorFlow [ a, b]:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getPDG() << " "
      << std::setw(12) << v[i].getGeneratorStatus() << " "
      << std::setw(12) << v[i].getSimulatorStatus() << " "
      << std::setw(12) << v[i].getCharge() << " "
      << std::setw(12) << v[i].getTime() << " "
      << std::setw(12) << v[i].getMass() << " "
      << std::setw(12) << v[i].getVertex() << " "
      << std::setw(12) << v[i].getEndpoint() << " "
      << std::setw(12) << v[i].getMomentum() << " "
      << std::setw(12) << v[i].getMomentumAtEndpoint() << " "
      << std::setw(12) << v[i].getSpin() << " "
      << std::setw(12) << v[i].getColorFlow() << " "
      << std::endl;

    o << "      parents : ";
    for (unsigned j = 0, N = v[i].parents_size(); j < N; ++j) {
      o << v[i].getParents(j).id() << " ";
    }
    o << std::endl;
    o << "      daughters : ";
    for (unsigned j = 0, N = v[i].daughters_size(); j < N; ++j) {
      o << v[i].getDaughters(j).id() << " ";
    }
    o << std::endl;



  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

