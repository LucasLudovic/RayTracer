//
// EPITECH PROJECT, 2025
// App
// File description:
// Entrypoint for the raytracer
//

#include "my_macros.hpp"
#include "src/Raytracer/Raytracer.hpp"
#include <iostream>
#include <string>

using raytracer::Raytracer;

int execute_raytracer(const std::string &sceneFile)
{
    try {
        raytracer::Raytracer raytracerCore(sceneFile);

        raytracerCore.run();
    } catch (const Raytracer::RaytracerError &error) {
        std::cerr << "Application Error: " << error.what() << std::endl;
        return EPITECH_FAILURE;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }
    return EPITECH_SUCCESS;
}
