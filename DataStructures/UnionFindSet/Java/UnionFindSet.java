/**
 *  @author Nhat M. Nguyen
 *  @update 07-08-18
**/


class UnionFindSet {
    int n;
    int[] parent;
    int[] rank;

    UnionFindSet(int n_) {
        n = n_;
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return find(parent[u]);
    }

    void union(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u  == root_v) return;
        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        }
        else if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        }
        else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }

    int numComponents() {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                res++;
            }
        }
        return res;
    }
}