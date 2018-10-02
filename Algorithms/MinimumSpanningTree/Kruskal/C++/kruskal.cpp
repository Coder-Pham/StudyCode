/**
 *  Author Nhat M. Nguyen
 *  Update 02-10-18
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
        u = find(u);
        v = find(v);
        if (u == v) return false;
        root[v] = u;
        return true;
    }
};


struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main() {
    // Get number of vertices and edges
    int nVertices, nEdges;
    cin >> nVertices >> nEdges;

    // Get all edges
    vector<Edge> edges;

    for (int i = 0; i < nEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge edge(u, v, w);
        edges.push_back(edge);
    }

    // Sort all edges in ascending order of weight
    sort(edges.begin(), edges.end(),
        [] (Edge e1, Edge e2) {
            return e1.w < e2.w;
        });

    // Union-Find set for all vertices
    DSU dsu(nVertices);

    // Kruskal's Minimum Spanning Tree
    vector<Edge> mst;
    int minCost = 0;

    for (Edge edge : edges) {
        int root_u = dsu.find(edge.u);
        int root_v = dsu.find(edge.v);
        if (dsu.merge(root_u, root_v)) {
            mst.push_back(edge);
        }
    }

    for (Edge edge : mst) {
        minCost += edge.w;
    }

    cout << "Min cost: " << minCost << "\n";

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

