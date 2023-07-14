/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD08-lysandra.manuguerra
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::setStatus(std::string status)
{
    Status = status;
}

Droid::setEnergy(size_t energy)
{
    Energy = energy;
}

Droid::setId(std::string id)
{
    Id = id;
}

// int main()
// {
    // Droid d;
    // Droid d1("Avenger");
    // size_t Durasel = 200;
    // std::cout << d << std::endl;
    // std::cout << d1 << std::endl;
    // d = d1;
    // d.setStatus(new std::string("Kill Kill Kill !"));
    // d << Durasel;
    // std::cout << d << " --" << Durasel << std::endl;
    // Droid d2 = d;
    // d.setId(" Rex ");
    // std::cout << ( d2 != d ) << std::endl;
    // return 0;
// }
