# B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra

# Project : Raytracer

Ray tracing is a technique used to generate realistic digital images by simulating the inverse path of light.
This program is able to generate an image from a file describing the scene.

This programs can generate results with:

- Lights
- Materials
- Primitives
- Camera

The scenes are generate via libconfig formatted files, given as arguments to the program when it start. The result appear in a .ppm generated file.

## Camera :
Takes parameters such has : 
- Resolution, with a width and an height;
- Position, with an x, y, z;
- Rotation, with an x, y, z;
and field of view in degree.

## Lights :
Global lights works with a multiplier and some other point of lights can be added (they need an x, y and z).
Available lights are :
- Ambiant
- Directional
- Colored

## Material :
Available Material are :
- Chess board
- Flat color

## Primitives :
Primitives take a number of parameters such has its position and the color or material.
Available primitives are:
- Cone
- Cylinder
- Plane
- Sphere

## Add more to the raytracer !
If you want to add to this project, verify if the parcing for what you want exist or add it yourself. Then verify the asked parameters and used them in your creation.
