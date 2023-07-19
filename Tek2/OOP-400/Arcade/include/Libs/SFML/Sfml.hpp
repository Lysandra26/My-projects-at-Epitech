/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Sfml.hpp
*/

#pragma once

#include "../IDisplayModule.hpp"
#include <SFML/Graphics.hpp>

namespace Arcade
{
    class Sfml : public IDisplayModule
    {
        public:
            Sfml();
            virtual ~Sfml();

            void createWindow(unsigned int width, unsigned int height, const std::string &title) override;
            void destroyWindow() override;
            void clear() const override;
            void display() const override;

            void drawRectangle(Vector2f pos, Vector2f size, Color color) const override;
            void drawCircle(Vector2f pos, float radius, Color color) const override;
            void drawText(Vector2f pos, const std::string &text, unsigned int size, Color color) const override;
            void drawSprite(Vector2f pos, const std::string &path) const override;

            bool isOpen() const;
            Input getInput();

        private:
            sf::RenderWindow m_window;
            sf::Color getColor(Color color) const;
    };
    extern "C" IDisplayModule *entryPoint();
}