/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_
#include "Header.hpp"

namespace RayTracer {
namespace Light {
class DirectionalLight:public ILights {
    public:
        DirectionalLight(const Vector3D& direction, const Color& color);
        Color calculateLight(const Intersection& intersection, const Scene& scene) const override;
    private:
        Math::Vector3D direction;
        Color color;
};
}
}

#endif /* !DIRECTIONALLIGHT_HPP_ */
