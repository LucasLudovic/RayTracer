//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// Header for object to handle the raytracer
//

#pragma once

#include "IRenderer.hpp"
#include "src/Scene/Scene.hpp"
#include <exception>
#include <memory>
#include <string>

namespace raytracer {

    /**
     * @class Raytracer
     * @brief Main class responsible for managing the ray tracing process.
     *
     * The Raytracer class loads a scene from a file, initializes the renderer,
     * and handles the main execution loop of the ray tracing system.
     */
    class Raytracer {
       public:
        /**
         * @brief Constructs a Raytracer with the given scene file and renderer path.
         * @param file Path to the scene description file.
         * @param rendererPath Path to the renderer shared library.
         */
        Raytracer(const std::string &file, const std::string rendererPath);

        /**
         * @brief Default destructor.
         */
        ~Raytracer() = default;

        /**
         * @class RaytracerError
         * @brief Exception class for errors occurring in the Raytracer.
         *
         * Used to report runtime errors with a custom message.
         */
        class RaytracerError : public std::exception {
           public:
            /**
             * @brief Constructs a RaytracerError with a message.
             * @param msg The error message.
             */
            RaytracerError(const std::string &msg) : _msg(msg) {};

            /**
             * @brief Returns the error message.
             * @return A C-style string with the error message.
             */
            [[nodiscard]] const char *what() const noexcept override
            {
                return this->_msg.c_str();
            }

           private:
            std::string _msg;  ///< Error message.
        };

        /**
         * @brief Starts and runs the ray tracing process.
         *
         * This method executes the main loop of the ray tracer, performing
         * rendering using the loaded scene and selected renderer.
         */
        void run();

       private:
        bool _isRunning =
            true;      ///< Flag indicating if the raytracer is running.
        Scene _scene;  ///< The scene to be rendered.
        std::string _rendererPath;  ///< Path to the dynamic renderer library.

        std::unique_ptr<renderer::IRenderer> renderer =
            nullptr;  ///< Pointer to the dynamically loaded renderer.
    };

}  // namespace raytracer
