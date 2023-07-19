/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Ray
*/

#include "Ray.hpp"

namespace RayTracer {

    Ray::Ray(): origin(), direction()
    {}

    Ray::Ray(const Math::Point3D& origin, const Math::Vector3D& direction): origin(origin), direction(direction)
    {}

    Ray::Ray(const Ray& other): origin(other.origin), direction(other.direction)
    {}

    Ray::Ray(Ray&& other) noexcept: origin(std::move(other.origin)), direction(std::move(other.direction))
    {}

    Ray& Ray::operator=(const Ray& other)
    {
        origin = other.origin;
        direction = other.direction;
        return *this;
    }

    Ray& Ray::operator=(Ray&& other) noexcept
    {
        origin = std::move(other.origin);
        direction = std::move(other.direction);
        return *this;
    }
}
