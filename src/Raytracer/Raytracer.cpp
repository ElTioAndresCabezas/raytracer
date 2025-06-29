#include "Raytracer.hpp"
#include <cmath>

void Raytracer::Render() {
  // TODO: Implement!
}

int Raytracer::RayFindObstacle(
  const Vector3D& pov, const Vector3D& dir,
  double& hitDistance, int& hitIndex,
  Vector3D& hitLocation, Vector3D& hitNormal
) {
  HitType hitType = HitType::NONE;
  for (unsigned i = 0; i < scene.spheres.size(); ++i) {
    Sphere* sphere = &scene.spheres[i];
    Vector3D sphereToPov (pov - sphere->center);
    double radius = sphere->radius,
           parallelSphereToPov = dir.Dot(sphereToPov),
           dirSquared = dir.Squared(),
           visibilityRate = parallelSphereToPov * parallelSphereToPov - dirSquared * (sphereToPov.Squared() - radius * radius);

    if (visibilityRate < 1e-6) continue;

    double visibilityRateSqrt = std::sqrt(visibilityRate);
    double distance = dmin(-parallelSphereToPov - visibilityRateSqrt, -parallelSphereToPov + visibilityRateSqrt) / dirSquared;

    // Non-trivial distance and closer to a previous hit
    if (distance < 1e-6 || distance >= hitDistance) continue;

    hitType = HitType::SPHERE;
    hitIndex = i;
    hitDistance = distance;
    hitLocation = pov + (dir * hitDistance);
    hitNormal = (hitLocation - sphere->center) * (1 / radius);
  }
  for (unsigned i = 0; i < scene.planes.size(); ++i) {
    Plane* plane = &scene.planes[i];
    double parallelPlaneToPov = -plane->normal.Dot(pov);

    if (parallelPlaneToPov > -1e-6) continue;

    double d2 = plane->normal.Dot(pov);
    double distance = (d2 + plane->offset) / parallelPlaneToPov;

    if (distance < 1e-6 || distance >= hitDistance) continue;
    hitType = HitType::PLANE;
    hitIndex = i;
    hitDistance = distance;
    hitLocation = pov + (dir * hitDistance);
    hitNormal = plane->normal;
  }

  return hitType;
}

Vector3D Raytracer::calculatePixel(Vector3D& pov, Vector3D& dir, int k) {
  // TODO: Implement!
  Vector3D color;
  return color;
}