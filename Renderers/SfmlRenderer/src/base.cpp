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
#include <memory>
#include <iostream>

///
/// \brief Constructor for SFMLRenderer.
/// 
/// Initializes the SFML render window, loads the font from file,
/// sets up the pixel buffer, creates the texture and sprite.
/// Throws RendererError if any resource fails to load or initialize.
///
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

    this->_pixel.resize({this->_windowX, this->_windowY}, sf::Color::Black);

    if (!this->_texture.loadFromImage(this->_pixel)) {
        throw RendererError("Unable to load pixel in texture");
    }

    this->_sprite = std::make_unique<sf::Sprite>(this->_texture);
    if (this->_sprite == nullptr) {
        throw RendererError("Unable to create sprite from texture");
    }
}

///
/// \brief Destructor for SFMLRenderer.
/// 
/// Closes the SFML window if it is still open.
///
renderer::SFMLRenderer::~SFMLRenderer()
{
    if (this->_window)
        this->_window->close();
}

///
/// \brief Resizes the rendering context and updates internal buffers.
/// 
/// Updates the window size, resizes the texture and pixel buffer,
/// updates the view and sprite accordingly. Throws RendererError
/// if the size is invalid or if a resource cannot be resized.
/// 
/// \param size New window size as a 2D vector.
///
void renderer::SFMLRenderer::resize(raytracer::Vector2<unsigned> size)
{
    if (size.getX() == 0 || size.getY() == 0) {
        throw RendererError("Size must be strictly superior to 0");
    }

    this->_windowX = size.getX();
    this->_windowY = size.getY();

    this->_window->setSize({this->_windowX, this->_windowY});

    if (this->_texture.resize(this->_window->getSize()) == false) {
        throw RendererError("Unable to resize texture");
    }

    this->_pixel.resize({this->_windowX, this->_windowY}, sf::Color::Black);
    this->_sprite->setTexture(this->_texture, true);

    sf::View newView = this->_window->getDefaultView();
    newView.setSize({static_cast<float>(this->_windowX),
        static_cast<float>(this->_windowY)});
    newView.setCenter({static_cast<float>(this->_windowX) / 2.f,
        static_cast<float>(this->_windowY) / 2.f});
    this->_window->setView(newView);
}

///
/// \brief C-style factory function for creating an SFMLRenderer instance.
/// 
/// Used for dynamic loading of the renderer in a plugin system.
/// 
/// \return A unique pointer to an IRenderer instance.
///
extern "C" {
std::unique_ptr<renderer::IRenderer> createRenderer(void)
{
    return std::make_unique<renderer::SFMLRenderer>();
}
}
