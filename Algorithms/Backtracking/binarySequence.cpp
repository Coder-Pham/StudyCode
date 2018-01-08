#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

void init() {
    cin >> n;
    v.resize(n);
}

void printSeq() {
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    cout << "\n";
}

void backtrack(int p) {
    if (p == n) {
        printSeq();
        return;
    }
    for (int i = 0; i <= 1; i++) {
        v[p] = i;
        backtrack(p + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    init();
    backtrack(0);
    return 0;
}
