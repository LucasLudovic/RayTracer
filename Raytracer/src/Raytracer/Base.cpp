//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Object to handle the raytracer
//

#include "Raytracer.hpp"
#include "src/DlLib/DlLib.hpp"
#include "src/my_macros.hpp"
#include <chrono>
#include <fstream>
#include <thread>

raytracer::Raytracer::Raytracer(const std::string &file)
{
    std::ifstream fileStream(file);

    if (!fileStream.is_open())
        throw RaytracerError("File argument is invalid");
    fileStream.close();
    this->_scene.load(file);
    Utils::DlLib<renderer::IRenderer> renderer("lib/raytracer_sfml.so");
}

void raytracer::Raytracer::run()
{
    const std::chrono::milliseconds targetFrameDuration(FRAME_DURATION_MS);

    while (this->_isRunning) {
        auto frameStart = std::chrono::steady_clock::now();

        auto frameEnd = std::chrono::steady_clock::now();
        auto frameDuration =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                frameEnd - frameStart);
        if (frameDuration < targetFrameDuration) {
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
        }
    }
}
