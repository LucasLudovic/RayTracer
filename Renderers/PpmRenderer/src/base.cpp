//
// EPITECH PROJECT, 2025
// PpmRenderer
// File description:
// PpmRenderer
//

#include "IRenderer.hpp"
#include "PpmRenderer.hpp"
#include <iostream>
#include <memory>
#include <fstream>

renderer::PpmRenderer::PpmRenderer()
{
    std::ofstream _image("output.ppm");
    _windowX = 1920;
    _windowY = 1080;
    _image << "P3\n" << _windowX << " " << _windowY << "\n255\n";
}

renderer::PpmRenderer::~PpmRenderer()
{
}

void renderer::PpmRenderer::resize(raytracer::Vector2<unsigned> size)
{
}

extern "C" {
std::unique_ptr<renderer::IRenderer> createRenderer(void)
{
    return std::make_unique<renderer::PpmRenderer>();
}
}
