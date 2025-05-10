//
// EPITECH PROJECT, 2025
// Sphere
// File description:
// Sphere
//

#pragma once

#include "AObject.hpp"

namespace objects {
    class Sphere : public AObject {
       public:
        Sphere();

        class SphereError : public AObjectError {};

        std::unique_ptr<IObject> clone() const override;

        std::string getType() const override { return "Sphere"; };

       private:
    };
}  // namespace objects
