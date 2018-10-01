/**
 * author Nhat M. Nguyen
 * update 01-08-18
**/

#include <iostream>
#include <queue>   // std::priority_queue
#include <vector>
#include <utility> // std::pair


using namespace std;


const int MAXV = (int) 1e3;
const int MAXE = (int) 1e3;


struct Edge {
    int v;
    int w;

    Edge(int v_, int w_) {
        v = v_;
        w = w_;
    }

    bool operator < (const Edge &other) const {
        return w > other.w; // min heap is used but priority_queue is max heap by default
    }
};


bool visited[MAXV];
vector<Edge> adj[MAXV];
priority_queue<Edge, vector<Edge>> pq; 


void prim(int u, vector<Edge> adj_u) {
    visited[u] = true;
    for (Edge &edge : adj_u) {
        if (!visited[edge.v]) {
            pq.push(edge);
        }
    }
}


int main() {
    // Get number of vertices, number of edges
    int nVertices, nEdges;
    cin >> nVertices >> nEdges;

    // Get each edge: u, v, w and generate adjacent lists
    for (int i = 0; i < nEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // visited flags 
    fill(visited, visited + nVertices, false);

    // Prim's Minimum Spanning Tree
    int minCost = 0;

    visited[0] = true;
    prim(0, adj[0]);

    while (!pq.empty()) {
        Edge min_edge = pq.top();
        pq.pop();
        if (visited[min_edge.v]) continue;
        minCost += min_edge.w;
        prim(min_edge.v, adj[min_edge.v]);
    }

    cout << "Min Cost: " << minCost << "\n";

    return 0;
}

/*
  Sample test

== Input ==
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

== Output ==
Min cost: 23

*/

