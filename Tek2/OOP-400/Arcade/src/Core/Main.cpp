/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Main.cpp
*/

#include "Resources.hpp"
#include "Core.hpp"

/**
 * @brief Check if the arguments are valid
 *
 * @param argc The number of arguments
 * @param argv The arguments
 * @return int 0 if the arguments are valid, 84 otherwise
*/

int error(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 84;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << argv[1] << std::endl;
        return 84;
    }
    file.close();
    return 0;
}

/**
 * @brief The main function of the program
 *
 * @param argc The number of arguments
 * @param argv The arguments
*/

int main(int argc, char **argv)
{
    if (error(argc, argv) != 0) {
        return 84;
    }

    Core core;
    core.getPlayerName();
    core.getAllLib();
    core.getLib(argv[1]);
    core.launchArcade(argv[1]);
    return 0;
}
