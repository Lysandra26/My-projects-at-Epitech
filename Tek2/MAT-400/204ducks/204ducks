#!/usr/bin/env python3

import sys
import math
from math import exp
from math import *

if len(sys.argv) == 1:
    print("ERROR : No arguments, -h for help")
    sys.exit(84)

if len(sys.argv) > 2 and (sys.argv[1]) != '-h' :
    print("ERROR : Too many arguments")
    sys.exit(84)

def compute_result(a, t, mode = 0):
    return -a * math.exp(-t) - (4 - 3 * a) / 2 * math.exp(-2 * t) - (2 * a - 4) / 4 * math.exp(-4 * t) if mode == 0 else a * math.exp(-t) + (4 - 3 * a) * math.exp(-2 * t) + (2 * a - 4) * math.exp(-4 * t)

def probability(x, y):
    return x * exp(-y) + (4 - 3 * x) * exp(-2 * y) + (2 * x - 4) * exp(-4 * y)

def come_back(x, y):
    a = 0.0
    result = 0.0
    while (a <= (y * 1000)):
        result += probability(x, a / 100)
        if (result >= y):
            return (a / 100)
        a += 1

def calc_derivation(v, x, y):
    return pow((y - v), 2) * (probability(x, y) / 10)

def calculate_ducks(x):
    proba = 0.0
    time_elapsed = 0.0
    standard_dev = 0.0
    expected_time = 0.0
    while (time_elapsed < 99.999):
        proba += (probability(x , time_elapsed) / 10)
        expected_time += time_elapsed * (probability(x, time_elapsed) / 10)
        time_elapsed += 0.001
    expected_time = (expected_time / 99.999)
    while (time_elapsed > 0):
        standard_dev += calc_derivation(expected_time, x, time_elapsed)
        time_elapsed -= 0.001
    standard_dev = (standard_dev / 99.9999)
    standard_dev = pow(standard_dev, 0.5)
    print_result(expected_time, standard_dev, x)

def print_result(time, deviation, x):
    av_min, av_sec = divmod(time * 60, 60)
    min50, sec50 = divmod(come_back(x, 50) * 61, 61)
    min99, sec99 = divmod(come_back(x, 99) * 60, 60)
    perc1min = (compute_result(x, 1) - compute_result(x, 0)) * 100
    perc2min = (compute_result(x, 2) - compute_result(x, 0)) * 100
    print("Average return time: %0.0fm %0.0fs" %(av_min, av_sec))
    print("Standard deviation: {0:.3f}".format(deviation))
    print("Time after which 50%% of the ducks are back: %0.0fm %02ds" %(min50, sec50))
    print("Time after which 99%% of the ducks are back: %0.0fm %02ds" %(min99, sec99))
    print(f"Percentage of ducks back after 1 minute: {perc1min:.1f}%")
    print(f"Percentage of ducks back after 2 minutes: {perc2min:.1f}%")

def main() :
    if (sys.argv[1] == "-h") :
        print ("USAGE")
        print ("    ./204ducks a\n")
        print ("DESCRIPTION")
        print ("    a       constant (between 0 and 2.5)")
        sys.exit(0)
    if len(sys.argv) == 2 and (sys.argv[1]) != '-h' :
        try:
            x = float(sys.argv[1])
        except:
            print("Error: Bad arguments: a must be a float")
            exit(84)
        if (x < 0 or x > 2.5):
            print("a must be between 0 and 2.5")
            exit(84)
        calculate_ducks(x)
        exit(0)

main()