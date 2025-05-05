//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.hpp
//

#pragma once

#include "AParser.hpp"

namespace raytracer {
    class cfgParser : public AParser {
       public:
        void retrievePrimitives() const override;
        objects::IObject getCamera() const override;
        std::vector<objects::IObject> getPrimitives() const override;
    };
}  // namespace raytracer
