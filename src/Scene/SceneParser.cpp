#include "SceneParser.hpp"

using json = nlohmann::json;

Scene SceneParser::ParseScene(std::string& filename) {
  std::ifstream sceneFile(filename);
  json sceneJSON = json::parse(sceneFile);

  Scene scene;

  // Set scene camera
  scene.camera.angle = {
    sceneJSON["camera"]["angle"]["x"],
    sceneJSON["camera"]["angle"]["y"],
    sceneJSON["camera"]["angle"]["z"],
  };
  scene.camera.look = {
    sceneJSON["camera"]["look"]["x"],
    sceneJSON["camera"]["look"]["y"],
    sceneJSON["camera"]["look"]["z"],
  };
  scene.camera.zoom = 46;
  scene.camera.contrast = 32;

  // Add lights from JSON
  for(auto light : sceneJSON["lights"]) {
    scene.lights.emplace_back(
      (Vector3D) {
        (double) light["center"]["x"],
        (double) light["center"]["y"],
        (double) light["center"]["z"]
      },
      (Vector3D) {
        (double) light["color"]["r"],
        (double) light["color"]["g"],
        (double) light["color"]["b"]
      }
    );
  }

  // Add planes from JSON
  for(auto plane : sceneJSON["planes"]) {
    scene.planes.emplace_back(
      (Vector3D) {
        (double) plane["normal"]["x"],
        (double) plane["normal"]["y"],
        (double) plane["normal"]["z"]
      },
      plane["offset"]
    );
  }

  // Add spheres from JSON
  for(auto sphere : sceneJSON["spheres"]) {
    scene.spheres.emplace_back(
      (Vector3D) {
        (double) sphere["center"]["x"],
        (double) sphere["center"]["y"],
        (double) sphere["center"]["z"]
      },
      sphere["radius"]
    );
  }

  return scene;
}