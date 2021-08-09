// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/CalorimeterHitCollection.h"


// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


CalorimeterHitCollection::CalorimeterHitCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_data(new CalorimeterHitDataContainer()) {
}

CalorimeterHitCollection::~CalorimeterHitCollection() {
  clear();
  if (m_data) delete m_data;
}

ConstCalorimeterHit CalorimeterHitCollection::operator[](unsigned int index) const {
  return ConstCalorimeterHit(m_entries[index]);
}

ConstCalorimeterHit CalorimeterHitCollection::at(unsigned int index) const {
  return ConstCalorimeterHit(m_entries.at(index));
}

CalorimeterHit CalorimeterHitCollection::operator[](unsigned int index) {
  return CalorimeterHit(m_entries[index]);
}

CalorimeterHit CalorimeterHitCollection::at(unsigned int index) {
  return CalorimeterHit(m_entries.at(index));
}

size_t CalorimeterHitCollection::size() const {
  return m_entries.size();
}

CalorimeterHit CalorimeterHitCollection::create() {
  auto obj = m_entries.emplace_back(new CalorimeterHitObj());

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return CalorimeterHit(obj);
}

void CalorimeterHitCollection::clear() {
  m_data->clear();
  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void CalorimeterHitCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }


}

void CalorimeterHitCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new CalorimeterHitObj({index, m_collectionID}, data);

    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool CalorimeterHitCollection::setReferences(const podio::ICollectionProvider* ) {

  return true; //TODO: check success
}

void CalorimeterHitCollection::push_back(ConstCalorimeterHit object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void CalorimeterHitCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<CalorimeterHitDataContainer*>(address);
}

CalorimeterHit CalorimeterHitCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

CalorimeterHit* CalorimeterHitCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

CalorimeterHitCollectionIterator& CalorimeterHitCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstCalorimeterHit CalorimeterHitConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstCalorimeterHit* CalorimeterHitConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

CalorimeterHitConstCollectionIterator& CalorimeterHitConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const CalorimeterHitCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:      energy: energyError:        time:                 position [ x, y, z]:        type:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getCellID() << " "
      << std::setw(12) << v[i].getEnergy() << " "
      << std::setw(12) << v[i].getEnergyError() << " "
      << std::setw(12) << v[i].getTime() << " "
      << std::setw(12) << v[i].getPosition() << " "
      << std::setw(12) << v[i].getType() << " "
      << std::endl;




  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

