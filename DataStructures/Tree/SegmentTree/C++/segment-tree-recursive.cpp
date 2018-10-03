#include <bits/stdc++.h>


using namespace std;


struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n_) {
        n = n_;
        tree.resize(2 * n + 5);
    }

    inline int leftChild(int node)  { return 2 * node + 1; }

    inline int rightChild(int node) { return 2 * node + 2; }

    void build(int node, int start, int end, int a[]) {
        if (start == end) {
            tree[node] = a[start];
        }
        else {
            int mid = (start + end) / 2;
            build(leftChild(node), start, mid, a);
            build(rightChild(node), mid + 1, end, a);
            tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
        }
    }

    void build(int a[]) { build(0, 0, 2 * n - 1, a); }

    /**
     * 3 cases:
     *   1. [start, end] completely outside of [left, right]
     *   2. [start, end] completely inside of [left, right]
     *   3. [start, end] partially inside of [left, right]
    **/
    int query(int node, int start, int end, int left, int right) {
        // Case 1
        if (start > right || end < left) {
            return 0;
        }
        // Case 2
        if (left <= start && end <= right) {
            return tree[node];
        }
        // Case 3
        int mid = (start + end) / 2;
        int p = query(leftChild(node), start, mid, left, right);
        int q = query(rightChild(node), mid + 1, end, left, right);
        return p + q;
    }

    int query(int left, int right) { return query(0, 0, 2 * n - 1, left, right); }

    void update(int node, int start, int end, int index, int inc) {
        if (start == end) {
            tree[node] += inc;
        }
        else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update(leftChild(node), start, mid, index, inc);
            }
            else {
                update(rightChild(node), mid + 1, end, index, inc);
            }
            tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
        }
    }

    void update(int index, int inc) { update(0, 0, 2 * n - 1, index, inc); }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    SegmentTree segmentTree(n);
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    segmentTree.build(a);

    int q;
    cin >> q;

    for (int j = 0; j < q; j++) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, inc;
            cin >> index >> inc;
            for (int i = index; i < n; i++) {
                segmentTree.update(index, inc);
            }
        }
        else {
            int left, right;
            cin >> left >> right;
            cout << segmentTree.query(left, right) << '\n';
        }
    }

    return 0;
}
