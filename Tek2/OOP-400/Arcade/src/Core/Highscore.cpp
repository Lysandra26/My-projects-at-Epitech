/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Highscore
*/

#include "Core.hpp"
#include "Resources.hpp"
#include "../Libs/SFML/Sfml.hpp"
#include "../Libs/SDL2/SDL2.hpp"
#include "../Libs/NCURSES/ncurses.hpp"

void Core::HighScoreDisplay()
{
    _graphics->drawText({(1920 - 420), 150}, "HighScore", 40, Color::WHITE);
    if (_highScore.Selection == 1) {
        _graphics->drawText({(1920 - 450), 240}, "Nibbler :", 30, Color::WHITE);
        for (size_t i = 0; i < _highScore.NibblerPlayer.size(); i++) {
            _graphics->drawText({(1920 - 100), static_cast<float>(300 + (i * 30))}, _highScore.NibblerScore[i], 20, Color::WHITE);
            if (i < 9)
                _graphics->drawText({(1920 - 450), static_cast<float>(300 + (i * 30))}, std::to_string(i + 1) + " - " + _highScore.NibblerPlayer[i], 20, Color::WHITE);
            else
                _graphics->drawText({(1920 - 470), static_cast<float>(300 + (i * 30))}, std::to_string(i + 1) + " - " + _highScore.NibblerPlayer[i], 20, Color::WHITE);
        }
    } else if (_highScore.Selection == 2) {
        _graphics->drawText({(1920 - 450), 240}, "Snake :", 30, Color::WHITE);
        for (size_t i = 0; i < _highScore.SnakePlayer.size(); i++) {
            _graphics->drawText({(1920 - 100), static_cast<float>(300 + (i * 30))}, _highScore.SnakeScore[i], 20, Color::WHITE);
            if (i < 9)
                _graphics->drawText({(1920 - 450), static_cast<float>(300 + (i * 30))}, std::to_string(i + 1) + " - " + _highScore.SnakePlayer[i], 20, Color::WHITE);
            else
                _graphics->drawText({(1920 - 470), static_cast<float>(300 + (i * 30))}, std::to_string(i + 1) + " - " + _highScore.SnakePlayer[i], 20, Color::WHITE);
        }
    }
}

void Core::sortHighScore()
{
    for (size_t i = 0; i < _highScore.SnakeScore.size(); i++) {
        for (size_t j = i + 1; j < _highScore.SnakeScore.size(); j++) {
            if (std::stoi(_highScore.SnakeScore[i]) < std::stoi(_highScore.SnakeScore[j])) {
                std::swap(_highScore.SnakeScore[i], _highScore.SnakeScore[j]);
                std::swap(_highScore.SnakePlayer[i], _highScore.SnakePlayer[j]);
            }
        }
    }

    for (size_t i = 0; i < _highScore.NibblerScore.size(); i++) {
        for (size_t j = i + 1; j < _highScore.NibblerScore.size(); j++) {
            if (std::stoi(_highScore.NibblerScore[i]) < std::stoi(_highScore.NibblerScore[j])) {
                std::swap(_highScore.NibblerScore[i], _highScore.NibblerScore[j]);
                std::swap(_highScore.NibblerPlayer[i], _highScore.NibblerPlayer[j]);
            }
        }
    }
}

void Core::getHighScore()
{
    _highScore.SnakePlayer.clear();
    _highScore.SnakeScore.clear();
    _highScore.NibblerPlayer.clear();
    _highScore.NibblerScore.clear();

    std::ifstream inputFile("Resources/Score/highScore.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::string gameName;
            std::string playerName;
            int score;
            std::stringstream ss(line);
            ss >> gameName >> playerName >> score;
            if (gameName == "Snake") {
                _highScore.SnakePlayer.push_back(playerName);
                _highScore.SnakeScore.push_back(std::to_string(score));
            } else if (gameName == "Nibbler") {
                _highScore.NibblerPlayer.push_back(playerName);
                _highScore.NibblerScore.push_back(std::to_string(score));
            }
        }
        inputFile.close();
        sortHighScore();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}
