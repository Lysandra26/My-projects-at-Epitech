#!/usr/bin/env python3

import sys

def XY_law(tab, X_exp, Y_exp):
    print("--------------------------------------------------------------------------------")
    print("\tX=10\tX=20\tX=30\tX=40\tX=50\tY law")
    for i in range(len(tab)):
        print("Y=" + str((i + 1) * 10), end='\t')
        for j in range(len(tab[i])):
            print("%.3f" % tab[i][j], end='\t')
        Y_exp.append(calc_tab(tab, i, 0, 1))
        print("%.3f" % calc_tab(tab, i, 0, 1))
    print("X law\t", end='')
    for s in range(len(tab) - 1):
        X_exp.append(calc_tab(tab, 0, s, 0))
        print("%.3f" % calc_tab(tab, 0, s, 0), end='\t')
    X_exp.append(calc_tab(tab, 0, s + 1, 0))
    print("%.3f" % calc_tab(tab, 0, s + 1, 0) + "\t1.000")
    print("--------------------------------------------------------------------------------")

def Z_law(a, b):
    z = 2
    print("z\t20\t30\t40\t50\t60\t70\t80\t90\t100\np(Z=z)", end='')
    for z in range(2, 11):
        value = 0.0
        summ = 0.0
        for y in range(1, 6):
            for x in range(1, 6):
                value = result(x * 10, y * 10, a, b)
                if (x + y == z and y < 6):
                    summ += value
        print("\t%0.3f" %(summ), end='')
    print("\t")

def Variance(X_exp, Y_exp):
    totalX = sum(X_exp[i] * ((i + 1) * 10) for i in range(5))
    totalY = sum(Y_exp[i] * ((i + 1) * 10) for i in range(5))
    expX = sum(((i + 1) * 10 - totalX) ** 2 * X_exp[i] for i in range(5))
    expY = sum(((i + 1) * 10 - totalY) ** 2 * Y_exp[i] for i in range(5))
    print("--------------------------------------------------------------------------------")
    print("expected value of X:\t" + "%0.1f" % totalX)
    print("variance of X:\t\t" + "%0.1f" % expX)
    print("expected value of Y:\t" + "%0.1f" % totalY)
    print("variance of Y:\t\t" + "%0.1f" % expY)
    print("expected value of Z:\t" + "%0.1f" % (totalX + totalY))
    print("variance of Z:\t\t" + "%0.1f" % (expX + expY))
    print("--------------------------------------------------------------------------------")

def result(x, y, a, b):
    return ((a - x) * (b - y)) / ((5 * a - 150) * (5 * b - 150))

def create_tab(a, b):
    return [[float(result((x + 1) * 10, (y + 1) * 10, a, b)) for x in range(5)] for y in range(5)]

def calc_tab(tab, i, j, mode):
    result = 0
    for _ in range(5):
        result += tab[i][j]
        if mode == 1:
            j += 1
        else:
            i += 1
    return result

def main():
    if len(sys.argv) == 2:
        if sys.argv[1] == "-h":
            print("USAGE")
            print("    ./202unsold a b\n")
            print("DESCRIPTION")
            print("    a       constant computed from past results")
            print("    b       constant computed from past results")
            sys.exit(0)
        else:
            exit(84)
    if len(sys.argv) == 3:
        X_exp = []
        Y_exp = []
        try:
            a = int(sys.argv[1])
            b = int(sys.argv[2])
            if a <= 50 or b <= 0:
                exit(84)
        except:
            exit(84)
        tab = create_tab(a, b)
        XY_law(tab, X_exp, Y_exp)
        Z_law(a, b)
        Variance(X_exp, Y_exp)
    else:
        sys.stdout.write("Invalid number of arguments\n")
        exit(84)

main()
