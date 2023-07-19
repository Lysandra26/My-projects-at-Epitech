/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_
    #include "../IDisplayModule.hpp"
    #include <ncurses.h>
    #include <iostream>
    #include <cstring>
    #include <fstream>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <string>
    #include <curses.h>
    #include <vector>
    #include <sstream>
    #include <chrono>
    #include <thread>
    #include <unistd.h>
    #include <cstdlib>
    #include <ctime>
    #include <math.h>

namespace Arcade
{
    class Ncurses : public IDisplayModule
    {
        public:
            Ncurses();
            virtual ~Ncurses();

            void createWindow(unsigned int width, unsigned int height, const std::string &title) override;
            void destroyWindow() override;
            void clear() const override;
            void display() const override;

            void drawRectangle(Vector2f position, Vector2f size, Color color) const override;
            void drawCircle(Vector2f position, float radius, Color color) const override;
            void drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const override;
            void drawSprite(Vector2f position, const std::string &path) const override;

            bool isOpen() const override;
            Input getInput() override;

        protected:
        private:
            int getColor(Color color) const;

            WINDOW* _win;
            Ncurses *m_window;

            unsigned int _width;
            unsigned int _height;
    };
    extern "C" IDisplayModule *entryPoint();
}

#endif /* !NCURSES_HPP_ */
