// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_TrackState_H
#define EDM4HEP_TrackState_H

#include "edm4hep/Vector3f.h"
#include <array>
#include <ostream>

namespace edm4hep {


class TrackState {
public:
  int location{}; ///< for use with At{Other|IP|FirstHit|LastHit|Calorimeter|Vertex}|LastLocation
  float D0{}; ///< transverse impact parameter
  float phi{}; ///< azimuthal angle
  float omega{}; ///< is the signed curvature of the track in [1/mm].
  float Z0{}; ///< longitudinal impact parameter
  float tanLambda{}; ///< lambda is the dip angle of the track in r-z
  ::edm4hep::Vector3f referencePoint{}; ///< Reference point of the track parameters, e.g. the origin at the IP, or the position  of the first/last hits or the entry point into the calorimeter.
  std::array<float, 15> covMatrix{}; ///< lower triangular covariance matrix of the track parameters.  the order of parameters is  d0, phi, omega, z0, tan(lambda). the array is a row-major flattening of the matrix.

 static const int AtOther = 0 ; // any location other than the ones defined below
 static const int AtIP = 1 ;
 static const int AtFirstHit = 2 ;
 static const int AtLastHit = 3 ;
 static const int AtCalorimeter = 4 ;
 static const int AtVertex = 5 ;
 static const int LastLocation = AtVertex  ;
 

};

inline std::ostream& operator<<(std::ostream& o, const edm4hep::TrackState& value) {
  o << value.location << " ";
  o << value.D0 << " ";
  o << value.phi << " ";
  o << value.omega << " ";
  o << value.Z0 << " ";
  o << value.tanLambda << " ";
  o << value.referencePoint << " ";
  for (int i = 0; i < 15; ++i) {
    o << value.covMatrix[i] << "|";
  }
  o << " ";

  return o;
}

} // namespace edm4hep



#endif
