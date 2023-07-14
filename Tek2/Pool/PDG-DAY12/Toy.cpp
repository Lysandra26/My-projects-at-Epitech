/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-lysandra.manuguerra
** File description:
** Toy
*/

#include "Toy.hpp"
#include "Picture.hpp"

Toy::Toy()
{
}

Toy::Toy(Toy::ToyType toy_type, std::string &name, std::string fileName)
{
    Name = name;
}

Toy::~Toy()
{
}

std::string Toy::getName()
{
    return Name;
}

int main ()
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "./alien.txt");
    toto.setName("TOTO !");
    if (toto.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy : " << toto.getName() << std::endl
            << toto.getAscii() << std::endl;
    if (ET.getType() == Toy::ALIEN)
        std::cout << " this alien is : " << ET.getName() << std::endl
            << ET.getAscii() << std::endl;
    return 0;
}
