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
        virtual ~IObject() = default;

        class IObjectError : public std::exception {};

        virtual void setPosition(Vector3<double> pos) = 0;
        [[nodiscard]] virtual Vector3<double> getPosition() const = 0;
    };
}  // namespace objects
