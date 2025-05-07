cmake_minimum_required(VERSION 3.10)
project(raytracer_plane LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(raytracer_plane SHARED ${SOURCES})
set_target_properties(raytracer_plane PROPERTIES PREFIX "")

target_include_directories(raytracer_plane PRIVATE
    ../
    ../../Primitives/
    ../../Utils/
    ${LIBCONFIG_INCLUDE_DIRS}
)

target_link_libraries(raytracer_plane PRIVATE
    ${LIBCONFIG_LIBRARIES}
)

target_compile_options(raytracer_plane PRIVATE -fno-gnu-unique)
