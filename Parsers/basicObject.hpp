//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// basicObject
//

#pragma once

#include <string>
#include <vector>

#include "../Primitives/Material.hpp"
#include "../Utils/Vector.hpp"

namespace raytracer {
class BasicObject
{
   public:
    BasicObject() : _material() {};
    ~BasicObject() {};

    void setPosition(raytracer::Vector3<int> pos)
    {
        this->_position = pos;
    };

    [[nodiscard]] raytracer::Vector3<int> getPosition() const
    {
        return this->_position;
    };

    void setColor(raytracer::Vector3<double> rgb)
    {
        this->_material.set_color(rgb);
    }

    void setColor(double r, double g, double b)
    {
        this->_material.set_color(r, g, b);
    }

    raytracer::Vector3<double> getColor() const
    {
        return this->_material.get_color();
    }

    void setTransparence(double value)
    {
        this->_material.set_transparence(value);
    }

    double getTransparence() const
    {
        return this->_material.get_transparence();
    }

    void setReflection(double value)
    {
        this->_material.set_reflection(value);
    }

    double getReflection() const
    {
        return this->_material.get_reflection();
    }

    std::string getType() const
    {
        return this->_type;
    };

    void setType(const std::string &type)
    {
        this->_type = type;
    };

    void setResolution(raytracer::Vector2<int> res)
    {
        this->_res = res;
    }

    raytracer::Vector2<int> getResolution() const
    {
        return this->_res;
    }

    void setRotation(raytracer::Vector3<int> rotation)
    {
        this->_rotation = rotation;
    }

    raytracer::Vector3<int> getRotation() const
    {
        return this->_rotation;
    }

    void setFieldOfView(double value)
    {
        this->_fieldOfView = value;
    }

    double getFieldOfView() const
    {
        return this->_fieldOfView;
    }

    double getAmbient() const
    {
        return this->_ambient;
    }

    double getDiffuse() const
    {
        return this->_diffuse;
    }

    std::vector<raytracer::Vector3<int>> getPoint() const
    {
        return this->_point;
    }

    void setAmbient(double ambient)
    {
        this->_ambient = ambient;
    }

    void setDiffuse(double diffuse)
    {
        this->_diffuse = diffuse;
    }

    void setPoint(const std::vector<raytracer::Vector3<int>> &newPoint)
    {
        this->_point = newPoint;
    }

    void setRadius(int radius)
    {
        this->_radius = radius;
    }

    int getRadius()
    {
        return this->_radius;
    };
    void setNormal(raytracer::Vector3<double> normal)
    {
        this->_normal = normal;
    }

    const raytracer::Vector3<double> &getNormal()
    {
        return this->_normal;
    };

   private:
    std::string _type = "";
    raytracer::Vector3<int> _position = {0, 0, 0};
    objects::Material _material;
    raytracer::Vector2<int> _res = {0, 0};
    raytracer::Vector3<int> _rotation = {0, 0, 0};
    double _fieldOfView = 0;
    double _ambient = 0;
    double _diffuse = 0;
    std::vector<raytracer::Vector3<int>> _point;
    int _radius = 0;
    raytracer::Vector3<double> _normal = {0, 0, 1};
};
}  // namespace raytracer
