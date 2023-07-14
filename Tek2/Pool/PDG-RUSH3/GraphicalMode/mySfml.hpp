/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGRUSH3-william.andreo
** File description:
** mySfml
*/

#ifndef MYSFML_HPP_
    #define MYSFML_HPP_
    #include <iostream>
    #include <SFML/Window/Window.hpp>
    #include <SFML/Config.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Graphics/Font.hpp>

class info {
public:
    info(std::string name, int size_x, int size_y, int pose_x, int pose_y);
    ~info();
    std::string _name;
    sf::RectangleShape _rect;
    int size_x;
    int size_y;
    bool draw;
private:
};

int startSfml(void);
void DrawTime(sf::RenderWindow& window, sf::Text time);
void DrawCores(sf::RenderWindow& window, sf::Text core);
void DrawHostUser(sf::RenderWindow& window, sf::Text host, sf::Text user);
void DrawOpNameVersion(sf::RenderWindow& window, sf::Text name, sf::Text version);
void DrawCpuPer(sf::RenderWindow& window, sf::Text per);
void DrawCpuFreq(sf::RenderWindow& window, sf::Text freq);
void DrawCpuNumber(sf::RenderWindow& window, sf::Text num);
void DrawRam(sf::RenderWindow& window, sf::Text ram);

#endif /* !MYSFML_HPP_ */
