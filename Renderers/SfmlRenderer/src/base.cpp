//
// EPITECH PROJECT, 2025
// SFMLRenderer
// File description:
// SFMLRenderer
//

#include "IRenderer.hpp"
#include "SfmlRenderer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

renderer::SFMLRenderer::SFMLRenderer()
{
    this->_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode({this->_windowX, this->_windowY}), "Raytracer");

    if (this->_window == nullptr)
        throw RendererError("Unable to create window");
    this->_font = std::make_unique<sf::Font>();
    if (!std::filesystem::exists(
            "./assets/fonts/JetBrainsMonoNerdFont-Medium.ttf"))
        throw RendererError("Font file does not exist");
    if (!this->_font->openFromFile(
            "./assets/fonts/JetBrainsMonoNerdFont-Medium.ttf"))
        throw RendererError("Unable to load font");

    this->_pixel.resize({this->_windowX - 1, this->_windowY - 1}, sf::Color::Black);
    if (!this->_texture.loadFromImage(this->_pixel)) {
        throw RendererError("Unable to load pixel in texture");
    }

    this->_sprite = std::make_unique<sf::Sprite>(this->_texture);
    if (this->_sprite == nullptr) {
        throw RendererError("Unable to create sprite from texture");
    }
}

renderer::SFMLRenderer::~SFMLRenderer()
{
    if (this->_window)
        this->_window->close();
}

void renderer::SFMLRenderer::resize(raytracer::Vector2<unsigned> size)
{
    if (size.getX() == 0 || size.getY() == 0) {
        throw RendererError("Size must be strictly superior to 0");
    }
    this->_windowX = size.getX();
    this->_windowY = size.getY();
    this->_window->setSize({this->_windowX, this->_windowY});
}

extern "C" {
std::unique_ptr<renderer::IRenderer> createRenderer(void)
{
    return std::make_unique<renderer::SFMLRenderer>();
}
}
