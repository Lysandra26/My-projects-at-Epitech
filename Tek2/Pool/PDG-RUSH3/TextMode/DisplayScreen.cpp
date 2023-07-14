/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGRUSH3-william.andreo
** File description:
** DisplayScreen
*/

#include "my.hpp"

void IMonitorModule::printTop(IMonitorModule module)
{
    std::string line;
    std::string newLine;
    struct utsname osinfo;
    uname(&osinfo);
    sysinfo(&module.info);
    char* time = module.getTime();
    printw("%s\n", time);
    printw("Number of cores : %d\n", module.varGetCore);
    printw("Hostname : %s\nUsername : %s\n", module.hostname, module .username);
    printw("Operating system name : %s\nOperating system version : %s\n", osinfo.sysname, osinfo.version);
    printw("CPU Model : %s\n", module.cpuName.c_str());
    printw("CPU Percentage : %d\n", module.cpuPercentage);
    printw("CPU Frequency : %d\n", module.cpuFrequency);
    printw("CPU Number : %s\n\n", module.cpuNumber.c_str());
    printw("Total available RAM : %ldMB\n", module.info.freeram / (1024 * 1024));
    std::ifstream file("/proc/cpuinfo");
    while (std::getline(file, line)) {
        if (line.find("processor") != std::string::npos) {
            newLine = line.erase(0, 9);
            printw("CPU Number : %s\n", newLine.c_str());
        }
    }
    return;
}

void exit_matrix(void)
{
    endwin();
    exit(0);
}

void matrix_getchr(void)
{
    int ch;
    ch = getch();

    if (ch == 27)
        exit_matrix();
}

void initNcurses(void)
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
}

int startNcurses(void)
{
    initNcurses();
    while (1) {
        matrix_getchr();
        IMonitorModule module;
        IMonitorModule::printTop(module);
        refresh();
        usleep(1000000);
        erase();
        refresh();
    }
    exit_matrix();
    return 0;
}
