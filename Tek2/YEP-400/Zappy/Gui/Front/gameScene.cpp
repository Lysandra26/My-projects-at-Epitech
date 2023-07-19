/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** gameScene
*/

#include "../include/front.hpp"

void gui::Front::gameScene()
{
}

void gui::Front::drawMap(Camera camera)
{
    float spacing = 2.0f;
    float cubeSize = spacing;

    std::vector<Vector3> cubePositions;

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePosition = GetMousePosition();
        Ray mouseRay = GetMouseRay(mousePosition, camera);
        Vector3 mousePos3D;

        // Iterate over the cube positions and check for intersection with the mouse ray
        for (int i = 0; i < cubePositions.size(); i++) {
            const auto& position = cubePositions[i];

            // // Check if the mouse ray intersects with the cube
            // if (CheckCollisionRayBox(mouseRay, { position, { cubeSize, cubeSize, cubeSize } }))
            // {
            //     // Cube clicked, retrieve its position
            //     mousePos3D = position;
            //     break;
            // }
        }
        std::cout << "Clicked cube position: x = " << mousePos3D.x << ", y = " << mousePos3D.y << ", z = " << mousePos3D.z << std::endl;
    }

    for (int y = 0; y < MapY; y++)
    {
        for (int x = 0; x < MapX; x++)
        {
            float xPos = (x - (MapX - 1) / 2.0f) * spacing;
            float yPos = 0.9f;
            float zPos = (y - (MapY - 1) / 2.0f) * spacing;
            cubePositions.push_back(Vector3{ xPos, yPos, zPos });
        }
    }

    for (const auto& position : cubePositions) {
        DrawCube(position, cubeSize, cubeSize, cubeSize, BROWN);
        DrawCubeWires(position, cubeSize, cubeSize, cubeSize, BLACK);
    }
}

void gui::Front::displayInventory()
{
    // Window inventory
    Rectangle rectangle;
    rectangle.x = 0;
    rectangle.y = _screenHeight - 100;
    rectangle.width = _screenWidth;
    rectangle.height = 120;
    Color rectColor = { 255, 255, 255, 128 };
    DrawRectanglePro(rectangle, Vector2{ 0, 0 }, 0, rectColor);

    Tile* tileData = getTileData(0, 9);

    if (tileData != nullptr) {
        std::string info = "Linemate: " + std::to_string(tileData->linemate) + "\n" +
                           "Deraumere: " + std::to_string(tileData->deraumere) + "\n" +
                           "Sibur: " + std::to_string(tileData->sibur);

        std::string info2 = "Mendiane: " + std::to_string(tileData->mendiane) + "\n" +
                            "Phiras: " + std::to_string(tileData->phiras) + "\n" +
                            "Thystame: " + std::to_string(tileData->thystame);

        std::string foodInfo = "Food: " + std::to_string(tileData->food);

        DrawText(info.c_str(), 200, 630, 20, DARKGRAY);
        DrawText(info2.c_str(), 500, 630, 20, DARKGRAY);
        DrawText(foodInfo.c_str(), 700, 630, 20, DARKGRAY);
    }

    DrawText("Resources", 200, 600, 20, BLACK);
    DrawText("Player", 900, 600, 20, BLACK);
}

