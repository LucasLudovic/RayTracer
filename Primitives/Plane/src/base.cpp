//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "plane.hpp"

/// @brief Default constructor for the Plane class.
objects::Plane::Plane() : AObject() {}

/// @brief Creates a copy of the current Plane object.
/// @return A unique pointer to the cloned Plane object.
std::unique_ptr<objects::IObject> objects::Plane::clone() const
{
    return std::make_unique<objects::Plane>(*this);
}

extern "C" {
    /// @brief Factory function to create a new Plane primitive.
/// @return A unique pointer to a new Plane object.
    std::unique_ptr<objects::IObject> objects::createPrimitive(void)
    {
        return std::make_unique<objects::Plane>();
    }
}
