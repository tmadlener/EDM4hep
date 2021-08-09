// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstCaloHitContribution_H
#define EDM4HEP_ConstCaloHitContribution_H

#include "edm4hep/CaloHitContributionObj.h"

#include "edm4hep/Vector3f.h"
#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class MCParticle;
class ConstMCParticle;
}


namespace edm4hep {


/** @class ConstCaloHitContribution
 *  Monte Carlo contribution to SimCalorimeterHit
 *  @author: F.Gaede, DESY
 */
class ConstCaloHitContribution {

  friend class CaloHitContribution;
  friend class CaloHitContributionCollection;
  friend class CaloHitContributionConstCollectionIterator;

public:
  /// default constructor
  ConstCaloHitContribution();
  ConstCaloHitContribution(int PDG, float energy, float time, edm4hep::Vector3f stepPosition);

  /// constructor from existing CaloHitContributionObj
  ConstCaloHitContribution(CaloHitContributionObj* obj);

  /// copy constructor
  ConstCaloHitContribution(const ConstCaloHitContribution& other);

  /// copy-assignment operator
  ConstCaloHitContribution& operator=(const ConstCaloHitContribution& other);

  /// support cloning (deep-copy)
  ConstCaloHitContribution clone() const;

  /// destructor
  ~ConstCaloHitContribution();


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



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from CaloHitContributionObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstCaloHitContribution& other) const { return m_obj == other.m_obj; }
  bool operator==(const CaloHitContribution& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstCaloHitContribution& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  CaloHitContributionObj* m_obj;
};

} // namespace edm4hep


#endif
