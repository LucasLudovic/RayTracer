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
#include <filesystem>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>


void raytracer::Scene::_createPlane(std::unique_ptr<BasicObject> Plane)
{
    for (const auto &it : this->_availableObjects) {
        std::cout << "-------\n";
        std::cout << "Type Plane";
        std::cout << "-------\n";
        if (it->getType() == "Plane") {
            std::cout << "Plane Available\n";
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
            std::cout << "Sphere Available\n";
            auto newSphere = it->clone();
            newSphere->setPosition(Sphere->getPosition());
            newSphere->setColor(Sphere->getColor());
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
    newCamera.setFieldOfVue(Camera->getFieldOfView());
    this->_camera = std::make_unique<objects::Camera>(newCamera);
}

void raytracer::Scene::_setObjects(std::vector<std::unique_ptr<BasicObject>> Primitives)
{
    std::cout << "Dans getPrimitive\n";
    int i = 0;
    for (auto &it : Primitives) {
        std::cout << "PRIMITIVE number " << i << "\n";
        i += 1;
        if (it->getType() == "Plane") {
            std::cout << "Je vais dans le plane\n";
            this->_createPlane(std::move(it));
            std::cout << "Apres Plane\n";
            continue;
        }
        if (it->getType() == "Sphere") {
            std::cout << "Je vais dans la sphere\n";
            this->_createPlane(std::move(it));
            std::cout << "Apres sphere\n";
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
        exit (-1);
    } catch (const std::exception &e) {
        std::cerr << "Error retrieveObjects : " << e.what()
                  << std::endl;
        exit(-1);
    } catch (...) {
        std::cerr << "Erreur inconnue lors de retrieveObjects" << std::endl;
        exit(-1);
    }

    std::cout << "pas de seg ici\n";
    this->_getAvailableObject();
    std::cout << "pas de seg ici2\n";

    std::cout << "Avant getPrimitive\n";
    this->_setObjects(parser->getPrimitives());
    std::cout << "Apres getPrimitive\n";
    this->_createCamera(parser->getCamera());
    std::cout << "Apres getCamera\n";

    auto object = this->_composition.begin();
    std::cout << "Type : " << object->get()->getType() << '\n';
    std::cout << "Position : x = " << object->get()->getPosition().getX() << ", y = " << object->get()->getPosition().getY() << ", z = " << object->get()->getPosition().getZ() << '\n';
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
        std::filesystem::directory_iterator("./lib/objects")) {
        if (elem.path().extension() != ".so")
            continue;
        try {
            Utils::DlLib<objects::IObject> objectLib(elem.path().string());

            this->_objectsLib.push_back(objectLib);
            auto object = objectLib.loadLib("createPrimitive");
            this->_availableObjects.push_back(std::move(object));
        } catch (const Utils::DlLibError &error) {
            continue;
        }
    }

    if (this->_availableObjects.empty())
        throw SceneError("No object available for scene");
}
