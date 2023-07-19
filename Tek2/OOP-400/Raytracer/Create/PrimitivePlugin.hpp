/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** PrimitivePlugin
*/

#ifndef PRIMITIVEPLUGIN_HPP_
#define PRIMITIVEPLUGIN_HPP_

class PrimitivePlugin: public Plugin {
    public:
        virtual std::shared_ptr<Primitive> createSphere() = 0;
        virtual std::shared_ptr<Primitive> createPlane() = 0;
        virtual std::shared_ptr<Primitive> createLimitedCylinder() = 0;
        virtual std::shared_ptr<Primitive> createLimitedCone() = 0;
        virtual std::shared_ptr<Primitive> createTorus() = 0;
        virtual std::shared_ptr<Primitive> createTangleCube() = 0;
        virtual std::shared_ptr<Primitive> createTriangle() = 0;
        virtual std::shared_ptr<Primitive> loadOBJ(const std::string& filename) = 0;
        virtual std::shared_ptr<Primitive> createFractal() = 0;
        virtual std::shared_ptr<Primitive> createMobiusStrip() = 0;
        virtual std::shared_ptr<Primitive> createCylinder() = 0;
        virtual std::shared_ptr<Primitive> createCone() = 0;
    protected:
    private:
};

#endif /* !PRIMITIVEPLUGIN_HPP_ */
