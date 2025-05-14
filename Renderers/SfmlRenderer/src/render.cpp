//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render the window
//

#include "SfmlRenderer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>

void renderer::SFMLRenderer::render()
{
    this->_texture.update(this->_pixel);
    this->clear();
    this->_window->draw(*this->_sprite);
    this->_window->display();
}

void renderer::SFMLRenderer::clear()
{
    this->_pixel.resize({this->_windowX, this->_windowY}, sf::Color::Black);
    this->_window->clear();
}
