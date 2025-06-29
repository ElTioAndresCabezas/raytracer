#include "Vector3D.hpp"

struct Matrix {
  Vector3D m[3];

  void InitRotate(const Vector3D& angle);

  void Transform(Vector3D& vector);
};