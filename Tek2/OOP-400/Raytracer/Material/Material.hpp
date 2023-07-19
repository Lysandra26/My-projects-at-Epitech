/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

// Material interface

namespace RayTracer {
class Material {
    public:
        Color color;
        float transparency;
        float reflection;
        float refraction;
        // Other common properties
        Material()
        : color(255, 255, 255), transparency(0.5), refraction(1.0), reflection(0.5) {}

        Material(const Color& color, float transparency, float refraction, float reflection)
        : color(color), transparency(transparency), refraction(refraction), reflection(reflection) {}

        virtual Color getColorAt(const Point3D& point) const {
            return color;
        }

        const Color& getDiffuseColor() const { return color; }
        const Color& getSpecularColor() const { return color * reflection; }
        float getTransparency() const { return transparency; }
        float getReflection() const { return reflection; }
        float getRefraction() const { return refraction; }
};
}

#endif /* !MATERIAL_HPP_ */
