//
// EPITECH PROJECT, 2025
// IObject
// File description:
// IObject
//

#pragma once

#include "../Utils/Vector.hpp"
#include <exception>
#include <memory>
#include <string>

namespace objects {

    class IObject {
       public:
        virtual ~IObject() = default;

        class IObjectError : public std::exception {};

        virtual std::unique_ptr<IObject> clone() const = 0;

        virtual void setPosition(raytracer::Vector3<int> pos) = 0;
        [[nodiscard]] virtual raytracer::Vector3<int> getPosition() const = 0;

        virtual void setColor(raytracer::Vector3<int> rgb) = 0;
        virtual raytracer::Vector3<int> getColor() const = 0;

        virtual void setRadius(int radius) = 0;
        virtual int getRadius() = 0;

        virtual std::string getType() const = 0;
    };

    extern "C" std::unique_ptr<objects::IObject> createPrimitive(void);
}  // namespace objects
