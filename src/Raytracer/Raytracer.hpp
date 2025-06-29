#include "../Scene/Scene.hpp"

enum HitType {
  NONE,
  SPHERE,
  PLANE
};

class Raytracer {
  public:
    Raytracer(Scene scene)
      : scene(scene) {}

    void Render();
  private:
    Scene scene;

    HitType RayFindObstacle(
      const Vector3D& pov, const Vector3D& dir,
      double& hitDistance, int& hitIndex,
      Vector3D& hitLocation, Vector3D& hitNormal
    );

    Vector3D CalculatePixel(Vector3D& pov, Vector3D& dir, int k);

};