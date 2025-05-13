//
// EPITECH PROJECT, 2025
// SFMLRenderer
// File description:
// SFMLRenderer
//

#pragma once

#include "IRenderer.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

namespace renderer {
    class SFMLRenderer : public IRenderer {
       public:
        SFMLRenderer();
        ~SFMLRenderer();

        void drawText(const std::string &text,
            const raytracer::Vector2<float> &position,
            const unsigned size) override;
        void drawObject(const objects::IObject &object,
            const raytracer::Vector3<int> &color) override;
        void drawPixel(const raytracer::Vector2<int> &position,
            const raytracer::Vector3<int> &color) override;
        void render() override;
        void clear() override;
        void resize(raytracer::Vector2<unsigned> size) override;

       private:
        unsigned int _windowX = 900;
        unsigned int _windowY = 900;
        std::unique_ptr<sf::RenderWindow> _window = nullptr;
        std::unique_ptr<sf::Font> _font = nullptr;
        sf::Image _pixel;
        sf::Texture _texture;
        std::unique_ptr<sf::Sprite> _sprite = nullptr;
    };
}  // namespace renderer
