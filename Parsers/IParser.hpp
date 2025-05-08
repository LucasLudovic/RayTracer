//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Parser.hpp
//

#pragma once

#include "IObject.hpp"
#include <memory>
#include <vector>

namespace raytracer {
    class IParser {
       public:
        virtual ~IParser() = default;

        virtual void setFilename(const std::string &filename) = 0;
        virtual void retrieveObjects() = 0;
        virtual std::vector<std::unique_ptr<objects::IObject>>
        getPrimitives() = 0;
        virtual std::unique_ptr<objects::IObject> getCamera() = 0;
    };
}  // namespace raytracer

extern "C" std::unique_ptr<raytracer::IParser> createParser(void);
