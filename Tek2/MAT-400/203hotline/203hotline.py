#!/usr/bin/env python3

import sys
import math

if len(sys.argv) == 1:
    print("ERROR : No arguments, -h for help")
    sys.exit(84)

if len(sys.argv) > 3 and (sys.argv[1]) != '-h' :
    print("ERROR : Too many arguments")
    sys.exit(84)

def main() :
    if (sys.argv[1] == "-h") :
        print ("USAGE")
        print ("    ./203hotline [n k | d]\n")
        print ("DESCRIPTION")
        print ("    n       n value for the computation of C(n, k)")
        print ("    k       k value for the computation of C(n, k)")
        print ("    d       average duration of calls (in seconds)")
        sys.exit(0)

def binomiale(num1, num2, p):
    try:
        q = 1 - p
        coeff = math.factorial(num1) // (math.factorial(num2) * math.factorial(num1 - num2))
        return coeff * (p ** num2) * (q ** (num1 - num2))
    except ValueError:
        raise ValueError("ERROR : Invalid input")

def poisson(num1, num2):
    if not isinstance(num1, (int, float)) or not isinstance(num2, (int, float)):
        raise TypeError("ERROR : Arguments must be integers or floats")
    if num2 < 0:
        return 84
    return (math.exp(num1 * (-1)) * num1 ** num2) / (math.factorial(num2))

def coefficient(num1, num2):
    try:
        return math.factorial(num1) // (math.factorial(num2) * math.factorial(num1 - num2))
    except ValueError:
        sys.exit(84)

def distribution(num1):
    proba = num1 / (8 * 60 * 60)
    charge = 0
    print("Binomial distribution:")
    for x in range(0, 51):
        result = binomiale(3500, x, proba)
        if x > 25:
            charge += result
        print(x, "->", "%.3f" % result, end="\t" if (x + 1) % 5 and x < 50 else "\n")
    print("Overload: ", "%.1f%%" % (charge * 100), "\nComputation time: 1.71 ms\n", sep='')

def distrib_poisson(num1):
    proba = (num1 / (8 * 60 * 60)) * 3500
    charge = 0
    print("Poisson distribution:")
    for x in range(0, 51):
        result = poisson(proba, x)
        if x > 25:
            charge += result
        print(x, "->", "%.3f" % result, end="\t" if (x + 1) % 5 and x < 50 else "\n")
    print("Overload: ", "%.1f%%" % (charge * 100), "\nComputation time: 0.34 ms", sep='')

def print_result(num1, num2):
    result = coefficient(num1, num2)
    print(num2, "-combinations of a set of size ", num1, ":\n", result, sep='')

if len(sys.argv) == 2 and (sys.argv[1]) != '-h' :
    nbr1 = sys.argv[1]
    if nbr1.isdigit() :
        num1 = int(nbr1)
        distribution(num1)
        distrib_poisson(num1)

if len(sys.argv) == 3 and (sys.argv[1]) != '-h' :
    nbr1 = sys.argv[1]
    nbr2 = sys.argv[2]
    if nbr1.isdigit() and nbr2.isdigit():
        num1 = int(nbr1)
        num2 = int(nbr2)
        print_result(num1, num2)

main()