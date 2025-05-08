cmake_minimum_required(VERSION 3.10)

project(Raytracer CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 17)

# Parsers
add_subdirectory(Parsers/CfgParser)
# add_subdirectory(Parsers/XmlParser)
# add_subdirectory(Parsers/JsonParser)

# Primitives
add_subdirectory(Primitives/Sphere)
add_subdirectory(Primitives/Plane)
add_subdirectory(Primitives/Camera)

#Renderers
add_subdirectory(Renderers/SfmlRenderer)

# Core
add_subdirectory(Raytracer/)
