//
// EPITECH PROJECT, 2025
// Ray
// File description:
// Ray
//

#pragma once

#include "Vector.hpp"

namespace raytracer {
    class ray {
       public:
        ray() {}

        ray(const Vector3<double> &origin, const Vector3<double> &direction)
            : _origin(origin), _direction(direction)
        {}

        const Vector3<double> &getOrigin() const { return _origin; }

        const Vector3<double> &getDirection() const { return _direction; }

        Vector3<double> at(double length) const
        {
            return this->_origin + (this->_direction * length);
        }

       private:
        Vector3<double> _origin;
        Vector3<double> _direction;
    };
}  // namespace raytracer
