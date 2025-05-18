//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// basicObject
//

#pragma once

#include <string>
#include <vector>

#include "../Primitives/Material.hpp"
#include "../Utils/Vector.hpp"
#include "Material.hpp"
#include "../Primitives/Material.hpp"

namespace raytracer {

    ///
    /// \class BasicObject
    /// \brief Represents the fundamental object type for the raytracer scene, encapsulating common properties and behaviors.
    ///
    class BasicObject
    {
       public:

        ///
        /// \brief Default constructor. Initializes material and default values.
        ///
        BasicObject() : _material() {};

        ///
        /// \brief Default destructor.
        ///
        ~BasicObject() {};

        ///
        /// \brief Set the position of the object in 3D space.
        /// \param pos The position vector.
        ///
        void setPosition(raytracer::Vector3<int> pos)
        {
            this->_position = pos;
        };

        ///
        /// \brief Get the position of the object.
        /// \return The position vector.
        ///
        [[nodiscard]] raytracer::Vector3<int> getPosition() const
        {
            return this->_position;
        };

        ///
        /// \brief Set the color of the object.
        /// \param rgb The RGB vector specifying color.
        ///
        void setColor(raytracer::Vector3<double> rgb)
        {
            this->_material.set_color(rgb);
        }

        ///
        /// \brief Set the color using separate RGB values.
        /// \param r Red component.
        /// \param g Green component.
        /// \param b Blue component.
        ///
        void setColor(double r, double g, double b)
        {
            this->_material.set_color(r, g, b);
        }

        ///
        /// \brief Get the color of the object.
        /// \return The RGB color vector.
        ///
        raytracer::Vector3<double> getColor() const
        {
            return this->_material.get_color();
        }

        ///
        /// \brief Set the transparence value for the object.
        /// \param value Transparence amount.
        ///
        void setTransparence(double value)
        {
            this->_material.set_transparence(value);
        }

        ///
        /// \brief Get the transparence value.
        /// \return The transparence amount.
        ///
        double getTransparence() const
        {
            return this->_material.get_transparence();
        }

        ///
        /// \brief Set the reflection ratio for the object.
        /// \param value Reflection amount.
        ///
        void setReflection(double value)
        {
            this->_material.set_reflection(value);
        }

        ///
        /// \brief Get the reflection value.
        /// \return The reflection ratio.
        ///
        double getReflection() const
        {
            return this->_material.get_reflection();
        }

        ///
        /// \brief Get the type string of the object.
        /// \return The object type.
        ///
        std::string getType() const
        {
            return this->_type;
        };

        ///
        /// \brief Set the type string of the object.
        /// \param type The type string.
        ///
        void setType(const std::string &type)
        {
            this->_type = type;
        };

        ///
        /// \brief Set the resolution for the object.
        /// \param res The resolution vector (width, height).
        ///
        void setResolution(raytracer::Vector2<int> res)
        {
            this->_res = res;
        }

        ///
        /// \brief Get the object's resolution.
        /// \return The resolution vector.
        ///
        raytracer::Vector2<int> getResolution() {
            return this->_res;
        }

        ///
        /// \brief Set the rotation for the object.
        /// \param rotation The rotation vector (degrees or radians).
        ///
        void setRotation(raytracer::Vector3<int> rotation)
        {
            this->_rotation = rotation;
        }

        ///
        /// \brief Get the rotation for the object.
        /// \return The rotation vector.
        ///
        raytracer::Vector3<int> getRotation() const
        {
            return this->_rotation;
        }

        ///
        /// \brief Set the field of view (typically for camera-like objects).
        /// \param value The field of view angle.
        ///
        void setFieldOfView(double value)
        {
            this->_fieldOfView = value;
        }

        ///
        /// \brief Get the field of view.
        /// \return Field of view angle.
        ///
        double getFieldOfView() const
        {
            return this->_fieldOfView;
        }

        ///
        /// \brief Get the ambient parameter value.
        /// \return The ambient value.
        ///
        double getAmbient() const
        {
            return this->_ambient;
        }

        ///
        /// \brief Get the diffuse parameter value.
        /// \return The diffuse value.
        ///
        double getDiffuse() const
        {
            return this->_diffuse;
        }

        ///
        /// \brief Get the object's point vector.
        /// \return Vector of 3D points associated with the object.
        ///
        std::vector<raytracer::Vector3<int>> getPoint() const
        {
            return this->_point;
        }

        ///
        /// \brief Set the ambient parameter.
        /// \param ambient The ambient value.
        ///
        void setAmbient(double ambient)
        {
            this->_ambient = ambient;
        }

        ///
        /// \brief Set the diffuse parameter.
        /// \param diffuse The diffuse value.
        ///
        void setDiffuse(double diffuse)
        {
            this->_diffuse = diffuse;
        }

        ///
        /// \brief Set the object's point vector.
        /// \param newPoint New list of 3D points.
        ///
        void setPoint(const std::vector<raytracer::Vector3<int>> &newPoint)
        {
            this->_point = newPoint;
        }

        ///
        /// \brief Set the object radius.
        /// \param radius The radius value.
        ///
        void setRadius(int radius)
        {
            this->_radius = radius;
        }

        ///
        /// \brief Get the object radius.
        /// \return The radius value.
        ///
        int getRadius()
        {
            return this->_radius;
        };

        ///
        /// \brief Set the normal vector for the object.
        /// \param normal The normal vector.
        ///
        void setNormal(raytracer::Vector3<double> normal)
        {
            this->_normal = normal;
        }

        ///
        /// \brief Get the normal vector.
        /// \return Reference to the normal vector.
        ///
        const raytracer::Vector3<double> &getNormal()
        {
            return this->_normal;
        };

        ///
        /// \brief Set the direction vector for the object.
        /// \param direction The direction vector.
        ///
        void setDirection(raytracer::Vector3<double> direction)
        {
            this->_direction = direction;
        }

        ///
        /// \brief Get the direction vector.
        /// \return Reference to the direction vector.
        ///
        const raytracer::Vector3<double> &getDirection()
        {
            return this->_direction;
        };

        ///
        /// \brief Set the object's height.
        /// \param height The height value.
        ///
        void setHeight(int height)
        {
            this->_height = height;
        }

        ///
        /// \brief Get the object's height.
        /// \return Reference to the height value.
        ///
        const int &getHeight()
        {
            return this->_height;
        };

        ///
        /// \brief Set the object's angle.
        /// \param angle The angle value.
        ///
        void setAngle(int angle)
        {
            this->_angle = angle;
        }

        ///
        /// \brief Get the object's angle.
        /// \return Reference to the angle value.
        ///
        const int &getAngle()
        {
            return this->_angle;
        };

       private:
        std::string _type = ""; ///< The type of the object.
        raytracer::Vector3<int> _position = {0, 0, 0}; ///< Position vector.
        objects::Material _material; ///< Object's material.
        raytracer::Vector2<int> _res = {0, 0}; ///< Resolution.
        raytracer::Vector3<int> _rotation = {0, 0, 0}; ///< Rotation.
        double _fieldOfView = 0; ///< Field of view angle.
        double _ambient = 0; ///< Ambient value.
        double _diffuse = 0; ///< Diffuse value.
        std::vector<raytracer::Vector3<int>> _point; ///< Points associated with the object.
        int _radius = 0; ///< Radius.
        int _angle = 0; ///< Angle.
        int _height = 0; ///< Height.
        raytracer::Vector3<double> _normal = {0, 0, 1}; ///< Normal vector.
        raytracer::Vector3<double> _direction = {0, 0, 1}; ///< Direction vector.
    };
}  // namespace raytracer
