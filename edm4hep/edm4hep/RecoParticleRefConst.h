// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstRecoParticleRef_H
#define EDM4HEP_ConstRecoParticleRef_H

#include "edm4hep/RecoParticleRefObj.h"

#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class ConstReconstructedParticle;
}


namespace edm4hep {


/** @class ConstRecoParticleRef
 *  Used to get a subset of reconstructed particles from a collection (or many collections)
 *  @author: T. Madlener, DESY
 */
class ConstRecoParticleRef {

  friend class RecoParticleRef;
  friend class RecoParticleRefCollection;
  friend class RecoParticleRefConstCollectionIterator;

public:
  /// default constructor
  ConstRecoParticleRef();

  /// constructor from existing RecoParticleRefObj
  ConstRecoParticleRef(RecoParticleRefObj* obj);

  /// copy constructor
  ConstRecoParticleRef(const ConstRecoParticleRef& other);

  /// copy-assignment operator
  ConstRecoParticleRef& operator=(const ConstRecoParticleRef& other);

  /// support cloning (deep-copy)
  ConstRecoParticleRef clone() const;

  /// destructor
  ~ConstRecoParticleRef();


public:


  /// Access the reference to the reconstructed particle
  const ::edm4hep::ConstReconstructedParticle getParticle() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RecoParticleRefObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstRecoParticleRef& other) const { return m_obj == other.m_obj; }
  bool operator==(const RecoParticleRef& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstRecoParticleRef& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  RecoParticleRefObj* m_obj;
};

} // namespace edm4hep


#endif
