/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-lysandra.manuguerra
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_
    #include <iostream>
    #include <string>
    #include <map>
    #include <memory>
    #include <vector>
    #include <fstream>
    #include <sstream>
    #include <algorithm>

namespace nts
{
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent
    {
    public:
        IComponent() = default;
        virtual ~IComponent() = default;

        IComponent(IComponent const &) = delete;
        IComponent(IComponent &&) = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual const std::string &getName() const;
    };
}

std::ostream &operator<<(std::ostream &out, nts::Tristate state);

#endif /* !ICOMPONENT_HPP_ */
