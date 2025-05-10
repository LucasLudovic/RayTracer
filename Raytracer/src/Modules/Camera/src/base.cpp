//
// EPITECH PROJECT, 2025
// Base
// File description:
// Base functions
//

#include "Camera.hpp"

objects::Camera::Camera() {};

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

void objects::Camera::setFieldOfView(int value)
{
    this->_fieldOfView = value;
}

int objects::Camera::getFieldOfView() const
{
    return this->_fieldOfView;
}

void objects::Camera::setPosition(raytracer::Vector3<int> pos)
{
    this->_position = pos;
}

raytracer::Vector3<int> objects::Camera::getPosition() const
{
    return this->_position;
}
