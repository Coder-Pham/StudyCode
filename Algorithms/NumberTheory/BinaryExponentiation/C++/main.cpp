#include<bits/stdc++.h>

using namespace std;

/**
 * Calculate a^x
**/
int64_t BinExp(int64_t a, int64_t x) {
    int64_t res = 1;

    while (x > 0) {
        if (x & 1) {
            res *= a;
        }

        a *= a;
        b >>= 1;
    }

    return res;
}

/**
 * Calculate a^x
**/
int64_t BinExp(int64_t a, int64_t x, int64_t m) {
    int64_t res = 1;

    while (x > 0) {
        if (x & 1) {
            res *= a;
            res %= m;
        }

        a *= a;
        a %= m;
        b >>= 1;
    }

    return res;
}

int main() {

    return 0;
}
