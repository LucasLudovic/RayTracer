//
// EPITECH PROJECT, 2025
// PpmRenderer
// File description:
// PpmRenderer
//

#include "IRenderer.hpp"
#include "PpmRenderer.hpp"
#include <iostream>
#include <memory>
#include <fstream>

///
/// \brief Constructor for PpmRenderer.
/// 
/// Initializes the output PPM image file with default dimensions (900x900)
/// and writes the PPM header. Logs an error if the file cannot be opened.
///
renderer::PpmRenderer::PpmRenderer() : _image("output.ppm")
{
    _windowX = 900;
    _windowY = 900;

    if (!_image.is_open()) {
        std::cerr << "Failed to open output.ppm for writing" << std::endl;
        return;
    }

    _image << "P3\n" << _windowX << " " << _windowY << "\n255\n";
}

///
/// \brief Destructor for PpmRenderer.
/// 
/// Handles any necessary cleanup. Currently does nothing explicit.
///
renderer::PpmRenderer::~PpmRenderer()
{
}

///
/// \brief Resizes the PPM renderer's internal resolution.
/// 
/// Handles any necessary cleanup. Currently does nothing explicit.
/// 
/// \param size The new size as a 2D vector of unsigned integers.
///
void renderer::PpmRenderer::resize(raytracer::Vector2<unsigned> size)
{
}

///
/// \brief Factory function for creating a PpmRenderer instance.
/// 
/// Used for dynamic loading of the renderer via a C-compatible interface.
/// 
/// \return A unique pointer to a new PpmRenderer instance.
///
extern "C" {
std::unique_ptr<renderer::IRenderer> createRenderer(void)
{
    return std::make_unique<renderer::PpmRenderer>();
}
}

