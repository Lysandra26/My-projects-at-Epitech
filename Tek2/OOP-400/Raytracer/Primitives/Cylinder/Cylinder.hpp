/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
    #define CYLINDER_HPP_
    #include "Header.hpp"

namespace RayTracer {
namespace Primitive {
class Cylinder: public IPrimitive {
    public:

        Cylinder(const std::vector<double>& parameters, const Material& material);

        bool intersect(const Ray& ray, Intersection& intersection) const override;
   
        const Material& getMaterial() const override { return material; }
        Vector3D getNormal(const Point3D& point) const override;

    private:
    
        RayTracer::Math::Point3D center;
        double radius;
        double height;
        Material material;
};
}
}

#endif /* !CYLINDER_HPP_ */