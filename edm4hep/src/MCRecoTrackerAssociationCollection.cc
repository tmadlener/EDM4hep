// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCRecoTrackerAssociationCollection.h"

#include "edm4hep/SimTrackerHitCollection.h"
#include "edm4hep/TrackerHitCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


MCRecoTrackerAssociationCollection::MCRecoTrackerAssociationCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_rec(new std::vector<edm4hep::ConstTrackerHit>()),
  m_rel_sim(new std::vector<edm4hep::ConstSimTrackerHit>()),
  m_data(new MCRecoTrackerAssociationDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

MCRecoTrackerAssociationCollection::~MCRecoTrackerAssociationCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_rec) delete m_rel_rec;
  if (m_rel_sim) delete m_rel_sim;
}

ConstMCRecoTrackerAssociation MCRecoTrackerAssociationCollection::operator[](unsigned int index) const {
  return ConstMCRecoTrackerAssociation(m_entries[index]);
}

ConstMCRecoTrackerAssociation MCRecoTrackerAssociationCollection::at(unsigned int index) const {
  return ConstMCRecoTrackerAssociation(m_entries.at(index));
}

MCRecoTrackerAssociation MCRecoTrackerAssociationCollection::operator[](unsigned int index) {
  return MCRecoTrackerAssociation(m_entries[index]);
}

MCRecoTrackerAssociation MCRecoTrackerAssociationCollection::at(unsigned int index) {
  return MCRecoTrackerAssociation(m_entries.at(index));
}

size_t MCRecoTrackerAssociationCollection::size() const {
  return m_entries.size();
}

MCRecoTrackerAssociation MCRecoTrackerAssociationCollection::create() {
  auto obj = m_entries.emplace_back(new MCRecoTrackerAssociationObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return MCRecoTrackerAssociation(obj);
}

void MCRecoTrackerAssociationCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  for (auto& item : (*m_rel_rec)) { item.unlink(); }
  m_rel_rec->clear();

  for (auto& item : (*m_rel_sim)) { item.unlink(); }
  m_rel_sim->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void MCRecoTrackerAssociationCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }


  for (auto& obj : m_entries) {
    if (obj->m_rec) {
      m_refCollections[0]->emplace_back(obj->m_rec->getObjectID());
    } else {
       m_refCollections[0]->push_back({podio::ObjectID::invalid, podio::ObjectID::invalid});
    }
  }

  for (auto& obj : m_entries) {
    if (obj->m_sim) {
      m_refCollections[1]->emplace_back(obj->m_sim->getObjectID());
    } else {
       m_refCollections[1]->push_back({podio::ObjectID::invalid, podio::ObjectID::invalid});
    }
  }

}

void MCRecoTrackerAssociationCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new MCRecoTrackerAssociationObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool MCRecoTrackerAssociationCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::TrackerHitCollection* tmp_coll = static_cast<edm4hep::TrackerHitCollection*>(coll);
      m_entries[i]->m_rec = new ConstTrackerHit((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_rec = nullptr;
    }
  }

  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[1])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::SimTrackerHitCollection* tmp_coll = static_cast<edm4hep::SimTrackerHitCollection*>(coll);
      m_entries[i]->m_sim = new ConstSimTrackerHit((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_sim = nullptr;
    }
  }


  return true; //TODO: check success
}

void MCRecoTrackerAssociationCollection::push_back(ConstMCRecoTrackerAssociation object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void MCRecoTrackerAssociationCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<MCRecoTrackerAssociationDataContainer*>(address);
}

MCRecoTrackerAssociation MCRecoTrackerAssociationCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

MCRecoTrackerAssociation* MCRecoTrackerAssociationCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

MCRecoTrackerAssociationCollectionIterator& MCRecoTrackerAssociationCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstMCRecoTrackerAssociation MCRecoTrackerAssociationConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstMCRecoTrackerAssociation* MCRecoTrackerAssociationConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

MCRecoTrackerAssociationConstCollectionIterator& MCRecoTrackerAssociationConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const MCRecoTrackerAssociationCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      weight:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getWeight() << " "
      << std::endl;


    o << "      rec : ";
    o << v[i].getRec().id() << std::endl;
    o << "      sim : ";
    o << v[i].getSim().id() << std::endl;


  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

