/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** guiToServer
*/

#include "../include/back.hpp"

int gui::Back::initSocket()
{
    _sock = socket(AF_INET, SOCK_STREAM, 0);
    if (_sock == -1) {
        std::cerr << "Could not create socket" << std::endl;
        exit(84);
    }

    _server.sin_addr.s_addr = inet_addr(ip.c_str());
    _server.sin_family = AF_INET;
    _server.sin_port = htons(port);

    if (connect(_sock, (struct sockaddr *)&_server, sizeof(_server)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        exit(84);
    }
    return 0;
}

void gui::Back::writeToServer(std::string messages) {
    ssize_t bytesSent = send(_sock, messages.c_str(), messages.length(), 0);
    if (bytesSent == -1) {
        std::cerr << "Failed to send data" << std::endl;
    }
}

void gui::Back::receiveFromServer()
{
    char buffer[1024];
    ssize_t bytesRead = recv(_sock, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead == -1) {
        std::cerr << "Failed to receive data" << std::endl;
    } else if (bytesRead == 0) {
        std::cout << "Connection closed by the server" << std::endl;
    } else {
        buffer[bytesRead] = '\0';
        std::cout << "Received: " << buffer << std::endl;
    }
}

void gui::Back::receiveClientInformation()
{
    char buffer[1024];
    ssize_t bytesRead = recv(_sock, buffer, 1024, 0);
    if (bytesRead < 0) {
        std::cerr << "Error receiving client information.\n";
        return;
    }
    buffer[bytesRead] = '\0';
    std::string receivedData(buffer);

    // get map size
    size_t newlinePos = receivedData.find('\n');
    extractedData = receivedData.substr(0, newlinePos);

    std::cout << buffer << std::endl;
}

void gui::Back::receiveInfo()
{
    char buffer[1024];
    ssize_t bytesRead = recv(_sock, buffer, 1024, 0);
    if (bytesRead < 0) {
        std::cerr << "Error receiving client information.\n";
        return;
    }
    buffer[bytesRead] = '\0';
    std::string receivedData(buffer);

    Data = receivedData;
}

void gui::Back::closeSocket()
{
    close(_sock);
}
