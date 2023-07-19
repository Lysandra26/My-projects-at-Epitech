/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Headers
*/

#ifndef HEADERS_HPP_
#define HEADERS_HPP_

    #include <fstream>
    #include <vector>
    #include <memory>

    #include "Vector3D.hpp"
    #include "Matrix.hpp"
    #include "Point3D.hpp"
    #include "VectorN.hpp"
    #include "Rectangle3D.hpp"

    #include "Color.hpp"
    #include "Material.hpp"

    #include "Camera.hpp"
    #include "Ray.hpp"
    #include "Intersection.hpp" 

    #include "IPrimitive.hpp"
    #include "PrimitiveFactory.hpp"
    #include "Sphere.hpp"
    #include "Plane.hpp"
    
    #include "ILight.hpp"
    #include "AmbientLight.hpp"
    #include "DirectionalLight.hpp"
    #include "LightFactory.hpp"

    #include "Scene.hpp"
    #include "ISceneBuilder.hpp"
    #include "Parsing.hpp"
    #include "SceneLoader.hpp"
    #include "SceneBuilder.hpp"

    #include "PPMWritter.hpp"
    


#endif /* !HEADERS_HPP_ */
