/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** MatrixMethod
*/

#include "Matrix.hpp"

namespace Math
{
    Matrix Matrix::identity()
    {
        return Matrix({
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        });
    }

    Matrix Matrix::translation(double tx, double ty, double tz)
    {
        return Matrix({
            1, 0, 0, tx,
            0, 1, 0, ty,
            0, 0, 1, tz,
            0, 0, 0, 1
        });
    }

    Matrix Matrix::rotationX(double angle)
    {
        double rad = angle * M_PI / 180.0;
        double cosAngle = std::cos(rad);
        double sinAngle = std::sin(rad);

        return Matrix({
            1, 0, 0, 0,
            0, cosAngle, -sinAngle, 0,
            0, sinAngle, cosAngle, 0,
            0, 0, 0, 1
        });
    }

    Matrix Matrix::rotationY(double angle)
    {
        double rad = angle * M_PI / 180.0;
        double cosAngle = std::cos(rad);
        double sinAngle = std::sin(rad);

        return Matrix({
            cosAngle, 0, sinAngle, 0,
            0, 1, 0, 0,
            -sinAngle, 0, cosAngle, 0,
            0, 0, 0, 1
        });
    }

    Matrix Matrix::rotationZ(double angle)
    {
        double rad = angle * M_PI / 180.0;
        double cosAngle = std::cos(rad);
        double sinAngle = std::sin(rad);

        return Matrix({
            cosAngle, -sinAngle, 0, 0,
            sinAngle, cosAngle, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        });
    }

    Matrix Matrix::scaling(double sx, double sy, double sz)
    {
        return Matrix({
            sx, 0, 0, 0,
            0, sy, 0, 0,
            0, 0, sz, 0,
            0, 0, 0, 1
        });
    }
    
    Matrix Matrix::shear(double sxy, double sxz, double syx, double syz, double szx, double szy)
    {
        return Matrix({
            1, sxy, sxz, 0,
            syx, 1, syz, 0,
            szx, szy, 1, 0,
            0, 0, 0, 1
        });
    }
}