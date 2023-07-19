/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-lysandra.manuguerra
** File description:
** nano
*/

#include "ErrorArgument.hpp"
#include "Parser.hpp"

int main(int argc, char *argv[])
{
    ErrorArgument errorArgument;
    Parser parser;

    if (argc == 2) {
        if(parser.ParserFileExist(argv[1]) == 0)
            return 0;
    } else
        errorArgument.argument_missing();
    return 0;
}