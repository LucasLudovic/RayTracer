//
// EPITECH PROJECT, 2025
// Scene
// File description:
// Object containing the elements for the app
//

#pragma once

#include "IObject.hpp"
#include "Vector.hpp"
#include "IRenderer.hpp"
#include <exception>
#include <memory>
#include <string>
#include <vector>

namespace raytracer {
    class Scene {
       public:
        Scene() {};
        ~Scene() = default;

        void load(const std::string &file);
        void renderScene(renderer::IRenderer &renderer);

        class SceneError : public std::exception {
           public:
            SceneError(const std::string &msg) : _msg(msg) {};
            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            }
           private:
            std::string _msg;
        };

       private:
        std::vector<std::unique_ptr<objects::IObject>> _composition;
        std::vector<std::unique_ptr<objects::IObject>> _availableObjects;
        std::unique_ptr<objects::IObject> _camera;

        void _getAvailableObject();
        Vector3<double> _computeRelativePos(const objects::IObject &object);
    };
}  // namespace raytracer
