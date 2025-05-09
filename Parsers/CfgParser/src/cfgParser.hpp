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
        cfgParser() {};
        void retrieveObjects() override;

       private:
        libconfig::Config _cfg;

        void _retrievePrimitives(const libconfig::Setting &root);
        void _retrievePlane(const libconfig::Setting &primitives);
        void _retrieveSphere(const libconfig::Setting &primitives);

        void _retrieveCamera(const libconfig::Setting &root);
        raytracer::Vector3<int> _retrieveCameraPosition(const libconfig::Setting &camera);
        raytracer::Vector3<int> _retrieveCameraRotation(const libconfig::Setting &camera);
        raytracer::Vector2<int> _retrieveCameraResolution(const libconfig::Setting &camera);
    };
}  // namespace raytracer
