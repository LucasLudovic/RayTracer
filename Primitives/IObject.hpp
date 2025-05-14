//
// EPITECH PROJECT, 2025
// IObject
// File description:
// IObject
//

#pragma once

#include "../Utils/Vector.hpp"
#include <cstdint>
#include <exception>
#include <limits>
#include <memory>
#include <optional>
#include <string>

namespace raytracer {
    class Raycast;
}

namespace objects {

    typedef struct metaData_s {
        std::optional<int> radius;
        std::optional<raytracer::Vector3<double>> normal;
    } metaData_t;

    typedef struct hitResult_s {
        bool hit = false;
        double t = std::numeric_limits<double>::max();
        raytracer::Vector3<double> position;
        raytracer::Vector3<double> normal;
        raytracer::Vector3<int> color;
    } hitResult_t;

    class IObject {
       public:
        virtual ~IObject() = default;

        class IObjectError : public std::exception {};

        virtual std::unique_ptr<IObject> clone() const = 0;

        virtual void setPosition(raytracer::Vector3<int> pos) = 0;
        [[nodiscard]] virtual raytracer::Vector3<int> getPosition() const = 0;

        virtual void setColor(raytracer::Vector3<int> rgb) = 0;
        virtual raytracer::Vector3<int> getColor() const = 0;

        virtual std::string getType() const = 0;

        virtual bool hit(const raytracer::Raycast &ray,
            hitResult_t &result) const = 0;

        virtual void setMetadata(const metaData_t &metadata) = 0;
        virtual metaData_t &getMetaData() = 0;
    };

    extern "C" std::unique_ptr<objects::IObject> createPrimitive(void);
}  // namespace objects
