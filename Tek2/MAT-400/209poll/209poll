#!/usr/bin/env python3

import sys
from math import *

if len(sys.argv) == 1:
    print("ERROR : No arguments, -h for help")
    sys.exit(84)

if len(sys.argv) > 4 and (sys.argv[1]) != '-h' :
    print("ERROR : Too many arguments")
    sys.exit(84)

if len(sys.argv) < 4 and (sys.argv[1]) != '-h' :
    print("ERROR : Missing arguments")
    sys.exit(84)

def variance(pSize, sSize, p):
    p /= 100
    d = (p * (1 - p)) * (pSize - sSize)
    n = sSize * (pSize - 1)
    result = d / n
    return result

def compute(x):
    return x * 100.0 / 2.0

def print_conf(p, var):
    conf95 = compute(2 * 1.96 * sqrt(var))
    conf99 = compute(2 * 2.58 * sqrt(var))
    print("95%% confidence interval: [%.2f%%; %.2f%%]" % (max(0, p - conf95), min(100, p + conf95)))
    print("99%% confidence interval: [%.2f%%; %.2f%%]" % (max(0, p - conf99), min(100, p + conf99)))

def print_result(pSize, sSize, p):
    var = variance(pSize, sSize, p)
    print(f"Population size:\t {pSize}")
    print(f"Sample size:\t\t {sSize}")
    print(f"Voting intentions:\t {p:.2f}%")
    print(f"Variance:\t\t {var:.6f}")
    print_conf(p, var)

def main():
    tab = []
    if (sys.argv[1] == "-h"):
        print("USAGE")
        print("    ./209poll pSize sSize p\n")
        print("DESCRIPTION")
        print("    pSize   size of the population")
        print("    sSize   size of the sample (supposed to be representative)")
        print("    p       percentage of vooting intentions for a specific candidate")
        sys.exit(0)
    if len(sys.argv) <= 4:
        try:
            pSize = int(sys.argv[1])
            sSize = int(sys.argv[2])
            p = float(sys.argv[3])
            if (pSize < 0):
                print("ERROR : must be positive")
            if (sSize < 0):
                print("ERROR : must be positive")
            if (0.0 >= p >= 100.0):
                print("ERROR : must be a float")
            if (pSize <= sSize):
                print("ERROR : pSize should be < sSize")
            print_result(pSize, sSize, p)
        except:
            exit(84)
    sys.exit(0)

main()