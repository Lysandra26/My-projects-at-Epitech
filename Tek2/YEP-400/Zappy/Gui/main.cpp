/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** main.cpp
*/

#include "include/front.hpp"
#include "include/back.hpp"

void print_help_gui()
{
    std::cout << "USAGE: ./zappy_ai -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
    exit(0);
}

int parseArg(int argc, char* argv[], gui::Back& back) {
    if (argc == 2 && std::string(argv[1]) == "-help") {
        print_help_gui();
        return 0;
    }

    back.port = 7000;
    back.ip = "127.0.0.1";

    for (int i = 1; i < argc; i += 2) {
        std::string option = argv[i];
        int value = std::atoi(argv[i + 1]);

        if (option == "-p") {
            back.port = value;
        } else if (option == "-h") {
            back.ip = argv[i + 1];
        } else {
            std::cout << "Invalid argument: " << option << std::endl;
            std::cout << "Use '-help' for more information." << std::endl;
            return 84;
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    gui::Back back;
    gui::Front front;

    parseArg(argc, argv, back);
    front.menuScene(back);
    if (front.Running) {
        back.initSocket();
        back.receiveFromServer();
        back.sendTeamName();
        back.receiveClientInformation();
        back.receiveInfo();
        front.getMapSize(back.extractedData);
        front.parseTileData(back.Data);
        front.initWindow();
    }
    back.closeSocket();
    return 0;
}
