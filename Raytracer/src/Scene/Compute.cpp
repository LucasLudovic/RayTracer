//
// EPITECH PROJECT, 2025
// Compute
// File description:
// Compute
//

#include "Scene.hpp"
#include "src/Raycast/Raycast.hpp"
#include <cmath>

bool raytracer::Scene::_checkInShadow(
    const raytracer::Raycast &shadowRay, double lightDist) const
{
    for (const auto &obj : this->_composition) {
        objects::hitResult_t shadowHit;
        if (obj->hit(shadowRay, shadowHit) && shadowHit.t < lightDist) {
            return true;
        }
    }
    return false;
}

double raytracer::Scene::_computeDiffuseLighting(
    const objects::hitResult_t &hit,
    const raytracer::Vector3<double> &normal) const
{
    double diffuseIntensity = 0.0;

    for (const auto &lightPosInt : this->_lights->getPoint()) {
        raytracer::Vector3<double> lightPos(
            lightPosInt.getX(), lightPosInt.getY(), lightPosInt.getZ());

        raytracer::Vector3<double> lightVector = lightPos - hit.position;
        double lightDist = std::sqrt(lightVector.dot(lightVector));
        lightVector = lightVector * (1.0 / lightDist);

        raytracer::Raycast shadowRay(hit.position + normal, lightVector);

        bool isInShadow = this->_checkInShadow(shadowRay, lightDist);

        if (!isInShadow) {
            double diff = std::max(0.0, normal.dot(lightVector));
            diffuseIntensity += this->_lights->getDiffuse() * diff;
        }
    }

    return diffuseIntensity;
}

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

    intensity += this->_computeDiffuseLighting(hit, normal);
    intensity = std::min(intensity, 1.0);

    return raytracer::Vector3<double>(
        hit.material.get_color().getX() * intensity,
        hit.material.get_color().getY() * intensity,
        hit.material.get_color().getZ() * intensity);
}
