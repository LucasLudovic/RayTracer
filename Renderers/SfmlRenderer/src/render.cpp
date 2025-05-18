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

///
/// \brief Renders the current frame to the window.
/// 
/// Updates the texture with the current pixel data, clears the previous content,
/// draws the sprite to the window, and finally displays the updated frame.
///
void renderer::SFMLRenderer::render()
{
    this->_texture.update(this->_pixel);
    this->clear();
    this->_window->draw(*this->_sprite);
    this->_window->display();
}

///
/// \brief Clears the rendering context.
/// 
/// Resets the pixel buffer with a black background and clears the SFML window
/// in preparation for a new frame.
///
void renderer::SFMLRenderer::clear()
{
    this->_pixel.resize({this->_windowX, this->_windowY}, sf::Color::Black);
    this->_window->clear();
}
