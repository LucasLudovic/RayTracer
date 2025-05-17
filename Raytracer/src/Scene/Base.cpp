//
// EPITECH PROJECT, 2025
// Scene
// File description:
// Scene
//

#include "IObject.hpp"
#include "IParser.hpp"
#include "Scene.hpp"
#include "basicObject.hpp"
#include "src/DlLib/DlLib.hpp"
#include "src/Modules/Camera/src/Camera.hpp"
#include "src/Modules/Lights/src/Lights.hpp"
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

raytracer::Scene::~Scene()
{
    for (auto &it : this->_composition) {
        it.reset();
    }
    _camera.reset();
    _lights.reset();
    for (auto &it : this->_availableObjects) {
        it.reset();
    }
}

void raytracer::Scene::_createPlane(std::unique_ptr<BasicObject> Plane)
{
    for (const auto &it : this->_availableObjects) {
        if (it->getType() == "Plane") {
            auto newPlane = it->clone();
            newPlane->setPosition(Plane->getPosition());
            newPlane->setColor(Plane->getColor());
            newPlane->getMetaData().normal = Plane->getNormal();
            this->_composition.push_back(std::move(newPlane));
        }
    }
}

void raytracer::Scene::_createSphere(std::unique_ptr<BasicObject> Sphere)
{
    for (const auto &it : this->_availableObjects) {
        if (it->getType() == "Sphere") {
            auto newSphere = it->clone();
            newSphere->setPosition(Sphere->getPosition());
            newSphere->setColor(Sphere->getColor());
            newSphere->getMetaData().radius = Sphere->getRadius();
            this->_composition.push_back(std::move(newSphere));
        }
    }
}

void raytracer::Scene::_createCylinder(std::unique_ptr<BasicObject> Cylinder)
{
    for (const auto &it : this->_availableObjects) {
        if (it->getType() == "Cylinder") {
            auto newCylinder = it->clone();
            newCylinder->setPosition(Cylinder->getPosition());
            newCylinder->setColor(Cylinder->getColor());
            newCylinder->getMetaData().radius = Cylinder->getRadius();
            newCylinder->getMetaData().height = Cylinder->getHeight();
            newCylinder->getMetaData().direction = Cylinder->getDirection();
            this->_composition.push_back(std::move(newCylinder));
        }
    }
}

void raytracer::Scene::_createCone(std::unique_ptr<BasicObject> Cone)
{
    for (const auto &it : this->_availableObjects) {
        if (it->getType() == "Cone") {
            auto newCone = it->clone();
            newCone->setPosition(Cone->getPosition());
            newCone->setColor(Cone->getColor());
            newCone->getMetaData().radius = Cone->getRadius();
            newCone->getMetaData().height = Cone->getHeight();
            newCone->getMetaData().angle = Cone->getAngle();
            newCone->getMetaData().direction = Cone->getDirection();
            this->_composition.push_back(std::move(newCone));
        }
    }
}

void raytracer::Scene::_createCamera(std::unique_ptr<BasicObject> Camera)
{
    objects::Camera newCamera;

    newCamera.setResolution(Camera->getResolution());
    newCamera.setPosition(Camera->getPosition());
    newCamera.setRotation(Camera->getRotation());
    newCamera.setFieldOfView(Camera->getFieldOfView());
    this->_camera = std::make_unique<objects::Camera>(newCamera);
}

void raytracer::Scene::_createLights(std::unique_ptr<BasicObject> Lights)
{
    objects::Lights newLights;

    newLights.setAmbient(Lights->getAmbient());
    newLights.setDiffuse(Lights->getDiffuse());
    newLights.setPoint(Lights->getPoint());
    this->_lights = std::make_unique<objects::Lights>(newLights);
}

void raytracer::Scene::_setObjects(
    std::vector<std::unique_ptr<BasicObject>> Primitives)
{
    int i = 0;

    for (auto &it : Primitives) {
        i += 1;
        if (it->getType() == "Plane") {
            this->_createPlane(std::move(it));
            continue;
        }
        if (it->getType() == "Sphere") {
            this->_createSphere(std::move(it));
            continue;
        }
        if (it->getType() == "Cylinder") {
            this->_createCylinder(std::move(it));
            continue;
        }
        if (it->getType() == "Cone") {
            this->_createCone(std::move(it));
            continue;
        }
    }
}

void raytracer::Scene::load(const std::string &scene)
{
    Utils::DlLib<IParser> parserLib("lib/parsers/raytracer_cfg_parser.so");
    std::unique_ptr<IParser> parser = parserLib.loadLib("createParser");

    parser->setFilename(scene);

    try {
        parser->retrieveObjects();
    } catch (const ParserError &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    } catch (const std::exception &e) {
        std::cerr << "Error retrieveObjects : " << e.what() << std::endl;
        exit(-1);
    } catch (...) {
        std::cerr << "Erreur inconnue lors de retrieveObjects" << std::endl;
        exit(-1);
    }

    this->_getAvailableObject();

    this->_setObjects(parser->getPrimitives());
    this->_createCamera(parser->getCamera());
    this->_createLights(parser->getLights());
}

void raytracer::Scene::_getAvailableObject()
{
    for (const auto &elem :
        std::filesystem::directory_iterator("./lib/primitives")) {
        if (elem.path().extension() != ".so")
            continue;
        try {
            auto objectLib = std::make_unique<Utils::DlLib<objects::IObject>>(
                elem.path().string());

            auto object = objectLib->loadLib("createPrimitive");
            this->_availableObjects.push_back(std::move(object));
            this->_objectsLib.push_back(std::move(objectLib));
        } catch (const Utils::DlLibError &error) {
            continue;
        }
    }
    if (this->_availableObjects.empty()) {
        throw SceneError("No object available for scene");
    }
}
