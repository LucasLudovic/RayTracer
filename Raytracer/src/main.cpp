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
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl
              << "SCENE_FILE: scene configuration" << std::endl;
}

static int check_args(int argc, char **argv)
{
    if (argc != NB_ARGS || argv == nullptr || argv[0] == nullptr ||
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
    if (!check_args(argc, argv)) {
        return EPITECH_FAILURE;
    }
    return execute_raytracer(argv[1]);
}
