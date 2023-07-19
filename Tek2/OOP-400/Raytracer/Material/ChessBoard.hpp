/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** ChessBoard
*/
#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP
#include "Material.hpp"

class CheckerboardMaterial : public Material {
public:
    Color color1, color2;
    float size;

    CheckerboardMaterial(const Color& color1, const Color& color2, float size) {
        this->color1 = color1;
        this->color2 = color2;
        this->size = size;
    }

    Color getColorAt(const Point3D& point) const override {
        // Implement checkerboard pattern based on the point's coordinates
    }
};

#endif
