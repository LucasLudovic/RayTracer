//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Object to handle the raytracer
//


#include "src/Raytracer/Raytracer.hpp"
#include <fstream>

raytracer::Raytracer::Raytracer(const std::string &file)
{
    std::ifstream fileStream(file);

    if (!fileStream.is_open())
        throw RaytracerError("File argument is invalid\n");
    fileStream.close();
    this->_scene.load(file);
}

void raytracer::Raytracer::run()
{
    while (this->_isRunning) {
    }
}
