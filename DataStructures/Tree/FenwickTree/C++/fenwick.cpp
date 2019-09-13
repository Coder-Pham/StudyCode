/**
 * @author   Nhat M. Nguyen
 * @created  n/a
 * @updated  13-09-19
**/

#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    int n;
    int base;
    vector<int> tree;

    FenwickTree(int n, int base=0) : n(n), base(base) {
        assert(base == 0 || base == 1);
        tree.resize(n + 1);
    }

    void update(int pos, int inc) {
        pos += 1 - base;

        while (pos <= n) {
            tree[pos] += inc;
            pos += pos & (-pos);
        }
    }

    int query(int pos) {
        pos += 1 - base;
        int res = 0;

        while (pos > 0) {
            res += tree[pos];
            pos -= pos & (-pos);
        }

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    FenwickTree fenwick(n, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fenwick.update(i, x);
    }

    int q;
    cin >> q;

    for (int j = 0; j < q; j++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, inc;
            cin >> pos >> inc;
            fenwick.update(pos, inc);
        }
        else {
            int pos;
            cin >> pos;
            cout << fenwick.query(pos) << '\n';
        }
    }

    return 0;
}
