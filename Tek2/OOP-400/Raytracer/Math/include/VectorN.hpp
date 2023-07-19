/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** VectorN
*/

#ifndef VECTOR3D_HPP_
    #define VECTOR3D_HPP_
    #include <array>
    #include <cmath>
    #include <cstddef>

namespace Math {

    template <std::size_t N>
    class Vector {
        public:
            Vector();
            Vector(const std::array<double, N>& components);
            Vector(const Vector<N>& other);
            Vector(Vector<N>&& other) noexcept;

            Vector<N>& operator=(const Vector<N>& other);
            Vector<N>& operator=(Vector<N>&& other) noexcept;

            double length() const;

            Vector<N> operator+(const Vector<N>& other) const;
            Vector<N>& operator+=(const Vector<N>& other);
            Vector<N> operator-(const Vector<N>& other) const;
            Vector<N>& operator-=(const Vector<N>& other);
            Vector<N> operator*(const Vector<N>& other) const;
            Vector<N>& operator*=(const Vector<N>& other);
            Vector<N> operator/(const Vector<N>& other) const;
            Vector<N>& operator/=(const Vector<N>& other);

            Vector<N> operator*(double scalar) const;
            Vector<N>& operator*=(double scalar);
            Vector<N> operator/(double scalar) const;
            Vector<N>& operator/=(double scalar);

            double dot(const Vector<N>& other) const;

            double& operator[](std::size_t index);
            const double& operator[](std::size_t index) const;

        private:
            std::array<double, N> components;
    };

}

#endif /* !VECTORN_HPP_ */
