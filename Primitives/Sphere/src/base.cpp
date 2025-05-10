//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "IObject.hpp"
#include "Sphere.hpp"

objects::Sphere::Sphere(): AObject()
{
}

std::unique_ptr<objects::IObject> objects::Sphere::clone() const {
    return std::make_unique<objects::Sphere>(*this);
}
