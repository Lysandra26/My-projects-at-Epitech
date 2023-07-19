/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** SpherePlugin
*/

#ifndef SPHEREPLUGIN_HPP_
    #define SPHEREPLUGIN_HPP_
    #include "PrimitivePlugin.hpp"
    #include "Sphere.hpp"

class SpherePlugin: public PrimitivePlugin {
    public:
        std::shared_ptr<Primitive> createSphere() override
        {
            return std::make_shared<Sphere>();
        }
};

#endif /* !SPHEREPLUGIN_HPP_ */
