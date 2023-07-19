/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** AmbiantLight
*/

#include "AmbiantLight.hpp"

AmbientLight::AmbientLight(const Color& color): color(color)
{}

Color calculateLight(const Intersection& intersection, const Scene& scene) const override {
    // Calculate the light contribution at the intersection point for an ambient light
    // by multiplying the light color by the object's material
    // properties (like ambient color)

    // Get the ambient color of the material at the intersection point
    Color ambientColor = intersection.material->ambientColor;

    // Multiply the ambient color by the light color
    Color result = color * ambientColor;

    return result;
}


