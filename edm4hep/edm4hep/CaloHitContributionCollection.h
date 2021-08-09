// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CaloHitContributionCollection_H
#define EDM4HEP_CaloHitContributionCollection_H

// datamodel specific includes
#include "edm4hep/CaloHitContributionData.h"
#include "edm4hep/CaloHitContribution.h"
#include "edm4hep/CaloHitContributionObj.h"

// podio specific includes
#include "podio/ICollectionProvider.h"
#include "podio/CollectionBase.h"
#include "podio/CollectionIDTable.h"

#include <string>
#include <vector>
#include <deque>
#include <array>
#include <algorithm>
#include <ostream>

namespace edm4hep {


using CaloHitContributionDataContainer = std::vector<CaloHitContributionData>;
using CaloHitContributionObjPointerContainer = std::deque<CaloHitContributionObj*>;

class CaloHitContributionCollectionIterator {
public:
  CaloHitContributionCollectionIterator(size_t index, const CaloHitContributionObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  CaloHitContributionCollectionIterator(const CaloHitContributionCollectionIterator&) = delete;
  CaloHitContributionCollectionIterator& operator=(const CaloHitContributionCollectionIterator&) = delete;

  bool operator!=(const CaloHitContributionCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  CaloHitContribution operator*();
  CaloHitContribution* operator->();
  CaloHitContributionCollectionIterator& operator++();

private:
  size_t m_index;
  CaloHitContribution m_object;
  const CaloHitContributionObjPointerContainer* m_collection;
};


class CaloHitContributionConstCollectionIterator {
public:
  CaloHitContributionConstCollectionIterator(size_t index, const CaloHitContributionObjPointerContainer* collection) : m_index(index), m_object(nullptr), m_collection(collection) {}

  CaloHitContributionConstCollectionIterator(const CaloHitContributionConstCollectionIterator&) = delete;
  CaloHitContributionConstCollectionIterator& operator=(const CaloHitContributionConstCollectionIterator&) = delete;

  bool operator!=(const CaloHitContributionConstCollectionIterator& x) const {
    return m_index != x.m_index; // TODO: may not be complete
  }

  ConstCaloHitContribution operator*();
  ConstCaloHitContribution* operator->();
  CaloHitContributionConstCollectionIterator& operator++();

private:
  size_t m_index;
  ConstCaloHitContribution m_object;
  const CaloHitContributionObjPointerContainer* m_collection;
};


/**
A Collection is identified by an ID.
*/
class CaloHitContributionCollection : public podio::CollectionBase {

public:
  using const_iterator = CaloHitContributionConstCollectionIterator;
  using iterator = CaloHitContributionCollectionIterator;

  CaloHitContributionCollection();
  CaloHitContributionCollection(const CaloHitContributionCollection& ) = delete;
  CaloHitContributionCollection& operator=(const CaloHitContributionCollection& ) = delete;
//  CaloHitContributionCollection(CaloHitContributionVector* data, int collectionID);
  ~CaloHitContributionCollection();

  void clear() override final;

  /// operator to allow pointer like calling of members a la LCIO
  CaloHitContributionCollection* operator->() { return (CaloHitContributionCollection*) this; }

  /// Append a new object to the collection, and return this object.
  CaloHitContribution create();

  /// Append a new object to the collection, and return this object.
  /// Initialized with the parameters given
  template<typename... Args>
  CaloHitContribution create(Args&&... args);

  /// number of elements in the collection
  size_t size() const override final;

  /// fully qualified type name of elements - with namespace
  std::string getValueTypeName() const override { return std::string("edm4hep::CaloHitContribution"); }

  /// Returns the const object of given index
  ConstCaloHitContribution operator[](unsigned int index) const;
  /// Returns the object of a given index
  CaloHitContribution operator[](unsigned int index);
  /// Returns the const object of given index
  ConstCaloHitContribution at(unsigned int index) const;
  /// Returns the object of given index
  CaloHitContribution at(unsigned int index);


  /// Append object to the collection
  void push_back(ConstCaloHitContribution object);

  void prepareForWrite() override final;
  void prepareAfterRead() override final;
  void setBuffer(void* address) override final;
  bool setReferences(const podio::ICollectionProvider* collectionProvider) override final;

  podio::CollRefCollection* referenceCollections() override final { return &m_refCollections; }

  podio::VectorMembersInfo* vectorMembers() override { return &m_vecmem_info; }

  void setID(unsigned ID) override final {
    m_collectionID = ID;
    std::for_each(m_entries.begin(),m_entries.end(),
                  [ID] (CaloHitContributionObj* obj) { obj->id = {obj->id.index, static_cast<int>(ID)}; }
    );
    m_isValid = true;
  };

  unsigned getID() const override final {
    return m_collectionID;
  }

  bool isValid() const override final {
    return m_isValid;
  }

  // support for the iterator protocol
  iterator begin() {
    return iterator(0, &m_entries);
  }
  const_iterator begin() const {
    return const_iterator(0, &m_entries);
  }
  iterator end() {
    return iterator(m_entries.size(), &m_entries);
  }
  const_iterator end() const {
    return const_iterator(m_entries.size(), &m_entries);
  }

  /// returns the address of the pointer to the data buffer
  void* getBufferAddress() override final { return (void*)&m_data; }

  /// Returns the pointer to the data buffer
  std::vector<CaloHitContributionData>* _getBuffer() { return m_data; }

  template<size_t arraysize>
  const std::array<int, arraysize> PDG() const;
  template<size_t arraysize>
  const std::array<float, arraysize> energy() const;
  template<size_t arraysize>
  const std::array<float, arraysize> time() const;
  template<size_t arraysize>
  const std::array<edm4hep::Vector3f, arraysize> stepPosition() const;

private:
  bool m_isValid{false};
  bool m_isReadFromFile{false};
  int m_collectionID{0};
  CaloHitContributionObjPointerContainer m_entries;

  // members to handle 1-to-N-relations
  std::vector<edm4hep::ConstMCParticle>* m_rel_particle; ///< Relation buffer for read / write

  // members to handle vector members
  // members to handle streaming
  podio::CollRefCollection m_refCollections{};
  podio::VectorMembersInfo m_vecmem_info{};
  CaloHitContributionDataContainer* m_data;
};

std::ostream& operator<<(std::ostream& o, const CaloHitContributionCollection& v);

template<typename... Args>
CaloHitContribution CaloHitContributionCollection::create(Args&&... args) {
  const int size = m_entries.size();
  auto obj = new CaloHitContributionObj({size, m_collectionID}, {args...});
  m_entries.push_back(obj);
  return CaloHitContribution(obj);
}

template<size_t arraysize>
const std::array<int, arraysize> CaloHitContributionCollection::PDG() const {
  std::array<int, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.PDG;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> CaloHitContributionCollection::energy() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.energy;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<float, arraysize> CaloHitContributionCollection::time() const {
  std::array<float, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.time;
  }
  return tmp;
}

template<size_t arraysize>
const std::array<edm4hep::Vector3f, arraysize> CaloHitContributionCollection::stepPosition() const {
  std::array<edm4hep::Vector3f, arraysize> tmp;
  const auto valid_size = std::min(arraysize, m_entries.size());
  for (unsigned i = 0; i < valid_size; ++i) {
    tmp[i] = m_entries[i]->data.stepPosition;
  }
  return tmp;
}


} // namespace edm4hep


#endif
