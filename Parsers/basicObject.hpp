//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// basicObject
//

#pragma once

#include "../Utils/Vector.hpp"
#include <string>
#include <vector>

namespace raytracer {
    class BasicObject {
       public:
        BasicObject() {};
        ~BasicObject() {};

        void setPosition(raytracer::Vector3<int> pos)
        {
            this->_position = pos;
        };

        [[nodiscard]] raytracer::Vector3<int> getPosition() const
        {
            return this->_position;
        };

        void setColor(raytracer::Vector3<int> rgb) { this->_color = rgb; };

        raytracer::Vector3<int> getColor() const { return this->_color; };

        std::string getType() const { return this->_type; };

        void setType(const std::string &type) { this->_type = type; };

        void setResolution(raytracer::Vector2<int> res) { this->_res = res; }

        raytracer::Vector2<int> getResolution() const { return this->_res; }

        void setRotation(raytracer::Vector3<int> rotation)
        {
            this->_rotation = rotation;
        }

        raytracer::Vector3<int> getRotation() const { return this->_rotation; }

        void setFieldOfView(double value) { this->_fieldOfView = value; }

        double getFieldOfView() const { return this->_fieldOfView; }

        double getAmbient() const { return this->_ambient; }

        double getDiffuse() const { return this->_diffuse; }

        std::vector<raytracer::Vector3<int>> getPoint() const
        {
            return this->_point;
        }

        void setAmbient(double ambient) { this->_ambient = ambient; }

        void setDiffuse(double diffuse) { this->_diffuse = diffuse; }

        void setPoint(const std::vector<raytracer::Vector3<int>> &newPoint)
        {
            this->_point = newPoint;
        }

        void setRadius(int radius) { this->_radius = radius; }

        int getRadius() { return this->_radius; };

       private:
        std::string _type = "";
        raytracer::Vector3<int> _position = {0, 0, 0};
        raytracer::Vector3<int> _color = {0, 0, 0};
        raytracer::Vector2<int> _res = {0, 0};
        raytracer::Vector3<int> _rotation = {0, 0, 0};
        double _fieldOfView = 0;
        double _ambient = 0;
        double _diffuse = 0;
        std::vector<raytracer::Vector3<int>> _point;
        int _radius = 0;
    };
}  // namespace raytracer
