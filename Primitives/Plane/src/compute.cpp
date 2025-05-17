//
// EPITECH PROJECT, 2025
// Compute
// File description:
// Compute hit for plane
//

#include "../Raytracer/src/Raycast/Raycast.hpp"
#include "plane.hpp"
#include <iostream>

bool objects::Plane::hit(
    const raytracer::Raycast &ray, objects::hitResult_t &result) const
{
    if (!this->_metaData.normal.has_value()) {
        return false;
    }

    raytracer::Vector3<double> planePoint(this->_position.getX(),
        this->_position.getY(), this->_position.getZ());

    raytracer::Vector3<double> normal = this->_metaData.normal.value();
    raytracer::Vector3<double> rayOrigin = ray.getOrigin();
    raytracer::Vector3<double> rayDir = ray.getDirection();

    double denom = normal.dot(rayDir);
    if (std::abs(denom) < 1e-6) {
        return false;
    }

    double t = (planePoint - rayOrigin).dot(normal) / denom;
    if (t < 0.001) {
        return false;
    }

    result.hit = true;
    result.t = t;
    result.position = ray.at(t);
    result.normal = normal;
    result.material.set_color(this->getColor());
    result.material.set_reflection(this->getReflection());

    return true;
}
