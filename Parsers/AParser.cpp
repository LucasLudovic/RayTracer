//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// AParser.cpp
//

#include "AParser.hpp"

raytracer::AParser::AParser(const std::string &filename)
{
    this->_ifs.open(filename);

    if (!this->_ifs.is_open())
        throw ParserError("Open Failed");
}

raytracer::AParser::~AParser()
{
    if (this->_ifs.is_open()) {
        this->_ifs.close();
    }
}
