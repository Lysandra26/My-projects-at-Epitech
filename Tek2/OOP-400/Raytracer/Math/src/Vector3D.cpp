/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

namespace Math {

    Vector3D::Vector3D(): x(0), y(0), z(0)
    {}

    Vector3D::Vector3D(double x, double y, double z): x(x), y(y), z(z)
    {}

    Vector3D::Vector3D(const Vector3D& other): x(other.x), y(other.y), z(other.z)
    {}

    Vector3D::Vector3D(Vector3D&& other) noexcept : x(std::move(other.x)), y(std::move(other.y)), z(std::move(other.z))
    {}

    double Vector3D::lenght() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    double Vector3D::dot(const Vector3D& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3D& Vector3D::operator= (const Vector3D& other)
    {
        x = other.x; y = other.y; z = other.z; return *this;
    }

    Vector3D& Vector3D::operator= (Vector3D& other) noexcept
    {
        x = std::move(other.x); y = std::move(other.y); z = std::move(other.z); return *this;
    }

    Vector3D Vector3D::operator- (const Vector3D& other) const
    {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D& Vector3D::operator-= (const Vector3D& other)
    {
        x -= other.x; y -= other.y; z -= other.z; return *this;
    }

    Vector3D Vector3D::operator* (const Vector3D& other) const
    {
        return Vector3D(x * other.x, y * other.y, z * other.z);
    }

    Vector3D& Vector3D::operator*= (const Vector3D& other)
    {
        x *= other.x; y *= other.y; z *= other.z; return *this;
    }

    Vector3D Vector3D::operator/ (const Vector3D& other) const
    {
        return Vector3D(x / other.x, y / other.y, z / other.z);
    }

    Vector3D& Vector3D::operator/= (const Vector3D& other)
    {
        x /= other.x; y /= other.y; z /= other.z; return *this;
    }

    Vector3D Vector3D::operator* (double scalar) const
    {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    Vector3D& Vector3D::operator*= (double scalar)
    {
        x *= scalar; y *= scalar; z *= scalar; return *this;
    }

    Vector3D Vector3D::operator/ (double scalar) const
    {
        return Vector3D(x / scalar, y / scalar, z / scalar);
    }

    Vector3D& Vector3D::operator/= (double scalar)
    {
        x /= scalar; y /= scalar; z /= scalar; return *this;
    }

}