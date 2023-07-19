/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_
    #include <cmath>


namespace Math {

    class Vector3D {
        public:
            double x, y, z;

            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(const Vector3D& other);
            Vector3D(Vector3D&& other) noexcept;

            Vector3D& operator=(const Vector3D& other);
            Vector3D& operator=(Vector3D& other) noexcept;

            Vector3D operator+(const Vector3D& other) const;
            Vector3D& operator+=(const Vector3D& other);

            Vector3D operator-(const Vector3D& other) const;
            Vector3D& operator-=(const Vector3D& other);

            Vector3D operator*(const Vector3D& other) const;
            Vector3D& operator*=(const Vector3D& other);

            Vector3D operator/(const Vector3D& other) const;
            Vector3D& operator/=(const Vector3D& other);

            Vector3D operator*(double scalar) const;
            Vector3D& operator*=(double scalar);

            Vector3D operator/(double scalar) const;
            Vector3D& operator/=(double scalar);

            double lenght() const;
            double dot(const Vector3D& other) const;

        protected:
        private:
    };
}

#endif /* !VECTOR3D_HPP_ */
