//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.cpp
//

#include "cfgParser.hpp"
#include "AParser.hpp"
#include "BasicObject/basicObject.hpp"
#include <cstddef>
#include <libconfig.h++>
#include <memory>

void raytracer::cfgParser::retrievePrimitives()
{
    this->_cfg.readFile(this->_filename.c_str());

    const libconfig::Setting &root = this->_cfg.getRoot();
    const libconfig::Setting &primitives = root["primitives"];
    this->_Primitives.clear();

    for (auto &it : primitives) {
        if (!it.isArray() || !it.isList())
            throw ParserError("Primitive must be an array");
        objects::BasicObject NewPrimitive;
        double x, y, z;
        it.lookupValue("x", x);
        it.lookupValue("y", y);
        it.lookupValue("z", z);
        NewPrimitive.setType(it.getName());
        NewPrimitive.setPosition(Vector3(x, y, z));
        this->_Primitives.push_back(std::make_unique<objects::BasicObject>(NewPrimitive));
    }
}
