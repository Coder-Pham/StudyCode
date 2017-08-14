#include <iostream>
#include <vector>

using namespace std;

const int INF = (int) 1e3;
int n;
vector<int> x(INF);
vector<int> sum(INF);

void init() {
    cin >> n;
    // x[0] = 1 so that x[1] start at 1
    x[0] = 1;
    sum[0] = 0;
}

void printSeq(int len) {
    cout << x[1];
    for (int i = 2; i <= len; i++) {
        cout << " + " << x[i];
    }
    cout << "\n";
}

void backtrack(int p) {
    // the pth addend must be equal or greater than the (p - 1)th addend
    for (int i = x[p - 1]; sum[p - 1] + i <= n; i++) {
        x[p] = i;
        sum[p] = sum[p - 1] + x[p];
        if (sum[p] < n) {
            backtrack(p + 1);
        }
        else if (sum[p] == n) {
            printSeq(p);
            return;
        }
        else {
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    init();
    backtrack(1);
    return 0;
}
