//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// plane.hpp
//

#pragma once

#include "AObject.hpp"

namespace objects {

    /// @brief Class representing a plane object in the scene.
    /// Inherits from AObject and implements plane-specific methods.
    class Plane : public AObject {
       public:
        /// @brief Default constructor for the Plane class.
        Plane();

        /// @brief Clones the current Plane object.
        /// @return A unique pointer to a copy of the Plane object.
        std::unique_ptr<IObject> clone() const override;

        /// @brief Returns the type of the object.
        /// @return The string "Plane".
        std::string getType() const override { return "Plane"; };

        /// @brief Tests intersection between a ray and the plane.
        /// @param ray The ray to test.
        /// @param result Structure to store hit result data.
        /// @return `true` if the ray intersects the plane, `false` otherwise.
        bool hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const override;

       private:
        // No specific private members for Plane.
    };
}  // namespace objects
