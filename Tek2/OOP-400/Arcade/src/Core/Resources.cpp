/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Utils
*/

#include "Resources.hpp"

/**
 * @brief Construct a new Utils object
*/

Utils::Utils() {}

/**
 * @brief Destroy the Utils object
*/

Utils::~Utils() {}

/**
 * @brief Open a library
 *
 * @param path The path of the library
*/

void *Utils::my_dlopen(std::string path)
{
    void* lib = dlopen(path.c_str(), RTLD_NOW);
    if (lib == nullptr)
        std::cerr << "ERROR dlopen : " << dlerror() << std::endl;
    return lib;
}

/**
 * @brief Close a library
*/

void Utils::my_dlclose(void *lib)
{
    if (dlclose(lib) != 0)
        std::cerr << "ERROR dlclose : " << dlerror() << std::endl;
}
