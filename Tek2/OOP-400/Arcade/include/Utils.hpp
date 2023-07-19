/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

#pragma once

struct Vector2i {
    int x;
    int y;

    Vector2i(int x, int y) : x(x), y(y) {};
    Vector2i() : x(0), y(0) {};

    bool operator==(const Vector2i &other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Vector2i &other) const {
        return (x != other.x || y != other.y);
    }
};

struct Vector2f {
    float x;
    float y;

    Vector2f(float x, float y) : x(x), y(y) {};
    Vector2f() : x(0), y(0) {};

    bool operator==(const Vector2f &other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Vector2f &other) const {
        return (x != other.x || y != other.y);
    }
};

enum Color {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    TRANSPARENT
};

enum Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ESCAPE,
    ENTER,
    Z,
    Q,
    S,
    D,
    A,
    E,
    BACKSPACE,
    NONE
};

struct Lib {
    std::string sdl2 = "arcade_sdl2.so";
    std::string ncurses = "arcade_ncurses.so";
    std::string sfml = "arcade_sfml.so";
    std::string libcaca = "arcade_libcaca.so";
    std::string allegro5 = "arcade_allegro5.so";
};

struct Game {
    std::string snake = "arcade_snake.so";
    std::string nibbler = "arcade_nibbler.so";
    std::string pacman = "arcade_pacman.so";
    std::string qix = "arcade_qix.so";
    std::string centipede = "arcade_centipede.so";
    std::string solarfox = "arcade_solarfox.so";
};

#endif /* !UTILS_HPP_ */
