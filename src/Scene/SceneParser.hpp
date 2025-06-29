#include <fstream>
#include <nlohmann/json.hpp>

#include "Scene.hpp"
#include "SceneElements.hpp"

class SceneParser {
  public:
    static Scene ParseScene(std::string& filename);
};