/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_
    #include "Header.hpp"

namespace RayTracer {
namespace Primitive {
class Sphere: public IPrimitive {
    public:

        Sphere(const std::vector<double>& parameters, const Material& material);

        bool intersect(const Ray& ray, Intersection& intersection) const override;
   
        const Material& getMaterial() const override { return material; }
        Vector3D getNormal(const Point3D& point) const override { return (point - center).normalized(); }

    private:
    
        RayTracer::Math::Point3D center;
        double radius;
        Material material;
};
}
}

#endif /* !SPHERE_HPP_ */
