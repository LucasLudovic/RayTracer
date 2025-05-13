//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render the window
//

#include "SfmlRenderer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void renderer::SFMLRenderer::render()
{
    this->_texture.update(this->_pixel);
    this->_window->clear();
    this->_window->draw(*this->_sprite);
    this->_window->display();
}

void renderer::SFMLRenderer::clear()
{
    this->_pixel.resize({this->_windowX - 1, this->_windowY - 1}, sf::Color::Black);
    this->_window->clear();
}
