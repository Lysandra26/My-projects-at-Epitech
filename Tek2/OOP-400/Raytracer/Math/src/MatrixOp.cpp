/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-bsraytracer-sydney.luong
** File description:
** Matrix
*/

#include "Matrix.hpp"

namespace Math
{

    Matrix::Matrix(): values{} {}

    Matrix::Matrix(const std::array<double, 16>& values) : values(values) {}

    Matrix::Matrix(const Matrix& other) : values(other.values)
    {}

    Matrix::Matrix(Matrix&& other) noexcept: values(std::move(other.values))
    {}

    Matrix& Matrix::operator=(const Matrix& other)
    {
        values = other.values;
        return *this;
    }

    Matrix& Matrix::operator=(Matrix&& other) noexcept
    {
        values = std::move(other.values);
        return *this;
    }

    Matrix Matrix::operator+(const Matrix& other) const
    {
        std::array<double, 16> resultValues;

        for (size_t i = 0; i < 16; ++i) {
            resultValues[i] = values[i] + other.values[i];
        }
        return Matrix(resultValues);
    }

    Matrix& Matrix::operator+=(const Matrix& other)
    {
        for (size_t i = 0; i < 16; ++i) {
            values[i] += other.values[i];
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix& other) const
    {
        std::array<double, 16> resultValues;
        
        for (size_t i = 0; i < 16; ++i) {
            resultValues[i] = values[i] - other.values[i];
        }
        return Matrix(resultValues);
    }

    Matrix& Matrix::operator-=(const Matrix& other)
    {
        for (size_t i = 0; i < 16; ++i) {
            values[i] -= other.values[i];
        }
        return *this;
    }

    Matrix Matrix::operator*(const Matrix& other) const
    {
        Matrix result;

        for (size_t row = 0; row < 4; ++row) {
            for (size_t col = 0; col < 4; ++col) {
                double sum = 0;
                for (size_t k = 0; k < 4; ++k) {
                    sum += (*this)(row, k) * other(k, col);
                }
                result(row, col) = sum;
            }
        }
        return result;
    }

    Matrix& Matrix::operator*=(const Matrix& other)
    {
        Matrix result = *this * other;
        values = result.values;
        return *this;
    }

    Matrix Matrix::operator*(double scalar) const
    {
        std::array<double, 16> resultValues;

        for (size_t i = 0; i < 16; ++i) {
            resultValues[i] = values[i] * scalar;
        }
        return Matrix(resultValues);
    }

    Matrix& Matrix::operator*=(double scalar)
    {
        for (size_t i = 0; i < 16; ++i) {
            values[i] *= scalar;
        }
        return *this;
    }

    Matrix Matrix::operator/(double scalar) const
    {
        std::array<double, 16> resultValues;

        for (size_t i = 0; i < 16; ++i) {
            resultValues[i] = values[i] / scalar;
        }
        return Matrix(resultValues);
    }

    Matrix& Matrix::operator/=(double scalar)
    {
        for (size_t i = 0; i < 16; ++i) {
            values[i] /= scalar;
        }
        return *this;
    }

    double& Matrix::operator()(size_t row, size_t col)
    {
        return values[row * 4 + col];
    }

    const double& Matrix::operator()(size_t row, size_t col) const
    {
        return values[row * 4 + col];
    }
}

