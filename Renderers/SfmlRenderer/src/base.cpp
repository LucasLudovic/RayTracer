//
// EPITECH PROJECT, 2025
// SFMLRenderer
// File description:
// SFMLRenderer
//

#include "IRenderer.hpp"
#include "SfmlRenderer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

renderer::SFMLRenderer::SFMLRenderer()
{
    this->_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode({1920, 1080}), "Raytracer");

    if (this->_window == nullptr)
        throw RendererError("Unable to create window");
    this->_font = std::make_unique<sf::Font>();
    if (!std::filesystem::exists(
            "./assets/fonts/JetBrainsMonoNerdFont-Medium.ttf"))
        throw RendererError("Font file does not exist");
    if (!this->_font->openFromFile(
            "./assets/fonts/JetBrainsMonoNerdFont-Medium.ttf"))
        throw RendererError("Unable to load font");
}

renderer::SFMLRenderer::~SFMLRenderer()
{
    if (this->_window)
        this->_window->close();
}

// std::unique_ptr<renderer::IRenderer> createRenderer()
// {
//     return std::make_unique<renderer::SFMLRenderer>();
// }

extern "C" {
std::unique_ptr<renderer::IRenderer> createRenderer(void)
{
    return std::make_unique<renderer::SFMLRenderer>();
}
}
