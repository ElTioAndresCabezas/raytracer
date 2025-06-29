#pragma once
#include "../Math/Vector3D.hpp"

struct Plane {
  Vector3D normal;
  double offset;

  Plane(Vector3D normal, double offset)
    : normal(normal), offset(offset) {}
};

struct Sphere {
  Vector3D center;
  double radius;

  Sphere(Vector3D center, double radius)
    : center(center), radius(radius) {}
};

struct LightSource {
  Vector3D center;
  Vector3D color;

  LightSource(Vector3D center, Vector3D color)
    : center(center), color(color) {}
};

struct Camera {
  Vector3D angle;
  Vector3D look;
  double zoom;
  double contrast;
};