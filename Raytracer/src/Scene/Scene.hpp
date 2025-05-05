//
// EPITECH PROJECT, 2025
// Scene
// File description:
// Object containing the elements for the app
//

#pragma once

#include "IObject.hpp"
#include <string>
#include <vector>

namespace raytracer {
    class Scene {
       public:
        Scene() {};
        ~Scene() = default;

        void load(const std::string &file);

       private:
        std::vector<objects::IObject> _composition;
    };
}  // namespace raytracer
