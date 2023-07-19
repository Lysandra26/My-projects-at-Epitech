/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Ray
*/

#ifndef RAY_HPP_
    #define RAY_HPP_
    #include "Header.hpp"

namespace RayTracer {
class Ray {
    public:
        Vector3D origin;
        Vector3D direction;

        Ray(const Vector3D& origin, const Vector3D& direction)
        : origin(origin), direction(direction) {}

        shadowRay();

        Point3D getPoint(double t) const { return origin + t * direction * direction; }
        const Point3D& getOrigin() const { return origin; }
        const Vector3D& getDirection() const { return direction; }
    protected:
    private:
};
}

#endif /* !RAY_HPP_ */
