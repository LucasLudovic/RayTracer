//
// EPITECH PROJECT, 2025
// Material
// File description:
// Material
//

#pragma once

#include "../Utils/Vector.hpp"

namespace objects {
class Material
{
   public:
    Material() : _color(), _transparence(0), _reflection(0) {}
    void set_color(raytracer::Vector3<double> color)
    {
        this->_color = color;
    }
    void set_color(double r, double g, double b)
    {
        this->_color = {r, g, b};
    }
    void set_transparence(double transparence)
    {
        this->_transparence = transparence;
    }
    void set_reflection(double reflection)
    {
        this->_reflection = reflection;
    }
    [[nodiscard]] raytracer::Vector3<double> get_color() const
    {
        return this->_color;
    }
    [[nodiscard]] double get_transparence() const
    {
        return this->_transparence;
    }
    [[nodiscard]] double get_reflection() const
    {
        return this->_reflection;
    }

   private:
    raytracer::Vector3<double> _color;
    double _transparence;
    double _reflection;
};
}  // namespace objects
