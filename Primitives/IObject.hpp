//
// EPITECH PROJECT, 2025
// IObject
// File description:
// IObject
//

#pragma once

#include <cstdint>
#include <exception>
#include <limits>
#include <memory>
#include <optional>
#include <string>

#include "../Utils/Vector.hpp"
#include "Material.hpp"

namespace raytracer {
    class Raycast;
}

namespace objects {

    ///
    /// \struct metaData_s
    /// \brief Optional metadata for geometric objects.
    ///
    /// Contains optional parameters such as radius, angle, height, normal vector,
    /// or direction. This allows for more flexible object configuration (e.g., cones, planes, cylinders).
    ///
    typedef struct metaData_s {
        std::optional<int> radius; ///< Optional radius.
        std::optional<int> angle; ///< Optional angle.
        std::optional<int> height; ///< Optional height.
        std::optional<raytracer::Vector3<double>> normal; ///< Optional surface normal vector.
        std::optional<raytracer::Vector3<double>> direction; ///< Optional direction vector.
    } metaData_t;

    ///
    /// \struct hitResult_s
    /// \brief Stores the result of a ray-object intersection.
    ///
    /// Contains intersection information such as the hit position,
    /// normal at the point, distance `t`, and material properties.
    ///
    typedef struct hitResult_s {
        bool hit = false; ///< Whether an intersection occurred.
        double t = std::numeric_limits<double>::max(); ///< Distance to intersection.
        raytracer::Vector3<double> position; ///< Intersection position.
        raytracer::Vector3<double> normal; ///< Surface normal at intersection.
        Material material; ///< Material at the intersection point.
    } hitResult_t;

    ///
    /// \class IObjectError
    /// \brief Exception class for errors related to IObject.
    ///
    /// Thrown when an error occurs with object instantiation or usage.
    ///
    class IObjectError : public std::exception {
       public:
        ///
        /// \brief Constructor with error message.
        ///
        /// \param msg Error message.
        ///
        IObjectError(const std::string &msg);

        ///
        /// \brief Gets the error message.
        ///
        /// \return C-style string of the error message.
        ///
        [[nodiscard]] const char *what() const noexcept override
        {
            return this->_msg.c_str();
        }

       private:
        std::string _msg; ///< Stored error message.
    };

    ///
    /// \class IObject
    /// \brief Interface for geometric objects in the scene.
    ///
    /// All 3D primitives must implement this interface to be handled by the raytracer.
    ///
    class IObject {
       public:
        virtual ~IObject() = default;

        ///
        /// \brief Creates a deep copy of the object.
        ///
        /// \return A unique pointer to the cloned object.
        ///
        virtual std::unique_ptr<IObject> clone() const = 0;

        ///
        /// \brief Sets the object’s position in 3D space.
        ///
        /// \param pos A vector representing position.
        ///
        virtual void setPosition(raytracer::Vector3<int> pos) = 0;

        ///
        /// \brief Gets the object’s current position.
        ///
        /// \return The object's position vector.
        ///
        [[nodiscard]] virtual raytracer::Vector3<int> getPosition() const = 0;

        ///
        /// \brief Sets the object's color using a vector.
        ///
        virtual void setColor(raytracer::Vector3<double> rgb) = 0;

        ///
        /// \brief Sets the object's color using RGB values.
        ///
        virtual void setColor(double r, double g, double b) = 0;

        ///
        /// \brief Gets the current color of the object.
        ///
        virtual raytracer::Vector3<double> getColor() const = 0;

        ///
        /// \brief Sets the transparency level of the object.
        ///
        virtual void setTransparence(double value) = 0;

        ///
        /// \brief Gets the transparency level of the object.
        ///
        virtual double getTransparence() const = 0;

        ///
        /// \brief Sets the reflection factor of the object.
        ///
        virtual void setReflection(double value) = 0;

        ///
        /// \brief Gets the reflection factor of the object.
        ///
        virtual double getReflection() const = 0;

        ///
        /// \brief Returns a string representing the object type.
        ///
        virtual std::string getType() const = 0;

        ///
        /// \brief Performs a ray-object intersection test.
        ///
        /// \param ray The ray to cast.
        /// \param result The result structure to populate if a hit occurs.
        ///
        /// \return True if an intersection occurred, false otherwise.
        ///
        virtual bool hit(const raytracer::Raycast &ray, hitResult_t &result) const = 0;

        ///
        /// \brief Sets custom metadata for the object.
        ///
        /// \param metadata Metadata struct containing extra parameters.
        ///
        virtual void setMetadata(const metaData_t &metadata) = 0;

        ///
        /// \brief Returns a reference to the object's metadata.
        ///
        /// \return Reference to metadata struct.
        ///
        virtual metaData_t &getMetaData() = 0;
    };

    ///
    /// \brief Entry point to create a primitive object via dynamic loading.
    ///
    /// \return A unique pointer to a new IObject.
    ///
    extern "C" std::unique_ptr<objects::IObject> createPrimitive(void);

}  // namespace objects
