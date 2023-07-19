/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** main
*/

int main()
{
    // Create a concrete implementation of the SceneBuilder
    RayTracer::RayTracerSceneBuilder sceneBuilder;

    // Create a SceneParser and pass the builder to it
    RayTracer::SceneParser sceneParser(sceneBuilder);

    // Parse the scene file
    sceneParser.parse("path/to/scene/file");

    // Retrieve the constructed Scene object from the builder
    RayTracer::Scene scene = sceneBuilder.getScene();

    // Render the scene using rendering algorithm
    // ...

    return 0;
}
