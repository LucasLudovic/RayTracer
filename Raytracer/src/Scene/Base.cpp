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

void raytracer::Scene::_createPlane(std::unique_ptr<BasicObject> Plane)
{
    for (const auto &it : this->_availableObjects) {
        if (it->getType() == "Plane") {
            auto newPlane = it->clone();
            newPlane->setPosition(Plane->getPosition());
            newPlane->setColor(Plane->getColor());
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
            this->_createPlane(std::move(it));
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

    auto object = this->_composition.begin();
    std::cout << "Type : " << object->get()->getType() << '\n';
    std::cout << "Position : x = " << object->get()->getPosition().getX()
              << ", y = " << object->get()->getPosition().getY()
              << ", z = " << object->get()->getPosition().getZ() << '\n';
    std::cout << "camera, Pos: x = " << this->_camera->getPosition().getX()
              << ", y = " << this->_camera->getPosition().getY()
              << ", z = " << this->_camera->getPosition().getZ() << "\n";
    std::cout << "camera resolution = " << this->_camera->getResolution().getX()
              << " and " << this->_camera->getResolution().getY() << "\n";
    std::cout << "camera view = " << this->_camera->getFieldOfView() << '\n';
    std::cout << "Lights point:\n";
    for (auto &it : this->_lights->getPoint()) {
        std::cout << "x = " << it.getX() << ", y = " << it.getY() << ", z = " << it.getZ() << "\n";
    }
    // auto camera = parser->getCamera();
    // for (auto &it : this->_composition) {
    //     std::cout << "Zebi" << std::endl;
    //     std::cout << it->getType() << std::endl;
    // }
    std::cout << "WAAAAA" << std::endl;
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
        std::cout << "Throwing" << std::endl;
        throw SceneError("No object available for scene");
    }
    std::cout << "Je suis là" << std::endl;
}
