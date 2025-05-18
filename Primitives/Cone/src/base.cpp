//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "cone.hpp"

/// @brief Default constructor for the Cone class.
/// Initializes the base AObject class.
objects::Cone::Cone() : AObject() {}

/// @brief Creates a copy of the current Cone object.
/// @return A unique pointer to a new Cone object cloned from this instance.
std::unique_ptr<objects::IObject> objects::Cone::clone() const
{
    return std::make_unique<objects::Cone>(*this);
}

extern "C" {
    /// @brief Creates a new primitive object of type Cone.
    /// This function is used as a factory for creating Cone instances.
    /// @return A unique pointer to a newly created Cone object.
    std::unique_ptr<objects::IObject> objects::createPrimitive(void)
    {
        return std::make_unique<objects::Cone>();
    }
}
