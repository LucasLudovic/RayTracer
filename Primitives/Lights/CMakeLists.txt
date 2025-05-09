cmake_minimum_required(VERSION 3.10)
project(raytracer_lights LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(raytracer_lights SHARED ${SOURCES})
set_target_properties(raytracer_lights PROPERTIES PREFIX "")

target_include_directories(raytracer_lights PRIVATE
    ../
    ../../Primitives/
    ../../Utils/
    ${LIBCONFIG_INCLUDE_DIRS}
)

target_link_libraries(raytracer_lights PRIVATE
    ${LIBCONFIG_LIBRARIES}
)

target_compile_options(raytracer_lights PRIVATE -fno-gnu-unique)
