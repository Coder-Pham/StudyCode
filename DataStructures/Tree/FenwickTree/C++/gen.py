#!/usr/bin/python3


import random


def rdint(lower, upper):
    return random.randint(lower, upper)


def rddouble(lower, upper):
    return random.uniform(double(lower), double(upper))


def main():
    n = rdint(1, 10)
    print(n)

    for i in range(n):
        x = rdint(1, 10)
        print(x, end=' ')
    print()

    q = rdint(3, 5)
    print(q)

    for i in range(q):
        if i == q - 1:
            t = 2
        else:
            t = rdint(1, 2)

        print(t, end=' ')

        if t == 1:
            pos = rdint(0, n - 1)
            inc = rdint(1, 5)
            print("{0} {1}".format(pos, inc))
        else:
            pos = rdint(0, n - 1)
            print(pos)


if __name__ == "__main__":
    main()
