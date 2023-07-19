#!/usr/bin/env python3

import sys
from math import *

if len(sys.argv) == 1:
    print("ERROR : No arguments, -h for help")
    sys.exit(84)

if len(sys.argv) < 6 and (sys.argv[1]) != '-h' :
    print("ERROR : Not enough arguments")
    sys.exit(84)

if len(sys.argv) > 7 and (sys.argv[1]) != '-h' :
    print("ERROR : Too many arguments")
    sys.exit(84)

def main() :
    if (sys.argv[1] == "-h") :
        print ("USAGE")
        print ("    ./201yams d1 d2 d3 d4 d5 c\n")
        print ("DESCRIPTION")
        print ("    d1      value of first die (0 if not thrown)")
        print ("    d2      value of second die (0 if not thrown)")
        print ("    d3      value of third die (0 if not thrown)")
        print ("    d4      value of fourth die (0 if not thrown)")
        print ("    d5      value of fifth die (0 if not thrown)")
        print ("    c       expected combination")
        sys.exit(0)

def binomiale(a, b):
    res = (factorial(a) / (factorial(b) * factorial(a-b))) * pow(1/6, b) * pow(5/6, a-b)
    return (res)

def comb():
    if (list[0] == "yams") :
        probability = result(5, list[1])
        print(f"Chances to get a {list[1]} yams: {probability:.2f}%")
        return
    if (list[0] == "pair") :
        probability = result(2, list[1])
        print(f"Chances to get a {list[1]} pair: {probability:.2f}%")
        return
    if (list[0] == "three") :
        probability = result(3, list[1])
        print(f"Chances to get a {list[1]} three-of-a-kind: {probability:.2f}%")
        return
    if (list[0] == "four") :
        probability = result(4, list[1])
        print(f"Chances to get a {list[1]} four-of-a-kind: {probability:.2f}%")
        return
    if (list[0] == "full") :
        probability = 0
        print(f"Chances to get a {list[1]} full of {list[2]}: {probability:.2f}%")
        return
    if (list[0] == "straight") :
        probability = 0
        print(f"Chances to get a {list[1]} straight: {probability:.2f}%")
        return
    return

def apparition_dice(nb):
    apparition = 0
    if d1 == nb:
        apparition += 1
    if d2 == nb:
        apparition += 1
    if d3 == nb:
        apparition += 1
    if d4 == nb:
        apparition += 1
    if d5 == nb:
        apparition += 1
    return apparition

def result(dice, nb):
    result = 0.0
    apparition = apparition_dice(nb)
    if dice < apparition:
        result = 1
    else:
        for n in range(dice - apparition, 6 - apparition):
            result += binomiale(5 - apparition, n)
    return result * 100

nbList = list()

d1 = sys.argv[1]
try:
    d1 = int(d1)
    nbList.append(d1)
except:
    sys.exit(84)

d2 = sys.argv[2]
try:
    d2 = int(d2)
    nbList.append(d2)
except:
    sys.exit(84)

d3 = sys.argv[3]
try:
    d3 = int(d3)
    nbList.append(d3)
except:
    sys.exit(84)

d4 = sys.argv[4]
try:
    dice_4 = int(d4)
    nbList.append(d4)
except:
    sys.exit(84)

d5 = sys.argv[5]
try:
    d5 = int(d5)
    nbList.append(d5)
except:
    sys.exit(84)

combination = sys.argv[6]
list = []
list = combination.split('_')
try:
    dice_choice = int(list[1])
    if (dice_choice < 0 or dice_choice > 6):
        sys.exit(84)
except:
    sys.exit(84)

if (list[0] == "yams" or list[0] == "pair" or list[0] == "three" or list[0] == "four" or list[0] == "full" or list[0] == "straight"):
    comb()
else:
    print("Bad combanition, see -h for help")
    sys.exit(84)

main()