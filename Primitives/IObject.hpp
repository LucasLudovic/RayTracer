//
// EPITECH PROJECT, 2025
// IObject
// File description:
// IObject
//

#pragma once

#include "Utils.hpp"
#include <exception>
#include <string>

namespace objects {

    class IObject {
       public:
        IObject() = default;
        ~IObject() = default;

        class IObjectError : std::exception {};

        void setPosition(Vector3<double> pos);
        [[nodiscard]] Vector3<double> getPosition();
    };
}  // namespace objects
