"""
    @author Nhat M. Nguyen
    @date   20-04-18

"""


def naive_lcs(x, y):
    m = len(x)
    n = len(y)

    if m == 0 or n == 0:
        return 0

    if x[m - 1] == y[n - 1]:
        return naive_lcs(x[:(m - 1)], y[:(n - 1)]) + 1
    else:
        return max(naive_lcs(x[:(m - 1)], y),
                   naive_lcs(x, y[:(n - 1)]))


def main():
    x = "ABCBDAB"
    y = "BDCABA"
    print("Length of LCS: {0}".format(naive_lcs(x, y)))


if __name__ == "__main__":
    main()

# result: 4
