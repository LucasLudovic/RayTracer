//
// EPITECH PROJECT, 2025
// Raycast
// File description:
// Raycast
//

#pragma once

#include "Vector.hpp"

namespace raytracer {
    class raycast {
       public:
        raycast() {};
        raycast(
            const Vector3<double> &origin, const Vector3<double> &direction)
            : _origin(origin), _direction(direction) {};
        ~raycast() = default;

        Vector3<double> getOrigin() { return this->_origin; };

        Vector3<double> getDirection() { return this->_direction; };

       private:
        Vector3<double> _origin;
        Vector3<double> _direction;
    };
}  // namespace raytracer
