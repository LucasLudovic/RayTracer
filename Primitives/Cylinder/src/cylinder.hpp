//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// cylinder.hpp
//

#pragma once

#include "AObject.hpp"

namespace objects {
    class Cylinder : public AObject {
       public:
        Cylinder();

        std::unique_ptr<IObject> clone() const override;

        std::string getType() const override { return "Cylinder"; };
        bool hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const override;

       private:
    };
}  // namespace objects
