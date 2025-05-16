//
// EPITECH PROJECT, 2025
// Compute
// File description:
// Compute hit for cylinder
//

#include "../Raytracer/src/Raycast/Raycast.hpp"
#include "cylinder.hpp"
#include <cmath>
#include <array>

bool objects::Cylinder::hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const
{
    if (!this->_metaData.radius.has_value() ||
        !this->_metaData.direction.has_value() ||
        !this->_metaData.height.has_value())
        return false;

    const double radius = static_cast<double>(this->_metaData.radius.value());
    const double height = static_cast<double>(this->_metaData.height.value());
    raytracer::Vector3<double> axis = this->_metaData.direction.value();
    axis = axis * (1.0 / std::sqrt(axis.dot(axis)));

    const raytracer::Vector3<double> base = {
        static_cast<double>(this->_position.getX()),
        static_cast<double>(this->_position.getY()),
        static_cast<double>(this->_position.getZ())
    };
    const raytracer::Vector3<double> top = base + axis * height;

    const raytracer::Vector3<double> ro = ray.getOrigin();
    const raytracer::Vector3<double> rd = ray.getDirection();

    const raytracer::Vector3<double> delta = ro - base;
    const raytracer::Vector3<double> d = rd - axis * rd.dot(axis);
    const raytracer::Vector3<double> m = delta - axis * delta.dot(axis);

    const double a = d.dot(d);
    const double b = 2.0 * d.dot(m);
    const double c = m.dot(m) - radius * radius;

    const double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0.0 && std::abs(a) > 1e-6) {
        const double sqrtD = std::sqrt(discriminant);
        double t0 = (-b - sqrtD) / (2 * a);
        double t1 = (-b + sqrtD) / (2 * a);

        if (t0 > t1)
            std::swap(t0, t1);

        for (double t : {t0, t1}) {
            if (t < 0.001)
                continue;

            raytracer::Vector3<double> p = ray.at(t);
            double proj = (p - base).dot(axis);

            if (proj < 0 || proj > height)
                continue;

            raytracer::Vector3<double> projection = base + axis * proj;
            raytracer::Vector3<double> normal = p - projection;
            normal = normal * (1.0 / std::sqrt(normal.dot(normal)));

            result.hit = true;
            result.t = t;
            result.position = p;
            result.normal = normal;
            result.material.set_color(this->getColor());
            return true;
        }
    }
    for (const auto& [center, normal] : std::array<std::pair<raytracer::Vector3<double>, raytracer::Vector3<double>>, 2>{
        std::make_pair(base, axis * -1.0),
        std::make_pair(top, axis)
    }) {
        double denom = rd.dot(normal);
        if (std::abs(denom) < 1e-6)
            continue;

        double t = (center - ro).dot(normal) / denom;
        if (t < 0.001)
            continue;

        raytracer::Vector3<double> p = ray.at(t);
        if ((p - center).dot(p - center) <= radius * radius) {
            result.hit = true;
            result.t = t;
            result.position = p;
            result.normal = normal;
            result.material.set_color(this->getColor());
            return true;
        }
    }
    return false;
}
