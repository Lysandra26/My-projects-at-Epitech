/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** AmbiantLight
*/

#ifndef AMBIANTLIGHT_HPP_
#define AMBIANTLIGHT_HPP_

class AmbientLight : public ILight {
    public:
        AmbientLight(const Color& color):
        : color(color) {}

        Color calculateLight(const Intersection& intersection, const Scene& scene) const override {
            // Calculate the light contribution at the intersection point for an ambient light
            // This would typically involve multiplying the light color by the object's material
            // properties (e.g., ambient color)

            // Placeholder: return the light color for now
            return color;
        }

    private:
        Color color;
};


#endif /* !AMBIANTLIGHT_HPP_ */
