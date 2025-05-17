//
// EPITECH PROJECT, 2025
// Compute
// File description:
// Compute the sphere ray
//

#include "../Raytracer/src/Raycast/Raycast.hpp"
#include "IObject.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include <cmath>

bool objects::Sphere::hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const
{
    raytracer::Vector3<double> center(
        this->_position.getX(),
        this->_position.getY(),
        this->_position.getZ());

    raytracer::Vector3<double> oc = ray.getOrigin() - center;

    double a = ray.getDirection().dot(ray.getDirection());
    double b = 2.0 * ray.getDirection().dot(oc);
    double c = oc.dot(oc) - this->_metaData.radius.value() * this->_metaData.radius.value();
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0.0) {
        return false;
    }

    double sqrt_disc = std::sqrt(discriminant);
    double t1 = (-b - sqrt_disc) / (2.0 * a);
    double t2 = (-b + sqrt_disc) / (2.0 * a);

    double t = (t1 >= 0.001) ? t1 : ((t2 >= 0.001) ? t2 : -1.0);
    if (t < 0)
        return false;

    result.hit = true;
    result.t = t;
    result.position = ray.at(t);

    raytracer::Vector3<double> normal = result.position - center;
    double length = std::sqrt(normal.dot(normal));
    result.normal = normal * (1.0 / length);

    result.material.set_color(this->getColor());
    result.material.set_reflection(this->getReflection());
    return true;
}
