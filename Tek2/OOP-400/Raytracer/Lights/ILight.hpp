/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** ILight
*/

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_
#include "Color.hpp"

class ILight {
    public:
        virtual ~ILight() = default;
        virtual Color calculateLight(const Intersection& intersection, const Scene& scene) const = 0;
};

#endif /* !ILIGHT_HPP_ */
