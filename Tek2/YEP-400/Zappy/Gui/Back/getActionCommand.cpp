/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** getActionCommand
*/

#include "../include/back.hpp"

void getExpulsion(std::string command)
{
    std::istringstream iss(command);
    std::string pex;
    int numberPlayer;

    iss >> pex;

    if (iss >> numberPlayer) {
        std::cout << "Expulsion of player number " << numberPlayer << std::endl;
    } else {
        std::cerr << "Invalid map size format: " << command << std::endl;
    }
}

void getBroadcast(std::string command)
{
    std::istringstream iss(command);
    std::string pbc;
    int numberPlayer;
    std::string message;

    iss >> pbc;

    if (iss >> numberPlayer >> message) {
        std::cout << "Player number " << numberPlayer << " broadcast this message :" << message << std::endl;
    } else {
        std::cerr << "Invalid map size format: " << command << std::endl;
    }
}

void getEggLaying(std::string command)
{
    std::istringstream iss(command);
    std::string pfk;
    int numberPlayer;

    iss >> pfk;

    if (iss >> numberPlayer) {
        std::cout << "Player number " << numberPlayer << " is laying an egg" << std::endl;
    } else {
        std::cerr << "Invalid map size format: " << command << std::endl;
    }
}

void getRessourcesDrop(std::string command)
{
    std::istringstream iss(command);
    std::string pdr;
    int numberPlayer;
    int ressourceNumber;

    iss >> pdr;

    if (iss >> numberPlayer >> ressourceNumber) {
        std::cout << "Player number " << numberPlayer << " drop ressource number :" << ressourceNumber << std::endl;
    } else {
        std::cerr << "Invalid map size format: " << command << std::endl;
    }
}

void getRessourcesCollect(std::string command)
{
    std::istringstream iss(command);
    std::string pgt;
    int numberPlayer;
    int ressourceNumber;

    iss >> pgt;

    if (iss >> numberPlayer >> ressourceNumber) {
        std::cout << "Player number " << numberPlayer << " get ressource number :" << ressourceNumber << std::endl;
    } else {
        std::cerr << "Invalid map size format: " << command << std::endl;
    }
}
