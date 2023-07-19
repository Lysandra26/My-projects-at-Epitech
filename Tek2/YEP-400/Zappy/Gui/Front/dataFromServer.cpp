/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** dataFromServer
*/

#include "../include/front.hpp"

void gui::Front::getMapSize(std::string command)
{
    std::istringstream iss(command);
    std::string msz;

    iss >> msz;

    if (iss >> MapX >> MapY) {
        // std::cout << "x: " << MapX << ", y: " << MapY << std::endl;
    } else {
        std::cerr << "Invalid map size format: " << command << std::endl;
    }
}

void gui::Front::parseTileData(std::string command)
{
    std::istringstream iss(command);
    std::string token;

    while (iss >> token) {
        if (token == "bct") {
            Tile tile;
            if (iss >> tile.x >> tile.y >> tile.food >> tile.linemate >> tile.deraumere >> tile.sibur >> tile.mendiane >> tile.phiras >> tile.thystame) {
                mapTiles.push_back(tile);
            } else {
                std::cerr << "Invalid tile format: " << command << std::endl;
            }
        }
    }

    for (const auto& tile : mapTiles) {
        std::cout << "Tile (" << tile.x << ", " << tile.y << "): "
                  << tile.food << " " << tile.linemate << " "
                  << tile.deraumere << " " << tile.sibur << " "
                  << tile.mendiane << " " << tile.phiras << " " 
                  << tile.thystame << std::endl;
    }
}

Tile* gui::Front::getTileData(int x, int y)
{
    for (auto& tile : mapTiles) {
        if (tile.x == x && tile.y == y) {
            return &tile;
        }
    }
    return nullptr;  // Tile not found
}
