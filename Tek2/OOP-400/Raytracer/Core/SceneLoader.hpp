/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** SceneLoader
*/

#ifndef SCENELOADER_HPP_
#define SCENELOADER_HPP_

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Camera.hpp"
#include "IPrimitive.hpp"
#include "ILight.hpp"

class SceneLoader {
public:
    SceneLoader(const std::string& sceneFileName);
    Camera loadCamera();
    std::vector<std::unique_ptr<Primitive>> loadPrimitives();
    std::vector<std::unique_ptr<ILight>> loadLights();

private:
    std::string sceneFileName;
    std::vector<double> cameraParameters;
};


#endif /* !SCENELOADER_HPP_ */
