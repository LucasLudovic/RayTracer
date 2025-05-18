/*
** EPITECH PROJECT, 2025
** raytracer
** File description:
** ppmrenderer.hpp
*/

#pragma once

#include "IRenderer.hpp"
#include <fstream>

namespace renderer {

    ///
    /// \class PpmRenderer
    /// \brief A renderer that outputs a scene to a PPM image file.
    ///
    /// The `PpmRenderer` class implements the `IRenderer` interface and provides
    /// a minimal implementation that writes RGB pixel data to a plain text PPM
    /// (Portable PixMap) file.
    ///
    class PpmRenderer : public IRenderer {
       public:
        ///
        /// \brief Constructor for PpmRenderer.
        ///
        /// Initializes internal dimensions and opens the output PPM file
        /// ("output.ppm"). Also writes the appropriate PPM header.
        ///
        PpmRenderer();

        ///
        /// \brief Destructor for PpmRenderer.
        ///
        /// Handles cleanup. Closes the image file if necessary.
        ///
        ~PpmRenderer();

        ///
        /// \brief Draws text to the output (not implemented).
        ///
        /// \param text The string to draw.
        /// \param position The position on the screen.
        /// \param size The size of the font.
        ///
        void drawText(const std::string &text,
            const raytracer::Vector2<float> &position,
            const unsigned size) override;

        ///
        /// \brief Draws a 3D object to the output (not implemented).
        ///
        /// \param object The object to render.
        /// \param color The color to use for rendering.
        ///
        void drawObject(const objects::IObject &object,
            const raytracer::Vector3<double> &color) override;

        ///
        /// \brief Draws a single pixel with RGB color to the output.
        ///
        /// \param position The pixel's coordinates.
        /// \param color The color of the pixel.
        ///
        void drawPixel(const raytracer::Vector2<int> &position,
            const raytracer::Vector3<double> &color) override;

        ///
        /// \brief Finalizes the image output (not implemented).
        ///
        void render() override;

        ///
        /// \brief Clears the image buffer (not implemented).
        ///
        void clear() override;

        ///
        /// \brief Resizes the rendering resolution (currently unused).
        ///
        /// \param size The new dimensions.
        ///
        void resize(raytracer::Vector2<unsigned> size) override;

       private:
        unsigned int _windowX = 900;  ///< Width of the image output.
        unsigned int _windowY = 900;  ///< Height of the image output.
        std::ofstream _image;         ///< Output file stream for writing PPM data.
    };

}  // namespace renderer
