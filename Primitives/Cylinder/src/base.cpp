//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "cylinder.hpp"

/// @brief Default constructor for the Cylinder class.
/// Initializes the base AObject class.
objects::Cylinder::Cylinder() : AObject() {}

/// @brief Creates a copy of the current Cylinder object.
/// @return A unique pointer to a new Cylinder object cloned from this instance.
std::unique_ptr<objects::IObject> objects::Cylinder::clone() const
{
    return std::make_unique<objects::Cylinder>(*this);
}

extern "C" {
    /// @brief Factory function to create a new Cylinder primitive object.
    /// @return A unique pointer to a newly created Cylinder instance.
    std::unique_ptr<objects::IObject> objects::createPrimitive(void)
    {
        return std::make_unique<objects::Cylinder>();
    }
}
