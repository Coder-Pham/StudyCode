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
    v.resize(k);
}

void printSeq() {
    for (int i = 0; i < k; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

// the used vector is passed by value
// so that it can reset after generating a sequence
void backtrack(int p, vector<bool> used) {
    if (p == k) {
        printSeq();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        v[p] = i;
        used[i] = true;
        backtrack(p + 1, used);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    init();
    vector<bool> used(n + 1);
    fill(used.begin(), used.end(), false);
    backtrack(0, used);
    return 0;
}