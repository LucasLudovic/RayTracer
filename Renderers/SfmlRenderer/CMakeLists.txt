cmake_minimum_required(VERSION 3.10)
project(raytracer_sfml LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System)

set(MISSING_DEP FALSE)
if (NOT SFML_FOUND)
    set(MISSING_DEP TRUE)
endif()

if (MISSING_DEP)
    file(WRITE ${CMAKE_BINARY_DIR}/empty.cpp "")
    set(SOURCES ${CMAKE_BINARY_DIR}/empty.cpp)
else()
    file(GLOB SOURCES src/*.cpp)
endif()

add_library(raytracer_sfml SHARED ${SOURCES})
set_target_properties(raytracer_sfml PROPERTIES PREFIX "")

if (NOT MISSING_DEP)
    target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/Primitives/
    ${CMAKE_SOURCE_DIR}/Parsers/
    ${CMAKE_SOURCE_DIR}/Renderers/
)

    target_link_libraries(raytracer_sfml PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
    )
endif()

target_compile_options(raytracer_sfml PRIVATE -fno-gnu-unique)
