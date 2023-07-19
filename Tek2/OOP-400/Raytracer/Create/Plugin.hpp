/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Plugin
*/

#ifndef PLUGIN_HPP_
    #define PLUGIN_HPP_

class Plugin {
public:
    virtual ~Plugin() {}
    virtual void initialize() = 0;
    virtual void cleanup() = 0;
};

#endif /* !PLUGIN_HPP_ */
