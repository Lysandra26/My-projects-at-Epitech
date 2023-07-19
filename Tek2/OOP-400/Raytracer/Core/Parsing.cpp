/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Parsing
*/

#include "PrimitiveFactory.hpp"
#include <libconfig.h++>
#include <vector>
#include <memory>
#include "Camera.hpp"
#include "Parsing.hpp"

double axisToDouble(const std::string& axis)
{
    if (axis == "X" || axis == "x") {
        return 0.0;
    } else if (axis == "Y" || axis == "y") {
        return 1.0;
    } else if (axis == "Z" || axis == "z") {
        return 2.0;
    } else {
        throw std::invalid_argument("Invalid axis: " + axis);
    }
}
// adding deafult values if the parameters are not provided
std::unique_ptr<Camera> SceneLoader::parseCamera(const libconfig::Setting& cameraSetting)
{
    int width, height;
    double posX, posY, posZ;
    double rotX = 0, rotY = 0, rotZ = 0, fov = 60.0;

    if (cameraSetting.lookupValue("resolution.width", width) &&
        cameraSetting.lookupValue("resolution.height", height) &&
        cameraSetting.lookupValue("position.x", posX) &&
        cameraSetting.lookupValue("position.y", posY) &&
        cameraSetting.lookupValue("position.z", posZ)) {

        cameraSetting.lookupValue("rotation.x", rotX);
        cameraSetting.lookupValue("rotation.y", rotY);
        cameraSetting.lookupValue("rotation.z", rotZ);
        cameraSetting.lookupValue("fieldOfView", fov);

        Point3D position(posX, posY, posZ);
        Vector3D rotation(rotX, rotY, rotZ);

        return std::make_unique<Camera>(width, height, position, rotation, fov);
    } else {
        throw std::invalid_argument("Camera configuration is missing arguments");
    }
}

void parsePrimitives(const libconfig::Setting& primitivesSetting, std::vector<std::unique_ptr<Primitive>>& primitives)
{
    PrimitiveFactory factory;

    // Parse spheres
    const libconfig::Setting& spheres = primitivesSetting["spheres"];
    for (int i = 0; i < spheres.getLength(); ++i) {
        const libconfig::Setting& sphereSetting = spheres[i];

        double x = sphereSetting["x"];
        double y = sphereSetting["y"];
        double z = sphereSetting["z"];
        double r = sphereSetting["r"];
        double rColor = sphereSetting["color"]["r"];
        double gColor = sphereSetting["color"]["g"];
        double bColor = sphereSetting["color"]["b"];

        const libconfig::Setting& materialSetting = sphereSetting["material"];
        double transparency, refraction, reflection;
        materialSetting.lookupValue("transparency", transparency, 0.5);
        materialSetting.lookupValue("refraction", refraction, 1.0);
        materialSetting.lookupValue("reflection", reflection, 0.5);

        Material material(transparency, refraction, reflection);
        std::vector<double> sphereParameters = {x, y, z, r, rColor, gColor, bColor};
        auto sphere = factory.createPrimitive("sphere", sphereParameters, material);
        primitives.push_back(std::move(sphere));
    }

    // Parse planes
    const libconfig::Setting& planes = primitivesSetting["planes"];
    for (int i = 0; i < planes.getLength(); ++i) {
        const libconfig::Setting& planeSetting = planes[i];

        std::string axis = planeSetting["axis"];
        double position = planeSetting["position"];
        double rColor = planeSetting["color"]["r"];
        double gColor = planeSetting["color"]["g"];
        double bColor = planeSetting["color"]["b"];

        const libconfig::Setting& materialSetting = planeSetting["material"];
        double transparency, refraction, reflection;
        materialSetting.lookupValue("transparency", transparency, 0.5);
        materialSetting.lookupValue("refraction", refraction, 1.0);
        materialSetting.lookupValue("reflection", reflection, 0.5);

        Material material(transparency, refraction, reflection);
        std::vector<double> planeParameters = {axisToDouble(axis), position, rColor, gColor, bColor};
        auto plane = factory.createPrimitive("plane", planeParameters, material);
        primitives.push_back(std::move(plane));
    }

    // Parse 

    // Add more primitive parsing

    // Note: Make sure to add exception handling and error checking as needed.
}

void parseLights(const libconfig::Setting& lightsSetting, std::vector<std::unique_ptr<Light>>& lights)
{
    double ambient, diffuse;

    // Parse ambient and diffuse multipliers
    if (lightsSetting.lookupValue("ambient", ambient) && lightsSetting.lookupValue("diffuse", diffuse)) {
        auto ambientLight = std::make_unique<AmbientLight>(Color(ambient, ambient, ambient));
        lights.push_back(std::move(ambientLight));
    }

    // Parse point lights
    const libconfig::Setting& pointLights = lightsSetting["point"];
    for (int i = 0; i < pointLights.getLength(); ++i) {
        const libconfig::Setting& pointLightSetting = pointLights[i];

        double x = pointLightSetting["x"];
        double y = pointLightSetting["y"];
        double z = pointLightSetting["z"];

        auto pointLight = std::make_unique<PointLight>(Point3D(x, y, z), Color(diffuse, diffuse, diffuse));
        lights.push_back(std::move(pointLight));
    }
    // Parse directional lights
    const libconfig::Setting& directionalLights = lightsSetting["directional"];
    for (int i = 0; i < directionalLights.getLength(); ++i) {
        const libconfig::Setting& directionalLightSetting = directionalLights[i];

        double x = directionalLightSetting["x"];
        double y = directionalLightSetting["y"];
        double z = directionalLightSetting["z"];

        // Create a DirectionalLight object
        auto directionalLight = std::make_unique<DirectionalLight>(Vector3D(x, y, z), Color(diffuse, diffuse, diffuse));
        lights.push_back(std::move(directionalLight));
    }
}
