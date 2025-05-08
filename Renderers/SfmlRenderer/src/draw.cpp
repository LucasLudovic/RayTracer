//
// EPITECH PROJECT, 2025
// Draw
// File description:
// Draw the entity for SFML
//

#include "SfmlRenderer.hpp"
#include "Vector.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>

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

void renderer::SFMLRenderer::drawObject(const objects::IObject &object)
{
}
