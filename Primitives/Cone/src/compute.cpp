#include "../Raytracer/src/Raycast/Raycast.hpp"
#include "cone.hpp"
#include <cmath>

bool objects::Cone::hit(const raytracer::Raycast &ray, objects::hitResult_t &result) const
{
    if (!this->_metaData.direction.has_value() || 
        !this->_metaData.angle.has_value() || 
        !this->_metaData.height.has_value()) {
        return false;
    }

    const raytracer::Vector3<double> coneApex(
        this->_position.getX(), this->_position.getY(), this->_position.getZ());

    raytracer::Vector3<double> coneDir = this->_metaData.direction.value();
    coneDir = coneDir * (1.0 / std::sqrt(coneDir.dot(coneDir)));

    double angle = static_cast<double>(this->_metaData.angle.value()) * M_PI / 180.0;
    double height = static_cast<double>(this->_metaData.height.value());
    double cosAngle2 = std::cos(angle) * std::cos(angle);
    double tanAngle = std::tan(angle);
    double radius = height * tanAngle;
    const raytracer::Vector3<double> coneBase = coneApex + coneDir * height;

    const raytracer::Vector3<double> rayOrigin = ray.getOrigin();
    const raytracer::Vector3<double> rayDir = ray.getDirection();
    const raytracer::Vector3<double> v = rayOrigin - coneApex;

    double dotDirCone = rayDir.dot(coneDir);
    double dotVCone = v.dot(coneDir);

    double a = dotDirCone * dotDirCone - cosAngle2;
    double b = 2.0 * (dotDirCone * dotVCone - rayDir.dot(v) * cosAngle2);
    double c = dotVCone * dotVCone - v.dot(v) * cosAngle2;

    double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0 && std::abs(a) > 1e-6) {
        double sqrtD = std::sqrt(discriminant);
        double t1 = (-b - sqrtD) / (2.0 * a);
        double t2 = (-b + sqrtD) / (2.0 * a);

        if (t1 > t2)
            std::swap(t1, t2);

        for (double t : {t1, t2}) {
            if (t < 0.001)
                continue;

            raytracer::Vector3<double> hitPoint = ray.at(t);
            raytracer::Vector3<double> hitToApex = hitPoint - coneApex;
            double heightAtHit = hitToApex.dot(coneDir);

            if (heightAtHit < 0 || heightAtHit > height)
                continue;

            raytracer::Vector3<double> axisComponent = coneDir * heightAtHit;
            raytracer::Vector3<double> radialComponent = hitToApex - axisComponent;
            raytracer::Vector3<double> normal = radialComponent - coneDir * (std::sqrt(radialComponent.dot(radialComponent)) / tanAngle);
            normal = normal * (1.0 / std::sqrt(normal.dot(normal)));

            result.hit = true;
            result.t = t;
            result.position = hitPoint;
            result.normal = normal;
            result.material.set_color(this->getColor());
            return true;
        }
    }

    double denom = rayDir.dot(coneDir);
    if (std::abs(denom) > 1e-6) {
        double t_base = (coneBase - rayOrigin).dot(coneDir) / denom;
        if (t_base > 0.001) {
            raytracer::Vector3<double> p = ray.at(t_base);
            if ((p - coneBase).dot(p - coneBase) <= radius * radius) {
                result.hit = true;
                result.t = t_base;
                result.position = p;
                result.normal = coneDir;
                result.material.set_color(this->getColor());
                return true;
            }
        }
    }

    return false;
}
