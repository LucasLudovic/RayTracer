//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Parser.hpp
//

#pragma once

#include "IObject.hpp"
#include "basicObject.hpp"
#include <memory>
#include <vector>

namespace raytracer {

    ///
    /// \class ParserError
    /// \brief Exception class for parser-specific errors.
    ///
    class ParserError : public std::exception {
       public:
        ///
        /// \brief Constructs a ParserError with a specific message.
        /// \param msg The error message.
        ///
        ParserError(const std::string &msg) : _msg(msg) {};

        ///
        /// \brief Returns the error message.
        /// \return A C-style string containing the error message.
        ///
        const char *what() const noexcept override
        {
            return this->_msg.c_str();
        };

       private:
        std::string _msg; ///< The error message.
    };

    ///
    /// \class IParser
    /// \brief Abstract interface for all parser types in the raytracer project.
    ///
    class IParser {
       public:
        ///
        /// \brief Virtual destructor.
        ///
        virtual ~IParser() = default;

        ///
        /// \brief Sets the filename to be parsed.
        /// \param filename The name of the file.
        ///
        virtual void setFilename(const std::string &filename) = 0;

        ///
        /// \brief Parses and retrieves objects from the file.
        ///
        virtual void retrieveObjects() = 0;

        ///
        /// \brief Sets the available objects that can be parsed.
        /// \param availableObjects Vector of unique pointers to objects.
        ///
        virtual void _setAvailableObject(
            std::vector<std::unique_ptr<objects::IObject>> availableObjects) = 0;

        ///
        /// \brief Retrieves the parsed primitive objects.
        /// \return A vector of unique pointers to basic objects.
        ///
        virtual std::vector<std::unique_ptr<BasicObject>> getPrimitives() = 0;

        ///
        /// \brief Retrieves the parsed camera object.
        /// \return A unique pointer to the camera object.
        ///
        virtual std::unique_ptr<BasicObject> getCamera() = 0;

        ///
        /// \brief Retrieves the parsed light objects.
        /// \return A unique pointer to the light objects.
        ///
        virtual std::unique_ptr<BasicObject> getLights() = 0;
    };

}  // namespace raytracer

///
/// \brief Factory function to create a parser instance.
/// \return A unique pointer to a raytracer::IParser.
///
extern "C" std::unique_ptr<raytracer::IParser> createParser(void);
