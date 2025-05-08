cmake_minimum_required(VERSION 3.10)
project(raytracer_camera LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(raytracer_camera SHARED ${SOURCES})
set_target_properties(raytracer_camera PROPERTIES PREFIX "")

target_include_directories(raytracer_camera PRIVATE
    ../
    ../../Primitives/
    ../../Utils/
    ${LIBCONFIG_INCLUDE_DIRS}
)

target_link_libraries(raytracer_camera PRIVATE
    ${LIBCONFIG_LIBRARIES}
)

target_compile_options(raytracer_camera PRIVATE -fno-gnu-unique)
