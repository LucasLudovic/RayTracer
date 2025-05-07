cmake_minimum_required(VERSION 3.10)
project(raytracer_sphere LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(raytracer_sphere SHARED ${SOURCES})
set_target_properties(raytracer_sphere PROPERTIES
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/primitives"
)

target_include_directories(raytracer_sphere PRIVATE
    ../
    ../../Primitives/
    ../../Utils/
    ${LIBCONFIG_INCLUDE_DIRS}
)

target_link_libraries(raytracer_sphere PRIVATE
    ${LIBCONFIG_LIBRARIES}
)

target_compile_options(raytracer_sphere PRIVATE -fno-gnu-unique)
