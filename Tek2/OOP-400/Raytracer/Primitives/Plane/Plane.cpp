/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Plane
*/

// Plane.cpp
#include "Plane.hpp"

namespace RayTracer {
namespace Primitive {

    Plane::Plane(const std::vector<double>& parameters, const Material& material, const Color& color) 
    : distance(parameters[1]), material(material), color(color)
    {
        switch (static_cast<int>(parameters[0])) {
            case 0:
                normal = Vector3D(1, 0, 0);
                break;
            case 1:
                normal = Vector3D(0, 1, 0);
                break;
            case 2:
                normal = Vector3D(0, 0, 1);
                break;
            default:
                throw std::invalid_argument("Invalid axis value for Plane. Expected 0 (for X), 1 (for Y) or 2 (for Z).");
        }
    }

    bool Plane::intersect(const Ray& ray, Intersection& intersection) const
    {
        double denominator = normal.dot(ray.direction);

        // Check if the ray is parallel to the plane
        if (std::abs(denominator) > kEpsilon) { 
            // Calculate the t parameter for the ray at the intersection point
            double t = (normal * distance - ray.origin).dot(normal) / denominator;
            
            // Check if the intersection happens along the ray's direction
            if (t >= 0) {
                // Compute intersection data
                intersection.t = t;
                intersection.point = ray.origin + ray.direction * t;
                intersection.normal = normal;
                intersection.material = material;
                intersection.color = color;
                return true;
            }
        }
        return false;
    }
}
}
