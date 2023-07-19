/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Ncurses.cpp
*/

#include "ncurses.hpp"

/**
 * @brief Defines the entry point of the library
 *
 * @return IDisplayModule* The entry point
*/

extern "C" IDisplayModule *entryPoint()
{
    return new Arcade::Ncurses();
}

/**
 * @brief Construct a new Ncurses object
 *
*/

Arcade::Ncurses::Ncurses()
{
    initscr();
    curs_set(0);
    noecho();
    nodelay(stdscr, true);
    cbreak();
    keypad(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);
}

/**
 * @brief Destroy the Ncurses object
 *
*/

Arcade::Ncurses::~Ncurses() {}

/**
 * @brief Create a Window object
 *
 * @param width Width of the window
 * @param height Height of the window
 * @param title Title of the window
*/

void Arcade::Ncurses::createWindow(unsigned int width, unsigned int height, const std::string &title)
{
    _width = width;
    _height = height;
    std::string useless = title;

    _win = newwin(width, height, 0, 0);
}

/**
 * @brief Destroy the Window object
 *
*/

void Arcade::Ncurses::destroyWindow()
{
    curs_set(1);
    keypad(stdscr, FALSE);
    endwin();
}

/**
 * @brief Clear the window
 *
*/

void Arcade::Ncurses::clear() const
{
    werase(_win);
}

/**
 * @brief Display the window
 *
*/

void Arcade::Ncurses::display() const
{
    wrefresh(_win);
    // flushinp();
}

/**
 * @brief Draw a rectangle
 *
 * @param pos Position of the rectangle
 * @param size Size of the rectangle
 * @param color Color of the rectangle
*/

void Arcade::Ncurses::drawRectangle(Vector2f position, Vector2f size, Color color) const
{
    (void)size;
    wattron(_win, COLOR_PAIR(getColor(color)));

    mvwprintw(_win, position.y , position.x, " ");

    wattroff(_win, COLOR_PAIR(getColor(color)));

}

/**
 * @brief Draw a circle
 *
 * @param pos Position of the circle
 * @param radius Radius of the circle
 * @param color Color of the circle
*/

void Arcade::Ncurses::drawCircle(Vector2f position, float radius, Color color) const
{
    wattron(_win, COLOR_PAIR(getColor(color)));

    for (int i = -radius; i <= radius; i++) {
        for (int j = - radius; j <= radius; j++) {
            int distance = sqrt(i * i + j * j);
            if (distance <= radius) {
                mvaddch(position.y + i, position.x + j, ' ');
            }
        }
    }

    wattroff(_win, COLOR_PAIR(getColor(color)));
}

/**
 * @brief Draw text
 *
 * @param pos Position of the text
 * @param text Text to draw
 * @param size Size of the text
 * @param color Color of the text
*/

void Arcade::Ncurses::drawText(Vector2f position, const std::string &text, unsigned int size, Color color) const
{
    (void)size;
    wattron(_win, COLOR_PAIR(getColor(color)));
    mvwprintw(_win, position.y / 20, position.x / 9, "%s", text.c_str());
    wattroff(_win, COLOR_PAIR(getColor(color)));
}

/**
 * @brief Draw a sprite
 *
 * @param pos Position of the sprite
 * @param path Path of the sprite
*/

void Arcade::Ncurses::drawSprite(Vector2f position, const std::string &path) const
{
    std::string temp = path;
    mvwprintw(_win, position.y, position.x, " ");
}

/**
 * @brief Check if the window is open
 *
 * @return true If the window is open
 * @return false If the window is closed
*/

bool Arcade::Ncurses::isOpen() const
{
    if (_win) {
        return true;
    }
    return false;
}

/**
 * @brief Get the Input object
 *
 * @return Input The input
*/

int Arcade::Ncurses::getColor(Color color) const
{
    switch (color) {
        case Color::WHITE:
            return 1;
        case Color::RED:
            return 2;
        case Color::GREEN:
            return 3;
        case Color::YELLOW:
            return 4;
        case Color::BLUE:
            return 5;
        case Color::MAGENTA:
            return 6;
        case Color::CYAN:
            return 7;
        case Color::BLACK:
            return 8;
        case Color::TRANSPARENT:
            return 9;
        default:
            return 1;
    }
}

Input Arcade::Ncurses::getInput()
{
    int c = getch();

    if (c == KEY_UP) {
        return Input::UP;
    } else if (c == KEY_DOWN) {
        return Input::DOWN;
    } else if (c == KEY_LEFT) {
        return Input::LEFT;
    } else if (c == KEY_RIGHT) {
        return Input::RIGHT;
    } else if (c == SPACE) {
        return Input::SPACE;
    } else if (c == 27) {
        return Input::ESCAPE;
    } else if (c == '\n') {
        return Input::ENTER;
    } else if (c == 122) {
        return Input::Z;
    } else if (c == 113) {
        return Input::Q;
    } else if (c == 115) {
        return Input::S;
    } else if (c == 100) {
        return Input::D;
    } else if (c == 97) {
        return Input::A;
    } else if (c == 101) {
        return Input::E;
    } else if (c == KEY_BACKSPACE) {
        return Input::BACKSPACE;
    }
    return Input::NONE;
}
