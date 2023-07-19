/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDL2
*/

#include "SDL2.hpp"

/**
 * @brief Entry point of the library
 *
 * @return IDisplayModule* The entry point
*/

extern "C" IDisplayModule *entryPoint()
{
    return new Arcade::SDL2();
}

/**
 * @brief Defines the colors
 *
 * @param color Color to define
*/

SDL_Color Arcade::SDL2::getColor(Color color) const
{
    if (color == Color::RED) return SDL_Color{255, 0, 0, 255};
    if (color == Color::GREEN) return SDL_Color{0, 255, 0, 255};
    if (color == Color::BLUE) return SDL_Color{0, 0, 255, 255};
    if (color == Color::YELLOW) return SDL_Color{255, 255, 0, 255};
    if (color == Color::MAGENTA) return SDL_Color{255, 0, 255, 255};
    if (color == Color::CYAN) return SDL_Color{0, 255, 255, 255};
    if (color == Color::WHITE) return SDL_Color{255, 255, 255, 255};
    return SDL_Color{0, 0, 0, 255};
}

/**
 * @brief Get the Input object
 *
 * @return Input The input
*/

Input Arcade::SDL2::getInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return Input::ESCAPE;
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                return Input::ESCAPE;
            if (event.key.keysym.sym == SDLK_UP)
                return Input::UP;
            if (event.key.keysym.sym == SDLK_DOWN)
                return Input::DOWN;
            if (event.key.keysym.sym == SDLK_LEFT)
                return Input::LEFT;
            if (event.key.keysym.sym == SDLK_RIGHT)
                return Input::RIGHT;
            if (event.key.keysym.sym == SDLK_RETURN)
                return Input::ENTER;
            if (event.key.keysym.sym == SDLK_SPACE)
                return Input::SPACE;
            if (event.key.keysym.sym == SDLK_BACKSPACE)
                return Input::BACKSPACE;
        }
    }
    return Input::NONE;
}

/**
 * @brief Construct a new SDL2 object
*/

Arcade::SDL2::SDL2() {}

/**
 * @brief Destroy the SDL2 object
*/

Arcade::SDL2::~SDL2()
{
    Arcade::SDL2::destroyWindow();
}

/**
 * @brief Create the window
 *
 * @param width Width of the window
 * @param height Height of the window
 * @param title Title of the window
*/

void Arcade::SDL2::createWindow(unsigned int width, unsigned int height, const std::string &title)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("SDL_Init Error: " + std::string(SDL_GetError()));

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
        throw std::runtime_error("IMG_Init Error: " + std::string(IMG_GetError()));

    _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (_window == nullptr)
        throw std::runtime_error("SDL_CreateWindow Error: " + std::string(SDL_GetError()));

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr)
        throw std::runtime_error("SDL_CreateRenderer Error: " + std::string(SDL_GetError()));
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
}

/**
 * @brief Destroy the window
*/

void Arcade::SDL2::destroyWindow()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

/**
 * @brief Clear the window
 *
*/

void Arcade::SDL2::clear() const
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

/**
 * @brief Display the window
 *
*/

void Arcade::SDL2::display() const
{
    SDL_RenderPresent(_renderer);
}

/**
 * @brief Draw a rectangle
 *
 * @param pos Position of the rectangle
 * @param size Size of the rectangle
 * @param color Color of the rectangle
*/

void Arcade::SDL2::drawRectangle(Vector2f pos, Vector2f size, Color color) const
{
    SDL_Rect rect = {static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(size.x), static_cast<int>(size.y)};
    SDL_SetRenderDrawColor(_renderer, getColor(color).r, getColor(color).g, getColor(color).b, getColor(color).a);
    SDL_RenderFillRect(_renderer, &rect);
}

/**
 * @brief Draw a circle
 *
 * @param pos Position of the circle
 * @param radius Radius of the circle
 * @param color Color of the circle
*/

void Arcade::SDL2::drawCircle(Vector2f pos, float radius, Color color) const
{
    for (float angle = 0; angle < 2 * M_PI; angle += 0.01) {
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        Arcade::SDL2::drawRectangle({pos.x + x, pos.y + y}, {1, 1}, color);
    }
}

/**
 * @brief Draw a text
 *
 * @param pos Position of the text
 * @param text Text to display
 * @param size Size of the text
 * @param color Color of the text
*/

void Arcade::SDL2::drawText(Vector2f pos, const std::string &text, unsigned int size, Color color) const
{
    if (TTF_Init() != 0)
        throw std::runtime_error("TTF_Init Error: " + std::string(TTF_GetError()));

    TTF_Font *font = TTF_OpenFont("Resources/Fonts/arcade_i.ttf", size);
    if (font == nullptr)
        throw std::runtime_error("TTF_OpenFont Error: " + std::string(TTF_GetError()));

    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), getColor(color));
    if (surface == nullptr)
        throw std::runtime_error("TTF_RenderText_Solid Error: " + std::string(TTF_GetError()));

    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (texture == nullptr)
        throw std::runtime_error("SDL_CreateTextureFromSurface Error: " + std::string(SDL_GetError()));

    SDL_Rect rect = {static_cast<int>(pos.x), static_cast<int>(pos.y), surface->w, surface->h};
    SDL_RenderCopy(_renderer, texture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

/**
 * @brief Draw a sprite
 *
 * @param pos Position of the sprite
 * @param path Path of the sprite
*/

void Arcade::SDL2::drawSprite(Vector2f pos, const std::string &path) const
{
    SDL_Surface *surface = IMG_Load(path.c_str());
    if (surface == nullptr)
        throw std::runtime_error("IMG_Load Error: " + std::string(IMG_GetError()));

    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (texture == nullptr)
        throw std::runtime_error("SDL_CreateTextureFromSurface Error: " + std::string(SDL_GetError()));

    SDL_Rect rect = {static_cast<int>(pos.x), static_cast<int>(pos.y), surface->w, surface->h};
    SDL_RenderCopy(_renderer, texture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

/**
 * @brief Check if the window is open
 *
 * @return true If the window is open
 * @return false If the window is closed
*/

bool Arcade::SDL2::isOpen() const
{
    if (_window) {
        return true;
    }
    return false;
}
