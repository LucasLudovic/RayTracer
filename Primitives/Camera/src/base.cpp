//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "Camera.hpp"

objects::Camera::Camera(): AObject() {}

void objects::Camera::setResolution(raytracer::Vector2<int> res)
{
    this->_res = res;
}

raytracer::Vector2<int> objects::Camera::getResolution() const
{
    return this->_res;
}

void objects::Camera::setRotation(raytracer::Vector3<int> rotation)
{
    this->_rotation = rotation;
}

raytracer::Vector3<int> objects::Camera::getRotation() const
{
    return this->_rotation;
}

void objects::Camera::setFieldOfVue(int value)
{
    this->_fieldOfVue = value;
}

int objects::Camera::getFieldOfView() const
{
    return this->_fieldOfVue;
}
