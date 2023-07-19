/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** LightPlugin
*/

#ifndef LIGHTPLUGIN_HPP_
#define LIGHTPLUGIN_HPP_

class LightPlugin: public Plugin {
    public:
        virtual std::shared_ptr<Light> createLight() = 0;


    protected:
    private:
};

#endif /* !LIGHTPLUGIN_HPP_ */
