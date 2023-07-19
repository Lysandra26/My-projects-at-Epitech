/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Matrix
*/

#ifndef MATRIX_HPP_
    #define MATRIX_HPP_
    #include <array>
    #include <cmath>

namespace Math {
    class Matrix {
        public:
            Matrix();
            Matrix(const std::array<double, 16>& values);
            Matrix(const Matrix& other);
            Matrix(Matrix&& other) noexcept;

            Matrix& operator=(const Matrix& other);
            Matrix& operator=(Matrix&& other) noexcept;

            Matrix operator+(const Matrix& other) const;
            Matrix& operator+=(const Matrix& other);
            Matrix operator-(const Matrix& other) const;
            Matrix& operator-=(const Matrix& other);
            Matrix operator*(const Matrix& other) const;
            Matrix& operator*=(const Matrix& other);
            Matrix operator*(double scalar) const;
            Matrix& operator*=(double scalar);
            Matrix operator/(double scalar) const;
            Matrix& operator/=(double scalar);

            double& operator()(size_t row, size_t col);
            const double& operator()(size_t row, size_t col) const;

            static Matrix identity();
            static Matrix translation(double tx, double ty, double tz);
            static Matrix rotationX(double angle);
            static Matrix rotationY(double angle);
            static Matrix rotationZ(double angle);
            static Matrix scaling(double sx, double sy, double sz);
            static Matrix shear(double sxy, double sxz, double syx, double syz, double szx, double szy);

private:
    std::array<double, 16> values;
    };
}

#endif /* !MATRIX_HPP_ */
