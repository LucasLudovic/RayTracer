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
#include <filesystem>
#include <iostream>
#include <ostream>


std::unique_ptr<objects::IObject> raytracer::Scene::_createPlane(std::unique_ptr<BasicObject> Plane)
{
    
}

std::unique_ptr<objects::IObject> raytracer::Scene::_createSphere(std::unique_ptr<BasicObject> Sphere)
{

}

std::unique_ptr<objects::IObject> raytracer::Scene::_createCamera(std::unique_ptr<BasicObject> Camera)
{

}

void raytracer::Scene::_setObjects(std::vector<std::unique_ptr<BasicObject>> Primitives)
{
    for (const auto &it : Primitives) {
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

    std::vector<std::unique_ptr<BasicObject>> Primitives = parser->getPrimitives();
    std::cout << "Type : " << Primitives.begin()->get()->getColor().getX() << std::endl;
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

            auto object = objectLib.loadLib("createObject");
            this->_availableObjects.push_back(std::move(object));
        } catch (const Utils::DlLibError &error) {
            continue;
        }
    }

    if (this->_availableObjects.empty())
        throw SceneError("No object available for scene");
}
