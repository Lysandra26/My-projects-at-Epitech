/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Point3D
*/

#include "Point3D.hpp"

namespace Math {

    Point3D::Point3D(): x(0), y(0), z(0)
    {}

    Point3D::Point3D(double x, double y, double z): x(x), y(y), z(z)
    {}

    Point3D::Point3D(const Point3D& other): x(other.x), y(other.y), z(other.z)
    {}

    Point3D::Point3D(Point3D&& other) noexcept: x(std::move(other.x)), y(std::move(other.y)), z(std::move(other.z))
    {}

    Point3D& Point3D::operator= (const Point3D& other)
    {
        x = other.x; y = other.y; z = other.z; return *this;
    }

    Point3D& Point3D::operator= (Point3D&& other) noexcept
    {
        x = std::move(other.x); y = std::move(other.y); z = std::move(other.z); return *this;
    }

    Point3D Point3D::operator+ (const Vector3D& vector) const
    {
        return Point3D(x + vector.x, y + vector.y, z + vector.z);
    }

    Vector3D Point3D::operator-(const Point3D& other) const
    {
    return Math::Vector3D(x - other.x, y - other.y, z - other.z);
    }
}