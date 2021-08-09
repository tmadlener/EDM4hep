// AUTOMATICALLY GENERATED FILE - DO NOT EDIT

#ifndef EDM4HEP_Vector3f_H
#define EDM4HEP_Vector3f_H

#include <ostream>

namespace edm4hep {


class Vector3f {
public:
  float x{};
  float y{};
  float z{};

 Vector3f() : x(0),y(0),z(0) {}
 Vector3f(float xx, float yy, float zz) : x(xx),y(yy),z(zz) {}
 Vector3f(const float* v) : x(v[0]),y(v[1]),z(v[2]) {}
 bool operator==(const Vector3f& v) const { return (x==v.x&&y==v.y&&z==v.z) ; }
 float operator[](unsigned i) const { return *( &x + i ) ; }
 

};

inline std::ostream& operator<<(std::ostream& o, const edm4hep::Vector3f& value) {
  o << value.x << " ";
  o << value.y << " ";
  o << value.z << " ";

  return o;
}

} // namespace edm4hep



#endif
