/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-lysandra.manuguerra
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
    #define XORCOMPONENT_HPP_
    #include "IComponent.hpp"

namespace nts
{
    class XorComponent : public IComponent
    {
    public:
        XorComponent() = default;
        ~XorComponent() = default;
        nts::Tristate Xor(nts::Tristate a, nts::Tristate b) {}
       
        void simulate(std::size_t tick) = 0;
        Tristate compute(std::size_t pin) = 0;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        const std::string &getName() const;

    protected:
    private:
    };
}

#endif /* !XORCOMPONENT_HPP_ */
