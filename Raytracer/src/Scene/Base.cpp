//
// EPITECH PROJECT, 2025
// Scene
// File description:
// Scene
//

#include "IObject.hpp"
#include "IParser.hpp"
#include "Scene.hpp"
#include "src/DlLib/DlLib.hpp"
#include <filesystem>

void raytracer::Scene::load(const std::string &scene)
{
    Utils::DlLib<IParser> parserLib("lib/parsers/raytracer_cfg_parser.so");
    std::unique_ptr<IParser> parser = parserLib.loadLib();

    // à modifier, il faut que je stock dans this->_composition quand j'aurais un copy constructeur
    parser->getPrimitives();

    this->_camera = parser->getCamera();
}

void raytracer::Scene::_getAvailableObject()
{
    for (const auto &elem : std::filesystem::directory_iterator("./lib/objects")) {
        if (elem.path().extension() != ".so")
            continue;
        try {
            Utils::DlLib<objects::IObject> objectLib(elem.path().string());

            auto object = objectLib.loadLib();
            this->_availableObjects.push_back(std::move(object));
        } catch (const Utils::DlLibError &error) {
            continue;
        }
    }
    
    if (this->_availableObjects.empty())
        throw SceneError("No object available for scene");
}
