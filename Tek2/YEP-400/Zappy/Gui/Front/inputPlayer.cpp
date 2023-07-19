/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** inputPlayer
*/

#include "../include/front.hpp"

void gui::Front::controlCam(Camera3D camera)
{
    if (IsKeyDown(KEY_Q))
        camera.target.y -= 0.5f;
    if (IsKeyDown(KEY_Z))
        camera.target.y += 0.5f;
    if (IsKeyDown(KEY_S))
        camera.target.x -= 0.5f;
    if (IsKeyDown(KEY_D))
        camera.target.x += 0.5f;
}
