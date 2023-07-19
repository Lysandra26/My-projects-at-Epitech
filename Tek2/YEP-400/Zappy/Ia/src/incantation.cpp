/*
** EPITECH PROJECT, 2023
** Ia
** File description:
** incantation.cpp
*/

#include "../include/ia.hpp"

void AI::wich_ressource_i_need()
{
    std::cout << "Searching ressource...\n";
    while (!can_start_incantation()) {
        if (collectResources("food"))
            m_inventory[0]++;
        if (m_inventory[LINEMATE_INDEX] < elevationRequirements[m_lvl_bot][LINEMATE_INDEX]) {
            if (collectResources("linemate"))
                m_inventory[LINEMATE_INDEX]++;
        }
        if (m_inventory[DERAUMERE_INDEX] >= elevationRequirements[m_lvl_bot][DERAUMERE_INDEX]) {
            if (collectResources("deraumere"))
                m_inventory[DERAUMERE_INDEX]++;
        }
        if (m_inventory[SIBUR_INDEX] < elevationRequirements[m_lvl_bot][SIBUR_INDEX]) {
            if (collectResources("sibur"))
                m_inventory[SIBUR_INDEX]++;
        }
        if (m_inventory[MENDIANE_INDEX] >= elevationRequirements[m_lvl_bot][MENDIANE_INDEX]) {
            if (collectResources("mendiane"))
                m_inventory[MENDIANE_INDEX]++;
        }
        if (m_inventory[PHIRAS_INDEX] < elevationRequirements[m_lvl_bot][PHIRAS_INDEX]) {
            if (collectResources("phiras"))
                m_inventory[PHIRAS_INDEX]++;
        }
        if (m_inventory[THYSTAME_INDEX] >= elevationRequirements[m_lvl_bot][THYSTAME_INDEX]) {
            if (collectResources("thystame"))
                m_inventory[THYSTAME_INDEX]++;
        }
        send_msg("Forward\n");
        receive_msg(false);
        //send_msg("Inventory\n");
        //update_inventory(receive_msg(false));
    }
    std::cout << "Enought ressource...\n";
}

bool AI::can_start_incantation()
{
    if (m_lvl_bot < MAX_LEVEL) {
        if (m_inventory[LINEMATE_INDEX] >= elevationRequirements[m_lvl_bot][LINEMATE_INDEX] &&
            m_inventory[DERAUMERE_INDEX] >= elevationRequirements[m_lvl_bot][DERAUMERE_INDEX] &&
            m_inventory[SIBUR_INDEX] >= elevationRequirements[m_lvl_bot][SIBUR_INDEX] &&
            m_inventory[MENDIANE_INDEX] >= elevationRequirements[m_lvl_bot][MENDIANE_INDEX] &&
            m_inventory[PHIRAS_INDEX] >= elevationRequirements[m_lvl_bot][PHIRAS_INDEX] &&
            m_inventory[THYSTAME_INDEX] >= elevationRequirements[m_lvl_bot][THYSTAME_INDEX]) {
            send_msg("Fork\n");
            receive_msg(false);
            reproduction();
            return (true);
        }
    }
    return false;
}

void AI::prepare_incantation()
{
    for (int i = 1; i < 7; i++) {
        int tmp = elevationRequirements[m_lvl_bot][i];
        for (; tmp > 0; tmp--) {
            switch (i) {
                case 1:
                    send_msg("Set linemate\n");
                    receive_msg(false);
                    m_inventory[i]--;
                    break;
                case 2:
                    send_msg("Set deraumere\n");
                    receive_msg(false);
                    m_inventory[i]--;
                    break;
                case 3:
                    send_msg("Set sibur\n");
                    receive_msg(false);
                    m_inventory[i]--;
                    break;
                case 4:
                    send_msg("Set mendiane\n");
                    receive_msg(false);
                    m_inventory[i]--;
                    break;
                case 5:
                    send_msg("Set phiras\n");
                    receive_msg(false);
                    m_inventory[i]--;
                    break;
                case 6:
                    send_msg("Set thystame\n");
                    receive_msg(false);
                    m_inventory[i]--;
                    break;
                default:
                    break;
            }
        }
    }
}

void AI::start_incantation()
{
    std::cout << "INCANTATION STARTED\n";

    prepare_incantation();
    send_msg("Incantation\n");
    std::string response = receive_msg(true);
    if (response == "Elevation underway\n") {
        //m_state = INCANTATION;
        m_lvl_bot++;
        sleep(2);
        //wich_ressource_i_need();
        send_msg("Fork\n");
        receive_msg(true);
        reproduction();
    }/*
    send_msg("Inventory\n");
    receive_msg(true);
    std::cout << "Mon inventaire :";
    std::cout << "[ ";
    for (int i = 0; i < 7; i++) {
        std::cout << m_inventory[i];
        if (i != 6) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;
    */
}
