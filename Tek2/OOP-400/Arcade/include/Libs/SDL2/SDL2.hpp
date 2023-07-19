/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL2
*/

#pragma once

#include "../IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <map>

namespace Arcade
{
    class SDL2 : public IDisplayModule
    {
        public:
            SDL2();
            virtual ~SDL2();

            void createWindow(unsigned int width, unsigned int height, const std::string &title) override;
            void destroyWindow() override;
            void clear() const override;
            void display() const override;

            void drawRectangle(Vector2f position, Vector2f size, Color color) const override;
            void drawCircle(Vector2f position, float radius, Color color) const override;
            void drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const override;
            void drawSprite(Vector2f position, const std::string &path) const override;

            bool isOpen() const;
            Input getInput();

        private:
            SDL_Color getColor(Color color) const;

            SDL_Window *_window;
            SDL_Renderer *_renderer;
    };
    extern "C" IDisplayModule *entryPoint();
}
