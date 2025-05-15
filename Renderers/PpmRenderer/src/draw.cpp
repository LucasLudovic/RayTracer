//
// EPITECH PROJECT, 2025
// Draw
// File description:
// Draw the entity for SFML
//

#include "IRenderer.hpp"
#include "PpmRenderer.hpp"
#include "Vector.hpp"
#include <algorithm>
#include <iostream>

void renderer::PpmRenderer::drawText(const std::string &textStr,
    const raytracer::Vector2<float> &pos, const unsigned size)
{
}

void renderer::PpmRenderer::drawObject(
    const objects::IObject &object, const raytracer::Vector3<double> &color)
{}

void renderer::PpmRenderer::drawPixel(const raytracer::Vector2<int> &position,
    const raytracer::Vector3<double> &color)
{
    unsigned int x = static_cast<unsigned int>(position.getX());
    unsigned int y = static_cast<unsigned int>(position.getY());

    if (x >= static_cast<unsigned int>(_windowX) || y >= static_cast<unsigned int>(_windowY))
        return;

    int r = std::clamp(color.getX(), 0.0, 255.0);
    int g = std::clamp(color.getY(), 0.0, 255.0);
    int b = std::clamp(color.getZ(), 0.0, 255.0);

    _image << r << ' ' << g << ' ' << b << ' ';
}
