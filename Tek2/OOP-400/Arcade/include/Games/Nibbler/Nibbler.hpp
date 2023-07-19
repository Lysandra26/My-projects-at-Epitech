/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Nibbler
*/

#ifndef Nibbler_HPP_
    #define Nibbler_HPP_
    #include <iostream>
    #include "../IGamesModule.hpp"
    #include <ncurses.h>
    #include <cstring>
    #include <fstream>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <string>
    #include <curses.h>
    #include <vector>
    #include <sstream>
    #include <chrono>
    #include <thread>
    #include <unistd.h>
    #include <cstdlib>
    #include <ctime>
    #include <algorithm>
    #include <random>
    #include <iomanip>

namespace Arcade {
    class Nibbler : public IGamesModule {
        public:
            Nibbler();
            ~Nibbler();

            void init(IDisplayModule *graphics, std::string playerName) override;
            void update() override;
            void handleInput(Input input) override;
            void render() override;

            std::string getName() const override;
            unsigned int getCurrentScore() const override;
            unsigned int getHighScore() const override;
            void setState(GameState state) override;
            GameState getState() const override;

        protected:
        private:

            void init_map();
            void print_score_and_playername(int score, std::string playerName);
            void init_Nibbler(int Nibbler_size);
            void move_Nibbler();
            bool check_collision_with_tail();
            bool is_out_of_bounds();
            bool eat_apple();
            bool is_colliding_with_inner_walls();
            void load_next_level();
            bool is_level_completed();
            void handleCountdown();
            void saveScore();

            std::string _playerName;
            int _score;
            int **_Nibbler_pos;
            int _Nibbler_size;
            GameState _state;
            IDisplayModule *_graphics;

            int _remainingApples;
            int _currentLevel;

            struct Position {
                int x;
                int y;
            };

            enum class Direction {
                Up,
                Down,
                Left,
                Right
            };

            std::vector<Position> _Nibbler;
            Position _apple;
            Direction _direction;
            std::vector<Position> _innerWalls;
            std::string _currentLevelFile;

            std::chrono::steady_clock::time_point _lastUpdate;
            std::chrono::milliseconds _updateInterval;
            std::chrono::steady_clock::time_point _timerStart;

            std::vector<std::string> read_map_file(const std::string &filename);
            std::vector<Arcade::Nibbler::Position> load_apples_from_map(const std::string &filename);
            std::vector<Arcade::Nibbler::Position> _apples;
            std::chrono::seconds _timerEnd;

    };
    extern "C" IGamesModule *entryPoint();
};

#endif /* !Nibbler_HPP_ */
