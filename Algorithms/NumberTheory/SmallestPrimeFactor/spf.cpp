/**
 * @author Nhat M. Nguyen
 * @date   04-11-18
**/


#include <bits/stdc++.h>


using namespace std;


const int N = (int) (1e6 + 1);
const int SQRT_N = (int) ((double) sqrt(N));
int spf[N];


void preprocessSPF() { // O(nlog(log(n)))
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }

    for (int i = 2; i <= SQRT_N; i++) {
        if (spf[i] == i) { // i is a prime number
            int j = i + i;
            while (j < N) {
                if (spf[j] == j) { // only change spf[j] if it is unchanged before
                    spf[j] = i;
                }
                j += i;
            }
        }
    }
}


void solve() {
    preprocessSPF();

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
    solve();
    return 0;
}