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

       private:
    };
}  // namespace objects
