#!/usr/bin/python3


import random


def rdint(lower, upper):
    return random.randint(lower, upper)


def rddouble(lower, upper):
    return random.uniform(double(lower), double(upper))


def main():
    n = rdint(1, 1000)
    print(n)

    for i in range(n):
        x = rdint(1, 1000)
        print(x, end=' ')
    print()

    q = rdint(100, 1000)
    print(q)

    for i in range(q):
        if i == q - 1:
            qType = 2
        else:
            qType = rdint(1, 2)

        print(qType)

        if qType == 1:
            pos = rdint(0, n - 1)
            nval = rdint(1, 1000)
            print("{0} {1}".format(pos, nval))
        else:
            left = rdint(0, n - 1)
            right = rdint(left, n - 1)
            print("{0} {1}".format(left, right))


if __name__ == "__main__":
    main()
