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

renderer::PpmRenderer::PpmRenderer()
{
    // créer le .ppm ig 
}

renderer::PpmRenderer::~PpmRenderer()
{
}

extern "C" {
std::unique_ptr<renderer::IRenderer> createRenderer(void)
{
    return std::make_unique<renderer::PpmRenderer>();
}
}
