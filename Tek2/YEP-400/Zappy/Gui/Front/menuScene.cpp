/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** sceneMenu
*/

#include "../include/front.hpp"

void gui::Front::menuScene(gui::Back& back)
{
    InitWindow(_screenWidth, _screenHeight, "Zappy");
    bool goToGame = false;
    int selectedInput = 1;
    std::string portStr;
    portStr = std::to_string(back.port);
    Model playerModel = LoadModel("include/player.glb");

    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 50.0f, 100.0f };
    camera.target = (Vector3){ 15.0f, 0.0f, 15.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_UP)) {
            selectedInput--;
            if (selectedInput < 1)
                selectedInput = 3;
        }
        if (IsKeyPressed(KEY_DOWN)) {
            selectedInput++;
            if (selectedInput > 3)
                selectedInput = 1;
        }
        if (IsKeyPressed(KEY_ENTER)) {
            if (selectedInput == 3) {
                Running = true;
                break;
            }
        }
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        if (selectedInput == 1) {
            int key = GetCharPressed();
            if (key > 0 && key != KEY_ENTER) {
                back.ip += static_cast<char>(key);
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !back.ip.empty()) {
                back.ip.pop_back();
            }
        } else if (selectedInput == 2) {
            int key = GetCharPressed();
            if (key > 0 && key != KEY_ENTER) {
                portStr += static_cast<char>(key);
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !portStr.empty()) {
                portStr.pop_back();
            }
        }

        if (!portStr.empty()) {
            try {
                back.port = std::stoi(portStr);
            } catch (const std::exception& e) {
                back.port = 7000;
            }
        }

        BeginDrawing();
            ClearBackground(SKYBLUE);
            BeginMode3D(camera);
                DrawModel(playerModel, (Vector3){30.0f, -50.0f, 30.0f}, 20.0f, PURPLE);
            EndMode3D();
            backgroundSquare();
            DrawText("Zappy", 150, 50, 100, DARKGRAY);
            DrawText(selectedInput == 1 ? "NAME :" : "NAME", 150, 200, 40, selectedInput == 1 ? RED : DARKGRAY);
            DrawText(back.ip.c_str(), 300, 200, 40, selectedInput == 1 ? BLACK : DARKGRAY);
            DrawText(selectedInput == 2 ? "PORT :" : "PORT", 150, 250, 40, selectedInput == 2 ? RED : DARKGRAY);
            DrawText(portStr.c_str(), 300, 250, 40, selectedInput == 2 ? BLACK : DARKGRAY);
            DrawText(selectedInput == 3 ? "> START" : "START", 150, 300, 40, selectedInput == 3 ? RED : DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
}

void gui::Front::backgroundSquare()
{
    Rectangle rectangle;
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.width = _screenWidth / 2;
    rectangle.height = _screenHeight;
    Color rectColor = { 255, 255, 255, 128 };

    DrawRectanglePro(rectangle, Vector2{ 0, 0 }, 0, rectColor);
}
