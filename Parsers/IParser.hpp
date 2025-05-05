//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Parser.hpp
//

#pragma once

#include <vector>
#include "IObject.hpp"

namespace raytracer {
    class IParser {
       public:
        virtual ~IParser() = default;

        virtual void retrievePrimitives() const = 0;
        virtual std::vector<objects::IObject> getPrimitives() const = 0;
        virtual objects::IObject getCamera() const = 0;
    };
}  // namespace raytracer
