/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-lysandra.manuguerra
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
    #define PALADIN_HPP_
    #include "Peasant.hpp"
    #include "Knight.hpp"
    #include "Enchanter.hpp"
    #include "Priest.hpp"

class Paladin : public Peasant {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();
};

#endif /* !PALADIN_HPP_ */
