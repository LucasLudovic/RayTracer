//
// EPITECH PROJECT, 2025
// Material
// File description:
// Material
//

#pragma once

#include "../Utils/Vector.hpp"

namespace objects {
    ///
    /// \class Material
    /// \brief Represents surface properties of an object (color, reflection, transparence).
    ///
    /// The `Material` class stores appearance properties used by the raytracer
    /// to determine how an object interacts with light. This includes base color,
    /// reflection coefficient, and transparence (transparency) factor.
    ///
class Material
{
   public:
    ///
    /// \brief Default constructor.
    ///
    /// Initializes color to zero and sets reflection and transparence to 0.
    ///
    Material() : _color(), _transparence(0), _reflection(0) {}

    ///
    /// \brief Sets the material's color using a vector.
    ///
    /// \param color The RGB color vector.
    ///
    void set_color(raytracer::Vector3<double> color)
    {
        this->_color = color;
    }

    ///
     /// \brief Sets the material's color using individual RGB components.
    ///
    /// \param r Red component.
    /// \param g Green component.
    /// \param b Blue component.
    ///
    void set_color(double r, double g, double b)
    {
        this->_color = {r, g, b};
    }

    ///
    /// \brief Sets the transparence (opacity factor).
    ///
    /// A value of 0 means fully opaque; higher values increase transparency.
    ///
    /// \param transparence A double value representing transparence.
    ///
    void set_transparence(double transparence)
    {
        this->_transparence = transparence;
    }

    ///
    /// \brief Sets the reflection coefficient.
    ///
    /// A value of 0 means no reflection; higher values increase reflectiveness.
    ///
    /// \param reflection A double value representing reflection.
    ///
    void set_reflection(double reflection)
    {
        this->_reflection = reflection;
    }

    ///
    /// \brief Gets the current color of the material.
    ///
    /// \return A Vector3 representing the RGB color.
    ///
    [[nodiscard]] raytracer::Vector3<double> get_color() const
    {
        return this->_color;
    }

    ///
    /// \brief Gets the current transparence value.
    ///
    /// \return A double representing the transparence.
    ///
    [[nodiscard]] double get_transparence() const
    {
        return this->_transparence;
    }

    ///
    /// \brief Gets the current reflection value.
    ///
    /// \return A double representing the reflection coefficient.
    ///
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
