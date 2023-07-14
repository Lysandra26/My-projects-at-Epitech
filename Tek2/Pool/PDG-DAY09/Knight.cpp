/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-lysandra.manuguerra
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << Name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << Name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    int power = 10;

    if (hp <= 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return 0;
    }
    if (Power < power)
        std::cout << Name << " is out of power." << std::endl;
    else {
        Power -= power;
        std::cout << Name << " strikes with his sword." << std::endl;
        return 20;
    }
    return 0;
}

int Knight::special()
{
    int power = 30;

    if (hp <= 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return 0;
    }
    if (Power < power)
        std::cout << Name << " is out of power." << std::endl;
    else {
        Power -= power;
        std::cout << Name << " impales his enemy." << std::endl;
        return 50;
    }
    return 0;
}

void Knight::rest()
{
    if (hp > 0) {
        setPower(50);
        std::cout << Name << " eats." << std::endl;
    } else
        std::cout << Name << " is out of combat." << std::endl;
}
