//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render
//

#include "IRenderer.hpp"
#include "src/Scene/Scene.hpp"
#include <iostream>

void raytracer::Scene::renderScene(renderer::IRenderer &renderer)
{
    if (!this->_camera)
        throw SceneError("No camera in scene");
    std::cout << "Zebi" << std::endl;
    auto cameraPos = this->_camera->getPosition();

    renderer.clear();
    for (auto &it: this->_composition) {
        auto relativePos = this->_computeRelativePos(*it);
        auto previousPos = it->getPosition();
        it->setPosition(relativePos);
        renderer.drawObject(*it);
        it->setPosition(previousPos);
    }
    renderer.render();
}

raytracer::Vector3<int> raytracer::Scene::_computeRelativePos(const objects::IObject &object)
{
    Vector3<int> cameraPos = this->_camera->getPosition();
    Vector3<int> objectPos = object.getPosition();

    return objectPos - cameraPos;
}
