/*
** EPITECH PROJECT, 2023
** Day 4AM
** File description:
** z
*/

#include <unistd.h>
#include <stdio.h>

int main(void)
{
    if (write(1, "z\n", 2) == -1)
        return 84;
    return 0;
}
