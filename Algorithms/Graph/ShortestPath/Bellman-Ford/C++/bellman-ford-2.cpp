/**
 *  @author Nhat M. Nguyen
 *  @update 24-11-18
**/

/**
 * This implementation uses edge list to represent the graph
**/

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;

    Edge(int u_, int v_, int w_) {
        u = u_, v = v_, w = w_;
    }
};

const int INF = INT_MAX;
vector<Edge> edges;
vector<int> dist;
int nV, nE;

void relax(int u, int v, int w) {
    if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
    }
}

inline void err() {
    cout << "Error: The graph contains negative cycle\n";
}

bool bellman_ford(int src) {
    // Step 1: Processing
    dist.resize(nV);
    fill(dist.begin(), dist.end(), INF);

    dist[src] = 0;

    for (int i = 0; i < nV - 1; i++) {
        for (Edge &e : edges) {
            relax(e.u, e.v, e.w);
        }
    }

    // Step 2: Check for negative cycle
    for (Edge &e : edges) {
        if (dist[e.v] > dist[e.u] + e.w) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input
    cin >> nV >> nE;
    for (int i = 0; i < nE; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    // Bellman-Ford
    if (bellman_ford(0) == false) {
        err();
        return 0;
    }

    // Output
    for (int u = 0; u < nV; u++) {
        cout << "Dist[" << u << "] = " << dist[u] << '\n';
    }

    return 0;
}
