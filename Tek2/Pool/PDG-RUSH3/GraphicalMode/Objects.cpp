/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH3-william.andreo
** File description:
** Objects.cpp
*/

#include "mySfml.hpp"

void DrawTime(sf::RenderWindow& window, sf::Text time)
{
    time.setPosition(10,10);
    time.setFillColor(sf::Color::White);
    window.draw(time);
}

void DrawHostUser(sf::RenderWindow& window, sf::Text host, sf::Text user)
{
    sf::Font font;
    font.loadFromFile("./GraphicalMode/arial_narrow_7.ttf");
    sf::Text text("Username : ", font, 22);
    sf::Text text2("Hostname : ", font, 22);
    text.setPosition(10,260);
    text.setFillColor(sf::Color::White);
    text2.setPosition(10,310);
    text2.setFillColor(sf::Color::White);
    user.setPosition(120,260);
    user.setFillColor(sf::Color::White);
    host.setPosition(120,310);
    host.setFillColor(sf::Color::White);
    window.draw(text);
    window.draw(user);
    window.draw(text2);
    window.draw(host);
}

void DrawCores(sf::RenderWindow& window, sf::Text core)
{
    sf::Font font;
    font.loadFromFile("./GraphicalMode/arial_narrow_7.ttf");
    sf::Text text("Core : ", font, 22);
    text.setPosition(10, 410);
    text.setFillColor(sf::Color::White);
    core.setPosition(90,410);
    core.setFillColor(sf::Color::White);
    window.draw(text);
    window.draw(core);
}

void DrawOpNameVersion(sf::RenderWindow& window, sf::Text name, sf::Text version)
{
    sf::Font font;
    font.loadFromFile("./GraphicalMode/arial_narrow_7.ttf");
    sf::Text text("System Name : ", font, 22);
    sf::Text text2("System Version : ", font, 22);
    text.setPosition(10,510);
    text.setFillColor(sf::Color::White);
    text2.setPosition(10,560);
    text2.setFillColor(sf::Color::White);
    name.setPosition(170, 510);
    name.setFillColor(sf::Color::White);
    version.setPosition(180,560);
    version.setFillColor(sf::Color::White);
    window.draw(text);
    window.draw(text2);
    window.draw(name);
    window.draw(version);
}

void DrawCpuPer(sf::RenderWindow& window, sf::Text per)
{
    sf::Font font;
    font.loadFromFile("./GraphicalMode/arial_narrow_7.ttf");
    sf::Text text("Cpu percentage :         %", font, 22);
    text.setPosition(10,660);
    text.setFillColor(sf::Color::White);
    per.setPosition(190,660);
    per.setFillColor(sf::Color::White);
    window.draw(text);
    window.draw(per);
}

void DrawCpuFreq(sf::RenderWindow& window, sf::Text freq)
{
    sf::Font font;
    font.loadFromFile("./GraphicalMode/arial_narrow_7.ttf");
    sf::Text text("Cpu frequence :          MHz", font, 22);
    text.setPosition(10,760);
    text.setFillColor(sf::Color::White);
    freq.setPosition(165,760);
    freq.setFillColor(sf::Color::White);
    window.draw(text);
    window.draw(freq);
}

void DrawCpuNumber(sf::RenderWindow& window, sf::Text num)
{
    sf::Font font;
    font.loadFromFile("./GraphicalMode/arial_narrow_7.ttf");
    sf::Text text("Cpu number :", font, 22);
    text.setPosition(10,860);
    text.setFillColor(sf::Color::White);
    num.setPosition(140,860);
    num.setFillColor(sf::Color::White);
    window.draw(text);
    window.draw(num);
}

void DrawRam(sf::RenderWindow& window, sf::Text ram)
{
    sf::Font font;
    font.loadFromFile("./GraphicalMode/arial_narrow_7.ttf");
    sf::Text text("Ram :", font, 22);
    text.setPosition(10,960);
    text.setFillColor(sf::Color::White);
    ram.setPosition(70,960);
    ram.setFillColor(sf::Color::White);
    window.draw(text);
    window.draw(ram);
}

info::~info()
{
}
