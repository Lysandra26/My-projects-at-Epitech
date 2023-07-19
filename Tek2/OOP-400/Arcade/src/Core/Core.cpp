/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Core
*/

#include "Core.hpp"
#include "Resources.hpp"
#include "../Libs/SFML/Sfml.hpp"
#include "../Libs/SDL2/SDL2.hpp"
#include "../Libs/NCURSES/ncurses.hpp"

/**
 * @brief Construct a new Core object
*/

Core::Core() {}

/**
 * @brief Destroy the Core object
*/

Core::~Core()
{
    Utils utils;

    utils.my_dlclose(_lib);
    if (_game != nullptr)
        utils.my_dlclose(_game);
}

/**
 * @brief Get the Lib object
 *
 * @param path The path of the lib
*/

std::string Core::getLib(std::string path)
{
    std::string selectedLib = "";
    char delimiter = '_';
    std::string extension = ".so";

    size_t start_pos = path.find(delimiter);
    if (start_pos != std::string::npos)
    {
        size_t end_pos = path.find(extension);
        if (end_pos != std::string::npos)
        {
            selectedLib = path.substr(start_pos + 1, end_pos - start_pos - 1);
            return selectedLib;
        }
    }
    return selectedLib;
}

void Core::getAllLib()
{
    Lib libs;
    Game games;

    std::string folder_path = "lib/";
    std::string target_extension = ".so";

    for (const auto &entry : std::filesystem::directory_iterator(folder_path)) {
        if (entry.is_regular_file() && entry.path().extension() == target_extension) {
            std::string filename = entry.path().filename().string();
            if (filename == libs.sdl2 || filename == libs.ncurses || filename == libs.sfml) {
                _lib_files.push_back(filename);
            } else if (filename == games.snake || filename == games.nibbler) {
                _game_files.push_back(filename);
            }
        }
    }
}

int Core::getPlayerName()
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Enter your name: " << std::endl;
    std::cout << " " << std::endl;
    std::cin >> _playerName;
    std::cout << " " << std::endl;
    std::cout << "Hello " << _playerName << "!" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    return 0;
}

int Core::launchArcade(std::string lib)
{
    Utils utils;
    std::string target = "lib/";
    size_t position = lib.find(target);
    std::string result;
    std::string defLib = "./lib/arcade_sfml.so";
    std::string defLibResult;

    if (position != std::string::npos)
        result = lib.substr(position + target.length());

    if (position != std::string::npos)
        defLibResult = defLib.substr(position + target.length());

    for (const auto &element : _lib_files) {
        if (element == result) {
            _lib = utils.my_dlopen(lib);
            _libs[result] = _lib;
            this->_graphics = utils.my_dlsym<IDisplayModule>(_lib, "entryPoint");
        }
    }

    for (const auto &element : _game_files) {
        if (element == result) {
            _libIsSelected = true;
            _gameIsSelected = true;

            _lib = utils.my_dlopen(defLib);
            _libs[defLibResult] = _lib;
            this->_graphics = utils.my_dlsym<IDisplayModule>(_lib, "entryPoint");

            _gamelib = utils.my_dlopen(lib);
            _libs[result] = _gamelib;
            this->_game = utils.my_dlsym<IGamesModule>(_gamelib, "entryPoint");
        }
    }

    if (this->_graphics) {
        this->_graphics->createWindow(1920, 1080, "Arcade");
        MenuLoop();
    }
    return 0;
}

void Core::MenuInput()
{
    Input input = _graphics->getInput();

    if (input == Input::UP) {
        if (!_libIsSelected) {
            if (_libSelection > 0)
                _libSelection--;
        }
        if (_libIsSelected && !_gameIsSelected) {
            if (_gameSelection > 0) {
                _gameSelection--;
                _highScore.Selection != 1 ? _highScore.Selection-- : _highScore.Selection;
            }
        }
        _graphics->clear();
    }

    if (input == Input::DOWN) {
        if (!_libIsSelected) {
            if (_libSelection < _lib_files.size() - 1)
                _libSelection++;
        }
        if (_libIsSelected && !_gameIsSelected) {
            if (_gameSelection < _game_files.size() - 1) {
                _gameSelection++;
                _highScore.Selection != _highScore.nbOfGames ? _highScore.Selection++ : _highScore.Selection;
            }
        }
        _graphics->clear();
    }

    if (input == Input::ENTER) {
        if (!_libIsSelected && !_gameIsSelected)
            SwitchLib();
        else if (_libIsSelected && !_gameIsSelected)
            SwitchGame();
    }

    if (input == Input::BACKSPACE) {
        if (_libIsSelected && !_gameIsSelected)
            _libIsSelected = false;
        else if (_libIsSelected && _gameIsSelected) {
            _gameIsSelected = false;
        }
    }

    if (input == Input::ESCAPE) {
        _graphics->destroyWindow();
        exit(0);
    }
}

Color Core::setSelectionColor(bool isSelected, int selection, int i)
{
    if (isSelected)
        return Color::GREEN;
    return (i == selection) ? Color::RED : Color::WHITE;
}

void Core::MenuDisplay()
{
    _graphics->drawRectangle({0, 0}, {1920, 1080}, Color::WHITE);
    _graphics->drawText({(1920/2) - (290), 20}, "Arcade", 100, Color::BLACK);

    _graphics->drawRectangle({0, 0}, {500, 1080}, Color::BLUE);
    _graphics->drawRectangle({1920 - 500, 0}, {500, 1080}, Color::RED);

    for (size_t i = 0; i < _lib_files.size(); i++) {
        _graphics->drawText({50, static_cast<float>(220 + (i * 80))}, getLib(_lib_files[i]), 40, setSelectionColor(_libIsSelected, _libSelection, i));
    }

    for (size_t i = 0; i < _game_files.size(); i++) {
        _graphics->drawText({50, static_cast<float>(650 + (i * 80))}, getLib(_game_files[i]), 40, !_libIsSelected ? Color::WHITE : setSelectionColor(_gameIsSelected, _gameSelection, i));
    }

    HighScoreDisplay();
}

void Core::SwitchGame()
{
    Utils utils;

    _gameIsSelected = true;

    for (size_t i = 0; i < _game_files.size(); i++) {
        if (_game_files[i] == _game_files[_gameSelection]) {
            _gamelib = CheckOpenedGame(i);
            _libs[_game_files[_gameSelection]] = _gamelib;
            this->_game = utils.my_dlsym<IGamesModule>(_gamelib, "entryPoint");
            _game->setState(GameState::RUNNING);
            _game->init(_graphics, _playerName);
        }
    }
}

void *Core::CheckOpenedGame(int i)
{
    Utils utils;

    auto it = _libs.find(_game_files[_gameSelection]);
    if (it != _libs.end()) {
        return it->second;
    }
    _libs[_game_files[i]] = _gamelib;
    return utils.my_dlopen("lib/" + _game_files[i]);
}

void *Core::CheckOpenedLib(int i)
{
    Utils utils;

    auto it = _libs.find(_lib_files[_libSelection]);
    if (it != _libs.end()) {
        return it->second;
    }
    _libs[_lib_files[i]] = _lib;
    return utils.my_dlopen("lib/" + _lib_files[i]);;
}

void Core::SwitchLib()
{
    Utils utils;

    _libIsSelected = true;
    _graphics->destroyWindow();
    for (size_t i = 0; i < _lib_files.size(); i++) {
        if (_lib_files[i] == _lib_files[_libSelection]) {
            _lib = CheckOpenedLib(i);
            this->_graphics = utils.my_dlsym<IDisplayModule>(_lib, "entryPoint");
        }
    }
    if (this->_graphics) {
        this->_graphics->createWindow(1920, 1080, "Arcade");
        MenuLoop();
    }
}

int Core::MenuLoop()
{
    getHighScore();
    while (_graphics->isOpen()) {
        _graphics->clear();
        if (!_gameIsSelected)
            MenuInput();
        MenuDisplay();
        if (_libIsSelected == true && _gameIsSelected == true)
             gameLoop(_graphics->getInput());
        _graphics->display();
    }
    return 0;
}

int Core::gameLoop(Input input)
{
    if (_game->getState() == GameState::RUNNING) {
        _game->handleInput(input);
        _game->update();
        _game->render();
    }
    if (_game->getState() == GameState::GAME_OVER) {
        std::cout << "GAME OVER" << std::endl;
        _gameIsSelected = false;
        return 0;
    }
    return 0;
}
