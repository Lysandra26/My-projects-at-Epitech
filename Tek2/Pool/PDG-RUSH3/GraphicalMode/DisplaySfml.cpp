/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGRUSH3-william.andreo
** File description:
** DisplaySfml
*/

#include "mySfml.hpp"
#include "../src/IMonitorModule.hpp"

int startSfml(void)
{
    sf::RenderWindow window;
    sf::Event event;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::View view;
    bool space = true;
    bool _Time = true;
    bool _Core = true;
    bool _Names = true;
    bool _Op = true;
    bool _Cpu = true;
    bool _Ram = true;

    texture.loadFromFile("./GraphicalMode/image.jpg");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(1, 1));
    sf::Font font;
    font.loadFromFile("./GraphicalMode/arial_narrow_7.ttf");

    window.create(sf::VideoMode(1920, 1080), "MyGKrellm");
    window.setFramerateLimit(60);
    view.setSize(1920, 1080);
    view.setCenter(960, 540);
    while (window.isOpen())
    {
        IMonitorModule module;
        struct utsname osinfo;
        uname(&osinfo);
        sysinfo(&module.info);
        sf::Text time(module.getTime(), font, 22);
        sf::Text username(module.username, font, 22);
        sf::Text hostname(module.hostname, font, 22);
        sf::Text cores(std::to_string(module.varGetCore), font, 22);
        sf::Text Opname(osinfo.sysname, font, 22);
        sf::Text OpVersion(osinfo.version, font, 22);
        sf::Text CpuPer(std::to_string(module.cpuPercentage), font, 22);
        sf::Text CpuFreq(std::to_string(module.cpuFrequency), font, 22);
        sf::Text CpuNum(module.cpuNumber.c_str(), font, 22);
        sf::Text Ram(std::to_string(module.info.freeram / (1024 * 1024)), font, 22);
        sf::Text Tuto("1: Hide Time 2: Hide Names 3: Hide Core 4: Hide System 5: Hide CPU 6: Hide RAM\nA: Show Time B: Show Names C: Show Core D: Show System E: Show CPU F: Show RAM", font, 22);
        Tuto.setPosition(0, 1000);
        Tuto.setFillColor(sf::Color::White);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && view.getCenter().y > 540) {
                view.move(0, -10);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && view.getCenter().y < 1080) {
                view.move(0, 10);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && space == false) {
                space = true;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && space == true) {
                space = false;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _Time == false) {
                _Time = true;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && _Time == true) {
                _Time = false;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && _Names == false) {
                _Names = true;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && _Names == true) {
                _Names = false;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && _Core == false) {
                _Core = true;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && _Core == true) {
                _Core = false;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _Op == false) {
                _Op = true;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && _Op == true) {
                _Op = false;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && _Cpu == false) {
                _Cpu = true;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && _Cpu == true) {
                _Cpu = false;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && _Ram == false) {
                _Ram = true;
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && _Ram == true) {
                _Ram = false;
                continue;
            }
        }
        window.setView(view);
        window.clear();
        window.draw(sprite);
        if (space == true) {
            if ( _Time == true)
                DrawTime(window, time);
            if ( _Names == true)
                DrawHostUser(window, hostname, username);
            if ( _Core == true)
                DrawCores(window, cores);
            if ( _Op == true)
                DrawOpNameVersion(window, Opname, OpVersion);
            if ( _Cpu == true) {
                DrawCpuPer(window, CpuPer);
                DrawCpuFreq(window, CpuFreq);
                DrawCpuNumber(window, CpuNum);
            }
            if ( _Ram == true)
                DrawRam(window, Ram);
        }
        window.draw(Tuto);
        window.display();
    }
    return 0;
}
