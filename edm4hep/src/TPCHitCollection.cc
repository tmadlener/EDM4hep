// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TPCHitCollection.h"

#include <numeric>

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


TPCHitCollection::TPCHitCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_vec_rawDataWords(new std::vector<int>()),
  m_data(new TPCHitDataContainer()) {
  m_vecmem_info.emplace_back("int", &m_vec_rawDataWords);
}

TPCHitCollection::~TPCHitCollection() {
  clear();
  if (m_data) delete m_data;
  if (m_vec_rawDataWords) delete m_vec_rawDataWords;
}

ConstTPCHit TPCHitCollection::operator[](unsigned int index) const {
  return ConstTPCHit(m_entries[index]);
}

ConstTPCHit TPCHitCollection::at(unsigned int index) const {
  return ConstTPCHit(m_entries.at(index));
}

TPCHit TPCHitCollection::operator[](unsigned int index) {
  return TPCHit(m_entries[index]);
}

TPCHit TPCHitCollection::at(unsigned int index) {
  return TPCHit(m_entries.at(index));
}

size_t TPCHitCollection::size() const {
  return m_entries.size();
}

TPCHit TPCHitCollection::create() {
  auto obj = m_entries.emplace_back(new TPCHitObj());
  m_vecs_rawDataWords.push_back(obj->m_rawDataWords);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return TPCHit(obj);
}

void TPCHitCollection::clear() {
  m_data->clear();
  m_vec_rawDataWords->clear();
  for (auto& vec : m_vecs_rawDataWords) { delete vec; }
  m_vecs_rawDataWords.clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void TPCHitCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  const auto rawDataWords_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const TPCHitObj* obj) { return sum + obj->m_rawDataWords->size(); });
  m_vec_rawDataWords->reserve(rawDataWords_size);
  int rawDataWords_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].rawDataWords_begin = rawDataWords_index;
    (*m_data)[i].rawDataWords_end += rawDataWords_index;
    rawDataWords_index = (*m_data)[i].rawDataWords_end;
    for (const auto& it : (*m_vecs_rawDataWords[i])) { m_vec_rawDataWords->push_back(it); }

  }
}

void TPCHitCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new TPCHitObj({index, m_collectionID}, data);

    obj->m_rawDataWords = m_vec_rawDataWords;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool TPCHitCollection::setReferences(const podio::ICollectionProvider* ) {

  return true; //TODO: check success
}

void TPCHitCollection::push_back(ConstTPCHit object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

    m_vecs_rawDataWords.push_back(obj->m_rawDataWords);
  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void TPCHitCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<TPCHitDataContainer*>(address);
}

TPCHit TPCHitCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

TPCHit* TPCHitCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

TPCHitCollectionIterator& TPCHitCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstTPCHit TPCHitConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstTPCHit* TPCHitConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

TPCHitConstCollectionIterator& TPCHitConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const TPCHitCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:     quality:        time:      charge:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getCellID() << " "
      << std::setw(12) << v[i].getQuality() << " "
      << std::setw(12) << v[i].getTime() << " "
      << std::setw(12) << v[i].getCharge() << " "
      << std::endl;



    o << "      rawDataWords : ";
    for (unsigned j = 0, N = v[i].rawDataWords_size(); j < N; ++j) {
      o << v[i].getRawDataWords(j) << " ";
    }
    o << std::endl;

  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

