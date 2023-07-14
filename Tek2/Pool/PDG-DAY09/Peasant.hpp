/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD09-lysandra.manuguerra
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
    #define PEASANT_HPP_
    #include <iostream>
    #include <iomanip>

class Peasant {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();
        std::string Name;
        int Power;
        int hp;
        int getPower() const;
        int getHp() const;
        const std::string &getName() const;
        int attack();
        int special();
        void rest();
        void damage(int damage);
        void setPower(int Power);
};

#endif /* !PEASANT_HPP_ */
