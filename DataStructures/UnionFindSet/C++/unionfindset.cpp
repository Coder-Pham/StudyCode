/**
 * @author Nhat M. Nguyen
 * @date   28-07-18
**/


/**
 * In this version, UnionFindSet is coded as a struct.
 * This code has been used for the following submission:
 *   http://codeforces.com/contest/977/submission/40633339
**/


const int MAX = (int) (2 * 1e5 + 1);


struct UnionFindSet {
    int parent[MAX];
    int depth[MAX];

    UnionFindSet() {
        for (int i = 0; i < MAX; i++) {
            parent[i] = i;
            depth[i] = 0;
        }
    }

    int find(int u) {
        while (parent[u] != u) {
            u = parent[u];
        }
        return u;
    }

    void merge(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v) {
            return;
        }
        if (depth[root_u] < depth[root_v]) {
            parent[root_u] = root_v;
        }
        else if (depth[root_u] > depth[root_v]) {
            parent[root_v] = root_u;
        }
        else {
            parent[root_u] = root_v;
            depth[root_v]++;
        }
    }
};


int main() {
    UnionFindSet ufs;
    return 0;
}
