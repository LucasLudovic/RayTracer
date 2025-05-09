//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// AParser.hpp
//

#pragma once

#include "IObject.hpp"
#include "IParser.hpp"
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

        std::vector<std::unique_ptr<objects::IObject>> getPrimitives() override
        {
            return std::move(this->_Primitives);
        };

        std::unique_ptr<objects::IObject> getCamera() override
        {
            std::unique_ptr NewCam = std::move(this->_Camera);
            this->_Camera = nullptr;
            return NewCam;
        };

       protected:
        std::string _filename = "empty";
        std::vector<std::unique_ptr<objects::IObject>> _Primitives;
        std::vector<std::unique_ptr<objects::IObject>> _availableObjects;
        std::unique_ptr<objects::IObject> _Camera = nullptr;
    };
}  // namespace raytracer
