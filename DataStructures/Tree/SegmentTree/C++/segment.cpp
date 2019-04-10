/**
 * @author Nhat M. Nguyen
 * @update 10-04-19
**/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct SegmentTree {
    int n;
    vector<T> tree;

    inline int left(int node)  { return node * 2 + 1; }
    inline int right(int node) { return node * 2 + 2; }

    void build(vector<T>& a, int node, int node_range_low, int node_range_high) {
        if (node_range_low == node_range_high) {
            tree[node] = a[node_range_low];
        }
        else {
            int node_range_mid = (node_range_low + node_range_high) / 2;
            build(a, left(node), node_range_low, node_range_mid);
            build(a, right(node), node_range_mid + 1, node_range_high);
            tree[node] = tree[left(node)] + tree[right(node)];
        }
    }

    void build(vector<T>& a) {
        build(a, 0, 0, n - 1);
    }

    SegmentTree(vector<T>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a);
    }

    T query(int node, int node_range_low, int node_range_high, int query_range_low, int query_range_high) {
        if (node_range_low == query_range_low && node_range_high == query_range_high) {
            return tree[node];
        }
        else {
            int node_range_mid = (node_range_low + node_range_high) / 2;
            if (query_range_high <= node_range_mid) {    // only the left child stores query range
                return query(left(node), node_range_low, node_range_mid, query_range_low, query_range_high);
            }
            else if (query_range_low > node_range_mid) { // only the right child stores query range
                return query(right(node), node_range_mid + 1, node_range_high, query_range_low, query_range_high);
            }
            else {                                       // both children store query range
                return query(left(node), node_range_low, node_range_mid, query_range_low, node_range_mid)
                     + query(right(node), node_range_mid + 1, node_range_high, node_range_mid + 1, query_range_high);
            }
        }
    }

    T query(int query_range_low, int query_range_high) {
        return query(0, 0, n - 1, query_range_low, query_range_high);
    }

    void update(int node, int node_range_low, int node_range_high, int pos, int new_val) {
        if (node_range_low == node_range_high) {
            tree[node] = new_val;
        }
        else {
            int node_range_mid = (node_range_low + node_range_high) / 2;

            if (pos <= node_range_mid) {
                update(left(node), node_range_low, node_range_mid, pos, new_val);
            }
            else {
                update(right(node), node_range_mid + 1, node_range_high, pos, new_val);
            }

            tree[node] = tree[left(node)] + tree[right(node)];
        }
    }

    void update(int pos, int new_val) {
        update(0, 0, n - 1, pos, new_val);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a) {
        cin >> x;
    }

    SegmentTree<int> seg_tree(a);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos, new_val;
            cin >> pos >> new_val;
            seg_tree.update(pos, new_val);
        }
        else {
            int low, high;
            cin >> low >> high;
            cout << seg_tree.query(low, high) << '\n';
        }
    }

    return 0;
}
