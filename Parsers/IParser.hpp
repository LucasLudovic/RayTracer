//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Parser.hpp
//

#pragma once

#include <memory>
#include <vector>
#include "IObject.hpp"

namespace raytracer {
    class IParser {
       public:
        virtual ~IParser() = default;

        virtual void setFilename(const std::string &filename) = 0;
        virtual void retrieveObjects() = 0;
        const virtual std::vector<std::unique_ptr<objects::IObject>> &getPrimitives() const = 0;
        virtual std::unique_ptr<objects::IObject> getCamera() = 0;
    };
}  // namespace raytracer

extern "C" std::unique_ptr<raytracer::IParser> getObject();
