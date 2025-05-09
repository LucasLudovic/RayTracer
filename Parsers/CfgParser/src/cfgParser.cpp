//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.cpp
//

#include "cfgParser.hpp"
#include "AParser.hpp"
#include "Camera/src/Camera.hpp"
#include "IParser.hpp"
#include "Plane/src/plane.hpp"
#include "Sphere/src/Sphere.hpp"
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

raytracer::Vector3<double> raytracer::cfgParser::_retrieveCameraPosition(const libconfig::Setting &camera)
{
    const libconfig::Setting &position = camera["position"];

    double x, y, z;
    position.lookupValue("x", x);
    position.lookupValue("y", y);
    position.lookupValue("z", z);
    return Vector3(x, y, z);
}

raytracer::Vector3<int> raytracer::cfgParser::_retrieveCameraRotation(const libconfig::Setting &camera)
{
    const libconfig::Setting &rotation = camera["rotation"];
    int x, y, z;
    rotation.lookupValue("x", x);
    rotation.lookupValue("y", y);
    rotation.lookupValue("z", z);
    return Vector3(x, y, z);
}

raytracer::Vector2<int> raytracer::cfgParser::_retrieveCameraResolution(const libconfig::Setting &camera)
{
    const libconfig::Setting &resolution = camera["resolution"];
    int x, y;
    resolution.lookupValue("width", x);
    resolution.lookupValue("height", y);
    return Vector2(x, y);
}

void raytracer::cfgParser::_retrieveCamera(const libconfig::Setting &root)
{
    const libconfig::Setting &camera = root["camera"];

    if (!camera.isArray() && !camera.isList())
        throw ParserError("Camera must be an array");
    objects::Camera NewCamera;
    NewCamera.setPosition(this->_retrieveCameraPosition(camera));
    NewCamera.setResolution(this->_retrieveCameraResolution(camera));
    NewCamera.setRotation(this->_retrieveCameraRotation(camera));
    int fieldOfView = 0;
    camera.lookupValue("fieldOfView", fieldOfView);
    NewCamera.setFieldOfVue(fieldOfView);
    this->_Camera = std::make_unique<objects::Camera>(NewCamera);
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
std::unique_ptr<raytracer::IParser> getObject()
{
    return std::make_unique<raytracer::cfgParser>();
}
}
