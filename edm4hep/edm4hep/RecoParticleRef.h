// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_RecoParticleRef_H
#define EDM4HEP_RecoParticleRef_H

#include "edm4hep/RecoParticleRefConst.h"
#include "edm4hep/RecoParticleRefObj.h"

#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class ReconstructedParticle;
class ConstReconstructedParticle;
}


namespace edm4hep {


/** @class RecoParticleRef
 *  Used to get a subset of reconstructed particles from a collection (or many collections)
 *  @author: T. Madlener, DESY
 */
class RecoParticleRef {

  friend class RecoParticleRefCollection;
  friend class RecoParticleRefCollectionIterator;
  friend class ConstRecoParticleRef;

public:

  /// default constructor
  RecoParticleRef();

  /// constructor from existing RecoParticleRefObj
  RecoParticleRef(RecoParticleRefObj* obj);

  /// copy constructor
  RecoParticleRef(const RecoParticleRef& other);

  /// copy-assignment operator
  RecoParticleRef& operator=(const RecoParticleRef& other);

  /// support cloning (deep-copy)
  RecoParticleRef clone() const;

  /// destructor
  ~RecoParticleRef();

  /// conversion to const object
  operator ConstRecoParticleRef() const;

public:


  /// Access the reference to the reconstructed particle
  const ::edm4hep::ConstReconstructedParticle getParticle() const;


  /// Set the reference to the reconstructed particle
  void setParticle(::edm4hep::ConstReconstructedParticle value);




  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from RecoParticleRefObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const RecoParticleRef& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstRecoParticleRef& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const RecoParticleRef& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  RecoParticleRefObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstRecoParticleRef& value);

} // namespace edm4hep


#endif
