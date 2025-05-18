//
// EPITECH PROJECT, 2025
// Draw
// File description:
// Draw the entity for SFML
//

#include "IRenderer.hpp"
#include "PpmRenderer.hpp"
#include "Vector.hpp"
#include <algorithm>
#include <iostream>

///
/// \brief Draws a text string to the PPM image.
///
/// Currently, the function isn't necessary for Ppm format
///
/// \param textStr The text to draw.
/// \param pos The position where the text should appear.
/// \param size The font size.
///
void renderer::PpmRenderer::drawText(const std::string &textStr,
    const raytracer::Vector2<float> &pos, const unsigned size)
{
}

///
/// \brief Draws a 3D object to the PPM image.
///
/// Currently, the function isn't necessary for Ppm format
///
/// \param object The object to render.
/// \param color The color used to render the object.
///
void renderer::PpmRenderer::drawObject(
    const objects::IObject &object, const raytracer::Vector3<double> &color)
{
}

///
/// \brief Draws a single pixel in the PPM image output.
///
/// Converts the RGB color to integers in the range [0, 255],
/// clamps them if necessary, and writes them to the output stream
/// in the PPM plain-text format. Skips drawing if the position is out of bounds.
///
/// \param position 2D coordinates of the pixel.
/// \param color RGB color of the pixel (each component as a double).
///
void renderer::PpmRenderer::drawPixel(const raytracer::Vector2<int> &position,
    const raytracer::Vector3<double> &color)
{
    unsigned int x = static_cast<unsigned int>(position.getX());
    unsigned int y = static_cast<unsigned int>(position.getY());

    if (x >= static_cast<unsigned int>(_windowX) || y >= static_cast<unsigned int>(_windowY))
        return;

    int r = std::clamp(color.getX(), 0.0, 255.0);
    int g = std::clamp(color.getY(), 0.0, 255.0);
    int b = std::clamp(color.getZ(), 0.0, 255.0);

    _image << r << ' ' << g << ' ' << b << ' ';
}
