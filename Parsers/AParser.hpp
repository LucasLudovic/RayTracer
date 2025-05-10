//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// AParser.hpp
//

#pragma once

#include "IObject.hpp"
#include "IParser.hpp"
#include "basicObject.hpp"
#include <memory>
#include <string>

namespace raytracer {
    class AParser : public IParser {
       public:
        ~AParser() override = default;

        void setFilename(const std::string &filename) override
        {
            this->_filename = filename;
        };

        void retrieveObjects() override = 0;

        void _setAvailableObject(
            std::vector<std::unique_ptr<objects::IObject>> availableObjects)
            override
        {
            this->_availableObjects = std::move(availableObjects);
        };

        std::vector<std::unique_ptr<BasicObject>> getPrimitives() override
        {
            return std::move(this->_Primitives);
        };

        std::unique_ptr<BasicObject> getCamera() override
        {
            std::unique_ptr NewCam = std::move(this->_Camera);
            this->_Camera = nullptr;
            return NewCam;
        };

        std::unique_ptr<BasicObject> getLights() override
        {
            std::unique_ptr newLights = std::move(this->_Lights);
            this->_Lights = nullptr;
            return newLights;
        }

       protected:
        std::string _filename = "empty";
        std::vector<std::unique_ptr<raytracer::BasicObject>> _Primitives;
        std::vector<std::unique_ptr<objects::IObject>> _availableObjects;
        std::unique_ptr<BasicObject> _Camera;
        std::unique_ptr<BasicObject> _Lights;
    };
}  // namespace raytracer
