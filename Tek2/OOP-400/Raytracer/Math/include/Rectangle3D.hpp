/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_
    #include "Vector3D.hpp"
    #include "Point3D.hpp"
    #include <stdexcept>

namespace RayTracer
{
    class Rectangle3D
    {
        public:
            Math::Point3D origin;
            Math::Vector3D bottom_side;
            Math::Vector3D left_side;

            Rectangle3D(const Math::Point3D& origin, const Math::Vector3D& bottom_side, const Math::Vector3D& left_side);
            Math::Point3D pointAt(double u, double v) const;
    };
}

#endif /* !RECTANGLE_HPP_ */
