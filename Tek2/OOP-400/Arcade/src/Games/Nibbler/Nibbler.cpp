/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

/**
 * @brief Defines the entry point of the library
 *
 * @return IGamesModule* The entry point
*/

extern "C" IGamesModule *entryPoint()
{
    return new Arcade::Nibbler();
}

/**
 * @brief Construct a new Nibbler object
 *
*/

Arcade::Nibbler::Nibbler()
    : _direction(Direction::Right),
      _lastUpdate(std::chrono::steady_clock::now()),
      _updateInterval(std::chrono::milliseconds(150))
{}

/**
 * @brief Destroy the Nibbler object
*/

Arcade::Nibbler::~Nibbler() {}

/**
 * @brief Initialize the game
 *
 * @param graphics The graphics module
 * @param playerName The name of the player
*/

void Arcade::Nibbler::init(IDisplayModule *graphics, std::string playerName)
{
    _graphics = graphics;
    _playerName = playerName;
    _score = 0;
    init_Nibbler(4);
    _remainingApples = 0;
    _currentLevel = 1;
    _currentLevelFile = "Resources/Map/nibbler_lvl1.txt";
    _apples = load_apples_from_map(_currentLevelFile);
    _remainingApples = _apples.size();
    _timerStart = std::chrono::steady_clock::now();
    _timerEnd = std::chrono::seconds(90);
}

/**
 * @brief Update the game
*/

void Arcade::Nibbler::update()
{
    print_score_and_playername(_score, _playerName);
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - _lastUpdate) >= _updateInterval) {
        move_Nibbler();
        eat_apple();
        _lastUpdate = now;
    }
    handleCountdown();
    if (is_level_completed()) {
        load_next_level();
    }
}

/**
 * @brief Handle the input
 *
 * @param input The input
*/

void Arcade::Nibbler::handleInput(Input input)
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
            Arcade::Nibbler::saveScore();
            break;
        default:
            break;
    }
}

/**
 * @brief Check if the Nibbler is out of bounds
 *
 * @return true If the Nibbler is out of bounds
 * @return false If the Nibbler is not out of bounds
*/

bool Arcade::Nibbler::is_out_of_bounds() {
    const int MIN_X = 610;
    const int MAX_X = 1290;
    const int MIN_Y = 410;
    const int MAX_Y = 990;

    if (_Nibbler[0].x < MIN_X || _Nibbler[0].x >= MAX_X || _Nibbler[0].y < MIN_Y || _Nibbler[0].y >= MAX_Y || is_colliding_with_inner_walls()) {
        int random_direction = rand() % 2;

        if (_direction == Direction::Up || _direction == Direction::Down) {
            _direction = (random_direction == 0) ? Direction::Left : Direction::Right;
        } else {
            _direction = (random_direction == 0) ? Direction::Up : Direction::Down;
        }

        if (_Nibbler[0].x < MIN_X) {
            _Nibbler[0].x = MIN_X;
        } else if (_Nibbler[0].x >= MAX_X) {
            _Nibbler[0].x = MAX_X - 20;
        } else if (_Nibbler[0].y < MIN_Y) {
            _Nibbler[0].y = MIN_Y;
        } else if (_Nibbler[0].y >= MAX_Y) {
            _Nibbler[0].y = MAX_Y - 20;
        }

        return false;
    }

    return false;
}

/**
 * @brief Render the game
*/

void Arcade::Nibbler::render()
{
    init_map();
    for (const auto &part : _Nibbler) {
        _graphics->drawRectangle(Vector2f(part.x, part.y), Vector2f(20, 20), Color::MAGENTA);
    }
    for (const auto &apple : _apples) {
        _graphics->drawRectangle(Vector2f(apple.x, apple.y), Vector2f(20, 20), Color::RED);
    }

    auto now = std::chrono::steady_clock::now();
    auto remainingTime = _timerEnd - std::chrono::duration_cast<std::chrono::seconds>(now - _timerStart);
    std::stringstream timerText;
    timerText << "Time: " << std::setw(2) << std::setfill('0') << (remainingTime.count() / 60) << ":" << std::setw(2) << std::setfill('0') << (remainingTime.count() % 60);
    _graphics->drawText({740, 1010}, timerText.str(), 40, Color::BLACK);
}

/**
 * @brief Check the countdown
 *
*/

void Arcade::Nibbler::handleCountdown()
{
    auto now = std::chrono::steady_clock::now();
    auto remainingTime = _timerEnd - std::chrono::duration_cast<std::chrono::seconds>(now - _timerStart);
    if (remainingTime.count() <= 0) {
        _state = GameState::GAME_OVER;
        Arcade::Nibbler::saveScore();
    }
}

/**
 * @brief Function to move the Nibbler
*/

void Arcade::Nibbler::move_Nibbler()
{
    for (int i = _Nibbler_size - 1; i > 0; i--) {
        _Nibbler[i] = _Nibbler[i - 1];
    }

    switch (_direction) {
        case Direction::Up:
            _Nibbler[0].y -= 20;
            break;
        case Direction::Down:
            _Nibbler[0].y += 20;
            break;
        case Direction::Left:
            _Nibbler[0].x -= 20;
            break;
        case Direction::Right:
            _Nibbler[0].x += 20;
            break;
    }

    if (check_collision_with_tail()) {
        _state = GameState::GAME_OVER;
        Arcade::Nibbler::saveScore();
    }

    if (is_out_of_bounds()) {
        _state = GameState::GAME_OVER;
        Arcade::Nibbler::saveScore();
    }

    if (eat_apple()) {
        _Nibbler_size++;
    }
}

/**
 * @brief Read the map file
 *
 * @param filename The name of the file
 * @return std::vector<std::string> The map
 *
*/

std::vector<std::string> Arcade::Nibbler::read_map_file(const std::string &filename)
{
    std::vector<std::string> map;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open map file: " << filename << std::endl;
        return map;
    }

    while (std::getline(file, line)) {
        map.push_back(line);
    }

    file.close();
    return map;
}


/**
 * @brief Initialize the map
*/

void Arcade::Nibbler::init_map()
{
    _graphics->drawRectangle({600, 400}, {700, 600}, Color::BLACK);
    _graphics->drawRectangle({610, 410}, {680, 580}, Color::WHITE);

    _innerWalls.clear();

    std::vector<std::string> map = read_map_file(_currentLevelFile);

    for (size_t y = 0; y < map.size(); ++y) {
        for (size_t x = 0; x < map[y].length(); ++x) {
            if (map[y][x] == 'M') {
                _graphics->drawRectangle({610 + static_cast<float>(x * 20), 410 + static_cast<float>(y * 20)}, {20, 20}, Color::BLACK);
                _innerWalls.push_back({610 + static_cast<int>(x * 20), 410 + static_cast<int>(y * 20)});
            }
        }
    }
}

/**
 * @brief Load the apples from the map
 *
 * @param filename The name of the file
 * @return std::vector<Arcade::Nibbler::Position> The apples
 *
*/

std::vector<Arcade::Nibbler::Position> Arcade::Nibbler::load_apples_from_map(const std::string &filename)
{
    std::vector<Position> apples;
    std::vector<std::string> map = read_map_file(filename);

    for (size_t y = 0; y < map.size(); ++y) {
        for (size_t x = 0; x < map[y].length(); ++x) {
            if (map[y][x] == 'O') {
                apples.push_back({610 + static_cast<int>(x * 20), 410 + static_cast<int>(y * 20)});
            }
        }
    }

    return apples;
}

/**
 * @brief Check if the Nibbler is colliding with inner walls
 *
 * @return true If the Nibbler is colliding with inner walls
 * @return false If the Nibbler is not colliding with inner walls
*/

bool Arcade::Nibbler::is_colliding_with_inner_walls() {
    for (const auto &wall : _innerWalls) {
        if (_Nibbler[0].x == wall.x && _Nibbler[0].y == wall.y) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the level is completed
*/

bool Arcade::Nibbler::is_level_completed()
{
    return _remainingApples == 0;
}

/**
 * @brief Load the next level
*/

void Arcade::Nibbler::load_next_level()
{
    _currentLevel++;
    _currentLevelFile = "Resources/Map/nibbler_lvl" + std::to_string(_currentLevel) + ".txt";
    _apples = load_apples_from_map(_currentLevelFile);
    _remainingApples = _apples.size();

    init_map();
}


/**
 * @brief Initialize the Nibbler
 *
 * @param Nibbler_size The size of the Nibbler
*/

void Arcade::Nibbler::init_Nibbler(int Nibbler_size)
{
    _Nibbler_size = Nibbler_size;
    int startX = 950;
    int startY = 650;
    int rectSize = 20;

    for (int i = 0; i < _Nibbler_size; i++) {
        _Nibbler.push_back({startX, startY - (i * rectSize)});
    }
}

/**
 * @brief Check if the Nibbler collide with his tail
 *
 * @return true If the Nibbler collide with his tail
 * @return false If the Nibbler doesn't collide with his tail
*/

bool Arcade::Nibbler::check_collision_with_tail() {
    for (size_t i = 1; i < _Nibbler.size(); ++i) {
        if (_Nibbler[0].x == _Nibbler[i].x && _Nibbler[0].y == _Nibbler[i].y) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the Nibbler eat an apple
 *
 * @return true If the Nibbler eat an apple
 * @return false If the Nibbler doesn't eat an apple
*/

bool Arcade::Nibbler::eat_apple()
{
    for (auto it = _apples.begin(); it != _apples.end(); ++it) {
        if (_Nibbler[0].x == it->x && _Nibbler[0].y == it->y) {
            _score += 10;
            Position new_tail = {_Nibbler.back().x, _Nibbler.back().y};

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

            _Nibbler.push_back(new_tail);
            _apples.erase(it);
            _remainingApples--; // Mettre à jour le nombre de pommes restantes
            return true;
        }
    }
    return false;
}

/**
 * @brief Print the score and the player name
 *
 * @param score The score
 * @param playerName The name of the player
*/

void Arcade::Nibbler::print_score_and_playername(int score, std::string playerName)
{
    _graphics->drawText({710, 200}, "Player: " + playerName, 40, Color::BLACK);
    _graphics->drawText({740, 300}, "Score: " + std::to_string(score), 40, Color::BLACK);
}


/**
 * @brief Get the Name of the player
 *
 * @return std::string The name of the player
*/

std::string Arcade::Nibbler::getName() const { return _playerName; }

/**
 * @brief Get the Current Score of the player
 *
 * @return unsigned int The current score of the player
*/

unsigned int Arcade::Nibbler::getCurrentScore() const { return _score; }

/**
 * @brief Get the High Score of the player
 *
 * @return unsigned int The high score of the player
*/

unsigned int Arcade::Nibbler::getHighScore() const
{
    std::ifstream file("Resources/Score/hightScore.txt");
    std::string line;
    std::string result;
    int number = 0;

    while (std::getline(file, line)) {
        if (line.find("Nibbler") == 0) {
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

void Arcade::Nibbler::saveScore()
{
    int score = Arcade::Nibbler::getCurrentScore();
    std::string name = Arcade::Nibbler::getName();

    std::ofstream outfile("Resources/Score/highScore.txt", std::ios::app);
    if (outfile.is_open()) {
        outfile << "\nNibbler " << name << " " << score;
        outfile.close();
    }
}

/**
 * @brief Set the State of the game
 *
 * @param state The state of the game
 * @return GameState The state of the game
*/

void Arcade::Nibbler::setState(GameState state) { _state = state; }

/**
 * @brief Get the State of the game
 *
 * @return GameState The state of the game
*/

GameState Arcade::Nibbler::getState() const { return _state; }
