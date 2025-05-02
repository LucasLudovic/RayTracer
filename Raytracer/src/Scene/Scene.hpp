//
// EPITECH PROJECT, 2025
// Scene
// File description:
// Object containing the elements for the app
//

#pragma once

#include <string>
namespace raytracer {
    class Scene {
       public:
        Scene() {};
        ~Scene() = default;

        void load(const std::string &file);

       private:
    };
}  // namespace raytracer
