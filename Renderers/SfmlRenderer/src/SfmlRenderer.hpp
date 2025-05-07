//
// EPITECH PROJECT, 2025
// SFMLRenderer
// File description:
// SFMLRenderer
//

#pragma once

#include "IRenderer.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace renderer {
    class SFMLRenderer : public IRenderer {
       public:
        SFMLRenderer();
        ~SFMLRenderer();

        class SFMLError : public IRendererError {
           public:
            SFMLError(const std::string &msg) : _msg(msg) {};
            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            }
           private:
            std::string _msg;
        };

        void drawText(const std::string &text,
            const raytracer::Vector2<float> &position,
            const unsigned size) override;
        void drawObject(const objects::IObject &object) override;
        void render() override;
        void clear() override;

       private:
        const unsigned int _windowX = 900;
        const unsigned int _windowY = 900;
        std::unique_ptr<sf::RenderWindow> _window = nullptr;
        std::unique_ptr<sf::Font> _font = nullptr;
    };
}  // namespace renderer
