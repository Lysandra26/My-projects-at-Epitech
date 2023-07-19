/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** front
*/

#ifndef FRONT_HPP_
    #define FRONT_HPP_
    #include "raylib.h"
    #include "raymath.h"
    #include <fstream>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include "back.hpp"
    #include <sstream>

struct Tile {
    int x;
    int y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
};

namespace gui
{
    class Front
    {
        public:
            Front() = default;
            ~Front() = default;

            bool Running = false;
            int MapX = 0;
            int MapY = 0;
            std::vector<Tile> mapTiles;

            //initRaylib
            int initWindow();

            //gameScene
            void drawMap(Camera camera);
            void gameScene();
            void displayInventory();

            //menuScene
            void menuScene(gui::Back& back);
            void backgroundSquare();

            //createObject
            void linemateCreate();
            void deraumereCreate();
            void siburCreate();
            void mendianeCreate();
            void phirasCreate();
            void thystameCreate();
            void foodCreate();
            void playerCreate();

            //inputPlayer
            void controlCam(Camera3D camera);

            //dataFromServer
            void getMapSize(std::string command);
            void parseTileData(std::string command);
            Tile* getTileData(int x, int y);

        private:
            int _screenWidth = 1280;
            int _screenHeight = 720;
        protected:
    };
}

#endif /* !FRONT_HPP_ */
