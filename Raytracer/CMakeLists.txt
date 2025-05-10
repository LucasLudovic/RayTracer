cmake_minimum_required(VERSION 3.10)

project(raytracer CXX)

set(SOURCE_FILES
    src/main.cpp
    src/app.cpp
    src/Scene/Base.cpp
    src/Scene/Render.cpp
    src/DlLib/DlLib.cpp
    src/Raytracer/Base.cpp
    src/Modules/Camera/src/base.cpp
    src/Modules/Lights/src/base.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ../Primitives/)
target_include_directories(${PROJECT_NAME} PRIVATE ../Parsers/)
target_include_directories(${PROJECT_NAME} PRIVATE ../Utils/)
target_include_directories(${PROJECT_NAME} PRIVATE ../Renderers/)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
