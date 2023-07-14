/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-lysandra.manuguerra
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << Name << " fights for the ligth." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << Name << " is blessed." << std::endl;
}
