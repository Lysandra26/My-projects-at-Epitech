/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-lysandra.manuguerra
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
    #define CIRCUIT_HPP_
    #include "IComponent.hpp"

class Circuit {
    public:
        Circuit();
        ~Circuit();

        void addComponent(const std::string &name, std::unique_ptr<nts::IComponent> component);
        nts::IComponent *findComponent(const std::string &name) const;
        void simulate();
        void display();
    protected:
    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> components;
        int tick = 0;
};

#endif /* !CIRCUIT_HPP_ */
