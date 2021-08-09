// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstSimCalorimeterHit_H
#define EDM4HEP_ConstSimCalorimeterHit_H

#include "edm4hep/SimCalorimeterHitObj.h"

#include "edm4hep/CaloHitContribution.h"
#include "edm4hep/Vector3f.h"
#include <vector>
#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstSimCalorimeterHit
 *  Simulated calorimeter hit
 *  @author: F.Gaede, DESY
 */
class ConstSimCalorimeterHit {

  friend class SimCalorimeterHit;
  friend class SimCalorimeterHitCollection;
  friend class SimCalorimeterHitConstCollectionIterator;

public:
  /// default constructor
  ConstSimCalorimeterHit();
  ConstSimCalorimeterHit(unsigned long long cellID, float energy, edm4hep::Vector3f position);

  /// constructor from existing SimCalorimeterHitObj
  ConstSimCalorimeterHit(SimCalorimeterHitObj* obj);

  /// copy constructor
  ConstSimCalorimeterHit(const ConstSimCalorimeterHit& other);

  /// copy-assignment operator
  ConstSimCalorimeterHit& operator=(const ConstSimCalorimeterHit& other);

  /// support cloning (deep-copy)
  ConstSimCalorimeterHit clone() const;

  /// destructor
  ~ConstSimCalorimeterHit();


public:

  /// Access the ID of the sensor that created this hit
  const unsigned long long& getCellID() const;

  /// Access the energy of the hit in [GeV].
  const float& getEnergy() const;

  /// Access the position of the hit in world coordinates.
  const edm4hep::Vector3f& getPosition() const;



  unsigned int contributions_size() const;
  ::edm4hep::ConstCaloHitContribution getContributions(unsigned int) const;
  std::vector<::edm4hep::ConstCaloHitContribution>::const_iterator contributions_begin() const;
  std::vector<::edm4hep::ConstCaloHitContribution>::const_iterator contributions_end() const;
  podio::RelationRange<::edm4hep::ConstCaloHitContribution> getContributions() const;


  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimCalorimeterHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstSimCalorimeterHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const SimCalorimeterHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstSimCalorimeterHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimCalorimeterHitObj* m_obj;
};

} // namespace edm4hep


#endif
