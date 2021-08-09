// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_CaloHitContribution_H
#define EDM4HEP_CaloHitContribution_H

#include "edm4hep/CaloHitContributionConst.h"
#include "edm4hep/CaloHitContributionObj.h"

#include "edm4hep/Vector3f.h"
#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class MCParticle;
class ConstMCParticle;
}


namespace edm4hep {


/** @class CaloHitContribution
 *  Monte Carlo contribution to SimCalorimeterHit
 *  @author: F.Gaede, DESY
 */
class CaloHitContribution {

  friend class CaloHitContributionCollection;
  friend class CaloHitContributionCollectionIterator;
  friend class ConstCaloHitContribution;

public:

  /// default constructor
  CaloHitContribution();
  CaloHitContribution(int PDG, float energy, float time, edm4hep::Vector3f stepPosition);

  /// constructor from existing CaloHitContributionObj
  CaloHitContribution(CaloHitContributionObj* obj);

  /// copy constructor
  CaloHitContribution(const CaloHitContribution& other);

  /// copy-assignment operator
  CaloHitContribution& operator=(const CaloHitContribution& other);

  /// support cloning (deep-copy)
  CaloHitContribution clone() const;

  /// destructor
  ~CaloHitContribution();

  /// conversion to const object
  operator ConstCaloHitContribution() const;

public:

  /// Access the PDG code of the shower particle that caused this contribution.
  const int& getPDG() const;

  /// Access the energy in [GeV] of the this contribution
  const float& getEnergy() const;

  /// Access the time in [ns] of this contribution
  const float& getTime() const;

  /// Access the position of this energy deposition (step)
  const edm4hep::Vector3f& getStepPosition() const;


  /// Access the primary MCParticle that caused the shower responsible for this contribution to the hit.
  const ::edm4hep::ConstMCParticle getParticle() const;

  /// Set the PDG code of the shower particle that caused this contribution.
  void setPDG(int value);

  /// Set the energy in [GeV] of the this contribution
  void setEnergy(float value);

  /// Set the time in [ns] of this contribution
  void setTime(float value);

  /// Set the position of this energy deposition (step)
  void setStepPosition(edm4hep::Vector3f value);
  /// Get reference to position of this energy deposition (step)
  edm4hep::Vector3f& stepPosition();


  /// Set the primary MCParticle that caused the shower responsible for this contribution to the hit.
  void setParticle(::edm4hep::ConstMCParticle value);




  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from CaloHitContributionObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const CaloHitContribution& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstCaloHitContribution& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const CaloHitContribution& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  CaloHitContributionObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstCaloHitContribution& value);

} // namespace edm4hep


#endif
