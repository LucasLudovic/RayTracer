//
// EPITECH PROJECT, 2025
// IObject
// File description:
// IObject
//

#pragma once

#include <exception>
#include <memory>
#include <optional>
#include <string>

#include "../Utils/Vector.hpp"

namespace raytracer {
class Raycast;
}

namespace objects {

typedef struct metaData
{
    std::optional<int> radius;
} metaData_t;

class IObject
{
   public:
    virtual ~IObject() = default;

    class IObjectError : public std::exception
    {};

    virtual std::unique_ptr<IObject> clone() const = 0;

    virtual void setPosition(raytracer::Vector3<int> pos) = 0;
    [[nodiscard]] virtual raytracer::Vector3<int> getPosition() const = 0;

    virtual void setColor(raytracer::Vector3<double> rgb) = 0;
    virtual void setColor(double r, double g, double b) = 0;
    virtual raytracer::Vector3<double> getColor() const = 0;
    virtual void setTransparence(double value) = 0;
    virtual double getTransparence() const = 0;
    virtual void setReflection(double value) = 0;
    virtual double getReflection() const = 0;

    virtual std::string getType() const = 0;

    virtual bool hit(const raytracer::Raycast &ray) const = 0;

    virtual metaData_t &getMetaData() = 0;
};

extern "C" std::unique_ptr<objects::IObject> createPrimitive(void);
}  // namespace objects
