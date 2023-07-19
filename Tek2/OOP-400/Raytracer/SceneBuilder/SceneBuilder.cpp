/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** SceneBuilder
*/

#include "Header.hpp"

int main(int ac, char **av)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <scene_file.cfg>" << std::endl;
        return 1;
    }
    std::string sceneFileName = argv[1];
    SceneLoader sceneLoader(sceneFileName);
    Camera camera = sceneLoader.loadCamera();
    std::vector<std::unique_ptr<Primitive>> primitives = sceneLoader.loadPrimitives();
    std::vector<std::unique_ptr<ILight>> lights = sceneLoader.loadLights();
    
    std::vector<Color> imageBuffer(camera.width, camera.height);

    Renderer renderer;
    renderer.render(camera, primitives, lights, imageBuffer);

    // Save the image to a file
    std::string outputFileName = "output.ppm";
    PPMWriter::saveImage(outputFileName, imageBuffer, camera.width, camera.height);

    return 0;
}

