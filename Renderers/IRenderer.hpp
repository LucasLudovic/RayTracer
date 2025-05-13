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
    class RendererError : public std::exception {
       public:
        RendererError(const std::string &msg) : _msg(msg) {};

        [[nodiscard]] const char *what() const noexcept override
        {
            return this->_msg.c_str();
        };

       private:
        std::string _msg;
    };

    class IRenderer {
       public:
        virtual ~IRenderer() = default;

        virtual void drawText(const std::string &text,
            const raytracer::Vector2<float> &position,
            const unsigned size) = 0;
        virtual void drawObject(const objects::IObject &object,
            const raytracer::Vector3<int> &color) = 0;
        virtual void render() = 0;
        virtual void clear() = 0;

       private:
    };

    extern "C" std::unique_ptr<IRenderer> createRenderer(void);
}  // namespace renderer
