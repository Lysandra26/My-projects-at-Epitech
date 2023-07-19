/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_
    #include "Vector3D.hpp"

namespace Math {
    class Point3D {
        public:
            double x, y, z;

            Point3D();
            Point3D(double x, double y, double z);
            Point3D(const Point3D& other);
            Point3D(Point3D&& other) noexcept;

            Point3D& operator=(const Point3D& other);
            Point3D& operator=(Point3D&& other) noexcept;
            Point3D operator+(const Vector3D& vector) const;
            Vector3D operator-(const Point3D& other) const;
        protected:
        private:
    };
}

#endif /* !POINT3D_HPP_ */
