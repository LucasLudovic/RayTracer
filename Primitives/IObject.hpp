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

        virtual std::string getType() const = 0;
        virtual void setPosition(raytracer::Vector3<double> pos) = 0;
        [[nodiscard]] virtual raytracer::Vector3<double> getPosition() = 0;
    };
}  // namespace objects
