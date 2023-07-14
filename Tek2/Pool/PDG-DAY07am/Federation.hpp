/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD07am-lysandra.manuguerra
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
    #define FEDERATION_HPP_
    #include <iostream>
    #include <iomanip>

namespace Federation {
    namespace Starfleet {
        class Ship {
        public:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            Ship(int length, int width, std::string name, short maxWarp);
        };
    }
}

#endif /* !FEDERATION_HPP_ */
