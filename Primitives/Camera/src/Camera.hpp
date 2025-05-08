//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Camera.hpp
//

#pragma once

#include "AObject.hpp"

namespace objects {
    class Camera : public AObject {
       public:
        Camera();

        class CameraError : public AObjectError {};

        void setResolution(raytracer::Vector2<int> res);
        raytracer::Vector2<int> getResolution() const;

        void setRotation(raytracer::Vector3<int> rotation);
        raytracer::Vector3<int> getRotation() const;

        void setFieldOfVue(int value);
        int getFieldOfView() const;

       private:
        raytracer::Vector2<int> _res;
        raytracer::Vector3<int> _rotation;
        int _fieldOfVue = 0;
    };
}  // namespace objects
