#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <gd.h>

#include "../Scene/SceneParser.hpp"

using json = nlohmann::json;

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Not enough args!\n";
    return -1;
  }
  std::string filename = argv[1];
  Scene scene = SceneParser::ParseScene(filename);

  // TODO: Raytracing!
}