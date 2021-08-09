// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/SimCalorimeterHitCollection.h"

#include "edm4hep/CaloHitContributionCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


SimCalorimeterHitCollection::SimCalorimeterHitCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_contributions(new std::vector<edm4hep::ConstCaloHitContribution>()),
  m_data(new SimCalorimeterHitDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

SimCalorimeterHitCollection::~SimCalorimeterHitCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_contributions) delete m_rel_contributions;
}

ConstSimCalorimeterHit SimCalorimeterHitCollection::operator[](unsigned int index) const {
  return ConstSimCalorimeterHit(m_entries[index]);
}

ConstSimCalorimeterHit SimCalorimeterHitCollection::at(unsigned int index) const {
  return ConstSimCalorimeterHit(m_entries.at(index));
}

SimCalorimeterHit SimCalorimeterHitCollection::operator[](unsigned int index) {
  return SimCalorimeterHit(m_entries[index]);
}

SimCalorimeterHit SimCalorimeterHitCollection::at(unsigned int index) {
  return SimCalorimeterHit(m_entries.at(index));
}

size_t SimCalorimeterHitCollection::size() const {
  return m_entries.size();
}

SimCalorimeterHit SimCalorimeterHitCollection::create() {
  auto obj = m_entries.emplace_back(new SimCalorimeterHitObj());
  m_rel_contributions_tmp.push_back(obj->m_contributions);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return SimCalorimeterHit(obj);
}

void SimCalorimeterHitCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  // clear relations to contributions. Make sure to unlink() the reference data as they may be gone already.
  for (auto& pointer : m_rel_contributions_tmp) {
    for (auto& item : *pointer) {
      item.unlink();
    }
    delete pointer;
  }
  m_rel_contributions_tmp.clear();
  for (auto& item : (*m_rel_contributions)) { item.unlink(); }
  m_rel_contributions->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void SimCalorimeterHitCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  int contributions_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].contributions_begin = contributions_index;
    (*m_data)[i].contributions_end += contributions_index;
    contributions_index = (*m_data)[i].contributions_end;
    for (const auto& it : (*m_rel_contributions_tmp[i])) {
      if (it.getObjectID().index == podio::ObjectID::untracked) {
        throw std::runtime_error("Trying to persistify untracked object");
      }
      m_refCollections[0]->emplace_back(it.getObjectID());
    }

  }
}

void SimCalorimeterHitCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new SimCalorimeterHitObj({index, m_collectionID}, data);

    obj->m_contributions = m_rel_contributions;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool SimCalorimeterHitCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_refCollections[0]->size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
      CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::CaloHitContributionCollection* tmp_coll = static_cast<edm4hep::CaloHitContributionCollection*>(coll);
      const auto tmp = (*tmp_coll)[id.index];
      m_rel_contributions->emplace_back(tmp);
    } else {
      m_rel_contributions->emplace_back(nullptr);
    }
  }


  return true; //TODO: check success
}

void SimCalorimeterHitCollection::push_back(ConstSimCalorimeterHit object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

    m_rel_contributions_tmp.push_back(obj->m_contributions);
  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void SimCalorimeterHitCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<SimCalorimeterHitDataContainer*>(address);
}

SimCalorimeterHit SimCalorimeterHitCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

SimCalorimeterHit* SimCalorimeterHitCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

SimCalorimeterHitCollectionIterator& SimCalorimeterHitCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstSimCalorimeterHit SimCalorimeterHitConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstSimCalorimeterHit* SimCalorimeterHitConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

SimCalorimeterHitConstCollectionIterator& SimCalorimeterHitConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const SimCalorimeterHitCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:      energy:                 position [ x, y, z]:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getCellID() << " "
      << std::setw(12) << v[i].getEnergy() << " "
      << std::setw(12) << v[i].getPosition() << " "
      << std::endl;

    o << "      contributions : ";
    for (unsigned j = 0, N = v[i].contributions_size(); j < N; ++j) {
      o << v[i].getContributions(j).id() << " ";
    }
    o << std::endl;



  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

