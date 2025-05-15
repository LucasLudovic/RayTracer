//
// EPITECH PROJECT, 2025
// Draw
// File description:
// Draw the entity for SFML
//

#include "IRenderer.hpp"
#include "SfmlRenderer.hpp"
#include "Vector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <algorithm>
#include <iostream>

void renderer::SFMLRenderer::drawText(const std::string &textStr,
    const raytracer::Vector2<float> &pos, const unsigned size)
{
    if (!this->_font)
        throw RendererError("No font added\n");

    sf::Text text(*this->_font, textStr, size);
    text.setFillColor(sf::Color::White);
    text.setPosition({pos.getX(), pos.getY()});
    this->_window->draw(text);
}

void renderer::SFMLRenderer::drawObject(
    const objects::IObject &object, const raytracer::Vector3<double> &color)
{}

void renderer::SFMLRenderer::drawPixel(const raytracer::Vector2<int> &position,
    const raytracer::Vector3<double> &color)
{
    auto x = static_cast<unsigned int>(position.getX());
    auto y = static_cast<unsigned int>(position.getY());

    // std::cout << position << std::endl;
    // std::cout << x << " " << y << std::endl;
    if (x < 0 || x >= static_cast<int>(this->_windowX - 1) || y < 0 ||
        y >= static_cast<int>(this->_windowY - 1)) {
        return;
    }
    sf::Color clamped(
        static_cast<std::uint8_t>(std::clamp(color.getX(), 0.0, 255.0)),
        static_cast<std::uint8_t>(std::clamp(color.getY(), 0.0, 255.0)),
        static_cast<std::uint8_t>(std::clamp(color.getZ(), 0.0, 255.0)));
    this->_pixel.setPixel({x, y}, clamped);
}
