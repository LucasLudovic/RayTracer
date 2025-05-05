//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// AParser.hpp
//

#pragma once

#include "IParser.hpp"
#include <fstream>

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
        AParser(const std::string &filename);
        ~AParser() override;

        void retrievePrimitives() const override = 0;

        std::vector<objects::IObject> getPrimitives() const override
        {
            return this->_Primitives;
        };

        objects::IObject getCamera() const override { return this->_Camera; };

       private:
        std::ifstream _ifs;
        std::vector<objects::IObject> _Primitives;
        objects::IObject _Camera;
    };
}  // namespace raytracer
