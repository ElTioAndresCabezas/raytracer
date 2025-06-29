#pragma once

#include <math.h>

// Math operations and datatypes
double dmin(double a, double b);

struct Vector3D {
  double d[3];
  void Set(double x, double y, double z);

  // Operations for vectors
  #define do_op(o) \
    void operator o##= (const Vector3D& b); \
    void operator o##= (double b); \
    Vector3D operator o (const Vector3D& b) const; \
    Vector3D operator o (double b) const;
  do_op(*)
  do_op(+)
  do_op(-)
  #undef do_op

  // Inverse vector (opposite vector from origin)
  Vector3D operator- () const;

  // Raise all vector values to the power of b
  Vector3D Pow(double b) const;

  double Dot(const Vector3D& b) const;
  double Squared() const;
  double Length() const;

  void Normalize();
};