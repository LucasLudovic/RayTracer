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
    class PpmRenderer : public IRenderer {
       public:
        PpmRenderer();
        ~PpmRenderer();

        void drawText(const std::string &text,
            const raytracer::Vector2<float> &position,
            const unsigned size) override;

        void drawObject(const objects::IObject &object,
            const raytracer::Vector3<double> &color) override;

        void drawPixel(const raytracer::Vector2<int> &position,
            const raytracer::Vector3<double> &color) override;

        void render() override;
        void clear() override;
        void resize(raytracer::Vector2<unsigned> size) override;

       private:
        unsigned int _windowX = 900;
        unsigned int _windowY = 900;
        std::ofstream _image;
    };
}  // namespace renderer
