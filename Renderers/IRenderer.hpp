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

        void drawText();
        void drawObject(const objects::IObject &object);
        void render();
        void clear();
       private:
    };
}  // namespace renderer
