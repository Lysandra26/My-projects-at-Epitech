#include "Sfml.hpp"
#include <SFML/Graphics.hpp>

/**
 * @brief Defines the entry point of the library
 *
 * @return IDisplayModule* The entry point
*/

extern "C" IDisplayModule *entryPoint()
{
    return new Arcade::Sfml();
}

/**
 * @brief Defines the colors
 *
 * @param color Color to define
*/

sf::Color Arcade::Sfml::getColor(Color color) const
{
    if (color == Color::RED) return sf::Color(255, 0, 0, 255);
    if (color == Color::GREEN) return sf::Color(0, 255, 0, 255);
    if (color == Color::BLUE) return sf::Color(0, 0, 255, 255);
    if (color == Color::YELLOW) return sf::Color(255, 255, 0, 255);
    if (color == Color::MAGENTA) return sf::Color(255, 0, 255, 255);
    if (color == Color::CYAN) return sf::Color(0, 255, 255, 255);
    if (color == Color::WHITE) return sf::Color(255, 255, 255, 255);
    return sf::Color(0, 0, 0, 255);
}

/**
 * @brief Get the Input object
 *
 * @return Input The input
*/

Input Arcade::Sfml::getInput()
{
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return Input::ESCAPE;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                return Input::ESCAPE;
            if (event.key.code == sf::Keyboard::Up)
                return Input::UP;
            if (event.key.code == sf::Keyboard::Down)
                return Input::DOWN;
            if (event.key.code == sf::Keyboard::Left)
                return Input::LEFT;
            if (event.key.code == sf::Keyboard::Right)
                return Input::RIGHT;
            if (event.key.code == sf::Keyboard::Return)
                return Input::ENTER;
            if (event.key.code == sf::Keyboard::Space)
                return Input::SPACE;
            if (event.key.code == sf::Keyboard::BackSpace)
                return Input::BACKSPACE;
        }
    }
    return Input::NONE;
}

/**
 * @brief Construct a new Sfml object
 *
*/

Arcade::Sfml::Sfml()
{
}

/**
 * @brief Destroy the Sfml object
 *
*/

Arcade::Sfml::~Sfml()
{
    m_window.close();
}

/**
 * @brief Destroy the Window object
 *
*/

void Arcade::Sfml::destroyWindow()
{
    m_window.close();
}

/**
 * @brief Create a Window object
 *
 * @param width Width of the window
 * @param height Height of the window
 * @param title Title of the window
*/

void Arcade::Sfml::createWindow(unsigned int width, unsigned int height, const std::string &title)
{
    const_cast<sf::RenderWindow&>(m_window).create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
}

/**
 * @brief Clear the window
 *
*/

void Arcade::Sfml::clear() const
{
    const_cast<sf::RenderWindow&>(m_window).clear();
}

/**
 * @brief Display the window
 *
*/

void Arcade::Sfml::display() const
{
    const_cast<sf::RenderWindow&>(m_window).display();
}

/**
 * @brief Draw a rectangle
 *
 * @param pos Position of the rectangle
 * @param size Size of the rectangle
 * @param color Color of the rectangle
*/

void::Arcade::Sfml::drawRectangle(Vector2f pos, Vector2f size, Color color) const
{
    sf::RectangleShape rectangle(sf::Vector2f(size.x, size.y));
    rectangle.setPosition(pos.x, pos.y);
    rectangle.setFillColor(getColor(color));
    const_cast<sf::RenderWindow&>(m_window).draw(rectangle);
}

/**
 * @brief Draw a circle
 *
 * @param pos Position of the circle
 * @param radius Radius of the circle
 * @param color Color of the circle
*/

void Arcade::Sfml::drawCircle(Vector2f pos, float radius, Color color) const
{
    sf::CircleShape circle(radius);
    circle.setPosition(pos.x, pos.y);
    circle.setFillColor(getColor(color));
    const_cast<sf::RenderWindow&>(m_window).draw(circle);
}

/**
 * @brief Draw a text
 *
 * @param pos Position of the text
 * @param text Text to display
 * @param size Size of the text
 * @param color Color of the text
*/

void Arcade::Sfml::drawText(Vector2f pos, const std::string &text, unsigned int size, Color color) const
{
    sf::Font font;
    if (!font.loadFromFile("Resources/Fonts/arcade_i.ttf"))
        throw std::runtime_error("Error while loading font");
    sf::Text sfText(text, font, size);
    sfText.setPosition(pos.x, pos.y);
    sfText.setFillColor(getColor(color));
    const_cast<sf::RenderWindow&>(m_window).draw(sfText);
}

/**
 * @brief Draw a sprite
 *
 * @param pos Position of the sprite
 * @param path Path of the sprite
*/

void Arcade::Sfml::drawSprite(Vector2f pos, const std::string &path) const
{
    sf ::Texture texture;
    texture.loadFromFile(path);
    sf::Sprite sprite(texture);
    sprite.setPosition(pos.x, pos.y);
    const_cast<sf::RenderWindow&>(m_window).draw(sprite);
}

/**
 * @brief Check if the window is open
 *
 * @return true If the window is open
 * @return false If the window is closed
*/

bool Arcade::Sfml::isOpen() const
{
    if (m_window.isOpen())
        return true;
    return false;
}