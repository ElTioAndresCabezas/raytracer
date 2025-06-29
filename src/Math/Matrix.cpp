#include "Matrix.hpp"

void Matrix::InitRotate(const Vector3D& angle) {
  double cx = cos(angle.d[0]), cy = cos(angle.d[1]), cz = cos(angle.d[2]);
  double sx = sin(angle.d[0]), sy = sin(angle.d[1]), sz = sin(angle.d[2]);
  double sxsz = sx*sz, cxsz = cx*sz;
  double cxcz = cx*cz, sxcz = sx*cz;
  Matrix result = {{ {{ cy*cz, cy*sz, -sy }},
                      {{ sxcz*sy - cxsz, sxsz*sy + cxcz, sx*cy }},
                      {{ cxcz*sy + sxsz, cxsz*sy - sxcz, cx*cy }} }};
  *this = result;
}

void Matrix::Transform(Vector3D& vector) {
  vector.Set(m[0].Dot(vector), m[1].Dot(vector), m[2].Dot(vector));
}