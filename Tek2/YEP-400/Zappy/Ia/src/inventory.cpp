/*
** EPITECH PROJECT, 2023
** Ia
** File description:
** inventory.cpp
*/

#include "../include/ia.hpp"

void AI::update_inventory(std::string str)
{
    std::string digits;
    size_t digitIndex = 0;
    for (char c : str) {
        if (std::isdigit(c)) {
            digits.push_back(c);
        }
    }
    for (int i = 0; i < 7; i++) {
        m_inventory[i] = digits[digitIndex] - '0';
        digitIndex++;
        if (digits[digitIndex] == ',') {
            digitIndex++;
        }
    }
}

std::vector<std::vector<std::string>> parseInventory(const std::string &inventoryString)
{
    std::vector<std::vector<std::string>> result;
    std::string inventory = inventoryString.substr(1, inventoryString.size() - 2);
    std::istringstream iss(inventory);
    std::string item;
    size_t count = 0;

    while (std::getline(iss, item, ',') && count < 4) {
        std::vector<std::string> items;
        size_t start = item.find_first_not_of(' ');
        size_t end = item.find_last_not_of(' ');
        if (start != std::string::npos && end != std::string::npos) {
            item = item.substr(start, end - start + 1);
            std::istringstream itemIss(item);
            std::string subItem;
            while (std::getline(itemIss, subItem, ' '))
                items.push_back(subItem);
        }
        result.push_back(items);
        count++;
    }/*
    for (const auto &items : result) {
        for (const auto &item: items) {
            std::cout << item << " ";
        }
    }*/
    //std::cout << "\n";
    return result;
}
