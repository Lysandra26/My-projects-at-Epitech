/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGRUSH3-william.andreo
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
    #define IMONITORMODULE_HPP_
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <sstream>
    #include "../TextMode/my.hpp"
    #include "../GraphicalMode/mySfml.hpp"
    #include "stdlib.h"
    #include "stdio.h"
    #include "string.h"
    #include <iostream>
    #include <unistd.h>
    #include <sys/utsname.h>
    #include <sys/sysinfo.h>
    #include <ctime>
    #include <limits.h>


class IMonitorModule {
    public:
        IMonitorModule();
        ~IMonitorModule();
        int getCore() { return (sysconf(_SC_NPROCESSORS_ONLN));};
        int getHostName() { return (HOST_NAME_MAX);};
        int getUserName() { return (LOGIN_NAME_MAX);};
        int getFrequency();
        int getRam();
        void getNames();
        char* getTime();
        static void printTop(IMonitorModule module);
        std::string getProcessor();
        std::string getCpuName();
        double getCpuPercentage(void);
        std::string cpuNumber = getProcessor();
        int varGetCore = getCore();
        int varGetHostName = getHostName();
        int varGetUserName = getUserName();
        char hostname[HOST_NAME_MAX];
        char username[LOGIN_NAME_MAX];
        int cpuFrequency = getFrequency();
        int cpuPercentage = getCpuPercentage();
        std::string cpuName = getCpuName();
        struct sysinfo info;
    protected:
    private:

};



#endif /* !IMONITORMODULE_HPP_ */
