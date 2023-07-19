/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_
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

namespace Arcade {
    class Snake : public IGamesModule {
        public:
            Snake();
            ~Snake();

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
            void init_snake(int snake_size);
            void move_snake();
            bool check_collision_with_tail();
            bool is_out_of_bounds();
            void generate_apple();
            bool eat_apple();
            void saveScore();

            std::string _playerName;
            int _score;
            int **_snake_pos;
            int _snake_size;
            GameState _state;
            IDisplayModule *_graphics;

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

            std::vector<Position> _snake;
            Position _apple;
            Direction _direction;

            std::chrono::steady_clock::time_point _lastUpdate;
            std::chrono::milliseconds _updateInterval;


    };
    extern "C" IGamesModule *entryPoint();
};

#endif /* !SNAKE_HPP_ */
