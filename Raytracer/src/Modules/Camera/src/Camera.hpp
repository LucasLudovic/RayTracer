//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Camera.hpp
//

#pragma once

#include "Vector.hpp"

namespace objects {

    /**
     * @class Camera
     * @brief Represents a camera in a 3D scene.
     *
     * The Camera class defines the viewpoint in the ray tracing environment.
     * It holds the position, rotation, resolution, and field of view settings.
     */
    class Camera {
       public:
        /**
         * @brief Default constructor.
         */
        Camera();

        /**
         * @brief Sets the camera position in 3D space.
         * @param pos A 3D vector representing the position.
         */
        void setPosition(raytracer::Vector3<int> pos);

        /**
         * @brief Gets the camera position.
         * @return A 3D vector representing the camera position.
         */
        raytracer::Vector3<int> getPosition() const;

        /**
         * @brief Sets the resolution of the camera.
         * @param res A 2D vector representing the resolution (width x height).
         */
        void setResolution(raytracer::Vector2<int> res);

        /**
         * @brief Gets the camera resolution.
         * @return A 2D vector representing the resolution.
         */
        raytracer::Vector2<int> getResolution() const;

        /**
         * @brief Sets the camera rotation in 3D space.
         * @param rotation A 3D vector representing the rotation angles (pitch, yaw, roll).
         */
        void setRotation(raytracer::Vector3<int> rotation);

        /**
         * @brief Gets the camera rotation.
         * @return A 3D vector representing the camera's rotation.
         */
        raytracer::Vector3<int> getRotation() const;

        /**
         * @brief Sets the camera's field of view.
         * @param value Field of view in degrees.
         */
        void setFieldOfView(int value);

        /**
         * @brief Gets the field of view of the camera.
         * @return The field of view in degrees.
         */
        int getFieldOfView() const;

       private:
        raytracer::Vector2<int> _res;        ///< Resolution of the camera (width x height).
        raytracer::Vector3<int> _rotation;   ///< Rotation of the camera (pitch, yaw, roll).
        raytracer::Vector3<int> _position;   ///< Position of the camera in 3D space.
        int _fieldOfView = 0;                ///< Field of view in degrees.
    };

}  // namespace objects
