/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** PrimitiveFactory
*/

#ifndef PRIMITIVEFACTORY_HPP_
#define PRIMITIVEFACTORY_HPP_
#include "Header.hpp"

namespace RayTracer {
class PrimitiveFactory {
public:
    std::unique_ptr<Primitive> createPrimitive(const std::string& primitiveType, const std::vector<double>& parameters, const Material& material) {
        if (primitiveType == "sphere") {
            return std::make_unique<Sphere>(parameters, material);
        } else if (primitiveType == "plane") {
            return std::make_unique<Plane>(parameters, material);
        // } else if (primitiveType == "cone") {
        //     return std::make_unique<Cone>(parameters, material);
        // }
        } else {
            throw std::invalid_argument("Invalid primitive type: " + primitiveType);
    }
};
}
}

// HOW TO USE THE FACTORY:
// PrimitiveFactory factory;
// std::unique_ptr<Primitive> sphere = factory.createPrimitive("sphere", { /* sphere parameters */ });
// std::unique_ptr<Primitive> plane = factory.createPrimitive("plane", { /* plane parameters */ });

#endif /* !PRIMITIVEFACTORY_HPP_ */
