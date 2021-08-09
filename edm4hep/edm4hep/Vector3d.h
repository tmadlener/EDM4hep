// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Vector3d_H
#define EDM4HEP_Vector3d_H

#include <ostream>

namespace edm4hep {


class Vector3d {
public:
  double x{};
  double y{};
  double z{};

 Vector3d() : x(0),y(0),z(0) {}
 Vector3d(double xx, double yy, double zz) : x(xx),y(yy),z(zz) {}
 Vector3d(const double* v) : x(v[0]),y(v[1]),z(v[2]) {}
 Vector3d(const float* v) : x(v[0]),y(v[1]),z(v[2]) {}
 bool operator==(const Vector3d& v) const { return (x==v.x&&y==v.y&&z==v.z) ; }
 double operator[](unsigned i) const { return *( &x + i ) ; }
 

};

inline std::ostream& operator<<(std::ostream& o, const edm4hep::Vector3d& value) {
  o << value.x << " ";
  o << value.y << " ";
  o << value.z << " ";

  return o;
}

} // namespace edm4hep



#endif
