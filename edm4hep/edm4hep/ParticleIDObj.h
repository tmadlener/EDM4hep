// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ParticleIDOBJ_H
#define EDM4HEP_ParticleIDOBJ_H

// data model specific includes
#include "edm4hep/ParticleIDData.h"
#include "podio/RelationRange.h"
#include <vector>

#include "podio/ObjBase.h"
#include <vector>


namespace edm4hep {

class ParticleID;
class ConstParticleID;

class ParticleIDObj : public podio::ObjBase {
public:
  /// constructor
  ParticleIDObj();
  /// copy constructor (does a deep-copy of relation containers)
  ParticleIDObj(const ParticleIDObj&);
  /// constructor from ObjectID and ParticleIDData
  /// does not initialize the internal relation containers
  ParticleIDObj(const podio::ObjectID id, ParticleIDData data);
  /// No assignment operator
  ParticleIDObj& operator=(const ParticleIDObj&) = delete;
  virtual ~ParticleIDObj();

public:
  ParticleIDData data;
  std::vector<float>* m_parameters{nullptr};
};

} // namespace edm4hep


#endif
