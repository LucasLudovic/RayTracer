//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "cylinder.hpp"

objects::Cylinder::Cylinder() : AObject() {}

std::unique_ptr<objects::IObject> objects::Cylinder::clone() const
{
    return std::make_unique<objects::Cylinder>(*this);
}

extern "C"
{
    std::unique_ptr<objects::IObject> objects::createPrimitive(void)
    {
        return std::make_unique<objects::Cylinder>();
    }
}
