// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/CaloHitContributionCollection.h"

#include "edm4hep/MCParticleCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


CaloHitContributionCollection::CaloHitContributionCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_particle(new std::vector<edm4hep::ConstMCParticle>()),
  m_data(new CaloHitContributionDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

CaloHitContributionCollection::~CaloHitContributionCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_particle) delete m_rel_particle;
}

ConstCaloHitContribution CaloHitContributionCollection::operator[](unsigned int index) const {
  return ConstCaloHitContribution(m_entries[index]);
}

ConstCaloHitContribution CaloHitContributionCollection::at(unsigned int index) const {
  return ConstCaloHitContribution(m_entries.at(index));
}

CaloHitContribution CaloHitContributionCollection::operator[](unsigned int index) {
  return CaloHitContribution(m_entries[index]);
}

CaloHitContribution CaloHitContributionCollection::at(unsigned int index) {
  return CaloHitContribution(m_entries.at(index));
}

size_t CaloHitContributionCollection::size() const {
  return m_entries.size();
}

CaloHitContribution CaloHitContributionCollection::create() {
  auto obj = m_entries.emplace_back(new CaloHitContributionObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return CaloHitContribution(obj);
}

void CaloHitContributionCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  for (auto& item : (*m_rel_particle)) { item.unlink(); }
  m_rel_particle->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void CaloHitContributionCollection::prepareForWrite() {
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

void CaloHitContributionCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new CaloHitContributionObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool CaloHitContributionCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::MCParticleCollection* tmp_coll = static_cast<edm4hep::MCParticleCollection*>(coll);
      m_entries[i]->m_particle = new ConstMCParticle((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_particle = nullptr;
    }
  }


  return true; //TODO: check success
}

void CaloHitContributionCollection::push_back(ConstCaloHitContribution object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void CaloHitContributionCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<CaloHitContributionDataContainer*>(address);
}

CaloHitContribution CaloHitContributionCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

CaloHitContribution* CaloHitContributionCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

CaloHitContributionCollectionIterator& CaloHitContributionCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstCaloHitContribution CaloHitContributionConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstCaloHitContribution* CaloHitContributionConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

CaloHitContributionConstCollectionIterator& CaloHitContributionConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const CaloHitContributionCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:         PDG:      energy:        time:             stepPosition [ x, y, z]:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getPDG() << " "
      << std::setw(12) << v[i].getEnergy() << " "
      << std::setw(12) << v[i].getTime() << " "
      << std::setw(12) << v[i].getStepPosition() << " "
      << std::endl;


    o << "      particle : ";
    o << v[i].getParticle().id() << std::endl;


  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

