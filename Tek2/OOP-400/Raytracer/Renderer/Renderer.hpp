/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_
#include "Header.hpp"

namespace RayTracer {
class Renderer {
    public:
        Renderer() = default;
        void render(const Camera& camera, const std::vector<std::unique_ptr<Primitive>>& primitive,
        const std::vector<std::unique_ptr<ILight>>& lights, std::vector<Color>& imageBuffer);
        Color calculateColor(const Ray& ray, const Intersection& intersection, const Scene& scene, int depth) const;
    protected:
    private:
};
}

#endif /* !RENDERER_HPP_ */
