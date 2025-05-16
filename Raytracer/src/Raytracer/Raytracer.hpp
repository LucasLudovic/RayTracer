//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Header for object to handle the raytracer
//

#pragma once

#include "src/Scene/Scene.hpp"
#include <memory>
#include "IRenderer.hpp"
#include <exception>
#include <string>

namespace raytracer {
    class Raytracer {
       public:
        Raytracer(const std::string &file, const std::string rendererPath);
        ~Raytracer() = default;

        class RaytracerError : std::exception {
           public:
            RaytracerError(const std::string &msg) : _msg(msg) {};

            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            }

           private:
            std::string _msg;
        };
        
        void run();

       private:
        bool _isRunning = true;
        Scene _scene;
        std::string _rendererPath;

        std::unique_ptr<renderer::IRenderer> renderer = nullptr;
    };
};  // namespace raytracer
