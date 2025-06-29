#include "SceneElements.hpp"
#include <vector>

struct Scene {
  std::vector<Plane> planes;
  std::vector<Sphere> spheres;
  std::vector<LightSource> lights;
  Camera camera;
};