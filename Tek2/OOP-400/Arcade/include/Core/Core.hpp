/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include "../Libs/IDisplayModule.hpp"
    #include "../Games/IGamesModule.hpp"
    #include <iostream>
    #include <dlfcn.h>
    #include <string>
    #include <dirent.h>
    #include <fstream>
    #include <filesystem>
    #include <vector>
    #include <map>

class Core {
    public:
        Core();
        ~Core();
        std::string getLib(std::string path);
        void getAllLib();
        int getPlayerName();
        int launchArcade(std::string lib);
        int MenuLoop();
        int gameLoop(Input input);

    protected:
    private:
        Color setSelectionColor(bool isSelected, int selection, int i);

        void *CheckOpenedLib(int i);
        void *CheckOpenedGame(int i);
        void SwitchLib();
        void SwitchGame();

        void MenuInput();
        void MenuDisplay();

        void HighScoreDisplay();
        void getHighScore();
        void sortHighScore();

        IDisplayModule* _graphics;
        IGamesModule* _game;
        void* _lib = 0;
        void* _gamelib = 0;
        std::string _playerName;
        bool _libIsSelected = false;
        bool _gameIsSelected = false;
        size_t _libSelection = 0;
        size_t _gameSelection = 0;

        std::map<std::string, void*> _libs;

        struct {
            int Selection = 1;
            int nbOfGames = 2;

            std::vector<std::string> SnakePlayer;
            std::vector<std::string> SnakeScore;
            std::vector<std::string> NibblerPlayer;
            std::vector<std::string> NibblerScore;
        } _highScore;

        std::vector<std::string> _lib_files;
        std::vector<std::string> _game_files;
};

#endif /* !CORE_HPP_ */
