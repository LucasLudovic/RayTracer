//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Camera.hpp
//

#pragma once

#include "Vector.hpp"

namespace objects {
    class Camera {
       public:
        Camera();

        void setPosition(raytracer::Vector3<int> pos);
        raytracer::Vector3<int> getPosition() const;

        void setResolution(raytracer::Vector2<int> res);
        raytracer::Vector2<int> getResolution() const;

        void setRotation(raytracer::Vector3<int> rotation);
        raytracer::Vector3<int> getRotation() const;

        void setFieldOfView(int value);
        int getFieldOfView() const;

       private:
        raytracer::Vector2<int> _res;
        raytracer::Vector3<int> _rotation;
        raytracer::Vector3<int> _position;
        int _fieldOfView = 0;
    };
}  // namespace objects
