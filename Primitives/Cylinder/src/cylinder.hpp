//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// cylinder.hpp
//

#pragma once

#include "AObject.hpp"

namespace objects {

/// @brief Represents a Cylinder object in the raytracer scene.
/// Inherits from AObject and implements intersection logic.
class Cylinder : public AObject {
   public:
    /// @brief Default constructor for Cylinder.
    Cylinder();

    /// @brief Creates a clone (deep copy) of this Cylinder object.
    /// @return A unique_ptr to the cloned Cylinder.
    std::unique_ptr<IObject> clone() const override;

    /// @brief Returns the type name of the object.
    /// @return A string representing the object type: "Cylinder".
    std::string getType() const override { return "Cylinder"; };

    /// @brief Checks if the given ray intersects with this Cylinder.
    /// @param ray The raycast to test for intersection.
    /// @param result Reference to a hitResult_t to store intersection details.
    /// @return True if the ray hits the cylinder; otherwise false.
    bool hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const override;

   private:
    // No additional private members.
};

}  // namespace objects
