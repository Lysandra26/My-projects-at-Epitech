/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

namespace Raytracer {
namespace Light {
    
    DirectionalLight::DirectionalLight(const Vector3D& direction, const Color& color)
    : direction(direction.normalized()), color(color)
    {}


    Color DirectionalLight::calculateLight(const Intersection& intersection, const Scene& scene) const override
    {
        Vector3D intersectionPosition = intersection.getRay().getPoint(intersection.getDistance());
        Vector3D normal = intersection.getNormal();
        Vector3D viewDirection = (intersection.getRay().getOrigin() - intersectionPosition).normalized();
        Vector3D reflectionDirection = (2 * normal.dot(direction) * normal - direction).normalized();

        // Check for shadows
        Ray shadowRay(intersectionPosition, direction);
        if (scene.getClosestIntersection(shadowRay).hasHit()) {
            return Color(0, 0, 0);  // return black if in shadow
        }

        double diffuseIntensity = std::max(0.0, normal.dot(direction));
        double specularIntensity = std::pow(std::max(0.0, viewDirection.dot(reflectionDirection)), intersection.getMaterial().getShininess());
        Color diffuseComponent = intersection.getMaterial().getDiffuseColor() * color * diffuseIntensity;
        Color specularComponent = intersection.getMaterial().getSpecularColor() * color * specularIntensity;
        return diffuseComponent + specularComponent;
    }
}
}