/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

namespace RayTracer {
namespace Primitive {

    Cylinder::Cylinder(const std::vector<double>& parameters, const Material& material)
    : center(parameters[0], parameters[1], parameters[2]), radius(parameters[3]), height(parameters[4]), material(material)
    {}

    bool Cylinder::intersect(const Ray& ray, Intersection& intersection) const
    {
        Math::Vector3D axis = Vector3D(0, 1, 0);
        Math::Point3D top_center = center + Vector3D(0, height/2, 0);
        Math::Point3D bottom_center = center - Vector3D(0, height/2, 0);
        
        double t_top = (top_center - ray.origin).dot(axis) / ray.direction.dot(axis);
        Math::Point3D top_intersection_point = ray.pointAtParameter(t_top);
        double t_bottom = (bottom_center - ray.origin).dot(axis) / ray.direction.dot(axis);
        Math::Point3D bottom_intersection_point = ray.pointAtParameter(t_bottom);

        if (t_top < 0 && t_bottom < 0) {
            return false;
        } else if (t_top < 0) {
            Math::Vector3D normal = (bottom_intersection_point - bottom_center).normalized();
            intersection = Intersection(bottom_intersection_point, normal, material);
            return true;
        } else if (t_bottom < 0) {
            Math::Vector3D normal = (top_intersection_point - top_center).normalized();
            intersection = Intersection(top_intersection_point, normal, material);
            return true;
        }

        Math::Point3D intersection_point = t_top < t_bottom ? top_intersection_point : bottom_intersection_point;
        double d = (intersection_point - center).length();
        if (d > radius) {
            return false;
        }

        Math::Vector3D normal = getNormal(intersection_point);
        intersection = Intersection(intersection_point, normal, material);
        return true;
    }

    Vector3D Cylinder::getNormal(const Point3D& point) const
    {
        Math::Vector3D axis = Vector3D(0, 1, 0);
        Math::Vector3D normal = (point - center).normalized();
        normal = normal - axis * normal.dot(axis);
        return normal.normalized();
    }
}
}