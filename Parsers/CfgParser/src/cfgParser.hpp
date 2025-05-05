//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.hpp
//

#pragma once

#include "AParser.hpp"
#include "BasicObject/basicObject.hpp"
#include <libconfig.h++>

namespace raytracer {
    class cfgParser : public AParser {
       public:
        void retrievePrimitives() override;
        std::unique_ptr<objects::BasicObject> getCamera() override;
        const std::vector<std::unique_ptr<objects::BasicObject>> &getPrimitives() const override;

       private:
        libconfig::Config _cfg;
    };
}  // namespace raytracer
