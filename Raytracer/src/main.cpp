//
// EPITECH PROJECT, 2025
// Main
// File description:
// Main
//

#include "my_macros.hpp"
#include "app.hpp"
#include <iostream>
#include <string>

static void display_help()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE> <RENDERER>" << std::endl
              << "SCENE_FILE: scene configuration" << std::endl
              << "RENDERER: path to renderer lib (optionnal)" << std::endl;
}

static int check_args(int argc, char **argv)
{
    if ((argc != NB_ARGS && argc != NB_ARGS + 1) || argv == nullptr || argv[0] == nullptr ||
        argv[1] == nullptr) {
        display_help();
        return false;
    }

    std::string argument(argv[1]);
    if (argument == "-help") {
        display_help();
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    std::string rendererPath = "";
    if (!check_args(argc, argv)) {
        return EPITECH_FAILURE;
    }
    if (argv[2] != NULL)
        rendererPath = argv[2];
    return execute_raytracer(argv[1], rendererPath);
}
