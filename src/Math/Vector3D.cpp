#include "Vector3D.hpp"

double dmin(double a, double b) { return a<b ? a : b; }

void Vector3D::Set(double x, double y, double z) {
  d[0] = x;
  d[1] = y;
  d[2] = z;
}

#define do_op(o) \
  void Vector3D::operator o##= (const Vector3D& b) { for (unsigned n = 0; n < 3; ++n) d[n] o##= b.d[n]; } \
  void Vector3D::operator o##= (double b) { for (unsigned n = 0; n < 3; ++n) d[n] o##= b; } \
  Vector3D Vector3D::operator o (const Vector3D& b) const { Vector3D tmp(*this); tmp o##= b; return tmp; } \
  Vector3D Vector3D::operator o (double b) const { Vector3D tmp(*this); tmp o##= b; return tmp; }
do_op(*)
do_op(+)
do_op(-)
#undef do_op

Vector3D Vector3D::operator- () const {
  Vector3D tmp = {{ -d[0], -d[1], -d[2] }};
  return tmp;
}

Vector3D Vector3D::Pow(double b) const {
  Vector3D tmp = {{
    std::pow(d[0],b),
    std::pow(d[1],b),
    std::pow(d[2],b)
  }};
  return tmp;
}

double Vector3D::Dot(const Vector3D& b) const { return d[0]*b.d[0] + d[1]*b.d[1] + d[2]*b.d[2]; }
double Vector3D::Squared() const { return Dot(*this); }
double Vector3D::Length() const { return std::sqrt(Squared()); }

void Vector3D::Normalize() {*this *= 1.0 / Length(); }