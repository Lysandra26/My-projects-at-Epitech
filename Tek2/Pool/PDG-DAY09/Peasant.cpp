/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-lysandra.manuguerra
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)
{
    Name = name;
    hp = 100;
    Power = power;
    std::cout << name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << Name << " is back to his crops." << std::endl;
}

int Peasant::getPower() const
{
    return Power;
}

int Peasant::getHp() const
{
    return hp;
}

const std::string &Peasant::getName() const
{
    return Name;
}

int Peasant::attack()
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
        std::cout << Name << " tosses a stone." << std::endl;
        return 5;
    }
    return 0;
}

int Peasant::special()
{
    int power = 0;

    if (hp <= 0) {
        std::cout << Name << " is out of combat." << std::endl;
        return 0;
    }
    if (Power < power)
        std::cout << Name << " is out of power." << std::endl;
    else
        std::cout << Name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (hp > 0) {
        setPower(30);
        std::cout << Name << " takes a nap." << std::endl;
    } else
        std::cout << Name << " is out of combat." << std::endl;
}

void Peasant::damage(int damage)
{
    hp -= damage;
    if (hp <= 0) {
        hp = 0;
        std::cout << Name << " is out of combat." << std::endl;
    } else {
        std::cout << Name << " takes " << damage << " damage." << std::endl;
    }
}

void Peasant::setPower(int power)
{
    Power += power;
    if (Power >= 100)
        Power = 100;
}
