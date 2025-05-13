//
// EPITECH PROJECT, 2025
// AObject
// File description:
// AObject
//

#pragma once

#include "../Utils/Vector.hpp"
#include "IObject.hpp"
#include "Material.hpp"

namespace objects {

class AObject : public objects::IObject
{
   public:
    AObject() : _material() {};

        std::string getType() const override = 0;

        std::unique_ptr<IObject> clone() const override = 0;

        void setPosition(raytracer::Vector3<int> pos) override
        {
            this->_position = pos;
        }

        raytracer::Vector3<int> getPosition() const override
        {
            return this->_position;
        }

        void setColor(raytracer::Vector3<int> rgb) override
        {
            this->_color = rgb;
        }

        raytracer::Vector3<int> getColor() const override
        {
            return this->_color;
        }

        void setMetadata(const metaData_t &metadata) override {this->_metaData = metadata;};

        metaData_t &getMetaData() override { return this->_metaData; };

       protected:
        std::string _type;
        raytracer::Vector3<int> _position;
        raytracer::Vector3<int> _color;
        metaData_t _metaData;

    std::string getType() const override = 0;

    std::unique_ptr<IObject> clone() const override = 0;

    void setPosition(raytracer::Vector3<int> pos) override
    {
        this->_position = pos;
    }

    raytracer::Vector3<int> getPosition() const override
    {
        return this->_position;
    }

    void setColor(raytracer::Vector3<double> rgb) override
    {
        this->_material.set_color(rgb);
    }

    void setColor(double r, double g, double b) override
    {
        this->_material.set_color(r, g, b);
    }

    raytracer::Vector3<double> getColor() const override
    {
        return this->_material.get_color();
    }

    void setTransparence(double value) override
    {
        this->_material.set_transparence(value);
    }

    double getTransparence() const override
    {
        return this->_material.get_transparence();
    }

    void setReflection(double value) override
    {
        this->_material.set_reflection(value);
    }

    double getReflection() const override
    {
        return this->_material.get_reflection();
    }

    metaData_t &getMetaData() override
    {
        return this->_metaData;
    };

   protected:
    std::string _type;
    raytracer::Vector3<int> _position;
    objects::Material _material;
    metaData_t _metaData;
};
}  // namespace objects
