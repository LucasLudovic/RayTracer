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
#include <iostream>

raytracer::Raytracer::Raytracer(const std::string &file)
{
    std::ifstream fileStream(file);

    if (!fileStream.is_open())
        throw RaytracerError("File argument is invalid");
    fileStream.close();

    this->_scene.load(file);
}

void raytracer::Raytracer::run()
{
    const std::chrono::milliseconds targetFrameDuration(FRAME_DURATION_MS);
    Utils::DlLib<renderer::IRenderer> renderer("lib/renderers/raytracer_sfml.so");
    this->renderer = renderer.loadLib("createRenderer");

    if (this->renderer == nullptr) {
        throw RaytracerError("Unable to load renderer");
    }
    auto res = this->_scene.getCamera().getResolution();
    const auto resX = res.getX();
    const auto resY = res.getY();
    this->renderer->resize({static_cast<unsigned>(resX), static_cast<unsigned>(resY)});
    while (this->_isRunning) {
        auto frameStart = std::chrono::steady_clock::now();

        auto frameEnd = std::chrono::steady_clock::now();
        auto frameDuration =
            std::chrono::duration_cast<std::chrono::milliseconds>(
                frameEnd - frameStart);
        if (frameDuration < targetFrameDuration) {
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
        }
        this->_scene.renderScene(*this->renderer);
    }
}
