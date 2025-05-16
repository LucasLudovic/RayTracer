//
// EPITECH PROJECT, 2025
// Scene
// File description:
// Object containing the elements for the app
//

#pragma once

#include "IObject.hpp"
#include "Vector.hpp"
#include "IRenderer.hpp"
#include "basicObject.hpp"
#include "src/Modules/Lights/src/Lights.hpp"
#include "src/Modules/Camera/src/Camera.hpp"
#include "src/DlLib/DlLib.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace raytracer {
    class Scene {
       public:
        Scene() {};
        ~Scene();

        void load(const std::string &file);
        void renderScene(renderer::IRenderer &renderer);

        class SceneError : public std::exception {
           public:
            SceneError(const std::string &msg) : _msg(msg) {};
            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            }
           private:
            std::string _msg;
        };
        const objects::Camera &getCamera() {return *this->_camera;}

       private:
        std::vector<std::unique_ptr<objects::IObject>> _composition;
        std::unique_ptr<objects::Camera> _camera;
        std::unique_ptr<objects::Lights> _lights;
        std::vector<std::unique_ptr<objects::IObject>> _availableObjects;
        std::vector<std::unique_ptr<Utils::DlLib<objects::IObject>>> _objectsLib;

        Vector3<double> _computeLighting(const objects::hitResult_t &hit);
        void _getAvailableObject();
        void _createPlane(std::unique_ptr<BasicObject> Plane);
        void _createSphere(std::unique_ptr<BasicObject> Sphere);
        void _createCamera(std::unique_ptr<BasicObject> Camera);
        void _createLights(std::unique_ptr<BasicObject> Lights);
        void _setObjects(std::vector<std::unique_ptr<BasicObject>> Primitives);
        Vector3<int> _computeRelativePos(const objects::IObject &object);
    };
}  // namespace raytracer
