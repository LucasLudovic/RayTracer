//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Parser.hpp
//

#pragma once

#include <memory>
#include <vector>
#include "BasicObject/basicObject.hpp"
#include "IObject.hpp"

namespace raytracer {
    class IParser {
       public:
        virtual ~IParser() = default;

        virtual void retrievePrimitives() = 0;
        const virtual std::vector<std::unique_ptr<objects::BasicObject>> &getPrimitives() const = 0;
        virtual std::unique_ptr<objects::BasicObject> getCamera() = 0;
    };
}  // namespace raytracer
