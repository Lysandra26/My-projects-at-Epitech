/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Renderer
*/

#include "Renderer.hpp"

namespace RayTracer {
void Renderer::render(const Camera& camera, const std::vector<std::unique_ptr<Primitive>>& primitives,
                      const std::vector<std::unique_ptr<ILight>>& lights, std::vector<Color>& imageBuffer) {
    // Iterate through all the pixels in the image
    for (int y = 0; y < camera.height; ++y) {
        for (int x = 0; x < camera.width; ++x) {
            // Generate a ray through the pixel
            Ray ray = camera.generateRay(x, y);

            // Find the closest intersection
            Intersection closestIntersection;
            for (const auto& primitive : primitives) {
                Intersection intersection;
                if (primitive->intersect(ray, intersection)) {
                    if (!closestIntersection || intersection.t < closestIntersection.t) {
                        closestIntersection = intersection;
                    }
                }
            }
            // Calculate the color at the intersection
            if (closestIntersection) {
                Color pixelColor;

                for (const auto& light : lights) {
                    pixelColor += light->calculateLight(closestIntersection, primitives);
                }

                // Store the resulting color in the image buffer
                imageBuffer[y * camera.width + x] = pixelColor;
            } else {
                // Background color
                imageBuffer[y * camera.width + x] = Color(0, 0, 0);
            }
        }
    }
}

Color Renderer::calculateColor(const Ray& ray, const Intersection& intersection, const Scene& scene, int depth) const {
    // If the maximum recursion depth is reached, return black
    if (depth >= MAX_RECURSION_DEPTH) {
        return Color(0, 0, 0);
    }

    // Start with the ambient light contribution
    Color color = scene.getAmbientLight() * intersection.getMaterial().getAmbient();

    // Add contribution of each light source
    for (const auto& light : scene.getLights()) {
        Vector3D lightDirection = light->getDirection(intersection.getPosition());
        double lightIntensity = light->getIntensity(intersection.getPosition());

        // Calculate the diffuse contribution
        double diffuseFactor = std::max(intersection.getNormal().dot(lightDirection), 0.0);
        Color diffuseColor = intersection.getMaterial().getDiffuse() * diffuseFactor;

        // Calculate the specular contribution
        Vector3D reflectionDirection = reflect(-lightDirection, intersection.getNormal());
        double specularFactor = std::pow(std::max(ray.getDirection().dot(reflectionDirection), 0.0), intersection.getMaterial().getShininess());
        Color specularColor = intersection.getMaterial().getSpecular() * specularFactor;

        color += lightIntensity * (diffuseColor + specularColor);
    }

    // Calculate the reflection contribution
    if (intersection.getMaterial().getReflection() > 0) {
        Vector3D reflectionDirection = reflect(ray.getDirection(), intersection.getNormal());
        Ray reflectionRay(intersection.getPosition(), reflectionDirection);
        Intersection reflectionIntersection = scene.getClosestIntersection(reflectionRay);
        if (reflectionIntersection.hasHit()) {
            color += intersection.getMaterial().getReflection() * calculateColor(reflectionRay, reflectionIntersection, scene, depth + 1);
        }
    }

    // TODO: Calculate the refraction contribution

    return color;
}
}


