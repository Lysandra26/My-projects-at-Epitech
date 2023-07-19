/*
** EPITECH PROJECT, 2023
** Ia
** File description:
** handle_client.cpp
*/

#include "../include/ia.hpp"

const int BUFFER_SIZE = 1024;

std::string AI::receive_msg(bool print)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead = recv(m_socket_client, buffer, BUFFER_SIZE, 0);
    if (bytesRead < 0) {
        std::cerr << "Error receiving client information.\n";
        return NULL;
    }
    buffer[bytesRead] = '\0';
    if (print)
        std::cout << "Client number " << m_id_bot << " : "<< buffer;
    m_send_of_rcv = true;
    return (buffer);
}

void AI::send_msg(std::string msg)
{
    send(m_socket_client, msg.c_str(), std::strlen(msg.c_str()), 0);
}
