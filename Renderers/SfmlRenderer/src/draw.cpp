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

///
/// \brief Draws a text string at the specified position.
/// 
/// Uses the SFML text rendering system to draw a string with a given font and size.
/// Throws a RendererError if the font has not been initialized.
/// 
/// \param textStr The text to draw.
/// \param pos The 2D position where the text should appear.
/// \param size The font size.
///
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

///
/// \brief Draws a 3D object.
/// 
/// Not yet implemented. This function is meant to draw a complex object
/// using SFML primitives or a custom method.
///
/// \param object The object to render.
/// \param color The color used to render the object.
///
void renderer::SFMLRenderer::drawObject(
    const objects::IObject &object, const raytracer::Vector3<double> &color)
{
    // To be implemented
}

///
/// \brief Draws a single pixel at the specified position with a specific color.
/// 
/// The color components are clamped to the [0, 255] range and converted to SFML's color format.
/// If the position is outside the window bounds, the pixel is not drawn.
/// 
/// \param position The integer 2D coordinates of the pixel.
/// \param color The RGB color of the pixel (each component as a double from 0 to 255).
///
void renderer::SFMLRenderer::drawPixel(const raytracer::Vector2<int> &position,
    const raytracer::Vector3<double> &color)
{
    auto x = static_cast<unsigned int>(position.getX());
    auto y = static_cast<unsigned int>(position.getY());

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
