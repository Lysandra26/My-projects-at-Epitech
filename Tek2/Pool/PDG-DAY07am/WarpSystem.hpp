/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD07am-lysandra.manuguerra
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
    #define WARPSYSTEM_HPP_
    #include <iostream>
    #include <iomanip>

namespace WarpSystem {
    class QuantumReactor {
    public:
        bool _stability;
        bool isStable();
        void setStability(bool stability);
    };
}

#endif /* !WARPSYSTEM_HPP_ */
