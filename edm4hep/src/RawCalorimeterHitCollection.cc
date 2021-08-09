// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/RawCalorimeterHitCollection.h"


// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


RawCalorimeterHitCollection::RawCalorimeterHitCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_data(new RawCalorimeterHitDataContainer()) {
}

RawCalorimeterHitCollection::~RawCalorimeterHitCollection() {
  clear();
  if (m_data) delete m_data;
}

ConstRawCalorimeterHit RawCalorimeterHitCollection::operator[](unsigned int index) const {
  return ConstRawCalorimeterHit(m_entries[index]);
}

ConstRawCalorimeterHit RawCalorimeterHitCollection::at(unsigned int index) const {
  return ConstRawCalorimeterHit(m_entries.at(index));
}

RawCalorimeterHit RawCalorimeterHitCollection::operator[](unsigned int index) {
  return RawCalorimeterHit(m_entries[index]);
}

RawCalorimeterHit RawCalorimeterHitCollection::at(unsigned int index) {
  return RawCalorimeterHit(m_entries.at(index));
}

size_t RawCalorimeterHitCollection::size() const {
  return m_entries.size();
}

RawCalorimeterHit RawCalorimeterHitCollection::create() {
  auto obj = m_entries.emplace_back(new RawCalorimeterHitObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return RawCalorimeterHit(obj);
}

void RawCalorimeterHitCollection::clear() {
  m_data->clear();
  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void RawCalorimeterHitCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }


}

void RawCalorimeterHitCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new RawCalorimeterHitObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool RawCalorimeterHitCollection::setReferences(const podio::ICollectionProvider* ) {

  return true; //TODO: check success
}

void RawCalorimeterHitCollection::push_back(ConstRawCalorimeterHit object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void RawCalorimeterHitCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<RawCalorimeterHitDataContainer*>(address);
}

RawCalorimeterHit RawCalorimeterHitCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

RawCalorimeterHit* RawCalorimeterHitCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

RawCalorimeterHitCollectionIterator& RawCalorimeterHitCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstRawCalorimeterHit RawCalorimeterHitConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstRawCalorimeterHit* RawCalorimeterHitConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

RawCalorimeterHitConstCollectionIterator& RawCalorimeterHitConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const RawCalorimeterHitCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:   amplitude:   timeStamp:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getCellID() << " "
      << std::setw(12) << v[i].getAmplitude() << " "
      << std::setw(12) << v[i].getTimeStamp() << " "
      << std::endl;




  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

