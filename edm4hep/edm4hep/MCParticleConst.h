// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_ConstMCParticle_H
#define EDM4HEP_ConstMCParticle_H

#include "edm4hep/MCParticleObj.h"

#include "edm4hep/Vector2i.h"
#include "edm4hep/Vector3d.h"
#include "edm4hep/Vector3f.h"
#include <cmath>
#include <vector>
#include "podio/ObjectID.h"



namespace edm4hep {


/** @class ConstMCParticle
 *  The Monte Carlo particle - based on the lcio::MCParticle.
 *  @author: F.Gaede, DESY
 */
class ConstMCParticle {

  friend class MCParticle;
  friend class MCParticleCollection;
  friend class MCParticleConstCollectionIterator;

public:
  /// default constructor
  ConstMCParticle();
  ConstMCParticle(int PDG, int generatorStatus, int simulatorStatus, float charge, float time, double mass, edm4hep::Vector3d vertex, edm4hep::Vector3d endpoint, edm4hep::Vector3f momentum, edm4hep::Vector3f momentumAtEndpoint, edm4hep::Vector3f spin, edm4hep::Vector2i colorFlow);

  /// constructor from existing MCParticleObj
  ConstMCParticle(MCParticleObj* obj);

  /// copy constructor
  ConstMCParticle(const ConstMCParticle& other);

  /// copy-assignment operator
  ConstMCParticle& operator=(const ConstMCParticle& other);

  /// support cloning (deep-copy)
  ConstMCParticle clone() const;

  /// destructor
  ~ConstMCParticle();


public:

  /// Access the PDG code of the particle
  const int& getPDG() const;

  /// Access the status of the particle as defined by the generator
  const int& getGeneratorStatus() const;

  /// Access the status of the particle from the simulation program - use BIT constants below
  const int& getSimulatorStatus() const;

  /// Access the particle charge
  const float& getCharge() const;

  /// Access the creation time of the particle in [ns] wrt. the event, e.g. for preassigned decays or decays in flight from the simulator.
  const float& getTime() const;

  /// Access the mass of the particle in [GeV]
  const double& getMass() const;

  /// Access the production vertex of the particle in [mm].
  const edm4hep::Vector3d& getVertex() const;

  /// Access the endpoint of the particle in [mm]
  const edm4hep::Vector3d& getEndpoint() const;

  /// Access the particle 3-momentum at the production vertex in [GeV]
  const edm4hep::Vector3f& getMomentum() const;

  /// Access the particle 3-momentum at the endpoint in [GeV]
  const edm4hep::Vector3f& getMomentumAtEndpoint() const;

  /// Access the spin (helicity) vector of the particle.
  const edm4hep::Vector3f& getSpin() const;

  /// Access the color flow as defined by the generator
  const edm4hep::Vector2i& getColorFlow() const;



  unsigned int parents_size() const;
  ::edm4hep::ConstMCParticle getParents(unsigned int) const;
  std::vector<::edm4hep::ConstMCParticle>::const_iterator parents_begin() const;
  std::vector<::edm4hep::ConstMCParticle>::const_iterator parents_end() const;
  podio::RelationRange<::edm4hep::ConstMCParticle> getParents() const;
  unsigned int daughters_size() const;
  ::edm4hep::ConstMCParticle getDaughters(unsigned int) const;
  std::vector<::edm4hep::ConstMCParticle>::const_iterator daughters_begin() const;
  std::vector<::edm4hep::ConstMCParticle>::const_iterator daughters_end() const;
  podio::RelationRange<::edm4hep::ConstMCParticle> getDaughters() const;

 // define the bit positions for the simulation flag
 static const int BITEndpoint = 31;
 static const int BITCreatedInSimulation = 30;
 static const int BITBackscatter = 29 ;
 static const int BITVertexIsNotEndpointOfParent = 28 ;  
 static const int BITDecayedInTracker = 27 ; 
 static const int BITDecayedInCalorimeter = 26 ;   
 static const int BITLeftDetector = 25 ;     
 static const int BITStopped = 24 ;    
 static const int BITOverlay = 23 ;    
 /// return energy computed from momentum and mass 
 double getEnergy() const { return sqrt( getMomentum()[0]*getMomentum()[0]+getMomentum()[1]*getMomentum()[1]+
 getMomentum()[2]*getMomentum()[2] + getMass()*getMass()  )  ;} 

/// True if the particle has been created by the simulation program (rather than the generator).     
 bool isCreatedInSimulation() const { return ( getSimulatorStatus() & ( 0x1 << BITCreatedInSimulation ))  ; }    
 /// True if the particle is the result of a backscatter from a calorimeter shower. 
 bool isBackscatter() const { return ( getSimulatorStatus() & ( 0x1 << BITBackscatter )) ; }   
 /// True if the particle's vertex is not the endpoint of the  parent particle.     
 bool vertexIsNotEndpointOfParent() const { return ( getSimulatorStatus() & ( 0x1 << BITVertexIsNotEndpointOfParent )) ; } 
 /// True if the particle has interacted in a tracking region.                
 bool isDecayedInTracker() const { return ( getSimulatorStatus() & ( 0x1 << BITDecayedInTracker )) ; }     
 /// True if the particle has interacted in a calorimeter region.             
 bool isDecayedInCalorimeter() const { return ( getSimulatorStatus() & ( 0x1 << BITDecayedInCalorimeter )) ; }   
 /// True if the particle has left the world volume undecayed.                
 bool hasLeftDetector() const { return ( getSimulatorStatus() & ( 0x1 << BITLeftDetector )) ; }
 /// True if the particle has been stopped by the simulation program.         
 bool isStopped() const { return ( getSimulatorStatus() & ( 0x1 << BITStopped )) ; }     
 /// True if the particle has been overlayed by the simulation (or digitization)  program.
 bool isOverlay() const { return ( getSimulatorStatus() & ( 0x1 << BITOverlay )) ; }     
 

  /// check whether the object is actually available
  bool isAvailable() const;
  /// disconnect from MCParticleObj instance
  void unlink() { m_obj = nullptr; }

  bool operator==(const ConstMCParticle& other) const { return m_obj == other.m_obj; }
  bool operator==(const MCParticle& other) const;

  // less comparison operator, so that objects can be e.g. stored in sets.
  bool operator<(const ConstMCParticle& other) const { return m_obj < other.m_obj; }

  unsigned int id() const { return getObjectID().collectionID * 10000000 + getObjectID().index; }

  const podio::ObjectID getObjectID() const;

private:
  MCParticleObj* m_obj;
};

} // namespace edm4hep


#endif
