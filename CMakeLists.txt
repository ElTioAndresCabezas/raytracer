cmake_minimum_required(VERSION 4.0)
project(Raytracer LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory("third_party/json")

set(EXECUTABLE_OUTPUT_PATH bin)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -pthread -march=native -funroll-loops -fno-operator-names")

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE BIN_SRCS src/bin/*.cpp)
list(REMOVE_ITEM SRCS ${BIN_SRCS})

set(BUILD_TARGETS
  RayRender
)

foreach(target ${BUILD_TARGETS})
  add_executable(${target} ${CMAKE_SOURCE_DIR}/src/bin/${target}.cpp ${SRCS})
  target_link_libraries(${target} PRIVATE nlohmann_json::nlohmann_json)
endforeach(target)
