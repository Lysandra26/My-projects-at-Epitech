/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Sphere
*/

#include "Sphere.hpp"

namespace RayTracer {
namespace Primitive {

    Sphere::Sphere(const std::vector<double>& parameters, const Material& material)
    : center(parameters[0], parameters[1], parameters[2]), radius(parameters[3]), material(material)
    {}

    bool Sphere::intersect(const Ray& ray, Intersection& intersection) const
    {
        Math::Vector3D oc = ray.origin - center;
        double a = ray.direction.dot(ray.direction);
        double b = 2.0 * oc.dot(ray.direction);
        double c = oc.dot(oc) - radius * radius;
        double discriminant = (b * b) - 4 * a * c;

        if (discriminant < 0) {
            return false;
        } else {
            double t = (-b - sqrt(discriminant)) / (2.0 * a);
            Math::Point3D intersectionPoint = ray.pointAtParameter(t);
            Math::Vector3D normal = (intersectionPoint - center).normalized();
            intersection = Intersection(intersectionPoint, normal, material);
            return true;
        }
    }
}
}
