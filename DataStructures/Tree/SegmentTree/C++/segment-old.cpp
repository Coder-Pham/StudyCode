/**
 * @author Nhat M. Nguyen
 * @update 03-10-18
**/


#include <bits/stdc++.h>


using namespace std;


struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n_) {
        n = n_;
        tree.resize(n * 2);
    }

    inline int parent(int node)     { return node / 2; }

    inline int leftChild(int node)  { return node * 2; }

    inline int rightChild(int node) { return node * 2 + 1; }

    void build(vector<int> &a) {
        // Leaves are stored in tree[n + 0.. n + n - 1]
        for (int i = n - 1; i > -1; i--) {
            tree[n + i] = a[i];
        }
        // Build internal vertices upward
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[leftChild(i)] + tree[rightChild(i)];
        }
    }

    int query(int left, int right) {
        int left_node = left + n;
        int right_node = right + n;
        int res = 0;

        while (left_node <= right_node) {
            if (left_node % 2 != 0) { // is right child of its parent
                res += tree[left_node];
                left_node++;
            }
            if (right_node % 2 == 0) { // is left child of its parent
                res += tree[right_node];
                right_node--;
            }
            left_node  = parent(left_node);
            right_node = parent(right_node);
        }

        return res;
    }

    void update(int index, int inc) {
        int node = index + n;
        while (node > 0) {
            tree[node] += inc;
            node = parent(node);
        }
    }

    void modify(int index, int val) {
        int node = index + n;
        tree[node] = val;
        node = parent(node);
        while (node > 0) {
            tree[node] = tree[leftChild(node)] + tree[rightChild(node)];
            node = parent(node);
        }
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    SegmentTree segmentTree(n);
    vector<int> a;
    a.resize(n);

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
            segmentTree.update(index, inc);
        }
        else {
            int left, right;
            cin >> left >> right;
            cout << segmentTree.query(left, right) << '\n';
        }
    }

    return 0;
}
