/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** SceneBuilder
*/

#ifndef SCENEBUILDER_HPP_
    #define SCENEBUILDER_HPP_
    #include "ISceneBuilder.hpp"
    #include <unordered_map>

namespace RayTracer {
    namespace Builde {
        class SceneBuilder: public ISceneBuilder {
            public:
                void registerPrimitivePlugin(const std::string& type, std::function<std::unique_ptr<Primitive>(const PluginParameters&)> createFunction) override;
            protected:
            private:
                std::unordered_map<std::string, std::function<std::unique_ptr<Primitive>(const PluginParameters&)>> primitivePluginMap;
        };
    }
}


#endif /* !SCENEBUILDER_HPP_ */
