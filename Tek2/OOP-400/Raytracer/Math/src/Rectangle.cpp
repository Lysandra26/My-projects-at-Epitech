/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Rectangle
*/

#include "Rectangle3D.hpp"

namespace RayTracer
{
    Rectangle3D::Rectangle3D(const Math::Point3D& origin, const Math::Vector3D& bottom_side, const Math::Vector3D& left_side)
    : origin(origin), bottom_side(bottom_side), left_side(left_side)
    {}

    Math::Point3D Rectangle3D::pointAt(double u, double v) const
    {
        if (u < 0 || u > 1 || v < 0 || v > 1) {
            throw std::out_of_range("u and v must be in the range [0, 1]");
        }
        return origin + bottom_side * u + left_side * v;
    }
}

