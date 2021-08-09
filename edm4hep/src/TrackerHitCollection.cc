// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/TrackerHitCollection.h"

#include <numeric>

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


TrackerHitCollection::TrackerHitCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_vec_rawHits(new std::vector<edm4hep::ObjectID>()),
  m_data(new TrackerHitDataContainer()) {
  m_vecmem_info.emplace_back("edm4hep::ObjectID", &m_vec_rawHits);
}

TrackerHitCollection::~TrackerHitCollection() {
  clear();
  if (m_data) delete m_data;
  if (m_vec_rawHits) delete m_vec_rawHits;
}

ConstTrackerHit TrackerHitCollection::operator[](unsigned int index) const {
  return ConstTrackerHit(m_entries[index]);
}

ConstTrackerHit TrackerHitCollection::at(unsigned int index) const {
  return ConstTrackerHit(m_entries.at(index));
}

TrackerHit TrackerHitCollection::operator[](unsigned int index) {
  return TrackerHit(m_entries[index]);
}

TrackerHit TrackerHitCollection::at(unsigned int index) {
  return TrackerHit(m_entries.at(index));
}

size_t TrackerHitCollection::size() const {
  return m_entries.size();
}

TrackerHit TrackerHitCollection::create() {
  auto obj = m_entries.emplace_back(new TrackerHitObj());
  m_vecs_rawHits.push_back(obj->m_rawHits);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return TrackerHit(obj);
}

void TrackerHitCollection::clear() {
  m_data->clear();
  m_vec_rawHits->clear();
  for (auto& vec : m_vecs_rawHits) { delete vec; }
  m_vecs_rawHits.clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void TrackerHitCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  const auto rawHits_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const TrackerHitObj* obj) { return sum + obj->m_rawHits->size(); });
  m_vec_rawHits->reserve(rawHits_size);
  int rawHits_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].rawHits_begin = rawHits_index;
    (*m_data)[i].rawHits_end += rawHits_index;
    rawHits_index = (*m_data)[i].rawHits_end;
    for (const auto& it : (*m_vecs_rawHits[i])) { m_vec_rawHits->push_back(it); }

  }
}

void TrackerHitCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new TrackerHitObj({index, m_collectionID}, data);

    obj->m_rawHits = m_vec_rawHits;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool TrackerHitCollection::setReferences(const podio::ICollectionProvider* ) {

  return true; //TODO: check success
}

void TrackerHitCollection::push_back(ConstTrackerHit object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

    m_vecs_rawHits.push_back(obj->m_rawHits);
  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void TrackerHitCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<TrackerHitDataContainer*>(address);
}

TrackerHit TrackerHitCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

TrackerHit* TrackerHitCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

TrackerHitCollectionIterator& TrackerHitCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstTrackerHit TrackerHitConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstTrackerHit* TrackerHitConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

TrackerHitConstCollectionIterator& TrackerHitConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const TrackerHitCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:      cellID:        type:     quality:        time:        eDep:   eDepError:         edx:                 position [ x, y, z]:   covMatrix:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getCellID() << " "
      << std::setw(12) << v[i].getType() << " "
      << std::setw(12) << v[i].getQuality() << " "
      << std::setw(12) << v[i].getTime() << " "
      << std::setw(12) << v[i].getEDep() << " "
      << std::setw(12) << v[i].getEDepError() << " "
      << std::setw(12) << v[i].getEdx() << " "
      << std::setw(12) << v[i].getPosition() << " "
      << std::endl;



    o << "      rawHits : ";
    for (unsigned j = 0, N = v[i].rawHits_size(); j < N; ++j) {
      o << v[i].getRawHits(j) << " ";
    }
    o << std::endl;

  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

