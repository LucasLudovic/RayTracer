//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.cpp
//

#include "cfgParser.hpp"
#include "AParser.hpp"
#include "IParser.hpp"
#include "Plane/src/plane.hpp"
#include "Sphere/src/Sphere.hpp"
#include <algorithm>
#include <libconfig.h++>
#include <memory>

void raytracer::cfgParser::_retrievePlane(const libconfig::Setting &primitives)
{
    const libconfig::Setting &plane = primitives["planes"];

    for (const auto &it : plane) {
        if (!it.isArray() && !it.isList())
            throw ParserError("Primitive must be an array");
        objects::Plane NewPrimitive;
        double x = 0;
        double y = 0;
        double z = 0;
        std::string axis;
        it.lookupValue("axis", axis);
        if (axis == "Z")
            it.lookupValue("position", z);
        if (axis == "Y")
            it.lookupValue("position", y);
        if (axis == "X")
            it.lookupValue("position", x);
        NewPrimitive.setPosition(Vector3(x, y, z));
        const libconfig::Setting &color = it["color"];
        double r, g, b;
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        NewPrimitive.setColor(Vector3(r, g, b));
        this->_Primitives.push_back(std::make_unique<objects::Plane>(NewPrimitive));
    }
}

void raytracer::cfgParser::_retrieveSphere(const libconfig::Setting &primitives)
{
    const libconfig::Setting &spheres = primitives["spheres"];

    for (const auto &it : spheres) {
        if (!it.isArray() && !it.isList())
            throw ParserError("Primitive must be an array");
        objects::Sphere NewPrimitive;
        double x, y, z;
        it.lookupValue("x", x);
        it.lookupValue("y", y);
        it.lookupValue("z", z);
        NewPrimitive.setPosition(Vector3(x, y, z));
        const libconfig::Setting &color = it["color"];
        double r, g, b;
        color.lookupValue("r", r);
        color.lookupValue("g", g);
        color.lookupValue("b", b);
        NewPrimitive.setColor(Vector3(r, g, b));
        this->_Primitives.push_back(std::make_unique<objects::Sphere>(NewPrimitive));
    }
}

void raytracer::cfgParser::_retrievePrimitives(const libconfig::Setting &root)
{
    const libconfig::Setting &primitives = root["primitives"];

    this->_retrievePlane(primitives);
    this->_retrieveSphere(primitives);
}

void raytracer::cfgParser::_retrieveCamera(const libconfig::Setting &root)
{
    // const libconfig::Setting &camera = root["camera"];
    //
    // if (!camera.isArray() && !camera.isList())
    //     throw ParserError("Array must be an array");
    // const libconfig::Setting &position = camera["position"];
    // objects::BasicObject NewCamera;
    // double x, y, z;
    // position.lookupValue("x", x);
    // position.lookupValue("y", y);
    // position.lookupValue("z", z);
    // NewCamera.setType("camera");
    // NewCamera.setPosition(Vector3(x, y, z));
    // this->_Camera = std::make_unique<objects::BasicObject>(NewCamera);
}

void raytracer::cfgParser::retrieveObjects()
{
    this->_cfg.readFile(this->_filename.c_str());
    this->_Primitives.clear();

    const libconfig::Setting &root = this->_cfg.getRoot();
    this->_retrievePrimitives(root);
    this->_retrieveCamera(root);
}

extern "C" {
std::unique_ptr<raytracer::IParser> entrypoint_parser(const std::string &filename)
{
    return std::make_unique<raytracer::cfgParser>(filename);
}
}
