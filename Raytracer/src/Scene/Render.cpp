//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render
//

#include "IRenderer.hpp"
#include "src/Raycast/Raycast.hpp"
#include "src/Scene/Scene.hpp"
#include <cstdlib>
#include <iostream>

void raytracer::Scene::renderScene(renderer::IRenderer &renderer)
{
    if (!this->_camera)
        throw SceneError("No camera in scene");

    auto cameraPos = this->_camera->getPosition();

    renderer.clear();

    for (auto &it : this->_composition) {
        std::cout << it->getType() << std::endl;
        if (it->getType() == "Plane")
            continue;
        Vector3<double> cameraPosDouble(static_cast<double>(cameraPos.getX()),
            static_cast<double>(cameraPos.getY()),
            static_cast<double>(cameraPos.getZ()));

        Vector3 objectPos = it->getPosition() - cameraPos;

        Vector3<double> objectPosDouble(static_cast<double>(objectPos.getX()),
            static_cast<double>(objectPos.getY()),
            static_cast<double>(objectPos.getZ()));

        raytracer::Raycast ray(cameraPosDouble, objectPosDouble);

        objects::hitResult_t hit;

        if (it->hit(ray, hit)) {
            Vector3<double> illuminatedColor = this->_computeLighting(hit);

            Vector3<int> finalColor(static_cast<int>(illuminatedColor.getX()),
                static_cast<int>(illuminatedColor.getY()),
                static_cast<int>(illuminatedColor.getZ()));

            renderer.drawObject(*it, finalColor);
            std::cout << it->getColor() << std::endl;
            std::cout << finalColor << std::endl;
        }
    }

    renderer.render();
}

raytracer::Vector3<int> raytracer::Scene::_computeRelativePos(
    const objects::IObject &object)
{
    Vector3<int> cameraPos = this->_camera->getPosition();
    Vector3<int> objectPos = object.getPosition();

    return objectPos - cameraPos;
}
