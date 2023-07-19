/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-lysandra.manuguerra
** File description:
** ErrorArgument
*/

#include "ErrorArgument.hpp"

ErrorArgument::ErrorArgument() {}

ErrorArgument::~ErrorArgument() {}

int ErrorArgument::argument_missing()
{
    std::cerr << "ERROR :" << std::endl;
    std::cerr << "Missing argument, check -h for more info" << std::endl;
    return 84;
}
