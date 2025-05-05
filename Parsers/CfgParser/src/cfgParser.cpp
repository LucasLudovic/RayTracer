//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.cpp
//

#include "cfgParser.hpp"
#include "AParser.hpp"
#include "BasicObject/basicObject.hpp"
#include "IObject.hpp"
#include <algorithm>
#include <cstddef>
#include <libconfig.h++>

void raytracer::cfgParser::retrievePrimitives()
{
    this->_cfg.readFile(this->_filename.c_str());

    const libconfig::Setting &root = this->_cfg.getRoot();
    const libconfig::Setting &primitives = root["primitives"];
    this->_Primitives.clear();

    for (std::size_t i = 0; i < primitives.getLength(); i += 1) {
        if (!primitives[i].isArray() || !primitives.isList())
            throw ParserError("Primitive must be an array");
        objects::BasicObject NewPrimitive;
        double x, y, z;
        primitives[i].lookupValue("x", x);
        primitives[i].lookupValue("y", y);
        primitives[i].lookupValue("z", z);
        NewPrimitive.setType(primitives[i].getName());
        NewPrimitive.setPosition(Vector3(x, y, z));
        this->_Primitives.push_back(NewPrimitive);
    }
}

std::unique_ptr<objects::BasicObject> raytracer::cfgParser::getCamera()
{
    return std::move(this->_Camera);
}

const std::vector<objects::BasicObject> &raytracer::cfgParser::getPrimitives() const
{
    return this->_Primitives;
}
