/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** TextureMaterial
*/
#ifndef TEXTUREMATERIAL_HPP
#define TEXTUREMATERIAL_HPP
#include "Material.hpp"

class TextureMaterial : public Material {
    public:
        Texture texture;

        TextureMaterial(const Texture& texture) {
            this->texture = texture;
        }

        Color getColorAt(const Point3D& point) const override {
            // Implement texture sampling based on the point's UV coordinates
        }
};

#endif