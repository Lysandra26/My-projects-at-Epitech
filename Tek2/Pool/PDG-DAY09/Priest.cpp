/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-lysandra.manuguerra
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power) : Enchanter (name, power)
{
    std::cout << Name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << Name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (hp > 0) {
        setPower(100);
        hp = 100;
        std::cout << Name << " prays." << std::endl;
    } else
        std::cout << Name << " is out of combat." << std::endl;
}
