/**
 * @author Nhat M. Nguyen
 * @date   16-04-18
**/


/**
 * Naive sieve
 * + Time complexity   O(nlog(n)log(log(n)))
 * + Space complexity  O(n)
 *
 * Segmented sieve
 * + Time complexity   O(nlog(n)log(log(n)))
 * + Space complexity  O(sqrt(n))
**/


#include <bits/stdc++.h>


#ifdef DEBUG
    #define dcerr(x) \
        cerr << "$ " << setw(20) << \
            #x << setw(3) << "=" << setw(20) << x << "\n"

    #define dcout(x) \
        cout << "$ " << setw(20) << \
            #x << setw(3) << "=" << setw(20) << x << "\n"
#else
    #define dcerr(x)
    #define dcout(x)
#endif


using namespace std;


const long long N = (long long) 1e2;


vector<int> small_primes;
vector<long long> primes;


void naive_sieve() {
    cout << "Doing naive sieve...\n";
    int n = (int) ceil(sqrt(N));
    int sqrt_n = (int) ceil(sqrt(n));

    bool is_prime[n + 1];
    
    fill(is_prime, is_prime + n + 1, true);

    for (int i = 2; i <= sqrt_n; i++) {
        int composite = i * 2;
        while (composite <= n) {
            is_prime[composite] = false;
            composite += i;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            small_primes.push_back(i);
        }
    }
}


void segmented_sieve() {
    naive_sieve();
    int n = (int) ceil(sqrt(N));
    for (int i = 0;i < (int) small_primes.size(); i++) {
        primes.push_back(small_primes[i]);
    }
    long long low = n;
    long long high = n * 2;
    int cnt = 0;
    while (low <= N) {
        int range = high - low;
        bool is_prime[range];
        fill(is_prime, is_prime + range, true);
        for (int i = 0; i < (int) small_primes.size(); i++) {
            int mult = (int) ceil((double) low / small_primes[i]);
            long long composite = mult * small_primes[i];
            while (composite < high) {
                is_prime[composite - low] = false;
                composite += small_primes[i];
            }
        }
        for (int i = 0; i < range; i++) {
            if (is_prime[i]) {
                primes.push_back(i + low);
            }
        }
        low += n;
        if (high + n < N) {
            high += n;
        }
        else {
            high = N;
        }
        cnt++;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);

    segmented_sieve();
    int num_primes = primes.size();
    for (int i = 0; i < num_primes; i++) {
        cout << primes[i] << endl;
    }

    return 0;
}
