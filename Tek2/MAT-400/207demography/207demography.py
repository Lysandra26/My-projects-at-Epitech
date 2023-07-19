#!/usr/bin/env python3

import sys
from math import *

if len(sys.argv) == 1:
    print("ERROR : No arguments, -h for help")
    sys.exit(84)

if len(sys.argv) > 2 and (sys.argv[1]) != '-h' :
    print("ERROR : Too many arguments")
    sys.exit(84)

def main():
    tab = []
    if (sys.argv[1] == "-h"):
        print("USAGE")
        print("    ./207demography [code]+\n")
        print("DESCRIPTION")
        print("    code       number of values")
        sys.exit(0)
    if len(sys.argv) <= 2:
        try:
            n = float(sys.argv[1])
        except:
            exit(84)
    sys.exit(0)

main()