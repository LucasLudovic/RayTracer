//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Header for object to handle the raytracer
//

#pragma once

#include <exception>
#include <string>

namespace raytracer {
    class Raytracer {
       public:
        Raytracer(const std::string &file);
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

       private:
        
    };
};  // namespace raytracer
