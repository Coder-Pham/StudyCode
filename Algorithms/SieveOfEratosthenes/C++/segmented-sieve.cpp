#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>

using namespace std;

vector<int> naiveSieve(int lim) {
    bool isPrime[lim + 1];
    fill(isPrime, isPrime + lim + 1, true);

    for (int i = 2; i <= lim; i++) {
        if (!isPrime[i]) continue;
        int composite = i * 2;
        while (composite <= lim) {
            isPrime[composite] = false;
            composite += i;
        }
    }

    vector<int> prime;
    for (int i = 2; i <= lim; i++) {
        if (isPrime[i]) prime.push_back(i);
    }
    return prime;
}

vector<long long> segmentedSieve(long long lim) {
    int sqrtLim = (int) ceil(sqrt(lim));
    vector<int> sprime = naiveSieve(sqrtLim);
    int nsmall = sprime.size();
    vector<long long> prime;
    for (int i = 0; i < nsmall; i++) {
        prime.push_back((long long) sprime[i]);
    }
    long long low = sqrtLim + 1;
    long long high = sqrtLim + sqrtLim;
    
    while (low < lim) {
        int n = high - low + 1;
        bool isPrime[n];
        fill(isPrime, isPrime + n, true);
        for (int i = 0; i < nsmall; i++) {
            long long p = (long long) sprime[i];
            long long composite = ceil((double) low / p) * p;
            while (composite <= high) {
                isPrime[composite - low] = false;
                composite += p;
            }
        }
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                prime.push_back(i + low);
            }
        }
        low += sqrtLim;
        high = (high + sqrtLim > lim) ? (lim) : (high + sqrtLim);
    }
    return prime;
}

int main() {
    ios_base::sync_with_stdio(0);
    const long long N = (long long) 1e11;
    vector<long long> prime = segmentedSieve(N);
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}