//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render the window
//

#include "SfmlRenderer.hpp"

void renderer::SFMLRenderer::render()
{
    this->_window->display();
}

void renderer::SFMLRenderer::clear()
{
    this->_window->clear();
}
