#!/usr/bin/python3

import os
import time


NUM_TESTS = 1000
FAST = "st"
SLOW = "slow"


FLAGS = "-std=c++17 -Wall -Wextra -O2"


"""
    3 types of files:
    _i: input
    _o: right output, produced by SLOW
    _a: answer/attempt, produced by FAST
"""


def compile_cpp(file):
    print("Compiling {0}.cpp...".format(file))
    os.system("g++ {0} {1}.cpp -o {1}".format(FLAGS, file))


def compile():
    compile_cpp(SLOW)
    compile_cpp(FAST)


def run_test(test_index):
    # os.system("python3 gen.py |& tee -a in.txt")
    os.system("./gen.py > _i.txt")

    os.system("./{0} < _i.txt > _o.txt".format(SLOW))

    begin_time = time.time()
    os.system("./{0} < _i.txt > _a.txt".format(FAST))
    time_taken = time.time() - begin_time

    a_tokens = []
    o_tokens = []

    with open ("_a.txt", 'r') as f:
        for line in f:
            a_tokens += line.split()

    with open ("_o.txt", 'r') as f:
        for line in f:
            o_tokens += line.split()

    if len(a_tokens) != len(o_tokens):
        print("WA: mismatched number of tokens")
        return False
    else:
        for i in range(len(a_tokens)):
            if o_tokens[i] != a_tokens[i]:
                print("WA: different in token #{0}".format(i))
                return False

    # os.system("rm _i.txt _a.txt _o.txt")
    print("AC - time taken: {0:.6f}".format(time_taken))
    return True


def main():
    print("Compile?", end=' ')
    compile() if input() == 'y' else 0

    for i in range(NUM_TESTS):
        print("#Test {0}: ".format(i), end='')
        result = run_test(i)
        if result == False:
            break
    if result == True:
        print("All accepted!")


if __name__ == "__main__":
    main()
