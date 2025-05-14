//
// EPITECH PROJECT, 2025
// AObject
// File description:
// AObject
//

#pragma once

#include "../Utils/Vector.hpp"
#include "IObject.hpp"

namespace objects {

    class AObject : public objects::IObject {
       public:
        AObject() {};

        class AObjectError : public IObjectError {
           public:
            AObjectError(const std::string &msg) : _msg(msg) {};

            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            };

           private:
            std::string _msg;
        };

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
    };
}  // namespace objects
