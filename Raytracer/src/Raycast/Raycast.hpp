//
// EPITECH PROJECT, 2025
// Raycast
// File description:
// Raycast
//

#pragma once

#include "Vector.hpp"

namespace raytracer {

    /**
     * @class Raycast
     * @brief Represents a ray in 3D space for ray tracing.
     *
     * A ray consists of an origin and a direction. This class provides
     * utilities for querying ray properties and calculating points along the ray.
     */
    class Raycast {
       public:
        /**
         * @brief Default constructor.
         */
        Raycast() {};

        /**
         * @brief Constructs a Raycast with a given origin and direction.
         * @param origin The starting point of the ray.
         * @param direction The normalized direction vector of the ray.
         */
        Raycast(
            const Vector3<double> &origin, const Vector3<double> &direction)
            : _origin(origin), _direction(direction) {};

        /**
         * @brief Default destructor.
         */
        ~Raycast() = default;

        /**
         * @brief Returns the origin of the ray.
         * @return A 3D vector representing the origin point.
         */
        Vector3<double> getOrigin() const { return this->_origin; };

        /**
         * @brief Returns the direction of the ray.
         * @return A 3D vector representing the ray's direction.
         */
        Vector3<double> getDirection() const { return this->_direction; };

        /**
         * @brief Computes the position along the ray at a given distance.
         * @param length The distance from the origin.
         * @return A 3D point located along the ray at the specified distance.
         */
        Vector3<double> at(double length) const
        {
            return this->_origin + (this->_direction * length);
        }

       private:
        Vector3<double> _origin;    ///< Origin point of the ray.
        Vector3<double> _direction; ///< Direction vector of the ray.
    };

}  // namespace raytracer
