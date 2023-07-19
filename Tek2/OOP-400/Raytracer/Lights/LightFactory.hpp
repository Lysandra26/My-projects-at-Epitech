/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** LightFactory
*/

#ifndef LIGHTFACTORY_HPP_
#define LIGHTFACTORY_HPP_

class LightFactory {
public:
    std::unique_ptr<ILight> createLight(const std::string& lightType, const std::vector<double>& parameters) {
        if (lightType == "directional") {
            // parame are in the order: x, y, z, r, g, b
            Vector3D direction(parameters[0], parameters[1], parameters[2]);
            Color color(parameters[3], parameters[4], parameters[5]);
            return std::make_unique<DirectionalLight>(direction, color);
        } else if (lightType == "ambient") {
            // param are in the order: r, g, b, intensity
            Color color(parameters[0], parameters[1], parameters[2]);
            float intensity = static_cast<float>(parameters[3]);
            return std::make_unique<AmbientLight>(color, intensity);
        }
        
        // more light types here
        throw std::invalid_argument("Invalid light type: " + lightType);
    }
};

#endif /* !LIGHTFACTORY_HPP_ */
