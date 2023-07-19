/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../include/front.hpp"

int gui::Front::initWindow()
{
    InitWindow(_screenWidth, _screenHeight, "Zappy");

    Camera camera = { 0 };
    camera.position = (Vector3){ 15.0f, 10.0f, 1.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model linemateModel = LoadModel("include/linemate.glb");
    Model deraumereModel = LoadModel("include/deraumere.glb");
    Model siburModel = LoadModel("include/sibur.glb");
    Model mendianeModel = LoadModel("include/mendiane.glb");
    Model phirasModel = LoadModel("include/phiras.glb");
    Model thystameModel = LoadModel("include/thystame.glb");
    Model foodModel = LoadModel("include/food.glb");
    Model skyModel = LoadModel("include/low_poly_hoth_skybox.glb");
    Model playerModel = LoadModel("include/player.glb");

    Model envModel = LoadModel("include/lowpoly_stylized_environement.glb");
    Vector3 position = { 2.0f, 2.0f, 2.0f };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        BeginDrawing();
            ClearBackground(SKYBLUE);
            BeginMode3D(camera);
                DrawModelEx(linemateModel, (Vector3){3.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 60.0f, (Vector3){ 0.25f, 0.25f, 0.25f }, PURPLE);
                DrawModelEx(deraumereModel, (Vector3){ 4.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 60.0f, (Vector3){ 0.25f, 0.25f, 0.25f }, PINK);
                DrawModelEx(siburModel, (Vector3){5.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 60.0f, (Vector3){ 0.25f, 0.25f, 0.25f }, RED);
                DrawModelEx(mendianeModel, (Vector3){6.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 60.0f, (Vector3){ 0.25f, 0.25f, 0.25f }, BLUE);
                DrawModelEx(phirasModel, (Vector3){7.0f, 2.0f, 0.0f }, (Vector3){ 0.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 0.25f, 0.25f, 0.25f }, GREEN);
                DrawModelEx(thystameModel, (Vector3){8.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 60.0f, (Vector3){ 0.25f, 0.25f, 0.25f }, WHITE);
                DrawModelEx(foodModel, (Vector3){9.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 60.0f, (Vector3){ 0.25f, 0.25f, 0.25f }, YELLOW);
                // DON'T REMOVE THEM
                DrawModelEx(envModel, (Vector3){0.0f, -30.0f, 2.0f }, (Vector3){ 21.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 20.0f, 20.0f, 20.0f }, BLUE);
                DrawModelEx(skyModel, (Vector3){50.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 2.0f, 2.0f, 2.0f }, WHITE);
                //
                DrawModelEx(playerModel, (Vector3){1.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 0.5f, 0.5f, 0.5f }, PURPLE);
                drawMap(camera);
            EndMode3D();
            displayInventory();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
