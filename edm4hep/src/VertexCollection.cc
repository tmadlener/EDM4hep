// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#include "edm4hep/VertexCollection.h"

#include "edm4hep/ReconstructedParticleCollection.h"
#include <numeric>

// standard includes
#include <stdexcept>
#include <iomanip>

namespace edm4hep {


VertexCollection::VertexCollection() :
  m_isValid(false), m_isReadFromFile(false), m_collectionID(0), m_entries(),
  m_rel_associatedParticle(new std::vector<edm4hep::ConstReconstructedParticle>()),
  m_vec_parameters(new std::vector<float>()),
  m_data(new VertexDataContainer()) {
  m_refCollections.push_back(new std::vector<podio::ObjectID>());
  m_vecmem_info.emplace_back("float", &m_vec_parameters);
}

VertexCollection::~VertexCollection() {
  clear();
  if (m_data) delete m_data;
  for (auto& pointer : m_refCollections) { if (pointer) delete pointer; }
  if (m_rel_associatedParticle) delete m_rel_associatedParticle;
  if (m_vec_parameters) delete m_vec_parameters;
}

ConstVertex VertexCollection::operator[](unsigned int index) const {
  return ConstVertex(m_entries[index]);
}

ConstVertex VertexCollection::at(unsigned int index) const {
  return ConstVertex(m_entries.at(index));
}

Vertex VertexCollection::operator[](unsigned int index) {
  return Vertex(m_entries[index]);
}

Vertex VertexCollection::at(unsigned int index) {
  return Vertex(m_entries.at(index));
}

size_t VertexCollection::size() const {
  return m_entries.size();
}

Vertex VertexCollection::create() {
  auto obj = m_entries.emplace_back(new VertexObj());
  m_vecs_parameters.push_back(obj->m_parameters);

  obj->id = {int(m_entries.size() - 1), m_collectionID};
  return Vertex(obj);
}

void VertexCollection::clear() {
  m_data->clear();
  for (auto& pointer : m_refCollections) { pointer->clear(); }
  for (auto& item : (*m_rel_associatedParticle)) { item.unlink(); }
  m_rel_associatedParticle->clear();

  m_vec_parameters->clear();
  for (auto& vec : m_vecs_parameters) { delete vec; }
  m_vecs_parameters.clear();

  for (auto& obj : m_entries) { delete obj; }
  m_entries.clear();
}

void VertexCollection::prepareForWrite() {
  m_data->reserve(m_entries.size());
  for (auto& obj : m_entries) { m_data->push_back(obj->data); }

  // if the collection has been read from a file the rest of the information is
  // already in the correct format and we have to skip it, since the temporary
  // buffers are invalid
  if (m_isReadFromFile) return;
  for (auto& pointer : m_refCollections) { pointer->clear(); }

  const auto parameters_size = std::accumulate(m_entries.begin(), m_entries.end(), 0, [](size_t sum, const VertexObj* obj) { return sum + obj->m_parameters->size(); });
  m_vec_parameters->reserve(parameters_size);
  int parameters_index = 0;
  for (size_t i = 0, size = m_data->size(); i != size; ++i) {
    (*m_data)[i].parameters_begin = parameters_index;
    (*m_data)[i].parameters_end += parameters_index;
    parameters_index = (*m_data)[i].parameters_end;
    for (const auto& it : (*m_vecs_parameters[i])) { m_vec_parameters->push_back(it); }

  }
  for (auto& obj : m_entries) {
    if (obj->m_associatedParticle) {
      m_refCollections[0]->emplace_back(obj->m_associatedParticle->getObjectID());
    } else {
       m_refCollections[0]->push_back({podio::ObjectID::invalid, podio::ObjectID::invalid});
    }
  }

}

void VertexCollection::prepareAfterRead() {
  int index = 0;
  for (auto& data : *m_data) {
    auto obj = new VertexObj({index, m_collectionID}, data);

    obj->m_parameters = m_vec_parameters;
    m_entries.emplace_back(obj);
    ++index;
  }

  // at this point we are done with the I/O buffer and can safely clear it to not
  // have a redundant (but now useless) copy of the data
  m_data->clear();
  m_isReadFromFile = true;
}

bool VertexCollection::setReferences(const podio::ICollectionProvider* collectionProvider) {
  for (unsigned int i = 0, size = m_entries.size(); i != size; ++i) {
    const auto id = (*m_refCollections[0])[i];
    if (id.index != podio::ObjectID::invalid) {
        CollectionBase* coll = nullptr;
      collectionProvider->get(id.collectionID, coll);
      edm4hep::ReconstructedParticleCollection* tmp_coll = static_cast<edm4hep::ReconstructedParticleCollection*>(coll);
      m_entries[i]->m_associatedParticle = new ConstReconstructedParticle((*tmp_coll)[id.index]);
    } else {
      m_entries[i]->m_associatedParticle = nullptr;
    }
  }


  return true; //TODO: check success
}

void VertexCollection::push_back(ConstVertex object) {
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

void VertexCollection::setBuffer(void* address) {
  if (m_data) delete m_data;
  m_data = static_cast<VertexDataContainer*>(address);
}

Vertex VertexCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

Vertex* VertexCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

VertexCollectionIterator& VertexCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



ConstVertex VertexConstCollectionIterator::operator*() {
  m_object.m_obj = (*m_collection)[m_index];
  return m_object;
}

ConstVertex* VertexConstCollectionIterator::operator->() {
  m_object.m_obj = (*m_collection)[m_index];
  return &m_object;
}

VertexConstCollectionIterator& VertexConstCollectionIterator::operator++() {
  ++m_index;
  return *this;
}



std::ostream& operator<<(std::ostream& o, const VertexCollection& v) {
  const auto old_flags = o.flags();
  o << "          id:     primary:        chi2: probability:                 position [ x, y, z]:   covMatrix:algorithmType:" << '\n';

  for (size_t i = 0; i < v.size(); ++i) {
    o << std::scientific << std::showpos << std::setw(12) << v[i].id() << " "
      << std::setw(12) << v[i].getPrimary() << " "
      << std::setw(12) << v[i].getChi2() << " "
      << std::setw(12) << v[i].getProbability() << " "
      << std::setw(12) << v[i].getPosition() << " "
      << std::setw(12) << v[i].getAlgorithmType() << " "
      << std::endl;


    o << "      associatedParticle : ";
    o << v[i].getAssociatedParticle().id() << std::endl;

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

