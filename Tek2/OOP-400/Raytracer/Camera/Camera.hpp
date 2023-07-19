/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_
    #include "Point3D.hpp"
    #include "Vector3D.hpp"
    #include "Rectangle3D.hpp"
    #include "Sphere.hpp"
    #include "Ray.hpp"

namespace RayTracer {
class Camera {
public:
    Camera(int width, int height, const Point3D& position, const Vector3D& rotation, double fieldOfView)
        : width(width), height(height), position(position), rotation(rotation), fieldOfView(fieldOfView) {}

private:
    int width;
    int height;
    Point3D position;
    Vector3D rotation;
    double fieldOfView;
};
}


#endif /* !CAMERA_HPP_ */
