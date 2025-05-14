//
// EPITECH PROJECT, 2025
// Render
// File description:
// Render
//

#include "IRenderer.hpp"
#include "src/Raycast/Raycast.hpp"
#include "src/Scene/Scene.hpp"
#include <cmath>
#include <iostream>

void raytracer::Scene::renderScene(renderer::IRenderer &renderer)
{
    if (!this->_camera)
        throw SceneError("No camera in scene");

    const auto resX = this->_camera->getResolution().getX();
    const auto resY = this->_camera->getResolution().getY();
    const auto fov = this->_camera->getFieldOfView();
    const auto cameraPos = this->_camera->getPosition();

    const double aspectRatio = static_cast<double>(resX) / resY;
    const double scaleY = std::tan((fov * M_PI / 180.0) / 2);
    const double scaleX = scaleY * aspectRatio;

    for (int y = 0; y < resY; y += 1) {
        for (int x = 0; x < resX; x += 1) {
            double px = (2 * (x + 0.5) / resX - 1) * scaleX;
            double py = (1 - 2 * (y + 0.5) / resY) * scaleY;
            raytracer::Vector3<double> rayDir(px, py, -1);
            rayDir = rayDir * (1.0 / std::sqrt(rayDir.dot(rayDir)));

            raytracer::Vector3<double> rayOrigin(
                static_cast<double>(cameraPos.getX()),
                static_cast<double>(cameraPos.getY()),
                static_cast<double>(cameraPos.getZ()));

            raytracer::Raycast ray(rayOrigin, rayDir);

            objects::hitResult_t closestHit;
            closestHit.t = std::numeric_limits<double>::max();
            bool hitFound = false;
            objects::IObject *hitObject = nullptr;

            for (auto &it : this->_composition) {

                objects::hitResult_t hit;
                if (it->hit(ray, hit) && hit.t < closestHit.t) {
                    closestHit = hit;
                    hitObject = it.get();
                    hitFound = true;
                }
            }

            if (hitFound && hitObject) {
                // std::cout << "Hit: " << x << " " << y << std::endl;
                raytracer::Vector3<double> litColor =
                    this->_computeLighting(closestHit);

                // std::cout << "Original: " <<  litColor << std::endl;
                raytracer::Vector3<int> finalColor(
                    static_cast<int>(litColor.getX()),
                    static_cast<int>(litColor.getY()),
                    static_cast<int>(litColor.getZ()));
                // std::cout << "Final: " << finalColor << std::endl;

                renderer.drawPixel({x, y}, finalColor);
            } else {
                renderer.drawPixel({x, y}, Vector3<int>(0, 0, 0));
            }
        }
    }
    renderer.render();
    std::cout << "enfin fini" << std::endl;
}

raytracer::Vector3<int> raytracer::Scene::_computeRelativePos(
    const objects::IObject &object)
{
    Vector3<int> cameraPos = this->_camera->getPosition();
    Vector3<int> objectPos = object.getPosition();

    return objectPos - cameraPos;
}
