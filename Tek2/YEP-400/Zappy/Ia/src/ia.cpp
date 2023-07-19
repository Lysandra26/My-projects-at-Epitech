/*
** EPITECH PROJECT, 2023
** Ia
** File description:
** ia.cpp
*/

#include "../include/ia.hpp"

AI::AI(int port, char *name, char *machine, int id_bot)
{
    m_id_bot = id_bot;
    m_port = port;
    m_name = std::string(name);
    if (machine != NULL)
        m_machine = std::string(machine);
    else
        m_machine = "127.0.0.1";
    m_lvl_bot = 1;
    m_send_of_rcv = false;
}

void AI::set_nb_bot(int nb_bot)
{
    m_nb_bot = nb_bot;
}

int AI::create_socket()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;

    if (sock == -1) {
        std::cerr << "Failed to create socket.\n";
        return -1;
    }
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(m_port);
    if (inet_pton(AF_INET, m_machine.c_str(), &(serverAddress.sin_addr)) <= 0) {
        std::cerr << "Invalid address or address not supported.\n";
        return -1;
    }
    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Connection failed.\n";
        return -1;
    }
    return sock;
}

void AI::connect_to_server()
{
    std::string tmp;
    bool parse = false;
    int i;
    m_socket_client = create_socket();
    if (m_socket_client != -1)
        std::cout << "Connexion au serveur réussie.\n";
    receive_msg(true);
    send_msg(m_name + "\n");
    m_msg = receive_msg(true);
    for (i = 0; m_msg.c_str()[i] != '\n'; i++)
            tmp[i] = m_msg[i];
    m_num_client = std::atoi(tmp.c_str());
    tmp = "";
    //std::cout << "Nombre de place serveur : |" << m_num_client << "|\n";
    for (int j = 0; m_msg.c_str()[i] != '\0'; i++, j++) {
        if (m_msg.c_str()[i] == ' ') {
            m_x = std::atoi(tmp.c_str());
            tmp = "";
            parse = true;
            j = 0;
        }
        if (!parse)
            tmp[j] = m_msg[i];
        else
            tmp[j] = m_msg[i];
    }
    m_y = std::atoi(tmp.c_str());
    //std::cout << "X : |" << m_x << "|\n";
    //std::cout << "Y : |" << m_y << "|\n";
}

void AI::setup_bot()
{
    send_msg("Inventory\n");
    update_inventory(std::string(receive_msg(false)));
    if (m_id_bot > 1)
        sleep(10);
}

void AI::run()
{
    while(1) {
        send_msg("Inventory\n");
        update_inventory(receive_msg(true));
        if (can_start_incantation()) {
            start_incantation();
            send_msg("Inventory\n");
            update_inventory(receive_msg(false));
            //std::cout << "// c'etait l'update\n";
            search_food();
        }
        wich_ressource_i_need();
    }
    int status;
    pid_t childPid;
    while ((childPid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            std::cout << "Processus enfant " << childPid << " s'est terminé avec le code de sortie " << WEXITSTATUS(status) << std::endl;
        } else if (WIFSIGNALED(status)) {
            std::cout << "Processus enfant " << childPid << " s'est terminé en recevant le signal " << WTERMSIG(status) << std::endl;
        }
    }
}
