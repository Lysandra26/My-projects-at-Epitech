/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Cone
*/

#include "Cone.hpp"

namespace RayTracer {
namespace Primitive {

    Cone::Cone(const std::vector<double>& parameters, const Material& material)
    : center(parameters[0], parameters[1], parameters[2]), radius(parameters[3]), height(parameters[4]), material(material)
    {}

    bool Cone::intersect(const Ray& ray, Intersection& intersection) const
    {
        double a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z - radius * radius * ray.direction.y * ray.direction.y / (height * height);
        double b = 2.0 * (ray.direction.x * (ray.origin.x - center.x) + ray.direction.z * (ray.origin.z - center.z) - radius * radius * ray.direction.y * (ray.origin.y - center.y) / (height * height));
        double c = (ray.origin.x - center.x) * (ray.origin.x - center.x) + (ray.origin.z - center.z) * (ray.origin.z - center.z) - radius * radius * (ray.origin.y - center.y) * (ray.origin.y - center.y) / (height * height);

        double discriminant = b * b - 4.0 * a * c;

        if (discriminant < 0.0) {
            return false;
        }

        double t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);

        Math::Point3D intersection_point;
        if (t1 > 0.0) {
            intersection_point = ray.pointAtParameter(t1);
        } else if (t2 > 0.0) {
            intersection_point = ray.pointAtParameter(t2);
        } else {
            return false;
        }

        if (intersection_point.y < center.y || intersection_point.y > center.y + height) {
            return false;
        }

        Math::Vector3D normal = getNormal(intersection_point);
        intersection = Intersection(intersection_point, normal, material);
        return true;
    }

    Vector3D Cone::getNormal(const Point3D& point) const
    {
        double slope = radius * (center.y + height - point.y) / (height * height);

        Math::Vector3D normal(point.x - center.x, slope, point.z - center.z);
        return normal.normalized();
    }
}
}