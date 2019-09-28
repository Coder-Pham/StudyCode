/**
 * @author   Nhat M. Nguyen
 * @created  29-09-19
**/

#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e7;
vector<int> spf;
vector<int> primes;

int main() {
    spf.resize(N + 1, 0);

    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && i * primes[j] <= N; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }

    for (int x : primes) {
        cout << x << '\n';
    }

    return 0;
}