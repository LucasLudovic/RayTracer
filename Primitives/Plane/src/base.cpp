//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "plane.hpp"

objects::Plane::Plane() : AObject() {}

std::unique_ptr<objects::IObject> objects::Plane::clone() const
{
    return std::make_unique<objects::Plane>(*this);
}

bool objects::Plane::hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const {return false;}
