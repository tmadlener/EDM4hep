// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/ParticleIDCollection.h"

#include <numeric>

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


ParticleIDCollection::ParticleIDCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_vec_parameters(new std::vector<float>()),
  m_data(new ParticleIDDataContainer()) {
  m_vecmem_info.emplace_back("float", &m_vec_parameters);
}

ParticleIDCollection::~ParticleIDCollection() {
  clear();
  if (m_data) delete m_data;
  if (m_vec_parameters) delete m_vec_parameters;
}

ConstParticleID ParticleIDCollection::operator[](unsigned int index) const {
  return ConstParticleID(m_entries[index]);
}

ConstParticleID ParticleIDCollection::at(unsigned int index) const {
  return ConstParticleID(m_entries.at(index));
}

ParticleID ParticleIDCollection::operator[](unsigned int index) {
  return ParticleID(m_entries[index]);
}

ParticleID ParticleIDCollection::at(unsigned int index) {
  return ParticleID(m_entries.at(index));
}

size_t ParticleIDCollection::size() const {
  return m_entries.size();
}

ParticleID ParticleIDCollection::create() {
  auto obj = m_entries.emplace_back(new ParticleIDObj());
  m_vecs_parameters.push_back(obj->m_parameters);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return ParticleID(obj);
}

void ParticleIDCollection::clear() {
  m_data->clear();
  m_vec_parameters->clear();
  for (auto& vec : m_vecs_parameters) { delete vec; }
  m_vecs_parameters.clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void ParticleIDCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  const auto parameters_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const ParticleIDObj* obj) { return sum + obj->m_parameters->size(); });
  m_vec_parameters->reserve(parameters_size);
  int parameters_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].parameters_begin = parameters_index;
    (*m_data)[i].parameters_end += parameters_index;
    parameters_index = (*m_data)[i].parameters_end;
    for (const auto& it : (*m_vecs_parameters[i])) { m_vec_parameters->push_back(it); }

  }
}

void ParticleIDCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new ParticleIDObj({index, m_collectionID}, data);

    obj->m_parameters = m_vec_parameters;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool ParticleIDCollection::setReferences(const podio::ICollectionProvider* ) {

  return true; //TODO: check success
}

void ParticleIDCollection::push_back(ConstParticleID object) {
  const auto size = m_entries.size();
  auto obj = object.m_obj;
  if (obj->id.index == podio::ObjectID::untracked) {
    obj->id = {(int)size, m_collectionID};
    m_entries.push_back(obj);

    m_vecs_parameters.push_back(obj->m_parameters);
  } else {
    throw std::invalid_argument("Object already in a collection. Cannot add it to a second collection");
  }
}

void ParticleIDCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<ParticleIDDataContainer*>(address);
}

ParticleID ParticleIDCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ParticleID* ParticleIDCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

ParticleIDCollectionIterator& ParticleIDCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstParticleID ParticleIDConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstParticleID* ParticleIDConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

ParticleIDConstCollectionIterator& ParticleIDConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const ParticleIDCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:        type:         PDG:algorithmType:  likelihood:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getType() << " "
      << std::setw(12) << v[i].getPDG() << " "
      << std::setw(12) << v[i].getAlgorithmType() << " "
      << std::setw(12) << v[i].getLikelihood() << " "
      << std::endl;



    o << "      parameters : ";
    for (unsigned j = 0, N = v[i].parameters_size(); j < N; ++j) {
      o << v[i].getParameters(j) << " ";
    }
    o << std::endl;

  }

  o.flags(old_flags);
  return o;
}

} // namespace edm4hep

