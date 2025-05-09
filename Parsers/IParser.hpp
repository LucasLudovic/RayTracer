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
    class ParserError : public std::exception {
       public:
        ParserError(const std::string &msg) : _msg(msg) {};

        const char *what() const noexcept override
        {
            return this->_msg.c_str();
        };

       private:
        std::string _msg;
    };

    class IParser {
       public:
        virtual ~IParser() = default;

        virtual void setFilename(const std::string &filename) = 0;
        virtual void retrieveObjects() = 0;
        virtual void _setAvailableObject(
            std::vector<std::unique_ptr<objects::IObject>>
                availableObjects) = 0;
        virtual std::vector<std::unique_ptr<BasicObject>> getPrimitives() = 0;
        virtual std::unique_ptr<BasicObject> getCamera() = 0;
    };
}  // namespace raytracer

extern "C" std::unique_ptr<raytracer::IParser> createParser(void);
