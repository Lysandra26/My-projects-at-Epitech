/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

class Color {
public:
    Color(float r = 0.0f, float g = 0.0f, float b = 0.0f)
    : r(r), g(g), b(b) {}

    // Overloaded operators
    Color operator+(const Color& other) const
    {
        return Color(r + other.r, g + other.g, b + other.b);
    }

    Color operator*(float scalar) const
    {
        return Color(r * scalar, g * scalar, b * scalar);
    }

    Color operator*(const Color& other) const
    {
        return Color(r * other.r, g * other.g, b * other.b);
    }

    float r, g, b;
};


#endif /* !COLOR_HPP_ */
