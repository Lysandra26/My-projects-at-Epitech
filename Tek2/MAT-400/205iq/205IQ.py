#!/usr/bin/env python3

import sys
from math import *

if len(sys.argv) == 1:
    print("ERROR : No arguments, -h for help")
    sys.exit(84)

if len(sys.argv) > 5 and (sys.argv[1]) != '-h' :
    print("ERROR : Too many arguments")
    sys.exit(84)

if len(sys.argv) < 3 and (sys.argv[1]) != '-h' :
    print("ERROR : Missing arguments")
    sys.exit(84)

def getPerct(tab, index):
    res = 0.0
    max = tab[len(tab) - 1]
    while (index < max):
        res = res + (1 / (float(tab[1]) * sqrt(2 * pi))) * exp(-0.5 * pow((float(index) - float(tab[0])) / float(tab[1]), 2))
        index = index + 0.01
    return res

def getIQ(tab):
    if len(tab) == 2:
        for x in range(201):
            result = (1 / (float(tab[1]) * sqrt(2 * pi))) * exp(-0.5 * pow((float(tab[0]) - float(x)) / float(tab[1]), 2))
            print(x, format(round(result, 5), ".5f"))
    elif len(tab) == 3:
        res = getPerct(tab, 0.0)
        print (format(res, ".1f"), "% of people have an IQ inferior to ", tab[2], sep="")
    elif len(tab) == 4:
        res = getPerct(tab, tab[2])
        print (format(res, ".1f"), "% of people have an IQ between ", tab[2]," and ", tab[3], sep="")


def main():
    tab = []
    if (sys.argv[1] == "-h"):
        print("USAGE")
        print("    ./205IQ u s [IQ1] [IQ2]\n")
        print("DESCRIPTION")
        print("    u       mean")
        print("    s       standard deviation")
        print("    IQ1     minimum IQ")
        print("    IQ2     maximum IQ")
        sys.exit(0)
    if len(sys.argv) >= 3 and len(sys.argv) <= 5:
        try:
            for i in range(1, len(sys.argv)):
                tab.append(int(sys.argv[i]))
                if (tab[i-1] < 0 or tab[i-1] > 200):
                    sys.exit(84)
        except:
            exit(84)
        getIQ(tab)
    sys.exit(0)

main()