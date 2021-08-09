// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RecoParticleRefCollection.h"

#include "edm4hep/ReconstructedParticleCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


RecoParticleRefCollection::RecoParticleRefCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_particle(new std::vector<edm4hep::ConstReconstructedParticle>()),
  m_data(new RecoParticleRefDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

RecoParticleRefCollection::~RecoParticleRefCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_particle) delete m_rel_particle;
}

ConstRecoParticleRef RecoParticleRefCollection::operator[](unsigned int index) const {
  return ConstRecoParticleRef(m_entries[index]);
}

ConstRecoParticleRef RecoParticleRefCollection::at(unsigned int index) const {
  return ConstRecoParticleRef(m_entries.at(index));
}

RecoParticleRef RecoParticleRefCollection::operator[](unsigned int index) {
  return RecoParticleRef(m_entries[index]);
}

RecoParticleRef RecoParticleRefCollection::at(unsigned int index) {
  return RecoParticleRef(m_entries.at(index));
}

size_t RecoParticleRefCollection::size() const {
  return m_entries.size();
}

RecoParticleRef RecoParticleRefCollection::create() {
  auto obj = m_entries.emplace_back(new RecoParticleRefObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return RecoParticleRef(obj);
}

void RecoParticleRefCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  for (auto& item : (*m_rel_particle)) { item.unlink(); }
  m_rel_particle->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void RecoParticleRefCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }


  for (auto& obj : m_entries) {
    if (obj->m_particle) {
      m_refCollections[0]->emplace_back(obj->m_particle->getObjectID());
    } else {
       m_refCollections[0]->push_back({podio::ObjectID::invalid, podio::ObjectID::invalid});
    }
  }

}

void RecoParticleRefCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new RecoParticleRefObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool RecoParticleRefCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::ReconstructedParticleCollection* tmp_coll = static_cast<edm4hep::ReconstructedParticleCollection*>(coll);
      m_entries[i]->m_particle = new ConstReconstructedParticle((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_particle = nullptr;
    }
  }


  return true; //TODO: check success
}

void RecoParticleRefCollection::push_back(ConstRecoParticleRef object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void RecoParticleRefCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<RecoParticleRefDataContainer*>(address);
}

RecoParticleRef RecoParticleRefCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

RecoParticleRef* RecoParticleRefCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

RecoParticleRefCollectionIterator& RecoParticleRefCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstRecoParticleRef RecoParticleRefConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstRecoParticleRef* RecoParticleRefConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

RecoParticleRefConstCollectionIterator& RecoParticleRefConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const RecoParticleRefCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::endl;


    o << "      particle : ";
    o << v[i].getParticle().id() << std::endl;


  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

