//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// plane.hpp
//

#pragma once

#include "AObject.hpp"

namespace objects {
    class Plane : public AObject {
       public:
        Plane();

        class PlaneError : public AObjectError {};

        std::unique_ptr<IObject> clone() const override;

        std::string getType() const override { return "Plane"; };
        bool hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const override;

       private:
    };
}  // namespace objects

extern "C" {
std::unique_ptr<objects::IObject> objects::createPrimitive(void)
{
    return std::make_unique<objects::Plane>();
}
}
