/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** IDisplayModule.hpp
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <iostream>
#include <string>
#include "../Utils.hpp"

class IDisplayModule
{
public:
    virtual ~IDisplayModule() = default;

    virtual void createWindow(unsigned int width, unsigned int height, const std::string &title) = 0;
    virtual void destroyWindow() = 0;
    virtual void clear() const = 0;
    virtual void display() const = 0;

    virtual void drawRectangle(Vector2f position, Vector2f size, Color color) const = 0;
    virtual void drawCircle(Vector2f position, float radius, Color color) const = 0;
    virtual void drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const = 0;
    virtual void drawSprite(Vector2f position, const std::string &path) const = 0;

    virtual bool isOpen() const = 0;
    virtual Input getInput() { return Input::NONE; }
};

#endif /* !IDISPLAYMODULE_HPP_ */
