// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimCalorimeterHit_H
#define EDM4HEP_SimCalorimeterHit_H

#include "edm4hep/SimCalorimeterHitConst.h"
#include "edm4hep/SimCalorimeterHitObj.h"

#include "edm4hep/CaloHitContribution.h"
#include "edm4hep/Vector3f.h"
#include <vector>
#include "podio/ObjectID.h"
#include <ostream>



namespace edm4hep {


/** @class SimCalorimeterHit
 *  Simulated calorimeter hit
 *  @author: F.Gaede, DESY
 */
class SimCalorimeterHit {

  friend class SimCalorimeterHitCollection;
  friend class SimCalorimeterHitCollectionIterator;
  friend class ConstSimCalorimeterHit;

public:

  /// default constructor
  SimCalorimeterHit();
  SimCalorimeterHit(unsigned long long cellID, float energy, edm4hep::Vector3f position);

  /// constructor from existing SimCalorimeterHitObj
  SimCalorimeterHit(SimCalorimeterHitObj* obj);

  /// copy constructor
  SimCalorimeterHit(const SimCalorimeterHit& other);

  /// copy-assignment operator
  SimCalorimeterHit& operator=(const SimCalorimeterHit& other);

  /// support cloning (deep-copy)
  SimCalorimeterHit clone() const;

  /// destructor
  ~SimCalorimeterHit();

  /// conversion to const object
  operator ConstSimCalorimeterHit() const;

public:

  /// Access the ID of the sensor that created this hit
  const unsigned long long& getCellID() const;

  /// Access the energy of the hit in [GeV].
  const float& getEnergy() const;

  /// Access the position of the hit in world coordinates.
  const edm4hep::Vector3f& getPosition() const;



  /// Set the ID of the sensor that created this hit
  void setCellID(unsigned long long value);

  /// Set the energy of the hit in [GeV].
  void setEnergy(float value);

  /// Set the position of the hit in world coordinates.
  void setPosition(edm4hep::Vector3f value);
  /// Get reference to position of the hit in world coordinates.
  edm4hep::Vector3f& position();



  void addToContributions(::edm4hep::ConstCaloHitContribution);
  unsigned int contributions_size() const;
  ::edm4hep::ConstCaloHitContribution getContributions(unsigned int) const;
  std::vector<::edm4hep::ConstCaloHitContribution>::const_iterator contributions_begin() const;
  std::vector<::edm4hep::ConstCaloHitContribution>::const_iterator contributions_end() const;
  podio::RelationRange<::edm4hep::ConstCaloHitContribution> getContributions() const;



  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimCalorimeterHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const SimCalorimeterHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstSimCalorimeterHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const SimCalorimeterHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimCalorimeterHitObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstSimCalorimeterHit& value);

} // namespace edm4hep


#endif
