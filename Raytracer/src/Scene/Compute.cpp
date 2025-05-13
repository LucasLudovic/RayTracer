//
// EPITECH PROJECT, 2025
// Compute
// File description:
// Compute
//

#include <cmath>
#include "Scene.hpp"

raytracer::Vector3<double> raytracer::Scene::_computeLighting(
    const objects::hitResult_t &hit)
{
    if (!this->_lights || !this->_camera)
        return raytracer::Vector3<double>(0, 0, 0);

    double intensity = this->_lights->getAmbient();

    raytracer::Vector3<double> normal = hit.normal;
    normal = normal * (1.0 / std::sqrt(normal.dot(normal)));

    raytracer::Vector3<double> cameraPos(this->_camera->getPosition().getX(),
        this->_camera->getPosition().getY(),
        this->_camera->getPosition().getZ());

    raytracer::Vector3<double> cameraVector = cameraPos - hit.position;

    for (const auto &lightPosInt : this->_lights->getPoint()) {
        raytracer::Vector3<double> lightPos(
            lightPosInt.getX(), lightPosInt.getY(), lightPosInt.getZ());

        raytracer::Vector3<double> lightVector = lightPos - hit.position;
        lightVector = lightVector * (1.0 / std::sqrt(lightVector.dot(lightVector)));

        double diff = std::max(0.0, normal.dot(lightVector));
        intensity += this->_lights->getDiffuse() * diff;
    }

    intensity = std::min(intensity, 1.0);

    return raytracer::Vector3<double>(hit.color.getX() * intensity,
        hit.color.getY() * intensity, hit.color.getZ() * intensity);
}
