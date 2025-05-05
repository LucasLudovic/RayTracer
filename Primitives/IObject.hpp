//
// EPITECH PROJECT, 2025
// IObject
// File description:
// IObject
//

#pragma once

#include "../Utils/Vector.hpp"
#include <exception>
#include <string>

namespace objects {

    class IObject {
       public:
        virtual ~IObject() = default;

        class IObjectError : public std::exception {};

        void setPosition(raytracer::Vector3<double> pos);
        [[nodiscard]] raytracer::Vector3<double> getPosition();
    };
}  // namespace objects
