/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-lysandra.manuguerra
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
    #define ORCOMPONENT_HPP_
    #include "IComponent.hpp"

namespace nts
{
    class OrComponent : public IComponent
    {
    public:
        OrComponent() = default;
        ~OrComponent()= default;
        nts::Tristate Or(nts::Tristate a, nts::Tristate b) {}

        void simulate(std::size_t tick) = 0;
        Tristate compute(std::size_t pin) = 0;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        const std::string &getName() const;

    protected:
    private:
    };
}

#endif /* !ORCOMPONENT_HPP_ */
