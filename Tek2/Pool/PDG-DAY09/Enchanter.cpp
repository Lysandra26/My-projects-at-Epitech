/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-lysandra.manuguerra
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << Name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << Name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    int power = 0;

    if (hp <= 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return 0;
    }
    if (Power < power)
        std::cout << Name << " is out of power." << std::endl;
    else
        std::cout << Name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    int power = 50;

    if (hp <= 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return 0;
    }
    if (Power < power)
        std::cout << Name << " is out of power." << std::endl;
    else {
        Power -= power;
        std::cout << Name << " casts a fireball." << std::endl;
        return 99;
    }
    return 0;
}

void Enchanter::rest()
{
    if (hp > 0) {
        setPower(100);
        std::cout << Name << " meditates." << std::endl;
    } else
        std::cout << Name << " is out of combat." << std::endl;
}
