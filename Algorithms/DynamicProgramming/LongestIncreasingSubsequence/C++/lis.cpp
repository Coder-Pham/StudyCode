/**
 * @author    Nhat M. Nguyen
 * @created   22-04-18
 * @updated   23-08-19
**/

/**
 *  Idea: LIS(i) must contains MAX(LIS(j)) where
 *      0 < j < i and a[j] < a[i]
 *  Time complexity: O(n^2)
**/

#include <bits/stdc++.h>

using namespace std;

struct Result {
    int length;
    vector<int> seq;

    friend ostream& operator<<(ostream& os, const Result& res) {
        os << "{Length = " << res.length << "; ";
        os << "Sequence = [ ";
        for (auto x : res.seq) {
            os << x << ' ';
        }
        os << "]}\n";
        return os;
    }
};

Result CalcLIS(const vector<int>& a) {
    int n = a.size();
    vector<int> lis(n, 0);
    vector<int> pred(n, -1);

    Result res;
    res.length = 0;

    lis[0] = 1; // base case

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && lis[i] < lis[j]) {
                lis[i] = lis[j];
                pred[i] = j;
            }
        }
        lis[i]++;
    }

    int en = 0;

    for (int i = 1; i < n; i++) {
        if (lis[en] < lis[i]) {
            en = i;
            res.length = lis[en];
        }
    }

    for (int i = en; i != -1; i = pred[i]) {
        res.seq.push_back(i);
    }

    reverse(res.seq.begin(), res.seq.end());

    return res;
}

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << CalcLIS(a) << "\n";
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case " << i << ":\n";
        Solve();
    }

    return 0;
}
