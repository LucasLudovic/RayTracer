cmake_minimum_required(VERSION 3.10)
project(raytracer_ppm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(raytracer_ppm SHARED ${SOURCES})

target_include_directories(raytracer_ppm PRIVATE
    ../
    ../../Utils/
    ../../Raytracer/
    ../../Primitives/
)

set_target_properties(raytracer_ppm PROPERTIES
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/renderers"
)

target_compile_options(raytracer_ppm PRIVATE -fno-gnu-unique)
