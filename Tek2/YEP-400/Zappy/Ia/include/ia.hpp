/*
** EPITECH PROJECT, 2023
** Ia
** File description:
** ia
*/
#ifndef IA_HPP_
	#define IA_HPP_
    #include <iostream>
    #include <sstream>
    #include <cstdlib>
    #include <string>
    #include <cstring>
    #include <cstdio>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netdb.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <map>
    #include <vector>
    #include <sys/wait.h>

const int REQUIRED_PLAYER = 0;
const int LINEMATE_INDEX = 1;
const int DERAUMERE_INDEX = 2;
const int SIBUR_INDEX = 3;
const int MENDIANE_INDEX = 4;
const int PHIRAS_INDEX = 5;
const int THYSTAME_INDEX = 6;
const int MAX_LEVEL = 8;

const int elevationRequirements[MAX_LEVEL + 1][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {2, 1, 1, 1, 0, 0, 0},
        {2, 2, 0, 1, 0, 2, 0},
        {4, 1, 1, 2, 0, 1, 0},
        {4, 1, 2, 1, 3, 0, 0},
        {6, 1, 2, 3, 0, 1, 0},
        {6, 2, 2, 2, 2, 2, 1},
};

class AI {
	public:
		AI(int port, char *name, char *machine, int id_bot);
        void set_nb_bot(int nb_bot);
        int create_socket();
        void setup_bot();
        void connect_to_server();
        void run();
        std::string receive_msg(bool print);
        void send_msg(std::string msg);
        bool can_start_incantation();
        void start_incantation();
        void update_inventory(std::string);
        void prepare_incantation();
        //void updateEnvironment();
        //void processTile(const std::string &tile);
        bool collectResources(std::string ressource);
        void reproduction();
        void wich_ressource_i_need();
        void search_food();

	private:
        int m_id_bot;
        int m_port;
        int m_socket_client;
        int m_lvl_bot;
        int m_nb_bot;
        std::string m_name;
        std::string m_machine;
        std::string m_msg;
        bool m_send_of_rcv;
        int m_num_client;
        int m_x;
        int m_y;
        int m_inventory[7];
        bool test;
        pid_t m_pid;
        std::vector<std::vector<std::string>> m_environment;
};

std::vector<std::vector<std::string>> parseInventory(const std::string &inventoryString);
int start_ai(int port, char *name, char *machine, int id);

#endif /*IA_HPP_*/