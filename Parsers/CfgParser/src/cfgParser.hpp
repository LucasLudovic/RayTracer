//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.hpp
//

#pragma once

#include "AParser.hpp"
#include <libconfig.h++>

namespace raytracer {
    class cfgParser : public AParser {
       public:
        void retrieveObjects() override;

       private:
        libconfig::Config _cfg;

        void _retrievePrimitives(const libconfig::Setting &root);
        void _retrieveCamera(const libconfig::Setting &root);
        void _retrievePlane(const libconfig::Setting &primitives);
        void _retrieveSphere(const libconfig::Setting &primitives);
    };
}  // namespace raytracer
