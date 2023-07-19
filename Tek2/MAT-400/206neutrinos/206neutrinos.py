#!/usr/bin/env python3

import sys, os
from math import *

if len(sys.argv) == 1:
    print("ERROR : No arguments, -h for help")
    sys.exit(84)

if len(sys.argv) > 5 and (sys.argv[1]) != '-h' :
    print("ERROR : Too many arguments")
    sys.exit(84)

if len(sys.argv) < 5 and (sys.argv[1]) != '-h' :
    print("ERROR : Missing arguments")
    sys.exit(84)

def print_result(nb, a, h, sd):
    while (True):
        input_user = input("Enter the next value: ")
        if (input_user == "END"):
            exit(0)
        value = float(input_user)
        if (value < 0):
            exit(84)
        total = a * nb
        temp = (sd * sd + a * a) * nb
        nb = nb + 1
        a = (total + value) / nb
        sd = sqrt(((temp + pow(value, 2)) / nb) - pow(a, 2))
        square = sqrt((temp + pow(value, 2)) / nb)
        h = nb / ((1 / value) + ((nb - 1) / h))
        print("\tNumber of value:\t%d" % nb)
        print("\tStandard deviation:\t%.2f" % sd)
        print("\tArithmetic mean:\t%.2f" % a)
        print("\tRoot mean square:\t%.2f" % square)
        print("\tHarmonic mean:\t\t%.2f" % h)

def main():
    tab = []
    if (sys.argv[1] == "-h"):
        print("USAGE")
        print("    ./206neutrinos n a h sd\n")
        print("DESCRIPTION")
        print("    n       number of values")
        print("    a       arithmetic mean")
        print("    h       harmonic mean")
        print("    sd      standart deviation")
        sys.exit(0)
    if len(sys.argv) <= 5:
        try:
            n = float(sys.argv[1])
            a = float(sys.argv[2])
            h = float(sys.argv[3])
            sd = float(sys.argv[4])
            if (n > 0 or a > 0 or h > 0 or sd > 0):
                print_result(n, a, h, sd)
                exit(0)
            else:
                exit(84)
        except ValueError:
            exit(86)
    exit(0)

main()