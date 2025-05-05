//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// AParser.hpp
//

#pragma once

#include "BasicObject/basicObject.hpp"
#include "IObject.hpp"
#include "IParser.hpp"
#include <algorithm>
#include <fstream>
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
        AParser(const std::string &filename) : _filename(filename) {};
        ~AParser() override = default;

        void retrievePrimitives() override = 0;

        const std::vector<objects::BasicObject> &getPrimitives() const override
        {
            return this->_Primitives;
        };

        std::unique_ptr<objects::BasicObject> getCamera() override
        {
            return std::move(this->_Camera);
        };

       protected:
        std::string _filename;
        std::vector<objects::BasicObject> _Primitives;
        std::unique_ptr<objects::BasicObject> _Camera;
    };
}  // namespace raytracer
