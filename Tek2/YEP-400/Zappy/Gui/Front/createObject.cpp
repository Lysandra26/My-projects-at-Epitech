/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** createObject
*/

#include "../include/front.hpp"

void gui::Front::linemateCreate()
{
    Model linemateModel = LoadModel("include/linemate.glb");
}

void gui::Front::deraumereCreate()
{
    Model deraumereModel = LoadModel("include/deraumere.glb");
}

void gui::Front::siburCreate()
{
    Model siburModel = LoadModel("include/sibur.glb");
}

void gui::Front::mendianeCreate()
{
    Model mendianeModel = LoadModel("include/mendiane.glb");
}

void gui::Front::phirasCreate()
{
    Model phirasModel = LoadModel("include/phiras.glb");
}

void gui::Front::thystameCreate()
{
    Model thystameModel = LoadModel("include/thystame.glb");
}

void gui::Front::foodCreate()
{
    Model foodModel = LoadModel("include/food.glb");
    // Texture2D texture = LoadTexture("cheese_texture.png");
    // DrawModel(model, Vector3{ 1.0f, 1.0f, 1.0f }, 1.0f, WHITE);
}

void gui::Front::playerCreate()
{
    Model playerModel = LoadModel("include/player.glb");
    DrawModelEx(playerModel, (Vector3){1.0f, 2.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 0.5f, 0.5f, 0.5f }, PURPLE);
}
