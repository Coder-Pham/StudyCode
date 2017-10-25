#include <stdio.h>
#include <utility> // std::swap

using namespace std;

int calcGCD(int a, int b) {
    if (a < b) swap(a, b);
    while (b > 0) {
        a = a % b;
        if (a < b) swap(a, b);
    }
    return a;
}

long long calcLCM(int a, int b) {
    int gcd = calcGCD(a, b);
    long long lcm = (long long) (a / gcd) * b;
    return lcm;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("GCD of %d and %d is %d\n", x, y, calcGCD(x, y));
    printf("GCD of %d and %d is %I64d\n", x, y, calcLCM(x, y));
    return 0;
}