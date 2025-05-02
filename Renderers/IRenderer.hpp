//
// EPITECH PROJECT, 2025
// IRenderer
// File description:
// IRenderer
//

#include <exception>

#include "IObject.hpp"

namespace renderer {
    class IRenderer {
       public:
        ~IRenderer() = default;

        class IRendererError : public std::exception {};

        virtual void drawText();
        virtual void drawObject(const objects::IObject &object);
        virtual void render();
        virtual void clear();
       private:
    };
}  // namespace renderer
