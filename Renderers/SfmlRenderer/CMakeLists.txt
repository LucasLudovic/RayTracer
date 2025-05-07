cmake_minimum_required(VERSION 3.10)
project(raytracer_sfml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig)
pkg_check_modules(SFML_GRAPHICS sfml-graphics>=3.0.1)
pkg_check_modules(SFML_WINDOW sfml-window>=3.0.1)
pkg_check_modules(SFML_SYSTEM sfml-system>=3.0.1)

set(MISSING_DEP FALSE)
if (NOT SFML_GRAPHICS_FOUND OR NOT SFML_WINDOW_FOUND OR NOT SFML_SYSTEM_FOUND)
    set(MISSING_DEP TRUE)
endif()

if (MISSING_DEP)
    file(WRITE ${CMAKE_BINARY_DIR}/empty.cpp "")
    set(SOURCES ${CMAKE_BINARY_DIR}/empty.cpp)
else()
    file(GLOB SOURCES src/*.cpp)
endif()

add_library(raytracer_sfml SHARED ${SOURCES})
set_target_properties(raytracer_sfml PROPERTIES
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/renderer"
)

target_include_directories(raytracer_sfml PRIVATE
    ../
    ../../Utils/
    ../../Raytracer/
    ../../Primitives/
    ${SFML_GRAPHICS_INCLUDE_DIRS}
    ${SFML_WINDOW_INCLUDE_DIRS}
    ${SFML_SYSTEM_INCLUDE_DIRS}
)

target_link_libraries(raytracer_sfml PRIVATE
    ${SFML_GRAPHICS_LIBRARIES}
    ${SFML_WINDOW_LIBRARIES}
    ${SFML_SYSTEM_LIBRARIES}
)

target_compile_options(raytracer_sfml PRIVATE -fno-gnu-unique)
