/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Scene
*/

#include "Scene.h"

namespace RayTracer {
    Scene::Scene() : ambientLight(0, 0, 0) {}

    void Scene::addPrimitive(std::unique_ptr<Primitive::IPrimitive> primitive)
    {
        primitives.push_back(std::move(primitive));
    }

    void Scene::addLight(std::unique_ptr<ILight> light)
    {
        lights.push_back(std::move(light));
    }

    void Scene::setAmbientLight(const Color& ambientLight)
    {
        this->ambientLight = ambientLight;
    }

    const std::vector<std::unique_ptr<Primitive::IPrimitive>>& Scene::getPrimitives() const
    {
        return primitives;
    }

    const std::vector<std::unique_ptr<ILight>>& Scene::getLights() const
    {
        return lights;
    }

    const Color& Scene::getAmbientLight() const
    {
        return ambientLight;
    }

    Intersection Scene::getClosestIntersection(const Ray& ray) const
    {
        Intersection closestIntersection;
        double closestDistance = std::numeric_limits<double>::infinity();

        for (const auto& primitive : primitives) {
            Intersection intersection;
            if (primitive->intersect(ray, intersection)) {
                double distance = (intersection.getPosition() - ray.getOrigin()).length();
                if (distance < closestDistance) {
                    closestIntersection = intersection;
                    closestDistance = distance;
                }
            }
        }
        return closestIntersection;
    }
}

