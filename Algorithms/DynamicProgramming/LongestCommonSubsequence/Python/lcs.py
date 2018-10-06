'''
    Author: Pham Trong Nhan
    Date: 19/8/2018
    Method: Dynamic Programming
'''


def LCS(x, y):
    '''Longest common substring

    Arguments:
        x {string} -- First string
        y {string} -- Second string

    Param: L[i, j] is length of longest substring take from x[:i] and y[:j]

    Returns:
        [int] -- Length of longest common substring 
    '''
    L = [[0]*(len(y) + 1) for _ in range(len(x) + 1)]
    for i in range(len(x) + 1):
        for j in range(len(y) + 1):
            if (i == 0 or j == 0):
                L[i][j] = 0
            elif x[i - 1] == y[j - 1]:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i][j-1], L[i-1][j])

    return L[len(x)][len(y)]


def main():
    x = input('X: ')
    y = input('Y: ')
    print('Length of LCS: {}'.format(LCS(x, y)))


if __name__ == '__main__':
    main()
