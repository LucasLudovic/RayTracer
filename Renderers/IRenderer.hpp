//
// EPITECH PROJECT, 2025
// IRenderer
// File description:
// IRenderer
//

#include <exception>

#include "IObject.hpp"
#include "Vector.hpp"

namespace renderer {
    class IRenderer {
       public:
        virtual ~IRenderer() = 0;

        class IRendererError : public std::exception {};

        virtual void drawText(const std::string &text,
            const raytracer::Vector2<float> &position,
            const unsigned size) = 0;
        virtual void drawObject(const objects::IObject &object) = 0;
        virtual void render() = 0;
        virtual void clear() = 0;

       private:
    };
}  // namespace renderer
