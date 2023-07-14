/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD08-lysandra.manuguerra
** File description:
** Droid
*/

#ifndef DROID_HPP_
    #define DROID_HPP_
    #include <iostream>
    #include <iomanip>

class Droid {
    private:
        std::string Id;
        const size_t Attack = 25;
        size_t Energy = 50;
        const size_t Toughness = 15;
        std::string Status = "Standing by";
    public:
        setId(std::string id);
        setEnergy(size_t energy);
        setStatus(std::string status);
};

#endif /* !DROID_HPP_ */
