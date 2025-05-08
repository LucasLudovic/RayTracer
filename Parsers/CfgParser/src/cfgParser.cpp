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
    if (!primitives.exists("planes"))
        return;
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

        double r, g, b;
        if (!color.lookupValue("r", r) || !color.lookupValue("g", g) || !color.lookupValue("b", b))
            throw ParserError("Missing 'r', 'g' or 'b' in plane color");
        NewPrimitive.setColor(Vector3(r, g, b));
        this->_Primitives.push_back(
            std::make_unique<objects::Plane>(NewPrimitive));
    }
}

void raytracer::cfgParser::_retrieveSphere(const libconfig::Setting &primitives)
{
    if (!primitives.exists("spheres"))
        return;
    const libconfig::Setting &spheres = primitives["spheres"];

    for (const auto &it : spheres) {

        if (!it.isArray() && !it.isList())
            throw ParserError("Primitive must be an array");
        objects::Sphere NewPrimitive;

        double x, y, z;
        if (!it.lookupValue("x", x) || !it.lookupValue("y", y) ||
            !it.lookupValue("z", z))
            throw ParserError("Missing 'x', 'y' or 'z' in sphere position");
        NewPrimitive.setPosition(Vector3(x, y, z));
        const libconfig::Setting &color = it["color"];

        double r, g, b;
        if (!color.lookupValue("r", r) || !color.lookupValue("g", g) ||
            !color.lookupValue("b", b))
            throw ParserError("Missing 'r', 'g' or 'b' in sphere color");
        NewPrimitive.setColor(Vector3(r, g, b));
        this->_Primitives.push_back(
            std::make_unique<objects::Sphere>(NewPrimitive));
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

raytracer::Vector3<double> raytracer::cfgParser::_retrieveCameraPosition(
    const libconfig::Setting &camera)
{
    if (!camera.exists("position"))
        throw ParserError("Missing 'position' in camera configuration");
    const libconfig::Setting &position = camera["position"];

    double x, y, z;
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

    if (!camera.isArray() && !camera.isList())
        throw ParserError("Camera must be an array");
    objects::Camera NewCamera;
    NewCamera.setPosition(this->_retrieveCameraPosition(camera));
    NewCamera.setResolution(this->_retrieveCameraResolution(camera));
    NewCamera.setRotation(this->_retrieveCameraRotation(camera));
    int fieldOfView = 0;
    if (!camera.lookupValue("fieldOfView", fieldOfView))
        throw ParserError("No field of view for camera");
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
std::unique_ptr<raytracer::IParser> createParser()
{
    return std::make_unique<raytracer::cfgParser>();
}
}
