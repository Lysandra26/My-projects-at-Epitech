/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-lysandra.manuguerra
** File description:
** IGamesModule
*/

#ifndef IGAMESMODULE_HPP_
    #define IGAMESMODULE_HPP_
    #include <iostream>
    #include <string>
    #include "../Libs/IDisplayModule.hpp"

enum class GameState {
    RUNNING,
    PAUSED,
    GAME_OVER,
    WIN
};

class IGamesModule {
    public:
        IGamesModule() = default;
        virtual ~IGamesModule() = default;

        virtual void init(IDisplayModule *graphics, std::string playerName) = 0;
        virtual void update() = 0;
        virtual void handleInput(Input input) = 0;
        virtual void render() = 0;

        virtual std::string getName() const = 0;
        virtual unsigned int getCurrentScore() const = 0;
        virtual unsigned int getHighScore() const = 0;
        virtual void setState(GameState state) = 0;
        virtual GameState getState() const = 0;

    protected:
        GameState _state = GameState::PAUSED;
        unsigned int _currentScore;
        unsigned int _highScore;
        IDisplayModule *_graphical;
};


#endif /* !IGAMESMODULE_HPP_ */
