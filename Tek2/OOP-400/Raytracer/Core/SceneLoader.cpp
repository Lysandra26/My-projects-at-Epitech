/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** SceneLoader
*/

#include "SceneLoader.hpp"
#include "Parsing.hpp"
#include <libconfig.h++>
#include "PrimitiveFactory.hpp"
#include "LightFactory.hpp"

SceneLoader::SceneLoader(const std::string& sceneFileName)
    : sceneFileName(sceneFileName) {}


std::unique_ptr<Camera> SceneLoader::loadCamera() {
        const libconfig::Setting& cameraSetting = config.lookup("camera");
    return parseCamera(cameraSetting);
}

std::vector<std::unique_ptr<Primitive>> SceneLoader::loadPrimitives() {
    libconfig::Config config;
    config.readFile(sceneFileName.c_str());
    const libconfig::Setting& root = config.getRoot();
    const libconfig::Setting& primitivesSetting = root["primitives"];

    std::vector<std::unique_ptr<Primitive>> primitives;
    parsePrimitives(primitivesSetting, primitives);

    return primitives;
}

std::vector<std::unique_ptr<Light>> SceneLoader::loadLights() {
    std::vector<std::unique_ptr<Light>> lights;
    try {
        const libconfig::Setting& lightsSetting = cfg.lookup("lights");
        parseLights(lightsSetting, lights);
    } catch (const libconfig::SettingNotFoundException& nfex) {
        throw std::invalid_argument("Lights section not found in the scene file.");
    }
    return lights;
}

