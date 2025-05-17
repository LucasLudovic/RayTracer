//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "cone.hpp"

objects::Cone::Cone() : AObject() {}

std::unique_ptr<objects::IObject> objects::Cone::clone() const
{
    return std::make_unique<objects::Cone>(*this);
}

extern "C"
{
    std::unique_ptr<objects::IObject> objects::createPrimitive(void)
    {
        return std::make_unique<objects::Cone>();
    }
}
