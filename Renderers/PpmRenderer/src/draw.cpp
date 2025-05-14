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

void renderer::PpmRenderer::drawObject(
    const objects::IObject &object, const raytracer::Vector3<int> &color)
{}

void renderer::PpmRenderer::drawPixel(const raytracer::Vector2<int> &position,
    const raytracer::Vector3<int> &color)
{
    // auto x = static_cast<unsigned int>(position.getX());
    // auto y = static_cast<unsigned int>(position.getY());

    // if (x < 0 || x >= static_cast<int>(this->_windowX - 1) || y < 0 ||
    //     y >= static_cast<int>(this->_windowY - 1)) {
    //     return;
    // }

    // this->_pixel.setPixel({x, y},
    //     sf::Color(static_cast<std::uint8_t>(std::clamp(color.getX(), 0, 255)),
    //         static_cast<std::uint8_t>(std::clamp(color.getY(), 0, 255)),
    //         static_cast<std::uint8_t>(std::clamp(color.getZ(), 0, 255))));
}
