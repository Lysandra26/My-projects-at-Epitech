/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGRUSH3-william.andreo
** File description:
** IMonitorModule
*/

#include "IMonitorModule.hpp"

static unsigned long long lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle;

char *parseCpuModel(std::string str)
{
    std::string newStr;
    const char *newNewStr;
    char *returnValue;

    newStr = str.erase(0, 11);
    newNewStr = newStr.c_str();
    returnValue = const_cast<char *>(newNewStr);
    return returnValue;
}

std::string IMonitorModule::getCpuName(void)
{
    std::string newLine;
    std::string line;
    std::ifstream file("/proc/cpuinfo");

    while (std::getline(file, line)) {
        if (line.find("model name") != std::string::npos) {
            newLine = line.erase(0, 13);
        }
    }
    return newLine;
}

int parseCpuFrequency(char *str)
{
    int frequency = strlen(str);
    const char* p = str;
    while (*p <'0' || *p > '9') p++;
    str[frequency - 3] = '\0';
    frequency = atoi(p);
    return frequency;
}

int IMonitorModule::getFrequency(void)
{
    int frequency = 0;
    std::string line;
    std::ifstream file("/proc/cpuinfo");
    char *str;

    while (std::getline(file, line)) {
        if (line.find("cpu MHz") != std::string::npos) {
            str = &line[0];
            frequency = parseCpuFrequency(str);
        }
    }
    return frequency;
}

int parseLine(char* line)
{
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getRam()
{
    std::ifstream file("/proc/self/status");
    std::string line;
    int result = 0;
    char *str = NULL;

    while (std::getline(file, line)){
        if (line.find("VmRSS:") != std::string::npos) {
            str = &line[0];
            result = parseLine(str);
            break;
        }
    }

    return result;
}

double IMonitorModule::getCpuPercentage(void)
{
    double percent;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;

    std::ifstream file("/proc/stat");
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("cpu") != std::string::npos) {
            std::istringstream iss(line);
            std::string label;
            iss >> label;
            iss >> totalUser >> totalUserLow >> totalSys >> totalIdle;
            break;
        }
    }

    if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow || totalSys < lastTotalSys || totalIdle < lastTotalIdle) {
            percent = -1.0;
    }
    else {
            total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) + (totalSys - lastTotalSys);
            percent = total;
            total += (totalIdle - lastTotalIdle);
            percent /= total;
            percent *= 100;
    }
    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;

    return percent;

}

char* IMonitorModule::getTime()
{
    time_t now = time(nullptr);
    char *timeStr = ctime(&now);
    return timeStr;
}

void IMonitorModule::getNames()
{
    gethostname(this->hostname, HOST_NAME_MAX);
    getlogin_r(this->username, LOGIN_NAME_MAX);
}

std::string IMonitorModule::getProcessor(void)
{
    std::string line;
    std::string newLine;
    std::ifstream file("/proc/cpuinfo");
    char *str;

    while (std::getline(file, line)) {
        if (line.find("processor") != std::string::npos) {
            newLine = line.erase(0, 9);
        }
    }
    return newLine;
}

IMonitorModule::IMonitorModule()
{
    getFrequency();
    getCpuPercentage();
    getNames();
    getTime();
    getCpuName();
}

IMonitorModule::~IMonitorModule()
{
}
