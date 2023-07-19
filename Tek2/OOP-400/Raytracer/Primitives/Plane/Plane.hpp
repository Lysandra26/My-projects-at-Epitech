/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Plane
*/

#ifndef PLANE_HPP_
    #define PLANE_HPP_
    #include "Header.hpp"

namespace Raytracer {
namespace Primitive {
class Plane: public IPrimitive {
    public:

        Plane(const std::vector<double>& parameters, const Material& material);
    
        bool intersect(const Ray& ray, Intersection& intersection) const override;

        const Material& getMaterial() const override { return material; }
        Vector3D getNormal(const Point3D& point) const override { return normal; }
      
    private:
        double distance;
        std::string axis; // 0 for X, 1 for Y, 2 for Z
        double position;
        Material material;
};
}
}

#endif /* !PLANE_HPP_ */
