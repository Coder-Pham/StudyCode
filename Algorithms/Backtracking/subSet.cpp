#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <time.h>
#include <vector>
#include <utility>

#define debug(X) { cerr << #X << " = " << (X) << endl; }

using namespace std;

int n, k;
vector<int> v;

void init() {
    cin >> n >> k;
    v.resize(k + 1);
    v[0] = 0;
}

void printSeq() {
    for (int i = 1; i <= k; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void backtrack(int p) {
    if (p == k + 1) {
        printSeq();
        return;
    }
    // v[p - 1] + 1 <= v[p] <= n - k + p
    for (int i = v[p - 1] + 1; i <= n - k + p; i++) {
        v[p] = i;
        backtrack(p + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
#ifdef MYMACHINE
    int testNumber;
    cin >> testNumber;
    string inFile = to_string(testNumber) + ".in";
    freopen(inFile.c_str(), "r", stdin);
    clock_t programBeginTime = clock();
#endif
// ______________________________________________

    init();
    backtrack(1);


// ______________________________________________
#ifdef MYMACHINE
    clock_t programEndTime = clock();
    double programElapsedTime = (double) (programEndTime - programBeginTime);
    cerr << "Time elapsed: " << programElapsedTime / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
