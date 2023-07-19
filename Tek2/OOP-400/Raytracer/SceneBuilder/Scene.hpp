/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_
#include "Header.hpp"

namespace RayTracer {
class Scene {
    public:
        Scene();

        void addPrimitive(std::unique_ptr<Primitive::IPrimitive> primitive);
        void addLight(std::unique_ptr<ILight> light);
        void setAmbientLight(const Color& ambientLight);

        const std::vector<std::unique_ptr<Primitive::IPrimitive>>& getPrimitives() const;
        const std::vector<std::unique_ptr<ILight>>& getLights() const;
        const Color& getAmbientLight() const;

        Intersection getClosestIntersection(const Ray& ray) const;

    private:
        std::vector<std::unique_ptr<Primitive::IPrimitive>> primitives;
        std::vector<std::unique_ptr<ILight>> lights;
        Color ambientLight;
};
}

#endif /* !SCENE_HPP_ */
