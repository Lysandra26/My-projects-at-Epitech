/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** ISceneBuilder
*/

#ifndef ISCENEBUILDER_HPP_
#define ISCENEBUILDER_HPP_


namespace RayTracer {
    namespace Builder {
        class ISceneBuilder {
            public:
                virtual ~ISceneBuilder() = default;
                virtual void registerPrimitivePlugin(const std::string& type, std::function<std::unique_ptr<Primitive>(const PluginParameters&)> createFunction) = 0;
            protected:
            private:
        };
    }
}

#endif /* !ISCENEBUILDER_HPP_ */
