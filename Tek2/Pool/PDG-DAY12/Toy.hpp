/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-lysandra.manuguerra
** File description:
** Toy
*/

#ifndef TOY_HPP_
    #define TOY_HPP_

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
        Toy();
        Toy(Toy::ToyType toy_type, std::string &name, std::string fileName);
        ~Toy();
        getType();
        std::string getName();
        setName(std::string name);
        setAscii();
        getAscii();
        int Name;
    protected:
    private:
};

#endif /* !TOY_HPP_ */
