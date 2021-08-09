// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/MCRecoCaloAssociationCollection.h"

#include "edm4hep/CalorimeterHitCollection.h"
#include "edm4hep/SimCalorimeterHitCollection.h"

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


MCRecoCaloAssociationCollection::MCRecoCaloAssociationCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_rec(new std::vector<edm4hep::ConstCalorimeterHit>()),
  m_rel_sim(new std::vector<edm4hep::ConstSimCalorimeterHit>()),
  m_data(new MCRecoCaloAssociationDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
}

MCRecoCaloAssociationCollection::~MCRecoCaloAssociationCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_rec) delete m_rel_rec;
  if (m_rel_sim) delete m_rel_sim;
}

ConstMCRecoCaloAssociation MCRecoCaloAssociationCollection::operator[](unsigned int index) const {
  return ConstMCRecoCaloAssociation(m_entries[index]);
}

ConstMCRecoCaloAssociation MCRecoCaloAssociationCollection::at(unsigned int index) const {
  return ConstMCRecoCaloAssociation(m_entries.at(index));
}

MCRecoCaloAssociation MCRecoCaloAssociationCollection::operator[](unsigned int index) {
  return MCRecoCaloAssociation(m_entries[index]);
}

MCRecoCaloAssociation MCRecoCaloAssociationCollection::at(unsigned int index) {
  return MCRecoCaloAssociation(m_entries.at(index));
}

size_t MCRecoCaloAssociationCollection::size() const {
  return m_entries.size();
}

MCRecoCaloAssociation MCRecoCaloAssociationCollection::create() {
  auto obj = m_entries.emplace_back(new MCRecoCaloAssociationObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return MCRecoCaloAssociation(obj);
}

void MCRecoCaloAssociationCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  for (auto& item : (*m_rel_rec)) { item.unlink(); }
  m_rel_rec->clear();

  for (auto& item : (*m_rel_sim)) { item.unlink(); }
  m_rel_sim->clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void MCRecoCaloAssociationCollection::prepareForWrite() {
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

void MCRecoCaloAssociationCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new MCRecoCaloAssociationObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool MCRecoCaloAssociationCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::CalorimeterHitCollection* tmp_coll = static_cast<edm4hep::CalorimeterHitCollection*>(coll);
      m_entries[i]->m_rec = new ConstCalorimeterHit((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_rec = nullptr;
    }
  }

  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[1])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::SimCalorimeterHitCollection* tmp_coll = static_cast<edm4hep::SimCalorimeterHitCollection*>(coll);
      m_entries[i]->m_sim = new ConstSimCalorimeterHit((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_sim = nullptr;
    }
  }


  return true; //TODO: check success
}

void MCRecoCaloAssociationCollection::push_back(ConstMCRecoCaloAssociation object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void MCRecoCaloAssociationCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<MCRecoCaloAssociationDataContainer*>(address);
}

MCRecoCaloAssociation MCRecoCaloAssociationCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

MCRecoCaloAssociation* MCRecoCaloAssociationCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

MCRecoCaloAssociationCollectionIterator& MCRecoCaloAssociationCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstMCRecoCaloAssociation MCRecoCaloAssociationConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstMCRecoCaloAssociation* MCRecoCaloAssociationConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

MCRecoCaloAssociationConstCollectionIterator& MCRecoCaloAssociationConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const MCRecoCaloAssociationCollection& v) {
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

