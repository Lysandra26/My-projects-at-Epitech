/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-lysandra.manuguerra
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
    #define ENCHANTER_HPP_
    #include "Peasant.hpp"

class Enchanter : public Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();
        int attack();
        int special();
        void rest();
};

#endif /* !ENCHANTER_HPP_ */
