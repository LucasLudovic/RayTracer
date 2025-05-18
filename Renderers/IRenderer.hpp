//
// EPITECH PROJECT, 2025
// IRenderer
// File description:
// IRenderer
//

#pragma once

#include "IObject.hpp"
#include "Vector.hpp"
#include <exception>
#include <memory>

namespace renderer {

    ///
    /// \class RendererError
    /// \brief Custom exception class for rendering-related errors.
    ///
    class RendererError : public std::exception {
       public:
        ///
        /// \brief Constructor for RendererError.
        /// \param msg Error message string.
        ///
        RendererError(const std::string &msg) : _msg(msg) {};

        ///
        /// \brief Returns the error message.
        /// \return A C-style string containing the error message.
        ///
        [[nodiscard]] const char *what() const noexcept override
        {
            return this->_msg.c_str();
        };

       private:
        std::string _msg; ///< The error message.
    };

    ///
    /// \class IRenderer
    /// \brief Abstract interface for rendering systems.
    ///
    class IRenderer {
       public:
        ///
        /// \brief Virtual destructor.
        ///
        virtual ~IRenderer() = default;

        ///
        /// \brief Draws a text string on the screen.
        /// \param text The text to be rendered.
        /// \param position The position on the screen to render the text.
        /// \param size Font size of the text.
        ///
        virtual void drawText(const std::string &text,
            const raytracer::Vector2<float> &position,
            const unsigned size) = 0;

        ///
        /// \brief Draws a 3D object.
        /// \param object The object to draw.
        /// \param color The color used for rendering the object.
        ///
        virtual void drawObject(const objects::IObject &object,
            const raytracer::Vector3<double> &color) = 0;

        ///
        /// \brief Draws a single pixel.
        /// \param position Coordinates of the pixel.
        /// \param color Color of the pixel.
        ///
        virtual void drawPixel(const raytracer::Vector2<int> &position,
            const raytracer::Vector3<double> &color) = 0;

        ///
        /// \brief Renders the current frame.
        ///
        virtual void render() = 0;

        ///
        /// \brief Clears the current rendering context.
        ///
        virtual void clear() = 0;

        ///
        /// \brief Resizes the rendering context.
        /// \param size New dimensions of the rendering area.
        ///
        virtual void resize(raytracer::Vector2<unsigned> size) = 0;

       private:
        // Interface — no internal members.
    };

    ///
    /// \brief Factory function to create an instance of a renderer.
    /// \return A unique pointer to an IRenderer instance.
    ///
    extern "C" std::unique_ptr<IRenderer> createRenderer(void);

}  // namespace renderer
