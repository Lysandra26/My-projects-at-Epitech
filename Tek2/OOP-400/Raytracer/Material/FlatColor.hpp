/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** FlatColor
*/

#ifndef FLATCOLOR_HPP_
#define FLATCOLOR_HPP_
#include "Material.hpp"


class FlatColorMaterial: public Material {
    public:
        FlatColorMaterial(const Color& color) {
            this->color = color;
        }
};

#endif /* !FLATCOLOR_HPP_ */
