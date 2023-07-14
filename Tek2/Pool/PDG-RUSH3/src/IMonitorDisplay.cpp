/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGRUSH3-william.andreo
** File description:
** IMonitorDisplay
*/

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay()
{
}

IMonitorDisplay::~IMonitorDisplay()
{
}

int main(int argc, char *argv[])
{
    std::string text = "-text";
    std::string display = "-display";

    for (int i = 0; i < argc; i++) {
        std::string argI(argv[i]);
        if (argI == text)
            startNcurses();
        if (argI == display)
            startSfml();
    }
    return 0;
}

