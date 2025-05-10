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
    class Lights {
       public:
        Lights();

        double getAmbient() const { return this->_ambient; }

        double getDiffuse() const { return this->_diffuse; }

        std::vector<raytracer::Vector3<int>> getPoint() const { return this->_point; }

        void setAmbient(double ambient) { this->_ambient = ambient; }

        void setDiffuse(double diffuse) { this->_diffuse = diffuse; }

        void setPoint(const std::vector<raytracer::Vector3<int>> &newPoint)
        {
            this->_point = newPoint;
        }

       private:
        double _ambient = 0;
        double _diffuse = 0;
        std::vector<raytracer::Vector3<int>> _point;
    };
}  // namespace objects
