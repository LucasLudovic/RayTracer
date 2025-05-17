cmake_minimum_required(VERSION 3.10)
project(raytracer_cone LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES src/*.cpp)

add_library(raytracer_cone SHARED ${SOURCES})
set_target_properties(raytracer_cone PROPERTIES
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/primitives"
)

target_include_directories(raytracer_cone PRIVATE
    ../
    ../../Primitives/
    ../../Utils/
    ${LIBCONFIG_INCLUDE_DIRS}
)

target_link_libraries(raytracer_cone PRIVATE
    ${LIBCONFIG_LIBRARIES}
)

target_compile_options(raytracer_cone PRIVATE -fno-gnu-unique)
