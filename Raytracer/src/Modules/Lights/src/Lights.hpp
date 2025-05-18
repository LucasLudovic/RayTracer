//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Lights.hpp
//

#pragma once

#include "Vector.hpp"
#include <vector>

namespace objects {

    /**
     * @class Lights
     * @brief Represents the lighting configuration in a 3D scene.
     *
     * The Lights class defines ambient and diffuse light components,
     * as well as a list of point light sources in 3D space.
     */
    class Lights {
       public:
        /**
         * @brief Default constructor.
         */
        Lights();

        /**
         * @brief Gets the ambient light intensity.
         * @return A double representing the ambient light level.
         */
        double getAmbient() const { return this->_ambient; }

        /**
         * @brief Gets the diffuse light intensity.
         * @return A double representing the diffuse light level.
         */
        double getDiffuse() const { return this->_diffuse; }

        /**
         * @brief Gets the list of point light sources.
         * @return A vector of 3D vectors representing point light positions.
         */
        std::vector<raytracer::Vector3<int>> getPoint() const { return this->_point; }

        /**
         * @brief Sets the ambient light intensity.
         * @param ambient New ambient light level.
         */
        void setAmbient(double ambient) { this->_ambient = ambient; }

        /**
         * @brief Sets the diffuse light intensity.
         * @param diffuse New diffuse light level.
         */
        void setDiffuse(double diffuse) { this->_diffuse = diffuse; }

        /**
         * @brief Sets the point light sources.
         * @param newPoint A vector of 3D vectors representing new point light positions.
         */
        void setPoint(const std::vector<raytracer::Vector3<int>> &newPoint)
        {
            this->_point = newPoint;
        }

       private:
        double _ambient = 0; ///< Ambient light intensity.
        double _diffuse = 0; ///< Diffuse light intensity.
        std::vector<raytracer::Vector3<int>> _point; ///< Positions of point light sources.
    };

}  // namespace objects
