/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Snake
*/

#include "Snake.hpp"

/**
 * @brief Defines the entry point of the library
 *
 * @return IGamesModule* The entry point
*/

extern "C" IGamesModule *entryPoint()
{
    return new Arcade::Snake();
}

/**
 * @brief Construct a new Snake object
 *
*/

Arcade::Snake::Snake()
    : _direction(Direction::Right),
      _lastUpdate(std::chrono::steady_clock::now()),
      _updateInterval(std::chrono::milliseconds(150))
{}

/**
 * @brief Destroy the Snake object
*/

Arcade::Snake::~Snake() {}

/**
 * @brief Initialize the game
 *
 * @param graphics The graphics module
 * @param playerName The name of the player
*/

void Arcade::Snake::init(IDisplayModule *graphics, std::string playerName)
{
    _graphics = graphics;
    _playerName = playerName;
    _score = 0;
    init_snake(4);
    generate_apple();
}

/**
 * @brief Update the game
*/

void Arcade::Snake::update()
{
    print_score_and_playername(_score, _playerName);
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastUpdate) >= _updateInterval) {
        move_snake();
        eat_apple();
        _lastUpdate = now;
    }
}

/**
 * @brief Handle the input
 *
 * @param input The input
*/

void Arcade::Snake::handleInput(Input input)
{
    switch (input) {
        case Input::UP:
            if (_direction != Direction::Down) {
                _direction = Direction::Up;
            }
            break;
        case Input::DOWN:
            if (_direction != Direction::Up) {
                _direction = Direction::Down;
            }
            break;
        case Input::LEFT:
            if (_direction != Direction::Right) {
                _direction = Direction::Left;
            }
            break;
        case Input::RIGHT:
            if (_direction != Direction::Left) {
                _direction = Direction::Right;
            }
            break;
        case Input::ESCAPE:
            _state = GameState::GAME_OVER;
            Arcade::Snake::saveScore();
            break;
        default:
            break;
    }
}

/**
 * @brief Check if the snake is out of bounds
 *
 * @return true If the snake is out of bounds
 * @return false If the snake is not out of bounds
*/

bool Arcade::Snake::is_out_of_bounds() {
    const int MIN_X = 610;
    const int MAX_X = 1290;
    const int MIN_Y = 410;
    const int MAX_Y = 990;

    if (_snake[0].x < MIN_X || _snake[0].x >= MAX_X || _snake[0].y < MIN_Y || _snake[0].y >= MAX_Y) {
        return true;
    }
    return false;
}

/**
 * @brief Render the game
*/

void Arcade::Snake::render()
{
    init_map();
    for (const auto &part : _snake) {
        _graphics->drawRectangle(Vector2f(part.x, part.y), Vector2f(20, 20), Color::MAGENTA);
    }
    _graphics->drawRectangle(Vector2f(_apple.x, _apple.y), Vector2f(20, 20), Color::RED);
}

/**
 * @brief Function to move the snake
*/

void Arcade::Snake::move_snake()
{
    for (int i = _snake_size - 1; i > 0; i--) {
        _snake[i] = _snake[i - 1];
    }

    switch (_direction) {
        case Direction::Up:
            _snake[0].y -= 20;
            break;
        case Direction::Down:
            _snake[0].y += 20;
            break;
        case Direction::Left:
            _snake[0].x -= 20;
            break;
        case Direction::Right:
            _snake[0].x += 20;
            break;
    }

    if (check_collision_with_tail()) {
        _state = GameState::GAME_OVER;
        Arcade::Snake::saveScore();
    }

    if (is_out_of_bounds()) {
        _state = GameState::GAME_OVER;
        Arcade::Snake::saveScore();
    }

    if (eat_apple()) {
        _snake_size++; // Ajoutez le nouveau carré à la position de l'ancienne queue du serpent
    }
}

/**
 * @brief Initialize the map
*/

void Arcade::Snake::init_map()
{
    _graphics->drawRectangle({600, 400}, {700, 600}, Color::BLACK);
    _graphics->drawRectangle({610, 410}, {680, 580}, Color::WHITE);
}

/**
 * @brief Initialize the snake
 *
 * @param snake_size The size of the snake
*/

void Arcade::Snake::init_snake(int snake_size)
{
    _snake_size = snake_size;
    int startX = 950;
    int startY = 650;
    int rectSize = 20;

    for (int i = 0; i < _snake_size; i++) {
        _snake.push_back({startX, startY - (i * rectSize)});
    }
}

/**
 * @brief Check if the snake collide with his tail
 *
 * @return true If the snake collide with his tail
 * @return false If the snake doesn't collide with his tail
*/

bool Arcade::Snake::check_collision_with_tail() {
    for (size_t i = 1; i < _snake.size(); ++i) {
        if (_snake[0].x == _snake[i].x && _snake[0].y == _snake[i].y) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Generate a random apple
*/

void Arcade::Snake::generate_apple()
{
    srand(time(NULL));
    _apple.x = 610 + 20 * (rand() % 34);
    _apple.y = 410 + 20 * (rand() % 29);
}

/**
 * @brief Check if the snake eat an apple
 *
 * @return true If the snake eat an apple
 * @return false If the snake doesn't eat an apple
*/
bool Arcade::Snake::eat_apple()
{
    if (_snake[0].x == _apple.x && _snake[0].y == _apple.y) {
        _score += 10;
        Position new_tail = { _snake.back().x, _snake.back().y };

        switch (_direction) {
            case Direction::Up:
                new_tail.y += 20;
                break;
            case Direction::Down:
                new_tail.y -= 20;
                break;
            case Direction::Left:
                new_tail.x += 20;
                break;
            case Direction::Right:
                new_tail.x -= 20;
                break;
        }

        _snake.push_back(new_tail);
        generate_apple();
        return true;
    }
    return false;
}

/**
 * @brief Print the score and the player name
 *
 * @param score The score
 * @param playerName The name of the player
*/

void Arcade::Snake::print_score_and_playername(int score, std::string playerName)
{
    _graphics->drawText({710, 200}, "Player: " + playerName, 40, Color::BLACK);
    _graphics->drawText({740, 300}, "Score: " + std::to_string(score), 40, Color::BLACK);
}


/**
 * @brief Get the Name of the player
 *
 * @return std::string The name of the player
*/

std::string Arcade::Snake::getName() const { return _playerName; }

/**
 * @brief Get the Current Score of the player
 *
 * @return unsigned int The current score of the player
*/

unsigned int Arcade::Snake::getCurrentScore() const { return _score; }

/**
 * @brief Get the High Score of the player
 *
 * @return unsigned int The high score of the player
*/

unsigned int Arcade::Snake::getHighScore() const
{
    std::ifstream file("Resources/Score/hightScore.txt");
    std::string line;
    std::string result;
    int number = 0;

    while (std::getline(file, line)) {
        if (line.find("Snake") == 0) {
            result = line.substr(6);
        }
    }
    std::stringstream ss(result);
    std::string temp;
    while (ss >> temp) {
        if (isdigit(temp[0])) {
            number = stoi(temp);
        }
    }
    return number;
}

/**
 * @brief Set the State of the game
 *
 * @param state The state of the game
 * @return GameState The state of the game
*/

void Arcade::Snake::saveScore()
{
    int score = Arcade::Snake::getCurrentScore();
    std::string name = Arcade::Snake::getName();

    std::ofstream outfile("Resources/Score/highScore.txt", std::ios::app);
    if (outfile.is_open()) {
        outfile << "\nSnake " << name << " " << score;
        outfile.close();
    }
}

void Arcade::Snake::setState(GameState state) { _state = state; }

/**
 * @brief Get the State of the game
 *
 * @return GameState The state of the game
*/

GameState Arcade::Snake::getState() const { return _state; }
