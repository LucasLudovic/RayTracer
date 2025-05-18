//
// EPITECH PROJECT, 2025
// Scene
// File description:
// Object containing the elements for the app
//

#pragma once

#include "IObject.hpp"
#include "IRenderer.hpp"
#include "Vector.hpp"
#include "basicObject.hpp"
#include "src/DlLib/DlLib.hpp"
#include "src/Modules/Camera/src/Camera.hpp"
#include "src/Modules/Lights/src/Lights.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace raytracer {

    /**
     * @class Scene
     * @brief Represents a 3D scene composed of objects, lights, and a camera.
     *
     * The Scene class handles loading the scene from a file, managing objects and lights,
     * and rendering using a provided renderer. It includes utilities for lighting, ray
     * generation, and object management.
     */
    class Scene {
       public:
        /**
         * @brief Default constructor.
         */
        Scene() {};

        /**
         * @brief Destructor.
         */
        ~Scene();

        /**
         * @brief Loads a scene from a file.
         * @param file Path to the scene description file.
         * @throws SceneError If the scene fails to load.
         */
        void load(const std::string &file);

        /**
         * @brief Renders the current scene using the given renderer.
         * @param renderer The renderer used to display the scene.
         * @return a boolean for if the render should continue.
         */
        bool renderScene(renderer::IRenderer &renderer);

        /**
         * @class SceneError
         * @brief Exception class for Scene-related errors.
         */
        class SceneError : public std::exception {
           public:
            /**
             * @brief Constructs a SceneError with a message.
             * @param msg Description of the error.
             */
            SceneError(const std::string &msg) : _msg(msg) {};

            /**
             * @brief Returns the error message.
             * @return A C-style string with the error message.
             */
            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            }

           private:
            std::string _msg; ///< Error message string.
        };

        /**
         * @brief Returns the camera currently used by the scene.
         * @return A constant reference to the scene's camera.
         */
        const objects::Camera &getCamera() { return *this->_camera; }

       private:
        std::vector<std::unique_ptr<objects::IObject>> _composition; ///< Objects composing the scene.
        std::unique_ptr<objects::Camera> _camera; ///< Scene camera.
        std::unique_ptr<objects::Lights> _lights; ///< Scene lights.
        std::vector<std::unique_ptr<objects::IObject>> _availableObjects; ///< All available object instances.
        std::vector<std::unique_ptr<Utils::DlLib<objects::IObject>>> _objectsLib; ///< Libraries containing object types.

        /**
         * @brief Draws a single pixel on the renderer based on a ray.
         */
        void _drawPixel(renderer::IRenderer &renderer, Raycast &ray, int x, int y);

        /**
         * @brief Generates a ray from the camera for a given pixel.
         */
        Raycast _generateRay(int x, int y, int resX, int resY) const;

        /**
         * @brief Computes the lighting at the hit point.
         */
        Vector3<double> _computeLighting(const objects::hitResult_t &hit);

        /**
         * @brief Computes the specular component of lighting.
         */
        double _computeSpecularLighting(const objects::hitResult_t &hit,
                                        const Vector3<double> &normal,
                                        const Vector3<double> cameraVector) const;

        /**
         * @brief Computes the diffuse component of lighting.
         */
        double _computeDiffuseLighting(const objects::hitResult_t &hit,
                                       const raytracer::Vector3<double> &normal) const;

        /**
         * @brief Checks whether a point is in shadow.
         */
        bool _checkInShadow(const raytracer::Raycast &shadowRay, double lightDist) const;

        /**
         * @brief Loads available object types from dynamic libraries.
         */
        void _getAvailableObject();

        /**
         * @brief Creates a plane from a basic object.
         */
        void _createPlane(std::unique_ptr<BasicObject> Plane);

        /**
         * @brief Creates a sphere from a basic object.
         */
        void _createSphere(std::unique_ptr<BasicObject> Sphere);

        /**
         * @brief Creates a cylinder from a basic object.
         */
        void _createCylinder(std::unique_ptr<BasicObject> Cylinder);

        /**
         * @brief Creates a cone from a basic object.
         */
        void _createCone(std::unique_ptr<BasicObject> Cone);

        /**
         * @brief Creates a camera from a basic object.
         */
        void _createCamera(std::unique_ptr<BasicObject> Camera);

        /**
         * @brief Creates lights from a basic object.
         */
        void _createLights(std::unique_ptr<BasicObject> Lights);

        /**
         * @brief Sets all scene objects based on parsed primitives.
         */
        void _setObjects(std::vector<std::unique_ptr<BasicObject>> Primitives);

        /**
         * @brief Computes relative position of an object within the scene.
         */
        Vector3<int> _computeRelativePos(const objects::IObject &object);
    };

}  // namespace raytracer

