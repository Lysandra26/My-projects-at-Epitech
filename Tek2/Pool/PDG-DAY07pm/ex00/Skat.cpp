/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD07pm-lysandra.manuguerra
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat()
{
}

Skat::~Skat()
{
}

int main()
{
    Skat s(" Junior " , 5);
    std::cout << " Soldier " << s.name() << std :: endl;
    s.status();
    s.useStimPaks();
    return 0;
}