//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// cone.hpp
//

#pragma once

#include "AObject.hpp"

namespace objects {

    ///
    /// @class Cone
    /// @brief Represents a cone primitive in the raytracer scene.
    ///
    /// Inherits from AObject and implements hit detection for ray intersections.
    ///
    class Cone : public AObject {
       public:
        ///
        /// @brief Default constructor for the Cone class.
        ///
        Cone();

        ///
        /// @brief Creates a clone of the current Cone object.
        /// @return A unique pointer to the cloned Cone instance.
        ///
        std::unique_ptr<IObject> clone() const override;

        ///
        /// @brief Returns the type of the object as a string.
        /// @return The string "Cone".
        ///
        std::string getType() const override { return "Cone"; };

        ///
        /// @brief Tests if a ray intersects with the cone.
        /// @param ray The raycast to test against.
        /// @param result Reference to a hitResult_t structure to store intersection data.
        /// @return True if the ray hits the cone, false otherwise.
        ///
        bool hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const override;

       private:
        // Private members, if any, go here
    };
}  // namespace objects
