// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstParticleID_H
#define EDM4HEP_ConstParticleID_H

#include "edm4hep/ParticleIDObj.h"

#include <vector>
#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstParticleID
 *  ParticleID
 *  @author: F.Gaede, DESY
 */
class ConstParticleID {

  friend class ParticleID;
  friend class ParticleIDCollection;
  friend class ParticleIDConstCollectionIterator;

public:
  /// default constructor
  ConstParticleID();
  ConstParticleID(int type, int PDG, int algorithmType, float likelihood);

  /// constructor from existing ParticleIDObj
  ConstParticleID(ParticleIDObj* obj);

  /// copy constructor
  ConstParticleID(const ConstParticleID& other);

  /// copy-assignment operator
  ConstParticleID& operator=(const ConstParticleID& other);

  /// support cloning (deep-copy)
  ConstParticleID clone() const;

  /// destructor
  ~ConstParticleID();


public:

  /// Access the userdefined type
  const int& getType() const;

  /// Access the PDG code of this id - ( 999999 ) if unknown.
  const int& getPDG() const;

  /// Access the type of the algorithm/module that created this hypothesis
  const int& getAlgorithmType() const;

  /// Access the likelihood of this hypothesis - in a user defined normalization.
  const float& getLikelihood() const;



  unsigned int parameters_size() const;
  float getParameters(unsigned int) const;
  std::vector<float>::const_iterator parameters_begin() const;
  std::vector<float>::const_iterator parameters_end() const;
  podio::RelationRange<float> getParameters() const;


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ParticleIDObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstParticleID& other) const { return m_obj == other.m_obj; }
  bool operator==(const ParticleID& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstParticleID& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  ParticleIDObj* m_obj;
};

} // namespace edm4hep


#endif
