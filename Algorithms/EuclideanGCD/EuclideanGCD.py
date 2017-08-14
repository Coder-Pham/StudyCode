def gcd(a, b):
    if (a > b):
        a, b = b, a
    while (b > 0):
        a = a % b
        a, b = b, a
    return a

def main():
    a = int(input())
    b = int(input())
    print(gcd(a, b))

if __name__ == "__main__":
    main()
