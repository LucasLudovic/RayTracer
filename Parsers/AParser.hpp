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

    class AParser : public IParser {
       public:
        ~AParser() override = default;

        void setFilename(const std::string &filename) override { this->_filename = filename; };

        void retrieveObjects() override = 0;

        const std::vector<std::unique_ptr<objects::IObject>> &getPrimitives() const override
        {
            return this->_Primitives;
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
        std::unique_ptr<objects::IObject> _Camera = nullptr;
    };
}  // namespace raytracer
