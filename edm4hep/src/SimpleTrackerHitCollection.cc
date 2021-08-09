// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/SimpleTrackerHitCollection.h"


// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


SimpleTrackerHitCollection::SimpleTrackerHitCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_data(new SimpleTrackerHitDataContainer()) {
}

SimpleTrackerHitCollection::~SimpleTrackerHitCollection() {
  clear();
  if (m_data) delete m_data;
}

ConstSimpleTrackerHit SimpleTrackerHitCollection::operator[](unsigned int index) const {
  return ConstSimpleTrackerHit(m_entries[index]);
}

ConstSimpleTrackerHit SimpleTrackerHitCollection::at(unsigned int index) const {
  return ConstSimpleTrackerHit(m_entries.at(index));
}

SimpleTrackerHit SimpleTrackerHitCollection::operator[](unsigned int index) {
  return SimpleTrackerHit(m_entries[index]);
}

SimpleTrackerHit SimpleTrackerHitCollection::at(unsigned int index) {
  return SimpleTrackerHit(m_entries.at(index));
}

size_t SimpleTrackerHitCollection::size() const {
  return m_entries.size();
}

SimpleTrackerHit SimpleTrackerHitCollection::create() {
  auto obj = m_entries.emplace_back(new SimpleTrackerHitObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return SimpleTrackerHit(obj);
}

void SimpleTrackerHitCollection::clear() {
  m_data->clear();
  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void SimpleTrackerHitCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }


}

void SimpleTrackerHitCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new SimpleTrackerHitObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool SimpleTrackerHitCollection::setReferences(const podio::ICollectionProvider* ) {

  return true; //TODO: check success
}

void SimpleTrackerHitCollection::push_back(ConstSimpleTrackerHit object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void SimpleTrackerHitCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<SimpleTrackerHitDataContainer*>(address);
}

SimpleTrackerHit SimpleTrackerHitCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

SimpleTrackerHit* SimpleTrackerHitCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

SimpleTrackerHitCollectionIterator& SimpleTrackerHitCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstSimpleTrackerHit SimpleTrackerHitConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstSimpleTrackerHit* SimpleTrackerHitConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

SimpleTrackerHitConstCollectionIterator& SimpleTrackerHitConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const SimpleTrackerHitCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:                 position [ x, y, z]:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getPosition() << " "
      << std::endl;




  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

