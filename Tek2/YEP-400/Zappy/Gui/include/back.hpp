/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** back
*/

#ifndef BACK_HPP_
    #define BACK_HPP_
    #include <iostream>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <cstring>
    #include <cstdlib>
    #include <sstream>

namespace gui
{
    class Back
    {
        public:
            Back() = default;
            ~Back() = default;

            std::string ip;
            int port;
            int _sock;
            struct sockaddr_in _server;
            std::string extractedData;
            std::string Data;

            //guiToServer
            int initSocket();
            void writeToServer(std::string messages);
            void receiveFromServer();
            void receiveClientInformation();
            void closeSocket();
            void receiveInfo();

            //responseToServer
            void sendTeamName();
            void sendRequests();
        private:
        protected:
    };
}

#endif /* !BACK_HPP_ */
