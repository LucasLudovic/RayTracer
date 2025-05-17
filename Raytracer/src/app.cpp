//
// EPITECH PROJECT, 2025
// App
// File description:
// Entrypoint for the raytracer
//

#include "DlLib/DlLib.hpp"
#include "IParser.hpp"
#include "IRenderer.hpp"
#include "my_macros.hpp"
#include "src/Raytracer/Raytracer.hpp"
#include "src/Scene/Scene.hpp"
#include <iostream>
#include <string>

using raytracer::Raytracer;
using Utils::DlLibError;
using raytracer::Scene;

int execute_raytracer(const std::string &sceneFile, const std::string rendererPath)
{
    try {
        raytracer::Raytracer raytracerCore(sceneFile, rendererPath);

        raytracerCore.run();
    } catch (const Raytracer::RaytracerError &error) {
        std::cerr << "Application Error: " << error.what() << std::endl;
        return EPITECH_FAILURE;
    } catch (const DlLibError &error) {
        std::cerr << "Shared Library Error: " << error.what() << std::endl;
    } catch (const renderer::RendererError &error) {
        std::cerr << "Renderer error: " << error.what() << std::endl;
    } catch (const raytracer::ParserError &error) {
        std::cerr << "Parser error: " << error.what() << std::endl;
    } catch (const Scene::SceneError &error) {
        std::cerr << "Scene error: " << error.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
    }
    return EPITECH_SUCCESS;
}
