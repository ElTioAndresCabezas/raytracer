# Raytracer
A simple raytracer, heavily inspired by Joel ["Bisqwit"](https://github.com/bisqwit) Yliluoma's [Raytracer](https://bisqwit.iki.fi/jutut/kuvat/programming_examples/raytrace2.cpp), as seen on [YouTube](https://www.youtube.com/watch?v=N8elxpSu9pw).

The goal of this project is to make a codebase that is easier to build upon, and to make it easier for users to create demos. However, the biggest motivation for this project is to learn about how raytracing works.

# Features
- Scene JSONs: Specify the contents of a scene to run the raytracer with, using a JSON file that will be loaded at runtime. No need to recompile to change your scene!
- More compatibility: Add support for different technologies, like CUDA, to be able to run from the same executable.

# Building
TODO: Add building instructions

# Third-party elements
This program uses the following libraries made by others
- LibGD: For drawing the image.
- [nlohmann's JSON for Modern C++](https://github.com/nlohmann/json): For importing JSON scene descriptions

# TODOs
- Implement raytracing

## Optional
- Remove nlohmann's JSON for Modern C++ dependency and replace it with a custom JSON parser.
- Create tool to allow users to make raytracing scenes with a GUI