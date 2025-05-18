//
// EPITECH PROJECT, 2025
// Raytracer
// File description:
// CfgParser.hpp
//

#pragma once

#include "AParser.hpp"
#include <libconfig.h++>
#include <vector>

namespace raytracer {

    ///
    /// \class cfgParser
    /// \brief Concrete parser implementation for reading scene objects from libconfig files.
    ///
    class cfgParser : public AParser {
       public:
        ///
        /// \brief Default constructor.
        ///
        cfgParser() {};

        ///
        /// \brief Parses the configuration file and retrieves objects, camera and lights.
        ///
        void retrieveObjects() override;

       private:
        libconfig::Config _cfg; ///< The libconfig configuration object.

        ///
        /// \brief Retrieves all primitives from the root of the configuration.
        /// \param root The root configuration setting.
        ///
        void _retrievePrimitives(const libconfig::Setting &root);

        ///
        /// \brief Retrieves and parses all plane objects from the configuration.
        /// \param primitives The primitives setting from the configuration.
        ///
        void _retrievePlane(const libconfig::Setting &primitives);

        ///
        /// \brief Retrieves and parses all sphere objects from the configuration.
        /// \param primitives The primitives setting from the configuration.
        ///
        void _retrieveSphere(const libconfig::Setting &primitives);

        ///
        /// \brief Retrieves and parses all cylinder objects from the configuration.
        /// \param primitives The primitives setting from the configuration.
        ///
        void _retrieveCylinder(const libconfig::Setting &primitives);

        ///
        /// \brief Retrieves and parses all cone objects from the configuration.
        /// \param primitives The primitives setting from the configuration.
        ///
        void _retrieveCone(const libconfig::Setting &primitives);

        ///
        /// \brief Retrieves the camera data from the configuration.
        /// \param root The root configuration setting.
        ///
        void _retrieveCamera(const libconfig::Setting &root);

        ///
        /// \brief Retrieves the camera position from the configuration.
        /// \param camera The camera setting.
        /// \return The camera position as a Vector3<int>.
        ///
        raytracer::Vector3<int> _retrieveCameraPosition(const libconfig::Setting &camera);

        ///
        /// \brief Retrieves the camera rotation from the configuration.
        /// \param camera The camera setting.
        /// \return The camera rotation as a Vector3<int>.
        ///
        raytracer::Vector3<int> _retrieveCameraRotation(const libconfig::Setting &camera);

        ///
        /// \brief Retrieves the camera resolution from the configuration.
        /// \param camera The camera setting.
        /// \return The camera resolution as a Vector2<int>.
        ///
        raytracer::Vector2<int> _retrieveCameraResolution(const libconfig::Setting &camera);

        ///
        /// \brief Retrieves all light sources from the configuration.
        /// \param root The root configuration setting.
        ///
        void _retrieveLights(const libconfig::Setting &root);

        ///
        /// \brief Retrieves the light points from the configuration.
        /// \param lights The lights setting.
        /// \return A vector of Vector3<int> positions for each light point.
        ///
        std::vector<raytracer::Vector3<int>> _retrieveLightsPoint(const libconfig::Setting &lights);
    };
}  // namespace raytracer
