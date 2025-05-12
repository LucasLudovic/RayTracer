//
// EPITECH PROJECT, 2025
// Raycast
// File description:
// Raycast
//

#pragma once

#include "Vector.hpp"

namespace raytracer {
    class Raycast {
       public:
        Raycast() {};
        Raycast(
            const Vector3<double> &origin, const Vector3<double> &direction)
            : _origin(origin), _direction(direction) {};
        ~Raycast() = default;

        Vector3<double> getOrigin() { return this->_origin; };

        Vector3<double> getDirection() { return this->_direction; };
        Vector3<double> at(double length) const
        {
            return this->_origin + (this->_direction * length);
        }

       private:
        Vector3<double> _origin;
        Vector3<double> _direction;
    };
}  // namespace raytracer
