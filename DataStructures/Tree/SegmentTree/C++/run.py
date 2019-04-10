#!/usr/bin/python3

import os
import time


NUM_TESTS = 1000
GEN       = "python3 gen.py"
SLOW      = "./slow"
FAST      = "./segment"

"""
    This code should work on both Windows and Linux
    3 files:
    inf: input file
    ouf: output file
    anf: answer (correct output) file
"""


def run_test():
    os.system("{0} > inf".format(GEN))
    os.system("{0} < inf > anf".format(SLOW))

    begin_time = time.time()
    os.system("{0} < inf > ouf".format(FAST))
    time_taken = time.time() - begin_time

    ouf_tokens = []
    anf_tokens = []

    with open ("ouf", 'r') as f:
        for line in f:
            ouf_tokens += line.split()

    with open ("anf", 'r') as f:
        for line in f:
            anf_tokens += line.split()

    if len(ouf_tokens) != len(anf_tokens):
        print("WA: mismatched number of tokens")
        return False
    else:
        for i in range(len(ouf_tokens)):
            if anf_tokens[i] != ouf_tokens[i]:
                print("WA: different in token #{0}".format(i))
                print("ouf token: {0}".format(ouf_tokens[i]))
                print("anf token: {0}".format(anf_tokens[i]))
                return False

    print("AC - time taken: {0:.6f}".format(time_taken))
    return True


def main():
    for i in range(NUM_TESTS):
        print("#Test {0}: ".format(i), end='')
        result = run_test()
        if result == False:
            break

    if result == True:
        print("Good!")


if __name__ == "__main__":
    main()
