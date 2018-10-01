/**
 *  Author Nhat M. Nguyen
 *  Update 01-10-18
**/


#include <algorithm> // std::sort
#include <iostream>
#include <vector>


using namespace std;


struct DSU {
    int n;
    vector<int> root;

    DSU(int n_) {
        n = n_;
        root.resize(n);
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    };

    int find(int u) {
        while (u != root[u]) {
            u = root[u];
        }
        return u;
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        root[v] = u;
        return true;
    }
};


struct Edge {
    int u, v, w;

    Edge(int u_, int v_, int w_) {
        u = u_, v = v_, w = w_;
    }
};

int main() {
    // Get number of vertices and edges, and description of all edges
    int nV, nE;
    cin >> nV >> nE;

    vector<Edge> edges;

    for (int i = 0; i < nE; i++) {
        int u, v, w;
        edges.emplace_back(u, v, w);
    }

    // Sort all edges in ascending order of weight
    sort(edges.begin(), edges.end(),
        [] (Edge e1, Edge e2) {
            return e1.w < e2.w;
        });

    // Union-Find set for all vertices
    DSU dsu(nV);

    // Kruskal's Minimum Spanning Tree
    vector<Edge> mst;
    int min_cost = 0;

    for (Edge edge : edges) {
        int root_u = dsu.find(edge.u);
        int root_v = dsu.find(edge.v);
        if (dsu.merge(root_u, root_v)) {
            mst.push_back(edge);
        }
    }

    for (Edge edge : mst) {
        min_cost += edge.w;
    }

    cout << "Min cost: " << min_cost << "\n";

    return 0;
}


/*
  TEST

+ IN:
7 10
0 1 4
0 3 1
1 2 5
1 3 10
1 4 4
2 4 1
3 5 3
4 5 5
4 6 10
5 6 10

+ OUT:
Min cost: 23

*/

