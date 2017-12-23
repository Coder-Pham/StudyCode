/**
 *  Author: Nhat M. Nguyen
 *  Date: 23-12-17
**/

#include <algorithm> // std::sort
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // hash table
vector<int> depth;

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator < (const Edge &other) {
        return (this->w < other.w);
    }
};

int find(int u) {
    int v = u;
    while (v != parent[v]) {
        v = parent[v];
    }
    return v;
}

void unionSet(int a, int b) {
    if (depth[a] < depth[b]) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
        if (depth[a] == depth[b]) {
            depth[a]++;
        }
    }
}

int main() {
    /*** Get number of vertices and edges ***/
    int nVertices, nEdges;
    cin >> nVertices >> nEdges;

    /*** Get all edges ***/
    vector<Edge> edges;

    for (int i = 0; i < nEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Edge edge(u, v, w);
        edges.push_back(edge);
    }

    /*** Sort all edges in ascending order ***/
    sort(edges.begin(), edges.end());

    /*** Generate parent hash table & assign depth for each disjoint set ***/
    for (int i = 0; i < nVertices; i++) {
        parent.push_back(i);
        depth.push_back(0);
    }

    /*** Kruskal's Minimum Spanning Tree ***/
    vector<Edge> mst;
    int minCost = 0;

    for (Edge edge : edges) {
        int root_u = find(edge.u);
        int root_v = find(edge.v);
        if (root_u != root_v) {
            mst.push_back(edge);
            unionSet(root_u, root_v);
        }
    }

    for (Edge edge: mst) {
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

