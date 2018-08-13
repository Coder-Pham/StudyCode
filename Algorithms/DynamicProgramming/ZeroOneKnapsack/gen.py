import random

def rdint(lower, upper):
    return random.randint(lower, upper)

def rddouble(lower, upper):
    return random.uniform(double(lower), double(upper))

def main():
    N = rdint(1, 100)
    W = rdint(1, 1000)

    print("{0} {1}".format(N, W))

    for i in range(N):
        v = rdint(1, 100)
        print(v, end=' ')
    print()
    for i in range(N):
        w = rdint(1, 1000)
        print(w, end=' ')
    print()


if __name__ == "__main__":
    main()
