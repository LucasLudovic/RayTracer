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

    ///
    /// \class SFMLRenderer
    /// \brief Concrete renderer implementation using SFML for 2D rendering.
    ///
    class SFMLRenderer : public IRenderer {
       public:
        ///
        /// \brief Constructor for SFMLRenderer.
        ///
        SFMLRenderer();

        ///
        /// \brief Destructor for SFMLRenderer.
        ///
        ~SFMLRenderer();

        ///
        /// \brief Draws text using SFML.
        /// \param text The text string to render.
        /// \param position Position where the text should be drawn.
        /// \param size Font size of the text.
        ///
        void drawText(const std::string &text,
            const raytracer::Vector2<float> &position,
            const unsigned size) override;

        ///
        /// \brief Draws an object using SFML.
        /// \param object The object to be rendered.
        /// \param color The color to apply to the object.
        ///
        void drawObject(const objects::IObject &object,
            const raytracer::Vector3<double> &color) override;

        ///
        /// \brief Draws a single pixel using SFML.
        /// \param position Coordinates of the pixel.
        /// \param color Color of the pixel.
        ///
        void drawPixel(const raytracer::Vector2<int> &position,
            const raytracer::Vector3<double> &color) override;

        ///
        /// \brief Displays the rendered frame on the window.
        ///
        bool render() override;

        ///
        /// \brief Clears the window for a new frame.
        ///
        void clear() override;

        ///
        /// \brief Resizes the rendering window.
        /// \param size New size of the window.
        ///
        void resize(raytracer::Vector2<unsigned> size) override;

       private:
        unsigned int _windowX = 900; ///< Default window width.
        unsigned int _windowY = 900; ///< Default window height.
        std::unique_ptr<sf::RenderWindow> _window = nullptr; ///< SFML render window.
        std::unique_ptr<sf::Font> _font = nullptr; ///< Font used for drawing text.
        sf::Image _pixel; ///< SFML image used to store pixel data.
        sf::Texture _texture; ///< Texture used for rendering image data.
        std::unique_ptr<sf::Sprite> _sprite = nullptr; ///< Sprite for displaying the final frame.
    };

}  // namespace renderer
