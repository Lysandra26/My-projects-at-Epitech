/*
** EPITECH PROJECT, 2023
** Ia
** File description:
** environment.cpp
*/

#include "../include/ia.hpp"
bool AI::collectResources(std::string ressource)
{
    send_msg("Look\n");
    std::string tmp;
    int i = 0;
    std::string to = receive_msg(false);
    m_environment = parseInventory(to);

    for (const auto &items : m_environment) {
        for (const auto &item : items) {
            //std::cout << item << ", ";
            if (item == ressource) {
                tmp = item;
                break;
            }
        }
        //std::cout << std::endl;
        if (tmp == ressource)
            break;
        i++;
    }
    switch (i) {
        case 1:
            send_msg("Forward\n");
            receive_msg(false);
            send_msg("Left\n");
            receive_msg(false);
            send_msg("Forward\n");
            receive_msg(false);
            break;
        case 2:
            send_msg("Forward\n");
            receive_msg(false);
            break;
        case 3:
            send_msg("Forward\n");
            receive_msg(false);
            send_msg("Right\n");
            receive_msg(false);
            send_msg("Forward\n");
            receive_msg(false);
            break;
        default:
            break;
    }
    send_msg("Take " + tmp + "\n");
    std::string tmp2;
    if ((tmp2 = receive_msg(false)) == "ok\n")
        return (true);
    return (false);
}

void AI::search_food()
{
    int i = 0;
    std::cout << "Searching food...\n";
    while (m_inventory[0] < 20) {
        if (collectResources("food"))
            m_inventory[0]++;
        else {
            if (i < 5) {
                send_msg("Forward\n");
                receive_msg(false);
            } else if (i < 6) {
                send_msg("Right\n");
                receive_msg(false);
                send_msg("Right\n");
                receive_msg(false);
                send_msg("Forward\n");
                receive_msg(false);
            } else {
                send_msg("Forward\n");
                receive_msg(false);
            }
        }
        i++;
    }
}

/*
void AI::updateEnvironment()
{
    send_msg("Look\n");
    std::string response = receive_msg(true);
    std::vector<std::string> tiles = parseEnvironmentResponse(response);

    for (const std::string& tile : tiles)
        processTile(tile);
}

void AI::processTile(const std::string &tile)
{
    // Analyser les informations de la tuile pour extraire les ressources, les joueurs, etc.
    // et mettre à jour votre environnement interne en conséquence

    // Exemple de traitement : extraire le type de ressource et sa quantité de la tuile
    std::string resourceType;
    int resourceQuantity;

    size_t openParenthesisPos = tile.find('(');
    if (openParenthesisPos != std::string::npos)
    {
        // Extraire le type de ressource en supprimant les espaces avant et après
        resourceType = tile.substr(0, openParenthesisPos);
        trim(resourceType);
    }

    // Trouver la position de la première parenthèse fermante pour extraire la quantité de ressource
    size_t closeParenthesisPos = tile.find(')');
    if (closeParenthesisPos != std::string::npos)
    {
        // Extraire la quantité de ressource en supprimant les espaces avant et après
        std::string quantityString = tile.substr(openParenthesisPos + 1, closeParenthesisPos - openParenthesisPos - 1);
        trim(quantityString);

        // Convertir la quantité en entier
        resourceQuantity = std::stoi(quantityString);
    }

    // Mettre à jour votre environnement interne avec les informations extraites
    // (par exemple, stocker la quantité de chaque type de ressource dans une structure de données appropriée)
    updateInternalEnvironment(resourceType, resourceQuantity);
}

std::vector<std::string> AI::parseEnvironmentResponse(const std::string& response)
{
    // Implémenter le code pour analyser la réponse du serveur et extraire les informations sur les tuiles
    // et retourner un vecteur de chaînes de caractères représentant chaque tuile

    // Exemple simplifié : séparer la réponse en fonction des virgules pour obtenir chaque tuile
    std::vector<std::string> tiles;
    size_t startPos = 0;
    size_t commaPos = response.find(',');

    while (commaPos != std::string::npos)
    {
        std::string tile = response.substr(startPos, commaPos - startPos);
        tiles.push_back(tile);

        startPos = commaPos + 1;
        commaPos = response.find(',', startPos);
    }

    return tiles;
}

void AI::trim(std::string& str)
{
    // Fonction utilitaire pour supprimer les espaces avant et après une chaîne de caractères
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');

    if (first != std::string::npos && last != std::string::npos)
    {
        str = str.substr(first, last - first + 1);
    }
    else
    {
        str.clear();
    }
}
*/