/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** IPrimitives
*/

#ifndef IPRIMITIVES_HPP_
    #define IPRIMITIVES_HPP_
    #include "Header.hpp"

namespace RayTracer {
namespace Primitive {
class IPrimitive {
    public:        
        virtual ~IPrimitive()= default;
        virtual bool intersect(const Ray& ray, Intersection& intersection) const = 0;
        virtual Vector3D getNormal(const Vector3D& point) const = 0;
        virtual const Material& getMaterial() const = 0;
    protected:
    private:
};
}
}


#endif /* !IPRIMITIVES_HPP_ */
