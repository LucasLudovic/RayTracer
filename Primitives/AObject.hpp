//
// EPITECH PROJECT, 2025
// AObject
// File description:
// AObject
//

#pragma once

#include "../Utils/Vector.hpp"
#include "IObject.hpp"
#include "Material.hpp"

namespace objects {

    ///
    /// \class AObject
    /// \brief Abstract base class implementing common behavior for IObject.
    ///
    /// Provides default implementations for position, color, transparency, reflection,
    /// and metadata management. Concrete object types (like Sphere, Plane, etc.)
    /// should inherit from this and implement `getType()` and `clone()`.
    ///
    class AObject : public objects::IObject {
       public:
        ///
        /// \brief Default constructor.
        ///
        AObject() : _material() {}; 

        ///
        /// \brief Gets the type of object as a string.
        ///
        /// \return The object's type.
        ///
        std::string getType() const override = 0;

        ///
        /// \brief Clones the object.
        ///
        /// \return A unique pointer to the copied object.
        ///
        std::unique_ptr<IObject> clone() const override = 0;

        ///
        /// \brief Sets the position of the object.
        ///
        /// \param pos The new position.
        ///
        void setPosition(raytracer::Vector3<int> pos) override
        {
            this->_position = pos;
        }

        ///
        /// \brief Gets the position of the object.
        ///
        /// \return The object's position.
        ///
        raytracer::Vector3<int> getPosition() const override
        {
            return this->_position;
        }

        ///
        /// \brief Sets the object color using a vector.
        ///
        /// \param rgb Color vector (r, g, b).
        ///
        void setColor(raytracer::Vector3<double> rgb) override
        {
            this->_material.set_color(rgb);
        }

        ///
        /// \brief Sets the object color using individual RGB values.
        ///
        void setColor(double r, double g, double b) override
        {
            this->_material.set_color(r, g, b);
        }

        ///
        /// \brief Gets the current color of the object.
        ///
        raytracer::Vector3<double> getColor() const override
        {
            return this->_material.get_color();
        }

        ///
        /// \brief Sets the transparency value of the object.
        ///
        void setTransparence(double value) override
        {
            this->_material.set_transparence(value);
        }

        ///
        /// \brief Gets the transparency value.
        ///
        double getTransparence() const override
        {
            return this->_material.get_transparence();
        }

        ///
        /// \brief Sets the reflection coefficient.
        ///
        void setReflection(double value) override
        {
            this->_material.set_reflection(value);
        }

        ///
        /// \brief Gets the reflection coefficient.
        ///
        double getReflection() const override
        {
            return this->_material.get_reflection();
        }

        ///
        /// \brief Sets metadata for the object.
        ///
        /// \param metadata The metadata struct to apply.
        ///
        void setMetadata(const metaData_t &metadata) override
        {
            this->_metaData = metadata;
        };

        ///
        /// \brief Accesses the object's metadata.
        ///
        /// \return A reference to the object's metadata.
        ///
        metaData_t &getMetaData() override { return this->_metaData; };

       protected:
        std::string _type; ///< Type of the object.
        raytracer::Vector3<int> _position; ///< Position of the object in space.
        objects::Material _material; ///< Material properties.
        metaData_t _metaData; ///< Optional metadata (e.g., radius, height).
    };

}  // namespace objects
