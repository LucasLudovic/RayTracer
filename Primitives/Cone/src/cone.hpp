//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// cone.hpp
//

#pragma once

#include "AObject.hpp"

namespace objects {
    class Cone : public AObject {
       public:
        Cone();

        std::unique_ptr<IObject> clone() const override;

        std::string getType() const override { return "Cone"; };
        bool hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const override;

       private:
    };
}  // namespace objects
