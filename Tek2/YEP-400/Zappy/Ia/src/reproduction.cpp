/*
** EPITECH PROJECT, 2023
** Ia
** File description:
** reproduction.cpp
*/

#include "../include/ia.hpp"

void AI::reproduction()
{
    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "Error fork" << std::endl;
        exit(84);
    } else if (pid == 0) {
        start_ai(m_port, const_cast<char *>(m_name.c_str()), const_cast<char *>(m_machine.c_str()), m_id_bot + 1);
    } else {
        //rien
    }

}
