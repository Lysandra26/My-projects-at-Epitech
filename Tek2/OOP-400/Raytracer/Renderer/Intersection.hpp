/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Intersection
*/

#ifndef INTERSECTION_HPP_
#define INTERSECTION_HPP_
#include "Header.hpp"

namespace RayTracer {
class Intersection {
    public:
        // Constructor
        Intersection(const Ray& ray, double distance, const Vector3D& normal, const IPrimitive& primitive)
            : ray(ray), distance(distance), normal(normal), primitive(primitive) {}

        bool hasHit() const { return hit; }

        // Getters
        const Ray& getRay() const { return ray; }
        double getDistance() const { return distance; }
        const Vector3D& getNormal() const { return normal; }
        const IPrimitive& getPrimitive() const { return primitive; }

        // Get material properties
        const Material& getMaterial() const { return primitive.getMaterial(); }
        double getReflection() const { return primitive.getMaterial().reflection; }
        double getRefraction() const { return primitive.getMaterial().refraction; }

    private:
        Ray ray;
        double distance;
        Vector3D normal;
        const IPrimitive& primitive;
        bool hit;
};
}

#endif /* !INTERSECTION_HPP_ */
