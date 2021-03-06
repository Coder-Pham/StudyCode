/**
 * @author   Nhat M. Nguyen
 * @created  04-11-18
**/

#include <bits/stdc++.h>

using namespace std;

const int N = (int) (1e6 + 1);
const int SQRT_N = (int) ((double) sqrt(N));
int spf[N];

void SieveSPF() { // O(nlog(log(n)))
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }

    for (int i = 2; i <= SQRT_N; i++) {
        if (spf[i] == i) { // i is a prime number
            int j = i * i;
            while (j < N) {
                if (spf[j] == j) { // only change spf[j] if it is not changed yet
                    spf[j] = i;
                }
                j += i;
            }
        }
    }
}

void Solve() {
    SieveSPF();

    int n;
    cin >> n;

    vector<int> factors;
    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }

    for (int& factor : factors) {
        cout << factor << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}