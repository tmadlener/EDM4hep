// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_SimTrackerHit_H
#define EDM4HEP_SimTrackerHit_H

#include "edm4hep/SimTrackerHitConst.h"
#include "edm4hep/SimTrackerHitObj.h"

#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"
#include <cmath>
#include "podio/ObjectID.h"
#include <ostream>

// forward declarations
namespace edm4hep {
class MCParticle;
class ConstMCParticle;
}


namespace edm4hep {


/** @class SimTrackerHit
 *  Simulated tracker hit
 *  @author: F.Gaede, DESY
 */
class SimTrackerHit {

  friend class SimTrackerHitCollection;
  friend class SimTrackerHitCollectionIterator;
  friend class ConstSimTrackerHit;

public:

  /// default constructor
  SimTrackerHit();
  SimTrackerHit(unsigned long long cellID, float EDep, float time, float pathLength, int quality, edm4hep::Vector3d position, edm4hep::Vector3f momentum);

  /// constructor from existing SimTrackerHitObj
  SimTrackerHit(SimTrackerHitObj* obj);

  /// copy constructor
  SimTrackerHit(const SimTrackerHit& other);

  /// copy-assignment operator
  SimTrackerHit& operator=(const SimTrackerHit& other);

  /// support cloning (deep-copy)
  SimTrackerHit clone() const;

  /// destructor
  ~SimTrackerHit();

  /// conversion to const object
  operator ConstSimTrackerHit() const;

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

  /// Set the ID of the sensor that created this hit
  void setCellID(unsigned long long value);

  /// Set the energy deposited in the hit [GeV].
  void setEDep(float value);

  /// Set the proper time of the hit in the lab frame in [ns].
  void setTime(float value);

  /// Set the path length of the particle in the sensitive material that resulted in this hit.
  void setPathLength(float value);

  /// Set the quality bit flag.
  void setQuality(int value);

  /// Set the the hit position in [mm].
  void setPosition(edm4hep::Vector3d value);
  /// Get reference to the hit position in [mm].
  edm4hep::Vector3d& position();

  /// Set the the 3-momentum of the particle at the hits position in [GeV]
  void setMomentum(edm4hep::Vector3f value);
  /// Get reference to the 3-momentum of the particle at the hits position in [GeV]
  edm4hep::Vector3f& momentum();


  /// Set the MCParticle that caused the hit.
  void setMCParticle(::edm4hep::ConstMCParticle value);


 int  set_bit(int val, int num, bool bitval){ return (val & ~(1<<num)) | (bitval << num); }
 void setOverlay(bool val) { setQuality( set_bit( getQuality() , BITOverlay , val ) ) ;   }
 void setProducedBySecondary(bool val) { setQuality( set_bit( getQuality() , BITProducedBySecondary , val ) ) ;   }
 

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

  bool operator==(const SimTrackerHit& other) const { return m_obj == other.m_obj; }
  bool operator==(const ConstSimTrackerHit& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const SimTrackerHit& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  SimTrackerHitObj* m_obj;
};

std::ostream& operator<<(std::ostream& o, const ConstSimTrackerHit& value);

} // namespace edm4hep


#endif
