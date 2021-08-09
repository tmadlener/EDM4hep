// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ParticleID_H
#define EDM4HEP_ParticleID_H

#include "edm4hep/ParticleIDConst.h"
#include "edm4hep/ParticleIDObj.h"

#include <vector>
#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class ParticleID
 *  ParticleID
 *  @author: F.Gaede, DESY
 */
class ParticleID {

  friend class ParticleIDCollection;
  friend class ParticleIDCollectionIterator;
  friend class ConstParticleID;

public:

  /// default constructor
  ParticleID();
  ParticleID(int type, int PDG, int algorithmType, float likelihood);

  /// constructor from existing ParticleIDObj
  ParticleID(ParticleIDObj* obj);

  /// copy constructor
  ParticleID(const ParticleID& other);

  /// copy-assignment operator
  ParticleID& operator=(const ParticleID& other);

  /// support cloning (deep-copy)
  ParticleID clone() const;

  /// destructor
  ~ParticleID();

  /// conversion to const object
  operator ConstParticleID() const;

public:

  /// Access the userdefined type
  const int& getType() const;

  /// Access the PDG code of this id - ( 999999 ) if unknown.
  const int& getPDG() const;

  /// Access the type of the algorithm/module that created this hypothesis
  const int& getAlgorithmType() const;

  /// Access the likelihood of this hypothesis - in a user defined normalization.
  const float& getLikelihood() const;



  /// Set the userdefined type
  void setType(int value);

  /// Set the PDG code of this id - ( 999999 ) if unknown.
  void setPDG(int value);

  /// Set the type of the algorithm/module that created this hypothesis
  void setAlgorithmType(int value);

  /// Set the likelihood of this hypothesis - in a user defined normalization.
  void setLikelihood(float value);



  void addToParameters(float);
  unsigned int parameters_size() const;
  float getParameters(unsigned int) const;
  std::vector<float>::const_iterator parameters_begin() const;
  std::vector<float>::const_iterator parameters_end() const;
  podio::RelationRange<float> getParameters() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from ParticleIDObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ParticleID& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstParticleID& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ParticleID& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  ParticleIDObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstParticleID& value);

} // namespace edm4hep


#endif
