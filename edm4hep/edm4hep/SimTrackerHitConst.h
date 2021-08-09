// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstSimTrackerHit_H
#define EDM4HEP_ConstSimTrackerHit_H

#include "edm4hep/SimTrackerHitObj.h"

#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"
#include <cmath>
#include "podio/ObjectID.h"

// forward declarations
namespace edm4hep {
class MCParticle;
class ConstMCParticle;
}


namespace edm4hep {


/** @class ConstSimTrackerHit
 *  Simulated tracker hit
 *  @author: F.Gaede, DESY
 */
class ConstSimTrackerHit {

  friend class SimTrackerHit;
  friend class SimTrackerHitCollection;
  friend class SimTrackerHitConstCollectionIterator;

public:
  /// default constructor
  ConstSimTrackerHit();
  ConstSimTrackerHit(unsigned long long cellID, float EDep, float time, float pathLength, int quality, edm4hep::Vector3d position, edm4hep::Vector3f momentum);

  /// constructor from existing SimTrackerHitObj
  ConstSimTrackerHit(SimTrackerHitObj* obj);

  /// copy constructor
  ConstSimTrackerHit(const ConstSimTrackerHit& other);

  /// copy-assignment operator
  ConstSimTrackerHit& operator=(const ConstSimTrackerHit& other);

  /// support cloning (deep-copy)
  ConstSimTrackerHit clone() const;

  /// destructor
  ~ConstSimTrackerHit();


public:

  /// Access the ID of the sensor that created this hit
  const unsigned long long& getCellID() const;

  /// Access the energy deposited in the hit [GeV].
  const float& getEDep() const;

  /// Access the proper time of the hit in the lab frame in [ns].
  const float& getTime() const;

  /// Access the path length of the particle in the sensitive material that resulted in this hit.
  const float& getPathLength() const;

  /// Access the quality bit flag.
  const int& getQuality() const;

  /// Access the the hit position in [mm].
  const edm4hep::Vector3d& getPosition() const;

  /// Access the the 3-momentum of the particle at the hits position in [GeV]
  const edm4hep::Vector3f& getMomentum() const;


  /// Access the MCParticle that caused the hit.
  const ::edm4hep::ConstMCParticle getMCParticle() const;


 static const int  BITOverlay = 31;
 static const int  BITProducedBySecondary = 30;
 bool isOverlay() const { return getQuality() & (1 << BITOverlay) ; }
 bool isProducedBySecondary() const { return getQuality() & (1 << BITProducedBySecondary) ; }
 double x() const {return getPosition()[0];}
 double y() const {return getPosition()[1];}
 double z() const {return getPosition()[2];}
 double rho() const {return sqrt(x()*x() + y()*y());}
 

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from SimTrackerHitObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstSimTrackerHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const SimTrackerHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstSimTrackerHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimTrackerHitObj* m_obj;
};

} // namespace edm4hep


#endif
