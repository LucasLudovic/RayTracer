//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.cpp
//

#include "cfgParser.hpp"
#include "IParser.hpp"
#include "basicObject.hpp"
#include <iostream>
#include <libconfig.h++>
#include <memory>
#include <vector>

void raytracer::cfgParser::_retrievePlane(const libconfig::Setting &primitives)
{
    if (!primitives.exists("planes"))
        return;
    const libconfig::Setting &plane = primitives["planes"];

    for (const auto &it : plane) {
        BasicObject NewPrimitive;

        NewPrimitive.setType("Plane");

        int x = 0;
        int y = 0;
        int z = 0;
        std::string axis;
        it.lookupValue("axis", axis);
        if (axis == "Z")
            if (!it.lookupValue("position", z))
                throw ParserError("Missing 'position' in plane");
        if (axis == "Y")
            if (!it.lookupValue("position", y))
                throw ParserError("Missing 'position' in plane");
        if (axis == "X")
            if (!it.lookupValue("position", x))
                throw ParserError("Missing 'position' in plane");

        NewPrimitive.setPosition(Vector3(x, y, z));

        if (!it.exists("color"))
            throw ParserError("Missing 'color' in plane configuration");
        const libconfig::Setting &color = it["color"];

        int r, g, b;
        if (!color.lookupValue("r", r) || !color.lookupValue("g", g) ||
            !color.lookupValue("b", b))
            throw ParserError("Missing 'r', 'g' or 'b' in plane color");
        NewPrimitive.setColor(Vector3(r, g, b));
        this->_Primitives.push_back(
            std::make_unique<BasicObject>(NewPrimitive));
    }
}

void raytracer::cfgParser::_retrieveSphere(const libconfig::Setting &primitives)
{
    if (!primitives.exists("spheres"))
        return;
    const libconfig::Setting &spheres = primitives["spheres"];

    for (const auto &it : spheres) {
        BasicObject NewPrimitive;

        NewPrimitive.setType("Sphere");
        int x, y, z, radius;
        if (!it.lookupValue("x", x) || !it.lookupValue("y", y) ||
            !it.lookupValue("z", z) || !it.lookupValue("r", radius))
            throw ParserError("Missing 'x', 'y' or 'z' in sphere position");
        NewPrimitive.setPosition(Vector3(x, y, z));
        NewPrimitive.setRadius(radius);
        const libconfig::Setting &color = it["color"];

        int r, g, b;
        if (!color.lookupValue("r", r) || !color.lookupValue("g", g) ||
            !color.lookupValue("b", b))
            throw ParserError("Missing 'r', 'g' or 'b' in sphere color");
        NewPrimitive.setColor(Vector3(r, g, b));
        this->_Primitives.push_back(
            std::make_unique<BasicObject>(NewPrimitive));
    }
}

void raytracer::cfgParser::_retrievePrimitives(const libconfig::Setting &root)
{
    if (!root.exists("primitives"))
        throw ParserError("Missing 'primitives' in root configuration");
    const libconfig::Setting &primitives = root["primitives"];

    this->_retrievePlane(primitives);
    this->_retrieveSphere(primitives);
}

raytracer::Vector3<int> raytracer::cfgParser::_retrieveCameraPosition(
    const libconfig::Setting &camera)
{
    if (!camera.exists("position"))
        throw ParserError("Missing 'position' in camera configuration");
    const libconfig::Setting &position = camera["position"];

    int x, y, z;
    position.lookupValue("x", x);
    position.lookupValue("y", y);
    position.lookupValue("z", z);
    return Vector3(x, y, z);
}

raytracer::Vector3<int> raytracer::cfgParser::_retrieveCameraRotation(
    const libconfig::Setting &camera)
{
    if (!camera.exists("rotation"))
        throw ParserError("Missing 'rotation' in camera configuration");
    const libconfig::Setting &rotation = camera["rotation"];

    int x, y, z;
    if (!rotation.lookupValue("x", x) || !rotation.lookupValue("y", y) ||
        !rotation.lookupValue("z", z))
        throw ParserError("Missing 'x', 'y' or 'z' in camera rotation");
    return Vector3(x, y, z);
}

raytracer::Vector2<int> raytracer::cfgParser::_retrieveCameraResolution(
    const libconfig::Setting &camera)
{
    if (!camera.exists("resolution"))
        throw ParserError("Missing 'rotation' in camera configuration");
    const libconfig::Setting &resolution = camera["resolution"];

    int x, y;
    if (!resolution.lookupValue("width", x) ||
        !resolution.lookupValue("height", y))
        throw ParserError("Missing 'width' or 'height' in camera resolution");
    return Vector2(x, y);
}

void raytracer::cfgParser::_retrieveCamera(const libconfig::Setting &root)
{
    if (!root.exists("camera"))
        throw ParserError("Missing 'camera' in root configuration");
    const libconfig::Setting &camera = root["camera"];

    BasicObject NewCamera;
    NewCamera.setType("Camera");
    NewCamera.setPosition(this->_retrieveCameraPosition(camera));
    NewCamera.setResolution(this->_retrieveCameraResolution(camera));
    NewCamera.setRotation(this->_retrieveCameraRotation(camera));
    double fieldOfView = 0;
    if (!camera.lookupValue("fieldOfView", fieldOfView))
        throw ParserError("No field of view for camera");
    NewCamera.setFieldOfView(fieldOfView);
    this->_Camera = std::make_unique<BasicObject>(NewCamera);
}

std::vector<raytracer::Vector3<int>> raytracer::cfgParser::_retrieveLightsPoint(
    const libconfig::Setting &lights)
{
    if (!lights.exists("point"))
        throw ParserError("Missing 'rotation' in camera configuration");
    const libconfig::Setting &point = lights["point"];

    std::vector<Vector3<int>> points;

    for (auto &it : point) {
        int x, y, z;
        if (!it.lookupValue("x", x) || !it.lookupValue("y", y) ||
            !it.lookupValue("z", z))
            throw ParserError("Missing 'x', 'y' or 'z' in Lights point");
        points.push_back(Vector3(x, y, z));
    }
    return points;
}

void raytracer::cfgParser::_retrieveLights(const libconfig::Setting &root)
{
    if (!root.exists("lights"))
        throw ParserError("Missing 'lights' in root configuration");
    const libconfig::Setting &lights = root["lights"];

    BasicObject newLights;
    newLights.setType("Lights");
    double diffuse = 0;
    double ambient = 0;
    if (!lights.lookupValue("ambient", ambient) ||
        !lights.lookupValue("diffuse", diffuse))
        throw ParserError(
            "Missing 'diffuse' or 'ambient' in Lighst configuration");
    newLights.setAmbient(ambient);
    newLights.setDiffuse(diffuse);
    newLights.setPoint(this->_retrieveLightsPoint(lights));
    this->_Lights = std::make_unique<BasicObject>(newLights);
}

void raytracer::cfgParser::retrieveObjects()
{
    try {
        this->_cfg.readFile(this->_filename.c_str());
    } catch (...) {
        throw ParserError("Failed to open filename");
    }
    this->_Primitives.clear();

    const libconfig::Setting &root = this->_cfg.getRoot();
    this->_retrievePrimitives(root);
    this->_retrieveCamera(root);
    this->_retrieveLights(root);
}

extern "C" {
std::unique_ptr<raytracer::IParser> createParser()
{
    return std::make_unique<raytracer::cfgParser>();
}
}
