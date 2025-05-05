cmake_minimum_required(VERSION 3.10)
project(raytracer_cfg_parser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig)
pkg_check_modules(LIBCONFIG libconfig++)

set(MISSING_DEP FALSE)
if (NOT LIBCONFIG_FOUND)
    set(MISSING_DEP TRUE)
endif()

if (MISSING_DEP)
    file(WRITE ${CMAKE_BINARY_DIR}/empty.cpp "")
    set(SOURCES ${CMAKE_BINARY_DIR}/empty.cpp)
else()
    file(GLOB SOURCES src/*.cpp)
endif()

add_library(raytracer_cfg_parser SHARED ${SOURCES})
set_target_properties(raytracer_cfg_parser PROPERTIES PREFIX "")

target_include_directories(raytracer_cfg_parser PRIVATE
    ../
    ../../Primitives
    ${LIBCONFIG_INCLUDE_DIRS}
)

target_link_libraries(raytracer_cfg_parser PRIVATE
    ${LIBCONFIG_LIBRARIES}
)

target_compile_options(raytracer_cfg_parser PRIVATE -fno-gnu-unique)
