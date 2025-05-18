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

    ///
    /// \class AParser
    /// \brief Abstract base class providing parsing functionality for raytracer objects.
    ///
    class AParser : public IParser {
       public:
        ///
        /// \brief Destructor.
        ///
        ~AParser() override = default;

        ///
        /// \brief Sets the filename to be parsed.
        /// \param filename The name of the file to parse.
        ///
        void setFilename(const std::string &filename) override
        {
            this->_filename = filename;
        };

        ///
        /// \brief Retrieves and parses objects from the file.
        ///
        virtual void retrieveObjects() override = 0;

        ///
        /// \brief Sets the list of available objects for parsing.
        /// \param availableObjects A vector containing unique pointers to available objects.
        ///
        void _setAvailableObject(
            std::vector<std::unique_ptr<objects::IObject>> availableObjects)
            override
        {
            this->_availableObjects = std::move(availableObjects);
        };

        ///
        /// \brief Retrieves the list of primitive objects.
        /// \return A vector of unique pointers to primitive objects.
        ///
        std::vector<std::unique_ptr<BasicObject>> getPrimitives() override
        {
            return std::move(this->_Primitives);
        };

        ///
        /// \brief Retrieves the camera object.
        /// \return A unique pointer to the camera object.
        ///
        std::unique_ptr<BasicObject> getCamera() override
        {
            std::unique_ptr NewCam = std::move(this->_Camera);
            this->_Camera = nullptr;
            return NewCam;
        };

        ///
        /// \brief Retrieves the light objects.
        /// \return A unique pointer to the light objects.
        ///
        std::unique_ptr<BasicObject> getLights() override
        {
            std::unique_ptr newLights = std::move(this->_Lights);
            this->_Lights = nullptr;
            return newLights;
        }

       protected:
        std::string _filename = "empty"; ///< The filename to be parsed.
        std::vector<std::unique_ptr<raytracer::BasicObject>> _Primitives; ///< List of primitive objects.
        std::vector<std::unique_ptr<objects::IObject>> _availableObjects; ///< List of available objects for parsing.
        std::unique_ptr<BasicObject> _Camera; ///< Unique pointer to camera object.
        std::unique_ptr<BasicObject> _Lights; ///< Unique pointer to light objects.
    };

}  // namespace raytracer
